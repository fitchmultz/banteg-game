/* ui_element_layout_calc @ 0044fb50 */

/* [binja] float sub_44fb50(float arg1) */

float __cdecl ui_element_layout_calc(float arg1)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  float10 in_ST0;
  
  if (((undefined *)arg1 != &DAT_0048c300) && ((undefined *)arg1 != &DAT_0048c618)) {
    *(float *)((int)arg1 + 0x20) =
         *(float *)((int)arg1 + 0x3c) + *(float *)((int)arg1 + 0x18) + *(float *)((int)arg1 + 0x20);
    *(float *)((int)arg1 + 0x24) =
         *(float *)((int)arg1 + 0x40) + *(float *)((int)arg1 + 0x1c) + *(float *)((int)arg1 + 0x24);
    *(float *)((int)arg1 + 0x28) =
         *(float *)((int)arg1 + 0x3c) + *(float *)((int)arg1 + 0x18) + *(float *)((int)arg1 + 0x28);
    *(float *)((int)arg1 + 0x2c) =
         *(float *)((int)arg1 + 0x40) + *(float *)((int)arg1 + 0x1c) + *(float *)((int)arg1 + 0x2c);
    *(float *)((int)arg1 + 0x20) = *(float *)((int)arg1 + 0x3c) + *(float *)((int)arg1 + 0x18);
    fVar2 = *(float *)((int)arg1 + 0x74) - *(float *)((int)arg1 + 0x3c);
    *(float *)((int)arg1 + 0x24) = *(float *)((int)arg1 + 0x40) + *(float *)((int)arg1 + 0x1c);
    *(float *)((int)arg1 + 0x20) = fVar2 * 0.54 + *(float *)((int)arg1 + 0x20);
    fVar3 = *(float *)((int)arg1 + 0x78) - *(float *)((int)arg1 + 0x40);
    *(float *)((int)arg1 + 0x24) = fVar3 * 0.28 + *(float *)((int)arg1 + 0x24);
    *(float *)((int)arg1 + 0x28) = *(float *)((int)arg1 + 0x74) + *(float *)((int)arg1 + 0x18);
    *(float *)((int)arg1 + 0x2c) = *(float *)((int)arg1 + 0x78) + *(float *)((int)arg1 + 0x1c);
    *(float *)((int)arg1 + 0x28) = *(float *)((int)arg1 + 0x28) - fVar2 * 0.05;
    *(float *)((int)arg1 + 0x2c) = *(float *)((int)arg1 + 0x2c) - fVar3 * 0.1;
    if ((*(char *)((int)arg1 + 0x314) != '\0') && (iVar5 = 0, 0 < *(int *)((int)arg1 + 0x120))) {
      puVar4 = (undefined4 *)((int)arg1 + 0x6c);
      do {
        uVar1 = puVar4[-7];
        iVar5 = iVar5 + 2;
        puVar4[-7] = *puVar4;
        *puVar4 = uVar1;
        puVar4 = puVar4 + 0xe;
      } while (iVar5 < *(int *)((int)arg1 + 0x120));
    }
  }
  return (float)in_ST0;
}



