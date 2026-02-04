/* grim_mouse_shutdown @ 1000a7d0 */

/* releases DirectInput mouse objects */

void grim_mouse_shutdown(void)

{
  if (grim_mouse_device != (LPDIRECTINPUTDEVICE8A)0x0) {
    (*grim_mouse_device->lpVtbl->Unacquire)(grim_mouse_device);
    (*grim_mouse_device->lpVtbl->Release)(grim_mouse_device);
    grim_mouse_device = (LPDIRECTINPUTDEVICE8A)0x0;
  }
  if (grim_dinput_mouse != (LPDIRECTINPUT8A)0x0) {
    (*grim_dinput_mouse->lpVtbl->Release)(grim_dinput_mouse);
    grim_dinput_mouse = (LPDIRECTINPUT8A)0x0;
  }
  return;
}



