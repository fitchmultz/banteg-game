/* FUN_1001e294 @ 1001e294 */

void __cdecl FUN_1001e294(png_structp png_ptr,uint *param_2)

{
  png_byte *buf;
  png_structp png_ptr_00;
  int iVar1;
  int unaff_EBX;
  uint uVar2;
  uint unaff_EBP;
  png_uint_32 pVar3;
  char *pcVar4;
  
  png_ptr_00 = png_ptr;
  if (png_ptr->sig_bytes < 8) {
    uVar2 = (uint)png_ptr->sig_bytes;
    pVar3 = -uVar2 + 8;
    png_read_data(png_ptr,(png_bytep)(uVar2 + 0x20 + (int)param_2),pVar3);
    png_ptr_00->sig_bytes = '\b';
    iVar1 = FUN_100204e3((int)(param_2 + 8),uVar2,pVar3);
    if (iVar1 != 0) {
      if ((uVar2 < 4) && (iVar1 = FUN_100204e3((int)(param_2 + 8),uVar2,-uVar2 + 4), iVar1 != 0)) {
        pcVar4 = "Not a PNG file";
      }
      else {
        pcVar4 = "PNG file corrupted by ASCII conversion";
      }
      png_error(png_ptr_00,pcVar4);
    }
  }
  buf = png_ptr_00->chunk_name;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          png_read_data(png_ptr_00,(png_bytep)&png_ptr,4);
          pVar3 = png_get_uint_32((png_bytep)&png_ptr);
          png_reset_crc(png_ptr_00);
          png_crc_read(png_ptr_00,buf,4);
          if (*(int *)buf != 0x52444849) break;
          grim_png_read_IHDR(png_ptr_00,param_2,pVar3);
        }
        if (*(int *)buf != 0x45544c50) break;
        grim_png_read_PLTE((void *)0x45544c50,png_ptr_00,(int)param_2,pVar3);
      }
      if (*(int *)buf != 0x444e4549) break;
      FUN_10025483(png_ptr_00,param_2,pVar3,unaff_EBX,unaff_EBP);
    }
    if (*(int *)buf == 0x54414449) break;
    if (*(int *)buf == 0x414d4167) {
      FUN_100254cd(png_ptr_00,(int)param_2,pVar3);
    }
    else if (*(int *)buf == 0x42475273) {
      FUN_100255d8(png_ptr_00,(int)param_2,pVar3);
    }
    else if (*(int *)buf == 0x534e5274) {
      FUN_100256c7(png_ptr_00,(int)param_2,pVar3);
    }
    else {
      grim_png_read_chunk_generic(png_ptr_00,(int)param_2,pVar3);
    }
  }
  if ((png_ptr_00->mode & 1) == 0) {
    pcVar4 = "Missing IHDR before IDAT";
  }
  else {
    if ((png_ptr_00->color_type != '\x03') || ((png_ptr_00->mode & 2) != 0)) goto LAB_1001e3f8;
    pcVar4 = "Missing PLTE before IDAT";
  }
  png_error(png_ptr_00,pcVar4);
LAB_1001e3f8:
  png_ptr_00->mode = png_ptr_00->mode | 4;
  png_ptr_00->crc = pVar3;
  return;
}



