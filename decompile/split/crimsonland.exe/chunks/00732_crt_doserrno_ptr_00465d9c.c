/* crt_doserrno_ptr @ 00465d9c */

/* CRT doserrno pointer accessor (thread-local) */

uint * crt_doserrno_ptr(void)

{
  DWORD *pDVar1;
  
  pDVar1 = crt_get_thread_data();
  return pDVar1 + 3;
}



