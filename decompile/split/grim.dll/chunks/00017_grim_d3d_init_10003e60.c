/* grim_d3d_init @ 10003e60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* creates the Direct3D8 interface, configures display mode, and opens the window */

int grim_d3d_init(void)

{
  byte bVar1;
  char *pcVar2;
  HRESULT HVar3;
  uint uVar4;
  BOOL BVar5;
  undefined4 uVar6;
  HRSRC pHVar7;
  HGLOBAL pvVar8;
  LPVOID pvVar9;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  D3DDISPLAYMODE DStack_43c;
  D3DADAPTER_IDENTIFIER8 DStack_42c;
  
  DAT_1005c898 = 0;
  grim_d3d8 = (LPDIRECT3D8)0x0;
  grim_d3d_device = (LPDIRECT3DDEVICE8)0x0;
  DAT_1005b2b4 = D3DDEVTYPE_HAL;
  if ((char)DAT_1005cec8 == '\x01') {
    DAT_1005b2b4 = D3DDEVTYPE_REF;
  }
  grim_d3d8 = Direct3DCreate8(0xdc);
  if (grim_d3d8 == (IDirect3D8 *)0x0) {
    grim_error_text = s_D3D__Could_not_init_DirectX_8_1__10053a60;
    return 0;
  }
  (*grim_d3d8->lpVtbl->GetDeviceCaps)(grim_d3d8,DAT_1005d3e8,DAT_1005b2b4,(D3DCAPS8 *)&DAT_1005a498)
  ;
  bVar1 = 0;
  (*grim_d3d8->lpVtbl->GetAdapterIdentifier)(grim_d3d8,DAT_1005d3e8,2,&DStack_42c);
  pcVar2 = strchr(DStack_42c.Description,0x56);
  if (((((pcVar2 != (char *)0x0) && (pcVar2[1] == 'o')) && (pcVar2[2] == 'o')) &&
      ((pcVar2[3] == 'd' && (pcVar2[4] == 'o')))) && ((pcVar2[5] == 'o' && (pcVar2[6] == '3')))) {
    bVar1 = 1;
  }
  HVar3 = (*grim_d3d8->lpVtbl->GetAdapterDisplayMode)(grim_d3d8,0,&DStack_43c);
  if (HVar3 < 0) {
    grim_error_text = s_D3D__Error_getting_adapter_displ_10053a34;
    uVar4 = 0;
    if ((grim_d3d8 != (LPDIRECT3D8)0x0) &&
       (uVar4 = (*grim_d3d8->lpVtbl->Release)(grim_d3d8), uVar4 == 0)) {
      grim_d3d8 = (LPDIRECT3D8)0x0;
    }
    return uVar4 & 0xffffff00;
  }
  BVar5 = grim_window_create();
  uVar6 = DAT_1005ceb8;
  if ((char)BVar5 == '\0') {
    return BVar5;
  }
  puVar12 = &grim_present_width;
  for (iVar11 = 0xd; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  _DAT_10059e04 = uVar6;
  if (DAT_1005cc08 != '\x01') {
    _DAT_10059e0c = bVar1 + 1;
    _DAT_10059e24 = 0;
    _DAT_10059e28 = 0x80000000;
  }
  else {
    _DAT_10059e0c = 1;
    grim_texture_format = (IDirect3D8 *)DStack_43c.Format;
  }
  _DAT_10059e14 = (uint)(DAT_1005cc08 == '\x01');
  grim_present_height = grim_backbuffer_height;
  grim_present_width = grim_backbuffer_width;
  _DAT_10059e00 = grim_texture_format;
  _DAT_10059e08 = 0;
  _DAT_10059e20 = 1;
  _DAT_10059e18 = (uint)(DAT_1005ced8 != '\0');
  _DAT_10059e1c = 0x50;
  _DAT_10059e10 = DAT_1005d3fc;
  if (DAT_1005d3fc == (HWND)0x0) {
    _DAT_10059e10 = DAT_1005d3f8;
  }
  HVar3 = (*grim_d3d8->lpVtbl->CreateDevice)
                    (grim_d3d8,DAT_1005d3e8,DAT_1005b2b4,DAT_1005d3f8,0x20,
                     (D3DPRESENT_PARAMETERS *)&grim_present_width,&grim_d3d_device);
  if (HVar3 < 0) {
    grim_error_text = s_D3D__Could_not_set_the_requested_10053a04;
    MessageBoxA((HWND)0x0,s_D3D__Could_not_set_the_requested_10053a04,&DAT_10053824,0);
    FUN_10004280();
    uVar4 = grim_window_destroy();
    return uVar4 & 0xffffff00;
  }
  (*grim_d3d8->lpVtbl->GetDeviceCaps)(grim_d3d8,DAT_1005d3e8,DAT_1005b2b4,(D3DCAPS8 *)&DAT_1005a498)
  ;
  uVar6 = FUN_10004350();
  if ((char)uVar6 == '\0') {
    FUN_10004280();
    uVar4 = grim_window_destroy();
    return uVar4 & 0xffffff00;
  }
  puVar12 = &grim_texture_slots;
  for (iVar11 = 0x100; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  if (grim_preferred_texture_format != (void *)0x0) {
    iVar11 = grim_is_texture_format_supported((uint)grim_preferred_texture_format);
    if ((char)iVar11 == '\0') {
      grim_preferred_texture_format = (void *)0x0;
    }
    else if (grim_preferred_texture_format != (void *)0x0) goto LAB_10004142;
  }
  iVar11 = grim_select_texture_format();
  if ((char)iVar11 == '\0') {
    grim_error_text = s_D3D__Could_not_find_any_compatib_100539d0;
    FUN_10004280();
    grim_window_destroy();
  }
LAB_10004142:
  FUN_10004520();
  pHVar7 = FindResourceA(grim_module_handle,(LPCSTR)0x6f,(LPCSTR)0xa);
  pvVar8 = LoadResource(grim_module_handle,pHVar7);
  pvVar9 = LockResource(pvVar8);
  piVar10 = (int *)SizeofResource(grim_module_handle,pHVar7);
  uVar4 = FUN_1000cb5c((int **)grim_d3d_device,pvVar9,piVar10,-1,-1,1,0,
                       grim_preferred_texture_format,1,-1,(int **)0xffffffff,0,0,0,0x1005d3ec);
  if ((int)uVar4 < 0) {
    grim_error_text = s_D3D__Unable_to_load_default_font_100539a4;
    return uVar4 & 0xffffff00;
  }
  pHVar7 = FindResourceA(grim_module_handle,(LPCSTR)0x71,(LPCSTR)0xa);
  pvVar8 = LoadResource(grim_module_handle,pHVar7);
  pvVar9 = LockResource(pvVar8);
  piVar10 = (int *)SizeofResource(grim_module_handle,pHVar7);
  uVar4 = FUN_1000cb5c((int **)grim_d3d_device,pvVar9,piVar10,-1,-1,1,0,
                       grim_preferred_texture_format,1,-1,(int **)0xffffffff,0,0,0,0x1005d3f0);
  if ((int)uVar4 < 0) {
    grim_error_text = s_D3D__Unable_to_load_grim_splash_t_10053978;
    return uVar4 & 0xffffff00;
  }
  grim_backbuffer_surface = (LPDIRECT3DSURFACE8)0x0;
  grim_render_target_surface = (LPDIRECT3DSURFACE8)0x0;
  _DAT_1005d094 = grim_d3d8;
  _DAT_1005d0a4 = grim_d3d_device;
  DAT_1005c898 = 1;
  return CONCAT31((int3)((uint)grim_d3d8 >> 8),1);
}



