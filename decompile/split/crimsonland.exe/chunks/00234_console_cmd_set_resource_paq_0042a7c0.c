/* console_cmd_set_resource_paq @ 0042a7c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* console command handler for setresourcepaq; validates file and updates Grim config id 0x10 */

void console_cmd_set_resource_paq(void)

{
  int iVar1;
  char *pcVar2;
  FILE *fp;
  uint in_stack_ffffffec;
  char *pcVar3;
  
  iVar1 = console_cmd_argc_get();
  if (iVar1 != 2) {
    console_printf(&console_log_queue,s_setresourcepaq_<resourcepaq>_00473f44);
    return;
  }
  pcVar3 = &file_mode_read_binary;
  pcVar2 = console_cmd_arg_get(1);
  fp = (FILE *)crt_fopen(pcVar2,pcVar3);
  if (fp == (FILE *)0x0) {
    pcVar2 = console_cmd_arg_get(1);
    console_printf(&console_log_queue,s_File___s__not_found__00473f2c,pcVar2);
    return;
  }
  crt_fclose(fp);
  console_cmd_arg_get(1);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x10,in_stack_ffffffec);
  pcVar2 = console_cmd_arg_get(1);
  console_printf(&console_log_queue,s_Set_resource_paq_to___s__00473f10,pcVar2);
  return;
}



