/* console_cmd_extend @ 00401340 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* extends console height (extendconsole command handler) */

void console_cmd_extend(void)

{
  longlong lVar1;
  
  lVar1 = __ftol();
  _console_height_px = (int)lVar1;
  return;
}



