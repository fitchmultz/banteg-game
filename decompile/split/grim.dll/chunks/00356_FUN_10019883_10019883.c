/* FUN_10019883 @ 10019883 */

/* [binja] char* __thiscall sub_10019883(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

char * __thiscall FUN_10019883(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  byte *pbVar1;
  byte *extraout_EAX;
  byte *pbVar2;
  
  pbVar1 = (byte *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  pbVar2 = pbVar1 + *(int *)((int)this + 0x1058);
  for (; pbVar1 < pbVar2; pbVar1 = pbVar1 + 1) {
    *(float *)arg3 = (float)(*pbVar1 >> 5) * 0.14285715;
    *(float *)(arg3 + 4) = (float)(*pbVar1 >> 2 & 7) * 0.14285715;
    *(float *)(arg3 + 8) = (float)(*pbVar1 & 3) * 0.33333334;
    *(float *)(arg3 + 0xc) = 1.0;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    pbVar1 = extraout_EAX;
  }
  return (char *)pbVar1;
}



