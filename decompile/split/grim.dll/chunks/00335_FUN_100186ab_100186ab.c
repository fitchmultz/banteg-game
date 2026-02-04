/* FUN_100186ab @ 100186ab */

/* [binja] int16_t __thiscall sub_100186ab(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_100186ab(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  undefined2 *extraout_EDX;
  undefined2 *puVar6;
  int iVar7;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar4 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  uVar5 = 0;
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar7 = 0;
    puVar6 = extraout_EDX;
    do {
      fVar3 = *(float *)(iVar4 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar5 & 3) * 4);
      pfVar1 = (float *)(iVar7 + arg3);
      iVar2 = iVar7 + 4;
      iVar7 = iVar7 + 0x10;
      *puVar6 = CONCAT11((char)(int)ROUND(*(float *)(iVar2 + arg3) * 128.0 + fVar3),
                         (char)(int)ROUND(*pfVar1 * 128.0 + fVar3));
      puVar6 = puVar6 + 1;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



