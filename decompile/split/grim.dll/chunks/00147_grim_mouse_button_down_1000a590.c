/* grim_mouse_button_down @ 1000a590 */

/* reads the cached mouse button state */

int __cdecl grim_mouse_button_down(int button)

{
  return CONCAT31((int3)((uint)button >> 8),grim_mouse_state.rgbButtons[button] >> 7);
}



