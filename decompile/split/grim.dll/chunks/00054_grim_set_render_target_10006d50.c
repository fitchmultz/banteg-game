/* grim_set_render_target @ 10006d50 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0x30 (provisional): set render target; -1 resets */

int grim_set_render_target(int target_index)

{
  undefined4 in_EAX;
  uint uVar1;
  ULONG UVar2;
  
  UVar2 = CONCAT31((int3)((uint)in_EAX >> 8),grim_render_disabled);
  if (grim_render_disabled == '\0') {
    if (target_index < 0) {
      if (grim_backbuffer_surface != (LPDIRECT3DSURFACE8)0x0) {
        if (grim_render_target_surface != (LPDIRECT3DSURFACE8)0x0) {
          (*grim_render_target_surface->lpVtbl->Release)(grim_render_target_surface);
        }
        grim_render_target_surface = (LPDIRECT3DSURFACE8)0x0;
        uVar1 = (*grim_d3d_device->lpVtbl->SetRenderTarget)
                          (grim_d3d_device,grim_backbuffer_surface,(IDirect3DSurface8 *)0x0);
        if ((int)uVar1 < 0) {
          return uVar1 & 0xffffff00;
        }
        UVar2 = 0;
        if (grim_backbuffer_surface != (LPDIRECT3DSURFACE8)0x0) {
          UVar2 = (*grim_backbuffer_surface->lpVtbl->Release)(grim_backbuffer_surface);
        }
        grim_backbuffer_surface = (LPDIRECT3DSURFACE8)0x0;
      }
    }
    else {
      if (grim_render_target_surface != (LPDIRECT3DSURFACE8)0x0) {
        (*grim_render_target_surface->lpVtbl->Release)(grim_render_target_surface);
        grim_render_target_surface = (LPDIRECT3DSURFACE8)0x0;
      }
      if (grim_backbuffer_surface == (LPDIRECT3DSURFACE8)0x0) {
        (*grim_d3d_device->lpVtbl->GetRenderTarget)(grim_d3d_device,&grim_backbuffer_surface);
      }
      uVar1 = (**(code **)(**(int **)((&grim_texture_slots)[target_index] + 4) + 0x3c))
                        (*(int **)((&grim_texture_slots)[target_index] + 4),0,
                         &grim_render_target_surface);
      if ((int)uVar1 < 0) {
        return uVar1 & 0xffffff00;
      }
      UVar2 = (*grim_d3d_device->lpVtbl->SetRenderTarget)
                        (grim_d3d_device,grim_render_target_surface,(IDirect3DSurface8 *)0x0);
      if ((int)UVar2 < 0) {
        uVar1 = 0;
        if (grim_render_target_surface != (LPDIRECT3DSURFACE8)0x0) {
          uVar1 = (*grim_render_target_surface->lpVtbl->Release)(grim_render_target_surface);
        }
        grim_render_target_surface = (LPDIRECT3DSURFACE8)0x0;
        return uVar1 & 0xffffff00;
      }
    }
  }
  return CONCAT31((int3)(UVar2 >> 8),1);
}



