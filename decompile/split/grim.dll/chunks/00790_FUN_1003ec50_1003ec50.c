/* FUN_1003ec50 @ 1003ec50 */

void __cdecl FUN_1003ec50(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  
  puVar2 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x74);
  *(undefined4 **)(param_1 + 0x184) = puVar2;
  *puVar2 = &LAB_1003ed60;
  puVar2[2] = &LAB_1003edc0;
  puVar2[0x1c] = 0;
  if (param_2 == '\0') {
    iVar3 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,0x500);
    piVar8 = puVar2 + 8;
    iVar6 = 10;
    do {
      *piVar8 = iVar3;
      piVar8 = piVar8 + 1;
      iVar3 = iVar3 + 0x80;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    puVar2[4] = 0;
    puVar2[1] = &LAB_1003f1f0;
    puVar2[3] = &LAB_1003ef50;
    return;
  }
  _param_2 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    piVar8 = (int *)(*(int *)(param_1 + 0xc4) + 0xc);
    puVar7 = puVar2 + 0x12;
    do {
      iVar3 = *piVar8;
      iVar6 = iVar3;
      if (*(char *)(param_1 + 200) != '\0') {
        iVar6 = iVar3 * 3;
      }
      iVar1 = *(int *)(param_1 + 4);
      iVar3 = FUN_1003e470(piVar8[5],iVar3);
      iVar4 = FUN_1003e470(piVar8[4],piVar8[-1]);
      uVar5 = (**(code **)(iVar1 + 0x14))(param_1,1,1,iVar4,iVar3,iVar6);
      *puVar7 = uVar5;
      _param_2 = _param_2 + 1;
      puVar7 = puVar7 + 1;
      piVar8 = piVar8 + 0x15;
    } while (_param_2 < *(int *)(param_1 + 0x20));
  }
  puVar2[1] = &LAB_1003f200;
  puVar2[3] = &LAB_1003f470;
  puVar2[4] = puVar2 + 0x12;
  return;
}



