/* grim_window_destroy @ 10002880 */

/* posts quit and destroys the main window */

BOOL grim_window_destroy(void)

{
  WINBOOL WVar1;
  
  PostQuitMessage(0);
  if (DAT_1005d3f8 != (HWND)0x0) {
    DestroyWindow(DAT_1005d3f8);
  }
  if (DAT_1005d3fc != 0) {
    DestroyWindow(DAT_1005d3f8);
  }
  WVar1 = UnregisterClassA(DAT_10059df0,DAT_10059ddc);
  return WVar1;
}



