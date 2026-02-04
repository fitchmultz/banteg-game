/* grim_config_dialog_proc @ 10002120 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* dialog procedure for the Grim2D config UI */

int grim_config_dialog_proc(int hwnd,uint msg,uint wparam,int lparam)

{
  undefined4 uVar1;
  HRESULT HVar2;
  LRESULT LVar3;
  char *pcVar4;
  HWND pHVar5;
  UINT UVar6;
  HRESULT HVar7;
  undefined4 *puVar8;
  UINT Adapter;
  bool bVar9;
  UINT UVar10;
  char *pcVar11;
  WPARAM WVar12;
  int iVar13;
  LPARAM LVar14;
  char *pcStack_404;
  char cStack_400;
  undefined4 uStack_3ff;
  char acStack_200 [512];
  
  if (msg == 0x10) {
LAB_10002629:
    grim_config_dialog_canceled = 1;
LAB_10002631:
    EndDialog((HWND)hwnd,wparam & 0xffff);
  }
  else {
    if (msg == 0x110) {
      iVar13 = 5;
      DAT_1005b2b0 = hwnd;
      pHVar5 = GetDlgItem((HWND)hwnd,0x3f2);
      ShowWindow(pHVar5,iVar13);
      iVar13 = 0;
      pHVar5 = GetDlgItem((HWND)hwnd,0x40b);
      ShowWindow(pHVar5,iVar13);
      SendMessageA((HWND)hwnd,0x80,1,DAT_10059778);
      SendMessageA((HWND)hwnd,0x80,0,DAT_10059778);
      GetLocalTime((LPSYSTEMTIME)&DAT_1005c408);
      UVar6 = (*grim_d3d8_probe->lpVtbl->GetAdapterCount)(grim_d3d8_probe);
      Adapter = 0;
      DAT_1005befc = '\0';
      if (0 < (int)UVar6) {
        do {
          (*grim_d3d8_probe->lpVtbl->GetAdapterIdentifier)
                    (grim_d3d8_probe,Adapter,2,(D3DADAPTER_IDENTIFIER8 *)&DAT_10059788);
          if (Adapter == 0) {
            pcVar11 = s__s__default__1005330c;
          }
          else {
            pcVar11 = &DAT_10053308;
          }
          sprintf(acStack_200,pcVar11,&DAT_10059988);
          HVar7 = (*grim_d3d8_probe->lpVtbl->CheckDeviceType)
                            (grim_d3d8_probe,Adapter,D3DDEVTYPE_HAL,D3DFMT_R5G6B5,D3DFMT_R5G6B5,0);
          if ((-1 < HVar7) ||
             (HVar7 = (*grim_d3d8_probe->lpVtbl->CheckDeviceType)
                                (grim_d3d8_probe,Adapter,D3DDEVTYPE_HAL,D3DFMT_X8R8G8B8,
                                 D3DFMT_X8R8G8B8,0), -1 < HVar7)) {
            pcVar11 = acStack_200;
            WVar12 = 0;
            UVar10 = 0x143;
            pHVar5 = GetDlgItem((HWND)hwnd,0x3f1);
            SendMessageA(pHVar5,UVar10,WVar12,(LPARAM)pcVar11);
            DAT_1005befc = '\x01';
          }
          Adapter = Adapter + 1;
        } while ((int)Adapter < (int)UVar6);
      }
      LVar14 = 0;
      UVar10 = 0x14e;
      WVar12 = DAT_1005d3e8;
      pHVar5 = GetDlgItem((HWND)hwnd,0x3f1);
      SendMessageA(pHVar5,UVar10,WVar12,LVar14);
      LVar14 = 0;
      WVar12 = 0;
      UVar10 = 0x147;
      pHVar5 = GetDlgItem((HWND)hwnd,0x3f1);
      DAT_1005d3e8 = SendMessageA(pHVar5,UVar10,WVar12,LVar14);
      FUN_10001e90();
      if (DAT_1005befc == '\0') {
        pcVar11 = s_No_supported_display_adapters_de_10053454;
        WVar12 = 0;
        UVar10 = 0x143;
        pHVar5 = GetDlgItem((HWND)hwnd,0x3f1);
        SendMessageA(pHVar5,UVar10,WVar12,(LPARAM)pcVar11);
        iVar13 = MessageBoxA((HWND)hwnd,s_No_supported_display_adapters_we_10053248,
                             s_Crimsonland_100532fc,0x33);
        if (iVar13 != 6) {
          grim_config_dialog_canceled = 1;
          EndDialog((HWND)hwnd,wparam & 0xffff);
        }
      }
      return 1;
    }
    if (msg != 0x111) {
      return 0;
    }
    switch(wparam & 0xffff) {
    case 1000:
      LVar14 = 0;
      WVar12 = 0;
      UVar10 = 0xf0;
      pHVar5 = GetDlgItem((HWND)hwnd,0x3ef);
      LVar3 = SendMessageA(pHVar5,UVar10,WVar12,LVar14);
      LVar14 = 0;
      WVar12 = 0;
      DAT_1005d0c8 = LVar3 != 0;
      UVar10 = 0x147;
      pHVar5 = GetDlgItem((HWND)hwnd,0x3f9);
      WVar12 = SendMessageA(pHVar5,UVar10,WVar12,LVar14);
      cStack_400 = '\0';
      puVar8 = &uStack_3ff;
      for (iVar13 = 0x7f; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      *(undefined2 *)puVar8 = 0;
      *(undefined1 *)((int)puVar8 + 2) = 0;
      pcVar11 = &cStack_400;
      UVar10 = 0x148;
      pHVar5 = GetDlgItem((HWND)hwnd,0x3f9);
      SendMessageA(pHVar5,UVar10,WVar12,(LPARAM)pcVar11);
      pcVar11 = strstr(&cStack_400,s_window_10053494);
      DAT_1005b280 = pcVar11 != (char *)0x0;
      pcVar11 = strchr(&cStack_400,0x78);
      *pcVar11 = '\0';
      pcVar4 = strchr(pcVar11 + 1,0x78);
      if (pcVar4 == (char *)0x0) {
        pcStack_404 = &DAT_10053490;
      }
      else {
        *pcVar4 = '\0';
        pcStack_404 = pcVar4 + 1;
        pcVar4[4] = '\0';
      }
      DAT_10053054 = atoi(&cStack_400);
      DAT_10053058 = atoi(pcVar11 + 1);
      DAT_1005ce18 = DAT_10053054;
      _DAT_1005ce28 = DAT_10053058;
      iVar13 = atoi(pcStack_404);
      bVar9 = iVar13 == 0x10;
      DAT_1005b2b8 = CONCAT31(DAT_1005b2b8._1_3_,bVar9);
      DAT_1005ce38 = (-(uint)bVar9 & 0xfffffff0) + 0x20;
      sprintf(&cStack_400,s_w___d_h__d_bpp__d_1005347c,DAT_10053054,DAT_10053058,bVar9);
      grim_config_dialog_canceled = 0;
      LVar14 = 0;
      WVar12 = 0;
      UVar10 = 0x147;
      pHVar5 = GetDlgItem((HWND)hwnd,0x3f1);
      DAT_1005d3e8 = SendMessageA(pHVar5,UVar10,WVar12,LVar14);
      goto LAB_10002631;
    case 0x3e9:
      goto LAB_10002629;
    case 0x3f1:
      LVar14 = 0;
      WVar12 = 0;
      UVar10 = 0x147;
      pHVar5 = GetDlgItem((HWND)hwnd,0x3f1);
      DAT_1005d3e8 = SendMessageA(pHVar5,UVar10,WVar12,LVar14);
      FUN_10001e90();
      return 0;
    case 0x3f2:
      HVar2 = HlinkNavigateString((IUnknown *)0x0,u_http___www_crimsonland_com_10053524);
      if (HVar2 < 0) {
        MessageBoxA((HWND)0x0,s_Failed_to_open_browser_at_http___100534ec,s_Crimsonland_100532fc,
                    0x30);
        return 0;
      }
      break;
    case 0x3f5:
      UVar10 = WinExec(s_explorer_exe_manual_html_100534d0,3);
      if (UVar10 < 0x20) {
        MessageBoxA((HWND)0x0,s_Failed_to_open_the_Crimsonland_M_1005349c,s_Crimsonland_100532fc,
                    0x30);
        return 0;
      }
      break;
    case 0x3fb:
      uVar1 = FUN_10001a30();
      if ((char)uVar1 != '\0') {
        DialogBoxParamA(grim_module_handle,(LPCSTR)0x89,(HWND)hwnd,(DLGPROC)&LAB_10001ad0,0);
        return 0;
      }
      MessageBoxA((HWND)hwnd,s_Unable_to_load_configuration_fil_1005355c,
                  s_Parental_lock_problem_1005359c,0x40);
      return 0;
    case 0x3fc:
      LVar14 = 0;
      WVar12 = 0;
      UVar10 = 0x147;
      pHVar5 = GetDlgItem((HWND)hwnd,0x3f1);
      DAT_1005d3e8 = SendMessageA(pHVar5,UVar10,WVar12,LVar14);
      DialogBoxParamA(grim_module_handle,(LPCSTR)0x8a,(HWND)hwnd,(DLGPROC)&LAB_10001170,0);
      return 0;
    }
  }
  return 0;
}



