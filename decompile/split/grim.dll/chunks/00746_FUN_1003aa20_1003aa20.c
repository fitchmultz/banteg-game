/* FUN_1003aa20 @ 1003aa20 */

undefined4 __cdecl FUN_1003aa20(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar1 = (undefined4 *)param_1[5];
  iVar2 = puVar1[9];
  if (iVar2 < (int)puVar1[8]) {
    uVar3 = puVar1[8] - iVar2;
    if (0x1000 < (int)uVar3) {
      uVar3 = 0x1000;
    }
    puVar5 = (undefined4 *)(puVar1[7] + iVar2);
    puVar6 = (undefined4 *)puVar1[10];
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    puVar1[9] = puVar1[9] + uVar3;
    puVar1[1] = uVar3;
    *puVar1 = puVar1[10];
    *(undefined1 *)(puVar1 + 0xb) = 0;
    return CONCAT31((int3)(uVar3 >> 8),1);
  }
  if (*(char *)(puVar1 + 0xb) != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x29;
    (**(code **)*param_1)(param_1);
  }
  *(undefined4 *)(*param_1 + 0x14) = 0x74;
  (**(code **)(*param_1 + 4))(param_1,0xffffffff);
  *(undefined1 *)puVar1[10] = 0xff;
  *(undefined1 *)(puVar1[10] + 1) = 0xd9;
  puVar1[1] = 2;
  *puVar1 = puVar1[10];
  *(undefined1 *)(puVar1 + 0xb) = 0;
  return 1;
}



