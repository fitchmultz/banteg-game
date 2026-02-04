/* grim_is_mouse_button_down @ 10007410 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x58: cached mouse button state or poll */

int grim_is_mouse_button_down(int button)

{
  int iVar1;
  
  if (grim_input_cached != '\0') {
    return CONCAT31((int3)((uint)button >> 8),(&grim_mouse_button_cache)[button]);
  }
  iVar1 = grim_mouse_button_down(button);
  return iVar1;
}



