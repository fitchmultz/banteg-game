/* game_update_victory_screen @ 00406350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_406350() */

int game_update_victory_screen(void)

{
  int extraout_EAX;
  IGrim2D_vtbl *pIVar1;
  char *pcVar2;
  float fVar3;
  float fVar4;
  
  gameplay_render_world();
  ui_elements_update_and_render();
  fVar4 = 1.0;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  if (ui_screen_phase == -1) {
    ui_screen_phase = 0;
  }
  fVar3 = 0.8;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f4ccccd);
  if (config_blob.hardcore == '\0') {
    pcVar2 = s_Congratulations__004722c8;
  }
  else {
    pcVar2 = s_Incredible__004722b8;
  }
  (*grim_interface_ptr->vtable->grim_draw_text_mono_fmt)(grim_interface_ptr,fVar3,fVar4,pcVar2);
  fVar4 = 0.5;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  if (config_blob.hardcore == '\0') {
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_You_ve_completed_all_the_levels_b_00472288);
    fVar3 = fVar3 + 14.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_isn_t_over_yet__With_all_of_the_u_00472258);
    fVar3 = fVar3 + 14.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_and_weapons_your_Survival_is_jus_00472228);
    fVar3 = fVar3 + 14.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_You_can_also_replay_the_quests_i_004721fc);
    fVar3 = fVar3 + 14.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_As_an_additional_reward_for_your_004721d0);
    fVar3 = fVar3 + 14.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_playing__a_completely_new_and_di_004721a0);
    pcVar2 = s_mode_is_unlocked_for_you__Typ_o__00472174;
    pIVar1 = grim_interface_ptr->vtable;
  }
  else {
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_You_ve_done_the_thing_we_all_tho_00472148);
    fVar3 = fVar3 + 14.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_virtually_impossible__To_reward_y_00472120);
    fVar3 = fVar3 + 14.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_efforts_a_new_weapon_has_been_un_004720f8);
    fVar3 = fVar3 + 14.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,s_for_you__Splitter_Gun__004720e0);
    fVar3 = fVar3 + 14.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar4,fVar3,&s_empty_string);
    pcVar2 = &s_empty_string;
    pIVar1 = grim_interface_ptr->vtable;
  }
  fVar3 = fVar3 + 14.0;
  (*pIVar1->grim_draw_text_small_fmt)(grim_interface_ptr,fVar4,fVar3,pcVar2);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,fVar4,fVar3 + 14.0 + 8.0,s_Good_luck_with_your_battles__tro_004720b8
            );
  if ((game_completed_screen_flags & 1) == 0) {
    game_completed_screen_flags = game_completed_screen_flags | 1;
    DAT_0047f5e6 = 1;
    DAT_0047f5f5 = 0;
    DAT_0047f5f4 = 0;
    _DAT_0047f5f0 = 0x3f800000;
    _DAT_0047f5ec = 0;
    _DAT_0047f5e0 = (char *)0x0;
    DAT_0047f5e4 = 0;
    DAT_0047f5e5 = '\0';
    _DAT_0047f5e8 = 0;
    crt_atexit(&DAT_00406ae0);
  }
  _DAT_0047f5e0 = s_Survival_004720ac;
  if ((game_completed_screen_flags & 2) == 0) {
    game_completed_screen_flags = game_completed_screen_flags | 2;
    DAT_00480286 = 1;
    DAT_00480295 = 0;
    DAT_00480294 = 0;
    _DAT_00480290 = 0x3f800000;
    _DAT_0048028c = 0;
    _DAT_00480280 = (char *)0x0;
    DAT_00480284 = 0;
    DAT_00480285 = '\0';
    _DAT_00480288 = 0;
    crt_atexit(&DAT_00406ad0);
  }
  _DAT_00480280 = s_Rush_004720a0;
  if ((game_completed_screen_flags & 4) == 0) {
    game_completed_screen_flags = game_completed_screen_flags | 4;
    DAT_0048032e = 1;
    DAT_0048033d = 0;
    DAT_0048033c = 0;
    _DAT_00480338 = 0x3f800000;
    _DAT_00480334 = 0;
    _DAT_00480328 = (char *)0x0;
    DAT_0048032c = 0;
    DAT_0048032d = '\0';
    _DAT_00480330 = 0;
    crt_atexit(&DAT_00406ac0);
  }
  _DAT_00480328 = s_Typ_o_Shooter_00472090;
  if ((game_completed_screen_flags & 8) == 0) {
    game_completed_screen_flags = game_completed_screen_flags | 8;
    DAT_0048026e = 1;
    DAT_0048027d = 0;
    DAT_0048027c = 0;
    _DAT_00480278 = 0x3f800000;
    _DAT_00480274 = 0;
    _DAT_00480268 = (char *)0x0;
    DAT_0048026c = 0;
    DAT_0048026d = '\0';
    _DAT_00480270 = 0;
    crt_atexit(&DAT_00406ab0);
  }
  _DAT_00480268 = s_Main_Menu_00472084;
  ui_button_update((float *)&stack0xffffffc0,(ui_button_t *)&DAT_0047f5e0);
  ui_button_update((float *)&stack0xffffffc0,(ui_button_t *)&DAT_00480280);
  ui_button_update((float *)&stack0xffffffc0,(ui_button_t *)&DAT_00480328);
  ui_button_update((float *)&stack0xffffffc0,(ui_button_t *)&DAT_00480268);
  if (DAT_00480285 != '\0') {
    ui_transition_direction = 0;
    game_state_pending = 9;
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_mute_all(music_track_extra_0);
    config_blob.reserved0[0x18] = '\x02';
    config_blob.reserved0[0x19] = '\0';
    config_blob.reserved0[0x1a] = '\0';
    config_blob.reserved0[0x1b] = '\0';
  }
  if (DAT_0047f5e5 != '\0') {
    ui_transition_direction = 0;
    game_state_pending = 9;
    config_blob.reserved0[0x18] = '\x01';
    config_blob.reserved0[0x19] = '\0';
    config_blob.reserved0[0x1a] = '\0';
    config_blob.reserved0[0x1b] = '\0';
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_mute_all(music_track_extra_0);
  }
  if (DAT_0048032d != '\0') {
    render_pass_mode = 0;
    ui_transition_direction = 0;
    game_state_pending = 0x12;
    config_blob.reserved0[0x18] = '\x04';
    config_blob.reserved0[0x19] = '\0';
    config_blob.reserved0[0x1a] = '\0';
    config_blob.reserved0[0x1b] = '\0';
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_mute_all(music_track_extra_0);
    DAT_0048702c = 1;
  }
  if (DAT_0048026d != '\0') {
    sfx_mute_all(music_track_extra_0);
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_play_exclusive(music_track_crimson_theme_id);
    ui_transition_direction = 0;
    game_state_pending = 0;
    ui_sign_crimson_update_disabled = 0;
  }
  ui_cursor_render();
  return extraout_EAX;
}



