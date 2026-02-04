/* grim_bind_texture @ 10007830 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xc4: bind texture handle to stage */

void grim_bind_texture(int handle,int stage)

{
  IDirect3DBaseTexture8 *pTexture;
  
  if (((-1 < handle) && ((&grim_texture_slots)[handle] != 0)) &&
     (pTexture = *(IDirect3DBaseTexture8 **)((&grim_texture_slots)[handle] + 4),
     pTexture != (IDirect3DBaseTexture8 *)0x0)) {
    (*grim_d3d_device->lpVtbl->SetTexture)(grim_d3d_device,stage,pTexture);
    _grim_bound_texture_handle = handle;
  }
  return;
}



