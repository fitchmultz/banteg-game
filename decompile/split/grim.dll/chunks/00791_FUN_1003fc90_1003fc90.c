/* FUN_1003fc90 @ 1003fc90 */

void __cdecl FUN_1003fc90(int param_1,int param_2,int *param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  char *pcVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  int local_51c;
  int *piStack_518;
  int iStack_514;
  int iStack_510;
  char local_508 [256];
  int aiStack_408 [258];
  
  if (*param_3 == 0) {
    iVar3 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x5d4);
    *param_3 = iVar3;
  }
  iVar3 = *param_3;
  iVar4 = 0;
  *(int *)(iVar3 + 0xd0) = param_2;
  local_51c = 0;
  iVar7 = 1;
  do {
    bVar1 = *(byte *)(iVar7 + param_2);
    if (bVar1 != 0) {
      cVar2 = (char)iVar7;
      pcVar10 = local_508 + iVar4;
      for (uVar6 = (uint)(bVar1 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {
        *(uint *)pcVar10 = CONCAT22(CONCAT11(cVar2,cVar2),CONCAT11(cVar2,cVar2));
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = bVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = cVar2;
        pcVar10 = pcVar10 + 1;
      }
      iVar4 = local_51c + (uint)bVar1;
      local_51c = iVar4;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x11);
  local_508[iVar4] = '\0';
  iVar4 = 0;
  iVar7 = 0;
  iVar9 = (int)local_508[0];
  while (local_508[0] != '\0') {
    if (local_508[iVar7] == iVar9) {
      piVar5 = aiStack_408 + iVar7 + 1;
      do {
        cVar2 = local_508[iVar7 + 1];
        iVar7 = iVar7 + 1;
        *piVar5 = iVar4;
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (cVar2 == iVar9);
    }
    iVar4 = iVar4 << 1;
    iVar9 = iVar9 + 1;
    local_508[0] = local_508[iVar7];
  }
  iVar7 = 0;
  iVar4 = 1;
  piVar5 = (int *)(iVar3 + 0x48);
  do {
    if (*(char *)(iVar4 + param_2) == '\0') {
      *piVar5 = -1;
    }
    else {
      iVar9 = aiStack_408[iVar7 + 1];
      piVar5[0x12] = iVar7;
      piVar5[-0x11] = iVar9;
      iVar7 = iVar7 + (uint)*(byte *)(iVar4 + param_2);
      *piVar5 = aiStack_408[iVar7];
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar4 < 0x11);
  iVar4 = 0;
  *(undefined4 *)(iVar3 + 0x88) = 0xfffff;
  puVar11 = (undefined4 *)(iVar3 + 0xd4);
  for (iVar7 = 0x100; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  local_51c = 0;
  iVar7 = 1;
  iStack_510 = 7;
  do {
    iStack_514 = 1;
    if (*(char *)(param_2 + iVar7) != '\0') {
      puVar12 = (undefined1 *)(iVar4 + 0x11 + param_2);
      piStack_518 = aiStack_408 + iVar4 + 1;
      iVar9 = 1 << ((byte)iStack_510 & 0x1f);
      do {
        iVar4 = *piStack_518 << ((byte)iStack_510 & 0x1f);
        if (0 < iVar9) {
          puVar8 = (undefined1 *)(iVar4 + 0x4d4 + iVar3);
          piVar5 = (int *)(iVar3 + 0xd4 + iVar4 * 4);
          iVar4 = iVar9;
          do {
            *piVar5 = iVar7;
            piVar5 = piVar5 + 1;
            *puVar8 = *puVar12;
            puVar8 = puVar8 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        iStack_514 = iStack_514 + 1;
        iVar4 = local_51c + 1;
        piStack_518 = piStack_518 + 1;
        puVar12 = puVar12 + 1;
        local_51c = iVar4;
      } while (iStack_514 <= (int)(uint)*(byte *)(param_2 + iVar7));
    }
    iVar7 = iVar7 + 1;
    iStack_510 = iStack_510 + -1;
  } while (-1 < iStack_510);
  return;
}



