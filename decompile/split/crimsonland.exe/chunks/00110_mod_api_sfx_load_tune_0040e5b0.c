/* mod_api_sfx_load_tune @ 0040e5b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x64: clAPI_t::SFX_LoadTune (loads under mods\\) */

int mod_api_sfx_load_tune(char *filename)

{
  int iVar1;
  char acStack_104 [260];
  
  crt_sprintf(acStack_104,s_mods__s_00472f58,filename);
  iVar1 = music_load_track(acStack_104);
  return iVar1;
}



