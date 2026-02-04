/* grim_joystick_poll @ 1000a2b0 */

/* polls the joystick device and updates cached state */

int grim_joystick_poll(void)

{
  HRESULT HVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((grim_dinput_joystick != (LPDIRECTINPUT8A)0x0) &&
     (uVar2 = 0, grim_joystick_device != (LPDIRECTINPUTDEVICE8A)0x0)) {
    HVar1 = (*grim_joystick_device->lpVtbl->Poll)(grim_joystick_device);
    if (-1 < HVar1) {
      HVar1 = (*grim_joystick_device->lpVtbl->GetDeviceState)
                        (grim_joystick_device,0x110,&grim_joystick_state);
      return CONCAT31((int3)((uint)HVar1 >> 8),-1 < HVar1);
    }
    uVar2 = (*grim_joystick_device->lpVtbl->Acquire)(grim_joystick_device);
    while (uVar2 == 0x8007001e) {
      uVar2 = (*grim_joystick_device->lpVtbl->Acquire)(grim_joystick_device);
    }
  }
  return uVar2 & 0xffffff00;
}



