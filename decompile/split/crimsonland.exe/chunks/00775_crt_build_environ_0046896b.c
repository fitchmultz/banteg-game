/* crt_build_environ @ 0046896b */

/* builds environ array from environment block */

void crt_build_environ(void)

{
  char cVar1;
  size_t sVar2;
  char **ppcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
  if (DAT_004db4ec == 0) {
    crt_mbcs_init();
  }
  iVar5 = 0;
  for (pcVar6 = DAT_004d99c4; *pcVar6 != '\0'; pcVar6 = pcVar6 + sVar2 + 1) {
    if (*pcVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen(pcVar6);
  }
  ppcVar3 = _malloc(iVar5 * 4 + 4);
  crt_environ = ppcVar3;
  if (ppcVar3 == (char **)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_004d99c4;
  pcVar6 = DAT_004d99c4;
  while (cVar1 != '\0') {
    sVar2 = _strlen(pcVar6);
    if (*pcVar6 != '=') {
      pcVar4 = _malloc(sVar2 + 1);
      *ppcVar3 = pcVar4;
      if (pcVar4 == (char *)0x0) {
        __amsg_exit(9);
      }
      crt_strcpy(*ppcVar3,pcVar6);
      ppcVar3 = ppcVar3 + 1;
    }
    pcVar6 = pcVar6 + sVar2 + 1;
    cVar1 = *pcVar6;
  }
  crt_free_base(DAT_004d99c4);
  DAT_004d99c4 = (char *)0x0;
  *ppcVar3 = (char *)0x0;
  DAT_004db4e8 = 1;
  return;
}



