#include "sysconfig.h"
#include "sysdeps.h"
#include "config.h"
#include "options.h"
#include "custom.h"
#include "memory.h"
#include "blitter.h"
#include "blitfunc.h"

void blitdofast_0(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1) {
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		dest = 0;
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		dest = 0;
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (ptd) ptd += b->bltdmod;
}
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		do_put_mem_word (dstp, dstd);
		dstd = (0) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (ptd) ptd += b->bltdmod;
}
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_0(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1) {
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		dest = 0;
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		dest = 0;
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (ptd) ptd-=b->bltdmod;
}
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		do_put_mem_word (dstp, dstd);
		dstd = (0) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (ptd) ptd -= b->bltdmod;
}
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (~srca & srcc);
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (~srca & srcc);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((~srca & srcc)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (~srca & srcc);
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (~srca & srcc);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((~srca & srcc)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_2a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcc & ~(srca & srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcc & ~(srca & srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc & ~(srca & srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_2a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcc & ~(srca & srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcc & ~(srca & srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc & ~(srca & srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_30(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		dest = (srca & ~srcb);
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		dest = (srca & ~srcb);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca & ~srcb)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_30(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		dest = (srca & ~srcb);
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		dest = (srca & ~srcb);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca & ~srcb)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_3a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcb ^ (srca | (srcb ^ srcc)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcb ^ (srca | (srcb ^ srcc)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcb ^ (srca | (srcb ^ srcc)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_3a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcb ^ (srca | (srcb ^ srcc)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcb ^ (srca | (srcb ^ srcc)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcb ^ (srca | (srcb ^ srcc)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_3c(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		dest = (srca ^ srcb);
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		dest = (srca ^ srcb);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca ^ srcb)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_3c(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		dest = (srca ^ srcb);
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		dest = (srca ^ srcb);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca ^ srcb)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_4a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcc ^ (srca & (srcb | srcc)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcc ^ (srca & (srcb | srcc)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srca & (srcb | srcc)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_4a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcc ^ (srca & (srcb | srcc)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcc ^ (srca & (srcb | srcc)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srca & (srcb | srcc)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_6a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcc ^ (srca & srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcc ^ (srca & srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srca & srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_6a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcc ^ (srca & srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcc ^ (srca & srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srca & srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_8a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcc & (~srca | srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcc & (~srca | srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc & (~srca | srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_8a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcc & (~srca | srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcc & (~srca | srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc & (~srca | srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_8c(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcb & (~srca | srcc));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcb & (~srca | srcc));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcb & (~srca | srcc))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_8c(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcb & (~srca | srcc));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcb & (~srca | srcc));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcb & (~srca | srcc))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_9a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcc ^ (srca & ~srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcc ^ (srca & ~srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srca & ~srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_9a(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcc ^ (srca & ~srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcc ^ (srca & ~srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srca & ~srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_a8(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcc & (srca | srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcc & (srca | srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc & (srca | srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_a8(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcc & (srca | srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcc & (srca | srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc & (srca | srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_aa(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1) {
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = srcc;
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = srcc;
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		do_put_mem_word (dstp, dstd);
		dstd = (srcc) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_aa(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1) {
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = srcc;
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = srcc;
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		do_put_mem_word (dstp, dstd);
		dstd = (srcc) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_b1(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = ~(srca ^ (srcc | (srca ^ srcb)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = ~(srca ^ (srcc | (srca ^ srcb)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = (~(srca ^ (srcc | (srca ^ srcb)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_b1(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = ~(srca ^ (srcc | (srca ^ srcb)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = ~(srca ^ (srcc | (srca ^ srcb)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = (~(srca ^ (srcc | (srca ^ srcb)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_ca(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcc ^ (srca & (srcb ^ srcc)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcc ^ (srca & (srcb ^ srcc)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srca & (srcb ^ srcc)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_ca(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcc ^ (srca & (srcb ^ srcc)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcc ^ (srca & (srcb ^ srcc)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srca & (srcb ^ srcc)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_cc(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitbshift) {
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		dest = srcb;
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		dest = srcb;
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (ptb) ptb += b->bltbmod;
	if (ptd) ptd += b->bltdmod;
}
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		do_put_mem_word (dstp, dstd);
		dstd = (srcb) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (ptb) ptb += b->bltbmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_cc(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitbshift) {
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		dest = srcb;
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		dest = srcb;
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (ptb) ptb -= b->bltbmod;
	if (ptd) ptd-=b->bltdmod;
}
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		do_put_mem_word (dstp, dstd);
		dstd = (srcb) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (ptb) ptb -= b->bltbmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_d8(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srca ^ (srcc & (srca ^ srcb)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srca ^ (srcc & (srca ^ srcb)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca ^ (srcc & (srca ^ srcb)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_d8(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srca ^ (srcc & (srca ^ srcb)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srca ^ (srcc & (srca ^ srcb)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca ^ (srcc & (srca ^ srcb)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_e2(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcc ^ (srcb & (srca ^ srcc)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcc ^ (srcb & (srca ^ srcc)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srcb & (srca ^ srcc)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_e2(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcc ^ (srcb & (srca ^ srcc)));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcc ^ (srcb & (srca ^ srcc)));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc ^ (srcb & (srca ^ srcc)))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_ea(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srcc | (srca & srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srcc | (srca & srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc | (srca & srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_ea(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srcc | (srca & srcb));
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srcc | (srca & srcb));
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srcc | (srca & srcb))) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_f0(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		dest = srca;
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		dest = srca;
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = (srca) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptd) ptd += b->bltdmod;
}
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_f0(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		dest = srca;
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		dest = srca;
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = (srca) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptd) ptd -= b->bltdmod;
}
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_fa(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcc=((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptc) {srcc=*((uae_u32 *)ptc); ptc += 4;}
		dest = (srca | srcc);
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc += 2; }
		dest = (srca | srcc);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptc) b->bltcdat = (*(ptc-b->bltcmod-2) << 8) | *(ptc - b->bltcmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc += 2; }
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca | srcc)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptc) ptc += b->bltcmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_fa(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcc = ((uae_u32)b->bltcdat << 16) | b->bltcdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptc) { srcc=*((uae_u32 *)(ptc-2)); ptc -= 4;}
		dest = (srca | srcc);
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptc) { srcc=(uae_u32)*(uae_u16 *)ptc; ptc -= 2; }
		dest = (srca | srcc);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptc) b->bltcdat = (*(ptc + b->bltcmod + 2) << 8) | *(ptc + b->bltcmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 srcc = b->bltcdat;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptc) { srcc = do_get_mem_word((uae_u16 *)ptc); ptc -= 2; }
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca | srcc)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptc) ptc -= b->bltcmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltcdat = srcc;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_fc(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
int i,j;
uae_u32 totald = 0;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca=((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb=((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) {srca=*((uae_u32 *)pta); pta += 4;}
		if (ptb) {srcb=*((uae_u32 *)ptb); ptb += 4;}
		dest = (srca | srcb);
		totald |= dest;
		if (ptd) {*(uae_u32 *)ptd=dest; ptd += 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta += 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb += 2; }
		dest = (srca | srcb);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptd) ptd += b->bltdmod;
}
if (pta) b->bltadat = (*(pta-b->bltamod-2) << 8) | *(pta - b->bltamod - 1);
if (ptb) b->bltbdat = (*(ptb-b->bltbmod-2) << 8) | *(ptb - b->bltbmod - 1);
if (ptd) b->bltddat = (*(ptd-b->bltdmod-2) << 8) | *(ptd - b->bltdmod - 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;

		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb += 2;
			srcb = (((uae_u32)prevb << 16) | bltbdat) >> b->blitbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta += 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)preva << 16) | bltadat) >> b->blitashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca | srcb)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd += 2; }
	}
	if (pta) pta += b->bltamod;
	if (ptb) ptb += b->bltbmod;
	if (ptd) ptd += b->bltdmod;
}
b->bltbhold = srcb;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
void blitdofast_desc_fc(uae_u8 *pta, uae_u8 *ptb, uae_u8 *ptc, uae_u8 *ptd, struct bltinfo *b)
{
uae_u32 totald = 0;
int i,j;
if (currprefs.blits_32bit_enabled && b->hblitsize > 1 && !b->blitashift && b->bltafwm==0xffff && b->bltalwm==0xffff && !b->blitbshift) {
uae_u32 srca = ((uae_u32)b->bltadat << 16) | b->bltadat;
uae_u32 srcb = ((uae_u32)b->bltbdat << 16) | b->bltbdat;
uae_u32 dest;
int count=b->hblitsize/2, oddword=b->hblitsize&1;
for (j=0;j<b->vblitsize;j++) {
	for(i=0;i<count;i++) {
		if (pta) { srca=*((uae_u32 *)(pta-2)); pta -= 4;}
		if (ptb) { srcb=*((uae_u32 *)(ptb-2)); ptb -= 4;}
		dest = (srca | srcb);
		totald |= dest;
		if (ptd) {*(uae_u32 *)(ptd-2)=dest; ptd -= 4;}
	}
	if (oddword) {
		if (pta) { srca=(uae_u32)*(uae_u16 *)pta; pta -= 2; }
		if (ptb) { srcb=(uae_u32)*(uae_u16 *)ptb; ptb -= 2; }
		dest = (srca | srcb);
		totald |= dest;
		if (ptd) { *(uae_u16 *)ptd= dest; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptd) ptd-=b->bltdmod;
}
if (pta) b->bltadat = (*(pta + b->bltamod + 2) << 8) | *(pta + b->bltamod + 1);
if (ptb) b->bltbdat = (*(ptb + b->bltbmod + 2) << 8) | *(ptb + b->bltbmod + 1);
if (ptd) b->bltddat = (*(ptd + b->bltdmod + 2) << 8) | *(ptd + b->bltdmod + 1);
} else {
uae_u32 preva = 0;
uae_u32 prevb = 0, srcb = b->bltbhold;
uae_u32 dstd=0;
uae_u16 foo, *dstp = &foo;
for (j = 0; j < b->vblitsize; j++) {
	for (i = 0; i < b->hblitsize; i++) {
		uae_u32 bltadat, srca;
		if (ptb) {
			uae_u32 bltbdat = do_get_mem_word((uae_u16 *)ptb); ptb -= 2;
			srcb = ((bltbdat << 16) | prevb) >> b->blitdownbshift;
			prevb = bltbdat;
		}
		if (pta) { bltadat = do_get_mem_word((uae_u16 *)pta); pta -= 2; } else { bltadat = blt_info.bltadat; }
		bltadat &= blit_masktable[i];
		srca = (((uae_u32)bltadat << 16) | preva) >> b->blitdownashift;
		preva = bltadat;
		do_put_mem_word (dstp, dstd);
		dstd = ((srca | srcb)) & 0xFFFF;
		totald |= dstd;
		if (ptd) { dstp = (uae_u16 *)ptd; ptd -= 2; }
	}
	if (pta) pta -= b->bltamod;
	if (ptb) ptb -= b->bltbmod;
	if (ptd) ptd -= b->bltdmod;
}
b->bltbhold = srcb;
		do_put_mem_word (dstp, dstd);
}
if (totald != 0) b->blitzero = 0;
}
