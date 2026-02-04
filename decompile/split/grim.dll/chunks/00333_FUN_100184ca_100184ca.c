/* FUN_100184ca @ 100184ca */

/* [binja] int16_t __thiscall sub_100184ca(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_100184ca(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  int iVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  ushort *extraout_EDX;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar3 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar6 = 0;
    puVar5 = extraout_EDX;
    do {
      fVar2 = *(float *)(iVar3 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (uVar7 & 3) * 4);
      pfVar4 = (float *)(arg3 + iVar6);
      iVar1 = iVar6 + 0xc;
      iVar6 = iVar6 + 0x10;
      *puVar5 = (ushort)(((int)ROUND(*(float *)(iVar1 + arg3) * 255.0 + fVar2) & 0xffU) << 8) |
                (ushort)(int)ROUND((*pfVar4 * 0.2125 + pfVar4[1] * 0.7154 + pfVar4[2] * 0.0721) *
                                   255.0 + fVar2);
      puVar5 = puVar5 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



