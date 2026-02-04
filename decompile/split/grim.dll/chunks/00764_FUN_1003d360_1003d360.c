/* FUN_1003d360 @ 1003d360 */

undefined4 * __cdecl FUN_1003d360(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = param_1[1];
  if (0xffe0 < param_3) {
    *(undefined4 *)(*param_1 + 0x14) = 0x35;
    *(undefined4 *)(*param_1 + 0x18) = 3;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 & 7) != 0) {
    param_3 = param_3 + (8 - (param_3 & 7));
  }
  if ((param_2 < 0) || (1 < param_2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0xc;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  puVar3 = operator_new(param_3 + 0x10);
  if (puVar3 == (undefined4 *)0x0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x35;
    *(undefined4 *)(*param_1 + 0x18) = 4;
    (**(code **)*param_1)(param_1);
  }
  *(uint *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) + param_3 + 0x10;
  uVar2 = *(undefined4 *)(iVar1 + 0x38 + param_2 * 4);
  puVar3[1] = param_3;
  *puVar3 = uVar2;
  puVar3[2] = 0;
  *(undefined4 **)(iVar1 + 0x38 + param_2 * 4) = puVar3;
  return puVar3 + 4;
}



