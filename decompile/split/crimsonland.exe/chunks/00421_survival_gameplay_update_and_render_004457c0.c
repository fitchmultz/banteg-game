/* survival_gameplay_update_and_render @ 004457c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* survival mode frame loop: effects, spawns, death handling, world render, HUD, and debug name
   input */

void survival_gameplay_update_and_render(void)

{
  undefined1 *puVar1;
  byte bVar2;
  IGrim2D_vtbl *pIVar3;
  IGrim2D *pIVar4;
  int iVar5;
  uint uVar6;
  bonus_entry_t *pbVar7;
  byte *pbVar8;
  bool bVar9;
  float10 fVar10;
  longlong lVar11;
  char *pcVar12;
  float a;
  float fVar13;
  float local_30;
  float fStack_2c;
  float local_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float local_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
  local_30 = (float)((uint)local_30 & 0xffffff00);
  local_28 = (float)((uint)local_28 & 0xffffff00);
  if ((DAT_004d1528 & 1) == 0) {
    _DAT_004d7570 = player_state_table.pos_x + 128.0;
    DAT_004d1528 = DAT_004d1528 | 1;
    _DAT_004d7574 = player_state_table.pos_y;
    crt_atexit(&DAT_00445ff0);
  }
  pIVar4 = grim_interface_ptr;
  if (DAT_00478c94 != '\0') {
    DAT_004d7588 = 0;
    DAT_004d14a8 = 0;
    DAT_00478c94 = '\0';
  }
  local_14 = (float)config_blob.screen_height - 128.0;
  (&DAT_004d14a9)[DAT_004d7588] = 0;
  iVar5 = (*pIVar4->vtable->grim_is_key_down)(0x1c);
  if (((char)iVar5 != '\0') && (0 < DAT_004d7588)) {
    sfx_play(sfx_ui_typeenter);
    DAT_004d7578 = DAT_004d7578 + 1;
    (&DAT_004d14a8)[DAT_004d7588] = 0;
    iVar5 = creature_find_by_name(&DAT_004d14a8);
    if (iVar5 == -1) {
      pbVar8 = &DAT_004d14a8;
      pcVar12 = s_reload_00478e38;
      do {
        bVar2 = *pcVar12;
        bVar9 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_00445900:
          iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_00445905;
        }
        if (bVar2 == 0) break;
        bVar2 = ((byte *)pcVar12)[1];
        bVar9 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_00445900;
        pcVar12 = (char *)((byte *)pcVar12 + 2);
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_00445905:
      if (iVar5 == 0) {
        local_28 = (float)CONCAT31(local_28._1_3_,1);
      }
    }
    else {
      local_30 = (float)CONCAT31(local_30._1_3_,1);
      _DAT_004d7570 = (&creature_pool)[iVar5].pos_x;
      _DAT_004d7574 = (&creature_pool)[iVar5].pos_y;
      DAT_004d757c = DAT_004d757c + 1;
    }
    DAT_004d7588 = 0;
    DAT_004d14a8 = 0;
  }
  iVar5 = console_input_poll();
  if ((iVar5 != 0) && (iVar5 != 0xd)) {
    if (iVar5 == 8) {
      uVar6 = crt_rand();
      uVar6 = uVar6 & 0x80000001;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
      }
      sfx_play(uVar6 + _sfx_ui_typeclick_01);
      if (DAT_004d7588 < 1) {
        DAT_004d14a8 = 0;
      }
      else {
        puVar1 = &DAT_004d14a7 + DAT_004d7588;
        DAT_004d7588 = DAT_004d7588 + -1;
        *puVar1 = 0;
      }
    }
    else {
      if (DAT_004d7588 < 0x11) {
        (&DAT_004d14a8)[DAT_004d7588] = (char)iVar5;
        DAT_004d7588 = DAT_004d7588 + 1;
      }
      (&DAT_004d14a8)[DAT_004d7588] = 0;
      uVar6 = crt_rand();
      uVar6 = uVar6 & 0x80000001;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
      }
      sfx_play(uVar6 + _sfx_ui_typeclick_01);
    }
  }
  perks_update_effects();
  fStack_24 = frame_dt;
  if (time_scale_active != '\0') {
    frame_dt = frame_dt * 0.3;
    _time_scale_factor = 0x3e99999a;
    lVar11 = __ftol();
    frame_dt_ms = (int)lVar11;
  }
  effects_update();
  if (game_state_id == 0x12) {
    creature_update_all();
    projectile_update();
    fVar13 = local_30;
    if ((game_state_id == 0x12) &&
       (render_overlay_player_index = 0, 0 < (int)config_blob.reserved0._20_4_)) {
      do {
        player_fire_weapon('p',SUB41(fVar13,0));
        render_overlay_player_index = render_overlay_player_index + 1;
      } while (render_overlay_player_index < (int)config_blob.reserved0._20_4_);
    }
  }
  render_overlay_player_index = 0;
  player_state_table.weapon_id = 3;
  player_state_table.ammo = 0x41f00000;
  if (console_open_flag == '\0') {
    survival_spawn_cooldown = survival_spawn_cooldown - config_blob.reserved0._20_4_ * frame_dt_ms;
  }
  while (survival_spawn_cooldown < 0) {
    survival_spawn_cooldown =
         survival_spawn_cooldown + (0xdac - (int)highscore_active_record.survival_elapsed_ms / 800);
    if (survival_spawn_cooldown < 100) {
      survival_spawn_cooldown = 100;
    }
    local_28 = (float)(highscore_active_record.survival_elapsed_ms + 1);
    uStack_4 = 0x3f800000;
    fVar10 = (float10)(int)local_28;
    fStack_10 = (float)(fVar10 * (float10)8.333333e-06 + (float10)0.3);
    fStack_c = (float)(fVar10 * (float10)10000.0 + (float10)0.3);
    fVar10 = (float10)fsin(fVar10 * (float10)0.000100000005);
    fStack_8 = (float)(fVar10 + (float10)0.3);
    if (0.0 <= fStack_10) {
      if (1.0 < fStack_10) {
        fStack_10 = 1.0;
      }
    }
    else {
      fStack_10 = 0.0;
    }
    if (0.0 <= fStack_c) {
      if (1.0 < fStack_c) {
        fStack_c = 1.0;
      }
    }
    else {
      fStack_c = 0.0;
    }
    if (0.0 <= fStack_8) {
      if (1.0 < fStack_8) {
        fStack_8 = 1.0;
      }
    }
    else {
      fStack_8 = 0.0;
    }
    DAT_004d758c = DAT_004d758c + 1;
    local_30 = (float)terrain_texture_width + 64.0;
    fVar10 = (float10)fcos((float10)(int)highscore_active_record.survival_elapsed_ms *
                           (float10)0.001);
    fStack_2c = (float)((float10)terrain_texture_height * (float10)0.5 + fVar10 * (float10)256.0);
    iVar5 = creature_spawn_tinted(&local_30,&fStack_10,4);
    creature_name_assign_random(iVar5);
    fStack_20 = -64.0;
    fVar10 = (float10)fcos((float10)(int)highscore_active_record.survival_elapsed_ms *
                           (float10)0.001);
    fStack_1c = (float)((float10)terrain_texture_height * (float10)0.5 + fVar10 * (float10)256.0);
    iVar5 = creature_spawn_tinted(&fStack_20,&fStack_10,2);
    creature_name_assign_random(iVar5);
  }
  highscore_active_record.score_xp = player_state_table.experience;
  if (console_open_flag == '\0') {
    _bonus_weapon_power_up_timer = 0;
    highscore_active_record.survival_elapsed_ms =
         highscore_active_record.survival_elapsed_ms + frame_dt_ms;
    _bonus_reflex_boost_timer = 0;
    time_scale_active = '\0';
    (&weapon_usage_time)[player_state_table.weapon_id] =
         (&weapon_usage_time)[player_state_table.weapon_id] + frame_dt_ms;
  }
  camera_update();
  gameplay_render_world();
  creature_name_draw_labels();
  pbVar7 = bonus_pool;
  do {
    pbVar7->bonus_id = BONUS_ID_NONE;
    pbVar7 = pbVar7 + 1;
  } while ((int)pbVar7 < 0x482b08);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  if ((((demo_mode_active == '\0') && (player_state_table.health <= 0.0)) &&
      (player_state_table.death_timer < 0.0)) &&
     ((config_blob.reserved0._20_4_ == 1 ||
      ((player2_health <= 0.0 && (_player2_death_timer < 0.0)))))) {
    render_pass_mode = 0;
    game_state_pending = 7;
    ui_transition_direction = 0;
    (*grim_interface_ptr->vtable->grim_flush_input)();
    console_input_poll();
    sfx_mute_all(music_track_extra_0);
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_play_exclusive(music_track_shortie_monk_id);
  }
  frame_dt = fStack_24;
  lVar11 = __ftol();
  frame_dt_ms = (int)lVar11;
  perk_prompt_update_and_render();
  hud_update_and_render();
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  fVar13 = 2.94273e-44;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7c4,0);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.7);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)(-1.0,local_28 - 16.0,182.0,53.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  fVar13 = fVar13 + 1.0;
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,6.0,fVar13,&DAT_004712bc,&DAT_004d14a8);
  a = 1.0;
  fVar10 = (float10)fsin((float10)game_time_s * (float10)4.0);
  if ((float10)0.0 < fVar10) {
    a = 0.4;
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,a);
  pcVar12 = &DAT_004712b8;
  pIVar3 = grim_interface_ptr->vtable;
  iVar5 = (*pIVar3->grim_measure_text_width)(&DAT_004d14a8);
  (*pIVar3->grim_draw_text_small_fmt)(grim_interface_ptr,(float)iVar5 + 14.0,fVar13,pcVar12);
  highscore_active_record.shots_hit = DAT_004d757c;
  highscore_active_record.shots_fired = DAT_004d7578;
  ui_elements_update_and_render();
  return;
}



