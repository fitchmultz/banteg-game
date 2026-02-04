/* grim_set_color_slot @ 100081c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x118 (provisional): set color slot */

void grim_set_color_slot(int index,float r,float g,float b,float a)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = ftol();
  iVar2 = ftol();
  uVar3 = ftol();
  uVar4 = ftol();
  (&grim_color_slot0)[index] = ((uVar1 & 0xff | iVar2 << 8) << 8 | uVar3 & 0xff) << 8 | uVar4 & 0xff
  ;
  return;
}



