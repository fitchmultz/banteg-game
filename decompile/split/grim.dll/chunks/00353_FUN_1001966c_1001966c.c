/* FUN_1001966c @ 1001966c */

/* [binja] void* __thiscall sub_1001966c(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

void * __thiscall FUN_1001966c(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *extraout_EAX;
  
  puVar2 = (ushort *)
           (*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
           *(int *)((int)this + 0x18));
  puVar1 = puVar2 + *(int *)((int)this + 0x1058);
  for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
    *(float *)arg3 = (float)(*(byte *)((int)puVar2 + 1) & 0xf) * 0.06666667;
    *(float *)(arg3 + 4) = (float)(byte)((byte)*puVar2 >> 4) * 0.06666667;
    *(float *)(arg3 + 8) = (float)((byte)*puVar2 & 0xf) * 0.06666667;
    *(float *)(arg3 + 0xc) = (float)(*puVar2 >> 0xc) * 0.06666667;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar2 = extraout_EAX;
  }
  return puVar2;
}



