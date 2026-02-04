/* FUN_10018aca @ 10018aca */

/* [binja] int16_t __thiscall sub_10018aca(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10018aca(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float fVar1;
  int iVar2;
  uint *extraout_EDX;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar2 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar5 = 0;
    puVar3 = extraout_EDX;
    do {
      fVar1 = *(float *)(iVar2 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar4 & 3) * 4);
      *puVar3 = (int)ROUND(*(float *)(iVar5 + 4 + arg3) * 32768.0 + fVar1) << 0x10 |
                (int)ROUND(*(float *)(iVar5 + arg3) * 32768.0 + fVar1) & 0xffffU;
      puVar3 = puVar3 + 1;
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 0x10;
    } while (uVar4 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



