/* console_cmd_minimize @ 00401360 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* minimizes console height (minimizeconsole command handler) */

void console_cmd_minimize(void)

{
  _console_height_px = 300;
  return;
}



