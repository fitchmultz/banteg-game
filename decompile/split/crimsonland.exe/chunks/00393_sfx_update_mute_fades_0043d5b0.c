/* sfx_update_mute_fades @ 0043d5b0 */

/* ramps volume up/down based on mute flags */

void sfx_update_mute_fades(void)

{
  float fVar1;
  int iVar2;
  music_entry_t *entry;
  float *pfVar3;
  float volume;
  byte abStack_4 [4];
  
  if ((audio_suspend_flag == '\0') && (sfx_unmuted_flag != '\0')) {
    iVar2 = 0;
    pfVar3 = sfx_volume_table;
    entry = &music_entry_table;
    do {
      if (entry->vorbis_stream != (void *)0x0) {
        if (0.0 < config_blob.music_volume) {
          if (sfx_mute_flags[iVar2] == '\0') {
            (**(code **)(*(int *)entry->buffers[0] + 0x24))(entry->buffers[0],abStack_4);
            if ((abStack_4[0] & 1) == 0) {
              console_printf(&console_log_queue,s_SND__detected_unsilenced_hearabl_00478610);
              sfx_entry_resume((int)entry);
            }
            goto LAB_0043d63c;
          }
        }
        else {
          (**(code **)(*(int *)entry->buffers[0] + 0x48))(entry->buffers[0]);
LAB_0043d63c:
          fVar1 = config_blob.music_volume;
          if (sfx_mute_flags[iVar2] == '\0') {
            if (config_blob.music_volume <= *pfVar3) {
              if (*pfVar3 <= config_blob.music_volume) goto LAB_0043d709;
              *pfVar3 = config_blob.music_volume;
LAB_0043d6ff:
              volume = fVar1;
            }
            else {
              volume = frame_dt + *pfVar3;
              *pfVar3 = volume;
              fVar1 = config_blob.music_volume;
              if (config_blob.music_volume <= volume) goto LAB_0043d6ff;
            }
            sfx_entry_set_volume((int)entry,volume);
            goto LAB_0043d709;
          }
        }
        if (0.0 < *pfVar3) {
          fVar1 = *pfVar3 - frame_dt * 0.5;
          *pfVar3 = fVar1;
          if (0.0 < fVar1) {
            sfx_entry_set_volume((int)entry,fVar1);
          }
          else {
            sfx_entry_stop((int)entry);
          }
        }
        if (*pfVar3 < 0.0) {
          *pfVar3 = 0.0;
        }
      }
LAB_0043d709:
      entry = entry + 1;
      iVar2 = iVar2 + 1;
      pfVar3 = pfVar3 + 1;
    } while ((int)entry < 0x4c8450);
  }
  return;
}



