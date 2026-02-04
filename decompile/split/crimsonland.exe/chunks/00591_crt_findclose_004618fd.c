/* crt_findclose @ 004618fd */

/* CRT _findclose wrapper over FindClose */

int __cdecl crt_findclose(HANDLE handle)

{
  WINBOOL WVar1;
  int *piVar2;
  
  WVar1 = FindClose(handle);
  if (WVar1 == 0) {
    piVar2 = crt_errno_ptr();
    *piVar2 = 0x16;
    return -1;
  }
  return 0;
}



