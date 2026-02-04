/* FUN_0046d1be @ 0046d1be */

/* [binja] int32_t sub_46d1be(char arg1, int32_t arg2, char arg3) */

int __cdecl FUN_0046d1be(char arg1,int arg2,char arg3)

{
  uint uVar1;
  
  if ((*(byte *)((int)&DAT_004da280 + (byte)arg1 + 1) & arg3) == 0) {
    if (arg2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (uint)*(ushort *)(&DAT_0047b1ca + (uint)(byte)arg1 * 2) & arg2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



