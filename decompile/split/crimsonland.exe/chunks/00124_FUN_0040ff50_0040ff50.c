/* FUN_0040ff50 @ 0040ff50 */

/* [binja] int32_t sub_40ff50(int32_t arg1) */

int __cdecl FUN_0040ff50(int arg1)

{
  int iVar1;
  
  iVar1 = arg1 % 0x3c;
  if (iVar1 < 10) {
    crt_sprintf(&DAT_00482624,s__d_0_d_00473150,arg1 / 0x3c,iVar1);
    return 0x482624;
  }
  crt_sprintf(&DAT_00482624,s__d__d_00473148,arg1 / 0x3c,iVar1);
  return 0x482624;
}



