/* FUN_10019925 @ 10019925 */

/* [binja] char* __thiscall sub_10019925(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

char * __thiscall FUN_10019925(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  byte *pbVar1;
  byte *extraout_EAX;
  byte *pbVar2;
  
  pbVar1 = (byte *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  pbVar2 = pbVar1 + *(int *)((int)this + 0x1058);
  for (; pbVar1 < pbVar2; pbVar1 = pbVar1 + 1) {
    *(undefined4 *)arg3 = 0;
    *(undefined4 *)(arg3 + 4) = 0;
    *(undefined4 *)(arg3 + 8) = 0;
    *(float *)(arg3 + 0xc) = (float)*pbVar1 * 0.003921569;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    pbVar1 = extraout_EAX;
  }
  return (char *)pbVar1;
}



