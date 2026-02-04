/* FUN_1001e427 @ 1001e427 */

void __thiscall FUN_1001e427(void *this,png_structp png_ptr,byte *param_2,byte *param_3)

{
  png_uint_32 *ppVar1;
  png_byte pVar2;
  byte bVar3;
  uint uVar4;
  png_bytep buf;
  png_structp png_ptr_00;
  png_uint_32 pVar5;
  int iVar6;
  char *msg;
  png_structp extraout_ECX;
  uint uVar7;
  png_structp extraout_ECX_00;
  png_structp this_00;
  png_structp extraout_ECX_01;
  png_structp extraout_ECX_02;
  png_structp extraout_ECX_03;
  png_structp extraout_ECX_04;
  bool bVar8;
  byte *pbVar9;
  
  png_ptr_00 = png_ptr;
  if ((png_ptr->flags & 0x40) == 0) {
    this = png_ptr;
    FUN_10024f3b(png_ptr);
  }
  if ((png_ptr_00->interlaced != '\0') && ((png_ptr_00->transformations & 2) != 0)) {
    pVar2 = png_ptr_00->pass;
    if (pVar2 == '\0') {
      if (((uint)png_ptr_00->prev_row & 7) != 0) {
        bVar8 = param_3 == (byte *)0x0;
LAB_1001e539:
        if (bVar8) goto LAB_1001e48f;
        uVar7 = 0xff;
LAB_1001e544:
        FUN_100248e1((int)png_ptr_00,param_3,uVar7);
        this = extraout_ECX;
LAB_1001e48f:
        FUN_100258c8(this,(int *)png_ptr_00);
        return;
      }
    }
    else if (pVar2 == '\x01') {
      if ((((uint)png_ptr_00->prev_row & 7) != 0) || (png_ptr_00->width < 5)) {
        if (param_3 == (byte *)0x0) goto LAB_1001e48f;
        uVar7 = 0xf;
        goto LAB_1001e544;
      }
    }
    else if (pVar2 == '\x02') {
      this = (void *)((uint)png_ptr_00->prev_row & 0xffffff07);
      if ((char)this != '\x04') {
        if (param_3 == (byte *)0x0) goto LAB_1001e48f;
        bVar8 = ((uint)png_ptr_00->prev_row & 4) == 0;
        goto LAB_1001e539;
      }
    }
    else if (pVar2 == '\x03') {
      if ((((uint)png_ptr_00->prev_row & 3) != 0) || (png_ptr_00->width < 3)) {
        if (param_3 == (byte *)0x0) goto LAB_1001e48f;
        uVar7 = 0x33;
        goto LAB_1001e544;
      }
    }
    else if (pVar2 == '\x04') {
      this = (void *)((uint)png_ptr_00->prev_row & 0xffffff03);
      if ((char)this != '\x02') {
        if (param_3 == (byte *)0x0) goto LAB_1001e48f;
        bVar8 = ((uint)png_ptr_00->prev_row & 2) == 0;
        goto LAB_1001e539;
      }
    }
    else if (pVar2 == '\x05') {
      if ((((uint)png_ptr_00->prev_row & 1) != 0) || (png_ptr_00->width < 2)) {
        if (param_3 == (byte *)0x0) goto LAB_1001e48f;
        uVar7 = 0x55;
        goto LAB_1001e544;
      }
    }
    else if ((pVar2 == '\x06') && (((uint)png_ptr_00->prev_row & 1) == 0)) goto LAB_1001e48f;
  }
  if ((png_ptr_00->mode & 4) == 0) {
    png_error(png_ptr_00,"Invalid attempt to read row data");
  }
  (png_ptr_00->zstream).words[3] = (png_uint_32)png_ptr_00->sub_row;
  (png_ptr_00->zstream).words[4] = png_ptr_00->iwidth;
  do {
    if ((png_ptr_00->zstream).words[1] == 0) {
      if (png_ptr_00->crc == 0) {
        do {
          png_crc_finish(png_ptr_00,0);
          png_read_data(png_ptr_00,(png_bytep)&png_ptr,4);
          pVar5 = png_get_uint_32((png_bytep)&png_ptr);
          png_ptr_00->crc = pVar5;
          png_reset_crc(png_ptr_00);
          png_crc_read(png_ptr_00,png_ptr_00->chunk_name,4);
          if (*(int *)png_ptr_00->chunk_name != 0x54414449) {
            png_error(png_ptr_00,"Not enough image data");
          }
        } while (png_ptr_00->crc == 0);
      }
      uVar7 = png_ptr_00->zbuf_size;
      uVar4 = png_ptr_00->crc;
      buf = png_ptr_00->zbuf;
      (png_ptr_00->zstream).words[1] = uVar7;
      (png_ptr_00->zstream).words[0] = (png_uint_32)buf;
      if (uVar4 < uVar7) {
        (png_ptr_00->zstream).words[1] = uVar4;
      }
      png_crc_read(png_ptr_00,buf,(png_ptr_00->zstream).words[1]);
      png_ptr_00->crc = png_ptr_00->crc - (png_ptr_00->zstream).words[1];
    }
    iVar6 = inflate((z_streamp)&png_ptr_00->zstream,1);
    if (iVar6 == 1) {
      if ((((png_ptr_00->zstream).words[4] != 0) || ((png_ptr_00->zstream).words[1] != 0)) ||
         (png_ptr_00->crc != 0)) {
        png_error(png_ptr_00,"Extra compressed data");
      }
      png_ptr_00->mode = png_ptr_00->mode | 8;
      png_ptr_00->flags = png_ptr_00->flags | 0x20;
      break;
    }
    if (iVar6 != 0) {
      msg = (char *)(png_ptr_00->zstream).words[6];
      if (msg == (char *)0x0) {
        msg = "Decompression error";
      }
      png_error(png_ptr_00,msg);
    }
  } while ((png_ptr_00->zstream).words[4] != 0);
  pVar2 = png_ptr_00->color_type;
  *(png_byte *)((int)&png_ptr_00->idat_size + 2) = png_ptr_00->channels;
  *(png_byte *)((int)&png_ptr_00->idat_size + 1) = png_ptr_00->bit_depth;
  bVar3 = png_ptr_00->pixel_depth;
  *(byte *)((int)&png_ptr_00->idat_size + 3) = bVar3;
  *(png_byte *)&png_ptr_00->idat_size = pVar2;
  uVar7 = (uint)bVar3 * png_ptr_00->row_number + 7 >> 3;
  ppVar1 = &(png_ptr_00->row_info).rowbytes;
  *ppVar1 = png_ptr_00->row_number;
  pbVar9 = png_ptr_00->sub_row;
  (png_ptr_00->row_info).color_type = (char)uVar7;
  (png_ptr_00->row_info).bit_depth = (char)(uVar7 >> 8);
  (png_ptr_00->row_info).channels = (char)(uVar7 >> 0x10);
  (png_ptr_00->row_info).pixel_depth = (char)(uVar7 >> 0x18);
  FUN_10024dc0(png_ptr_00,(int)ppVar1,pbVar9 + 1,png_ptr_00->row_buf + 1,(uint)*pbVar9);
  FUN_10024790((int)png_ptr_00,(int)png_ptr_00->row_buf,(int)png_ptr_00->sub_row);
  this_00 = extraout_ECX_00;
  if (png_ptr_00->transformations != 0) {
    this_00 = png_ptr_00;
    FUN_10020149(png_ptr_00);
  }
  if ((png_ptr_00->interlaced == '\0') || ((png_ptr_00->transformations & 2) == 0)) {
    if (param_2 != (byte *)0x0) {
      FUN_100248e1((int)png_ptr_00,param_2,0xff);
      this_00 = extraout_ECX_03;
    }
    if (param_3 == (byte *)0x0) goto LAB_1001e7a4;
    uVar7 = 0xff;
    pbVar9 = param_3;
  }
  else {
    bVar3 = png_ptr_00->pass;
    this_00 = (png_structp)CONCAT31((int3)((uint)this_00 >> 8),bVar3);
    if (bVar3 < 6) {
      FUN_10024af7(ppVar1,(int *)(png_ptr_00->sub_row + 1),(uint)bVar3);
      this_00 = extraout_ECX_01;
    }
    if (param_3 != (byte *)0x0) {
      FUN_100248e1((int)png_ptr_00,param_3,*(uint *)(&DAT_1004e1f8 + (uint)png_ptr_00->pass * 4));
      this_00 = extraout_ECX_02;
    }
    if (param_2 == (byte *)0x0) goto LAB_1001e7a4;
    uVar7 = *(uint *)(&DAT_1004e1dc + (uint)png_ptr_00->pass * 4);
    pbVar9 = param_2;
  }
  FUN_100248e1((int)png_ptr_00,pbVar9,uVar7);
  this_00 = extraout_ECX_04;
LAB_1001e7a4:
  FUN_100258c8(this_00,(int *)png_ptr_00);
  if (png_ptr_00[1].write_data_fn != (png_rw_ptr)0x0) {
    (*png_ptr_00[1].write_data_fn)(png_ptr_00,png_ptr_00->prev_row,(png_uint_32)png_ptr_00->pass);
  }
  return;
}



