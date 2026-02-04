/* console_cmd_exec @ 00401250 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* executes a script file via console_exec_line (exec command handler) */

void console_cmd_exec(void)

{
  FILE *fp;
  char *pcVar1;
  
  if (console_cmd_argc != 2) {
    console_printf(&console_log_queue,s_exec_<script>_0047118c);
    return;
  }
  fp = (FILE *)crt_fopen(console_cmd_arg1,&DAT_00471160);
  if (fp != (FILE *)0x0) {
    console_printf(&console_log_queue,s_Executing___s__00471164,console_cmd_arg1);
    pcVar1 = crt_fgets(&DAT_0047e848,0x1ff,(undefined4 *)fp);
    while (pcVar1 != (char *)0x0) {
      pcVar1 = _strchr(&DAT_0047e848,10);
      if (pcVar1 != (char *)0x0) {
        *pcVar1 = '\0';
      }
      DAT_0047ea47 = 0;
      if ((((DAT_0047e848 != '/') && (DAT_0047e849 != '/')) && (DAT_0047e848 != '\n')) &&
         ((DAT_0047e848 != '\0' && (DAT_0047e848 != '#')))) {
        console_exec_line(&console_log_queue,&DAT_0047e848);
      }
      pcVar1 = crt_fgets(&DAT_0047e848,0x1ff,(undefined4 *)fp);
    }
    crt_fclose(fp);
    return;
  }
  console_printf(&console_log_queue,s_Cannot_open_file___s__00471174,console_cmd_arg1);
  return;
}



