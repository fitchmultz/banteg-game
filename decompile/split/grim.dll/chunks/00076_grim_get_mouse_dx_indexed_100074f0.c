/* grim_get_mouse_dx_indexed @ 100074f0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x78: alias of get_mouse_dx */

float grim_get_mouse_dx_indexed(int index)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x70))();
  return (float)fVar1;
}



