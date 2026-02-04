/* FUN_10019dd5 @ 10019dd5 */

/* [binja] char* __thiscall sub_10019dd5(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

char * __thiscall FUN_10019dd5(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  ushort *puVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort *extraout_EAX;
  
  puVar3 = (ushort *)
           (*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
           *(int *)((int)this + 0x18));
  puVar1 = puVar3 + *(int *)((int)this + 0x1058);
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    uVar2 = *puVar3;
    *(float *)arg3 = (float)(int)((char)((char)*puVar3 << 3) >> 3) * 0.0625;
    *(float *)(arg3 + 4) = (float)(int)((char)((char)(uVar2 >> 5) << 3) >> 3) * 0.0625;
    *(float *)(arg3 + 8) = 0.0;
    *(float *)(arg3 + 0xc) = (float)(*puVar3 >> 10) * 0.015873017;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar3 = extraout_EAX;
  }
  return (char *)puVar3;
}



