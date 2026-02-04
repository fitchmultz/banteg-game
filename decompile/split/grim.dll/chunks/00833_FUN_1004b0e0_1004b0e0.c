/* FUN_1004b0e0 @ 1004b0e0 */

int __cdecl FUN_1004b0e0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_4;
  
  puVar4 = *(undefined4 **)(param_1 + 0x34);
  puVar6 = *(undefined4 **)(param_1 + 0x30);
  local_4 = *(undefined4 **)(param_2 + 0xc);
  if (puVar4 < puVar6) {
    puVar4 = *(undefined4 **)(param_1 + 0x2c);
  }
  uVar3 = *(uint *)(param_2 + 0x10);
  uVar5 = (int)puVar4 - (int)puVar6;
  if (uVar3 < (uint)((int)puVar4 - (int)puVar6)) {
    uVar5 = uVar3;
  }
  if ((uVar5 != 0) && (param_3 == -5)) {
    param_3 = 0;
  }
  *(uint *)(param_2 + 0x10) = uVar3 - uVar5;
  *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar5;
  if (*(code **)(param_1 + 0x38) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0x3c),puVar6,uVar5);
    *(undefined4 *)(param_1 + 0x3c) = uVar1;
    *(undefined4 *)(param_2 + 0x30) = uVar1;
  }
  puVar4 = puVar6;
  puVar7 = local_4;
  for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  puVar2 = (undefined1 *)((int)puVar6 + uVar5);
  for (uVar3 = uVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  local_4 = (undefined4 *)((int)local_4 + uVar5);
  if (puVar2 == *(undefined1 **)(param_1 + 0x2c)) {
    puVar4 = *(undefined4 **)(param_1 + 0x28);
    if (*(undefined1 **)(param_1 + 0x34) == *(undefined1 **)(param_1 + 0x2c)) {
      *(undefined4 **)(param_1 + 0x34) = puVar4;
    }
    uVar5 = *(int *)(param_1 + 0x34) - (int)puVar4;
    uVar3 = *(uint *)(param_2 + 0x10);
    if (uVar3 < uVar5) {
      uVar5 = uVar3;
    }
    if ((uVar5 != 0) && (param_3 == -5)) {
      param_3 = 0;
    }
    *(uint *)(param_2 + 0x10) = uVar3 - uVar5;
    *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar5;
    if (*(code **)(param_1 + 0x38) != (code *)0x0) {
      uVar1 = (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0x3c),puVar4,uVar5);
      *(undefined4 *)(param_1 + 0x3c) = uVar1;
      *(undefined4 *)(param_2 + 0x30) = uVar1;
    }
    puVar6 = puVar4;
    puVar7 = local_4;
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    local_4 = (undefined4 *)((int)local_4 + uVar5);
    puVar2 = (undefined1 *)((int)puVar4 + uVar5);
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
  }
  *(undefined4 **)(param_2 + 0xc) = local_4;
  *(undefined1 **)(param_1 + 0x30) = puVar2;
  return param_3;
}



