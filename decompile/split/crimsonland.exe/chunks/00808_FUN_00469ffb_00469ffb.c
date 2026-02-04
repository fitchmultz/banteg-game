/* FUN_00469ffb @ 00469ffb */

/* [binja] int32_t sub_469ffb(int32_t arg1, int32_t arg2) */

int __cdecl FUN_00469ffb(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(arg1 + (arg2 / 0x20) * 4);
  iVar1 = crt_add_u32_carry(*puVar3,1 << (0x1fU - (char)(arg2 % 0x20) & 0x1f),puVar3);
  iVar2 = arg2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (uint *)(arg1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = crt_add_u32_carry(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return iVar1;
}



