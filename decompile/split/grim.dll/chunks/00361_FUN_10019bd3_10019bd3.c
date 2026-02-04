/* FUN_10019bd3 @ 10019bd3 */

/* [binja] char* __thiscall sub_10019bd3(void* arg1, int32_t arg2, int32_t arg3, uint32_t arg4) */

char * __thiscall FUN_10019bd3(void *this,void *arg1,int arg2,int arg3,uint arg4)

{
  float fVar1;
  byte *pbVar2;
  byte *extraout_EAX;
  byte *pbVar3;
  
  pbVar2 = (byte *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  pbVar3 = pbVar2 + *(int *)((int)this + 0x1058);
  for (; pbVar2 < pbVar3; pbVar2 = pbVar2 + 1) {
    fVar1 = (float)*pbVar2 * 0.003921569;
    *(float *)(arg3 + 8) = fVar1;
    *(float *)(arg3 + 4) = fVar1;
    *(float *)arg3 = fVar1;
    *(float *)(arg3 + 0xc) = 1.0;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    pbVar2 = extraout_EAX;
  }
  return (char *)pbVar2;
}



