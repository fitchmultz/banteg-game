/* grim_get_mouse_dy_indexed @ 10007500 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x7c: alias of get_mouse_dy */

float grim_get_mouse_dy_indexed(int index)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x74))();
  return (float)fVar1;
}



