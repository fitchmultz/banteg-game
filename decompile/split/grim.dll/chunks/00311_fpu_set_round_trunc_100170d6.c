/* fpu_set_round_trunc @ 100170d6 */

/* sets x87 rounding mode to truncate; saves control word in DAT_1005db6c */

void __fastcall fpu_set_round_trunc(void)

{
  undefined4 in_ECX;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22((short)((uint)in_ECX >> 0x10),in_FPUControlWord);
  DAT_1005db6c = local_8;
  return;
}



