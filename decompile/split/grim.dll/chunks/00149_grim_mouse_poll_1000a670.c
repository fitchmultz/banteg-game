/* grim_mouse_poll @ 1000a670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* polls the mouse device and updates cached position/delta */

int grim_mouse_poll(void)

{
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  int extraout_EAX;
  int iVar4;
  
  iVar2 = 0;
  if (grim_mouse_device != (LPDIRECTINPUTDEVICE8A)0x0) {
    grim_mouse_state.lX = 0;
    _DAT_1005db58 = 0.0;
    grim_mouse_state.lY = 0;
    _grim_mouse_dy = 0.0;
    grim_mouse_state.lZ = 0;
    _grim_mouse_dx = 0.0;
    grim_mouse_state.rgbButtons[0] = '\0';
    grim_mouse_state.rgbButtons[1] = '\0';
    grim_mouse_state.rgbButtons[2] = '\0';
    grim_mouse_state.rgbButtons[3] = '\0';
    grim_mouse_state.rgbButtons[4] = '\0';
    grim_mouse_state.rgbButtons[5] = '\0';
    grim_mouse_state.rgbButtons[6] = '\0';
    grim_mouse_state.rgbButtons[7] = '\0';
    iVar1 = (*grim_mouse_device->lpVtbl->GetDeviceState)(grim_mouse_device,0x14,&grim_mouse_state);
    iVar2 = 0;
    while (-1 < iVar1) {
      iVar4 = iVar2 + 1;
      _grim_mouse_dx = (float)grim_mouse_state.lX + _grim_mouse_dx;
      _grim_mouse_dy = (float)grim_mouse_state.lY + _grim_mouse_dy;
      _DAT_1005db58 = (float)grim_mouse_state.lZ + _DAT_1005db58;
      if ((99 < iVar2) ||
         (((grim_mouse_state.lX == 0 && (grim_mouse_state.lY == 0)) &&
          (iVar2 = 0, grim_mouse_state.lZ == 0)))) {
        if (2 < iVar4) {
          grim_noop();
          iVar2 = extraout_EAX;
        }
        grim_mouse_x = grim_mouse_x + _grim_mouse_dx;
        grim_mouse_y = grim_mouse_y + _grim_mouse_dy;
        _DAT_1005db4c = _DAT_1005db4c + _DAT_1005db58;
        goto LAB_1000a7cb;
      }
      grim_mouse_state.lX = 0;
      grim_mouse_state.lY = 0;
      grim_mouse_state.lZ = 0;
      grim_mouse_state.rgbButtons[0] = '\0';
      grim_mouse_state.rgbButtons[1] = '\0';
      grim_mouse_state.rgbButtons[2] = '\0';
      grim_mouse_state.rgbButtons[3] = '\0';
      grim_mouse_state.rgbButtons[4] = '\0';
      grim_mouse_state.rgbButtons[5] = '\0';
      grim_mouse_state.rgbButtons[6] = '\0';
      grim_mouse_state.rgbButtons[7] = '\0';
      iVar1 = (*grim_mouse_device->lpVtbl->GetDeviceState)(grim_mouse_device,0x14,&grim_mouse_state)
      ;
      iVar2 = iVar4;
    }
    iVar2 = (*grim_mouse_device->lpVtbl->Acquire)(grim_mouse_device);
    if (iVar2 == -0x7ff8ffe2) {
      do {
        HVar3 = (*grim_mouse_device->lpVtbl->Acquire)(grim_mouse_device);
      } while (HVar3 == -0x7ff8ffe2);
      return CONCAT31((int3)((uint)HVar3 >> 8),1);
    }
  }
LAB_1000a7cb:
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}



