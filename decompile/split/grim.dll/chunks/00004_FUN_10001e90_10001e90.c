/* FUN_10001e90 @ 10001e90 */

/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */

void FUN_10001e90(void)

{
  HWND pHVar1;
  HRESULT HVar2;
  uint wParam;
  WPARAM WVar3;
  char *pcVar4;
  UINT UVar5;
  LPARAM LVar6;
  
  wParam = DAT_1005cec8 & 0xff;
  LVar6 = 0;
  UVar5 = 0xf1;
  DAT_10053064 = (byte)(DAT_1005a4a4 >> 0x13) & 1;
  pHVar1 = GetDlgItem(DAT_1005b2b0,0x3ed);
  SendMessageA(pHVar1,UVar5,wParam,LVar6);
  DAT_1005d400 = DAT_1005d0c8;
  HVar2 = (*grim_d3d8_probe->lpVtbl->CheckDeviceType)
                    (grim_d3d8_probe,0,D3DDEVTYPE_HAL,D3DFMT_X8R8G8B8,D3DFMT_X8R8G8B8,0);
  LVar6 = 0;
  WVar3 = 0;
  DAT_10053065 = -1 < HVar2;
  UVar5 = 0x14b;
  pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
  SendMessageA(pHVar1,UVar5,WVar3,LVar6);
  if (DAT_10053064 != 0) {
    pcVar4 = s_640x480__windowed__10053440;
    WVar3 = 0;
    UVar5 = 0x143;
    pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
    SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
    pcVar4 = s_800x600__windowed__1005342c;
    WVar3 = 0;
    UVar5 = 0x143;
    pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
    SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
    pcVar4 = s_960x600__wide_window__10053414;
    WVar3 = 0;
    UVar5 = 0x143;
    pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
    SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
    pcVar4 = s_1024x768__windowed__10053400;
    WVar3 = 0;
    UVar5 = 0x143;
    pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
    SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
  }
  pcVar4 = s_640x480x16_100533f4;
  WVar3 = 0;
  UVar5 = 0x143;
  pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
  SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
  pcVar4 = s_800x600x16_100533e8;
  WVar3 = 0;
  UVar5 = 0x143;
  pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
  SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
  pcVar4 = s_960x600x16__wide__100533d4;
  WVar3 = 0;
  UVar5 = 0x143;
  pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
  SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
  pcVar4 = s_1024x768x16_100533c8;
  WVar3 = 0;
  UVar5 = 0x143;
  pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
  SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
  if (DAT_10053065 != '\0') {
    pcVar4 = s_640x480x32_100533bc;
    WVar3 = 0;
    UVar5 = 0x143;
    pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
    SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
    pcVar4 = s_800x600x32_100533b0;
    WVar3 = 0;
    UVar5 = 0x143;
    pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
    SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
    pcVar4 = s_960x600x32__wide__1005339c;
    WVar3 = 0;
    UVar5 = 0x143;
    pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
    SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
    pcVar4 = s_1024x768x32_10053390;
    WVar3 = 0;
    UVar5 = 0x143;
    pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
    SendMessageA(pHVar1,UVar5,WVar3,(LPARAM)pcVar4);
  }
  if (DAT_1005ce18 == 0x280) {
    WVar3 = 0;
  }
  else if (DAT_1005ce18 == 800) {
    WVar3 = 1;
  }
  else if (DAT_1005ce18 == 0x3c0) {
    WVar3 = 2;
  }
  else if (DAT_1005ce18 == 0x400) {
    WVar3 = 3;
  }
  else {
    WVar3 = (-(uint)(DAT_1005ce18 != 0x690) & 0xfffffffd) + 4;
  }
  if ((DAT_1005cc08 != '\x01') || (DAT_10053064 == 0)) {
    if (DAT_1005ce38 == 0x10) {
      WVar3 = WVar3 + 4;
    }
    else if (DAT_1005ce38 == 0x20) {
      WVar3 = WVar3 + 8;
    }
    if (DAT_10053064 == 0) {
      WVar3 = WVar3 - 4;
    }
  }
  LVar6 = 0;
  UVar5 = 0x14e;
  pHVar1 = GetDlgItem(DAT_1005b2b0,0x3f9);
  SendMessageA(pHVar1,UVar5,WVar3,LVar6);
  return;
}



