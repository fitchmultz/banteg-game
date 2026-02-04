/* FUN_100254cd @ 100254cd */

void __cdecl FUN_100254cd(png_structp png_ptr,int param_2,uint param_3)

{
  uint uVar1;
  float fVar2;
  png_structp png_ptr_00;
  int iVar3;
  int iVar4;
  png_uint_32 pVar5;
  char *msg;
  
  iVar3 = param_2;
  png_ptr_00 = png_ptr;
  uVar1 = png_ptr->mode;
  if ((uVar1 & 1) == 0) {
    png_error(png_ptr,"Missing IHDR before gAMA");
  }
  else {
    if ((uVar1 & 4) != 0) {
      msg = "Invalid gAMA after IDAT";
      goto LAB_100254fe;
    }
    if ((uVar1 & 2) == 0) {
      if (((param_2 != 0) && ((*(uint *)(param_2 + 8) & 1) != 0)) &&
         ((*(uint *)(param_2 + 8) & 0x800) == 0)) {
        msg = "Duplicate gAMA chunk";
        goto LAB_100254fe;
      }
    }
    else {
      png_warning(png_ptr,"Out of place gAMA chunk");
    }
  }
  if (param_3 == 4) {
    png_crc_read(png_ptr_00,(png_bytep)&png_ptr,4);
    iVar4 = png_crc_finish(png_ptr_00,0);
    if (iVar4 != 0) {
      return;
    }
    pVar5 = png_get_uint_32((png_bytep)&png_ptr);
    if (pVar5 == 0) {
      return;
    }
    if ((*(uint *)(iVar3 + 8) & 0x800) != 0) {
      fVar2 = (float)(int)pVar5;
      if ((int)pVar5 < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      if (500.0 < ABS(fVar2 - 45455.0)) {
        png_warning(png_ptr_00,"Ignoring incorrect gAMA value when sRGB is also present");
        return;
      }
    }
    fVar2 = (float)(int)pVar5;
    if ((int)pVar5 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    png_ptr_00[1].jmpbuf[4] = (png_uint_32)(fVar2 * 1e-05);
    FUN_10020301((int)png_ptr_00,iVar3,(double)(fVar2 * 1e-05));
    return;
  }
  msg = "Incorrect gAMA chunk length";
LAB_100254fe:
  png_warning(png_ptr_00,msg);
  png_crc_finish(png_ptr_00,param_3);
  return;
}



