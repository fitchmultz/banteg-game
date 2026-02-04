/* FUN_0043aa60 @ 0043aa60 */

undefined4 FUN_0043aa60(void)

{
  int iVar1;
  uint3 extraout_var;
  
  iVar1 = game_is_full_version();
  if ((char)iVar1 == '\0') {
    console_printf(&console_log_queue,s___Potentially_illegal_score_dete_00477b16 + 2);
    iVar1 = (uint)extraout_var << 8;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}



