/* FUN_100256c7 @ 100256c7 */

void __cdecl FUN_100256c7(png_structp png_ptr,int param_2,uint param_3)

{
  byte *pbVar1;
  png_byte pVar2;
  png_bytep buf;
  int iVar3;
  char *pcVar4;
  undefined4 local_c;
  ushort local_8;
  
  if ((png_ptr->mode & 1) == 0) {
    png_error(png_ptr,"Missing IHDR before tRNS");
  }
  else {
    if ((png_ptr->mode & 4) != 0) {
      pcVar4 = "Invalid tRNS after IDAT";
LAB_1002573c:
      png_warning(png_ptr,pcVar4);
      png_crc_finish(png_ptr,param_3);
      return;
    }
    if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 0x10) != 0)) {
      pcVar4 = "Duplicate tRNS chunk";
      goto LAB_1002573c;
    }
  }
  pVar2 = png_ptr->color_type;
  if (pVar2 == '\x03') {
    if ((png_ptr->mode & 2) == 0) {
      png_warning(png_ptr,"Missing PLTE before tRNS");
LAB_1002570d:
      if (param_3 != 0) {
        buf = png_malloc(png_ptr,param_3);
        pbVar1 = (byte *)((int)&png_ptr->flags + 1);
        *pbVar1 = *pbVar1 | 0x20;
        png_ptr[1].jmpbuf[0xf] = (png_uint_32)buf;
        png_crc_read(png_ptr,buf,param_3);
        *(short *)((int)&png_ptr->chunk_name_pad + 2) = (short)param_3;
        goto LAB_10025833;
      }
      png_warning(png_ptr,"Zero length tRNS chunk");
    }
    else {
      if (param_3 <= (ushort)png_ptr->chunk_name_pad) goto LAB_1002570d;
      png_warning(png_ptr,"Incorrect tRNS chunk length");
    }
LAB_10025870:
    png_crc_finish(png_ptr,param_3);
  }
  else {
    if (pVar2 == '\x02') {
      if (param_3 != 6) {
LAB_100257fe:
        pcVar4 = "Incorrect tRNS chunk length";
LAB_10025867:
        png_warning(png_ptr,pcVar4);
        goto LAB_10025870;
      }
      png_crc_read(png_ptr,(png_bytep)&local_c,6);
      *(short *)((int)&png_ptr[1].error_fn + 2) =
           (short)((local_c & 0xff) * 0x100 + (local_c >> 8 & 0xff));
      *(ushort *)&png_ptr[1].warning_fn = (ushort)local_c._2_1_ * 0x100 + (ushort)local_c._3_1_;
      *(ushort *)((int)&png_ptr[1].warning_fn + 2) = local_8 * 0x100 + (local_8 >> 8);
    }
    else {
      if (pVar2 != '\0') {
        pcVar4 = "tRNS chunk not allowed with alpha channel";
        goto LAB_10025867;
      }
      if (param_3 != 2) goto LAB_100257fe;
      png_crc_read(png_ptr,(png_bytep)&local_c,2);
      *(ushort *)&png_ptr[1].error_ptr = (ushort)local_c * 0x100 + ((ushort)local_c >> 8);
    }
    *(undefined2 *)((int)&png_ptr->chunk_name_pad + 2) = 1;
LAB_10025833:
    iVar3 = png_crc_finish(png_ptr,0);
    if (iVar3 == 0) {
      FUN_10020435((int)png_ptr,param_2,png_ptr[1].jmpbuf[0xf],
                   (uint)*(ushort *)((int)&png_ptr->chunk_name_pad + 2),&png_ptr[1].error_fn);
    }
  }
  return;
}



