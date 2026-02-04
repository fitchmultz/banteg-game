/* FUN_1001a0eb @ 1001a0eb */

/* WARNING: Removing unreachable block (ram,0x1001a185) */
/* [binja] int32_t* __thiscall sub_1001a0eb(void* arg1, uint32_t arg2, int32_t arg3, int32_t arg4)
    */

int * __thiscall FUN_1001a0eb(void *this,void *arg1,uint arg2,int arg3,int arg4)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *extraout_EAX;
  
  puVar3 = (uint *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  puVar1 = puVar3 + *(int *)((int)this + 0x1058);
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    uVar2 = *puVar3;
    *(float *)arg3 = (float)(int)((short)((short)*puVar3 << 6) >> 6) * 0.001953125;
    *(float *)(arg3 + 4) = (float)(int)((short)((short)(uVar2 >> 10) << 6) >> 6) * 0.001953125;
    *(float *)(arg3 + 8) = (float)(int)((short)((ushort)(uVar2 >> 0x14) << 6) >> 6) * 0.001953125;
    *(float *)(arg3 + 0xc) = (float)(*puVar3 >> 0x1e) * 0.33333334;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar3 = extraout_EAX;
  }
  return (int *)puVar3;
}



