/* mod_api_core_get_var @ 0040e040 */

/* mod API vtable 0x04: clAPI_t::CORE_GetVar (returns a 3-pointer var_t view:
   id/stringValue/floatValue) */

mod_var_t * mod_api_core_get_var(char *id)

{
  undefined4 *puVar1;
  
  puVar1 = console_cvar_find(&console_log_queue,id);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = console_register_cvar(&console_log_queue,id,&DAT_0047125c);
  }
  puVar1[8] = puVar1 + 3;
  ((mod_var_t *)(puVar1 + 6))->id = (char *)*puVar1;
  puVar1[7] = puVar1[4];
  return (mod_var_t *)(puVar1 + 6);
}



