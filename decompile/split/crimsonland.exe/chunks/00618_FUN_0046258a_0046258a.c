/* FUN_0046258a @ 0046258a */

/* [binja] int32_t sub_46258a(int32_t arg1) */

int __cdecl FUN_0046258a(int arg1)

{
  char cVar1;
  UINT UVar2;
  
  if (arg1 != 0) {
    cVar1 = (char)arg1;
    arg1 = (int)CONCAT12(0x5c,CONCAT11(0x3a,cVar1 + '@'));
    UVar2 = GetDriveTypeA((LPCSTR)&arg1);
    if ((UVar2 == 0) || (UVar2 == 1)) {
      return 0;
    }
  }
  return 1;
}



