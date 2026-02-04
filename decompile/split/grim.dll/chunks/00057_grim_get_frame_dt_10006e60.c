/* grim_get_frame_dt @ 10006e60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x3c: clamped frame delta */

float grim_get_frame_dt(void)

{
  if (0.1 < _grim_frame_dt) {
    return 0.1;
  }
  return _grim_frame_dt;
}



