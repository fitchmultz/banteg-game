/* FUN_100324f2 @ 100324f2 */

/* [binja] int16_t* sub_100324f2(int16_t* arg1, int16_t* arg2, int32_t arg3) */

short * __cdecl FUN_100324f2(short *arg1,short *arg2,int arg3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int in_stack_00000010;
  
  iVar2 = *(int *)(arg1 + 0x2e);
  iVar3 = *(int *)(*(int *)(arg1 + 0xd2) + 0x18);
  iVar5 = 0;
  if (0 < in_stack_00000010) {
    do {
      pbVar4 = *(byte **)(arg2 + iVar5 * 2);
      arg1 = arg2;
      for (iVar1 = iVar2; iVar1 != 0; iVar1 = iVar1 + -1) {
        arg1 = (short *)(*(int *)(iVar3 + (uint)(*pbVar4 >> 3) * 4) +
                        ((uint)(pbVar4[1] >> 2) * 0x20 + (uint)(pbVar4[2] >> 3)) * 2);
        *arg1 = *arg1 + 1;
        if (*arg1 == 0) {
          *arg1 = -1;
        }
        pbVar4 = pbVar4 + 3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < in_stack_00000010);
  }
  return arg1;
}



