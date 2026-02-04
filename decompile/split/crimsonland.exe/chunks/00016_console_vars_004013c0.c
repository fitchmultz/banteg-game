/* console_vars @ 004013c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* prints registered cvar names and a count (vars command handler) */

void console_vars(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = console_log_queue; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[1]) {
    console_printf(&console_log_queue,&DAT_004711ac,*puVar1);
    iVar2 = iVar2 + 1;
  }
  console_printf(&console_log_queue,s__i_variables_004711b0,iVar2);
  return;
}



