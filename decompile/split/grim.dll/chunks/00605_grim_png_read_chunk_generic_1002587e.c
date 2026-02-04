/* grim_png_read_chunk_generic @ 1002587e */

void __cdecl grim_png_read_chunk_generic(png_structp png_ptr,int param_2,uint param_3)

{
  png_check_chunk_name(png_ptr,png_ptr->chunk_name);
  if (((png_ptr->chunk_name[0] & 0x20) == 0) &&
     (FUN_1001e147(png_ptr,(undefined4 *)"unknown critical chunk"), param_2 == 0)) {
    return;
  }
  if ((png_ptr->mode & 4) != 0) {
    png_ptr->mode = png_ptr->mode | 8;
  }
  png_crc_finish(png_ptr,param_3);
  return;
}



