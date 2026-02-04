/* mod_api_core_execute @ 0040e0a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x0c: clAPI_t::CORE_Execute */

void mod_api_core_execute(char *string)

{
  console_exec_line(&console_log_queue,string);
  return;
}



