/* FUN_10018405 @ 10018405 */

/* [binja] int16_t __thiscall sub_10018405(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10018405(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  undefined1 *extraout_EDX;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar1 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  uVar3 = 0;
  puVar4 = extraout_EDX;
  if (*(int *)((int)this + 0x1058) != 0) {
    do {
      pfVar2 = (float *)(arg3 + iVar5);
      *puVar4 = (char)(int)ROUND(*(float *)(iVar1 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 +
                                           (uVar3 & 3) * 4) +
                                 (*pfVar2 * 0.2125 + pfVar2[1] * 0.7154 + pfVar2[2] * 0.0721) *
                                 255.0);
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 1;
      iVar5 = iVar5 + 0x10;
    } while (uVar3 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



