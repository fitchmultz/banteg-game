/* console_history_apply @ 004018d0 */

/* loads a history entry into the input buffer (used by Up/Down navigation) */

void __fastcall console_history_apply(int console_state)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  
  iVar7 = 0;
  iVar1 = *(int *)(console_state + 0x14) + -1;
  puVar3 = *(undefined4 **)(console_state + 0x10);
  puVar4 = *(undefined4 **)(console_state + 0x10);
  if (0 < iVar1) {
    do {
      puVar4 = (undefined4 *)puVar3[1];
      if (puVar4 == (undefined4 *)0x0) {
        *(int *)(console_state + 0x14) = iVar7;
        puVar4 = puVar3;
        break;
      }
      iVar7 = iVar7 + 1;
      puVar3 = puVar4;
    } while (iVar7 < iVar1);
  }
  uVar5 = 0xffffffff;
  pcVar8 = (char *)*puVar4;
  do {
    pcVar9 = pcVar8;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar8 + 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  pcVar8 = pcVar9 + -uVar5;
  pcVar9 = (char *)&console_input_buf;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar8 = (char *)&console_input_buf;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  console_input_cursor = ~uVar5 - 1;
  console_input_ready = 0;
  return;
}



