/* game_over_screen_update @ 0040ffc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* game over flow: high score entry, results text, and navigation buttons */

void game_over_screen_update(void)

{
  char cVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  highscore_record_t *phVar9;
  undefined4 *puVar10;
  char *pcVar11;
  highscore_record_t *phVar12;
  longlong lVar13;
  int y;
  int w;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (((byte)game_over_screen_flags & 1) == 0) {
    game_over_screen_flags._0_1_ = (byte)game_over_screen_flags | 1;
    DAT_004825ae = 1;
    DAT_004825bd = 0;
    DAT_004825bc = 0;
    _DAT_004825b8 = 0x3f800000;
    _DAT_004825b4 = 0;
    _DAT_004825a8 = (undefined *)0x0;
    DAT_004825ac = 0;
    DAT_004825ad = '\0';
    _DAT_004825b0 = 0;
    crt_atexit(&DAT_004107d0);
  }
  if (((byte)game_over_screen_flags & 2) == 0) {
    game_over_screen_flags._0_1_ = (byte)game_over_screen_flags | 2;
    _DAT_004825a0 = 0x3f800000;
    _DAT_00482590 = &DAT_0048256c;
    DAT_00482594 = 0;
    _DAT_00482598 = 0x18;
    _DAT_0048259c = 0x60;
    crt_atexit(&DAT_004107c0);
  }
  _bonus_reflex_boost_timer = 0;
  if ((ui_transition_direction != '\0') && (highscore_return_latch != '\0')) {
    highscore_return_latch = '\0';
    ui_screen_phase = 1;
  }
  if ((((game_state_id == 7) && (game_state_pending == 0x19)) && (ui_transition_direction != '\0'))
     && (iVar3 = sfx_is_unmuted(music_track_shortie_monk_id), (char)iVar3 == '\0')) {
    sfx_play_exclusive(music_track_shortie_monk_id);
  }
  gameplay_render_world();
  ui_elements_update_and_render();
  perk_prompt_update_and_render();
  local_4 = _DAT_0048cc64 + DAT_0048cc88;
  local_10 = DAT_0048cc84 + _DAT_0048cc60 + 180.0;
  fVar2 = local_4 + 40.0;
  w = 0x40;
  local_18 = (_DAT_0048cc50 + local_10 + 44.0) - 10.0;
  y = 0x100;
  iVar3 = DAT_0048f7f8;
  local_14 = fVar2;
  local_c = fVar2;
  local_8 = local_18;
  lVar13 = __ftol();
  iVar6 = (int)lVar13;
  lVar13 = __ftol();
  ui_draw_textured_quad((int)lVar13,iVar6,y,w,iVar3);
  if (ui_screen_phase == -1) {
    highscore_load_table();
    DAT_004825a4 = highscore_rank_index();
    highscore_active_record.game_mode_id = config_blob.reserved0[0x18];
    (*grim_interface_ptr->vtable->grim_flush_input)();
    console_input_poll();
    (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c);
    if (DAT_004825a4 < 100) {
      uVar4 = 0xffffffff;
      ui_screen_phase = 0;
      phVar12 = &highscore_active_record;
      do {
        phVar9 = phVar12;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        phVar9 = (highscore_record_t *)(phVar12->player_name + 1);
        pcVar8 = phVar12->player_name;
        phVar12 = phVar9;
      } while (*pcVar8 != '\0');
      uVar4 = ~uVar4;
      _DAT_00482598 = 0x14;
      _DAT_00482590 = &DAT_0048256c;
      puVar7 = (undefined4 *)((int)phVar9 - uVar4);
      puVar10 = &DAT_0048256c;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar10 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      uVar4 = 0xffffffff;
      phVar12 = &highscore_active_record;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar8 = phVar12->player_name;
        phVar12 = (highscore_record_t *)(phVar12->player_name + 1);
      } while (*pcVar8 != '\0');
      DAT_00482594 = ~uVar4 - 1;
LAB_00410232:
      local_18 = local_18 + 8.0;
      DAT_00496604 = 0x3f800000;
      local_14 = local_14 + 84.0;
      (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004965f8);
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_18 + 42.0,local_14,s_State_your_name__trooper__00473190);
      local_14 = local_14 + 40.0;
      DAT_00496604 = 0x3f333333;
      _DAT_004825a8 = &DAT_0047318c;
      local_10 = local_18 + 170.0;
      local_c = local_14 - 8.0;
      ui_button_update(&local_10,(ui_button_t *)&DAT_004825a8);
      _DAT_0048259c = 0xa6;
      iVar3 = ui_text_input_update(&local_18,(int *)&DAT_00482590);
      if (((char)iVar3 != '\0') || (DAT_004825ad != '\0')) {
        uVar4 = 0xffffffff;
        iVar3 = 0;
        pcVar8 = (char *)&DAT_0048256c;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        iVar6 = ~uVar4 - 1;
        if (0 < iVar6) {
          if (0 < iVar6) {
            do {
              if (*(char *)((int)&DAT_0048256c + iVar3) != ' ') break;
              iVar3 = iVar3 + 1;
            } while (iVar3 < iVar6);
          }
          if (*(char *)((int)&DAT_0048256c + iVar3) != '\0') {
            ui_screen_phase = 1;
            sfx_play(sfx_ui_typeenter);
            phVar12 = &highscore_active_record;
            for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
              phVar12->player_name[0] = '\0';
              phVar12->player_name[1] = '\0';
              phVar12->player_name[2] = '\0';
              phVar12->player_name[3] = '\0';
              phVar12 = (highscore_record_t *)(phVar12->player_name + 4);
            }
            uVar4 = 0xffffffff;
            pcVar8 = (char *)&DAT_0048256c;
            do {
              pcVar11 = pcVar8;
              if (uVar4 == 0) break;
              uVar4 = uVar4 - 1;
              pcVar11 = pcVar8 + 1;
              cVar1 = *pcVar8;
              pcVar8 = pcVar11;
            } while (cVar1 != '\0');
            uVar4 = ~uVar4;
            _DAT_00482590 = &DAT_0048256c;
            pcVar8 = pcVar11 + -uVar4;
            phVar12 = &highscore_active_record;
            for (uVar5 = uVar4 >> 2; iVar3 = DAT_00482594, uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined4 *)phVar12->player_name = *(undefined4 *)pcVar8;
              pcVar8 = pcVar8 + 4;
              phVar12 = (highscore_record_t *)(phVar12->player_name + 4);
            }
            player_name_length = DAT_00482594;
            for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
              phVar12->player_name[0] = *pcVar8;
              pcVar8 = pcVar8 + 1;
              phVar12 = (highscore_record_t *)(phVar12->player_name + 1);
            }
            highscore_active_record.player_name[iVar3] = '\0';
            highscore_save_active();
            highscore_load_table();
            goto LAB_004103c2;
          }
        }
        DAT_004825ad = '\0';
        sfx_play(sfx_shock_hit_01);
      }
LAB_004103c2:
      local_14 = local_14 + 60.0;
      (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004965f8);
      if (DAT_004825a4 < 100) {
        local_10 = local_18 + 16.0;
        local_c = local_14 + 16.0;
        ui_text_input_render(&local_10,6.652423e-39,1.0);
        ui_cursor_render();
        return;
      }
      goto LAB_00410782;
    }
    ui_screen_phase = 1;
  }
  else {
    if (ui_screen_phase == 0) goto LAB_00410232;
    if (ui_screen_phase != 1) goto LAB_00410782;
  }
  local_18 = local_8 + 30.0;
  _DAT_00482590 = &DAT_0048256c;
  if (DAT_004825a4 < 100) {
    local_14 = fVar2 + 64.0;
  }
  else {
    local_14 = fVar2 + 62.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,local_18 + 8.0,local_14,s_Score_too_low_for_top_d__00473170,100);
    local_14 = local_14 + 6.0;
  }
  local_10 = local_18;
  local_c = local_14 + 16.0;
  ui_text_input_render(&local_10,6.652423e-39,1.0);
  local_14 = local_14 + 146.0;
  if (((byte)game_over_screen_flags & 4) == 0) {
    game_over_screen_flags._0_1_ = (byte)game_over_screen_flags | 4;
    DAT_0048250e = 1;
    DAT_0048251d = 0;
    DAT_0048251c = 0;
    _DAT_00482518 = 0x3f800000;
    _DAT_00482514 = 0;
    _DAT_00482508 = (char *)0x0;
    DAT_0048250c = 0;
    DAT_0048250d = '\0';
    _DAT_00482510 = 0;
    crt_atexit(&DAT_004107b0);
  }
  _DAT_00482508 = s_Play_Again_00473164;
  if (((byte)game_over_screen_flags & 8) == 0) {
    game_over_screen_flags._0_1_ = (byte)game_over_screen_flags | 8;
    DAT_00482556 = 1;
    DAT_00482565 = 0;
    DAT_00482564 = 0;
    _DAT_00482560 = 0x3f800000;
    _DAT_0048255c = 0;
    _DAT_00482550 = (char *)0x0;
    DAT_00482554 = 0;
    DAT_00482555 = '\0';
    _DAT_00482558 = 0;
    crt_atexit(&DAT_004107a0);
  }
  _DAT_00482550 = s_High_scores_00473158;
  if (((byte)game_over_screen_flags & 0x10) == 0) {
    game_over_screen_flags._0_1_ = (byte)game_over_screen_flags | 0x10;
    DAT_0048253e = 1;
    DAT_0048254d = 0;
    DAT_0048254c = 0;
    _DAT_00482548 = 0x3f800000;
    _DAT_00482544 = 0;
    _DAT_00482538 = (char *)0x0;
    DAT_0048253c = 0;
    DAT_0048253d = '\0';
    _DAT_00482540 = 0;
    crt_atexit(&DAT_00410790);
  }
  _DAT_00482538 = s_Main_Menu_00472084;
  local_18 = (local_18 - 4.0) + 26.0;
  ui_button_update(&local_18,(ui_button_t *)&DAT_00482508);
  local_14 = local_14 + 32.0;
  ui_button_update(&local_18,(ui_button_t *)&DAT_00482550);
  local_14 = local_14 + 32.0;
  ui_button_update(&local_18,(ui_button_t *)&DAT_00482538);
  local_14 = local_14 + 32.0;
  if (DAT_0048250d != '\0') {
    ui_transition_direction = '\0';
    game_state_pending = 9;
    if (config_blob.reserved0._24_4_ == 4) {
      game_state_pending = 0x12;
    }
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_mute_all(music_track_extra_0);
  }
  if (DAT_00482555 != '\0') {
    DAT_00487258._0_1_ = config_blob.reserved0[0x18];
    DAT_00487258._1_1_ = config_blob.reserved0[0x19];
    DAT_00487258._2_1_ = config_blob.reserved0[0x1a];
    DAT_00487258._3_1_ = config_blob.reserved0[0x1b];
    highscore_return_latch = '\x01';
    DAT_00487250 = _quest_stage_major;
    DAT_00487254 = _quest_stage_minor;
    DAT_0048725c = config_blob.hardcore;
    ui_transition_direction = '\0';
    game_state_pending = 0xe;
  }
  if (DAT_0048253d != '\0') {
    sfx_mute_all(music_track_extra_0);
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_play_exclusive(music_track_crimson_theme_id);
    ui_transition_direction = '\0';
    game_state_pending = 0;
    ui_sign_crimson_update_disabled = 0;
  }
LAB_00410782:
  ui_cursor_render();
  return;
}



