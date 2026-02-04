/* FUN_10017c6a @ 10017c6a */

/* [binja] int16_t __thiscall sub_10017c6a(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10017c6a(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  byte *extraout_EDX;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  byte local_20;
  
  uVar7 = 0;
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar4 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar6 = 0;
    pbVar5 = extraout_EDX;
    do {
      fVar3 = *(float *)(iVar4 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar7 & 3) * 4);
      pfVar1 = (float *)(iVar6 + arg3);
      iVar2 = iVar6 + 8;
      local_20 = (byte)(int)ROUND(*(float *)(iVar6 + 4 + arg3) * 7.0 + fVar3);
      iVar6 = iVar6 + 0x10;
      *pbVar5 = ((char)(int)ROUND(*pfVar1 * 7.0 + fVar3) << 3 | local_20) << 2 |
                (byte)(int)ROUND(*(float *)(iVar2 + arg3) * 3.0 + fVar3);
      pbVar5 = pbVar5 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



