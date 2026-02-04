/* mod_api_sfx_play_sample @ 0040e570 */

/* mod API vtable 0x60: clAPI_t::SFX_PlaySample */

void mod_api_sfx_play_sample(int sfxId,float pan,float volume)

{
  sfx_play_panned((float)sfxId);
  return;
}



