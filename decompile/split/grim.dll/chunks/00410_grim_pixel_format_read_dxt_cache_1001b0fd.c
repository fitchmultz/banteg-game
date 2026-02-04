/* grim_pixel_format_read_dxt_cache @ 1001b0fd */

/* decodes DXT blocks into cache on demand and copies RGBA floats to output (color key aware) */

void grim_pixel_format_read_dxt_cache(void *this,uint x,uint y,float *out)

{
  undefined4 *puVar1;
  void *pvVar2;
  int extraout_ECX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_EDX;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  undefined4 *puVar8;
  
  seh_prolog();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + *(int *)(extraout_ECX + 0x1034);
  *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + *(int *)(extraout_ECX + 0x1040);
  iVar3 = extraout_ECX;
  if (*(int *)(extraout_ECX + 0x10b8) == 0) {
    iVar3 = *(int *)(extraout_ECX + 0x10a4);
    pvVar2 = operator_new(iVar3 << 8);
    *(void **)(unaff_EBP + -0x24) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      _vector_constructor_iterator_(pvVar2,0x10,iVar3 << 4,(_func_void_ptr_void_ptr *)&LAB_1000ae4f)
      ;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(void **)(*(int *)(unaff_EBP + -0x10) + 0x10b8) = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_1001b396;
    iVar3 = *(int *)(unaff_EBP + -0x10);
  }
  uVar4 = *(uint *)(unaff_EBP + 8) & 0xfffffffc;
  if ((uVar4 != *(uint *)(iVar3 + 0x10b0)) ||
     (*(int *)(unaff_EBP + 0xc) != *(int *)(iVar3 + 0x10b4))) {
    *(uint *)(iVar3 + 0x10b0) = uVar4;
    *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10b4) = *(undefined4 *)(unaff_EBP + 0xc);
    iVar3 = *(int *)(unaff_EBP + -0x10);
    uVar4 = *(uint *)(iVar3 + 0x108c);
    iVar6 = *(int *)(iVar3 + 0x10b8);
    iVar7 = (*(uint *)(iVar3 + 0x10b0) >> 2) * *(int *)(iVar3 + 0x1050) +
            (uVar4 >> 2) * *(int *)(iVar3 + 0x1080) +
            *(int *)(iVar3 + 0x10b4) * *(int *)(iVar3 + 0x1054) + *(int *)(iVar3 + 0x18);
    for (; uVar4 < *(uint *)(iVar3 + 0x1094); uVar4 = uVar4 + 4) {
      (**(code **)(iVar3 + 0x1084))(iVar6,iVar7);
      iVar3 = *(int *)(unaff_EBP + -0x10);
      iVar7 = iVar7 + *(int *)(iVar3 + 0x1080);
      iVar6 = iVar6 + 0x100;
    }
  }
  iVar6 = *(int *)(unaff_EBP + 8);
  iVar7 = *(int *)(iVar3 + 0x1090);
  uVar4 = *(int *)(iVar3 + 0x1030) - *(int *)(iVar3 + 0x108c);
  uVar5 = *(int *)(iVar3 + 0x1058) + uVar4;
  for (; uVar4 < uVar5; uVar4 = uVar4 + 1) {
    puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
    puVar8 = (undefined4 *)
             (((uVar4 & 0xfffffffc | iVar6 - iVar7 & 3U) << 2 | uVar4 & 3) * 0x10 +
             *(int *)(iVar3 + 0x10b8));
    *puVar1 = *puVar8;
    puVar1[1] = puVar8[1];
    puVar1[2] = puVar8[2];
    puVar1[3] = puVar8[3];
    *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 0x10;
    iVar3 = *(int *)(unaff_EBP + -0x10);
  }
  if (*(int *)(iVar3 + 0x10) != 0) {
    fpu_set_round_trunc();
    while (*(uint *)(unaff_EBP + 0x10) < extraout_EDX) {
      *(float *)(unaff_EBP + -0x14) = **(float **)(unaff_EBP + 0x10) * 31.0 + 0.5;
      *(int *)(unaff_EBP + -0x18) = (int)ROUND(*(float *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x18);
      *(float *)(unaff_EBP + -0x34) = (float)*(int *)(unaff_EBP + -0x14) * 0.032258064;
      *(float *)(unaff_EBP + -0x14) = *(float *)(*(int *)(unaff_EBP + 0x10) + 4) * 63.0 + 0.5;
      *(int *)(unaff_EBP + -0x1c) = (int)ROUND(*(float *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x1c);
      *(float *)(unaff_EBP + -0x30) = (float)*(int *)(unaff_EBP + -0x14) * 0.015873017;
      *(float *)(unaff_EBP + -0x14) = *(float *)(*(int *)(unaff_EBP + 0x10) + 8) * 31.0 + 0.5;
      *(int *)(unaff_EBP + -0x20) = (int)ROUND(*(float *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x20);
      *(float *)(unaff_EBP + -0x2c) = (float)*(int *)(unaff_EBP + -0x14) * 0.032258064;
      *(float *)(unaff_EBP + -0x14) =
           *(float *)(*(int *)(unaff_EBP + -0x10) + 0x106c) *
           *(float *)(*(int *)(unaff_EBP + 0x10) + 0xc) + 0.5;
      *(int *)(unaff_EBP + -0x24) = (int)ROUND(*(float *)(unaff_EBP + -0x14));
      iVar3 = *(int *)(unaff_EBP + -0x10);
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x24);
      if ((((*(float *)(unaff_EBP + -0x34) == *(float *)(iVar3 + 0x1c)) &&
           (*(float *)(unaff_EBP + -0x30) == *(float *)(iVar3 + 0x20))) &&
          (*(float *)(unaff_EBP + -0x2c) == *(float *)(iVar3 + 0x24))) &&
         ((float)*(int *)(unaff_EBP + -0x14) * *(float *)(iVar3 + 0x1070) ==
          *(float *)(iVar3 + 0x28))) {
        puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        *puVar1 = *(undefined4 *)(unaff_EBP + -0x44);
        puVar1[1] = *(undefined4 *)(unaff_EBP + -0x40);
        puVar1[2] = *(undefined4 *)(unaff_EBP + -0x3c);
        puVar1[3] = *(undefined4 *)(unaff_EBP + -0x38);
      }
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 0x10;
    }
    *(undefined4 *)(unaff_EBP + -0x24) = DAT_1005db6c;
  }
LAB_1001b396:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



