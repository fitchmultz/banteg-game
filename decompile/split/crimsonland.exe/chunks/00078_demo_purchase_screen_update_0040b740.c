/* demo_purchase_screen_update @ 0040b740 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* demo upsell screen: feature list, purchase link, and exit handling */

void demo_purchase_screen_update(void)

{
  float fVar1;
  char cVar2;
  IGrim2D_vtbl *pIVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  float unaff_EBP;
  float unaff_EDI;
  char *pcVar7;
  float10 fVar8;
  longlong lVar9;
  int iVar10;
  float fVar11;
  int iVar12;
  float fVar13;
  int w;
  float fVar14;
  char *text;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  if ((ui_transition_direction != '\0') && (iVar5 = game_is_full_version(), (char)iVar5 != '\0')) {
    ui_transition_direction = '\0';
    game_state_pending = 0;
    demo_mode_active = 1;
    config_load_presets();
    sfx_mute_all(music_track_intro_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_play_exclusive(music_track_crimson_theme_id);
    ui_elements_update_and_render();
    ui_cursor_render();
    return;
  }
  if ((demo_purchase_screen_active == '\0') &&
     (((iVar5 = input_primary_just_pressed(), (char)iVar5 != '\0' ||
       (iVar5 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(1), (char)iVar5 != '\0')) ||
      (iVar5 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x39), (char)iVar5 != '\0')))) {
    demo_purchase_screen_active = '\x01';
    demo_time_limit_ms = 16000;
  }
  if ((DAT_00480320 & 1) == 0) {
    DAT_00480320 = DAT_00480320 | 1;
    DAT_004802b6 = 1;
    DAT_004802c5 = 0;
    DAT_004802c4 = 0;
    _DAT_004802c0 = 0x3f800000;
    _DAT_004802bc = 0;
    _DAT_004802b0 = (char *)0x0;
    DAT_004802b4 = 0;
    DAT_004802b5 = 0;
    _DAT_004802b8 = 0;
    crt_atexit(&DAT_0040c1b0);
  }
  _DAT_004802b0 = s_Maybe_later_00471b78;
  if ((DAT_00480320 & 2) == 0) {
    DAT_00480320 = DAT_00480320 | 2;
    DAT_0047f67e = 1;
    DAT_0047f68d = 0;
    DAT_0047f68c = 0;
    _DAT_0047f688 = 0x3f800000;
    _DAT_0047f684 = 0;
    _DAT_0047f678 = (char *)0x0;
    DAT_0047f67c = 0;
    DAT_0047f67d = 0;
    _DAT_0047f680 = 0;
    crt_atexit(&DAT_0040c1a0);
  }
  _DAT_0047f678 = s_Purchase_00471b6c;
  fStack_20 = 1.0;
  fStack_2c = (float)quest_spawn_timeline * 0.016;
  if (fStack_2c < 20.0) {
    fStack_20 = fStack_2c * 0.05;
  }
  if (demo_time_limit_ms + -500 < quest_spawn_timeline) {
    fStack_1c = (float)(demo_time_limit_ms - quest_spawn_timeline);
    fStack_20 = (float)(int)fStack_1c * 0.002;
  }
  fVar13 = 1.0;
  fVar14 = fStack_20;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_20);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f4ccccd);
  text = &s_empty_string;
  if (demo_purchase_screen_active == '\0') {
    if (quest_spawn_timeline == 0) {
      demo_upsell_message_index = (demo_upsell_message_index + 1) % 5;
    }
    if (demo_upsell_message_index == 0) {
      text = s_Want_more_Levels__00472780;
    }
    else if (demo_upsell_message_index == 1) {
      text = s_Want_more_Weapons__0047276c;
    }
    else if (demo_upsell_message_index == 2) {
      text = s_Want_more_Perks__00472758;
    }
    else if (demo_upsell_message_index == 3) {
      text = s_Want_unlimited_Play_time__0047273c;
    }
    else if (demo_upsell_message_index == 4) {
      text = s_Want_to_post_your_high_scores__0047271c;
    }
  }
  else {
    ui_pulse_timer_ms = ui_pulse_timer_ms + frame_dt_ms;
    fVar8 = (float10)fsin((float10)(ui_pulse_timer_ms % 1000) * (float10)6.2831855);
    fVar1 = (float)(fVar8 * fVar8);
    (*grim_interface_ptr->vtable->grim_set_color_slot)(0,0.0,0.0,0.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_color_slot)(1,0.0,0.0,0.3,1.0);
    (*grim_interface_ptr->vtable->grim_set_color_slot)(2,0.0,0.4,fVar1 * 0.55,fVar1);
    (*grim_interface_ptr->vtable->grim_set_color_slot)(3,0.0,0.4,0.4,1.0);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,0.5,0.5);
    iVar10 = 0;
    pIVar3 = grim_interface_ptr->vtable;
    iVar5 = (*pIVar3->grim_get_texture_handle)(s_backplasma_0047296c);
    (*pIVar3->grim_bind_texture)(iVar5,iVar10);
    (*grim_interface_ptr->vtable->grim_draw_quad)
              (0.0,0.0,(float)config_blob.screen_width,(float)config_blob.screen_height);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
    fStack_28 = 0.0;
    if (config_blob.screen_width == 800) {
      fStack_28 = 64.0;
    }
    else if (config_blob.screen_width == 0x400) {
      fStack_28 = 128.0;
    }
    iVar5 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_mockup_00472964);
    w = 0x100;
    iVar10 = config_blob.screen_height / 2 + -0x8c;
    iVar12 = 0x200;
    fStack_1c = (float)(config_blob.screen_width / 2 + -0x80);
    lVar9 = __ftol();
    ui_draw_textured_quad((int)lVar9,iVar10,iVar12,w,iVar5);
    iVar5 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_cl_logo_00471f70);
    iVar12 = 0x40;
    fStack_1c = (float)(config_blob.screen_height / 2 + -200);
    iVar10 = 0x200;
    lVar9 = __ftol();
    ui_draw_textured_quad(config_blob.screen_width / 2 + -0x100,(int)lVar9,iVar10,iVar12,iVar5);
    fVar13 = 1.0;
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f19999a);
    fVar14 = (float)(config_blob.screen_height / 2 + -0x68);
    lVar9 = __ftol();
    fVar4 = (float)(int)lVar9;
    (*grim_interface_ptr->vtable->grim_draw_text_small)
              (fVar4,fVar14,s_Upgrade_to_the_full_version_of_C_00472930);
    fVar14 = fVar14 + 28.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small)
              (fVar4,fVar14,s_Full_version_features__00472918);
    fStack_28 = fVar14 + 15.0;
    fVar11 = 1.0;
    pIVar3 = grim_interface_ptr->vtable;
    fStack_2c = fVar4;
    iVar5 = (*pIVar3->grim_measure_text_width)(s_Full_version_features__00472918);
    (*pIVar3->grim_draw_rect_outline)(&fStack_2c,(float)iVar5,fVar11);
    fVar14 = fVar14 + 22.0;
    fVar11 = (float)((int)lVar9 + 8);
    (*grim_interface_ptr->vtable->grim_draw_text_small)
              (fVar11,fVar14,s__Unlimited_Play_Time_in_three_th_004728e4);
    fVar14 = fVar14 + 22.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar11,fVar14,s__The_varied_weapon_arsenal_consi_004728ac);
    fVar14 = fVar14 + 17.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar11,fVar14,s_weapons_that_allow_you_to_deal_d_00472870);
    fVar14 = fVar14 + 17.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar11,fVar14,s_fire_and_electricity__00472858);
    fVar14 = fVar14 + 22.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar11,fVar14,s__Over_40_game_altering_Perks__00472838);
    fVar14 = fVar14 + 22.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar11,fVar14,s__40_insane_Levels_that_give_you_00472818);
    fVar14 = fVar14 + 18.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar11,fVar14,s_hours_of_intense_and_fun_gamepla_004727f4);
    fVar14 = fVar14 + 22.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small)
              (fVar11,fVar14,s__The_ability_to_post_your_high_s_004727c4);
    fVar14 = fVar14 + 22.0 + 22.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small)
              (fVar4,fVar14,s_Purchasing_the_game_is_very_easy_00472794);
    fVar14 = fVar14 + 17.0 + 17.0 + 22.0;
    fStack_2c = (float)(config_blob.screen_width / 2 + 0x80);
    fStack_28 = (float)(config_blob.screen_height / 2 + 0x66) + fVar1 * 0.3 + 50.0;
    iVar5 = ui_button_update(&fStack_2c,(ui_button_t *)&DAT_0047f678);
    if ((char)iVar5 != '\0') {
      shareware_offer_seen_latch = '\x01';
      DAT_0047ea50 = 1;
      ShellExecuteA((HWND)0x0,&DAT_00471b38,s_http___buy_crimsonland_com_00471b40,(LPCSTR)0x0,
                    (LPCSTR)0x0,1);
      return;
    }
    fStack_2c = (float)(config_blob.screen_width / 2 + 0x80);
    unaff_EDI = (float)(config_blob.screen_height / 2 + 0x66);
    fStack_28 = (float)(int)unaff_EDI + fVar1 * 0.3 + 90.0;
    iVar5 = ui_button_update(&fStack_2c,(ui_button_t *)&DAT_004802b0);
    if ((char)iVar5 != '\0') {
      if (shareware_offer_seen_latch != '\0') {
        DAT_0047ea50 = 1;
      }
      ui_transition_direction = '\0';
      game_state_pending = 0;
      demo_mode_active = 1;
      if (shareware_offer_seen_latch != '\0') {
        demo_mode_active = 1;
        ui_transition_direction = '\0';
        game_state_pending = 0;
        return;
      }
      config_load_presets();
      sfx_mute_all(music_track_intro_id);
      sfx_mute_all(music_track_crimsonquest_id);
      sfx_play_exclusive(music_track_crimson_theme_id);
      return;
    }
    quest_spawn_timeline = quest_spawn_timeline + frame_dt_ms;
    if (demo_time_limit_ms < quest_spawn_timeline) {
      render_pass_mode = 0;
      demo_mode_start();
    }
    if (demo_purchase_screen_active != '\0') goto LAB_0040c103;
  }
  uVar6 = 0xffffffff;
  pcVar7 = text;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  uStack_24 = 0;
  fStack_20 = 0.0;
  fStack_1c = 0.0;
  fVar1 = (float)(~uVar6 - 1) * 12.8;
  fStack_2c = 60.0;
  fVar4 = ((float)quest_spawn_timeline / (float)demo_time_limit_ms) * fVar1;
  fStack_18 = unaff_EBP * 0.5;
  fStack_28 = (fVar14 + 50.0) - 4.0;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&fStack_2c,fVar1 + 12.0,30.0);
  fStack_1c = fVar4 * 0.8;
  fStack_2c = fVar13 + 72.0;
  fStack_28 = 0.5;
  uStack_24 = 0x3dcccccd;
  fStack_20 = 0.1;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)((float *)&stack0xffffffd0,unaff_EDI,3.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,unaff_EDI);
  (*grim_interface_ptr->vtable->grim_draw_text_mono)(50.0,fVar4,text);
LAB_0040c103:
  ui_elements_update_and_render();
  ui_cursor_render();
  return;
}



