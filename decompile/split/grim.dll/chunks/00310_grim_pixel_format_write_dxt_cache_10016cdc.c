/* grim_pixel_format_write_dxt_cache @ 10016cdc */

/* writes RGBA floats into the DXT block cache and encodes when block data is complete */

void grim_pixel_format_write_dxt_cache(void *this,uint x,uint y,float *pixels)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  float *pfVar4;
  void *this_00;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int unaff_EBP;
  uint uVar9;
  undefined4 *puVar10;
  uint *puVar11;
  
  seh_prolog();
  uVar9 = *(int *)(unaff_EBP + 8) + *(int *)((int)this_00 + 0x1034);
  *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + *(int *)((int)this_00 + 0x1040);
  iVar6 = *(int *)((int)this_00 + 0x10c0);
  *(uint *)(unaff_EBP + 8) = uVar9;
  if (iVar6 == 0) {
    puVar2 = operator_new(*(int *)((int)this_00 + 0x10a8) * *(int *)((int)this_00 + 0x10ac) * 8);
    *(undefined4 **)((int)this_00 + 0x10c0) = puVar2;
    if (puVar2 == (undefined4 *)0x0) goto LAB_100170c5;
    for (uVar5 = (uint)(*(int *)((int)this_00 + 0x10a8) * *(int *)((int)this_00 + 0x10ac) * 8) >> 2;
        uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  puVar11 = (uint *)(*(int *)((int)this_00 + 0x10c0) +
                    ((*(int *)(unaff_EBP + 0xc) - *(int *)((int)this_00 + 0x109c)) *
                     *(int *)((int)this_00 + 0x10a8) +
                    (uVar9 - *(int *)((int)this_00 + 0x1090) >> 2)) * 8);
  uVar5 = puVar11[1];
  *(uint **)(unaff_EBP + -0x10) = puVar11;
  if (uVar5 == 0) {
    iVar6 = *(int *)((int)this_00 + 0x10a4);
    *(int *)(unaff_EBP + -0x18) = iVar6 << 4;
    pvVar3 = operator_new(iVar6 << 8);
    *(void **)(unaff_EBP + -0x14) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      _vector_constructor_iterator_
                (pvVar3,0x10,*(int *)(unaff_EBP + -0x18),(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
      uVar5 = *(uint *)(unaff_EBP + -0x14);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    puVar11[1] = uVar5;
    if (uVar5 == 0) goto LAB_100170c5;
    *puVar11 = 0;
    *(int *)((int)this_00 + 0x10bc) = *(int *)((int)this_00 + 0x10bc) + 1;
  }
  if (*puVar11 == 0) {
    uVar5 = 4;
    if (3 < *(uint *)((int)this_00 + 0x103c)) {
      uVar5 = *(uint *)((int)this_00 + 0x103c);
    }
    if (((uVar9 & 3) < *(uint *)((int)this_00 + 0x1034)) || (uVar5 < (uVar9 & 3) + 4)) {
      uVar5 = *(uint *)((int)this_00 + 0x108c);
      iVar6 = (uVar9 >> 2) * *(int *)((int)this_00 + 0x1050) +
              (uVar5 >> 2) * *(int *)((int)this_00 + 0x1080) +
              *(int *)((int)this_00 + 0x1054) * *(int *)(unaff_EBP + 0xc) +
              *(int *)((int)this_00 + 0x18);
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4);
      *(uint *)(unaff_EBP + -0x18) = uVar5;
      while (uVar5 < *(uint *)((int)this_00 + 0x1094)) {
        (**(code **)((int)this_00 + 0x1084))(*(undefined4 *)(unaff_EBP + -0x14),iVar6);
        iVar6 = iVar6 + *(int *)((int)this_00 + 0x1080);
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x100;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
        uVar5 = *(uint *)(unaff_EBP + -0x18);
      }
      puVar11 = *(uint **)(unaff_EBP + -0x10);
    }
    else {
      uVar5 = *(uint *)((int)this_00 + 0x1038);
      *(undefined4 *)(unaff_EBP + -0x18) = 4;
      if (3 < uVar5) {
        *(uint *)(unaff_EBP + -0x18) = uVar5;
      }
      if (*(uint *)((int)this_00 + 0x108c) < *(uint *)((int)this_00 + 0x1030)) {
        (**(code **)((int)this_00 + 0x1084))
                  (puVar11[1],
                   (*(uint *)((int)this_00 + 0x108c) >> 2) * *(int *)((int)this_00 + 0x1080) +
                   (uVar9 >> 2) * *(int *)((int)this_00 + 0x1050) +
                   *(int *)((int)this_00 + 0x1054) * *(int *)(unaff_EBP + 0xc) +
                   *(int *)((int)this_00 + 0x18));
      }
      if (*(uint *)(unaff_EBP + -0x18) < *(uint *)((int)this_00 + 0x1094)) {
        (**(code **)((int)this_00 + 0x1084))
                  (puVar11[1],
                   (*(uint *)((int)this_00 + 0x1094) - 4 >> 2) * *(int *)((int)this_00 + 0x1080) +
                   (uVar9 >> 2) * *(int *)((int)this_00 + 0x1050) +
                   *(int *)((int)this_00 + 0x1054) * *(int *)(unaff_EBP + 0xc) +
                   *(int *)((int)this_00 + 0x18));
      }
    }
  }
  if (*(int *)((int)this_00 + 0x1048) != 0) {
    pfVar4 = grim_convert_vertex_space(this_00,*(float **)(unaff_EBP + 0x10));
    *(float **)(unaff_EBP + 0x10) = pfVar4;
  }
  uVar5 = *(int *)((int)this_00 + 0x1030) - *(int *)((int)this_00 + 0x108c);
  iVar6 = *(int *)((int)this_00 + 0x1090);
  uVar7 = *(int *)((int)this_00 + 0x1058) + uVar5;
  if (uVar5 < uVar7) {
    do {
      puVar10 = (undefined4 *)
                (((uVar5 & 0xfffffffc | uVar9 - iVar6 & 3) << 2 | uVar5 & 3) * 0x10 +
                *(int *)(*(int *)(unaff_EBP + -0x10) + 4));
      puVar2 = *(undefined4 **)(unaff_EBP + 0x10);
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 0x10;
      *puVar10 = *puVar2;
      puVar10[1] = puVar2[1];
      puVar10[2] = puVar2[2];
      uVar5 = uVar5 + 1;
      puVar10[3] = puVar2[3];
    } while (uVar5 < uVar7);
    uVar9 = *(uint *)(unaff_EBP + 8);
    puVar11 = *(uint **)(unaff_EBP + -0x10);
  }
  uVar5 = uVar9 - *(int *)((int)this_00 + 0x1090) & 3;
  if (*(int *)((int)this_00 + 0x1074) == 0) {
    *puVar11 = *puVar11 | 1 << (sbyte)uVar5;
  }
  else {
    *(undefined4 *)(unaff_EBP + 0x10) = 0;
    do {
      if ((*(uint *)((int)this_00 + 0x107c) & *(uint *)(unaff_EBP + 0x10)) == uVar5) {
        *puVar11 = *puVar11 | 1 << ((byte)*(undefined4 *)(unaff_EBP + 0x10) & 0x1f);
      }
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
    } while (*(uint *)(unaff_EBP + 0x10) < 4);
  }
  if (*puVar11 == 0xf) {
    uVar5 = *(uint *)((int)this_00 + 0x108c);
    iVar6 = (uVar9 >> 2) * *(int *)((int)this_00 + 0x1050) +
            (uVar5 >> 2) * *(int *)((int)this_00 + 0x1080) +
            *(int *)((int)this_00 + 0x1054) * *(int *)(unaff_EBP + 0xc) +
            *(int *)((int)this_00 + 0x18);
    *(uint *)(unaff_EBP + 0xc) = puVar11[1];
    *(uint *)(unaff_EBP + -0x18) = uVar5;
    while (uVar9 = *(uint *)((int)this_00 + 0x1094), *(int *)(unaff_EBP + -0x14) = iVar6,
          uVar5 < uVar9) {
      uVar9 = 0;
      if (*(int *)((int)this_00 + 0x1074) != 0) {
        uVar8 = *(undefined4 *)(unaff_EBP + 0xc);
        do {
          *(undefined4 *)(unaff_EBP + 0x10) = 0;
          iVar6 = uVar9 << 2;
          *(undefined4 *)(unaff_EBP + 8) = uVar8;
          do {
            iVar1 = (*(uint *)(unaff_EBP + 0x10) & *(uint *)((int)this_00 + 0x1078)) +
                    (*(uint *)((int)this_00 + 0x107c) & uVar9) * 4;
            if (iVar6 != iVar1) {
              puVar2 = *(undefined4 **)(unaff_EBP + 8);
              puVar10 = (undefined4 *)(iVar1 * 0x10 + *(int *)(unaff_EBP + 0xc));
              *puVar2 = *puVar10;
              puVar2[1] = puVar10[1];
              puVar2[2] = puVar10[2];
              puVar2[3] = puVar10[3];
              puVar11 = *(uint **)(unaff_EBP + -0x10);
            }
            *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x10;
            iVar6 = iVar6 + 1;
          } while (*(uint *)(unaff_EBP + 0x10) < 4);
          uVar8 = *(undefined4 *)(unaff_EBP + 8);
          uVar9 = uVar9 + 1;
        } while (uVar9 < 4);
      }
      iVar6 = *(int *)(unaff_EBP + -0x14);
      (**(code **)((int)this_00 + 0x1088))(iVar6,*(undefined4 *)(unaff_EBP + 0xc));
      iVar6 = iVar6 + *(int *)((int)this_00 + 0x1080);
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 0x100;
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
      uVar5 = *(uint *)(unaff_EBP + -0x18);
    }
    if (((puVar11 + 2 <
          (uint *)(*(int *)((int)this_00 + 0x10c0) +
                  *(int *)((int)this_00 + 0x10ac) * *(int *)((int)this_00 + 0x10a8) * 8)) &&
        (puVar11[2] == 0)) && (puVar11[3] == 0)) {
      puVar11[3] = puVar11[1];
      puVar11[1] = 0;
    }
    else {
      operator_delete((void *)puVar11[1]);
      *(int *)((int)this_00 + 0x10bc) = *(int *)((int)this_00 + 0x10bc) + -1;
    }
    puVar11[1] = 0;
  }
LAB_100170c5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



