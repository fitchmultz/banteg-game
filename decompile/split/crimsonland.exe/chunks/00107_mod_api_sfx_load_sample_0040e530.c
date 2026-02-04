/* mod_api_sfx_load_sample @ 0040e530 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x58: clAPI_t::SFX_LoadSample (loads under mods\\) */

int mod_api_sfx_load_sample(char *filename)

{
  int iVar1;
  char acStack_104 [260];
  
  crt_sprintf(acStack_104,s_mods__s_00472f58,filename);
  iVar1 = sfx_load_sample(acStack_104);
  return iVar1;
}



