/* FUN_100197f1 @ 100197f1 */

/* WARNING: Removing unreachable block (ram,0x10019837) */
/* [binja] int32_t* __thiscall sub_100197f1(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

int * __thiscall FUN_100197f1(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  uint *puVar1;
  uint *puVar2;
  uint *extraout_EAX;
  
  puVar2 = (uint *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  puVar1 = puVar2 + *(int *)((int)this + 0x1058);
  for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
    *(float *)arg3 = (float)(*puVar2 & 0xffff) * 1.5259022e-05;
    *(float *)(arg3 + 4) = (float)*(ushort *)((int)puVar2 + 2) * 1.5259022e-05;
    *(float *)(arg3 + 8) = 1.0;
    *(float *)(arg3 + 0xc) = 1.0;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar2 = extraout_EAX;
  }
  return (int *)puVar2;
}



