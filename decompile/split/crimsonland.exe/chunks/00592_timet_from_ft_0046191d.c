/* ___timet_from_ft @ 0046191d */

/* Library Function - Single Match
    ___timet_from_ft
   
   Library: Visual Studio 2003 Release */

int __cdecl ___timet_from_ft(FILETIME *param_1)

{
  WINBOOL WVar1;
  long lVar2;
  _SYSTEMTIME local_1c;
  _FILETIME local_c;
  
  if ((param_1->dwLowDateTime != 0) || (param_1->dwHighDateTime != 0)) {
    WVar1 = FileTimeToLocalFileTime((FILETIME *)param_1,&local_c);
    if (WVar1 != 0) {
      WVar1 = FileTimeToSystemTime(&local_c,&local_1c);
      if (WVar1 != 0) {
        lVar2 = crt_mktime((uint)local_1c.wYear,(uint)local_1c.wMonth,(uint)local_1c.wDay,
                           (uint)local_1c.wHour,(uint)local_1c.wMinute,(uint)local_1c.wSecond,-1);
        return lVar2;
      }
    }
  }
  return -1;
}



