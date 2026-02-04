/* FUN_10017f34 @ 10017f34 */

/* [binja] int16_t __thiscall sub_10017f34(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10017f34(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  ushort *extraout_EDX;
  ushort *puVar7;
  uint uVar8;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar5 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  uVar8 = 0;
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar6 = 0;
    puVar7 = extraout_EDX;
    do {
      fVar4 = *(float *)(iVar5 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar8 & 3) * 4);
      pfVar1 = (float *)(iVar6 + arg3);
      iVar2 = iVar6 + 4;
      iVar3 = iVar6 + 8;
      iVar6 = iVar6 + 0x10;
      *puVar7 = (ushort)(((int)ROUND(*pfVar1 * 15.0 + fVar4) << 4 |
                         (int)ROUND(*(float *)(iVar2 + arg3) * 15.0 + fVar4)) << 4) |
                (ushort)(int)ROUND(*(float *)(iVar3 + arg3) * 15.0 + fVar4);
      puVar7 = puVar7 + 1;
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



