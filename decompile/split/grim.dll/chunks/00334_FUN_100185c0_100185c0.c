/* FUN_100185c0 @ 100185c0 */

/* [binja] int16_t __thiscall sub_100185c0(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_100185c0(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  byte *extraout_EDX;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar2 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar5 = 0;
    pbVar4 = extraout_EDX;
    do {
      fVar1 = *(float *)(iVar2 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar6 & 3) * 4);
      pfVar3 = (float *)(arg3 + iVar5);
      *pbVar4 = (char)(int)ROUND(*(float *)(iVar5 + 0xc + arg3) * 15.0 + fVar1) << 4 |
                (byte)(int)ROUND((*pfVar3 * 0.2125 + pfVar3[1] * 0.7154 + pfVar3[2] * 0.0721) * 15.0
                                 + fVar1);
      pbVar4 = pbVar4 + 1;
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 0x10;
    } while (uVar6 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



