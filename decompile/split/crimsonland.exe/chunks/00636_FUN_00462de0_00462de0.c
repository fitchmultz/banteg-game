/* FUN_00462de0 @ 00462de0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_00462de0(void *this,byte *param_1,byte *param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  void *extraout_ECX;
  void *this_00;
  void *extraout_ECX_00;
  void *locale_00;
  uint c;
  void *locale;
  
  iVar3 = _DAT_004da3b0;
  if (DAT_004d9a4c == 0) {
    bVar6 = 0xff;
    do {
      do {
        cVar7 = '\0';
        if (bVar6 == 0) goto LAB_00462e2e;
        bVar6 = *param_2;
        param_2 = param_2 + 1;
        bVar5 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar5 == bVar6);
      bVar4 = bVar6 + 0xbf + (-((byte)(bVar6 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar5 = bVar5 + 0xbf;
      bVar6 = bVar5 + (-(bVar5 < 0x1a) & 0x20U) + 0x41;
    } while (bVar6 == bVar4);
    cVar7 = (bVar6 < bVar4) * -2 + '\x01';
LAB_00462e2e:
    locale = (void *)(int)cVar7;
  }
  else {
    LOCK();
    _DAT_004da3b0 = _DAT_004da3b0 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_004da3ac;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_004da3b0 = iVar3;
      crt_lock(0x13);
      this = extraout_ECX;
    }
    c = (uint)bVar1;
    locale = (void *)0xff;
    locale_00 = (void *)0x0;
    do {
      do {
        if ((char)locale == '\0') goto LAB_00462e8f;
        bVar6 = *param_2;
        locale = (void *)CONCAT31((int3)((uint)locale >> 8),bVar6);
        param_2 = param_2 + 1;
        bVar5 = *param_1;
        locale_00 = (void *)CONCAT31((int3)((uint)locale_00 >> 8),bVar5);
        param_1 = param_1 + 1;
      } while (bVar6 == bVar5);
      locale_00 = (void *)crt_tolower_l(this,locale_00,(int)locale);
      locale = (void *)crt_tolower_l(this_00,locale,c);
      this = extraout_ECX_00;
    } while ((byte)locale_00 == (byte)locale);
    uVar2 = (uint)((byte)locale_00 < (byte)locale);
    locale = (void *)((1 - uVar2) - (uint)(uVar2 != 0));
LAB_00462e8f:
    if (c == 0) {
      LOCK();
      _DAT_004da3b0 = _DAT_004da3b0 + -1;
      UNLOCK();
    }
    else {
      crt_unlock(0x13);
    }
  }
  return (uint)locale;
}



