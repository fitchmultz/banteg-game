/* FUN_10041ba0 @ 10041ba0 */

void __cdecl FUN_10041ba0(int *param_1)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  int iStack_c;
  
  puVar3 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0xa0);
  param_1[0x67] = (int)puVar3;
  *puVar3 = &LAB_10041da0;
  puVar3[1] = &LAB_10041dc0;
  *(undefined1 *)(puVar3 + 2) = 0;
  if ((char)param_1[0x42] != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x17;
    (**(code **)*param_1)(param_1);
  }
  if (((char)param_1[0x12] == '\0') || (bVar2 = true, param_1[0x45] < 2)) {
    bVar2 = false;
  }
  iStack_c = 0;
  if (0 < param_1[8]) {
    piVar7 = (int *)(param_1[0x31] + 0x24);
    puVar8 = puVar3 + 0xd;
    do {
      iVar4 = (piVar7[-7] * *piVar7) / param_1[0x45];
      iVar5 = (piVar7[-6] * *piVar7) / param_1[0x45];
      iVar9 = param_1[0x44];
      iVar1 = param_1[0x43];
      puVar8[0xc] = iVar5;
      if ((char)piVar7[3] == '\0') {
        *puVar8 = &LAB_10041ec0;
      }
      else if ((iVar4 == iVar1) && (iVar5 == iVar9)) {
        *puVar8 = &LAB_10041eb0;
      }
      else {
        if (iVar4 * 2 == iVar1) {
          if (iVar5 == iVar9) {
            if ((bVar2) && (2 < (uint)piVar7[1])) {
              *puVar8 = &LAB_100420e0;
            }
            else {
              *puVar8 = &LAB_10041ff0;
            }
          }
          else {
            if ((iVar4 * 2 != iVar1) || (iVar5 * 2 != iVar9)) goto LAB_10041cf5;
            if ((bVar2) && (2 < (uint)piVar7[1])) {
              *puVar8 = &LAB_100421b0;
              *(undefined1 *)(puVar3 + 2) = 1;
            }
            else {
              *puVar8 = &LAB_10042050;
            }
          }
        }
        else {
LAB_10041cf5:
          if ((iVar1 % iVar4 == 0) && (iVar9 % iVar5 == 0)) {
            *puVar8 = &LAB_10041ed0;
            *(char *)(iStack_c + 0x8c + (int)puVar3) = (char)(iVar1 / iVar4);
            *(char *)(iStack_c + 0x96 + (int)puVar3) = (char)(iVar9 / iVar5);
          }
          else {
            *(undefined4 *)(*param_1 + 0x14) = 0x25;
            (**(code **)*param_1)(param_1);
          }
        }
        iVar9 = param_1[0x44];
        iVar1 = param_1[1];
        iVar4 = FUN_1003e470(param_1[0x17],param_1[0x43]);
        uVar6 = (**(code **)(iVar1 + 8))(param_1,1,iVar4,iVar9);
        puVar8[-10] = uVar6;
      }
      iStack_c = iStack_c + 1;
      puVar8 = puVar8 + 1;
      piVar7 = piVar7 + 0x15;
    } while (iStack_c < param_1[8]);
  }
  return;
}



