/* crt_mt_init @ 00465451 */

/* CRT thread init (TLS + locks) */

undefined4 crt_mt_init(void)

{
  DWORD *lpTlsValue;
  WINBOOL WVar1;
  DWORD DVar2;
  
  crt_init_locks();
  DAT_0047b6f0 = TlsAlloc();
  if (DAT_0047b6f0 != 0xffffffff) {
    lpTlsValue = crt_calloc(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      WVar1 = TlsSetValue(DAT_0047b6f0,lpTlsValue);
      if (WVar1 != 0) {
        crt_init_thread_data(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}



