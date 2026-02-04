/* crt_isctype @ 00463c74 */

/* ctype classification (MBCS via GetStringTypeA/W) */

uint __thiscall crt_isctype(void *this,int c,uint mask)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (c + 1U < 0x101) {
    c._2_2_ = *(ushort *)(crt_ctype_table + c * 2);
  }
  else {
    if ((crt_ctype_table[(c >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)c) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)c,(char)((uint)c >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_0046a8ce(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&c + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return c._2_2_ & mask;
}



