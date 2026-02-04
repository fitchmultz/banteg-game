/* FUN_0046e301 @ 0046e301 */

/* [binja] int32_t sub_46e301() */

int FUN_0046e301(void)

{
  LPCWCH lpWideCharStr;
  size_t _Size;
  char *lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;
  
  lpWideCharStr = (LPCWCH)*DAT_004d99a8;
  puVar2 = DAT_004d99a8;
  while( true ) {
    if (lpWideCharStr == (LPCWCH)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCCH)0x0,(LPBOOL)0x0);
    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (char *)0x0)) ||
       (iVar1 = WideCharToMultiByte(1,0,(LPCWCH)*puVar2,-1,lpMultiByteStr,_Size,(LPCCH)0x0,
                                    (LPBOOL)0x0), iVar1 == 0)) break;
    FUN_0046e617(lpMultiByteStr,0);
    lpWideCharStr = (LPCWCH)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return -1;
}



