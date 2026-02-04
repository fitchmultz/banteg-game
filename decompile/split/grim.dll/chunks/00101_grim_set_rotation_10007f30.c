/* grim_set_rotation @ 10007f30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xfc: precompute sin/cos (+45deg) for rotation matrix */

void grim_set_rotation(float radians)

{
  float10 fVar1;
  
  _grim_rotation_radians = radians;
  fVar1 = (float10)fcos((float10)radians + (float10)0.7853982);
  grim_rotation_cos = (float)fVar1;
  fVar1 = (float10)fsin((float10)radians + (float10)0.7853982);
  _DAT_1005a460 = grim_rotation_cos;
  _DAT_1005a46c = grim_rotation_cos;
  DAT_10059f40 = (float)fVar1;
  _DAT_1005a468 = -DAT_10059f40;
  _DAT_1005a464 = DAT_10059f40;
  return;
}



