/* FUN_0046b10e @ 0046b10e */

int __cdecl FUN_0046b10e(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  int *piVar2;
  
  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_004d9a4c == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_004d9a5c,0x220,&param_2,1,lpMultiByteStr,DAT_0047b3cc,(LPCCH)0x0
                                ,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  piVar2 = crt_errno_ptr();
  *piVar2 = 0x2a;
  return -1;
}



