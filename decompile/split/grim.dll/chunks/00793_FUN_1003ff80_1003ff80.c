/* FUN_1003ff80 @ 1003ff80 */

uint __cdecl FUN_1003ff80(undefined4 *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if (param_3 < param_5) {
    uVar1 = FUN_1003fe80(param_1,param_2,param_3,param_5);
    if ((char)uVar1 == '\0') {
      return 0xffffffff;
    }
    param_2 = param_1[3];
    param_3 = param_1[4];
  }
  iVar2 = param_3 - param_5;
  piVar4 = (int *)(param_4 + 0x44 + param_5 * 4);
  uVar3 = (int)param_2 >> ((byte)iVar2 & 0x1f) & (1 << ((byte)param_5 & 0x1f)) - 1U;
  if (*piVar4 < (int)uVar3) {
    do {
      if (iVar2 < 1) {
        uVar1 = FUN_1003fe80(param_1,param_2,iVar2,1);
        if ((char)uVar1 == '\0') {
          return 0xffffffff;
        }
        param_2 = param_1[3];
        iVar2 = param_1[4];
      }
      iVar2 = iVar2 + -1;
      piVar4 = piVar4 + 1;
      uVar3 = uVar3 << 1 | (int)param_2 >> ((byte)iVar2 & 0x1f) & 1U;
      param_5 = param_5 + 1;
    } while (*piVar4 < (int)uVar3);
  }
  param_1[4] = iVar2;
  param_1[3] = param_2;
  if (0x10 < param_5) {
    *(undefined4 *)(*(int *)param_1[5] + 0x14) = 0x72;
    (**(code **)(*(int *)param_1[5] + 4))((int *)param_1[5],0xffffffff);
    return 0;
  }
  return (uint)*(byte *)((*(int *)(param_4 + 0x8c + param_5 * 4) - *(int *)(param_4 + param_5 * 4))
                         + *(int *)(param_4 + 0xd0) + 0x11 + uVar3);
}



