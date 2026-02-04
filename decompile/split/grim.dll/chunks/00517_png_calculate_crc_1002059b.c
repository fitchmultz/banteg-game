/* png_calculate_crc @ 1002059b */

/* update png CRC with buffer */

void __cdecl png_calculate_crc(png_structp png_ptr,png_bytep data,png_uint_32 length)

{
  png_colorp ppVar1;
  
  if ((png_ptr->chunk_name[0] & 0x20) == 0) {
    if ((png_ptr->flags & 0x800) != 0) {
      return;
    }
  }
  else if ((png_ptr->flags & 0x300) == 0x300) {
    return;
  }
  ppVar1 = (png_colorp)FUN_10025aec((uint)png_ptr->palette,data,length);
  png_ptr->palette = ppVar1;
  return;
}



