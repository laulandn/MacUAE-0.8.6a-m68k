 /*
  * UAE - The Un*x Amiga Emulator
  *
  *  Serial Line Emulation
  *
  * (c) 1996, 1997 Stefan Reinauer <stepan@linux.de>
  * (c) 1997 Christian Schmitt <schmitt@freiburg.linux.de>
  *
  */

#include "sysconfig.h"
#include "sysdeps.h"

#include "config.h"
#include "options.h"
#include "uae.h"
#include "memory.h"
#include "custom.h"
#include "readcpu.h"
#include "newcpu.h"
#include "cia.h"

// serial stuff for Mac by TKR. All changes marked with 'TKR'.
#define	MACOS	// TKR
#ifdef MACOS	// TKR
#include "device.h"
#endif

#undef POSIX_SERIAL
/* Some more or less good way to determine whether we can safely compile in
 * the serial stuff. I'm certain it breaks compilation on some systems. */
#if defined HAVE_SYS_TERMIOS_H && defined HAVE_POSIX_OPT_H && defined HAVE_SYS_IOCTL_H && defined HAVE_TCGETATTR
#define POSIX_SERIAL
#endif

#ifdef POSIX_SERIAL
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#else
#define TIOCM_CAR 1
#define TIOCM_DSR 2
#ifdef _WIN32
#include "osdep/parser.h"
#endif
#endif

#if !defined B300 || !defined B1200 || !defined B2400 || !defined B4800 || !defined B9600
#undef POSIX_SERIAL
#endif
#if !defined B19200 || !defined B57600 || !defined B115200 || !defined B230400
#undef POSIX_SERIAL
#endif

#ifndef O_NONBLOCK
#define O_NONBLOCK O_NDELAY
#endif

#define SERIALDEBUG 1 /* 0, 1, 2 3 */
//#define MODEMTEST   0 /* 0 or 1 */

void serial_open (void);
void serial_close (void);
void serial_init (void);
void serial_exit (void);

void serial_dtr_on (void);
void serial_dtr_off (void);

void serial_flush_buffer (void);
static int serial_read (char *buffer);

int serial_readstatus (void);
uae_u16 serial_writestatus(int old, int new);

uae_u16 SERDATR (void);

int  SERDATS (void);
void  SERPER (uae_u16 w);
void  SERDAT (uae_u16 w);

static char inbuf[1024], outbuf[1024];
static int inptr, inlast, outlast;

int waitqueue=0,
    carrier=0,
    serdev=0,
    dsr=0,
    dtr=0,
    isbaeh=0,
    doreadser=0,
    serstat=-1;

int sd = -1;

#ifdef POSIX_SERIAL
    struct termios tios;
#endif

uae_u16 serper=0,serdat;

void SERPER (uae_u16 w)
{
    int baud=0, pspeed;

    if (!currprefs.use_serial)
	return;

    if (serper == w)  /* don't set baudrate if it's already ok */
	return;
    serper=w;

    if (w&0x8000)
	write_log( "SERPER: 9bit transmission not implemented.\n" );

    switch (w & 0x7fff)
    {
     /* These values should be calculated by the current
      * color clock value (NTSC/PAL). But this solution is
      * easy and it works.
      */

     case 0x2e9b:
     case 0x2e14:
         baud=300;
#ifdef POSIX_SERIAL
         pspeed=B300;
#endif
         break;
     case 0x170a:
     case 0x0b85:
         baud=1200;
#ifdef POSIX_SERIAL
         pspeed=B1200;
#endif
         break;
     case 0x05c2:
     case 0x05b9:
         baud=2400;
#ifdef POSIX_SERIAL
         pspeed=B2400;
#endif
         break;
     case 0x02e9:
     case 0x02e1:
         baud=4800;
#ifdef POSIX_SERIAL
         pspeed=B4800;
#endif
         break;
     case 0x0174:
     case 0x0170:
         baud=9600;
#ifdef POSIX_SERIAL
         pspeed=B9600;
#endif
         break;
     case 0x00b9:
     case 0x00b8:
         baud=19200;
#ifdef POSIX_SERIAL
         pspeed=B19200;
#endif
         break;
     case 0x005c:
     case 0x005d:
         baud=38400;
#ifdef POSIX_SERIAL
         pspeed=B38400;
#endif
         break;
     case 0x003d:
         baud=57600;
#ifdef POSIX_SERIAL
         pspeed=B57600;
#endif
         break;
     case 0x001e:
         baud=115200;
#ifdef POSIX_SERIAL
         pspeed=B115200;
#endif
         break;
     case 0x000f:
         baud=230400;
#ifdef POSIX_SERIAL
         pspeed=B230400;
#endif
         break;
     default:
#ifdef _WIN32
         baud = (unsigned int)(3579546.471/(double)((w&0x7fff)+1));
#else
      write_log( "SERPER: unsupported baudrate (0x%04x) %d\n",w&0x7fff,
		 (unsigned int)(3579546.471/(double)((w&0x7fff)+1)));  return;
#endif
    }

#ifdef _WIN32
    setbaud(baud);
#endif

#if defined POSIX_SERIAL
    /* Only access hardware when we own it */
    if (serdev == 1) {
	if (tcgetattr (sd, &tios) < 0) {
	write_log( "SERPER: TCGETATTR failed\n" );
	    return;
	}

	if (cfsetispeed (&tios, pspeed) < 0) {    /* set serial input speed */
	write_log( "SERPER: CFSETISPEED (%d bps) failed\n", baud );
	    return;
	}
	if (cfsetospeed (&tios, pspeed) < 0) {    /* set serial output speed */
	write_log( "SERPER: CFSETOSPEED (%d bps) failed\n", baud );
	    return;
	}

	if (tcsetattr (sd, TCSADRAIN, &tios) < 0) {
	write_log( "SERPER: TCSETATTR failed\n" );
	    return;
	}
    }
#endif

#ifdef MACOS	// TKR
    /* Only access hardware when we own it */
    if (serdev == 1) {
	if(COM_SetBaudrate(COM_GetComHandle(),baud)) {
	    fprintf (stderr, "SERPER: CFSETISPEED (%d bps) failed\n", baud);
	    return;
		}
    }
#endif			// YKR

//#endif

#if SERIALDEBUG > 0
    if (serdev == 1)
    write_log( "SERPER: baudrate set to %d bit/sec\n", baud );
#endif
}

/* Not (fully) implemented yet:
 *
 *  -  Something's wrong with the Interrupts.
 *     (NComm works, TERM does not. TERM switches to a
 *     blind mode after a connect and wait's for the end
 *     of an asynchronous read before switching blind
 *     mode off again. It never gets there on UAE :-< )
 *
 *  -  RTS/CTS handshake, this is not really neccessary,
 *     because you can use RTS/CTS "outside" without
 *     passing it through to the emulated Amiga
 *
 *  -  ADCON-Register ($9e write, $10 read) Bit 11 (UARTBRK)
 *     (see "Amiga Intern", pg 246)
 */

void SERDAT (uae_u16 w)
{
    unsigned char z;

    if (!currprefs.use_serial)
	return;

    z = (unsigned char)(w&0xff);

#ifdef _WIN32
    if (currprefs.serial_demand && !dtr) {
        write_log( "SERDAT: Baeh.. Your software needs SERIAL_ALWAYS to work properly.\n" );
        openser( sername );
        dtr=1;
    }
    writeser(z);
#else

    if (currprefs.serial_demand && !dtr) {
	if (!isbaeh) {
	write_log( "SERDAT: Baeh.. Your software needs SERIAL_ALWAYS to work properly.\n" );
	    isbaeh=1;
	}
	return;
    } else {
	outbuf[outlast++] = z;
	if (outlast == sizeof outbuf)
	    serial_flush_buffer();
    }
#endif

#if SERIALDEBUG > 2
    write_log( "SERDAT: wrote 0x%04x\n", w );
#endif

    serdat|=0x2000; /* Set TBE in the SERDATR ... */
    intreq|=1;      /* ... and in INTREQ register */
    return;
}

uae_u16 SERDATR (void)
{
    if (!currprefs.use_serial)
	return 0;
#if SERIALDEBUG > 2
    write_log( "SERDATR: read 0x%04x\n", serdat );
#endif
    waitqueue = 0;
    return serdat;
}

int SERDATS (void)
{
    unsigned char z;

    if (!serdev)           /* || (serdat&0x4000)) */
	return 0;

    if (waitqueue == 1) {
	intreq |= 0x0800;
	return 1;
    }

    if ((serial_read ((char *)&z)) == 1) {
	waitqueue = 1;
	serdat = 0x4100; /* RBF and STP set! */
	serdat |= ((unsigned int)z) & 0xff;
	intreq |= 0x0800; /* Set RBF flag (Receive Buffer full) */

#if SERIALDEBUG > 1
      write_log( "SERDATS: received 0x%02x --> serdat==0x%04x\n",
		 (unsigned int)z, (unsigned int)serdat);
#endif
	return 1;
    }
    return 0;
}

void serial_dtr_on(void)
{
#if SERIALDEBUG > 0
  write_log( "SERIAL: DTR on.\n" );
#endif
    dtr=1;

    if (currprefs.serial_demand)
	serial_open ();
}

void serial_dtr_off(void)
{
#if SERIALDEBUG > 0
  write_log( "SERIAL: DTR off.\n" );
#endif
    dtr=0;
    if (currprefs.serial_demand)
	serial_close ();
}

static int serial_read (char *buffer)
{
#ifdef _WIN32
    return readser( buffer );
#else
    if (inptr < inlast) {
	*buffer = inbuf[inptr++];
	return 1;
    }

    if (serdev == 1) {
#ifdef MACOS	// TKR
	inlast = COM_ReceiveData(COM_GetComHandle(),inbuf,sizeof(inbuf));
#else
	inlast = read (sd, inbuf, sizeof inbuf);
#endif
	inptr = 0;
	if (inptr < inlast) {
	    *buffer = inbuf[inptr++];
	    return 1;
	}
    }

    return 0;
#endif
}

void serial_flush_buffer(void)
{
#ifdef _WIN32
    doserout();
#else
    if (serdev == 1) {
	if (outlast) {
#ifdef MACOS	// TKR
		(void)COM_SendData(COM_GetComHandle(),outbuf,outlast);
#else
	    if (sd != 0) {
		write (sd, outbuf, outlast);
	    }
#endif
	}
	outlast = 0;
    } else {
      outlast = 0;
      inptr = 0;
      inlast = 0;
    }
#endif
}

int serial_readstatus(void)
{
    int status = 0;
#ifdef _WIN32
    getserstat( &status );
#endif
#ifdef POSIX_SERIAL
    ioctl (sd, TIOCMGET, &status);
#endif
#ifdef MACOS		// TKR
if (COM_StatusIsSet(COM_GetComHandle(),COMFLG_STATUSCD)) status+=TIOCM_CAR;
if (COM_StatusIsSet(COM_GetComHandle(),COMFLG_STATUSDSR)) status+=TIOCM_DSR;
// or like Win32 ?
//    status = 0;
#endif
    if (status & TIOCM_CAR) {
	if (!carrier) {
	    ciabpra |= 0x20; /* Push up Carrier Detect line */
	    carrier = 1;
#if SERIALDEBUG > 0
	write_log( "SERIAL: Carrier detect.\n" );
#endif
	}
    } else {
	if (carrier) {
	    ciabpra &= ~0x20;
	    carrier = 0;
#if SERIALDEBUG > 0
	write_log( "SERIAL: Carrier lost.\n" );
#endif
	}
    }

    if (status & TIOCM_DSR) {
	if (!dsr) {
	    ciabpra |= 0x08; /* DSR ON */
	    dsr = 1;
	}
    } else {
	if (dsr) {
	    ciabpra &= ~0x08;
	    dsr = 0;
	}
    }
    return status;
}

uae_u16 serial_writestatus (int old, int new)
{
    if (((old&0x80)==0x80) && ((new&0x80)==0x00))
	serial_dtr_on();
    if (((old&0x80)==0x00) && ((new&0x80)==0x80))
	serial_dtr_off();

#if SERIALDEBUG > 0
    if ((old&0x40)!=(new&0x40))
      write_log( "SERIAL: RTS %s.\n",((new&0x40)==0x40)?"set":"cleared");

    if ((old&0x10)!=(new&0x10))
      write_log( "SERIAL: CTS %s.\n",((new&0x10)==0x10)?"set":"cleared");
#endif
    return new; /* This value could also be changed here */
}

void serial_open(void)
{
    if (serdev == 1)
	return;

#ifdef MACOS	// TKR
	if(COM_Connect(COM_GetComHandle()))
	{
	fprintf (stdout, "Error: Could not open Device %s\n", sername);
	return;
	}
	
    serdev = 1;
    
#ifndef MODEMTEST
	if(COM_SetHandshake(COM_GetComHandle(),HANDSHAKE_NONE)) {	/* Disable RTS/CTS */
#else
	if(COM_SetHandshake(COM_GetComHandle(),HANDSHAKE_DTRCTS)) {	/* Enabled for testing modems */
#endif
	fprintf (stderr,"Serial: TCSETATTR failed\n");
	return;
    }

#else // MACOS

#ifdef _WIN32
    if( !openser( sername ) )
    {
        write_log( "SERIAL: Could not open Device %s\n", sername );
        return;
    }
#else
    if ((sd = open (sername, O_RDWR|O_NONBLOCK|O_BINARY, 0)) < 0) {
      write_log( "SERIAL: Could not open Device %s\n", sername );
	return;
    }
#endif
    serdev = 1;

#ifdef POSIX_SERIAL
    if (tcgetattr (sd, &tios) < 0) {		/* Initialize Serial tty */
      write_log( "SERIAL: TCGETATTR failed\n" );
	return;
    }
    cfmakeraw (&tios);

#ifndef MODEMTEST
    tios.c_cflag &= ~CRTSCTS; /* Disable RTS/CTS */
#else
    tios.c_cflag |= CRTSCTS; /* Enabled for testing modems */
#endif

    if (tcsetattr (sd, TCSADRAIN, &tios) < 0) {
      write_log( "SERIAL: TCSETATTR failed\n" );
	return;
    }
#endif
#endif
}

void serial_close (void)
{
#ifdef MACOS	// TKR
	(void)COM_Disconnect(COM_GetComHandle());
#else
#ifdef _WIN32
    closeser();
#else
    if (sd != 0)
	close(sd);
#endif
    serdev = 0;
#endif //MACOS
}

void serial_init (void)
{
    if (!currprefs.use_serial)
	return;

    if (!currprefs.serial_demand)
	serial_open ();

    serdat = 0x2000;
    return;
}

void serial_exit (void)
{
    serial_close ();	/* serial_close can always be called because it	*/
    dtr = 0;		/* just closes *opened* filehandles which is ok	*/
    return;		/* when exiting.				*/
}
