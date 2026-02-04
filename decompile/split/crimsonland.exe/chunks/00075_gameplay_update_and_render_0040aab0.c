/* gameplay_update_and_render @ 0040aab0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* main gameplay frame loop for state 9 (timers, updates, renders, UI) */

void gameplay_update_and_render(void)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  longlong lVar4;
  float local_8;
  float fStack_4;
  
  fVar1 = frame_dt;
  if (time_scale_active != '\0') {
    _time_scale_factor = 0.3;
    if (_bonus_reflex_boost_timer < 1.0) {
      _time_scale_factor = (1.0 - _bonus_reflex_boost_timer) * 0.7 + 0.3;
    }
    frame_dt = _time_scale_factor * frame_dt;
    lVar4 = __ftol();
    frame_dt_ms = (int)lVar4;
  }
  if (demo_mode_active == '\0') {
    iVar2 = game_is_full_version();
    if (((char)iVar2 == '\0') && (config_blob.reserved0._24_4_ != 8)) {
      game_status_blob.game_sequence_id = game_sequence_get();
      if ((int)game_status_blob.game_sequence_id < 0x249f01) {
        if (demo_trial_elapsed_ms < 1) {
          if (config_blob.reserved0._24_4_ != 3) goto LAB_0040abea;
        }
        else if ((config_blob.reserved0._24_4_ != 3) ||
                (local_8 = (float)(demo_trial_elapsed_ms / 1000),
                5.0 < (float)(int)local_8 * 0.016666668)) goto LAB_0040abae;
        if ((game_state_id != 9) || ((_quest_stage_major < 2 && (_quest_stage_minor < 0xb))))
        goto LAB_0040abea;
      }
LAB_0040abae:
      frame_dt_ms = 0;
      frame_dt = 0.0;
      goto LAB_0040abf9;
    }
LAB_0040abea:
    if (game_paused_flag != '\0') goto LAB_0040abae;
LAB_0040ac01:
    if (console_open_flag == '\0') {
      perks_update_effects();
    }
  }
  else {
LAB_0040abf9:
    if (game_paused_flag == '\0') goto LAB_0040ac01;
  }
  effects_update();
  if (((demo_mode_active == '\0') && (iVar2 = game_is_full_version(), (char)iVar2 == '\0')) &&
     (config_blob.reserved0._24_4_ != 8)) {
    game_status_blob.game_sequence_id = game_sequence_get();
    if ((int)game_status_blob.game_sequence_id < 0x249f01) {
      if (demo_trial_elapsed_ms < 1) {
        if (config_blob.reserved0._24_4_ != 3) goto LAB_0040aca0;
      }
      else if ((config_blob.reserved0._24_4_ != 3) ||
              (local_8 = (float)(demo_trial_elapsed_ms / 1000),
              5.0 < (float)(int)local_8 * 0.016666668)) goto LAB_0040acbb;
      if ((game_state_id != 9) || ((_quest_stage_major < 2 && (_quest_stage_minor < 0xb))))
      goto LAB_0040aca0;
    }
  }
  else {
LAB_0040aca0:
    if ((game_paused_flag == '\0') && (game_state_id == 9)) {
      creature_update_all();
      projectile_update();
    }
  }
LAB_0040acbb:
  if (((demo_mode_active == '\0') && (iVar2 = game_is_full_version(), (char)iVar2 == '\0')) &&
     (config_blob.reserved0._24_4_ != 8)) {
    game_status_blob.game_sequence_id = game_sequence_get();
    if ((int)game_status_blob.game_sequence_id < 0x249f01) {
      if (demo_trial_elapsed_ms < 1) {
        if (config_blob.reserved0._24_4_ != 3) goto LAB_0040ad54;
      }
      else if ((config_blob.reserved0._24_4_ != 3) ||
              (local_8 = (float)(demo_trial_elapsed_ms / 1000),
              5.0 < (float)(int)local_8 * 0.016666668)) goto LAB_0040ad8e;
      if ((game_state_id != 9) || ((_quest_stage_major < 2 && (_quest_stage_minor < 0xb))))
      goto LAB_0040ad54;
    }
  }
  else {
LAB_0040ad54:
    if ((game_paused_flag == '\0') &&
       ((game_state_id == 9 &&
        (render_overlay_player_index = 0, 0 < (int)config_blob.reserved0._20_4_)))) {
      do {
        player_update();
        render_overlay_player_index = render_overlay_player_index + 1;
      } while (render_overlay_player_index < (int)config_blob.reserved0._20_4_);
    }
  }
LAB_0040ad8e:
  render_overlay_player_index = 0;
  if (config_blob.reserved0._24_4_ == 1) {
    survival_update();
  }
  if (config_blob.reserved0._24_4_ == 2) {
    rush_mode_update();
  }
  if (config_blob.reserved0._24_4_ == 3) {
    quest_mode_update();
  }
  highscore_active_record.score_xp = player_state_table.experience;
  if ((console_open_flag == '\0') && (game_paused_flag == '\0')) {
    if (0.0 < _bonus_weapon_power_up_timer) {
      _bonus_weapon_power_up_timer = _bonus_weapon_power_up_timer - frame_dt;
    }
    if (0.0 < _bonus_energizer_timer) {
      _bonus_energizer_timer = _bonus_energizer_timer - frame_dt;
    }
    time_scale_active = 0.0 < _bonus_reflex_boost_timer;
    if ((bool)time_scale_active) {
      _bonus_reflex_boost_timer = _bonus_reflex_boost_timer - frame_dt;
    }
    highscore_active_record.survival_elapsed_ms =
         highscore_active_record.survival_elapsed_ms + frame_dt_ms;
    (&weapon_usage_time)[player_state_table.weapon_id] =
         (&weapon_usage_time)[player_state_table.weapon_id] + frame_dt_ms;
  }
  camera_update();
  gameplay_render_world();
  if (config_blob.reserved0._24_4_ == 8) {
    tutorial_timeline_update();
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  if (demo_mode_active == '\0') {
    if (((player_state_table.health <= 0.0) && (player_state_table.death_timer < 0.0)) &&
       ((config_blob.reserved0._20_4_ == 1 ||
        ((player2_health <= 0.0 && (_player2_death_timer < 0.0)))))) {
      render_pass_mode = 0;
      ui_transition_direction = 0;
      game_state_pending = (-(uint)(config_blob.reserved0._24_4_ != 3) & 0xfffffffb) + 0xc;
      (*grim_interface_ptr->vtable->grim_flush_input)();
      console_input_poll();
      sfx_mute_all(music_track_extra_0);
      sfx_mute_all(music_track_crimson_theme_id);
      sfx_mute_all(music_track_shortie_monk_id);
      sfx_play_exclusive(music_track_shortie_monk_id);
    }
  }
  else {
    pfVar3 = &player_state_table.health;
    do {
      *pfVar3 = 100.0;
      pfVar3 = pfVar3 + 0xd8;
    } while ((int)pfVar3 < 0x490f94);
  }
  if (config_blob.reserved0._24_4_ != 2) {
    crt_ci_pow();
    lVar4 = __ftol();
    if (1000 - (int)lVar4 < player_state_table.experience) {
      perk_pending_count = perk_pending_count + 1;
      config_blob.perk_prompt_counter = config_blob.perk_prompt_counter + 1;
      if (0x32 < config_blob.perk_prompt_counter) {
        config_blob.perk_prompt_counter = 0;
        config_blob.full_version = '\0';
      }
      sfx_play(sfx_ui_levelup);
      player_state_table.level = player_state_table.level + 1;
    }
  }
  if ((console_open_flag == '\0') && (game_paused_flag == '\0')) {
    if (perk_prompt_hover_active == '\0') {
      iVar2 = -frame_dt_ms;
    }
    else {
      iVar2 = frame_dt_ms * 3;
    }
    perk_prompt_pulse = perk_prompt_pulse + iVar2 * 2;
    if (perk_prompt_pulse < 0) {
      perk_prompt_pulse = 0;
    }
    else if (1000 < perk_prompt_pulse) {
      perk_prompt_pulse = 1000;
    }
  }
  if (((((demo_mode_active == '\0') && (game_paused_flag == '\0')) && (mouse_button_down == '\0'))
      && ((config_blob.reserved0._24_4_ != 2 && (0 < perk_pending_count)))) &&
     ((0.0 < player_state_table.health ||
      ((config_blob.reserved0._20_4_ == 2 && (0.0 < player2_health)))))) {
    local_8 = ui_mouse_x - _perk_prompt_origin_x;
    fStack_4 = ui_mouse_y - _perk_prompt_origin_y;
    if (game_state_pending != 6) {
      iVar2 = (*grim_interface_ptr->vtable->grim_is_key_active)(config_blob.key_pick_perk);
      if ((((char)iVar2 == '\0') &&
          (iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x39), (char)iVar2 == '\0'))
         && (iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x4e), (char)iVar2 == '\0')
         ) {
        if (((local_8 <= perk_prompt_bounds_min_x) || (fStack_4 <= perk_prompt_bounds_min_y)) ||
           ((_perk_prompt_bounds_max_x <= local_8 || (_perk_prompt_bounds_max_y <= fStack_4)))) {
          perk_prompt_hover_active = '\0';
        }
        else {
          perk_prompt_hover_active = '\x01';
          iVar2 = input_primary_just_pressed();
          if ((char)iVar2 != '\0') goto joined_r0x0040b1bc;
        }
      }
      else {
        perk_prompt_pulse = 1000;
joined_r0x0040b1bc:
        if (perk_choices_dirty != '\0') {
          perks_generate_choices();
          perk_choices_dirty = '\0';
        }
        game_state_set(6);
      }
    }
  }
  iVar2 = (*grim_interface_ptr->vtable->grim_is_mouse_button_down)(0);
  mouse_button_down = (char)iVar2 != '\0';
  bonus_update();
  frame_dt = fVar1;
  lVar4 = __ftol();
  frame_dt_ms = (int)lVar4;
  if (((demo_mode_active == '\0') && (perk_prompt_update_and_render(), demo_mode_active == '\0')) &&
     ((iVar2 = game_is_full_version(), (char)iVar2 == '\0' && (config_blob.reserved0._24_4_ != 8))))
  {
    game_status_blob.game_sequence_id = game_sequence_get();
    if ((int)game_status_blob.game_sequence_id < 0x249f01) {
      if (demo_trial_elapsed_ms < 1) {
        if (config_blob.reserved0._24_4_ != 3) goto LAB_0040b2ad;
      }
      else if ((config_blob.reserved0._24_4_ != 3) ||
              (local_8 = (float)(demo_trial_elapsed_ms / 1000),
              5.0 < (float)(int)local_8 * 0.016666668)) goto LAB_0040b2b2;
      if ((game_state_id != 9) || ((_quest_stage_major < 2 && (_quest_stage_minor < 0xb))))
      goto LAB_0040b2ad;
    }
  }
  else {
LAB_0040b2ad:
    ui_render_aim_indicators();
  }
LAB_0040b2b2:
  hud_update_and_render();
  ui_elements_update_and_render();
  iVar2 = game_is_full_version();
  if ((char)iVar2 == '\0') {
    if (((demo_mode_active == '\0') && (iVar2 = game_is_full_version(), (char)iVar2 == '\0')) &&
       (config_blob.reserved0._24_4_ != 8)) {
      game_status_blob.game_sequence_id = game_sequence_get();
      if ((int)game_status_blob.game_sequence_id < 0x249f01) {
        if (demo_trial_elapsed_ms < 1) {
          if (config_blob.reserved0._24_4_ != 3) goto LAB_0040b3bd;
        }
        else if ((config_blob.reserved0._24_4_ != 3) ||
                (local_8 = (float)(demo_trial_elapsed_ms / 1000),
                5.0 < (float)(int)local_8 * 0.016666668)) goto LAB_0040b35f;
        if ((game_state_id != 9) || ((_quest_stage_major < 2 && (_quest_stage_minor < 0xb))))
        goto LAB_0040b3bd;
      }
LAB_0040b35f:
      DAT_00480898 = DAT_00480898 + frame_dt_ms;
      local_8 = (float)config_blob.screen_width * 0.5 - 256.0;
      fStack_4 = (float)config_blob.screen_height * 0.5 - 128.0;
      demo_trial_overlay_render(&local_8,1.0);
      DAT_00480850 = 1;
    }
    else {
LAB_0040b3bd:
      DAT_00480898 = DAT_00480898 - frame_dt_ms;
      DAT_00480850 = 0;
    }
    if (DAT_00480898 < 0) {
      DAT_00480898 = 0;
    }
    else if (1000 < DAT_00480898) {
      DAT_00480898 = 1000;
    }
  }
  iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x3b);
  if ((char)iVar2 != '\0') {
    game_paused_flag = game_paused_flag == '\0';
  }
  iVar2 = game_is_full_version();
  if (((char)iVar2 == '\0') && (config_blob.reserved0._24_4_ != 8)) {
    game_status_blob.game_sequence_id = game_sequence_get();
    if ((int)game_status_blob.game_sequence_id < 0x249f01) {
      if (demo_trial_elapsed_ms < 1) {
        if (config_blob.reserved0._24_4_ != 3) goto LAB_0040b4bc;
      }
      else if ((config_blob.reserved0._24_4_ != 3) ||
              (local_8 = (float)(demo_trial_elapsed_ms / 1000),
              5.0 < (float)(int)local_8 * 0.016666668)) goto LAB_0040b494;
      if ((game_state_id != 9) || ((_quest_stage_major < 2 && (_quest_stage_minor < 0xb))))
      goto LAB_0040b4bc;
    }
LAB_0040b494:
    game_paused_flag = '\0';
LAB_0040b49a:
    DAT_00487284 = DAT_00487284 + frame_dt_ms * -4;
  }
  else {
LAB_0040b4bc:
    if (game_paused_flag == '\0') goto LAB_0040b49a;
    DAT_00487284 = DAT_00487284 + frame_dt_ms * 2;
  }
  if (DAT_00487284 < 0) {
    DAT_00487284 = 0;
  }
  else {
    if (DAT_00487284 < 0x3e9) {
      if (DAT_00487284 < 1) goto LAB_0040b52d;
    }
    else {
      DAT_00487284 = 1000;
    }
    local_8 = (float)config_blob.screen_width * 0.5 - 256.0;
    fStack_4 = (float)config_blob.screen_height * 0.5 - 128.0;
    ui_render_keybind_help(&local_8,(float)DAT_00487284 * 0.001);
  }
LAB_0040b52d:
  iVar2 = game_is_full_version();
  if ((char)iVar2 != '\0') {
    return;
  }
  if (config_blob.reserved0._24_4_ == 8) {
    return;
  }
  game_status_blob.game_sequence_id = game_sequence_get();
  if ((int)game_status_blob.game_sequence_id < 0x249f01) {
    if (demo_trial_elapsed_ms < 1) {
      if (config_blob.reserved0._24_4_ != 3) {
        return;
      }
    }
    else if ((config_blob.reserved0._24_4_ != 3) ||
            (local_8 = (float)(demo_trial_elapsed_ms / 1000),
            5.0 < (float)(int)local_8 * 0.016666668)) goto LAB_0040b5b4;
    if (game_state_id != 9) {
      return;
    }
    if ((_quest_stage_major < 2) && (_quest_stage_minor < 0xb)) {
      return;
    }
  }
LAB_0040b5b4:
  if (demo_mode_active == '\0') {
    ui_cursor_render();
  }
  return;
}



