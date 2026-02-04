/* audio_resume_channels @ 0043d770 */

/* iterates channels and resumes playback */

void audio_resume_channels(void)

{
  music_entry_t *entry;
  int iVar1;
  
  if (((sfx_unmuted_flag != '\0') && (config_blob.reserved0[1] == '\0')) &&
     (config_blob.reserved0[0] == '\0')) {
    iVar1 = 0;
    entry = &music_entry_table;
    do {
      if (sfx_mute_flags[iVar1] == '\0') {
        sfx_entry_resume((int)entry);
      }
      entry = entry + 1;
      iVar1 = iVar1 + 1;
    } while ((int)entry < 0x4c8450);
  }
  return;
}



