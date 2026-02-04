/* FUN_10018990 @ 10018990 */

/* [binja] int16_t __thiscall sub_10018990(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10018990(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint *extraout_EDX;
  uint *puVar4;
  uint local_c;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar2 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  local_c = 0;
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar3 = 0;
    puVar4 = extraout_EDX;
    do {
      fVar1 = *(float *)(iVar2 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (local_c & 3) * 4);
      *puVar4 = (((int)ROUND(*(float *)(iVar3 + 8 + arg3) * 128.0 + fVar1) & 0xffU |
                 (int)ROUND(*(float *)(iVar3 + 0xc + arg3) * 128.0 + fVar1) << 8) << 8 |
                (int)ROUND(*(float *)(iVar3 + 4 + arg3) * 128.0 + fVar1) & 0xffU) << 8 |
                (int)ROUND(*(float *)(iVar3 + arg3) * 128.0 + fVar1) & 0xffU;
      puVar4 = puVar4 + 1;
      local_c = local_c + 1;
      iVar3 = iVar3 + 0x10;
    } while (local_c < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



