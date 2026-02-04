/* FUN_0046c5db @ 0046c5db */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046c5db(void)

{
  byte bVar1;
  byte bVar2;
  char *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  void *this;
  byte *_Source;
  int local_8;
  
  crt_lock(0xc);
  DAT_0047df18 = 0xffffffff;
  DAT_0047df08 = 0xffffffff;
  DAT_004d9b90 = 0;
  _Str1 = (char *)FUN_0046e0d7("TZ");
  if (_Str1 == (char *)0x0) {
    crt_unlock(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_004d9b98);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_0047de70 = (void *)(DAT_004d9b98 * 0x3c);
    DAT_004d9b90 = 1;
    if (DAT_004d9bde != 0) {
      DAT_0047de70 = (void *)((int)DAT_0047de70 + DAT_004d9bec * 0x3c);
    }
    if ((DAT_004d9c32 == 0) || (DAT_004d9c40 == 0)) {
      DAT_0047de74 = 0;
      _DAT_0047de78 = 0;
    }
    else {
      DAT_0047de74 = 1;
      _DAT_0047de78 = (DAT_004d9c40 - DAT_004d9bec) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_004d9a5c,0x220,(LPCWCH)&DAT_004d9b9c,-1,PTR_DAT_0047defc,0x3f,
                                (LPCCH)0x0,&local_8);
    if ((iVar4 == 0) || (local_8 != 0)) {
      *PTR_DAT_0047defc = 0;
    }
    else {
      PTR_DAT_0047defc[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_004d9a5c,0x220,(LPCWCH)&DAT_004d9bf0,-1,PTR_DAT_0047df00,0x3f,
                                (LPCCH)0x0,&local_8);
    if ((iVar4 != 0) && (local_8 == 0)) {
      PTR_DAT_0047df00[0x3f] = 0;
      return;
    }
LAB_0046c84c:
    *PTR_DAT_0047df00 = 0;
  }
  else {
    if ((*_Str1 != '\0') &&
       ((DAT_004d9c44 == (char *)0x0 || (iVar4 = _strcmp(_Str1,DAT_004d9c44), iVar4 != 0)))) {
      crt_free_base(DAT_004d9c44);
      sVar5 = _strlen(_Str1);
      DAT_004d9c44 = _malloc(sVar5 + 1);
      if (DAT_004d9c44 != (char *)0x0) {
        crt_strcpy(DAT_004d9c44,_Str1);
        crt_unlock(0xc);
        _strncpy(PTR_DAT_0047defc,_Str1,3);
        _Source = (byte *)(_Str1 + 3);
        PTR_DAT_0047defc[3] = 0;
        bVar1 = *_Source;
        if (bVar1 == 0x2d) {
          _Source = (byte *)(_Str1 + 4);
        }
        iVar4 = FUN_00460dd2(this,_Source);
        DAT_0047de70 = (void *)(iVar4 * 0xe10);
        for (; (bVar2 = *_Source, bVar2 == 0x2b || (('/' < (char)bVar2 && ((char)bVar2 < ':'))));
            _Source = _Source + 1) {
        }
        if (*_Source == 0x3a) {
          _Source = _Source + 1;
          iVar4 = FUN_00460dd2(DAT_0047de70,_Source);
          DAT_0047de70 = (void *)((int)DAT_0047de70 + iVar4 * 0x3c);
          for (; ('/' < (char)*_Source && ((char)*_Source < ':')); _Source = _Source + 1) {
          }
          if (*_Source == 0x3a) {
            _Source = _Source + 1;
            iVar4 = FUN_00460dd2(DAT_0047de70,_Source);
            DAT_0047de70 = (void *)((int)DAT_0047de70 + iVar4);
            for (; ('/' < (char)*_Source && ((char)*_Source < ':')); _Source = _Source + 1) {
            }
          }
        }
        if (bVar1 == 0x2d) {
          DAT_0047de70 = (void *)-(int)DAT_0047de70;
        }
        DAT_0047de74 = (int)(char)*_Source;
        if (DAT_0047de74 != 0) {
          _strncpy(PTR_DAT_0047df00,(char *)_Source,3);
          PTR_DAT_0047df00[3] = 0;
          return;
        }
        goto LAB_0046c84c;
      }
    }
    crt_unlock(0xc);
  }
  return;
}



