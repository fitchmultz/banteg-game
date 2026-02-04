/* grim_set_color @ 10007f90 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x114 (provisional) */

void grim_set_color(float r,float g,float b,float a)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = ftol();
  iVar2 = ftol();
  uVar3 = ftol();
  uVar4 = ftol();
  grim_color_slot0 = ((uVar1 & 0xff | iVar2 << 8) << 8 | uVar3 & 0xff) << 8 | uVar4 & 0xff;
  grim_color_slot3 = grim_color_slot0;
  DAT_1005bc0c = grim_color_slot0;
  DAT_1005bc08 = grim_color_slot0;
  return;
}



