/* grim_png_read_PLTE @ 10025359 */

void __thiscall grim_png_read_PLTE(void *this,png_structp png_ptr,int param_2,uint param_3)

{
  byte *pbVar1;
  ushort *puVar2;
  uint uVar3;
  png_structp png_ptr_00;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  png_structp unaff_ESI;
  undefined1 *puVar7;
  char *pcVar8;
  int local_8;
  
  png_ptr_00 = png_ptr;
  uVar3 = png_ptr->mode;
  if ((uVar3 & 1) == 0) {
    pcVar8 = "Missing IHDR before PLTE";
LAB_10025385:
    png_error(png_ptr,pcVar8);
LAB_1002538d:
    png_ptr_00->mode = png_ptr_00->mode | 2;
    if (param_3 % 3 != 0) {
      pcVar8 = "Invalid palette chunk";
      unaff_ESI = png_ptr_00;
      if (png_ptr_00->color_type != '\x03') goto LAB_100253ad;
      png_error(png_ptr_00,"Invalid palette chunk");
    }
    iVar5 = (int)param_3 / 3;
    puVar6 = FUN_1002052b(png_ptr_00,iVar5,3);
    pbVar1 = (byte *)((int)&png_ptr_00->flags + 1);
    *pbVar1 = *pbVar1 | 0x10;
    if (0 < iVar5) {
      puVar7 = (undefined1 *)((int)puVar6 + 2);
      local_8 = iVar5;
      do {
        png_crc_read(png_ptr_00,(png_bytep)&png_ptr,3);
        puVar7[-2] = png_ptr._0_1_;
        puVar7[-1] = png_ptr._1_1_;
        *puVar7 = png_ptr._2_1_;
        puVar7 = puVar7 + 3;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
    png_crc_finish(png_ptr_00,0);
    iVar4 = param_2;
    *(undefined4 **)&png_ptr_00->num_palette = puVar6;
    *(short *)&png_ptr_00->chunk_name_pad = (short)iVar5;
    FUN_100203bd((int)png_ptr_00,param_2,puVar6,(short)iVar5);
    if ((((png_ptr_00->color_type == '\x03') && (iVar4 != 0)) &&
        ((*(byte *)(iVar4 + 8) & 0x10) != 0)) &&
       (puVar2 = (ushort *)((int)&png_ptr_00->chunk_name_pad + 2),
       (ushort)png_ptr_00->chunk_name_pad < *puVar2)) {
      png_warning(png_ptr_00,"Truncating incorrect tRNS chunk length");
      *puVar2 = (ushort)png_ptr_00->chunk_name_pad;
    }
  }
  else {
    pcVar8 = this;
    if ((uVar3 & 4) == 0) {
      if ((uVar3 & 2) != 0) {
        pcVar8 = "Duplicate PLTE chunk";
        goto LAB_10025385;
      }
      goto LAB_1002538d;
    }
LAB_100253ad:
    png_warning(unaff_ESI,pcVar8);
    png_crc_finish(png_ptr_00,param_3);
  }
  return;
}



