/* crt_heap_select @ 00466a8e */

/* selects CRT heap strategy */

int crt_heap_select(void)

{
  char cVar1;
  WINBOOL WVar2;
  DWORD DVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  char *this;
  int unaff_EBX;
  char local_1230 [4240];
  char local_1a0 [260];
  DWORD local_9c;
  uint local_98;
  DWORD local_8c;
  CHAR aCStackY_18 [4];
  byte bVar7;
  
  crt_chkstk();
  local_9c = 0x94;
  WVar2 = GetVersionExA((LPOSVERSIONINFOA)&local_9c);
  if (((WVar2 == 0) || (local_8c != 2)) || (local_98 < 5)) {
    aCStackY_18[0] = -0x18;
    aCStackY_18[1] = 'j';
    aCStackY_18[2] = 'F';
    aCStackY_18[3] = '\0';
    DVar3 = GetEnvironmentVariableA("__MSVCRT_HEAP_SELECT",local_1230,0x1090);
    if (DVar3 != 0) {
      pcVar6 = local_1230;
      while (local_1230[0] != '\0') {
        cVar1 = *pcVar6;
        if (('`' < cVar1) && (cVar1 < '{')) {
          *pcVar6 = cVar1 + -0x20;
        }
        pcVar6 = pcVar6 + 1;
        local_1230[0] = *pcVar6;
      }
      builtin_memcpy(aCStackY_18,"&kF",4);
      iVar4 = _strncmp("__GLOBAL_HEAP_SELECTED",local_1230,0x16);
      if (iVar4 == 0) {
        pcVar6 = local_1230;
      }
      else {
        builtin_memcpy(aCStackY_18,"HkF",4);
        GetModuleFileNameA((HMODULE)0x0,local_1a0,0x104);
        pcVar6 = local_1a0;
        while (local_1a0[0] != '\0') {
          cVar1 = *pcVar6;
          if (('`' < cVar1) && (cVar1 < '{')) {
            *pcVar6 = cVar1 + -0x20;
          }
          pcVar6 = pcVar6 + 1;
          local_1a0[0] = *pcVar6;
        }
        pcVar6 = _strstr(local_1230,local_1a0);
      }
      if ((pcVar6 != (char *)0x0) && (pcVar6 = _strchr(pcVar6,0x2c), pcVar6 != (char *)0x0)) {
        pcVar6 = pcVar6 + 1;
        cVar1 = *pcVar6;
        this = pcVar6;
        while (cVar1 != '\0') {
          if (*this == ';') {
            *this = '\0';
          }
          else {
            this = this + 1;
          }
          cVar1 = *this;
        }
        aCStackY_18[0] = -0x52;
        aCStackY_18[1] = 'k';
        aCStackY_18[2] = 'F';
        aCStackY_18[3] = '\0';
        lVar5 = crt_strtol_l(this,pcVar6,(char *)0x0,(char **)0xa,unaff_EBX);
        if (lVar5 == 2) {
          return 2;
        }
        if (lVar5 == 3) {
          return 3;
        }
        if (lVar5 == 1) {
          return 1;
        }
      }
    }
    bVar7 = (byte)unaff_EBX;
    FUN_00466a61((int *)&stack0xfffffff8);
    iVar4 = 3 - (uint)(bVar7 < 6);
  }
  else {
    iVar4 = 1;
  }
  return iVar4;
}



