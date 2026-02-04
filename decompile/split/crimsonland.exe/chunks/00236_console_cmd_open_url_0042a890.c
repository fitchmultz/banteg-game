/* console_cmd_open_url @ 0042a890 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* console command handler for openurl; converts to wide and calls HlinkNavigateString */

void console_cmd_open_url(void)

{
  int iVar1;
  char *pcVar2;
  HRESULT HVar3;
  WCHAR *lpWideCharStr;
  int cchWideChar;
  WCHAR aWStack_208 [260];
  
  lpWideCharStr = aWStack_208;
  iVar1 = console_cmd_argc_get();
  if (iVar1 != 2) {
    console_printf(&console_log_queue,s_openurl_<url>_00473fbc);
    return;
  }
  cchWideChar = 0x104;
  iVar1 = -1;
  pcVar2 = console_cmd_arg_get(1);
  MultiByteToWideChar(0,0,pcVar2,iVar1,lpWideCharStr,cchWideChar);
  HVar3 = HlinkNavigateString((IUnknown *)0x0,aWStack_208);
  if (HVar3 < 0) {
    console_printf(&console_log_queue,s_Failed_to_launch_web_browser__00473f9c);
    return;
  }
  pcVar2 = console_cmd_arg_get(1);
  console_printf(&console_log_queue,s_Launching_web_browser___s____00473f7c,pcVar2);
  return;
}



