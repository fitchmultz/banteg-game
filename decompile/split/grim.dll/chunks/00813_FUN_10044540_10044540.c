/* FUN_10044540 @ 10044540 */

void __cdecl FUN_10044540(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int local_18;
  int *piStack_14;
  char cStack_10;
  int iStack_c;
  
  iVar1 = *(int *)(param_1 + 0x1a4);
  if (*(int *)(param_1 + 0x4c) == 1) {
    local_18 = 0x1fe;
    *(undefined1 *)(iVar1 + 0x1c) = 1;
  }
  else {
    local_18 = 0;
    *(undefined1 *)(iVar1 + 0x1c) = 0;
  }
  uVar3 = (**(code **)(*(int *)(param_1 + 4) + 8))
                    (param_1,1,local_18 + 0x100,*(undefined4 *)(param_1 + 100));
  *(undefined4 *)(iVar1 + 0x18) = uVar3;
  iVar4 = *(int *)(iVar1 + 0x14);
  iStack_c = 0;
  if (0 < *(int *)(param_1 + 100)) {
    piStack_14 = (int *)(iVar1 + 0x20);
    do {
      iVar6 = *piStack_14;
      iVar4 = iVar4 / iVar6;
      if (local_18 != 0) {
        *(int *)(*(int *)(iVar1 + 0x18) + iStack_c * 4) =
             *(int *)(*(int *)(iVar1 + 0x18) + iStack_c * 4) + 0xff;
      }
      puVar2 = *(undefined1 **)(*(int *)(iVar1 + 0x18) + iStack_c * 4);
      iVar5 = (iVar6 + 0xfe) / (iVar6 * 2 + -2);
      iVar9 = 0;
      iVar10 = 0;
      do {
        if (iVar5 < iVar10) {
          iVar7 = iVar9 * 0x1fe;
          do {
            iVar5 = (iVar7 + 0x2fc + iVar6) / (iVar6 * 2 + -2);
            iVar9 = iVar9 + 1;
            iVar7 = iVar7 + 0x1fe;
          } while (iVar5 < iVar10);
        }
        cStack_10 = (char)iVar4;
        puVar2[iVar10] = cStack_10 * (char)iVar9;
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0x100);
      if (local_18 != 0) {
        iVar6 = 1;
        puVar8 = puVar2;
        do {
          puVar8 = puVar8 + -1;
          *puVar8 = *puVar2;
          puVar2[iVar6 + 0xff] = puVar2[0xff];
          iVar6 = iVar6 + 1;
        } while (iVar6 < 0x100);
      }
      iStack_c = iStack_c + 1;
      piStack_14 = piStack_14 + 1;
    } while (iStack_c < *(int *)(param_1 + 100));
  }
  return;
}



