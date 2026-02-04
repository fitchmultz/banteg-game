/* FUN_1001914b @ 1001914b */

/* [binja] int16_t __thiscall sub_1001914b(void* arg1, int32_t arg2, int32_t arg3, void* arg4) */

short __thiscall FUN_1001914b(void *this,void *arg1,int arg2,int arg3,void *arg4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint local_c;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (int)grim_convert_vertex_space(this,(float *)arg3);
  }
  puVar8 = (uint *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  iVar6 = *(int *)((int)this + 0x2c);
  fpu_set_round_trunc();
  local_c = 0;
  if (*(int *)((int)this + 0x1058) != 0) {
    iVar7 = 0;
    do {
      fVar4 = *(float *)(iVar6 + ((arg2 & 3U) + ((uint)arg1 & 3) * 8) * 4 + (local_c & 3) * 4);
      uVar1 = (uint)ROUND(*(float *)(iVar7 + arg3) * 65535.0 + fVar4);
      uVar2 = (uint)ROUND(*(float *)(iVar7 + 4 + arg3) * 65535.0 + fVar4);
      uVar3 = (uint)ROUND(*(float *)(iVar7 + 8 + arg3) * 65535.0 + fVar4);
      fVar5 = *(float *)(iVar7 + 0xc + arg3);
      *puVar8 = uVar2 << 0x10 | uVar3;
      puVar8[1] = (((int)ROUND(fVar5 * 65535.0 + fVar4) << 0x10 | uVar1) >> 0x10 |
                  (int)uVar2 >> 0x1f) << 0x10 | (uVar1 << 0x10 | uVar2) >> 0x10 | (int)uVar3 >> 0x1f
      ;
      puVar8 = puVar8 + 2;
      local_c = local_c + 1;
      iVar7 = iVar7 + 0x10;
    } while (local_c < *(uint *)((int)this + 0x1058));
  }
  return (short)DAT_1005db6c;
}



