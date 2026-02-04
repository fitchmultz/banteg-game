/* FUN_1001a348 @ 1001a348 */

/* WARNING: Removing unreachable block (ram,0x1001a3c7) */
/* WARNING: Removing unreachable block (ram,0x1001a3a5) */
/* WARNING: Removing unreachable block (ram,0x1001a3e0) */
/* [binja] uint32_t __thiscall sub_1001a348(uint32_t arg1, uint32_t arg2, int32_t arg3, uint32_t
   arg4) */

uint __thiscall FUN_1001a348(void *this,uint arg1,uint arg2,int arg3,uint arg4)

{
  uint *puVar1;
  uint *puVar2;
  uint *extraout_EAX;
  uint *puVar3;
  ulonglong uVar4;
  
  puVar3 = (uint *)(*(int *)((int)this + 0x1050) * arg1 + *(int *)((int)this + 0x1054) * arg2 +
                   *(int *)((int)this + 0x18));
  puVar1 = puVar3 + *(int *)((int)this + 0x1058) * 2;
  puVar2 = puVar1;
  for (; puVar3 < puVar1; puVar3 = puVar3 + 2) {
    uVar4 = __aullshr(0x20,puVar3[1]);
    *(float *)arg3 = (float)((uint)uVar4 & 0xffff) * 1.5259022e-05;
    *(float *)(arg3 + 4) = (float)(*puVar3 >> 0x10) * 1.5259022e-05;
    *(float *)(arg3 + 8) = (float)(*puVar3 & 0xffff) * 1.5259022e-05;
    puVar2 = (uint *)(uint)*(ushort *)((int)puVar3 + 6);
    *(float *)(arg3 + 0xc) = (float)(int)puVar2 * 1.5259022e-05;
    arg3 = (int)(arg3 + 0x10);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    grim_apply_color_key(this,(float *)(arg3 + *(int *)((int)this + 0x1058) * -4 * 4));
    puVar2 = extraout_EAX;
  }
  return (uint)puVar2;
}



