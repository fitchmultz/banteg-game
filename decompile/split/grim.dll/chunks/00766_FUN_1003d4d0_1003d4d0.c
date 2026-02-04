/* FUN_1003d4d0 @ 1003d4d0 */

int __cdecl FUN_1003d4d0(int *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = (uint)(0xffe0 / (ulonglong)(uint)(param_3 * 0x80));
  iVar2 = param_1[1];
  if (uVar1 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x45;
    (**(code **)*param_1)(param_1);
  }
  if ((int)param_4 <= (int)uVar1) {
    uVar1 = param_4;
  }
  *(uint *)(iVar2 + 0x4c) = uVar1;
  iVar2 = FUN_1003d210(param_1,param_2,param_4 * 4);
  uVar6 = 0;
  if (param_4 != 0) {
    do {
      if (param_4 - uVar6 <= uVar1) {
        uVar1 = param_4 - uVar6;
      }
      puVar3 = FUN_1003d360(param_1,param_2,uVar1 * param_3 * 0x80);
      if (uVar1 != 0) {
        puVar4 = (undefined4 *)(iVar2 + uVar6 * 4);
        uVar6 = uVar6 + uVar1;
        uVar5 = uVar1;
        do {
          *puVar4 = puVar3;
          puVar4 = puVar4 + 1;
          puVar3 = puVar3 + param_3 * 0x20;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    } while (uVar6 < param_4);
  }
  return iVar2;
}



