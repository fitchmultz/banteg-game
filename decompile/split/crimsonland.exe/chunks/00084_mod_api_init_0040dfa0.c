/* mod_api_init @ 0040dfa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* initializes the mod API context (writes mod_api_context.vtable = &mod_api_vtable at 0x0046f3e4;
   see cl_mod_sdk_v1/ClMod.h) */

void mod_api_init(void)

{
  mod_api_context.vtable = &mod_api_vtable;
  _DAT_00481ae8 = 1;
  return;
}



