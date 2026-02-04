/* FUN_10019f17 @ 10019f17 */

/* [binja] char* __thiscall sub_10019f17(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

char * __thiscall FUN_10019f17(void *this,void *arg1,int arg2,int arg3,int arg4)

{
  char *pcVar1;
  char *pcVar2;
  char *extraout_EAX;
  
  pcVar2 = (char *)(*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  pcVar1 = pcVar2 + *(int *)((int)this + 0x1058) * 4;
  for (; pcVar2 < pcVar1; pcVar2 = pcVar2 + 4) {
    *(float *)arg3 = (float)(int)*pcVar2 * 0.0078125;
    *(float *)(arg3 + 4) = (float)(int)pcVar2[1] * 0.0078125;
    *(float *)(arg3 + 8) = (float)(int)pcVar2[2] * 0.0078125;
    *(float *)(arg3 + 0xc) = (float)(int)pcVar2[3] * 0.0078125;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    pcVar2 = extraout_EAX;
  }
  return pcVar2;
}



