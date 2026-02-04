/* fpu_save_control_word @ 10020708 */

/* captures x87 FPU control word into DAT_1005db70 (used by DXT encode helpers) */

void __fastcall fpu_save_control_word(void)

{
  undefined4 in_ECX;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22((short)((uint)in_ECX >> 0x10),in_FPUControlWord);
  fpu_control_word_saved_dxt = local_8;
  return;
}



