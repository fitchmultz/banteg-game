/* sfx_play_exclusive @ 0043d460 */

/* mutes other sfx ids and ensures the chosen id is audible */

void __cdecl sfx_play_exclusive(int sfx_id)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  if (((sfx_unmuted_flag != '\0') && (config_blob.reserved0[1] == '\0')) &&
     (config_blob.reserved0[0] == '\0')) {
    if (DAT_004824d1 == '\0') {
      if (sfx_id == music_track_extra_0) {
        if (DAT_004cc8d4 != '\0') {
          return;
        }
        if (DAT_004cc8d0 == 0) {
          return;
        }
        iVar2 = crt_rand();
        DAT_004cc8d4 = '\x01';
        sfx_id = music_playlist[iVar2 % DAT_004cc8d0];
      }
      else {
        DAT_004cc8d4 = '\0';
      }
    }
    iVar2 = 0;
    do {
      if ((iVar2 != sfx_id) && (iVar3 = sfx_is_unmuted(iVar2), (char)iVar3 != '\0')) {
        sfx_mute_all(iVar2);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x80);
    if (sfx_volume_table[sfx_id] <= 0.0) {
      sfx_entry_start_playback((int)(&music_entry_table + sfx_id));
      sfx_entry_set_volume((int)(&music_entry_table + sfx_id),config_blob.music_volume);
      fVar1 = config_blob.music_volume;
      sfx_mute_flags[sfx_id] = '\0';
      sfx_volume_table[sfx_id] = fVar1;
    }
  }
  return;
}



