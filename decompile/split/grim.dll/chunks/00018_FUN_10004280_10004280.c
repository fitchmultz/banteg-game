/* FUN_10004280 @ 10004280 */

/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */

void FUN_10004280(void)

{
  void *texture;
  ULONG UVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (grim_backbuffer_surface != (LPDIRECT3DSURFACE8)0x0) {
    UVar1 = (*grim_backbuffer_surface->lpVtbl->Release)(grim_backbuffer_surface);
    if (UVar1 == 0) {
      grim_backbuffer_surface = (LPDIRECT3DSURFACE8)0x0;
    }
  }
  if (grim_render_target_surface != (LPDIRECT3DSURFACE8)0x0) {
    UVar1 = (*grim_render_target_surface->lpVtbl->Release)(grim_render_target_surface);
    if (UVar1 == 0) {
      grim_render_target_surface = (LPDIRECT3DSURFACE8)0x0;
    }
  }
  if (grim_font_texture != (int *)0x0) {
    iVar2 = (**(code **)(*grim_font_texture + 8))(grim_font_texture);
    if (iVar2 == 0) {
      grim_font_texture = (int *)0x0;
    }
  }
  if (DAT_1005d3f0 != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_1005d3f0 + 8))(DAT_1005d3f0);
    if (iVar2 == 0) {
      DAT_1005d3f0 = (int *)0x0;
    }
  }
  puVar3 = &grim_texture_slots;
  do {
    texture = (void *)*puVar3;
    if (texture != (void *)0x0) {
      grim_texture_release(texture);
      operator_delete(texture);
      *puVar3 = 0;
    }
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < 0x1005d804);
  FUN_100044e0();
  if (grim_d3d_device != (LPDIRECT3DDEVICE8)0x0) {
    (*grim_d3d_device->lpVtbl->Release)(grim_d3d_device);
  }
  grim_d3d_device = (LPDIRECT3DDEVICE8)0x0;
  if (grim_d3d8 != (LPDIRECT3D8)0x0) {
    (*grim_d3d8->lpVtbl->Release)(grim_d3d8);
  }
  grim_d3d8 = (LPDIRECT3D8)0x0;
  return;
}



