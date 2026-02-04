/* crt_getstream @ 004641a0 */

/* CRT: allocate FILE struct from pool */

undefined4 * crt_getstream(void)

{
  FILE *pFVar1;
  int iVar2;
  FILE *pFVar3;
  
  pFVar3 = (FILE *)0x0;
  crt_lock(2);
  iVar2 = 0;
  if (0 < crt_stream_count) {
    do {
      pFVar1 = crt_stream_table[iVar2];
      if (pFVar1 == (FILE *)0x0) {
        pFVar1 = _malloc(0x38);
        crt_stream_table[iVar2] = pFVar1;
        if (crt_stream_table[iVar2] != (FILE *)0x0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(crt_stream_table[iVar2] + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(crt_stream_table[iVar2] + 0x20));
          pFVar3 = crt_stream_table[iVar2];
LAB_00464244:
          if (pFVar3 != (FILE *)0x0) {
            *(undefined4 *)(pFVar3 + 0x10) = 0xffffffff;
            *(undefined4 *)(pFVar3 + 4) = 0;
            *(undefined4 *)(pFVar3 + 0xc) = 0;
            *(undefined4 *)(pFVar3 + 8) = 0;
            *(undefined4 *)pFVar3 = 0;
            *(undefined4 *)(pFVar3 + 0x1c) = 0;
          }
        }
        break;
      }
      if (((byte)pFVar1[0xc] & 0x83) == 0) {
        crt_lock_file2(iVar2,(int)pFVar1);
        if (((byte)crt_stream_table[iVar2][0xc] & 0x83) == 0) {
          pFVar3 = crt_stream_table[iVar2];
          goto LAB_00464244;
        }
        crt_unlock_file2(iVar2,(int)crt_stream_table[iVar2]);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < crt_stream_count);
  }
  crt_unlock(2);
  return (undefined4 *)pFVar3;
}



