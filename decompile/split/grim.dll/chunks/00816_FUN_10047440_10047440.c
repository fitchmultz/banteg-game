/* FUN_10047440 @ 10047440 */

undefined4 __cdecl FUN_10047440(int param_1,int param_2,char *param_3,int param_4)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (((param_3 == (char *)0x0) || (*param_3 != s_1_1_3_1005820c[0])) || (param_4 != 0x38)) {
    return 0xfffffffa;
  }
  if (param_1 == 0) {
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (*(int *)(param_1 + 0x20) == 0) {
    *(code **)(param_1 + 0x20) = FUN_10047a00;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    *(code **)(param_1 + 0x24) = FUN_10047a20;
  }
  iVar3 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x18);
  *(int *)(param_1 + 0x1c) = iVar3;
  if (iVar3 == 0) {
    return 0xfffffffc;
  }
  *(undefined4 *)(iVar3 + 0x14) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 0;
  if (param_2 < 0) {
    param_2 = -param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 1;
  }
  if ((7 < param_2) && (param_2 < 0x10)) {
    *(int *)(*(int *)(param_1 + 0x1c) + 0x10) = param_2;
    puVar4 = FUN_10049340(param_1,(undefined *)
                                  (~-(uint)(*(int *)(*(int *)(param_1 + 0x1c) + 0xc) != 0) &
                                  0x10049190),1 << ((byte)param_2 & 0x1f));
    *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x14) = puVar4;
    puVar1 = *(uint **)(param_1 + 0x1c);
    if (puVar1[5] == 0) {
      if ((puVar1 != (uint *)0x0) && (*(code **)(param_1 + 0x24) != (code *)0x0)) {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),puVar1);
        *(undefined4 *)(param_1 + 0x1c) = 0;
      }
      return 0xfffffffc;
    }
    if (puVar1 != (uint *)0x0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *puVar1 = -(uint)(puVar1[3] != 0) & 7;
      FUN_100492c0(*(int **)(*(int *)(param_1 + 0x1c) + 0x14),param_1,(int *)0x0);
    }
    return 0;
  }
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 0x24) != 0)) {
    piVar2 = *(int **)(*(int *)(param_1 + 0x1c) + 0x14);
    if (piVar2 != (int *)0x0) {
      FUN_1004a100(piVar2,param_1);
    }
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return 0xfffffffe;
}



