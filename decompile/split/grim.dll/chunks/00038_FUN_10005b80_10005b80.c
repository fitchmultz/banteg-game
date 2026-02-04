/* FUN_10005b80 @ 10005b80 */

undefined4 __cdecl FUN_10005b80(byte *param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  
  uVar5 = 0xffffffff;
  pcVar9 = PTR_DAT_10053040;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  do {
    if (DAT_1005a458 <= (int)uVar5) {
      return 0;
    }
    pbVar3 = (byte *)(DAT_1005a670 + uVar5);
    uVar6 = 0xffffffff;
    pbVar8 = pbVar3;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar2 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (bVar2 != 0);
    iVar7 = ~uVar6 - 1;
    pbVar8 = param_1;
    do {
      bVar2 = *pbVar3;
      bVar10 = bVar2 < *pbVar8;
      if (bVar2 != *pbVar8) {
LAB_10005be1:
        iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_10005be6;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar10 = bVar2 < pbVar8[1];
      if (bVar2 != pbVar8[1]) goto LAB_10005be1;
      pbVar3 = pbVar3 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_10005be6:
    if (iVar4 == 0) {
      return *(undefined4 *)(DAT_1005a670 + iVar7 + 1 + uVar5);
    }
    uVar5 = *(int *)(DAT_1005a670 + iVar7 + 1 + uVar5) + iVar7 + 5 + uVar5;
  } while( true );
}



