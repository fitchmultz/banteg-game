/* FUN_100136d2 @ 100136d2 */

/* [binja] int32_t __fastcall sub_100136d2(int32_t* arg1) */

int __fastcall FUN_100136d2(int *arg1)

{
  ushort *puVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  
  puVar3 = *(ushort **)(arg1[1] + 0x18);
  iVar4 = *arg1;
  iVar5 = *(int *)(iVar4 + 0x1050);
  puVar6 = *(ushort **)(iVar4 + 0x18);
  puVar8 = (ushort *)(*(int *)(iVar4 + 0x105c) * iVar5 + (int)puVar6);
  for (; puVar6 < puVar8; puVar6 = puVar6 + iVar5) {
    iVar4 = *(int *)(iVar4 + 0x1058);
    puVar9 = (ushort *)(iVar5 + (int)puVar6);
    puVar7 = puVar3;
    for (puVar10 = puVar6; puVar10 < puVar6 + iVar4; puVar10 = puVar10 + 2) {
      puVar1 = puVar9 + 1;
      uVar2 = *puVar9;
      puVar9 = puVar9 + 2;
      *puVar7 = (ushort)((puVar10[1] & 0xffff03e0) + 0x40 +
                         (*puVar1 & 0xffff03e0) + (*puVar10 & 0xffff03e0) + (uVar2 & 0xffff03e0) >>
                        2) & 0x3e0 |
                (ushort)((*puVar1 & 0x7c1f) + (*puVar10 & 0x7c1f) + (uVar2 & 0x7c1f) + 0x802 +
                         (puVar10[1] & 0x7c1f) >> 2) & 0x7c1f;
      puVar7 = puVar7 + 1;
    }
    puVar3 = (ushort *)((int)puVar3 + *(int *)(arg1[1] + 0x1050));
    iVar4 = *arg1;
    iVar5 = *(int *)(iVar4 + 0x1050);
  }
  return 0;
}



