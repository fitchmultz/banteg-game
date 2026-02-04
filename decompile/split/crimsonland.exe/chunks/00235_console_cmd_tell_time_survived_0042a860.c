/* console_cmd_tell_time_survived @ 0042a860 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* console command handler for telltimesurvived; prints survived time in seconds */

void console_cmd_tell_time_survived(void)

{
  longlong lVar1;
  
  lVar1 = __ftol();
  console_printf(&console_log_queue,s_Survived___i_seconds__00473f64,(int)lVar1);
  return;
}



