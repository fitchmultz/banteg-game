/* FUN_10020036 @ 10020036 */

void __cdecl FUN_10020036(png_structp png_ptr)

{
  png_byte pVar1;
  ushort uVar2;
  png_structp ppVar3;
  png_structp ppVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int local_8;
  
  ppVar4 = png_ptr;
  pVar1 = png_ptr->color_type;
  if ((png_ptr->transformations & 0x602000) != 0) {
    FUN_1001fd2d(png_ptr);
    if (pVar1 == '\x03') {
      uVar7 = (uint)(ushort)png_ptr->chunk_name_pad;
      if (uVar7 != 0) {
        pbVar5 = (byte *)(*(int *)&png_ptr->num_palette + 2);
        do {
          pbVar5[-2] = *(byte *)((uint)pbVar5[-2] + png_ptr[1].jmpbuf[6]);
          pbVar5[-1] = *(byte *)((uint)pbVar5[-1] + png_ptr[1].jmpbuf[6]);
          *pbVar5 = *(byte *)((uint)*pbVar5 + png_ptr[1].jmpbuf[6]);
          pbVar5 = pbVar5 + 3;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
    }
  }
  if (((png_ptr->transformations & 8) != 0) && (pVar1 == '\x03')) {
    ppVar3 = png_ptr + 1;
    iVar8 = 8 - (uint)(byte)png_ptr[1].jmpbuf[0xc];
    png_ptr = (png_structp)(8 - (uint)*(byte *)((int)png_ptr[1].jmpbuf + 0x31));
    local_8 = 8 - (uint)*(byte *)((int)ppVar3->jmpbuf + 0x32);
    if ((iVar8 < 0) || (8 < iVar8)) {
      iVar8 = 0;
    }
    if (((int)png_ptr < 0) || (8 < (int)png_ptr)) {
      png_ptr = (png_structp)0x0;
    }
    if ((local_8 < 0) || (8 < local_8)) {
      local_8 = 0;
    }
    uVar2 = (ushort)ppVar4->chunk_name_pad;
    if (uVar2 != 0) {
      iVar6 = 0;
      uVar7 = (uint)uVar2;
      do {
        pbVar5 = (byte *)(iVar6 + *(int *)&ppVar4->num_palette);
        *pbVar5 = *pbVar5 >> ((byte)iVar8 & 0x1f);
        pbVar5 = (byte *)(iVar6 + 1 + *(int *)&ppVar4->num_palette);
        *pbVar5 = *pbVar5 >> ((byte)png_ptr & 0x1f);
        pbVar5 = (byte *)(iVar6 + 2 + *(int *)&ppVar4->num_palette);
        *pbVar5 = *pbVar5 >> ((byte)local_8 & 0x1f);
        iVar6 = iVar6 + 3;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
  }
  return;
}



