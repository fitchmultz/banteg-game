/* grim_select_texture_format @ 10004830 */

/* chooses the first supported texture format */

int grim_select_texture_format(void)

{
  int iVar1;
  uint3 uVar2;
  
  iVar1 = grim_is_texture_format_supported(0x15);
  if ((char)iVar1 != '\0') {
    grim_preferred_texture_format = 0x15;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  iVar1 = grim_is_texture_format_supported(0x33545844);
  if ((char)iVar1 != '\0') {
    grim_preferred_texture_format = 0x33545844;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  iVar1 = grim_is_texture_format_supported(0x1a);
  if ((char)iVar1 != '\0') {
    grim_preferred_texture_format = 0x1a;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  iVar1 = grim_is_texture_format_supported(0x19);
  if ((char)iVar1 != '\0') {
    grim_preferred_texture_format = 0x19;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  iVar1 = grim_is_texture_format_supported(0x14);
  if ((char)iVar1 != '\0') {
    grim_preferred_texture_format = 0x14;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  iVar1 = grim_is_texture_format_supported(0x16);
  if ((char)iVar1 != '\0') {
    grim_preferred_texture_format = 0x16;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  iVar1 = grim_is_texture_format_supported(0x14);
  if ((char)iVar1 != '\0') {
    grim_preferred_texture_format = 0x14;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  iVar1 = grim_is_texture_format_supported(0x17);
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if ((char)iVar1 != '\0') {
    grim_preferred_texture_format = 0x17;
    return CONCAT31(uVar2,1);
  }
  grim_error_text = s_D3D__No_supported_texture_format_10053af4;
  return (uint)uVar2 << 8;
}



