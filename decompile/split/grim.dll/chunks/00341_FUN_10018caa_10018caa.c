/* FUN_10018caa @ 10018caa */

/* [binja] int16_t __thiscall sub_10018caa(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10018caa(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint *extraout_EDX;
  uint *puVar5;
  uint local_c;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar3 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  local_c = 0;
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar4 = 0;
    puVar5 = extraout_EDX;
    do {
      fVar1 = *(float *)(iVar3 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (local_c & 3) * 4);
      fVar2 = *(float *)(iVar4 + 0xc + arg3);
      *puVar5 = (((int)ROUND(*(float *)(iVar4 + 8 + arg3) * 512.0 + fVar1) & 0x3ffU |
                 (int)ROUND(fVar2 + fVar2 + fVar1) << 10) << 10 |
                (int)ROUND(*(float *)(iVar4 + 4 + arg3) * 512.0 + fVar1) & 0x3ffU) << 10 |
                (int)ROUND(*(float *)(iVar4 + arg3) * 512.0 + fVar1) & 0x3ffU;
      puVar5 = puVar5 + 1;
      local_c = local_c + 1;
      iVar4 = iVar4 + 0x10;
    } while (local_c < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



