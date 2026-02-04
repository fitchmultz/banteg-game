/* console_cmd_quit @ 00401240 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* sets the quit/exit flag (quit command handler) */

void console_cmd_quit(void)

{
  DAT_0047ea50 = 1;
  return;
}



