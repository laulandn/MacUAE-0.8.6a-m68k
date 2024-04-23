 /* 
  * UAE - The Un*x Amiga Emulator
  * 
  * Support for MacOS sound
  * 
  * Copyright 1997 Bernd Schmidt
  */
  
#define SOUND_HAS_PRIORITY
#ifdef SOUND_HAS_PRIORITY
#define IHF_SOUNDADJUST 7
#endif

#include "AsgardESS.h"

extern uae_u16 sndbuffer[];
extern uae_u16 *sndbufpt;
extern int sndbufsize;
extern int outpout_sound;

extern void flush_sound_buffers(void);

static __inline__ void check_sound_buffers (void)
{		
    if ((char *)sndbufpt - (char *)sndbuffer >= sndbufsize) {
#if 0
    	AsgardESS_PlaySample( 0							// int voice,
						,(unsigned char  *)sndbuffer	// unsigned char *pData,
						,currprefs.sound_maxbsiz		// long length,
						,currprefs.sound_freq			// long frequency,
						,AESS_MAXIMUM_VOLUME			// int volume,
						,0x1	);						// Boolean loop)
#endif							
		sndbufpt = sndbuffer ;
		}
}

#define PUT_SOUND_BYTE(b)	*(uae_u8 *)sndbufpt = b; sndbufpt = (uae_u16 *)(((uae_u8 *)sndbufpt) + 1);
#define PUT_SOUND_WORD(b) 	*(uae_u16 *)sndbufpt = b; sndbufpt = (uae_u16 *)(((uae_u8 *)sndbufpt) + 2);

/* Stereo */

//#define PUT_SOUND_BYTE_LEFT(b) PUT_SOUND_BYTE(b)
//#define PUT_SOUND_WORD_LEFT(b) PUT_SOUND_WORD(b)
//#define PUT_SOUND_BYTE_RIGHT(b) PUT_SOUND_BYTE(b)
//#define PUT_SOUND_WORD_RIGHT(b) PUT_SOUND_WORD(b)

#define SOUND16_BASE_VAL 0
#define SOUND8_BASE_VAL  0

#define DEFAULT_SOUND_MINB 22050
#define DEFAULT_SOUND_MAXB 22050
#define DEFAULT_SOUND_BITS 8
#define DEFAULT_SOUND_FREQ 22050

// #define HAVE_STEREO_SUPPORT

