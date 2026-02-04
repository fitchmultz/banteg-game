/* console_cmd_set @ 00401510 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* sets a cvar from tokens (set command handler) */

void console_cmd_set(void)

{
  undefined4 *puVar1;
  
  if (console_cmd_argc != 3) {
    console_printf(&console_log_queue,s_set_<var>_<value>_004711e4);
    return;
  }
  puVar1 = console_register_cvar(&console_log_queue,console_cmd_arg1,console_cmd_arg2);
  console_printf(&console_log_queue,s___s__set_to___s__004711d0,*puVar1,puVar1[4]);
  return;
}



