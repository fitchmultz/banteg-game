/* crt_get_thread_data @ 004654b8 */

/* CRT per-thread data accessor */

DWORD * crt_get_thread_data(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  WINBOOL WVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_0047b6f0);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = crt_calloc(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      WVar1 = TlsSetValue(DAT_0047b6f0,lpTlsValue);
      if (WVar1 != 0) {
        crt_init_thread_data(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_00465513;
      }
    }
    __amsg_exit(0x10);
  }
LAB_00465513:
  SetLastError(dwErrCode);
  return lpTlsValue;
}



