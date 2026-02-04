/* grim_shutdown @ 10005ff0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x18 (provisional): Grim2D shutdown */

void grim_shutdown(void)

{
  FUN_10005a40(&DAT_1005d828);
  grim_mouse_shutdown();
  grim_keyboard_shutdown();
  FUN_1000a330();
  FUN_10004280();
  grim_window_destroy();
  return;
}



