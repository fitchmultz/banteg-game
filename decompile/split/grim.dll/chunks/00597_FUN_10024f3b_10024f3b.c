/* FUN_10024f3b @ 10024f3b */

void __cdecl FUN_10024f3b(png_structp png_ptr)

{
  png_byte pVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  png_bytep ppVar5;
  png_uint_32 pVar6;
  
  (png_ptr->zstream).words[1] = 0;
  FUN_10020036(png_ptr);
  uVar3 = png_ptr->height;
  if (png_ptr->interlaced == '\0') {
    pVar6 = png_ptr->width;
    png_ptr->num_rows = uVar3;
    png_ptr->row_number = pVar6;
    png_ptr->iwidth = png_ptr->rowbytes + 1;
  }
  else {
    if ((png_ptr->transformations & 2) == 0) {
      uVar3 = uVar3 + 7 >> 3;
    }
    pVar6 = png_ptr->width;
    png_ptr->num_rows = uVar3;
    iVar4 = (uint)png_ptr->pass * 4;
    uVar3 = ((pVar6 - *(int *)(&DAT_1004ea90 + iVar4)) + -1 + *(uint *)(&DAT_1004eaac + iVar4)) /
            *(uint *)(&DAT_1004eaac + iVar4);
    png_ptr->row_number = uVar3;
    png_ptr->iwidth = (png_ptr->pixel_depth * uVar3 + 7 >> 3) + 1;
  }
  uVar3 = (uint)png_ptr->pixel_depth;
  uVar2 = png_ptr->transformations;
  if (((uVar2 & 4) != 0) && (png_ptr->bit_depth < 8)) {
    uVar3 = 8;
  }
  if ((uVar2 & 0x1000) != 0) {
    pVar1 = png_ptr->color_type;
    if (pVar1 == '\x03') {
      uVar3 = (uint)(*(short *)((int)&png_ptr->chunk_name_pad + 2) != 0) * 8 + 0x18;
    }
    else if (pVar1 == '\0') {
      if (uVar3 < 8) {
        uVar3 = 8;
      }
      if (*(short *)((int)&png_ptr->chunk_name_pad + 2) != 0) {
        uVar3 = uVar3 * 2;
      }
    }
    else if ((pVar1 == '\x02') && (*(short *)((int)&png_ptr->chunk_name_pad + 2) != 0)) {
      uVar3 = (uVar3 << 2) / 3;
    }
  }
  if ((char)(uVar2 >> 8) < '\0') {
    pVar1 = png_ptr->color_type;
    if (pVar1 == '\x03') {
      uVar3 = 0x20;
    }
    else if (pVar1 == '\0') {
      uVar3 = ((8 < uVar3) - 1 & 0xfffffff0) + 0x20;
    }
    else if (pVar1 == '\x02') {
      uVar3 = ((0x20 < uVar3) - 1 & 0xffffffe0) + 0x40;
    }
  }
  ppVar5 = png_malloc(png_ptr,((pVar6 + 7 & 0xfffffff8) * uVar3 + 7 >> 3) + 1 +
                              ((int)(uVar3 + 7) >> 3));
  png_ptr->sub_row = ppVar5;
  ppVar5 = png_malloc(png_ptr,png_ptr->rowbytes + 1);
  png_ptr->row_buf = ppVar5;
  FUN_100247b3((int)png_ptr,(char)ppVar5,0);
  png_ptr->flags = png_ptr->flags | 0x40;
  return;
}



