/* FUN_10019ae8 @ 10019ae8 */

/* [binja] char* __thiscall sub_10019ae8(void* arg1, void* arg2, int32_t arg3, uint32_t arg4) */

char * __thiscall FUN_10019ae8(void *this,void *arg1,void *arg2,int arg3,uint arg4)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *extraout_EAX;
  undefined4 *puVar3;
  
  pbVar2 = (byte *)(*(int *)((int)this + 0x1050) * (int)arg1 +
                    *(int *)((int)this + 0x1054) * (int)arg2 + *(int *)((int)this + 0x18));
  pbVar1 = pbVar2 + *(int *)((int)this + 0x1058) * 2;
  for (; pbVar2 < pbVar1; pbVar2 = pbVar2 + 2) {
    puVar3 = (undefined4 *)((*pbVar2 + 3) * 0x10 + (int)this);
    *(undefined4 *)arg3 = *puVar3;
    *(undefined4 *)(arg3 + 4) = puVar3[1];
    *(undefined4 *)(arg3 + 8) = puVar3[2];
    *(undefined4 *)(arg3 + 0xc) = puVar3[3];
    *(float *)(arg3 + 0xc) = (float)pbVar2[1] * 0.003921569;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    pbVar2 = extraout_EAX;
  }
  return (char *)pbVar2;
}



