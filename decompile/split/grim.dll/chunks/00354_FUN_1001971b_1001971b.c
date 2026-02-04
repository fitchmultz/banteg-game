/* FUN_1001971b @ 1001971b */

/* WARNING: Removing unreachable block (ram,0x10019782) */
/* WARNING: Removing unreachable block (ram,0x10019767) */
/* WARNING: Removing unreachable block (ram,0x1001979e) */
/* WARNING: Removing unreachable block (ram,0x100197b8) */
/* [binja] int32_t* __thiscall sub_1001971b(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

int * __thiscall FUN_1001971b(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  uint *puVar1;
  uint *puVar2;
  uint *extraout_EAX;
  
  puVar2 = (uint *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  puVar1 = puVar2 + *(int *)((int)this + 0x1058);
  for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
    *(float *)arg3 = (float)(*puVar2 & 0x3ff) * 0.0009775171;
    *(float *)(arg3 + 4) = (float)(*puVar2 >> 10 & 0x3ff) * 0.0009775171;
    *(float *)(arg3 + 8) = (float)(*puVar2 >> 0x14 & 0x3ff) * 0.0009775171;
    *(float *)(arg3 + 0xc) = (float)(*puVar2 >> 0x1e) * 0.33333334;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar2 = extraout_EAX;
  }
  return (int *)puVar2;
}



