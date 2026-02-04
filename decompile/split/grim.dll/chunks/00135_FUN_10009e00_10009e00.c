/* FUN_10009e00 @ 10009e00 */

undefined4 __cdecl FUN_10009e00(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = param_1[4];
  if (((iVar3 == 0xcd) || (iVar3 == 0xce)) && ((char)param_1[0x10] == '\0')) {
    if ((uint)param_1[0x1e] < (uint)param_1[0x18]) {
      *(undefined4 *)(*param_1 + 0x14) = 0x42;
      (**(code **)*param_1)(param_1);
    }
    (**(code **)(param_1[0x5f] + 4))(param_1);
    param_1[4] = 0xd2;
  }
  else if (iVar3 == 0xcf) {
    param_1[4] = 0xd2;
  }
  else if (iVar3 != 0xd2) {
    *(undefined4 *)(*param_1 + 0x14) = 0x12;
    *(int *)(*param_1 + 0x18) = param_1[4];
    (**(code **)*param_1)(param_1);
  }
  puVar2 = (undefined4 *)param_1[99];
  cVar1 = *(char *)((int)puVar2 + 0x11);
  while( true ) {
    if (cVar1 != '\0') {
      (**(code **)(param_1[5] + 0x18))(param_1);
      uVar4 = FUN_1003dd00((int)param_1);
      return CONCAT31((int3)((uint)uVar4 >> 8),1);
    }
    iVar3 = (*(code *)*puVar2)(param_1);
    if (iVar3 == 0) break;
    puVar2 = (undefined4 *)param_1[99];
    cVar1 = *(char *)((int)puVar2 + 0x11);
  }
  return 0;
}



