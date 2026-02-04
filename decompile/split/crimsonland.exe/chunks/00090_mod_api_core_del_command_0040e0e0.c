/* mod_api_core_del_command @ 0040e0e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x14: clAPI_t::CORE_DelCommand */

uchar mod_api_core_del_command(char *id)

{
  uchar uVar1;
  
  uVar1 = console_command_unregister(&console_log_queue,id);
  return uVar1;
}



