/* FUN_10017604 @ 10017604 */

/* [binja] int16_t __thiscall sub_10017604(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10017604(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  uint *extraout_EDX;
  uint *puVar8;
  uint uVar9;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar6 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  uVar9 = 0;
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar7 = 0;
    puVar8 = extraout_EDX;
    do {
      fVar5 = *(float *)(iVar6 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar9 & 3) * 4);
      pfVar1 = (float *)(iVar7 + arg3);
      iVar2 = iVar7 + 4;
      iVar3 = iVar7 + 8;
      iVar4 = iVar7 + 0xc;
      iVar7 = iVar7 + 0x10;
      *puVar8 = (((int)ROUND(*(float *)(iVar4 + arg3) * 255.0 + fVar5) << 8 |
                 (int)ROUND(*pfVar1 * 255.0 + fVar5)) << 8 |
                (int)ROUND(*(float *)(iVar2 + arg3) * 255.0 + fVar5)) << 8 |
                (int)ROUND(*(float *)(iVar3 + arg3) * 255.0 + fVar5);
      puVar8 = puVar8 + 1;
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



