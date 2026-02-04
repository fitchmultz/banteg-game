/* grim_check_device @ 10005cb0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xc: device creation test */

int grim_check_device(void)

{
  uint uVar1;
  HRESULT HVar2;
  ULONG UVar3;
  int iVar4;
  LPDIRECT3DDEVICE8 arg3;
  LPDIRECT3DDEVICE8 pDestSurface;
  IDirect3DSurface8 *pIStack_4;
  
  pIStack_4 = (IDirect3DSurface8 *)0x0;
  pDestSurface = grim_d3d_device;
  uVar1 = (*grim_d3d_device->lpVtbl->CreateImageSurface)
                    (grim_d3d_device,grim_present_width,grim_present_height,D3DFMT_A8R8G8B8,
                     &pIStack_4);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffff00;
  }
  arg3 = grim_d3d_device;
  HVar2 = (*grim_d3d_device->lpVtbl->GetFrontBuffer)
                    (grim_d3d_device,(IDirect3DSurface8 *)pDestSurface);
  if (HVar2 < 0) {
    UVar3 = (*arg3->lpVtbl->Release)(arg3);
    return UVar3 & 0xffffff00;
  }
  iVar4 = FUN_1000ae52((int)pDestSurface,0,(int *)arg3,0,(int *)0x0);
  if (iVar4 < 0) {
    UVar3 = (*arg3->lpVtbl->Release)(arg3);
    return UVar3 & 0xffffff00;
  }
  UVar3 = (*arg3->lpVtbl->Release)(arg3);
  return CONCAT31((int3)(UVar3 >> 8),1);
}



