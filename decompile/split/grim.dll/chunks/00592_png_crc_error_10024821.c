/* png_crc_error @ 10024821 */

/* read stored CRC and compare with computed */

int __cdecl png_crc_error(png_structp png_ptr)

{
  bool bVar1;
  png_structp ppVar2;
  png_colorp ppVar3;
  uint uVar4;
  
  ppVar2 = png_ptr;
  bVar1 = true;
  if ((png_ptr->chunk_name[0] & 0x20) == 0) {
    if ((png_ptr->flags & 0x800) == 0) goto LAB_1002484d;
  }
  else if ((png_ptr->flags & 0x300) != 0x300) goto LAB_1002484d;
  bVar1 = false;
LAB_1002484d:
  png_read_data(png_ptr,(png_bytep)&png_ptr,4);
  if (bVar1) {
    ppVar3 = (png_colorp)png_get_uint_32((png_bytep)&png_ptr);
    uVar4 = (uint)(ppVar3 != ppVar2->palette);
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



