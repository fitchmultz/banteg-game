/* mod_api_sfx_play_tune @ 0040e5f0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x6c: clAPI_t::SFX_PlayTune */

void mod_api_sfx_play_tune(int tuneId)

{
  sfx_play_exclusive(tuneId);
  return;
}



