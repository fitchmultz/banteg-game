/* FUN_1001a22e @ 1001a22e */

/* WARNING: Removing unreachable block (ram,0x1001a274) */
/* [binja] int32_t* __thiscall sub_1001a22e(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

int * __thiscall FUN_1001a22e(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  uint *puVar1;
  float fVar2;
  uint *puVar3;
  uint *extraout_EAX;
  
  puVar3 = (uint *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  puVar1 = puVar3 + *(int *)((int)this + 0x1058);
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    fVar2 = (float)(*puVar3 & 0xffff) * 1.5259022e-05;
    *(float *)(arg3 + 8) = fVar2;
    *(float *)(arg3 + 4) = fVar2;
    *(float *)arg3 = fVar2;
    *(float *)(arg3 + 0xc) = (float)*(ushort *)((int)puVar3 + 2) * 1.5259022e-05;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar3 = extraout_EAX;
  }
  return (int *)puVar3;
}



