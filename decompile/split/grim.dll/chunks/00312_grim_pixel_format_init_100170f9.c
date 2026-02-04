/* grim_pixel_format_init @ 100170f9 */

/* initializes format descriptor, bytes-per-pixel, palette expansion, and coordinate mode */

void * __thiscall grim_pixel_format_init(void *this,uint *desc,uint bits_per_pixel,uint coord_mode)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  float *pfVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  
  *(undefined ***)this = &PTR_FUN_1004cae4;
  _vector_constructor_iterator_
            ((void *)((int)this + 0x30),0x10,0x100,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
  *(uint *)((int)this + 0x18) = *desc;
  *(uint *)((int)this + 4) = desc[1];
  *(uint *)((int)this + 0x1050) = desc[2];
  *(uint *)((int)this + 0x1054) = desc[3];
  puVar6 = desc + 10;
  puVar9 = (uint *)((int)this + 0x1030);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar9 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar3 = &DAT_10054418;
  if (desc[0x10] == 0) {
    puVar3 = &DAT_10054398;
  }
  *(undefined **)((int)this + 0x2c) = puVar3;
  *(uint *)((int)this + 0x1068) = bits_per_pixel >> 3;
  *(undefined4 *)((int)this + 0x1048) = 0;
  *(undefined4 *)((int)this + 0x104c) = 0;
  *(uint *)((int)this + 0xc) = (uint)(bits_per_pixel != 0);
  *(uint *)((int)this + 8) = coord_mode;
  uVar7 = desc[0x11];
  *(uint *)((int)this + 0x10) = uVar7;
  if (uVar7 != 0) {
    uVar7 = desc[0x11];
    *(float *)((int)this + 0x1c) = (float)(uVar7 >> 0x10 & 0xff) * 0.003921569;
    *(float *)((int)this + 0x20) = (float)(uVar7 >> 8 & 0xff) * 0.003921569;
    *(float *)((int)this + 0x24) = (float)(uVar7 & 0xff) * 0.003921569;
    *(float *)((int)this + 0x28) = (float)(uVar7 >> 0x18) * 0.003921569;
  }
  if ((*(int *)((int)this + 4) == 0x29) || (*(int *)((int)this + 4) == 0x28)) {
    *(undefined4 *)((int)this + 0x14) = 1;
    if (desc[0x12] == 0) {
      iVar2 = 0x100;
      puVar1 = (undefined4 *)((int)this + 0x38);
      do {
        puVar1[1] = 0x3f800000;
        *puVar1 = 0x3f800000;
        iVar2 = iVar2 + -1;
        puVar1[-1] = 0x3f800000;
        puVar1[-2] = 0x3f800000;
        puVar1 = puVar1 + 4;
      } while (iVar2 != 0);
    }
    else {
      pfVar4 = (float *)((int)this + 0x34);
      uVar7 = 0;
      do {
        uVar8 = uVar7 + 4;
        pfVar4[-1] = (float)*(byte *)(uVar7 + desc[0x12]) * 0.003921569;
        *pfVar4 = (float)*(byte *)(uVar7 + 1 + desc[0x12]) * 0.003921569;
        pfVar4[1] = (float)*(byte *)(uVar7 + 2 + desc[0x12]) * 0.003921569;
        pfVar4[2] = (float)*(byte *)(uVar7 + 3 + desc[0x12]) * 0.003921569;
        pfVar4 = pfVar4 + 4;
        uVar7 = uVar8;
      } while (uVar8 < 0x400);
    }
  }
  else {
    *(undefined4 *)((int)this + 0x14) = 0;
  }
  *(int *)((int)this + 0x105c) = *(int *)((int)this + 0x103c) - *(int *)((int)this + 0x1034);
  iVar2 = *(int *)((int)this + 0x1030);
  iVar5 = *(int *)((int)this + 0x1038) - iVar2;
  *(int *)((int)this + 0x1060) = *(int *)((int)this + 0x1044) - *(int *)((int)this + 0x1040);
  *(int *)((int)this + 0x1058) = iVar5;
  *(int *)((int)this + 0x1064) = *(int *)((int)this + 0x1068) * iVar5;
  if (*(int *)((int)this + 0xc) != 0) {
    *(int *)((int)this + 0x18) =
         *(int *)((int)this + 0x18) +
         *(int *)((int)this + 0x1068) * iVar2 +
         *(int *)((int)this + 0x1050) * *(int *)((int)this + 0x1034) +
         *(int *)((int)this + 0x1054) * *(int *)((int)this + 0x1040);
    *(undefined4 *)((int)this + 0x1038) = *(undefined4 *)((int)this + 0x1058);
    *(undefined4 *)((int)this + 0x103c) = *(undefined4 *)((int)this + 0x105c);
    *(int *)((int)this + 0x1030) = 0;
    *(undefined4 *)((int)this + 0x1034) = 0;
    *(undefined4 *)((int)this + 0x1040) = 0;
    *(undefined4 *)((int)this + 0x1044) = *(undefined4 *)((int)this + 0x1060);
  }
  return this;
}



