/* audio_init_music @ 0043c9c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* loads music pack and registers music track ids */

void audio_init_music(void)

{
  int iVar1;
  float *pfVar2;
  char *pcVar3;
  
  if ((config_blob.reserved0[0] == '\0') && (config_blob.reserved0[1] == '\0')) {
    iVar1 = 0x20;
    pcVar3 = sfx_mute_flags;
    while (iVar1 != 0) {
      iVar1 = iVar1 + -1;
      builtin_strncpy(pcVar3,"\x01\x01\x01\x01",4);
      pcVar3 = pcVar3 + 4;
    }
    pfVar2 = sfx_volume_table;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *pfVar2 = 0.0;
      pfVar2 = pfVar2 + 1;
    }
    iVar1 = resource_pack_set(s_music_paq_00477eec);
    DAT_004cc8d5 = (char)iVar1;
    if (DAT_004cc8d5 == '\0') {
      pcVar3 = s____resource_paq__music_paq__not_f_00477e84;
    }
    else {
      pcVar3 = s____set_sound_resource_paq__music_00477ec4;
    }
    console_printf(&console_log_queue,pcVar3);
    music_track_intro_id = music_load_track(s_music_intro_ogg_00477e74);
    music_track_shortie_monk_id = music_load_track(s_music_shortie_monk_ogg_00477e5c);
    console_exec_line(&console_log_queue,s_exec_music_game_tunes_txt_00477e40);
    music_track_crimson_theme_id = music_load_track(s_music_crimson_theme_ogg_00477e28);
    music_track_crimsonquest_id = music_load_track(s_music_crimsonquest_ogg_00477e10);
    music_track_extra_0 = music_track_crimsonquest_id + 1;
    _music_track_extra_1 = music_track_crimsonquest_id + 2;
    sfx_unmuted_flag = 1;
  }
  return;
}



