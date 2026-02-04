/* quest_mode_update @ 004070e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* quest mode update: spawn timeline, stage completion, and transitions */

void quest_mode_update(void)

{
  uint uVar1;
  int iVar2;
  
  if ((console_open_flag != '\0') || (render_pass_mode == '\0')) goto LAB_00407129;
  uVar1 = creatures_none_active();
  if ((char)uVar1 == '\0') {
LAB_00407104:
    quest_spawn_timeline = quest_spawn_timeline + frame_dt_ms;
  }
  else {
    iVar2 = quest_spawn_table_empty();
    if ((char)iVar2 == '\0') goto LAB_00407104;
  }
  DAT_00487244 = DAT_00487244 + frame_dt_ms;
LAB_00407129:
  quest_spawn_timeline_update();
  if (demo_mode_active == '\0') {
    uVar1 = creatures_none_active();
    if ((char)uVar1 != '\0') {
      iVar2 = quest_spawn_table_empty();
      if ((char)iVar2 != '\0') {
        _bonus_reflex_boost_timer = 0;
        if (quest_transition_timer_ms < 0) {
          sfx_mute_all(music_track_extra_0);
          iVar2 = _quest_stage_minor + _quest_stage_major * 10;
          game_status_blob.quest_play_counts[iVar2 + 0x28] =
               game_status_blob.quest_play_counts[iVar2 + 0x28] + 1;
          quest_transition_timer_ms = frame_dt_ms;
          return;
        }
        if ((800 < quest_transition_timer_ms) && (quest_transition_timer_ms < 0x353)) {
          sfx_play(sfx_questhit);
          quest_transition_timer_ms = frame_dt_ms + 0x353;
          return;
        }
        if ((2000 < quest_transition_timer_ms) && (quest_transition_timer_ms < 0x803)) {
          quest_transition_timer_ms = 0x803;
          sfx_play_exclusive(music_track_crimsonquest_id);
          quest_transition_timer_ms = quest_transition_timer_ms + frame_dt_ms;
          sfx_volume_table[music_track_crimsonquest_id] = 0.0;
          return;
        }
        if (0x9c4 < quest_transition_timer_ms) {
          iVar2 = _quest_stage_minor + -10 + _quest_stage_major * 10;
          if (quest_unlock_index < iVar2) {
            quest_unlock_index = iVar2;
          }
          if ((config_blob.hardcore != '\0') && (quest_unlock_index_full < iVar2)) {
            quest_unlock_index_full = iVar2;
          }
          game_save_status();
          game_state_pending = 8;
          ui_transition_direction = 0;
          (*grim_interface_ptr->vtable->grim_flush_input)();
          console_input_poll();
          highscore_active_record.score_xp = 0;
        }
        quest_transition_timer_ms = quest_transition_timer_ms + frame_dt_ms;
      }
    }
  }
  return;
}



