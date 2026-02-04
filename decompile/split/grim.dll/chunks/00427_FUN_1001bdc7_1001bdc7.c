/* FUN_1001bdc7 @ 1001bdc7 */

/* [binja] int32_t __thiscall sub_1001bdc7(void** arg1, int32_t arg2, int32_t* arg3) */

int __thiscall FUN_1001bdc7(void *this,void **arg1,int arg2,int *arg3)

{
  int iVar1;
  HANDLE pvVar2;
  void **lpFileName;
  _OSVERSIONINFOA local_9c;
  undefined4 *local_8;
  
  if (arg1 == (void **)0x0) {
    return -0x7789f794;
  }
  lpFileName = arg1;
  local_8 = this;
  if (arg2 != 0) {
    local_9c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_9c);
    if (local_9c.dwPlatformId != 2) {
      lpFileName = (void **)&stack0xffffff58;
      iVar1 = WideCharToMultiByte(0,0,(LPCWCH)arg1,-1,(LPSTR)0x0,0,(LPCCH)0x0,(LPBOOL)0x0);
      FUN_1004b790();
      WideCharToMultiByte(0,0,(LPCWCH)arg1,-1,&stack0xffffff58,iVar1,(LPCCH)0x0,(LPBOOL)0x0);
      arg2 = 0;
      this = local_8;
    }
    if (arg2 != 0) {
      pvVar2 = CreateFileW((LPCWSTR)lpFileName,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0,
                           (HANDLE)0x0);
      goto LAB_1001be6e;
    }
  }
  pvVar2 = CreateFileA((LPCSTR)lpFileName,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
LAB_1001be6e:
  *(HANDLE *)this = pvVar2;
  if (pvVar2 == (HANDLE)0xffffffff) {
    GetLastError();
    iVar1 = -0x7789f4a7;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



