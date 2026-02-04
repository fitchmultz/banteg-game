/* mod_api_core_add_command @ 0040e0c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x10: clAPI_t::CORE_AddCommand */

void mod_api_core_add_command(char *id,void *cmd)

{
  console_register_command(&console_log_queue,id,cmd);
  return;
}



