/* mod_api_inp_get_key_name @ 0040e680 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x80: clAPI_t::INP_GetKeyName */

char * mod_api_inp_get_key_name(int key)

{
  char *pcVar1;
  
  pcVar1 = input_key_name(key);
  return pcVar1;
}



