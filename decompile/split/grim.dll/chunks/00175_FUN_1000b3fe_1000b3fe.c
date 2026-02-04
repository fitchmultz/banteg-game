/* FUN_1000b3fe @ 1000b3fe */

/* [binja] int32_t __stdcall sub_1000b3fe(int32_t* arg1, int32_t* arg2, int32_t arg3, int32_t arg4,
   float arg5) */

int FUN_1000b3fe(int *arg1,int *arg2,int arg3,int arg4,float arg5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  float *pfVar8;
  float *extraout_EDX;
  float *pfVar9;
  int extraout_EDX_00;
  float *extraout_EDX_01;
  int iVar10;
  int unaff_ESI;
  int iVar11;
  float10 fVar12;
  float in_stack_00000018;
  uint local_1a0 [19];
  uint local_154 [19];
  int local_108 [6];
  int local_f0;
  uint local_ec;
  int local_e8 [4];
  int local_d8 [4];
  undefined1 local_c8 [24];
  int local_b0;
  float local_a8 [8];
  float local_88;
  float local_84;
  float local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70 [6];
  int local_58;
  uint local_54;
  float local_50;
  float local_4c;
  float local_48;
  uint local_44;
  void *local_40;
  void *local_3c;
  int *local_38;
  float local_34;
  int *local_30;
  void *local_2c;
  void *local_28;
  float *local_24;
  float *local_20;
  int *local_1c;
  int *local_18;
  float local_14;
  uint local_10;
  float *local_c;
  uint local_8;
  
  local_30 = (int *)0x0;
  local_38 = (int *)0x0;
  local_18 = (int *)0x0;
  local_1c = (int *)0x0;
  FUN_10016121(local_d8);
  FUN_10016121(local_e8);
  if (arg1 == (int *)0x0) {
    iVar10 = -0x7789f794;
    goto LAB_1000bbde;
  }
  if (arg2 != (int *)0x0) {
    if (arg4 == -1) {
      arg4 = 0;
    }
    if ((arg4 & 0xffe4ffffU) == 0) {
      if (arg5 == -NAN) {
        arg5 = 1.4013e-45;
      }
      if ((arg5 != 0.0) &&
         (((((uint)arg5 < 3 || (arg5 == 5.60519e-45)) || (arg5 == 1.12104e-44)) ||
          (arg5 == 2.24208e-44)))) {
        iVar10 = (**(code **)(*arg1 + 0x38))(arg1,0,local_108);
        if ((iVar10 < 0) || (iVar10 = (**(code **)(*arg2 + 0x38))(arg2,0,local_70), iVar10 < 0)) {
          iVar10 = -0x7fffbffb;
          goto LAB_1000bbde;
        }
        piVar5 = grim_format_info_lookup(local_70[0]);
        piVar6 = grim_format_info_lookup(local_108[0]);
        if ((((*piVar5 != 0) && (*piVar6 != 0)) &&
            ((((iVar10 = piVar5[1], iVar10 == 0 || (iVar10 == 1)) ||
              ((iVar10 == 2 || (iVar10 == 4)))) &&
             ((((piVar6[1] == 0 && (1 < (uint)piVar6[5])) && (1 < (uint)piVar6[6])) &&
              ((1 < (uint)piVar6[7] && (local_58 == local_f0)))))))) && (local_54 == local_ec)) {
          uVar7 = (**(code **)(*arg2 + 0x34))(arg2);
          local_44 = (**(code **)(*arg1 + 0x34))(arg1);
          if (uVar7 == local_44) {
            iVar10 = (**(code **)(*arg1 + 0x38))(arg1,0,local_c8);
            iVar11 = local_b0;
            if (-1 < iVar10) {
              local_28 = operator_new(local_b0 << 4);
              if (local_28 == (void *)0x0) {
                local_28 = (void *)0x0;
              }
              else {
                _vector_constructor_iterator_
                          (local_28,0x10,iVar11,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
              }
              iVar10 = local_b0;
              local_3c = operator_new(local_b0 << 4);
              if (local_3c == (void *)0x0) {
                local_3c = (void *)0x0;
              }
              else {
                _vector_constructor_iterator_
                          (local_3c,0x10,iVar10,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
              }
              iVar10 = local_b0;
              local_40 = operator_new(local_b0 << 4);
              if (local_40 == (void *)0x0) {
                local_40 = (void *)0x0;
              }
              else {
                _vector_constructor_iterator_
                          (local_40,0x10,iVar10,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
              }
              iVar10 = local_b0;
              local_2c = operator_new(local_b0 << 4);
              if (local_2c == (void *)0x0) {
                local_2c = (void *)0x0;
              }
              else {
                _vector_constructor_iterator_
                          (local_2c,0x10,iVar10,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
              }
              local_20 = operator_new(local_b0 * 4 + 8);
              local_c = operator_new(local_b0 * 4 + 8);
              local_24 = operator_new(local_b0 * 4 + 8);
              if ((((local_3c == (void *)0x0) || (local_40 == (void *)0x0)) ||
                  ((local_2c == (void *)0x0 ||
                   (((local_28 == (void *)0x0 || (local_20 == (float *)0x0)) ||
                    (local_c == (float *)0x0)))))) || (local_24 == (float *)0x0)) {
                iVar10 = -0x7ff8fff2;
LAB_1000bb62:
                piVar5 = local_38;
                if (local_30 != (int *)0x0) {
                  (**(code **)*local_30)(1);
                }
                if (piVar5 != (int *)0x0) {
                  (**(code **)*piVar5)(1);
                }
              }
              else {
                local_10 = 0;
                if (local_44 != 0) {
                  do {
                    (**(code **)(*arg1 + 0x3c))(arg1,local_10,&local_1c);
                    (**(code **)(*arg2 + 0x3c))(arg2,local_10,&local_18);
                    if (local_10 == 0) {
                      iVar10 = 0x20000;
                    }
                    else {
                      iVar10 = 0;
                    }
                    iVar10 = FUN_100161bb(local_d8,(char *)local_1a0,local_1c,(int *)0x0,0,
                                          (int *)0x0,iVar10,unaff_ESI);
                    if (iVar10 < 0) goto LAB_1000bb7b;
                    if (arg1 == arg2) {
                      iVar10 = 0x10001;
                    }
                    else {
                      iVar10 = 1;
                    }
                    iVar10 = FUN_100161bb(local_e8,(char *)local_154,local_18,(int *)0x0,0,
                                          (int *)0x0,iVar10,unaff_ESI);
                    if (((iVar10 < 0) ||
                        (iVar10 = (**(code **)(*arg1 + 0x38))(arg1,local_10,local_108), iVar10 < 0))
                       || (iVar10 = (**(code **)(*arg2 + 0x38))(arg2,local_10,local_70), iVar10 < 0)
                       ) goto LAB_1000bb7b;
                    piVar5 = grim_pixel_format_create(local_154);
                    local_30 = piVar5;
                    local_38 = grim_pixel_format_create(local_1a0);
                    if ((piVar5 == (int *)0x0) || (local_38 == (int *)0x0)) {
                      iVar10 = -0x7fffbffb;
                      goto LAB_1000bb62;
                    }
                    (**(code **)(*piVar5 + 4))(local_54 - 1,0,local_28);
                    (**(code **)(*piVar5 + 4))(0,0,local_3c);
                    fVar12 = FUN_1000b3b5((int)arg5);
                    pfVar9 = local_20;
                    *local_20 = (float)fVar12;
                    fVar12 = FUN_1000b3b5((int)arg5);
                    *local_c = (float)fVar12;
                    fVar12 = FUN_1000b3b5((int)arg5);
                    pfVar9[local_58 + 1] = (float)fVar12;
                    fVar12 = FUN_1000b3b5((int)arg5);
                    extraout_EDX[local_58 + 1] = (float)fVar12;
                    local_8 = 0;
                    if (0 < local_58) {
                      pfVar8 = extraout_EDX;
                      do {
                        pfVar8 = pfVar8 + 1;
                        fVar12 = FUN_1000b3b5((int)arg5);
                        *(float *)(((int)pfVar9 - (int)extraout_EDX) + (int)pfVar8) = (float)fVar12;
                        fVar12 = FUN_1000b3b5((int)arg5);
                        *pfVar8 = (float)fVar12;
                        local_8 = local_8 + 1;
                      } while ((int)local_8 < local_58);
                    }
                    local_8 = 0;
                    if (0 < (int)local_54) {
                      do {
                        local_78 = local_8 + 1;
                        pfVar9 = (float *)(local_78 % local_54);
                        (**(code **)(*local_30 + 4))(pfVar9,0,local_40);
                        fVar12 = FUN_1000b3b5((int)arg5);
                        *local_24 = (float)fVar12;
                        fVar12 = FUN_1000b3b5((int)arg5);
                        iVar10 = 0;
                        *(float *)(extraout_EDX_00 + 4 + local_58 * 4) = (float)fVar12;
                        iVar11 = 0;
                        if (0 < local_58) {
                          do {
                            fVar12 = FUN_1000b3b5((int)arg5);
                            *extraout_EDX_01 = (float)fVar12;
                            iVar11 = iVar11 + 1;
                          } while (iVar11 < local_58);
                          if (0 < local_58) {
                            local_74 = arg4 & 0x100000;
                            local_80 = 1.0;
                            local_7c = arg4 & 0x80000;
                            do {
                              iVar11 = 0;
                              local_14 = 0.0;
                              if ((iVar10 != 0) || ((arg4 & 0x10000U) == 0)) {
                                local_14 = local_c[iVar10 + 1] + local_c[iVar10];
                                iVar11 = 1;
                              }
                              if ((iVar10 < local_58 + -1) || ((arg4 & 0x10000U) == 0)) {
                                iVar11 = iVar11 + 1;
                                local_14 = local_14 - (local_c[iVar10 + 2] + local_c[iVar10 + 1]);
                              }
                              local_14 = local_14 * in_stack_00000018;
                              if (iVar11 != 1) {
                                local_14 = local_14 * 0.5;
                              }
                              iVar11 = 0;
                              local_34 = 0.0;
                              if ((local_8 != 0) || ((arg4 & 0x20000U) == 0)) {
                                local_34 = local_c[iVar10 + 1] + local_20[iVar10 + 1];
                                iVar11 = 1;
                              }
                              if (((int)local_8 < (int)(local_54 - 1)) || ((arg4 & 0x20000U) == 0))
                              {
                                iVar11 = iVar11 + 1;
                                local_34 = local_34 - (local_24[iVar10 + 1] + local_c[iVar10 + 1]);
                              }
                              if (iVar11 == 1) {
                                fVar1 = local_34 * in_stack_00000018;
                              }
                              else {
                                fVar1 = local_34 * in_stack_00000018 * 0.5;
                              }
                              pfVar9 = &local_50;
                              local_88 = fVar1 * 0.0 - local_14 * -1.0;
                              local_84 = local_14 * 0.0 - fVar1 * -1.0;
                              local_48 = local_80;
                              local_50 = local_88;
                              local_4c = local_84;
                              thunk_FUN_1000ce69();
                              local_14 = 1.0;
                              if (local_74 != 0) {
                                local_a8[0] = local_20[iVar10];
                                local_a8[1] = local_20[iVar10 + 1];
                                local_a8[2] = local_20[iVar10 + 2];
                                local_a8[4] = local_c[iVar10 + 2];
                                local_a8[3] = local_c[iVar10];
                                local_a8[7] = local_24[iVar10 + 2];
                                local_a8[5] = local_24[iVar10];
                                fVar3 = 0.0;
                                fVar1 = (local_c + iVar10)[1];
                                local_a8[6] = local_24[iVar10 + 1];
                                iVar11 = 0;
                                do {
                                  pfVar8 = local_a8 + iVar11;
                                  fVar2 = *pfVar8 - fVar1;
                                  *pfVar8 = fVar2;
                                  if (fVar2 < 0.0) {
                                    *pfVar8 = 0.0;
                                  }
                                  iVar11 = iVar11 + 1;
                                  fVar3 = fVar3 + *pfVar8;
                                } while (iVar11 < 8);
                                fVar1 = fVar3 * in_stack_00000018 * 0.125;
                                if (0.0 < fVar1) {
                                  local_14 = SQRT(fVar1 * fVar1 + 1.0);
                                  local_14 = (local_14 - fVar1) / local_14;
                                }
                              }
                              pfVar8 = (float *)(iVar10 * 0x10 + (int)local_2c);
                              if (local_7c == 0) {
                                *pfVar8 = (local_50 + 1.0) * 0.5;
                                pfVar8[1] = (local_4c + 1.0) * 0.5;
                                fVar1 = (local_48 + 1.0) * 0.5;
                              }
                              else {
                                *pfVar8 = 0.5 - local_50 * 0.5;
                                pfVar8[1] = 0.5 - local_4c * 0.5;
                                fVar1 = 0.5 - local_48 * 0.5;
                              }
                              iVar10 = iVar10 + 1;
                              pfVar8[2] = fVar1;
                              pfVar8[3] = local_14;
                            } while (iVar10 < local_58);
                          }
                        }
                        (**(code **)(*local_38 + 8))(local_8,0,local_2c,pfVar9);
                        pfVar8 = local_20;
                        pfVar4 = local_24;
                        pfVar9 = local_c;
                        local_20 = local_c;
                        local_c = local_24;
                        local_24 = pfVar8;
                        local_8 = local_78;
                      } while ((int)local_78 < (int)local_54);
                    }
                    (**(code **)*local_30)(1);
                    (**(code **)*local_38)(1);
                    if (local_18 != (int *)0x0) {
                      (**(code **)(*local_18 + 8))(local_18);
                      local_18 = (int *)0x0;
                    }
                    if (local_1c != (int *)0x0) {
                      (**(code **)(*local_1c + 8))(local_1c);
                      local_1c = (int *)0x0;
                    }
                    local_10 = local_10 + 1;
                  } while (local_10 < local_44);
                }
                iVar10 = 0;
              }
LAB_1000bb7b:
              if (local_18 != (int *)0x0) {
                (**(code **)(*local_18 + 8))(local_18);
                local_18 = (int *)0x0;
              }
              if (local_1c != (int *)0x0) {
                (**(code **)(*local_1c + 8))(local_1c);
                local_1c = (int *)0x0;
              }
              operator_delete(local_28);
              operator_delete(local_3c);
              operator_delete(local_40);
              operator_delete(local_2c);
              operator_delete(local_20);
              operator_delete(local_c);
              operator_delete(local_24);
            }
            goto LAB_1000bbde;
          }
        }
      }
    }
  }
  iVar10 = -0x7789f794;
LAB_1000bbde:
  FUN_100161b6((char *)local_e8);
  FUN_100161b6((char *)local_d8);
  return iVar10;
}



