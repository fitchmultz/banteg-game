/* FUN_0041db50 @ 0041db50 */

/* [binja] int32_t sub_41db50(uint32_t arg1, int32_t* arg2) */

int __cdecl FUN_0041db50(uint arg1,int *arg2)

{
  uint lptstrFilename;
  int *piVar1;
  void *lpData;
  WINBOOL WVar2;
  DWORD local_4;
  
  piVar1 = arg2;
  lptstrFilename = arg1;
  if ((arg1 == 0) || (arg2 == (int *)0x0)) {
    return -0x7ff8ffa9;
  }
  arg1 = GetFileVersionInfoSizeA((LPCSTR)arg1,&local_4);
  if (arg1 != 0) {
    lpData = operator_new(arg1);
    if (lpData == (void *)0x0) {
      return -0x7ff8fff2;
    }
    WVar2 = GetFileVersionInfoA((LPCSTR)lptstrFilename,0,arg1,lpData);
    if (WVar2 != 0) {
      arg2 = (int *)0x0;
      WVar2 = VerQueryValueA(lpData,&DAT_004739b8,&arg2,&arg1);
      if ((WVar2 != 0) && (arg2 != (int *)0x0)) {
        piVar1[1] = arg2[2];
        *piVar1 = arg2[3];
        crt_free(lpData);
        return 0;
      }
    }
    crt_free(lpData);
  }
  return -0x7fffbffb;
}



