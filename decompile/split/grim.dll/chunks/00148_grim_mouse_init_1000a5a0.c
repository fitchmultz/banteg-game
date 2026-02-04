/* grim_mouse_init @ 1000a5a0 */

/* initializes DirectInput mouse device and acquires it */

int grim_mouse_init(void)

{
  HWND hwnd;
  HWND pHVar1;
  HMODULE pHVar2;
  uint uVar3;
  int iVar4;
  DWORD DVar5;
  REFIID pIVar6;
  LPDIRECTINPUT8A *ppIVar7;
  LPDIRECTINPUT8A pIVar8;
  
  hwnd = DAT_1005d3f8;
  if ((DAT_1005d3f8 == (HWND)0x0) && (pHVar1 = GetForegroundWindow(), pHVar1 == (HWND)0x0)) {
    GetDesktopWindow();
  }
  if (grim_dinput_mouse == (LPDIRECTINPUT8A)0x0) {
    ppIVar7 = &grim_dinput_mouse;
    pIVar6 = (REFIID)&DAT_1005034c;
    DVar5 = 0x800;
    pIVar8 = grim_dinput_mouse;
    pHVar2 = GetModuleHandleA((LPCSTR)0x0);
    uVar3 = DirectInput8Create(pHVar2,DVar5,pIVar6,ppIVar7,(LPUNKNOWN)pIVar8);
    if ((int)uVar3 < 0) {
      grim_dinput_mouse = (LPDIRECTINPUT8A)0x0;
      return uVar3 & 0xffffff00;
    }
  }
  if (grim_mouse_device == (LPDIRECTINPUTDEVICE8A)0x0) {
    uVar3 = (*grim_dinput_mouse->lpVtbl->CreateDevice)
                      (grim_dinput_mouse,(REFGUID)&DAT_100502ac,&grim_mouse_device,(LPUNKNOWN)0x0);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffff00;
    }
    uVar3 = (*grim_mouse_device->lpVtbl->SetDataFormat)
                      (grim_mouse_device,(LPCDIDATAFORMAT)&DAT_10050284);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffff00;
    }
    uVar3 = (*grim_mouse_device->lpVtbl->SetCooperativeLevel)(grim_mouse_device,hwnd,5);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffff00;
    }
    if (grim_mouse_device != (LPDIRECTINPUTDEVICE8A)0x0) {
      (*grim_mouse_device->lpVtbl->Acquire)(grim_mouse_device);
    }
  }
  iVar4 = grim_mouse_poll();
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}



