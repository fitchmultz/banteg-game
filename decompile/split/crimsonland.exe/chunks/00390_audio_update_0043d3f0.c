/* audio_update @ 0043d3f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* updates sfx cooldowns, music streams, and mute fades */

void audio_update(void)

{
  float *pfVar1;
  music_entry_t *entry;
  
  if (config_blob.reserved0[0] == '\0') {
    pfVar1 = sfx_cooldown_table;
    do {
      if (0.0 < *pfVar1) {
        *pfVar1 = *pfVar1 - _DAT_0047ea48;
      }
      pfVar1 = pfVar1 + 1;
    } while ((int)pfVar1 < 0x4c3e80);
    if (sfx_unmuted_flag != '\0') {
      entry = &music_entry_table;
      do {
        if (entry->vorbis_stream != (void *)0x0) {
          music_stream_update((int)entry);
        }
        entry = entry + 1;
      } while ((int)entry < 0x4c8450);
      sfx_update_mute_fades();
    }
  }
  return;
}



