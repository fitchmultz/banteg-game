/* crt_getdcwd @ 004624b5 */

/* CRT: get current working directory for drive */

char * __cdecl crt_getdcwd(int drive,char *buf,uint size)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  DWORD DVar5;
  uint _Size;
  char *pcVar6;
  CHAR local_10c [260];
  LPSTR local_8;
  
  iVar1 = drive;
  if (drive == 0) {
    DVar5 = GetCurrentDirectoryA(0x104,local_10c);
  }
  else {
    iVar2 = FUN_0046258a(drive);
    if (iVar2 == 0) {
      puVar3 = crt_doserrno_ptr();
      *puVar3 = 0xf;
      piVar4 = crt_errno_ptr();
      *piVar4 = 0xd;
      return (char *)0x0;
    }
    drive = (int)CONCAT12(0x2e,CONCAT11(0x3a,(char)iVar1 + '@'));
    DVar5 = GetFullPathNameA((LPCSTR)&drive,0x104,local_10c,&local_8);
  }
  if ((DVar5 != 0) && (_Size = DVar5 + 1, _Size < 0x105)) {
    if (buf == (char *)0x0) {
      if ((int)_Size <= (int)size) {
        _Size = size;
      }
      pcVar6 = _malloc(_Size);
      if (pcVar6 != (char *)0x0) {
LAB_00462576:
        pcVar6 = crt_strcpy(pcVar6,local_10c);
        return pcVar6;
      }
      piVar4 = crt_errno_ptr();
      *piVar4 = 0xc;
    }
    else {
      pcVar6 = buf;
      if ((int)_Size <= (int)size) goto LAB_00462576;
      piVar4 = crt_errno_ptr();
      *piVar4 = 0x22;
    }
  }
  return (char *)0x0;
}



