/* FUN_1001a2bc @ 1001a2bc */

/* [binja] void* __thiscall sub_1001a2bc(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

void * __thiscall FUN_1001a2bc(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  ushort *puVar1;
  ushort *extraout_EAX;
  ushort *puVar2;
  
  puVar1 = (ushort *)
           (*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
           *(int *)((int)this + 0x18));
  puVar2 = (ushort *)(*(int *)((int)this + 0x1064) + (int)puVar1);
  for (; puVar1 < puVar2; puVar1 = puVar1 + 3) {
    *(float *)arg3 = (float)puVar1[2] * 1.5259022e-05;
    *(float *)(arg3 + 4) = (float)puVar1[1] * 1.5259022e-05;
    *(float *)(arg3 + 8) = (float)*puVar1 * 1.5259022e-05;
    *(float *)(arg3 + 0xc) = 1.0;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



