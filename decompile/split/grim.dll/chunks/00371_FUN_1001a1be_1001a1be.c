/* FUN_1001a1be @ 1001a1be */

/* [binja] int16_t* __thiscall sub_1001a1be(void* arg1, int32_t arg2, int32_t arg3, uint32_t arg4)
    */

short * __thiscall FUN_1001a1be(void *this,void *arg1,int arg2,int arg3,uint arg4)

{
  ushort *puVar1;
  float fVar2;
  ushort *puVar3;
  ushort *extraout_EAX;
  
  puVar3 = (ushort *)
           (*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * arg2 +
           *(int *)((int)this + 0x18));
  puVar1 = puVar3 + *(int *)((int)this + 0x1058);
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    fVar2 = (float)*puVar3 * 1.5259022e-05;
    *(float *)(arg3 + 8) = fVar2;
    *(float *)(arg3 + 4) = fVar2;
    *(float *)arg3 = fVar2;
    *(float *)(arg3 + 0xc) = 1.0;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar3 = extraout_EAX;
  }
  return (short *)puVar3;
}



