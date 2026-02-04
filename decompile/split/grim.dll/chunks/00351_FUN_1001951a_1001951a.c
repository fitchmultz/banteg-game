/* FUN_1001951a @ 1001951a */

/* [binja] int16_t* __thiscall sub_1001951a(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

short * __thiscall FUN_1001951a(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *extraout_EAX;
  
  puVar2 = (ushort *)
           (*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
           *(int *)((int)this + 0x18));
  puVar1 = puVar2 + *(int *)((int)this + 0x1058);
  for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
    *(float *)arg3 = (float)((*puVar2 & 0x7c00) >> 10) * 0.032258064;
    *(float *)(arg3 + 4) = (float)((*puVar2 & 0x3e0) >> 5) * 0.032258064;
    *(float *)(arg3 + 8) = (float)((byte)*puVar2 & 0x1f) * 0.032258064;
    *(float *)(arg3 + 0xc) = 1.0;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar2 = extraout_EAX;
  }
  return (short *)puVar2;
}



