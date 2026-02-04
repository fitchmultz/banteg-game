/* quest_start_selected @ 0043a790 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* resets quest state, selects quest metadata, and runs its builder */

void __cdecl quest_start_selected(int tier,int index)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_004281e0();
  quest_spawn_count = 0;
  quest_spawn_timeline = 0;
  DAT_00487244 = 0;
  fx_queue_rotated = 0;
  fx_queue_count = 0;
  highscore_active_record.full_version_marker = '\0';
  highscore_active_record.survival_elapsed_ms = 0;
  highscore_active_record.score_xp = 0;
  highscore_active_record.quest_stage_minor = '\0';
  highscore_active_record.quest_stage_major = '\0';
  highscore_active_record.game_mode_id = '\0';
  highscore_active_record.most_used_weapon_id = '\0';
  highscore_active_record.creature_kill_count = 0;
  highscore_active_record.shots_hit = 0;
  highscore_active_record.shots_fired = 0;
  highscore_active_record.date_checksum = '\0';
  highscore_active_record.year_offset = '\0';
  highscore_active_record.month = '\0';
  highscore_active_record.day = '\0';
  highscore_active_record.flags = '\0';
  uVar1 = crt_rand();
  highscore_active_record.reserved0._0_4_ = uVar1 & 0xfee050f;
  projectile_reset_pools();
  player_state_table.pos_x = (float)terrain_texture_width * 0.5;
  player_state_table.pos_y = (float)terrain_texture_height * 0.5;
  iVar4 = index + -0xb + tier * 10;
  terrain_generate(&quest_selected_meta + iVar4);
  weapon_assign_player(0,(&quest_selected_meta)[iVar4].start_weapon_id);
  weapon_assign_player(1,(&quest_selected_meta)[iVar4].start_weapon_id);
  console_printf(&console_log_queue,s_Setup_tier__d_quest__d__00477aec,tier,index);
  if ((&quest_selected_meta)[iVar4].builder == (quest_builder_fn_t)0x0) {
    quest_build_fallback(&quest_spawn_table,&quest_spawn_count);
  }
  else {
    (*(&quest_selected_meta)[iVar4].builder)(&quest_spawn_table,&quest_spawn_count);
  }
  iVar6 = 0;
  iVar4 = 0;
  _DAT_00486fd4 = 0;
  _DAT_00487030 = 0;
  if (0 < quest_spawn_count) {
    piVar2 = &quest_spawn_table.pos_y_block.heading_block.count;
    iVar3 = quest_spawn_count;
    do {
      if (((config_blob.hardcore != '\0') && (iVar5 = *piVar2, 1 < iVar5)) && (piVar2[-2] != 0x3c))
      {
        if (piVar2[-2] == 0x2b) {
          iVar5 = iVar5 + 2;
        }
        else {
          iVar5 = iVar5 + 8;
        }
        *piVar2 = iVar5;
      }
      iVar6 = iVar6 + *piVar2;
      if (iVar4 < piVar2[-1]) {
        iVar4 = piVar2[-1];
      }
      piVar2 = piVar2 + 6;
      iVar3 = iVar3 + -1;
      _DAT_00486fd4 = iVar6;
      _DAT_00487030 = iVar4;
    } while (iVar3 != 0);
  }
  return;
}



