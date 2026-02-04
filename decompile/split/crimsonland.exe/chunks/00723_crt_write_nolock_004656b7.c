/* crt_write_nolock @ 004656b7 */

/* CRT: write handle (no lock), text-mode CRLF translation */

int __cdecl crt_write_nolock(int fd,char *buf,uint count)

{
  void ***pppvVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  WINBOOL WVar7;
  int *piVar8;
  uint *puVar9;
  char local_418 [1028];
  int local_14;
  DWORD local_10;
  DWORD local_c;
  char *local_8;
  
  local_c = 0;
  local_14 = 0;
  if (count == 0) {
LAB_004656d0:
    iVar4 = 0;
  }
  else {
    pppvVar1 = &crt_pioinfo_table + (fd >> 5);
    uVar5 = fd & 0x1f;
    if (((uint)(*pppvVar1)[uVar5 * 9 + 1] & 0x20) != 0) {
      crt_lseek_nolock(fd,0,2);
    }
    if (((uint)(*pppvVar1 + uVar5 * 9)[1] & 0x80) == 0) {
      WVar7 = WriteFile((*pppvVar1)[uVar5 * 9],buf,count,&local_10,(LPOVERLAPPED)0x0);
      if (WVar7 == 0) {
        fd = GetLastError();
      }
      else {
        local_c = local_10;
        fd = 0;
      }
LAB_0046579f:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (fd == 0) goto LAB_00465811;
      if (fd == 5) {
        piVar8 = crt_errno_ptr();
        *piVar8 = 9;
        puVar9 = crt_doserrno_ptr();
        *puVar9 = 5;
      }
      else {
        crt_dosmaperr(fd);
      }
    }
    else {
      local_8 = buf;
      fd = 0;
      if (count != 0) {
        do {
          pcVar6 = local_418;
          do {
            if (count <= (uint)((int)local_8 - (int)buf)) break;
            pcVar2 = local_8 + 1;
            cVar3 = *local_8;
            local_8 = pcVar2;
            if (cVar3 == '\n') {
              local_14 = local_14 + 1;
              *pcVar6 = '\r';
              pcVar6 = pcVar6 + 1;
            }
            *pcVar6 = cVar3;
            pcVar6 = pcVar6 + 1;
          } while ((int)pcVar6 - (int)local_418 < 0x400);
          WVar7 = WriteFile((*pppvVar1)[uVar5 * 9],local_418,(int)pcVar6 - (int)local_418,&local_10,
                            (LPOVERLAPPED)0x0);
          if (WVar7 == 0) {
            fd = GetLastError();
            goto LAB_0046579f;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar6 - (int)local_418) ||
             (count <= (uint)((int)local_8 - (int)buf))) goto LAB_0046579f;
        } while( true );
      }
LAB_00465811:
      if ((((uint)(*pppvVar1)[uVar5 * 9 + 1] & 0x40) != 0) && (*buf == '\x1a')) goto LAB_004656d0;
      piVar8 = crt_errno_ptr();
      *piVar8 = 0x1c;
      puVar9 = crt_doserrno_ptr();
      *puVar9 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}



