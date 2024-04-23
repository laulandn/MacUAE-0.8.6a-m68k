#include "sysconfig.h"
#include "sysdeps.h"
#include "custom.h"
#include "p2c.h"
void set_hires_h_0_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_0_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		app[i] = v1;
	}
}

void set_lores_h_0_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_0_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_0_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		app[i] = v1;
	}
}

void set_lores_h_0_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_0_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		v1 = app[i*2 + 0]; v2 = app[i*2 + 1];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_0_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		v1 = app[i];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		app[i] = v1;
	}
}

void set_lores_h_0_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		v1 = app[i*4 + 0]; v2 = app[i*4 + 1]; v3 = app[i*4 + 2]; v4 = app[i*4 + 3];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_1_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_1_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		app[i] = v1;
	}
}

void set_lores_h_1_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_1_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_h[data][0] << 2;
			v2 |= hirestab_h[data][1] << 2;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_1_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_l[data][0] << 2;
		}
		app[i] = v1;
	}
}

void set_lores_h_1_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= lorestab_h[data][0] << 2;
			v2 |= lorestab_h[data][1] << 2;
			v3 |= lorestab_h[data][2] << 2;
			v4 |= lorestab_h[data][3] << 2;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_1_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		v1 = app[i*2 + 0]; v2 = app[i*2 + 1];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_h[data][0] << 3;
			v2 |= hirestab_h[data][1] << 3;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_1_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		v1 = app[i];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_l[data][0] << 3;
		}
		app[i] = v1;
	}
}

void set_lores_h_1_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		v1 = app[i*4 + 0]; v2 = app[i*4 + 1]; v3 = app[i*4 + 2]; v4 = app[i*4 + 3];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= lorestab_h[data][0] << 3;
			v2 |= lorestab_h[data][1] << 3;
			v3 |= lorestab_h[data][2] << 3;
			v4 |= lorestab_h[data][3] << 3;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_2_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_h[data][0] << 2;
			v2 |= hirestab_h[data][1] << 2;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_2_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_l[data][0] << 2;
		}
		app[i] = v1;
	}
}

void set_lores_h_2_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= lorestab_h[data][0] << 2;
			v2 |= lorestab_h[data][1] << 2;
			v3 |= lorestab_h[data][2] << 2;
			v4 |= lorestab_h[data][3] << 2;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_2_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_h[data][0] << 2;
			v2 |= hirestab_h[data][1] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_h[data][0] << 4;
			v2 |= hirestab_h[data][1] << 4;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_2_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_l[data][0] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_l[data][0] << 4;
		}
		app[i] = v1;
	}
}

void set_lores_h_2_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= lorestab_h[data][0] << 2;
			v2 |= lorestab_h[data][1] << 2;
			v3 |= lorestab_h[data][2] << 2;
			v4 |= lorestab_h[data][3] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= lorestab_h[data][0] << 4;
			v2 |= lorestab_h[data][1] << 4;
			v3 |= lorestab_h[data][2] << 4;
			v4 |= lorestab_h[data][3] << 4;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_2_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		v1 = app[i*2 + 0]; v2 = app[i*2 + 1];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_h[data][0] << 3;
			v2 |= hirestab_h[data][1] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_h[data][0] << 5;
			v2 |= hirestab_h[data][1] << 5;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_2_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		v1 = app[i];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_l[data][0] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_l[data][0] << 5;
		}
		app[i] = v1;
	}
}

void set_lores_h_2_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		v1 = app[i*4 + 0]; v2 = app[i*4 + 1]; v3 = app[i*4 + 2]; v4 = app[i*4 + 3];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= lorestab_h[data][0] << 3;
			v2 |= lorestab_h[data][1] << 3;
			v3 |= lorestab_h[data][2] << 3;
			v4 |= lorestab_h[data][3] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= lorestab_h[data][0] << 5;
			v2 |= lorestab_h[data][1] << 5;
			v3 |= lorestab_h[data][2] << 5;
			v4 |= lorestab_h[data][3] << 5;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_3_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_h[data][0] << 2;
			v2 |= hirestab_h[data][1] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_h[data][0] << 3;
			v2 |= hirestab_h[data][1] << 3;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_3_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_l[data][0] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_l[data][0] << 3;
		}
		app[i] = v1;
	}
}

void set_lores_h_3_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= lorestab_h[data][0] << 2;
			v2 |= lorestab_h[data][1] << 2;
			v3 |= lorestab_h[data][2] << 2;
			v4 |= lorestab_h[data][3] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= lorestab_h[data][0] << 3;
			v2 |= lorestab_h[data][1] << 3;
			v3 |= lorestab_h[data][2] << 3;
			v4 |= lorestab_h[data][3] << 3;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_3_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_h[data][0] << 2;
			v2 |= hirestab_h[data][1] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_h[data][0] << 4;
			v2 |= hirestab_h[data][1] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 600);
			v1 |= hirestab_h[data][0] << 6;
			v2 |= hirestab_h[data][1] << 6;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_3_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_l[data][0] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_l[data][0] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 600);
			v1 |= hirestab_l[data][0] << 6;
		}
		app[i] = v1;
	}
}

void set_lores_h_3_1 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= lorestab_h[data][0] << 2;
			v2 |= lorestab_h[data][1] << 2;
			v3 |= lorestab_h[data][2] << 2;
			v4 |= lorestab_h[data][3] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= lorestab_h[data][0] << 4;
			v2 |= lorestab_h[data][1] << 4;
			v3 |= lorestab_h[data][2] << 4;
			v4 |= lorestab_h[data][3] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 600);
			v1 |= lorestab_h[data][0] << 6;
			v2 |= lorestab_h[data][1] << 6;
			v3 |= lorestab_h[data][2] << 6;
			v4 |= lorestab_h[data][3] << 6;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_3_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		v1 = app[i*2 + 0]; v2 = app[i*2 + 1];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_h[data][0] << 3;
			v2 |= hirestab_h[data][1] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_h[data][0] << 5;
			v2 |= hirestab_h[data][1] << 5;
		}
		{
			unsigned int data = *(ptr + i  + 700);
			v1 |= hirestab_h[data][0] << 7;
			v2 |= hirestab_h[data][1] << 7;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_3_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		v1 = app[i];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_l[data][0] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_l[data][0] << 5;
		}
		{
			unsigned int data = *(ptr + i  + 700);
			v1 |= hirestab_l[data][0] << 7;
		}
		app[i] = v1;
	}
}

void set_lores_h_3_2 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		v1 = app[i*4 + 0]; v2 = app[i*4 + 1]; v3 = app[i*4 + 2]; v4 = app[i*4 + 3];
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= lorestab_h[data][0] << 3;
			v2 |= lorestab_h[data][1] << 3;
			v3 |= lorestab_h[data][2] << 3;
			v4 |= lorestab_h[data][3] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= lorestab_h[data][0] << 5;
			v2 |= lorestab_h[data][1] << 5;
			v3 |= lorestab_h[data][2] << 5;
			v4 |= lorestab_h[data][3] << 5;
		}
		{
			unsigned int data = *(ptr + i  + 700);
			v1 |= lorestab_h[data][0] << 7;
			v2 |= lorestab_h[data][1] << 7;
			v3 |= lorestab_h[data][2] << 7;
			v4 |= lorestab_h[data][3] << 7;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_4_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_h[data][0] << 2;
			v2 |= hirestab_h[data][1] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_h[data][0] << 3;
			v2 |= hirestab_h[data][1] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_h[data][0] << 4;
			v2 |= hirestab_h[data][1] << 4;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_4_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_l[data][0] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_l[data][0] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_l[data][0] << 4;
		}
		app[i] = v1;
	}
}

void set_lores_h_4_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= lorestab_h[data][0] << 2;
			v2 |= lorestab_h[data][1] << 2;
			v3 |= lorestab_h[data][2] << 2;
			v4 |= lorestab_h[data][3] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= lorestab_h[data][0] << 3;
			v2 |= lorestab_h[data][1] << 3;
			v3 |= lorestab_h[data][2] << 3;
			v4 |= lorestab_h[data][3] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= lorestab_h[data][0] << 4;
			v2 |= lorestab_h[data][1] << 4;
			v3 |= lorestab_h[data][2] << 4;
			v4 |= lorestab_h[data][3] << 4;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_5_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_h[data][0] << 2;
			v2 |= hirestab_h[data][1] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_h[data][0] << 3;
			v2 |= hirestab_h[data][1] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_h[data][0] << 4;
			v2 |= hirestab_h[data][1] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_h[data][0] << 5;
			v2 |= hirestab_h[data][1] << 5;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_5_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_l[data][0] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_l[data][0] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_l[data][0] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_l[data][0] << 5;
		}
		app[i] = v1;
	}
}

void set_lores_h_5_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= lorestab_h[data][0] << 2;
			v2 |= lorestab_h[data][1] << 2;
			v3 |= lorestab_h[data][2] << 2;
			v4 |= lorestab_h[data][3] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= lorestab_h[data][0] << 3;
			v2 |= lorestab_h[data][1] << 3;
			v3 |= lorestab_h[data][2] << 3;
			v4 |= lorestab_h[data][3] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= lorestab_h[data][0] << 4;
			v2 |= lorestab_h[data][1] << 4;
			v3 |= lorestab_h[data][2] << 4;
			v4 |= lorestab_h[data][3] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= lorestab_h[data][0] << 5;
			v2 |= lorestab_h[data][1] << 5;
			v3 |= lorestab_h[data][2] << 5;
			v4 |= lorestab_h[data][3] << 5;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_6_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_h[data][0] << 2;
			v2 |= hirestab_h[data][1] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_h[data][0] << 3;
			v2 |= hirestab_h[data][1] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_h[data][0] << 4;
			v2 |= hirestab_h[data][1] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_h[data][0] << 5;
			v2 |= hirestab_h[data][1] << 5;
		}
		{
			unsigned int data = *(ptr + i  + 600);
			v1 |= hirestab_h[data][0] << 6;
			v2 |= hirestab_h[data][1] << 6;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_6_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_l[data][0] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_l[data][0] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_l[data][0] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_l[data][0] << 5;
		}
		{
			unsigned int data = *(ptr + i  + 600);
			v1 |= hirestab_l[data][0] << 6;
		}
		app[i] = v1;
	}
}

void set_lores_h_6_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= lorestab_h[data][0] << 2;
			v2 |= lorestab_h[data][1] << 2;
			v3 |= lorestab_h[data][2] << 2;
			v4 |= lorestab_h[data][3] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= lorestab_h[data][0] << 3;
			v2 |= lorestab_h[data][1] << 3;
			v3 |= lorestab_h[data][2] << 3;
			v4 |= lorestab_h[data][3] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= lorestab_h[data][0] << 4;
			v2 |= lorestab_h[data][1] << 4;
			v3 |= lorestab_h[data][2] << 4;
			v4 |= lorestab_h[data][3] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= lorestab_h[data][0] << 5;
			v2 |= lorestab_h[data][1] << 5;
			v3 |= lorestab_h[data][2] << 5;
			v4 |= lorestab_h[data][3] << 5;
		}
		{
			unsigned int data = *(ptr + i  + 600);
			v1 |= lorestab_h[data][0] << 6;
			v2 |= lorestab_h[data][1] << 6;
			v3 |= lorestab_h[data][2] << 6;
			v4 |= lorestab_h[data][3] << 6;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

void set_hires_h_7_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_h[data][0] << 0;
			v2 = hirestab_h[data][1] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_h[data][0] << 1;
			v2 |= hirestab_h[data][1] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_h[data][0] << 2;
			v2 |= hirestab_h[data][1] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_h[data][0] << 3;
			v2 |= hirestab_h[data][1] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_h[data][0] << 4;
			v2 |= hirestab_h[data][1] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_h[data][0] << 5;
			v2 |= hirestab_h[data][1] << 5;
		}
		{
			unsigned int data = *(ptr + i  + 600);
			v1 |= hirestab_h[data][0] << 6;
			v2 |= hirestab_h[data][1] << 6;
		}
		{
			unsigned int data = *(ptr + i  + 700);
			v1 |= hirestab_h[data][0] << 7;
			v2 |= hirestab_h[data][1] << 7;
		}
		app[i*2 + 0] = v1;
		app[i*2 + 1] = v2;
	}
}

void set_hires_l_7_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = hirestab_l[data][0] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= hirestab_l[data][0] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= hirestab_l[data][0] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= hirestab_l[data][0] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= hirestab_l[data][0] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= hirestab_l[data][0] << 5;
		}
		{
			unsigned int data = *(ptr + i  + 600);
			v1 |= hirestab_l[data][0] << 6;
		}
		{
			unsigned int data = *(ptr + i  + 700);
			v1 |= hirestab_l[data][0] << 7;
		}
		app[i] = v1;
	}
}

void set_lores_h_7_0 (uae_u32 *app, uae_u8 *ptr, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		uae_u32 v1, v2, v3, v4;
		{
			unsigned int data = *(ptr + i  + 0);
			v1 = lorestab_h[data][0] << 0;
			v2 = lorestab_h[data][1] << 0;
			v3 = lorestab_h[data][2] << 0;
			v4 = lorestab_h[data][3] << 0;
		}
		{
			unsigned int data = *(ptr + i  + 100);
			v1 |= lorestab_h[data][0] << 1;
			v2 |= lorestab_h[data][1] << 1;
			v3 |= lorestab_h[data][2] << 1;
			v4 |= lorestab_h[data][3] << 1;
		}
		{
			unsigned int data = *(ptr + i  + 200);
			v1 |= lorestab_h[data][0] << 2;
			v2 |= lorestab_h[data][1] << 2;
			v3 |= lorestab_h[data][2] << 2;
			v4 |= lorestab_h[data][3] << 2;
		}
		{
			unsigned int data = *(ptr + i  + 300);
			v1 |= lorestab_h[data][0] << 3;
			v2 |= lorestab_h[data][1] << 3;
			v3 |= lorestab_h[data][2] << 3;
			v4 |= lorestab_h[data][3] << 3;
		}
		{
			unsigned int data = *(ptr + i  + 400);
			v1 |= lorestab_h[data][0] << 4;
			v2 |= lorestab_h[data][1] << 4;
			v3 |= lorestab_h[data][2] << 4;
			v4 |= lorestab_h[data][3] << 4;
		}
		{
			unsigned int data = *(ptr + i  + 500);
			v1 |= lorestab_h[data][0] << 5;
			v2 |= lorestab_h[data][1] << 5;
			v3 |= lorestab_h[data][2] << 5;
			v4 |= lorestab_h[data][3] << 5;
		}
		{
			unsigned int data = *(ptr + i  + 600);
			v1 |= lorestab_h[data][0] << 6;
			v2 |= lorestab_h[data][1] << 6;
			v3 |= lorestab_h[data][2] << 6;
			v4 |= lorestab_h[data][3] << 6;
		}
		{
			unsigned int data = *(ptr + i  + 700);
			v1 |= lorestab_h[data][0] << 7;
			v2 |= lorestab_h[data][1] << 7;
			v3 |= lorestab_h[data][2] << 7;
			v4 |= lorestab_h[data][3] << 7;
		}
		app[i*4 + 0] = v1;
		app[i*4 + 1] = v2;
		app[i*4 + 2] = v3;
		app[i*4 + 3] = v4;
	}
}

