/* crt_beginthread @ 0046223f */

/* CRT: beginthread (CreateThread wrapper) */

void * __cdecl crt_beginthread(void *start,uint stack_size,void *arg)

{
  void *lpThreadId;
  HANDLE hThread;
  DWORD DVar1;
  
  DVar1 = 0;
  lpThreadId = crt_calloc(1,0x74);
  if (lpThreadId != (void *)0x0) {
    crt_init_thread_data(lpThreadId);
    *(void **)((int)lpThreadId + 0x48) = start;
    *(void **)((int)lpThreadId + 0x4c) = arg;
    hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,stack_size,crt_thread_entry,lpThreadId,4,
                           lpThreadId);
    *(HANDLE *)((int)lpThreadId + 4) = hThread;
    if ((hThread != (HANDLE)0x0) && (DVar1 = ResumeThread(hThread), DVar1 != 0xffffffff)) {
      return hThread;
    }
    DVar1 = GetLastError();
  }
  crt_free_base(lpThreadId);
  if (DVar1 != 0) {
    crt_dosmaperr(DVar1);
  }
  return (void *)0xffffffff;
}



