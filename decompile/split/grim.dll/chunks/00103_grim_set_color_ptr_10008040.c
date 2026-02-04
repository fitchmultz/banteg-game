/* grim_set_color_ptr @ 10008040 */

/* Grim2D vtable 0x110: set color from float[4] */

void grim_set_color_ptr(float *rgba)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
  uVar1 = ftol();
  uVar2 = ftol();
  uVar3 = ftol();
  uVar4 = ftol();
  rgba = (float *)CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4);
  grim_color_slot0 = rgba;
  grim_color_slot3 = rgba;
  DAT_1005bc0c = rgba;
  DAT_1005bc08 = rgba;
  return;
}



