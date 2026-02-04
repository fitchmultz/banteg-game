/* grim_png_read_IHDR @ 10025163 */

void __cdecl grim_png_read_IHDR(png_structp png_ptr,uint *param_2,int param_3)

{
  byte bVar1;
  png_uint_32 pVar2;
  png_uint_32 pVar3;
  png_byte local_20 [4];
  png_byte local_1c [4];
  byte local_18;
  byte local_17;
  byte local_16;
  byte local_15;
  byte local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (png_ptr->mode != 0) {
    png_error(png_ptr,"Out of place IHDR");
  }
  if (param_3 != 0xd) {
    png_error(png_ptr,"Invalid IHDR chunk");
  }
  png_ptr->mode = png_ptr->mode | 1;
  png_crc_read(png_ptr,local_20,0xd);
  png_crc_finish(png_ptr,0);
  pVar2 = png_get_uint_32(local_20);
  pVar3 = png_get_uint_32(local_1c);
  local_10 = (uint)local_16;
  local_c = (uint)local_15;
  local_8 = (uint)local_14;
  if ((((pVar2 == 0) || (0x7fffffff < pVar2)) || (pVar3 == 0)) || (0x7fffffff < pVar3)) {
    png_error(png_ptr,"Invalid image size in IHDR");
  }
  if (((local_18 != 1) && (local_18 != 2)) &&
     ((local_18 != 4 && ((local_18 != 8 && (local_18 != 0x10)))))) {
    png_error(png_ptr,"Invalid bit depth in IHDR");
  }
  if (((local_17 == 1) || (local_17 == 5)) || (6 < local_17)) {
    png_error(png_ptr,"Invalid color type in IHDR");
  }
  if (((local_17 == 3) && (8 < local_18)) ||
     (((local_17 == 2 || ((local_17 == 4 || (local_17 == 6)))) && (local_18 < 8)))) {
    png_error(png_ptr,"Invalid color type/bit depth combination in IHDR");
  }
  if (1 < (int)local_8) {
    png_error(png_ptr,"Unknown interlace method in IHDR");
  }
  if (local_10 != 0) {
    png_error(png_ptr,"Unknown compression method in IHDR");
  }
  if (local_c != 0) {
    png_error(png_ptr,"Unknown filter method in IHDR");
  }
  png_ptr->interlaced = (png_byte)local_8;
  png_ptr->width = pVar2;
  png_ptr->height = pVar3;
  png_ptr->bit_depth = local_18;
  png_ptr->color_type = local_17;
  if (local_17 != 0) {
    if (local_17 == 2) {
      png_ptr->channels = '\x03';
      goto LAB_1002531b;
    }
    if (local_17 != 3) {
      if (local_17 == 4) {
        png_ptr->channels = '\x02';
      }
      else if (local_17 == 6) {
        png_ptr->channels = '\x04';
      }
      goto LAB_1002531b;
    }
  }
  png_ptr->channels = '\x01';
LAB_1002531b:
  bVar1 = png_ptr->channels * local_18;
  png_ptr->pixel_depth = bVar1;
  png_ptr->rowbytes = bVar1 * pVar2 + 7 >> 3;
  FUN_1002031c(png_ptr,param_2,pVar2,pVar3,local_18,local_17,(png_byte)local_8,(char)local_10,
               (char)local_c);
  return;
}



