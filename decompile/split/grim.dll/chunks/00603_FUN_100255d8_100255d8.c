/* FUN_100255d8 @ 100255d8 */

void __cdecl FUN_100255d8(png_structp png_ptr,int param_2,uint param_3)

{
  uint uVar1;
  png_structp png_ptr_00;
  byte bVar2;
  int iVar3;
  char *msg;
  
  png_ptr_00 = png_ptr;
  uVar1 = png_ptr->mode;
  if ((uVar1 & 1) == 0) {
    png_error(png_ptr,"Missing IHDR before sRGB");
  }
  else {
    if ((uVar1 & 4) != 0) {
      msg = "Invalid sRGB after IDAT";
      goto LAB_100255fe;
    }
    if ((uVar1 & 2) == 0) {
      if ((param_2 != 0) && ((*(byte *)(param_2 + 9) & 8) != 0)) {
        msg = "Duplicate sRGB chunk";
        goto LAB_100255fe;
      }
    }
    else {
      png_warning(png_ptr,"Out of place sRGB chunk");
    }
  }
  if (param_3 == 1) {
    png_crc_read(png_ptr_00,(png_bytep)((int)&png_ptr + 3),1);
    iVar3 = png_crc_finish(png_ptr_00,0);
    if (iVar3 != 0) {
      return;
    }
    bVar2 = png_ptr._3_1_;
    if (3 < png_ptr._3_1_) {
      png_warning(png_ptr_00,"Unknown sRGB intent");
      return;
    }
    if (((*(byte *)(param_2 + 8) & 1) != 0) &&
       (500.0 < ABS(((float)png_ptr_00[1].jmpbuf[4] * 100000.0 + 0.5) - 45455.0))) {
      png_warning(png_ptr_00,"Ignoring incorrect gAMA value when sRGB is also present");
    }
    FUN_100203fc((int)png_ptr_00,param_2,bVar2);
    return;
  }
  msg = "Incorrect sRGB chunk length";
LAB_100255fe:
  png_warning(png_ptr_00,msg);
  png_crc_finish(png_ptr_00,param_3);
  return;
}



