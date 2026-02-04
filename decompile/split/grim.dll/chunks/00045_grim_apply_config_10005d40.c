/* grim_apply_config @ 10005d40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0x10: opens D3D config dialog and applies settings */

int grim_apply_config(void)

{
  uint uVar1;
  int *in_ECX;
  
  if (DAT_10059778 == (HICON)0x0) {
    DAT_10059778 = LoadIconA(grim_module_handle,(LPCSTR)0x72);
  }
  grim_config_dialog_canceled = '\0';
  grim_d3d8_probe = Direct3DCreate8(0xdc);
  if (grim_d3d8_probe == (IDirect3D8 *)0x0) {
    grim_error_text = s_D3D__Could_not_init_DirectX_8_1__10053a60;
    uVar1 = MessageBoxA((HWND)0x0,s_D3D__Could_not_init_DirectX_8_1__10053a60,&DAT_10053824,0);
    return uVar1 & 0xffffff00;
  }
  (*grim_d3d8_probe->lpVtbl->GetDeviceCaps)
            (grim_d3d8_probe,0,D3DDEVTYPE_HAL,(D3DCAPS8 *)&DAT_1005a498);
  DialogBoxParamA(grim_module_handle,(LPCSTR)0x74,(HWND)0x0,grim_config_dialog_proc,0);
  (*grim_d3d8_probe->lpVtbl->Release)(grim_d3d8_probe);
  if (grim_config_dialog_canceled == '\0') {
    (**(code **)(*in_ECX + 0x20))(0x54,DAT_1005d400);
    if ((char)DAT_1005b2b8 == '\0') {
      (**(code **)(*in_ECX + 0x20))(0x2b,0x20);
    }
    else {
      (**(code **)(*in_ECX + 0x20))(0x2b,0x10);
    }
    (**(code **)(*in_ECX + 0x20))(0x54,DAT_1005d400);
    (**(code **)(*in_ECX + 0x20))(8,DAT_1005b280);
    (**(code **)(*in_ECX + 0x20))(0x34,0);
    (**(code **)(*in_ECX + 0x20))(8,DAT_1005b280);
    (**(code **)(*in_ECX + 0x20))(0x29,DAT_10053054);
    (**(code **)(*in_ECX + 0x20))(0x2a,DAT_10053058);
  }
  return (uint)(grim_config_dialog_canceled == '\0');
}



