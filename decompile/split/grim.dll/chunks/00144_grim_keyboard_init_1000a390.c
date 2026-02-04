/* grim_keyboard_init @ 1000a390 */

/* initializes DirectInput keyboard device and acquires it */

int __cdecl grim_keyboard_init(int hwnd)

{
  HWND pHVar1;
  HMODULE pHVar2;
  uint uVar3;
  int iVar4;
  DWORD DVar5;
  REFIID pIVar6;
  LPDIRECTINPUT8A *ppIVar7;
  LPDIRECTINPUT8A pIVar8;
  DIPROPHEADER DStack_14;
  undefined4 uStack_4;
  
  if ((hwnd == 0) && (pHVar1 = GetForegroundWindow(), pHVar1 == (HWND)0x0)) {
    GetDesktopWindow();
  }
  if (grim_dinput_keyboard == (LPDIRECTINPUT8A)0x0) {
    ppIVar7 = &grim_dinput_keyboard;
    pIVar6 = (REFIID)&DAT_1005034c;
    DVar5 = 0x800;
    pIVar8 = grim_dinput_keyboard;
    pHVar2 = GetModuleHandleA((LPCSTR)0x0);
    uVar3 = DirectInput8Create(pHVar2,DVar5,pIVar6,ppIVar7,(LPUNKNOWN)pIVar8);
    if ((int)uVar3 < 0) {
      grim_dinput_keyboard = (LPDIRECTINPUT8A)0x0;
      return uVar3 & 0xffffff00;
    }
  }
  if (grim_keyboard_device == (LPDIRECTINPUTDEVICE8A)0x0) {
    uVar3 = (*grim_dinput_keyboard->lpVtbl->CreateDevice)
                      (grim_dinput_keyboard,(REFGUID)&DAT_1005029c,&grim_keyboard_device,
                       (LPUNKNOWN)0x0);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffff00;
    }
    uVar3 = (*grim_keyboard_device->lpVtbl->SetDataFormat)
                      (grim_keyboard_device,(LPCDIDATAFORMAT)&DAT_1005007c);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffff00;
    }
    uVar3 = (*grim_keyboard_device->lpVtbl->SetCooperativeLevel)
                      (grim_keyboard_device,(HWND)hwnd,0x16);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffff00;
    }
    DStack_14.dwSize = 0x14;
    DStack_14.dwHeaderSize = 0x10;
    DStack_14.dwObj = 0;
    DStack_14.dwHow = 0;
    uStack_4 = 10;
    (*grim_keyboard_device->lpVtbl->SetProperty)(grim_keyboard_device,(REFGUID)0x1,&DStack_14);
    if (grim_keyboard_device != (LPDIRECTINPUTDEVICE8A)0x0) {
      (*grim_keyboard_device->lpVtbl->Acquire)(grim_keyboard_device);
    }
  }
  iVar4 = grim_keyboard_poll();
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}



