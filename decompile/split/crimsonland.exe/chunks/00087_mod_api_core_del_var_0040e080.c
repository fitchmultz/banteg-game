/* mod_api_core_del_var @ 0040e080 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x08: clAPI_t::CORE_DelVar */

uchar mod_api_core_del_var(char *id)

{
  uchar uVar1;
  
  uVar1 = console_cvar_unregister(&console_log_queue,id);
  return uVar1;
}



