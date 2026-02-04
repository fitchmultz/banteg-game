/* FUN_10018228 @ 10018228 */

/* [binja] int16_t __thiscall sub_10018228(void* arg1, int32_t arg2, int32_t arg3, float* arg4) */

short __thiscall FUN_10018228(void *this,void *arg1,int arg2,int arg3,float *arg4)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  ushort *extraout_EDX;
  ushort *puVar6;
  uint uVar7;
  uint local_14;
  int local_10;
  uint local_c;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  iVar2 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  uVar7 = 0;
  if (*(int *)((int)this + 0x1058) != 0) {
    local_10 = 0;
    puVar6 = extraout_EDX;
    do {
      local_14 = 0;
      local_c = 0;
      pfVar5 = (float *)((int)this + 0x38);
      do {
        fVar4 = *(float *)(arg3 + 4) - pfVar5[-1];
        fVar3 = *(float *)(arg3 + 8) - *pfVar5;
        if ((*(float *)arg3 - pfVar5[-2]) * (*(float *)arg3 - pfVar5[-2]) +
            fVar4 * fVar4 + fVar3 * fVar3 < 3.4028235e+38) {
          local_14 = local_c;
        }
        local_c = local_c + 1;
        pfVar5 = pfVar5 + 4;
      } while (local_c < 0x100);
      iVar1 = local_10 + 0xc;
      local_10 = local_10 + 0x10;
      *puVar6 = (ushort)(byte)(int)ROUND(*(float *)(iVar1 + arg3) * 255.0 +
                                         *(float *)(iVar2 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4
                                                   + (uVar7 & 3) * 4)) << 8 | (ushort)local_14;
      puVar6 = puVar6 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



