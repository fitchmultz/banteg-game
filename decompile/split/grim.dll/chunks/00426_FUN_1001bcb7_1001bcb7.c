/* FUN_1001bcb7 @ 1001bcb7 */

/* [binja] int32_t __thiscall sub_1001bcb7(int32_t* arg1, int32_t* arg2, int32_t* arg3) */

int __thiscall FUN_1001bcb7(void *this,int *arg1,int *arg2,int *arg3)

{
  HANDLE pvVar1;
  LPVOID pvVar2;
  DWORD DVar3;
  _OSVERSIONINFOA local_9c;
  int local_8;
  
  if (arg1 == (int *)0x0) {
    return -0x7789f794;
  }
  if (arg2 != (int *)0x0) {
    local_9c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_9c);
    if (local_9c.dwPlatformId != 2) {
      local_8 = WideCharToMultiByte(0,0,(LPCWCH)arg1,-1,(LPSTR)0x0,0,(LPCCH)0x0,(LPBOOL)0x0);
      FUN_1004b790();
      WideCharToMultiByte(0,0,(LPCWCH)arg1,-1,&stack0xffffff58,local_8,(LPCCH)0x0,(LPBOOL)0x0);
      arg2 = (int *)0x0;
      arg1 = (int *)&stack0xffffff58;
    }
    if (arg2 != (int *)0x0) {
      pvVar1 = CreateFileW((LPCWSTR)arg1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x10000000,
                           (HANDLE)0x0);
      goto LAB_1001bd6b;
    }
  }
  pvVar1 = CreateFileA((LPCSTR)arg1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x10000000,(HANDLE)0x0
                      );
LAB_1001bd6b:
  *(HANDLE *)this = pvVar1;
  if (pvVar1 != (HANDLE)0xffffffff) {
    pvVar1 = CreateFileMappingA(pvVar1,(LPSECURITY_ATTRIBUTES)0x0,2,0,0,(LPCSTR)0x0);
    *(HANDLE *)((int)this + 4) = pvVar1;
    if (pvVar1 != (HANDLE)0xffffffff) {
      pvVar2 = MapViewOfFile(pvVar1,4,0,0,0);
      *(LPVOID *)((int)this + 8) = pvVar2;
      if (pvVar2 != (LPVOID)0x0) {
        DVar3 = GetFileSize(*(HANDLE *)this,(LPDWORD)0x0);
        *(DWORD *)((int)this + 0xc) = DVar3;
        if (DVar3 != 0xffffffff) {
          return 0;
        }
      }
    }
  }
  GetLastError();
  return -0x7789f4a7;
}



