/* mod_api_sfx_free_tune @ 0040e5e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x68: clAPI_t::SFX_FreeTune */

uchar mod_api_sfx_free_tune(int tuneId)

{
  int iVar1;
  
  iVar1 = music_release_track(tuneId);
  return (uchar)iVar1;
}



