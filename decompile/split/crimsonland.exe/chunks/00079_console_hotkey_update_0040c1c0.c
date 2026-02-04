/* console_hotkey_update @ 0040c1c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* per-frame input/update function; contains console hotkey block (DIK_GRAVE) at 0x0040c360 and
   DIK_F12 check; entry identified via WinDbg */

void console_hotkey_update(void)

{
  IGrim2D_vtbl *pIVar1;
  int iVar2;
  char *pcVar3;
  FILE *fp;
  float *pfVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 extraout_ST0_07;
  longlong lVar8;
  float y;
  float fVar9;
  uint in_stack_ffffffc0;
  float fStack_20;
  float fStack_1c;
  uint auStack_10 [4];
  
  (*grim_interface_ptr->vtable->grim_get_frame_dt)();
  frame_dt = (float)extraout_ST0;
  if (quest_unlock_index < 0x28) {
    config_blob.hardcore = '\0';
  }
  iVar2 = game_is_full_version();
  if ((char)iVar2 == '\0') {
    if ((int)game_status_blob.game_sequence_id < 0) {
      game_status_blob.game_sequence_id = 1200000;
    }
    game_status_blob.game_sequence_id = game_sequence_get();
    config_blob.hardcore = '\0';
  }
  iVar2 = game_is_full_version();
  if ((char)iVar2 != '\0') {
    _DAT_0048823c = &LAB_00447350;
    shareware_offer_seen_latch = '\0';
  }
  if ((DAT_00486faa == '\0') && (iVar2 = game_is_full_version(), (char)iVar2 != '\0')) {
    DAT_004875c4 = DAT_004875c4 + 60.0;
    DAT_004875b8 = DAT_00488218;
    DAT_004875bc = DAT_0048821c;
    DAT_00486faa = '\x01';
    DAT_00488208 = 0;
    _DAT_004875c0 = _DAT_004875c0 - 20.0;
  }
  if ((audio_suspend_flag == '\0') &&
     (pcVar3 = (char *)(*grim_interface_ptr->vtable->grim_get_config_var)(auStack_10,0x57),
     *pcVar3 != '\0')) {
    if ((render_pass_mode == '\0') || (config_blob.reserved0._24_4_ != 3)) {
      terrain_generate_random();
    }
    else {
      uVar6 = _quest_stage_minor - 1;
      uVar7 = _quest_stage_major - 1;
      if (9 < (int)uVar6) {
        uVar6 = uVar6 % 10;
      }
      if (3 < (int)uVar7) {
        uVar7 = uVar7 + (uVar7 >> 2) * -4;
      }
      terrain_generate(&quest_selected_meta + uVar7 + uVar6 * 10);
    }
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x57,in_stack_ffffffc0 & 0xffffff00);
  }
  iVar2 = game_is_full_version();
  if (((char)iVar2 == '\0') && (10 < quest_unlock_index)) {
    quest_unlock_index = 10;
  }
  if (audio_suspend_flag != '\0') {
    audio_resume_all();
    return;
  }
  game_time_ms = game_time_ms + frame_dt_ms;
  iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x29);
  if ((char)iVar2 != '\0') {
    console_set_open(&console_log_queue,console_open_flag == '\0');
  }
  console_update(0x47eea0);
  iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x58);
  if ((char)iVar2 != '\0') {
    do {
      if (DAT_004808c4 < 10) {
        pcVar3 = s_shot_00_d_bmp_004729b8;
      }
      else if (DAT_004808c4 < 100) {
        pcVar3 = s_shot_0_d_bmp_004729a8;
      }
      else {
        pcVar3 = s_shot__d_bmp_0047299c;
      }
      crt_sprintf(&DAT_0047f634,pcVar3);
      fp = (FILE *)crt_fopen(&DAT_0047f634,&file_mode_read_binary);
      if (fp != (FILE *)0x0) {
        crt_fclose(fp);
      }
      DAT_004808c4 = DAT_004808c4 + 1;
    } while (fp != (FILE *)0x0);
    (*grim_interface_ptr->vtable->grim_check_device)();
  }
  if ((demo_mode_active == '\0') && (DAT_00480850 == '\0')) {
    game_status_blob.game_sequence_id = game_sequence_get();
    iVar2 = game_state_id;
    if ((console_open_flag == '\0') && ((render_pass_mode != '\0' && (game_state_id == 9)))) {
      lVar8 = __ftol();
      game_status_blob.game_sequence_id = game_status_blob.game_sequence_id + (int)lVar8;
    }
    if ((demo_trial_elapsed_ms < 1) || (console_open_flag != '\0')) goto LAB_0040c4b7;
    if (render_pass_mode != '\0') {
      if ((iVar2 == 9) && (config_blob.reserved0._24_4_ != 8)) {
        lVar8 = __ftol();
        demo_trial_elapsed_ms = demo_trial_elapsed_ms + (int)lVar8;
      }
      goto LAB_0040c4b7;
    }
  }
  else {
LAB_0040c4b7:
    if (((render_pass_mode != '\0') && (iVar2 = perk_count_get(perk_id_reflex_boosted), iVar2 != 0))
       && (game_state_id == 9)) {
      frame_dt = frame_dt * 0.9;
    }
  }
  game_time_s = game_time_s + frame_dt;
  _DAT_0047ea48 = frame_dt;
  lVar8 = __ftol();
  frame_dt_ms = (int)lVar8;
  if (((console_open_flag == '\0') && (render_pass_mode != '\0')) &&
     ((game_state_id == 9 && (config_blob.reserved0._24_4_ != 8)))) {
    DAT_0048718c = DAT_0048718c + frame_dt_ms;
  }
  if (DAT_0048702c == '\0') {
    screen_fade_alpha = screen_fade_alpha - (frame_dt + frame_dt);
  }
  else {
    screen_fade_alpha = frame_dt * 10.0 + screen_fade_alpha;
  }
  if (0.0 <= screen_fade_alpha) {
    if (1.0 < screen_fade_alpha) {
      screen_fade_alpha = 1.0;
    }
  }
  else {
    screen_fade_alpha = 0.0;
  }
  if (console_open_flag != '\0') {
    frame_dt = 0.0;
  }
  (*grim_interface_ptr->vtable->grim_get_mouse_dx)();
  if ((extraout_ST0_00 == (float10)0.0) ||
     ((*grim_interface_ptr->vtable->grim_get_mouse_dy)(), extraout_ST0_01 == (float10)0.0)) {
    DAT_004871cb = 0;
  }
  else {
    DAT_004871cb = 1;
    ui_mouse_blocked = 0;
    DAT_004808c8 = 0;
  }
  fStack_20 = 0.0;
  fStack_1c = 0.0;
  (*grim_interface_ptr->vtable->grim_get_config_float)(player_state_table.input.axis_aim_x);
  fVar9 = (float)extraout_ST0_02;
  (*grim_interface_ptr->vtable->grim_get_config_float)(player_state_table.input.axis_aim_y);
  if ((float10)0.2 < SQRT((float10)fVar9 * (float10)fVar9 + extraout_ST0_03 * extraout_ST0_03)) {
    fStack_1c = (float)extraout_ST0_03;
    fStack_20 = fVar9;
  }
  (*grim_interface_ptr->vtable->grim_get_config_float)(player_state_table.input.axis_move_x);
  fVar9 = (float)extraout_ST0_04;
  (*grim_interface_ptr->vtable->grim_get_config_float)(player_state_table.input.axis_move_y);
  if ((float10)0.2 < SQRT((float10)fVar9 * (float10)fVar9 + extraout_ST0_05 * extraout_ST0_05)) {
    fStack_20 = fStack_20 + fVar9;
    fStack_1c = (float)((float10)fStack_1c + extraout_ST0_05);
  }
  if (0.2 < SQRT(fStack_20 * fStack_20 + fStack_1c * fStack_1c)) {
    DAT_004808c8 = 1;
  }
  if (game_state_id == 9) {
    DAT_004808c8 = 0;
LAB_0040c71b:
    (*grim_interface_ptr->vtable->grim_get_mouse_dx)();
    ui_mouse_x = (float)(extraout_ST0_06 * (float10)(float)config_blob.reserved8 +
                         extraout_ST0_06 * (float10)(float)config_blob.reserved8 +
                        (float10)ui_mouse_x);
    (*grim_interface_ptr->vtable->grim_get_mouse_dy)();
    pfVar4 = (float *)&player_aim_screen_x;
    ui_mouse_y = (float)(extraout_ST0_07 * (float10)(float)config_blob.reserved8 +
                         extraout_ST0_07 * (float10)(float)config_blob.reserved8 +
                        (float10)ui_mouse_y);
    do {
      *pfVar4 = ui_mouse_x;
      pfVar4[1] = ui_mouse_y;
      pfVar4 = pfVar4 + 2;
    } while ((int)pfVar4 < 0x487204);
  }
  else {
    if (DAT_004808c8 != 1) goto LAB_0040c71b;
    ui_mouse_x = (float)config_blob.reserved8 * frame_dt * fStack_20 * 540.0 + ui_mouse_x;
    ui_mouse_y = (float)config_blob.reserved8 * frame_dt * fStack_1c * 540.0 + ui_mouse_y;
  }
  if (ui_mouse_x < 0.0) {
    ui_mouse_x = 0.0;
  }
  if (ui_mouse_y < 0.0) {
    ui_mouse_y = 0.0;
  }
  if ((float)(config_blob.screen_width + -1) < ui_mouse_x) {
    ui_mouse_x = (float)(config_blob.screen_width + -1);
  }
  if ((float)(config_blob.screen_height + -1) < ui_mouse_y) {
    ui_mouse_y = (float)(config_blob.screen_height + -1);
  }
  if ((game_state_id == 0x16) || (DAT_004824d1 != '\0')) {
    FUN_0040b630();
  }
  else if (game_state_id == 9) {
    if (demo_purchase_screen_active == '\0') {
      gameplay_update_and_render();
    }
    else {
      (*grim_interface_ptr->vtable->grim_clear_color)(0.0,0.0,0.0,0.0);
    }
    if (demo_mode_active != '\0') {
LAB_0040c8a0:
      demo_purchase_screen_update();
    }
    if (audio_suspend_flag != '\0') {
      return;
    }
  }
  else {
    if (game_state_id == 0x18) {
      gameplay_update_and_render();
      goto LAB_0040c8a0;
    }
    if (game_state_id == 6) {
      perk_selection_screen_update();
    }
    else if (game_state_id == 7) {
      game_over_screen_update();
    }
    else if (game_state_id == 8) {
      quest_results_screen_update();
    }
    else if (game_state_id == 0xc) {
      quest_failed_screen_update();
    }
    else if (game_state_id == 0x12) {
      survival_gameplay_update_and_render();
    }
    else if (game_state_id == 0x15) {
      game_update_victory_screen();
    }
    else {
      demo_purchase_screen_active = '\0';
      game_update_generic_menu();
    }
  }
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,2.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.6);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3ecccccd);
  iVar2 = game_is_full_version();
  if ((char)iVar2 == '\0') {
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.3,0.3,0.6);
  }
  fVar9 = 0.45;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3ee66666);
  if (*(float *)((int)cv_showFPS + 0xc) != 0.0) {
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.6);
    (*grim_interface_ptr->vtable->grim_get_fps)();
    lVar8 = __ftol();
    pIVar1 = grim_interface_ptr->vtable;
    if ((int)lVar8 < 400) {
      (*pIVar1->grim_get_fps)();
      lVar8 = __ftol();
      uVar5 = (undefined4)lVar8;
      pcVar3 = &DAT_00471f40;
      iVar2 = config_blob.screen_width + -0x2d;
    }
    else {
      (*pIVar1->grim_get_fps)();
      lVar8 = __ftol();
      uVar5 = (undefined4)lVar8;
      pcVar3 = &DAT_00472990;
      iVar2 = config_blob.screen_width + -0x33;
    }
    (*pIVar1->grim_draw_text_small_fmt)
              (grim_interface_ptr,(float)iVar2,(float)(config_blob.screen_height + -0x18),pcVar3,
               uVar5);
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.6);
  console_render(&console_log_queue);
  crt_rand();
  audio_update();
  iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(1);
  if ((((char)iVar2 != '\0') && ((render_pass_mode != '\0' || (game_state_id == 0x16)))) &&
     ((game_state_id == 9 || ((game_state_id == 0x16 || (game_state_id == 0x12)))))) {
    ui_transition_direction = 0;
    game_state_pending = 5;
    if (plugin_interface_ptr != (mod_interface_t *)0x0) {
      (plugin_interface_ptr->parms).fields.onPause = '\x01';
    }
  }
  if (DAT_00471308 == 0xffffffff) {
    uVar6 = crt_rand();
    DAT_00471308 = uVar6 & 0x8000001f;
    if ((int)DAT_00471308 < 0) {
      DAT_00471308 = (DAT_00471308 - 1 | 0xffffffe0) + 1;
    }
  }
  if ((((game_state_id == 4) && (render_pass_mode == '\0')) && (local_system_time._2_2_ == 3)) &&
     ((local_system_day == 3 && (DAT_00471308 == 3)))) {
    DAT_00471308 = 0xffffffff;
    (*grim_interface_ptr->vtable->grim_set_color)(0.2,1.0,0.6,0.5);
    pcVar3 = s_Orbes_Volantes_Exstare_00472978;
    y = 5.0;
    pIVar1 = grim_interface_ptr->vtable;
    uVar6 = crt_rand();
    uVar6 = uVar6 & 0x8000003f;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
    }
    (*pIVar1->grim_draw_text_small)((float)(int)(uVar6 + 0x10),y,pcVar3);
  }
  iVar2 = game_is_full_version();
  if ((char)iVar2 == '\0') {
    if (demo_mode_active == '\0') {
      FUN_0041df50();
      (*grim_interface_ptr->vtable->grim_draw_rect_filled)
                ((float *)&stack0xffffffac,(float)config_blob.screen_width,8.0);
      (*grim_interface_ptr->vtable->grim_draw_rect_filled)
                ((float *)&stack0xffffffa8,(float)(config_blob.screen_width + -4) * fVar9,3.0);
      goto LAB_0040cd14;
    }
LAB_0040cd20:
    if (game_state_pending == 0) {
      iVar2 = ui_elements_max_timeline();
      if (iVar2 == 0) {
        fVar9 = 1.0;
      }
      else {
        fVar9 = 1.0 - (float)ui_elements_timeline / (float)iVar2;
      }
      fVar9 = fVar9 * fVar9;
      if (game_state_prev == 0x18) {
        fVar9 = 1.0 - fVar9;
        demo_purchase_screen_active = '\0';
      }
      if (0.0 <= fVar9) {
        if (1.0 < fVar9) {
          fVar9 = 1.0;
        }
      }
      else {
        fVar9 = 0.0;
      }
      (*grim_interface_ptr->vtable->grim_draw_fullscreen_color)(0.0,0.0,0.0,fVar9);
    }
  }
  else {
LAB_0040cd14:
    if (demo_mode_active != '\0') goto LAB_0040cd20;
  }
  if (game_state_pending == 10) {
    iVar2 = ui_elements_max_timeline();
    if (iVar2 == 0) {
      fVar9 = 1.0;
    }
    else {
      fVar9 = 1.0 - (float)ui_elements_timeline / (float)iVar2;
    }
    if (game_state_prev == 0x16) {
      fVar9 = 1.0 - fVar9;
    }
    if (0.0 <= fVar9) {
      if (1.0 < fVar9) {
        fVar9 = 1.0;
      }
    }
    else {
      fVar9 = 0.0;
    }
    (*grim_interface_ptr->vtable->grim_draw_fullscreen_color)(0.0,0.0,0.0,fVar9);
  }
  iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x10);
  if (((char)iVar2 == '\0') ||
     (iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x38), (char)iVar2 == '\0')) {
    if (DAT_0047ea50 == '\0') goto LAB_0040cf06;
  }
  else {
    DAT_0047ea50 = '\x01';
  }
  iVar2 = game_is_full_version();
  if ((char)iVar2 != '\0') {
    config_sync_from_grim();
    return;
  }
  if (shareware_offer_seen_latch != '\0') {
    return;
  }
  iVar2 = game_is_full_version();
  if ((char)iVar2 != '\0') {
    return;
  }
  config_sync_from_grim();
  demo_mode_start();
  sfx_mute_all(music_track_crimson_theme_id);
  sfx_mute_all(music_track_extra_0);
  sfx_mute_all(music_track_intro_id);
  sfx_play_exclusive(music_track_shortie_monk_id);
  DAT_0047ea50 = '\0';
  shareware_offer_seen_latch = '\x01';
LAB_0040cf06:
  if (DAT_004d7a24 != '\0') {
    DAT_004d7a24 = '\0';
    ui_render_loading();
    ui_render_loading();
    audio_suspend_all();
    game_is_full_version();
  }
  if (DAT_004d7a25 != '\0') {
    DAT_004d7a25 = '\0';
    ui_render_loading();
    ui_render_loading();
    audio_suspend_all();
    game_is_full_version();
  }
  if (DAT_004d7a26 != '\0') {
    DAT_004d7a26 = '\0';
    ui_render_loading();
    ui_render_loading();
    audio_suspend_all();
    game_is_full_version();
  }
  if ((((DAT_004d11f0 == 0) && (DAT_004d11f8 != '\0')) && (DAT_004d11f4 != 0)) &&
     ((game_state_id != 0xe || (DAT_00480838 != '\0')))) {
    Sleep(100);
    return;
  }
  return;
}



