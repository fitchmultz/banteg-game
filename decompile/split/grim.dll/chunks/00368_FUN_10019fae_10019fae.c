/* FUN_10019fae @ 10019fae */

/* [binja] int16_t* __thiscall sub_10019fae(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

short * __thiscall FUN_10019fae(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  short *psVar1;
  short *psVar2;
  short *extraout_EAX;
  
  psVar2 = (short *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2
                    + *(int *)((int)this + 0x18));
  psVar1 = psVar2 + *(int *)((int)this + 0x1058) * 2;
  for (; psVar2 < psVar1; psVar2 = psVar2 + 2) {
    *(float *)arg3 = (float)(int)*psVar2 * 3.0517578e-05;
    *(float *)(arg3 + 4) = (float)(int)psVar2[1] * 3.0517578e-05;
    *(float *)(arg3 + 8) = 0.0;
    *(float *)(arg3 + 0xc) = 1.0;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    psVar2 = extraout_EAX;
  }
  return psVar2;
}



