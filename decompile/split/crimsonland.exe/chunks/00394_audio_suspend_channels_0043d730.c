/* audio_suspend_channels @ 0043d730 */

/* iterates channels and suspends playback */

void audio_suspend_channels(void)

{
  music_entry_t *entry;
  
  if (((sfx_unmuted_flag != '\0') && (config_blob.reserved0[1] == '\0')) &&
     (config_blob.reserved0[0] == '\0')) {
    entry = &music_entry_table;
    do {
      sfx_entry_stop((int)entry);
      entry = entry + 1;
    } while ((int)entry < 0x4c8450);
  }
  return;
}



