/* console_tokenize_line @ 00402580 */

/* splits a console line into tokens */

void console_tokenize_line(char *line)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char **ppcVar5;
  char *pcVar6;
  int iVar7;
  
  console_cmd_argc = 0;
  iVar7 = console_cmd_argc;
  if (line != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar2 = line;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (((~uVar3 - 1 < 2) || (*line != '/')) || (line[1] != '/')) {
      uVar3 = 0xffffffff;
      do {
        pcVar2 = line;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar2 = line + 1;
        cVar1 = *line;
        line = pcVar2;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar2 = pcVar2 + -uVar3;
      pcVar6 = (char *)&DAT_0047eaa0;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar6 = pcVar6 + 1;
      }
      pcVar2 = crt_strtok((char *)&DAT_0047eaa0,&DAT_004712d8);
      iVar7 = console_cmd_argc;
      if (pcVar2 != (char *)0x0) {
        iVar7 = 1;
        ppcVar5 = &console_cmd_arg1;
        console_cmd_name = pcVar2;
        while (pcVar2 = crt_strtok((char *)0x0,&DAT_004712d8), pcVar2 != (char *)0x0) {
          *ppcVar5 = pcVar2;
          iVar7 = iVar7 + 1;
          ppcVar5 = ppcVar5 + 1;
        }
      }
    }
  }
  console_cmd_argc = iVar7;
  return;
}



