/* mod_api_sfx_free_sample @ 0040e560 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x5c: clAPI_t::SFX_FreeSample */

uchar mod_api_sfx_free_sample(int sfxId)

{
  int iVar1;
  
  iVar1 = sfx_release_sample(sfxId);
  return (uchar)iVar1;
}



