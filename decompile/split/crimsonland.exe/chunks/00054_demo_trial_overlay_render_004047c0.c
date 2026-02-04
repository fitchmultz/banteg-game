/* demo_trial_overlay_render @ 004047c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders the demo trial warning panel and remaining time message */

void __cdecl demo_trial_overlay_render(float *xy,float alpha)

{
  IGrim2D_vtbl *pIVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  float fVar7;
  char acStack_118 [8];
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  float local_104;
  char acStack_98 [152];
  
  local_104 = alpha * 0.8;
  DAT_00480850 = 1;
  local_110 = 0;
  local_10c = 0;
  local_108 = 0;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(xy,512.0,256.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,(float)xy);
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)(xy,512.0,256.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  fVar7 = 0.0;
  pIVar1 = grim_interface_ptr->vtable;
  iVar3 = (*pIVar1->grim_get_texture_handle)(s_cl_logo_00471f70);
  (*pIVar1->grim_bind_texture)(iVar3,(int)fVar7);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_draw_quad)(*xy + 72.0,xy[1] + 22.0,371.2,46.4);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,*xy + 131.0,xy[1] + 9.0,s_You_ve_been_playing_the_Demo_ver_00471f48)
  ;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,(float)xy);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  fVar7 = *xy + 26.0;
  fVar2 = xy[1] + 80.0;
  iVar3 = FUN_0041df50();
  iVar3 = iVar3 - game_status_blob.game_sequence_id;
  if (0 < demo_trial_elapsed_ms) {
    iVar3 = 300000 - demo_trial_elapsed_ms;
  }
  iVar5 = (iVar3 / 1000) / 0x3c;
  iVar4 = (int)((ulonglong)((longlong)iVar5 * 0x77777777) >> 0x20) - iVar5;
  iVar5 = iVar5 + ((iVar4 >> 5) - (iVar4 >> 0x1f)) * 0x3c;
  iVar4 = iVar3 / 1000 + iVar5 * -0x3c;
  iVar3 = (iVar3 + (iVar5 * 0x3c + iVar4) * -1000) / 10;
  if (iVar5 < 0) {
    iVar4 = 0;
    iVar3 = 0;
    pcVar6 = &DAT_00471f44;
    iVar5 = 0;
  }
  else if (iVar4 < 10) {
    pcVar6 = &DAT_00471f44;
  }
  else {
    pcVar6 = &DAT_00471f40;
  }
  crt_sprintf(acStack_98,pcVar6,iVar4);
  if (iVar3 < 10) {
    pcVar6 = s__d__s_0_d_00471f34;
  }
  else {
    pcVar6 = s__d__s__d_00471f28;
  }
  crt_sprintf(acStack_118,pcVar6,iVar5,acStack_98,iVar3);
  iVar3 = game_is_full_version();
  if ((((char)iVar3 == '\0') && (config_blob.reserved0._24_4_ != 8)) &&
     (game_status_blob.game_sequence_id = game_sequence_get(),
     (int)game_status_blob.game_sequence_id < 0x249f01)) {
    if (demo_trial_elapsed_ms < 1) {
      if (config_blob.reserved0._24_4_ == 3) goto LAB_00404b1b;
    }
    else if ((config_blob.reserved0._24_4_ == 3) &&
            ((float)(demo_trial_elapsed_ms / 1000) * 0.016666668 <= 5.0)) {
LAB_00404b1b:
      if ((game_state_id == 9) && ((1 < _quest_stage_major || (10 < _quest_stage_minor)))) {
        fVar2 = fVar2 - 6.0;
        if (demo_trial_elapsed_ms < 1) {
          (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                    (grim_interface_ptr,fVar7,fVar2,s_You_ve_completed_all_Quest_mode_l_00471ee0);
          (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                    (grim_interface_ptr,fVar7,fVar2 + 18.0,
                     s_However__you_still_have__s_time_l_00471e94,acStack_118);
          fVar2 = fVar2 + 18.0 + 18.0;
          (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                    (grim_interface_ptr,fVar7,fVar2,&s_empty_string);
          fVar2 = fVar2 + 14.0;
        }
        else {
          (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                    (grim_interface_ptr,fVar7,fVar2 + 6.0,
                     s_You_ve_completed_all_Quest_mode_l_00471ee0);
          fVar2 = fVar2 + 6.0 + 18.0;
        }
        (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                  (grim_interface_ptr,fVar7,fVar2,s_If_you_would_like_to_have_unlimi_00471e48);
        (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                  (grim_interface_ptr,fVar7,fVar2 + 18.0,s_please_upgrade_to_the_full_versi_00471e14
                  );
        fVar2 = fVar2 + 18.0 + 22.0;
        (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                  (grim_interface_ptr,fVar7,fVar2,s_The_full_version_features_unrest_00471ddc);
        fVar2 = fVar2 + 18.0;
        (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                  (grim_interface_ptr,fVar7,fVar2,s_game_modes_and_be_able_to_post_y_00471d94);
        fVar2 = fVar2 + 18.0;
        goto LAB_00404ee5;
      }
    }
  }
  if ((iVar5 < 1) && (iVar4 < 1)) {
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_Trial_time_is_up__If_you_would_l_00471d44);
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2 + 18.0,s_all_features__please_upgrade_to_t_00471cf4);
    fVar2 = fVar2 + 18.0 + 18.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_is_very_easy_and_takes_just_minu_00471ccc);
    fVar2 = fVar2 + 24.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_Buy_the_full_version_to_gain_unr_00471c90);
    fVar2 = fVar2 + 18.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_game_modes_and_be_able_to_post_y_00471d94);
    fVar2 = fVar2 + 18.0;
  }
  else {
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2 - 7.0,s_You_have_used_up_your_play_time_i_00471c48,
               acStack_118);
    fVar2 = (fVar2 - 7.0) + 16.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_have__s_time_left_to_play_Quest_m_00471c14,
               acStack_118);
    fVar2 = fVar2 + 22.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_If_you_would_like_to_have_unlimi_00471e48);
    fVar2 = fVar2 + 16.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_please_upgrade_to_the_full_versi_00471bc4);
    fVar2 = fVar2 + 16.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_and_takes_just_minutes__00471ba8);
    fVar2 = fVar2 + 22.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_Buy_the_full_version_to_gain_unr_00471c90);
    fVar2 = fVar2 + 16.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fVar7,fVar2,s_game_modes_and_be_able_to_post_y_00471d94);
    fVar2 = fVar2 + 16.0;
  }
LAB_00404ee5:
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,fVar7,fVar2,s_it_now__You_ll_have_a_great_time_00471b84);
  if ((DAT_0047f62c & 1) == 0) {
    DAT_0047f62c = DAT_0047f62c | 1;
    ui_button_maybe_later.enabled = '\x01';
    ui_button_maybe_later.force_wide = '\0';
    ui_button_maybe_later.force_small = '\0';
    ui_button_maybe_later.alpha = 1.0;
    ui_button_maybe_later.click_anim = 0;
    ui_button_maybe_later.label = (char *)0x0;
    ui_button_maybe_later.hovered = '\0';
    ui_button_maybe_later.activated = '\0';
    ui_button_maybe_later.hover_anim = 0;
    crt_atexit(&DAT_00405150);
  }
  ui_button_maybe_later.label = s_Maybe_later_00471b78;
  if ((DAT_0047f62c & 2) == 0) {
    DAT_0047f62c = DAT_0047f62c | 2;
    ui_button_table_a.enabled = '\x01';
    ui_button_table_a.force_wide = '\0';
    ui_button_table_a.force_small = '\0';
    ui_button_table_a.alpha = 1.0;
    ui_button_table_a.click_anim = 0;
    ui_button_table_a.label = (char *)0x0;
    ui_button_table_a.hovered = '\0';
    ui_button_table_a.activated = '\0';
    ui_button_table_a.hover_anim = 0;
    crt_atexit(&DAT_00405140);
  }
  ui_button_table_a.label = s_Purchase_00471b6c;
  if ((DAT_0047f62c & 4) == 0) {
    DAT_0047f62c = DAT_0047f62c | 4;
    ui_button_already_paid.enabled = '\x01';
    ui_button_already_paid.force_wide = '\0';
    ui_button_already_paid.force_small = '\0';
    ui_button_already_paid.alpha = 1.0;
    ui_button_already_paid.click_anim = 0;
    ui_button_already_paid.label = (char *)0x0;
    ui_button_already_paid.hovered = '\0';
    ui_button_already_paid.activated = '\0';
    ui_button_already_paid.hover_anim = 0;
    crt_atexit(&DAT_00405130);
  }
  ui_button_already_paid.label = s_Already_paid_00471b5c;
  iVar3 = ui_button_update((float *)&stack0xfffffec4,&ui_button_table_a);
  if ((char)iVar3 != '\0') {
    shareware_offer_seen_latch = 1;
    DAT_0047ea50 = 1;
    ShellExecuteA((HWND)0x0,&DAT_00471b38,s_http___buy_crimsonland_com_00471b40,(LPCSTR)0x0,
                  (LPCSTR)0x0,1);
  }
  iVar3 = ui_button_update((float *)&stack0xfffffed0,&ui_button_maybe_later);
  if ((char)iVar3 != '\0') {
    ui_transition_direction = 0;
    game_state_pending = 0;
    render_pass_mode = 0;
    sfx_mute_all(music_track_intro_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_mute_all(music_track_extra_0);
    sfx_play_exclusive(music_track_crimson_theme_id);
  }
  return;
}



