/* mod_api_gfx_load_texture @ 0040e280 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x28: clAPI_t::GFX_LoadTexture (loads under mods\\ and prefixes CLM_) */

int mod_api_gfx_load_texture(char *filename)

{
  int iVar1;
  char acStack_208 [260];
  char acStack_104 [260];
  
  crt_sprintf(acStack_208,s_mods__s_00472f58,filename);
  crt_sprintf(acStack_104,s_CLM__s_00472f50,filename);
  iVar1 = texture_get_or_load(acStack_104,acStack_208);
  return iVar1;
}



