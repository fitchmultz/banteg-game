/* grim_keyboard_shutdown @ 1000a550 */

/* releases DirectInput keyboard objects */

void grim_keyboard_shutdown(void)

{
  if (grim_keyboard_device != (LPDIRECTINPUTDEVICE8A)0x0) {
    (*grim_keyboard_device->lpVtbl->Unacquire)(grim_keyboard_device);
    (*grim_keyboard_device->lpVtbl->Release)(grim_keyboard_device);
    grim_keyboard_device = (LPDIRECTINPUTDEVICE8A)0x0;
  }
  if (grim_dinput_keyboard != (LPDIRECTINPUT8A)0x0) {
    (*grim_dinput_keyboard->lpVtbl->Release)(grim_dinput_keyboard);
    grim_dinput_keyboard = (LPDIRECTINPUT8A)0x0;
  }
  return;
}



