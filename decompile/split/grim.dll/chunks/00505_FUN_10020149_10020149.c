/* FUN_10020149 @ 10020149 */

void __cdecl FUN_10020149(png_structp png_ptr)

{
  int iVar1;
  int iVar2;
  png_error_ptr *pppVar3;
  
  if (png_ptr->sub_row == (png_bytep)0x0) {
    png_error(png_ptr,"NULL row buffer");
  }
  if ((png_ptr->transformations & 0x1000) != 0) {
    if ((char)png_ptr->idat_size == '\x03') {
      iVar1._0_2_ = png_ptr->num_palette;
      iVar1._2_2_ = png_ptr->num_trans;
      FUN_1001f6c5(&(png_ptr->row_info).rowbytes,(int)(png_ptr->sub_row + 1),iVar1,
                   png_ptr[1].jmpbuf[0xf],(uint)*(ushort *)((int)&png_ptr->chunk_name_pad + 2));
    }
    else {
      if (*(short *)((int)&png_ptr->chunk_name_pad + 2) == 0) {
        pppVar3 = (png_error_ptr *)0x0;
      }
      else {
        pppVar3 = &png_ptr[1].error_fn;
      }
      FUN_1001f8cd((int *)&(png_ptr->row_info).rowbytes,(int)(png_ptr->sub_row + 1),(int)pppVar3);
    }
  }
  if (((png_ptr->transformations & 0x2000) != 0) && (png_ptr->color_type != '\x03')) {
    FUN_1001f377((int *)&(png_ptr->row_info).rowbytes,png_ptr->sub_row + 1,png_ptr[1].jmpbuf[6],
                 png_ptr[1].jmpbuf[9],(byte)png_ptr[1].jmpbuf[3]);
  }
  if ((png_ptr->transformations & 0x400) != 0) {
    FUN_1001f0fb((int *)&(png_ptr->row_info).rowbytes,png_ptr->sub_row + 1);
  }
  if ((png_ptr->transformations & 0x40) != 0) {
    FUN_1001fc1f((int *)&(png_ptr->row_info).rowbytes,png_ptr->sub_row + 1,(int)png_ptr[1].io_ptr,
                 png_ptr[1].mode);
    iVar2._0_1_ = (png_ptr->row_info).color_type;
    iVar2._1_1_ = (png_ptr->row_info).bit_depth;
    iVar2._2_1_ = (png_ptr->row_info).channels;
    iVar2._3_1_ = (png_ptr->row_info).pixel_depth;
    if (iVar2 == 0) {
      png_error(png_ptr,"png_do_dither returned rowbytes=0");
    }
  }
  if ((png_ptr->transformations & 8) != 0) {
    FUN_1001ef84((byte *)&(png_ptr->row_info).rowbytes,png_ptr->sub_row + 1,
                 (byte *)((int)png_ptr[1].jmpbuf + 0x35));
  }
  if ((png_ptr->transformations & 4) != 0) {
    FUN_1001ee74((int *)&(png_ptr->row_info).rowbytes,(int)(png_ptr->sub_row + 1));
  }
  if ((png_ptr->transformations & 1) != 0) {
    FUN_1001ec8b((int *)&(png_ptr->row_info).rowbytes,png_ptr->sub_row + 1);
  }
  if ((png_ptr->transformations & 0x8000) != 0) {
    FUN_1001f13f(&(png_ptr->row_info).rowbytes,(int)(png_ptr->sub_row + 1),
                 (uint)*(ushort *)&png_ptr->field_0x11e,(byte)png_ptr->flags);
  }
  if ((png_ptr->transformations & 0x10) != 0) {
    FUN_1001ec5e((int *)&(png_ptr->row_info).rowbytes,png_ptr->sub_row + 1);
  }
  return;
}



