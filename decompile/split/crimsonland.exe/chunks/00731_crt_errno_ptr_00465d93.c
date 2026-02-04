/* crt_errno_ptr @ 00465d93 */

/* CRT errno pointer accessor (thread-local) */

int * crt_errno_ptr(void)

{
  DWORD *pDVar1;
  
  pDVar1 = crt_get_thread_data();
  return (int *)(pDVar1 + 2);
}



