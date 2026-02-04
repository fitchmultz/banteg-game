/* crt_read_nolock @ 00466064 */

/* CRT: read handle (no lock), CRLF translation */

int __cdecl crt_read_nolock(int fd,char *buf,uint count)

{
  void ***pppvVar1;
  char cVar2;
  void *pvVar3;
  byte bVar4;
  uint uVar5;
  WINBOOL WVar6;
  DWORD DVar7;
  int *piVar8;
  uint *puVar9;
  char *pcVar10;
  int iVar11;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)0x0;
  if (count != 0) {
    uVar5 = fd & 0x1f;
    pppvVar1 = &crt_pioinfo_table + (fd >> 5);
    iVar11 = uVar5 * 0x24;
    pvVar3 = (&crt_pioinfo_table)[fd >> 5][uVar5 * 9 + 1];
    if (((uint)pvVar3 & 2) == 0) {
      pcVar10 = buf;
      if ((((uint)pvVar3 & 0x48) != 0) &&
         (cVar2 = *(char *)((int)(&crt_pioinfo_table)[fd >> 5] + iVar11 + 5), cVar2 != '\n')) {
        count = count - 1;
        *buf = cVar2;
        pcVar10 = buf + 1;
        local_c = (char *)0x1;
        *(undefined1 *)((int)*pppvVar1 + iVar11 + 5) = 10;
      }
      WVar6 = ReadFile((*pppvVar1)[uVar5 * 9],pcVar10,count,&local_10,(LPOVERLAPPED)0x0);
      if (WVar6 == 0) {
        DVar7 = GetLastError();
        if (DVar7 == 5) {
          piVar8 = crt_errno_ptr();
          *piVar8 = 9;
          puVar9 = crt_doserrno_ptr();
          *puVar9 = 5;
        }
        else {
          if (DVar7 == 0x6d) {
            return 0;
          }
          crt_dosmaperr(DVar7);
        }
        return -1;
      }
      bVar4 = *(byte *)(*pppvVar1 + uVar5 * 9 + 1);
      if ((bVar4 & 0x80) == 0) {
        return (int)local_c + local_10;
      }
      if ((local_10 == 0) || (*buf != '\n')) {
        bVar4 = bVar4 & 0xfb;
      }
      else {
        bVar4 = bVar4 | 4;
      }
      *(byte *)(*pppvVar1 + uVar5 * 9 + 1) = bVar4;
      count = (uint)buf;
      local_c = buf + (int)local_c + local_10;
      pcVar10 = buf;
      if (buf < local_c) {
        do {
          cVar2 = *(char *)count;
          if (cVar2 == '\x1a') {
            bVar4 = *(byte *)(*pppvVar1 + uVar5 * 9 + 1);
            if ((bVar4 & 0x40) == 0) {
              *(byte *)(*pppvVar1 + uVar5 * 9 + 1) = bVar4 | 2;
            }
            break;
          }
          if (cVar2 == '\r') {
            if (count < local_c + -1) {
              if (*(char *)(count + 1) == '\n') {
                count = count + 2;
                goto LAB_004661ef;
              }
              *pcVar10 = '\r';
              pcVar10 = pcVar10 + 1;
              count = count + 1;
            }
            else {
              count = count + 1;
              WVar6 = ReadFile((*pppvVar1)[uVar5 * 9],&local_5,1,&local_10,(LPOVERLAPPED)0x0);
              if (((WVar6 == 0) && (DVar7 = GetLastError(), DVar7 != 0)) || (local_10 == 0)) {
LAB_00466209:
                *pcVar10 = '\r';
LAB_0046620c:
                pcVar10 = pcVar10 + 1;
              }
              else if (((uint)(*pppvVar1)[uVar5 * 9 + 1] & 0x48) == 0) {
                if ((pcVar10 == buf) && (local_5 == '\n')) {
LAB_004661ef:
                  *pcVar10 = '\n';
                  goto LAB_0046620c;
                }
                crt_lseek_nolock(fd,-1,1);
                if (local_5 != '\n') goto LAB_00466209;
              }
              else {
                if (local_5 == '\n') goto LAB_004661ef;
                *pcVar10 = '\r';
                pcVar10 = pcVar10 + 1;
                *(char *)((int)*pppvVar1 + iVar11 + 5) = local_5;
              }
            }
          }
          else {
            *pcVar10 = cVar2;
            pcVar10 = pcVar10 + 1;
            count = count + 1;
          }
        } while (count < local_c);
      }
      return (int)pcVar10 - (int)buf;
    }
  }
  return 0;
}



