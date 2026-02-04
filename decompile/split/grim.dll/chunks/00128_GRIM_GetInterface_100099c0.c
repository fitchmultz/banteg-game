/* GRIM__GetInterface @ 100099c0 */

/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* export: constructs (singleton) Grim2D interface instance backed by grim_interface_vtable */

IGrim2D * GRIM__GetInterface(void)

{
                    /* 0x99c0  1  GRIM__GetInterface */
  grim_d3d8_probe = Direct3DCreate8(0xdc);
  if (grim_d3d8_probe == (IDirect3D8 *)0x0) {
    grim_error_text = s_D3D__Could_not_init_DirectX_8_1__10053a60;
    MessageBoxA((HWND)0x0,s_D3D__Could_not_init_DirectX_8_1__10053a60,&DAT_10053824,0);
    return (IGrim2D *)0x0;
  }
  (*grim_d3d8_probe->lpVtbl->Release)(grim_d3d8_probe);
  FUN_100052f0();
  grim_interface_instance = operator_new(4);
  if (grim_interface_instance != (IGrim2D *)0x0) {
    grim_interface_instance->vtable = &grim_interface_vtable;
    return grim_interface_instance;
  }
  grim_interface_instance = (IGrim2D *)0x0;
  return (IGrim2D *)0x0;
}



