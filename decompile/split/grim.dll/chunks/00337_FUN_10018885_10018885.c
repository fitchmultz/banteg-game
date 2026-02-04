/* FUN_10018885 @ 10018885 */

/* [binja] int16_t __thiscall sub_10018885(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_10018885(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  uint *extraout_EDX;
  uint *puVar7;
  int iVar8;
  undefined1 local_24;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar5 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  uVar6 = 0;
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar8 = 0;
    puVar7 = extraout_EDX;
    do {
      fVar4 = *(float *)(iVar5 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar6 & 3) * 4);
      pfVar1 = (float *)(iVar8 + arg3);
      iVar2 = iVar8 + 4;
      iVar3 = iVar8 + 0xc;
      iVar8 = iVar8 + 0x10;
      local_24 = (undefined1)(int)ROUND(*(float *)(iVar2 + arg3) * 128.0 + fVar4);
      *puVar7 = (uint)CONCAT11((char)(int)ROUND(*(float *)(iVar3 + arg3) * 255.0 + fVar4),local_24)
                << 8 | (int)ROUND(*pfVar1 * 128.0 + fVar4) & 0xffU;
      puVar7 = puVar7 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



