/* grim_joystick_init @ 1000a1c0 */

/* initializes DirectInput joystick device and acquires it */

int __cdecl grim_joystick_init(int hwnd)

{
  HWND pHVar1;
  HMODULE pHVar2;
  uint uVar3;
  HRESULT HVar4;
  uint3 uVar6;
  int iVar5;
  DWORD DVar7;
  REFIID pIVar8;
  LPDIRECTINPUT8A *ppIVar9;
  LPDIRECTINPUT8A pIVar10;
  
  if ((hwnd == 0) && (pHVar1 = GetForegroundWindow(), pHVar1 == (HWND)0x0)) {
    GetDesktopWindow();
  }
  if (grim_dinput_joystick == (LPDIRECTINPUT8A)0x0) {
    ppIVar9 = &grim_dinput_joystick;
    pIVar8 = (REFIID)&DAT_1005034c;
    DVar7 = 0x800;
    pIVar10 = grim_dinput_joystick;
    pHVar2 = GetModuleHandleA((LPCSTR)0x0);
    uVar3 = DirectInput8Create(pHVar2,DVar7,pIVar8,ppIVar9,(LPUNKNOWN)pIVar10);
    if ((int)uVar3 < 0) {
      grim_dinput_joystick = (LPDIRECTINPUT8A)0x0;
      return uVar3 & 0xffffff00;
    }
  }
  if (grim_joystick_device == (LPDIRECTINPUTDEVICE8A)0x0) {
    HVar4 = (*grim_dinput_joystick->lpVtbl->EnumDevices)
                      (grim_dinput_joystick,4,(LPDIENUMDEVICESCALLBACKA)&LAB_1000a110,(LPVOID)0x0,1)
    ;
    uVar6 = (uint3)((uint)HVar4 >> 8);
    if (HVar4 < 0) {
      return (uint)uVar6 << 8;
    }
    if (DAT_1005d948 == '\0') {
      return (uint)uVar6 << 8;
    }
    uVar3 = (*grim_joystick_device->lpVtbl->SetDataFormat)
                      (grim_joystick_device,(LPCDIDATAFORMAT)&DAT_1004fe74);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffff00;
    }
    uVar3 = (*grim_joystick_device->lpVtbl->SetCooperativeLevel)(grim_joystick_device,(HWND)hwnd,5);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffff00;
    }
    uVar3 = (*grim_joystick_device->lpVtbl->EnumObjects)
                      (grim_joystick_device,(LPDIENUMDEVICEOBJECTSCALLBACKA)&LAB_1000a150,
                       (LPVOID)hwnd,0);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffff00;
    }
    if (grim_joystick_device != (LPDIRECTINPUTDEVICE8A)0x0) {
      (*grim_joystick_device->lpVtbl->Acquire)(grim_joystick_device);
    }
  }
  iVar5 = grim_joystick_poll();
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}



