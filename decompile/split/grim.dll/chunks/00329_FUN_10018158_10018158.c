/* FUN_10018158 @ 10018158 */

/* [binja] int16_t __thiscall sub_10018158(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10018158(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint *extraout_EDX;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar2 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar3 = 0;
    puVar4 = extraout_EDX;
    do {
      fVar1 = *(float *)(iVar2 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar5 & 3) * 4);
      *puVar4 = (int)ROUND(*(float *)(iVar3 + 4 + arg3) * 65535.0 + fVar1) << 0x10 |
                (int)ROUND(*(float *)(iVar3 + arg3) * 65535.0 + fVar1);
      puVar4 = puVar4 + 1;
      uVar5 = uVar5 + 1;
      iVar3 = iVar3 + 0x10;
    } while (uVar5 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



