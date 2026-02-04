/* FUN_10025483 @ 10025483 */

void __cdecl
FUN_10025483(png_structp png_ptr,undefined4 param_2,undefined4 param_3,int param_4,uint param_5)

{
  if ((((png_ptr->mode & 1) == 0) || ((png_ptr->mode & 4) == 0)) &&
     (png_error(png_ptr,"No image in file"), param_4 == 0)) {
    return;
  }
  png_ptr->mode = png_ptr->mode | 0x18;
  if (param_5 != 0) {
    png_warning(png_ptr,"Incorrect IEND chunk length");
  }
  png_crc_finish(png_ptr,param_5);
  return;
}



