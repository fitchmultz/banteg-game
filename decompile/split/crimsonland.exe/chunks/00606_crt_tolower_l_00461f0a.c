/* crt_tolower_l @ 00461f0a */

/* CRT: tolower with locale */

int __thiscall crt_tolower_l(void *this,void *locale,int c)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  pvVar1 = locale;
  if (DAT_004d9a4c == 0) {
    if ((0x40 < (int)locale) && ((int)locale < 0x5b)) {
      pvVar1 = (void *)((int)locale + 0x20);
    }
  }
  else {
    iVar3 = 1;
    local_8 = this;
    if ((int)locale < 0x100) {
      if (DAT_0047b3cc < 2) {
        uVar2 = (byte)crt_ctype_table[(int)locale * 2] & 1;
      }
      else {
        uVar2 = crt_isctype(this,(int)locale,1);
      }
      if (uVar2 == 0) {
        return (int)pvVar1;
      }
    }
    if ((crt_ctype_table[((int)pvVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      locale = (void *)(CONCAT31((int3)((uint)locale >> 8),(char)pvVar1) & 0xffff00ff);
    }
    else {
      uVar2 = (uint)locale >> 0x10;
      locale._0_2_ = CONCAT11((char)pvVar1,(char)((uint)pvVar1 >> 8));
      locale = (void *)(CONCAT22((short)uVar2,locale._0_2_) & 0xff00ffff);
      iVar3 = 2;
    }
    iVar3 = crt_lcmap_string(DAT_004d9a4c,0x100,(char *)&locale,iVar3,(ushort *)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        pvVar1 = (void *)((uint)local_8 & 0xff);
      }
      else {
        pvVar1 = (void *)((uint)local_8 & 0xffff);
      }
    }
  }
  return (int)pvVar1;
}



