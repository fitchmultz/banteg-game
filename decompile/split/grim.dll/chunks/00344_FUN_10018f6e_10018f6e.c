/* FUN_10018f6e @ 10018f6e */

/* [binja] int16_t __thiscall sub_10018f6e(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10018f6e(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  uint *extraout_EDX;
  uint *puVar5;
  uint uVar6;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar2 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  uVar6 = 0;
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar4 = 0;
    puVar5 = extraout_EDX;
    do {
      fVar1 = *(float *)(iVar2 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar6 & 3) * 4);
      pfVar3 = (float *)(arg3 + iVar4);
      *puVar5 = (int)ROUND(*(float *)(iVar4 + 0xc + arg3) * 65535.0 + fVar1) << 0x10 |
                (int)ROUND((*pfVar3 * 0.2125 + pfVar3[1] * 0.7154 + pfVar3[2] * 0.0721) * 65535.0 +
                           fVar1);
      puVar5 = puVar5 + 1;
      uVar6 = uVar6 + 1;
      iVar4 = iVar4 + 0x10;
    } while (uVar6 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



