/* quest_failed_screen_update @ 004107e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* quest failure screen: retry options and navigation */

void quest_failed_screen_update(void)

{
  float fVar1;
  int iVar2;
  int x;
  IGrim2D_vtbl *pIVar3;
  longlong lVar4;
  int y;
  int w;
  char *text;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  _bonus_reflex_boost_timer = 0;
  if ((((game_state_id == 0xc) && (game_state_pending == 0x19)) && (ui_transition_direction != '\0')
      ) && (iVar2 = sfx_is_unmuted(music_track_shortie_monk_id), (char)iVar2 == '\0')) {
    sfx_play_exclusive(music_track_shortie_monk_id);
  }
  gameplay_render_world();
  ui_elements_update_and_render();
  perk_prompt_update_and_render();
  local_4 = _DAT_0048dbdc + DAT_0048dc00;
  local_10 = DAT_0048dbfc + _DAT_0048dbd8 + 180.0;
  fVar1 = local_4 + 40.0;
  w = 0x40;
  local_18 = (_DAT_0048dbc8 + local_10 + 44.0) - 10.0;
  y = 0x100;
  iVar2 = DAT_0048f7f8;
  local_14 = fVar1;
  local_c = fVar1;
  local_8 = local_18;
  lVar4 = __ftol();
  x = (int)lVar4;
  lVar4 = __ftol();
  ui_draw_textured_quad((int)lVar4,x,y,w,iVar2);
  if (ui_screen_phase == -1) {
    highscore_load_table();
    DAT_00482604 = highscore_rank_index();
    highscore_active_record.game_mode_id = config_blob.reserved0[0x18];
    (*grim_interface_ptr->vtable->grim_flush_input)();
    console_input_poll();
    (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c);
    ui_screen_phase = 0;
  }
  else if (ui_screen_phase != 0) goto LAB_00410cc1;
  local_18 = local_8 + 30.0;
  local_14 = fVar1 + 70.0 + 16.0;
  switch(quest_fail_retry_count) {
  default:
    text = s_Quest_failed__try_again__004731bc;
    pIVar3 = grim_interface_ptr->vtable;
    break;
  case 1:
    text = s_You_didn_t_make_it__do_try_again_00473244;
    pIVar3 = grim_interface_ptr->vtable;
    break;
  case 2:
    text = s_Third_time_no_good__00473230;
    pIVar3 = grim_interface_ptr->vtable;
    break;
  case 3:
    text = s_No_luck_this_time__have_another_g_0047320c;
    pIVar3 = grim_interface_ptr->vtable;
    break;
  case 4:
    text = s_Persistence_will_be_rewared__004731ec;
    pIVar3 = grim_interface_ptr->vtable;
    break;
  case 5:
    text = s_Try_one_more_time__004731d8;
    pIVar3 = grim_interface_ptr->vtable;
  }
  (*pIVar3->grim_draw_text_small)(local_18,local_14,text);
  local_14 = local_14 + 16.0;
  local_18 = local_18 + 6.0;
  local_10 = local_18 + 4.0;
  local_c = local_14 + 10.0;
  ui_text_input_render(&local_10,6.652423e-39,1.0);
  local_14 = local_14 + 98.0;
  local_18 = local_18 + 16.0;
  if ((DAT_004825d8 & 1) == 0) {
    DAT_004825d8 = DAT_004825d8 | 1;
    DAT_00482686 = 1;
    DAT_00482695 = 0;
    DAT_00482694 = 0;
    _DAT_00482690 = 0x3f800000;
    _DAT_0048268c = 0;
    _DAT_00482680 = (char *)0x0;
    DAT_00482684 = 0;
    DAT_00482685 = '\0';
    _DAT_00482688 = 0;
    crt_atexit(&DAT_00410d10);
  }
  _DAT_00482680 = s_Play_Again_00473164;
  if ((DAT_004825d8 & 2) == 0) {
    DAT_004825d8 = DAT_004825d8 | 2;
    DAT_0048269e = 1;
    DAT_004826ad = 0;
    DAT_004826ac = 0;
    _DAT_004826a8 = 0x3f800000;
    _DAT_004826a4 = 0;
    _DAT_00482698 = (char *)0x0;
    DAT_0048269c = 0;
    DAT_0048269d = '\0';
    _DAT_004826a0 = 0;
    crt_atexit(&DAT_00410d00);
  }
  _DAT_00482698 = s_Play_Another_004731ac;
  if ((DAT_004825d8 & 4) == 0) {
    DAT_004825d8 = DAT_004825d8 | 4;
    DAT_004824f6 = 1;
    DAT_00482505 = 0;
    DAT_00482504 = 0;
    _DAT_00482500 = 0x3f800000;
    _DAT_004824fc = 0;
    _DAT_004824f0 = (char *)0x0;
    DAT_004824f4 = 0;
    DAT_004824f5 = '\0';
    _DAT_004824f8 = 0;
    crt_atexit(&DAT_00410cf0);
  }
  _DAT_004824f0 = s_Main_Menu_00472084;
  ui_button_update(&local_18,(ui_button_t *)&DAT_00482680);
  local_14 = local_14 + 32.0;
  ui_button_update(&local_18,(ui_button_t *)&DAT_00482698);
  local_14 = local_14 + 32.0;
  ui_button_update(&local_18,(ui_button_t *)&DAT_004824f0);
  local_14 = local_14 + 32.0;
  if (DAT_00482685 != '\0') {
    quest_fail_retry_count = quest_fail_retry_count + 1;
    ui_transition_direction = '\0';
    game_state_pending = 9;
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_mute_all(music_track_extra_0);
    render_pass_mode = 0;
  }
  if (DAT_0048269d != '\0') {
    quest_fail_retry_count = 0;
    ui_transition_direction = '\0';
    game_state_pending = 0xb;
    ui_sign_crimson_update_disabled = 0;
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_mute_all(music_track_extra_0);
    sfx_play_exclusive(music_track_crimson_theme_id);
  }
  if (DAT_004824f5 != '\0') {
    quest_fail_retry_count = 0;
    sfx_mute_all(music_track_extra_0);
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_play_exclusive(music_track_crimson_theme_id);
    ui_transition_direction = '\0';
    game_state_pending = 0;
    ui_sign_crimson_update_disabled = 0;
  }
LAB_00410cc1:
  ui_cursor_render();
  return;
}



