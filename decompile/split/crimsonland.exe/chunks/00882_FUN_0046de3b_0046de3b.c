/* FUN_0046de3b @ 0046de3b */

/* [binja] int16_t* sub_46de3b(int16_t* arg1, int32_t* arg2) */

short * __cdecl FUN_0046de3b(short *arg1,int *arg2)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  int *piVar5;
  short *psVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  byte local_28;
  undefined1 uStack_27;
  short sStack_26;
  short local_24;
  undefined2 uStack_22;
  undefined2 local_20;
  undefined1 uStack_1e;
  byte bStack_1d;
  int *local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  ushort *local_c;
  short *local_8;
  
  piVar5 = arg2;
  psVar4 = arg1;
  local_18 = 0;
  local_28 = 0;
  uStack_27 = 0;
  sStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  local_20 = 0;
  uStack_1e = 0;
  bStack_1d = 0;
  psVar6 = (short *)((ushort)arg1[5] & 0x7fff);
  uVar9 = *(ushort *)((int)arg2 + 10) & 0x7fff;
  uVar10 = (ushort)(*(ushort *)((int)arg2 + 10) ^ arg1[5]) & 0x8000;
  psVar1 = (short *)(uVar9 + (int)psVar6);
  if ((((ushort)psVar6 < 0x7fff) && (uVar8 = (ushort)uVar9, uVar8 < 0x7fff)) &&
     ((ushort)psVar1 < 0xbffe)) {
    if ((ushort)psVar1 < 0x3fc0) {
LAB_0046dede:
      psVar4[4] = 0;
      psVar4[5] = 0;
      psVar4[2] = 0;
      psVar4[3] = 0;
      psVar4[0] = 0;
      psVar4[1] = 0;
      return (short *)0x0;
    }
    if ((((ushort)psVar6 != 0) ||
        (psVar1 = (short *)((int)psVar1 + 1), (*(uint *)(arg1 + 4) & 0x7fffffff) != 0)) ||
       ((psVar6 = (short *)0x0, *(int *)(arg1 + 2) != 0 || (*(int *)arg1 != 0)))) {
      arg1 = psVar1;
      if (((uVar8 == 0) && (arg1 = (short *)((int)arg1 + 1), (arg2[2] & 0x7fffffffU) == 0)) &&
         ((arg2[1] == 0 && (*arg2 == 0)))) goto LAB_0046dede;
      local_14 = 0;
      local_8 = &local_24;
      arg2 = (int *)0x5;
      do {
        if (0 < (int)arg2) {
          local_c = (ushort *)(psVar4 + local_14);
          local_10 = (ushort *)(piVar5 + 2);
          local_1c = arg2;
          do {
            iVar7 = crt_add_u32_carry(*(uint *)(local_8 + -2),(uint)*local_c * (uint)*local_10,
                                      (uint *)(local_8 + -2));
            if (iVar7 != 0) {
              *local_8 = *local_8 + 1;
            }
            local_c = local_c + 1;
            local_10 = local_10 + -1;
            local_1c = (int *)((int)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
        arg2 = (int *)((int)arg2 + -1);
      } while (0 < (int)arg2);
      arg1 = arg1 + 0x6001;
      if ((short)arg1 < 1) {
LAB_0046df92:
        arg1 = (short *)((int)arg1 + 0xffff);
        if ((short)arg1 < 0) {
          iVar7 = -(int)(short)arg1;
          arg1 = (short *)((int)arg1 + iVar7);
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            crt_u96_shr1((uint *)&local_28);
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          if (local_18 != 0) {
            local_28 = local_28 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_1d & 0x80) != 0) break;
          crt_u96_shl1((uint *)&local_28);
          arg1 = (short *)((int)arg1 + 0xffff);
        } while (0 < (short)arg1);
        if ((short)arg1 < 1) goto LAB_0046df92;
      }
      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||
         (sVar2 = CONCAT11(bStack_1d,uStack_1e), iVar3 = CONCAT22(local_20,uStack_22),
         iVar7 = CONCAT22(local_24,sStack_26),
         (CONCAT22(sStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_24,sStack_26) == -1) {
          iVar7 = 0;
          if (CONCAT22(local_20,uStack_22) == -1) {
            if (CONCAT11(bStack_1d,uStack_1e) == -1) {
              arg1 = (short *)((int)arg1 + 1);
              sVar2 = -0x8000;
              iVar3 = 0;
              iVar7 = 0;
            }
            else {
              sVar2 = CONCAT11(bStack_1d,uStack_1e) + 1;
              iVar3 = 0;
              iVar7 = 0;
            }
          }
          else {
            sVar2 = CONCAT11(bStack_1d,uStack_1e);
            iVar3 = CONCAT22(local_20,uStack_22) + 1;
          }
        }
        else {
          iVar7 = CONCAT22(local_24,sStack_26) + 1;
          sVar2 = CONCAT11(bStack_1d,uStack_1e);
          iVar3 = CONCAT22(local_20,uStack_22);
        }
      }
      local_24 = (short)((uint)iVar7 >> 0x10);
      sStack_26 = (short)iVar7;
      local_20 = (undefined2)((uint)iVar3 >> 0x10);
      uStack_22 = (undefined2)iVar3;
      bStack_1d = (byte)((ushort)sVar2 >> 8);
      uStack_1e = (undefined1)sVar2;
      psVar6 = arg1;
      if (0x7ffe < (ushort)arg1) goto LAB_0046e03b;
      psVar6 = (short *)((uint)arg1 | uVar10);
      *psVar4 = sStack_26;
      *(uint *)(psVar4 + 1) = CONCAT22(uStack_22,local_24);
      *(uint *)(psVar4 + 3) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    psVar4[5] = (short)psVar6;
  }
  else {
LAB_0046e03b:
    psVar4[2] = 0;
    psVar4[3] = 0;
    psVar4[0] = 0;
    psVar4[1] = 0;
    *(uint *)(psVar4 + 4) = (-(uint)((short)uVar10 != 0) & 0x80000000) + 0x7fff8000;
  }
  return psVar6;
}



