/* grim_is_texture_format_supported @ 100047f0 */

/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* checks device support for a texture format */

int __cdecl grim_is_texture_format_supported(uint format)

{
  HRESULT HVar1;
  
  HVar1 = (*grim_d3d8->lpVtbl->CheckDeviceFormat)
                    (grim_d3d8,DAT_1005d3e8,DAT_1005b2b4,grim_texture_format,0,D3DRTYPE_TEXTURE,
                     format);
  return CONCAT31((int3)((uint)HVar1 >> 8),-1 < HVar1);
}



