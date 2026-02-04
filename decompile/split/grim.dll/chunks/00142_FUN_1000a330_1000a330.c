/* FUN_1000a330 @ 1000a330 */

void FUN_1000a330(void)

{
  if (grim_joystick_device != (LPDIRECTINPUTDEVICE8A)0x0) {
    (*grim_joystick_device->lpVtbl->Unacquire)(grim_joystick_device);
    (*grim_joystick_device->lpVtbl->Release)(grim_joystick_device);
    grim_joystick_device = (LPDIRECTINPUTDEVICE8A)0x0;
  }
  if (grim_dinput_joystick != (LPDIRECTINPUT8A)0x0) {
    (*grim_dinput_joystick->lpVtbl->Release)(grim_dinput_joystick);
    grim_dinput_joystick = (LPDIRECTINPUT8A)0x0;
  }
  return;
}



