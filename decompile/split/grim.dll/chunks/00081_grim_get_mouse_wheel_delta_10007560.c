/* grim_get_mouse_wheel_delta @ 10007560 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x60 (provisional) */

float grim_get_mouse_wheel_delta(void)

{
  if (grim_input_cached != '\0') {
    return _DAT_1005d3b8;
  }
  return _DAT_1005db58;
}



