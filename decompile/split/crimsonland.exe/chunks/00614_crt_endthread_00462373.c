/* crt_endthread @ 00462373 */

/* CRT: thread cleanup and exit */

void crt_endthread(void)

{
  DWORD *pDVar1;
  
  if (PTR_FUN_0047b168 != (undefined *)0x0) {
    (*(code *)PTR_FUN_0047b168)();
  }
  pDVar1 = crt_get_thread_data();
  if (pDVar1 == (DWORD *)0x0) {
    __amsg_exit(0x10);
  }
  if ((HANDLE)pDVar1[1] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)pDVar1[1]);
  }
  crt_free_thread_data((undefined *)pDVar1);
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



