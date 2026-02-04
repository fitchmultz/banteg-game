/* FUN_1001fd2d @ 1001fd2d */

void __cdecl FUN_1001fd2d(png_structp png_ptr)

{
  png_structp ppVar1;
  byte bVar2;
  png_uint_32 pVar3;
  png_structp png_ptr_00;
  undefined1 uVar4;
  undefined2 uVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  ushort local_10;
  uint local_8;
  
  png_ptr_00 = png_ptr;
  if ((float)png_ptr[1].jmpbuf[4] != 0.0) {
    if (png_ptr->bit_depth < 9) {
      pvVar6 = png_malloc(png_ptr,0x100);
      png_ptr = (png_structp)0x0;
      png_ptr_00[1].jmpbuf[6] = (png_uint_32)pvVar6;
      do {
        _CIpow();
        uVar4 = ftol();
        ppVar1 = (png_structp)((int)png_ptr->jmpbuf + 1);
        *(undefined1 *)((int)png_ptr->jmpbuf + png_ptr_00[1].jmpbuf[6]) = uVar4;
        png_ptr = ppVar1;
      } while ((int)ppVar1 < 0x100);
    }
    else {
      if ((png_ptr->color_type & 2) == 0) {
        local_8 = (uint)*(byte *)((int)png_ptr[1].jmpbuf + 0x33);
      }
      else {
        local_8 = (uint)(byte)png_ptr[1].jmpbuf[0xc];
        uVar10 = (uint)*(byte *)((int)png_ptr[1].jmpbuf + 0x31);
        if (local_8 < uVar10) {
          local_8 = uVar10;
        }
        uVar10 = (uint)*(byte *)((int)png_ptr[1].jmpbuf + 0x32);
        if (local_8 < uVar10) {
          local_8 = uVar10;
        }
      }
      if (local_8 == 0) {
        local_8 = 0;
      }
      else {
        local_8 = 0x10 - local_8;
      }
      if (((png_ptr->transformations & 0x400) != 0) && ((int)local_8 < 5)) {
        local_8 = 5;
      }
      if (8 < (int)local_8) {
        local_8 = 8;
      }
      if ((int)local_8 < 0) {
        local_8 = 0;
      }
      bVar2 = (byte)local_8;
      bVar9 = 8 - bVar2;
      iVar11 = 1 << (bVar9 & 0x1f);
      png_ptr[1].jmpbuf[3] = local_8 & 0xff;
      pvVar6 = png_malloc(png_ptr,iVar11 << 2);
      pVar3 = png_ptr->transformations;
      png_ptr[1].jmpbuf[9] = (png_uint_32)pvVar6;
      png_ptr = (png_structp)0x0;
      if ((pVar3 & 0x480) == 0) {
        if (0 < iVar11) {
          do {
            pvVar6 = png_malloc(png_ptr_00,0x200);
            *(void **)(png_ptr_00[1].jmpbuf[9] + (int)png_ptr * 4) = pvVar6;
            iVar13 = 0;
            do {
              _CIpow();
              uVar5 = ftol();
              *(undefined2 *)(iVar13 + *(int *)(png_ptr_00[1].jmpbuf[9] + (int)png_ptr * 4)) = uVar5
              ;
              iVar13 = iVar13 + 2;
            } while (iVar13 < 0x200);
            png_ptr = (png_structp)((int)png_ptr->jmpbuf + 1);
          } while ((int)png_ptr < iVar11);
        }
      }
      else {
        if (0 < iVar11) {
          do {
            pvVar6 = png_malloc(png_ptr_00,0x200);
            ppVar1 = (png_structp)((int)png_ptr->jmpbuf + 1);
            *(void **)(png_ptr_00[1].jmpbuf[9] + (int)png_ptr * 4) = pvVar6;
            png_ptr = ppVar1;
          } while ((int)ppVar1 < iVar11);
        }
        uVar10 = 0;
        png_ptr = (png_structp)0x0;
        do {
          _CIpow();
          uVar7 = ftol();
          if (uVar10 <= uVar7) {
            local_10 = (ushort)(((uint)png_ptr & 0xff) << 8) | (ushort)png_ptr;
            do {
              uVar12 = uVar10 >> (bVar9 & 0x1f);
              uVar8 = 0xff >> (bVar2 & 0x1f) & uVar10;
              uVar10 = uVar10 + 1;
              *(ushort *)(*(int *)(png_ptr_00[1].jmpbuf[9] + uVar8 * 4) + uVar12 * 2) = local_10;
            } while (uVar10 <= uVar7);
          }
          png_ptr = (png_structp)((int)png_ptr->jmpbuf + 1);
        } while ((int)png_ptr < 0x100);
        if (uVar10 < (uint)(iVar11 << 8)) {
          do {
            *(undefined2 *)
             (*(int *)(png_ptr_00[1].jmpbuf[9] + (0xff >> (bVar2 & 0x1f) & uVar10) * 4) +
             (uVar10 >> (bVar9 & 0x1f)) * 2) = 0xffff;
            uVar10 = uVar10 + 1;
          } while (uVar10 < (uint)(iVar11 << 8));
        }
      }
    }
  }
  return;
}



