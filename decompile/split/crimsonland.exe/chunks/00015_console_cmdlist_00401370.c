/* console_cmdlist @ 00401370 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* prints registered command names and a count (cmdlist command handler) */

void console_cmdlist(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = console_command_list_head; puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    console_printf(&console_log_queue,&DAT_004711ac,*puVar1);
    iVar2 = iVar2 + 1;
  }
  console_printf(&console_log_queue,s__i_commands_0047119c,iVar2);
  return;
}



