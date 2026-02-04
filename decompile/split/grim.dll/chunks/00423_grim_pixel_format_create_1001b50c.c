/* grim_pixel_format_create @ 1001b50c */

/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* factory: picks pixel format implementation from FourCC/D3DFORMAT */

void * grim_pixel_format_create(uint *desc)

{
  uint *desc_00;
  uint uVar1;
  void *pvVar2;
  int unaff_EBP;
  int *piVar3;
  
  seh_prolog();
  desc_00 = *(uint **)(unaff_EBP + 8);
  uVar1 = desc_00[1];
  piVar3 = (int *)0x0;
  if ((int)uVar1 < 0x31545845) {
    if (uVar1 == 0x31545844) {
      pvVar2 = operator_new(0x10c4);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x20;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_dxt1(pvVar2,desc_00);
    }
    else if ((int)uVar1 < 0x29) {
      if (uVar1 == 0x28) {
        pvVar2 = operator_new(0x106c);
        *(void **)(unaff_EBP + 8) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0xd;
        if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
        piVar3 = grim_pixel_format_ctor_a8p8(pvVar2,desc_00);
      }
      else {
        switch(uVar1) {
        case 0x14:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          if (pvVar2 == (void *)0x0) {
LAB_1001bc03:
            piVar3 = (int *)0x0;
          }
          else {
            piVar3 = grim_pixel_format_ctor_r8g8b8(pvVar2,desc_00);
          }
          break;
        case 0x15:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_a8r8g8b8(pvVar2,desc_00);
          break;
        case 0x16:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_x8r8g8b8(pvVar2,desc_00);
          break;
        case 0x17:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 3;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_r5g6b5(pvVar2,desc_00);
          break;
        case 0x18:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 4;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_x1r5g5b5(pvVar2,desc_00);
          break;
        case 0x19:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 5;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_a1r5g5b5(pvVar2,desc_00);
          break;
        case 0x1a:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 6;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_a4r4g4b4(pvVar2,desc_00);
          break;
        case 0x1b:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 7;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_r3g3b2(pvVar2,desc_00);
          break;
        case 0x1c:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 8;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_a8(pvVar2,desc_00);
          break;
        case 0x1d:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 9;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_a8r3g3b2(pvVar2,desc_00);
          break;
        case 0x1e:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 10;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_x4r4g4b4(pvVar2,desc_00);
          break;
        case 0x1f:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 0xb;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_a2b10g10r10(pvVar2,desc_00);
          break;
        default:
          goto switchD_1001b54e_caseD_20;
        case 0x22:
          pvVar2 = operator_new(0x106c);
          *(void **)(unaff_EBP + 8) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 0xc;
          if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
          piVar3 = grim_pixel_format_ctor_g16r16(pvVar2,desc_00);
        }
      }
    }
    else if ((int)uVar1 < 0x3f) {
      if (uVar1 == 0x3e) {
        pvVar2 = operator_new(0x106c);
        *(void **)(unaff_EBP + 8) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0x14;
        if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
        piVar3 = grim_pixel_format_ctor_x8l8v8u8(pvVar2,desc_00);
      }
      else if (uVar1 == 0x29) {
        pvVar2 = operator_new(0x106c);
        *(void **)(unaff_EBP + 8) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0xe;
        if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
        piVar3 = grim_pixel_format_ctor_p8(pvVar2,desc_00);
      }
      else if (uVar1 == 0x32) {
        pvVar2 = operator_new(0x106c);
        *(void **)(unaff_EBP + 8) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0xf;
        if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
        piVar3 = grim_pixel_format_ctor_l8(pvVar2,desc_00);
      }
      else if (uVar1 == 0x33) {
        pvVar2 = operator_new(0x106c);
        *(void **)(unaff_EBP + 8) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0x10;
        if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
        piVar3 = grim_pixel_format_ctor_a8l8(pvVar2,desc_00);
      }
      else if (uVar1 == 0x34) {
        pvVar2 = operator_new(0x106c);
        *(void **)(unaff_EBP + 8) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0x11;
        if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
        piVar3 = grim_pixel_format_ctor_a4l4(pvVar2,desc_00);
      }
      else if (uVar1 == 0x3c) {
        pvVar2 = operator_new(0x106c);
        *(void **)(unaff_EBP + 8) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0x12;
        if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
        piVar3 = grim_pixel_format_ctor_v8u8(pvVar2,desc_00);
      }
      else {
        if (uVar1 != 0x3d) goto switchD_1001b54e_caseD_20;
        pvVar2 = operator_new(0x106c);
        *(void **)(unaff_EBP + 8) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0x13;
        if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
        piVar3 = grim_pixel_format_ctor_l6v5u5(pvVar2,desc_00);
      }
    }
    else if (uVar1 == 0x3f) {
      pvVar2 = operator_new(0x106c);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x15;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_q8w8v8u8(pvVar2,desc_00);
    }
    else if (uVar1 == 0x40) {
      pvVar2 = operator_new(0x106c);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x16;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_v16u16(pvVar2,desc_00);
    }
    else if (uVar1 == 0x41) {
      pvVar2 = operator_new(0x106c);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x17;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_w11v11u10(pvVar2,desc_00);
    }
    else if (uVar1 == 0x43) {
      pvVar2 = operator_new(0x106c);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x18;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_a2w10v10u10(pvVar2,desc_00);
    }
    else {
      if (uVar1 != 0x46) goto switchD_1001b54e_caseD_20;
      pvVar2 = operator_new(0x106c);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x19;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_d16_lockable(pvVar2,desc_00);
    }
  }
  else if ((int)uVar1 < 0x36314c21) {
    if (uVar1 == 0x36314c20) {
      pvVar2 = operator_new(0x106c);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x1a;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_l16(pvVar2,desc_00);
    }
    else if (uVar1 == 0x32545844) {
      pvVar2 = operator_new(0x10c4);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x21;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_dxt2(pvVar2,desc_00);
    }
    else if (uVar1 == 0x32595559) {
      pvVar2 = operator_new(0x109c);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x1f;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_yuy2(pvVar2);
    }
    else if (uVar1 == 0x33545844) {
      pvVar2 = operator_new(0x10c4);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x22;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_dxt3(pvVar2,desc_00);
    }
    else if (uVar1 == 0x34545844) {
      pvVar2 = operator_new(0x10c4);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x23;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_dxt4(pvVar2,desc_00);
    }
    else {
      if (uVar1 != 0x35545844) goto switchD_1001b54e_caseD_20;
      pvVar2 = operator_new(0x10c4);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x24;
      if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
      piVar3 = grim_pixel_format_ctor_dxt5(pvVar2,desc_00);
    }
  }
  else if (uVar1 == 0x36314c41) {
    pvVar2 = operator_new(0x106c);
    *(void **)(unaff_EBP + 8) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0x1b;
    if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
    piVar3 = grim_pixel_format_ctor_al16(pvVar2,desc_00);
  }
  else if (uVar1 == 0x36315220) {
    pvVar2 = operator_new(0x106c);
    *(void **)(unaff_EBP + 8) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0x1c;
    if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
    piVar3 = grim_pixel_format_ctor_r16(pvVar2,desc_00);
  }
  else if (uVar1 == 0x36315241) {
    pvVar2 = operator_new(0x106c);
    *(void **)(unaff_EBP + 8) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0x1d;
    if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
    piVar3 = grim_pixel_format_ctor_ar16(pvVar2,desc_00);
  }
  else {
    if (uVar1 != 0x59565955) goto switchD_1001b54e_caseD_20;
    pvVar2 = operator_new(0x109c);
    *(void **)(unaff_EBP + 8) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0x1e;
    if (pvVar2 == (void *)0x0) goto LAB_1001bc03;
    piVar3 = grim_pixel_format_ctor_uyvy(pvVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if ((piVar3 != (int *)0x0) && (piVar3[4] != 0)) {
    (**(code **)(*piVar3 + 0xc))();
  }
switchD_1001b54e_caseD_20:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}



