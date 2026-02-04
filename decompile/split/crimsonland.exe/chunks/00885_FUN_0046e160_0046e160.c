/* FUN_0046e160 @ 0046e160 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_46e160(char* arg1, char* arg2, int32_t arg3) */

int __cdecl FUN_0046e160(char *arg1,char *arg2,int arg3)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  void *locale;
  int iVar6;
  void *this;
  void *locale_00;
  bool bVar7;
  
  iVar2 = _DAT_004da3b0;
  iVar6 = 0;
  if (arg3 != 0) {
    if (DAT_004d9a4c == 0) {
      do {
        bVar3 = *arg1;
        cVar1 = *arg2;
        uVar4 = CONCAT11(bVar3,cVar1);
        if (bVar3 == 0) break;
        uVar4 = CONCAT11(bVar3,cVar1);
        uVar5 = (uint)uVar4;
        if (cVar1 == '\0') break;
        arg1 = (char *)((byte *)arg1 + 1);
        arg2 = arg2 + 1;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar5 = (uint)CONCAT11(bVar3 + 0x20,cVar1);
        }
        uVar4 = (ushort)uVar5;
        bVar3 = (byte)uVar5;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar4 = (ushort)CONCAT31((int3)(uVar5 >> 8),bVar3 + 0x20);
        }
        bVar3 = (byte)(uVar4 >> 8);
        bVar7 = bVar3 < (byte)uVar4;
        if (bVar3 != (byte)uVar4) goto LAB_0046e1bf;
        arg3 = arg3 + -1;
      } while (arg3 != 0);
      iVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar7 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_0046e1bf:
        iVar6 = -1;
        if (!bVar7) {
          iVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_004da3b0 = _DAT_004da3b0 + 1;
      UNLOCK();
      bVar7 = 0 < DAT_004da3ac;
      if (bVar7) {
        LOCK();
        UNLOCK();
        _DAT_004da3b0 = iVar2;
        crt_lock(0x13);
      }
      uVar5 = (uint)bVar7;
      locale = (void *)0x0;
      locale_00 = (void *)0x0;
      do {
        locale = (void *)CONCAT31((int3)((uint)locale >> 8),*arg1);
        locale_00 = (void *)CONCAT31((int3)((uint)locale_00 >> 8),*arg2);
        if ((locale == (void *)0x0) || (locale_00 == (void *)0x0)) break;
        arg1 = arg1 + 1;
        arg2 = arg2 + 1;
        locale_00 = (void *)crt_tolower_l((void *)arg3,locale_00,(int)locale);
        locale = (void *)crt_tolower_l(this,locale,arg3);
        bVar7 = locale < locale_00;
        if (locale != locale_00) goto LAB_0046e235;
        arg3 = arg3 + -1;
      } while ((void *)arg3 != (void *)0x0);
      iVar6 = 0;
      bVar7 = locale < locale_00;
      if (locale != locale_00) {
LAB_0046e235:
        iVar6 = -1;
        if (!bVar7) {
          iVar6 = 1;
        }
      }
      if (uVar5 == 0) {
        LOCK();
        _DAT_004da3b0 = _DAT_004da3b0 + -1;
        UNLOCK();
      }
      else {
        crt_unlock(0x13);
      }
    }
  }
  return iVar6;
}



