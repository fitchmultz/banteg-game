/* grim_set_mouse_pos @ 10007530 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x64: set cached mouse position */

void grim_set_mouse_pos(float x,float y)

{
  grim_mouse_x = x;
  grim_mouse_y = y;
  _grim_mouse_x_cached = x;
  _grim_mouse_y_cached = y;
  return;
}



