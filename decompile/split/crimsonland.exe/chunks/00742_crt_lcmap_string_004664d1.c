/* crt_lcmap_string @ 004664d1 */

/* CRT: LCMapString wrapper with multibyte/Unicode handling */

int __cdecl
crt_lcmap_string(uint locale,uint flags,char *src,int srclen,ushort *dst,int dstlen,uint codepage,
                int use_cp)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0046fbd0;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_004d9a64 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,&DAT_004ab1a8,1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_004d9a64 = 2;
    }
    else {
      DAT_004d9a64 = 1;
    }
  }
  if (0 < srclen) {
    srclen = FUN_0046e5ec(src,srclen);
  }
  if (DAT_004d9a64 == 2) {
    iVar1 = LCMapStringA(locale,flags,src,srclen,(LPSTR)dst,dstlen);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_004d9a64 == 1) {
    if (codepage == 0) {
      codepage = DAT_004d9a5c;
    }
    iVar1 = MultiByteToWideChar(codepage,(-(uint)(use_cp != 0) & 8) + 1,src,srclen,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      local_8 = 0;
      crt_chkstk();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (iVar2 = MultiByteToWideChar(codepage,1,src,srclen,(LPWSTR)&stack0xffffffc4,iVar1),
         iVar2 != 0)) {
        iVar2 = LCMapStringW(locale,flags,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          if ((flags & 0x400) == 0) {
            local_8 = 1;
            crt_chkstk();
            local_8 = 0xffffffff;
            if (&stack0x00000000 == (undefined1 *)0x3c) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(locale,flags,(LPCWSTR)&stack0xffffffc4,iVar1,
                                 (LPWSTR)&stack0xffffffc4,iVar2);
            if (iVar1 == 0) {
              ExceptionList = local_14;
              return 0;
            }
            if (dstlen == 0) {
              dstlen = 0;
              dst = (ushort *)0x0;
            }
            iVar2 = WideCharToMultiByte(codepage,0x220,(LPCWCH)&stack0xffffffc4,iVar2,(LPSTR)dst,
                                        dstlen,(LPCCH)0x0,(LPBOOL)0x0);
            iVar1 = iVar2;
          }
          else {
            if (dstlen == 0) {
              ExceptionList = local_14;
              return iVar2;
            }
            if (dstlen < iVar2) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(locale,flags,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)dst,dstlen);
          }
          if (iVar1 != 0) {
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}



