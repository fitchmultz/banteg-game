/* FUN_10049340 @ 10049340 */

undefined4 * __cdecl FUN_10049340(int param_1,undefined *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x40);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),8,0x5a0);
  puVar1[9] = iVar2;
  if (iVar2 == 0) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),puVar1);
    return (undefined4 *)0x0;
  }
  iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,param_3);
  puVar1[10] = iVar2;
  if (iVar2 == 0) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),puVar1[9]);
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),puVar1);
    return (undefined4 *)0x0;
  }
  *puVar1 = 0;
  puVar1[0xb] = iVar2 + param_3;
  puVar1[0xe] = param_2;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[0xd] = iVar2;
  puVar1[0xc] = iVar2;
  if (param_2 != (undefined *)0x0) {
    uVar3 = (*(code *)param_2)(0,0,0);
    puVar1[0xf] = uVar3;
    *(undefined4 *)(param_1 + 0x30) = uVar3;
  }
  return puVar1;
}



