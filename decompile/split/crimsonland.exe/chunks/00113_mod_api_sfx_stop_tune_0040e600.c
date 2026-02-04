/* mod_api_sfx_stop_tune @ 0040e600 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x70: clAPI_t::SFX_StopTune */

void mod_api_sfx_stop_tune(int tuneId)

{
  sfx_mute_all(tuneId);
  return;
}



