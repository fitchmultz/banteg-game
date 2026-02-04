/* crt_flushall @ 0046150a */

/* CRT: flush all streams (mode 0/1) */

int __cdecl crt_flushall(int mode)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  crt_lock(2);
  iVar4 = 0;
  if (0 < crt_stream_count) {
    do {
      pFVar1 = crt_stream_table[iVar4];
      if ((pFVar1 != (FILE *)0x0) && (((byte)pFVar1[0xc] & 0x83) != 0)) {
        crt_lock_file2(iVar4,(int)pFVar1);
        pFVar1 = crt_stream_table[iVar4];
        if ((*(uint *)(pFVar1 + 0xc) & 0x83) != 0) {
          if (mode == 1) {
            iVar2 = crt_fflush_nolock((int *)pFVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((mode == 0) && ((*(uint *)(pFVar1 + 0xc) & 2) != 0)) {
            iVar2 = crt_fflush_nolock((int *)pFVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        crt_unlock_file2(iVar4,(int)crt_stream_table[iVar4]);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < crt_stream_count);
  }
  crt_unlock(2);
  if (mode != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}



