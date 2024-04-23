 /* 
  * UAE - The Un*x Amiga Emulator
  * 
  * Joystick emulation stubs
  * 
  * Copyright 1997 Bernd Schmidt
  */

#include "sysconfig.h"
#include "sysdeps.h"

#include "config.h"
#include "options.h"
#include "memory.h"
#include "custom.h"
#include "joystick.h"

int nr_joysticks;

void read_joystick(int nr, unsigned int *dir, int *button)
{
#if 1
    *dir = 0;
    *button = 0;
#else

    int bot=0, right=0, top=0, left=0, fire=0;
    unsigned char km[16];
    
    GetKeys( (unsigned long *) km);
    
    fire=(((km[59>>3]>>(59&7))&1));
    right=(((km[124>>3]>>(124&7))&1));
    left=(((km[123>>3]>>(123&7))&1));
    bot=(((km[125>>3]>>(125&7))&1));
    top=(((km[126>>3]>>(126&7))&1));
    
	if (left) top = !top;
	if (right) bot = !bot;
    *dir = bot | (right << 1) | (top << 8) | (left << 9);
    *button = fire;

#endif
}

void init_joystick(void)
{
    nr_joysticks = 0;
}

void close_joystick(void)
{
}

