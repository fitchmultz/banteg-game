/* grim_measure_text_width @ 100096c0 */

/* Grim2D vtable 0x14c: small font width metric (handles newlines) */

int grim_measure_text_width(char *text)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  if (text == (char *)0x0) {
    return 0;
  }
  uVar3 = 0xffffffff;
  iVar2 = 0;
  iVar4 = 0;
  pcVar5 = text;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar6 = 0;
  if (0 < (int)(~uVar3 - 1)) {
    do {
      if (text[iVar6] == 10) {
        if (iVar2 < iVar4) {
          iVar2 = iVar4;
        }
        iVar4 = 0;
      }
      else {
        iVar4 = iVar4 + (uint)*(byte *)((int)&grim_font2_glyph_widths +
                                       (uint)(byte)(&grim_font2_char_map)[(byte)text[iVar6]]);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(~uVar3 - 1));
    if (iVar2 < iVar4) {
      iVar2 = iVar4;
    }
  }
  return iVar2;
}



