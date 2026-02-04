/* FUN_10019c41 @ 10019c41 */

/* [binja] char* __thiscall sub_10019c41(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

char * __thiscall FUN_10019c41(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  byte *pbVar1;
  float fVar2;
  byte *pbVar3;
  byte *extraout_EAX;
  
  pbVar3 = (byte *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  pbVar1 = pbVar3 + *(int *)((int)this + 0x1058) * 2;
  for (; pbVar3 < pbVar1; pbVar3 = pbVar3 + 2) {
    fVar2 = (float)*pbVar3 * 0.003921569;
    *(float *)(arg3 + 8) = fVar2;
    *(float *)(arg3 + 4) = fVar2;
    *(float *)arg3 = fVar2;
    *(float *)(arg3 + 0xc) = (float)pbVar3[1] * 0.003921569;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    pbVar3 = extraout_EAX;
  }
  return (char *)pbVar3;
}



