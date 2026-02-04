/* png_crc_finish @ 100250d7 */

/* read remaining chunk bytes and check CRC */

int __cdecl png_crc_finish(png_structp png_ptr,png_uint_32 skip)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  uVar1 = png_ptr->zbuf_size;
  for (; uVar1 < skip; skip = skip - uVar1) {
    png_crc_read(png_ptr,png_ptr->zbuf,png_ptr->zbuf_size);
  }
  if (skip != 0) {
    png_crc_read(png_ptr,png_ptr->zbuf,skip);
  }
  iVar3 = png_crc_error(png_ptr);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    bVar2 = png_ptr->chunk_name[0] & 0x20;
    if (((bVar2 == 0) || ((png_ptr->flags & 0x200) != 0)) &&
       ((bVar2 != 0 || ((png_ptr->flags & 0x400) == 0)))) {
      FUN_1001e147(png_ptr,(undefined4 *)"CRC error");
    }
    else {
      FUN_1001e16c(png_ptr,(undefined4 *)"CRC error");
    }
    iVar3 = 1;
  }
  return iVar3;
}



