/* FUN_10017d68 @ 10017d68 */

/* [binja] int16_t __thiscall sub_10017d68(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10017d68(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  int iVar1;
  uint uVar2;
  undefined1 *extraout_EDX;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar1 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  uVar2 = 0;
  puVar3 = extraout_EDX;
  if (*(int *)((int)this + 0x1058) != 0) {
    do {
      *puVar3 = (char)(int)ROUND(*(float *)(iVar4 + 0xc + arg3) * 255.0 +
                                 *(float *)(iVar1 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 +
                                           (uVar2 & 3) * 4));
      puVar3 = puVar3 + 1;
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 0x10;
    } while (uVar2 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



