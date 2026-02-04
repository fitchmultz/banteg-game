/* wrap_text_to_width_alloc @ 0042fd00 */

/* allocates a wrapped copy of text to fit max_width_px (replaces spaces with '\n' using
   grim_measure_text_width per char) */

char * __thiscall wrap_text_to_width_alloc(void *this,char *text,int max_width_px)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uStack_4;
  
  uVar4 = 0xffffffff;
  pcVar2 = text;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar5 = ~uVar4 - 1;
  uStack_4 = (uint)this & 0xffffff;
  pcVar2 = operator_new(~uVar4);
  uVar4 = 0xffffffff;
  do {
    pcVar7 = text;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = text + 1;
    cVar1 = *text;
    text = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar7 + -uVar4;
  pcVar9 = pcVar2;
  for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar8 = 0;
  iVar10 = max_width_px;
  if (0 < iVar5) {
    do {
      uStack_4._0_3_ = CONCAT12(pcVar2[iVar8],(undefined2)uStack_4);
      iVar3 = (*grim_interface_ptr->vtable->grim_measure_text_width)((char *)((int)&uStack_4 + 2));
      iVar10 = iVar10 - iVar3;
      if (iVar10 < 0) {
        do {
          iVar10 = iVar8 + -1;
          iVar8 = iVar8 + -1;
        } while (pcVar2[iVar10] != ' ');
        pcVar2[iVar8] = '\n';
        iVar10 = max_width_px;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar5);
  }
  return pcVar2;
}



