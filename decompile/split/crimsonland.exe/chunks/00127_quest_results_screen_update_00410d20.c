/* quest_results_screen_update @ 00410d20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* quest/campaign results screen: final time, perk bonus, high score entry, and buttons */

void quest_results_screen_update(void)

{
  char cVar1;
  IGrim2D_vtbl *pIVar2;
  float fVar3;
  float a;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  highscore_record_t *phVar10;
  undefined4 *puVar11;
  char *pcVar12;
  highscore_record_t *phVar13;
  longlong lVar14;
  int y;
  int w;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  _bonus_reflex_boost_timer = 0;
  quest_fail_retry_count = 0;
  if ((((game_state_id == 8) && (game_state_pending == 0x19)) && (ui_transition_direction != '\0'))
     && (iVar4 = sfx_is_unmuted(music_track_shortie_monk_id), (char)iVar4 == '\0')) {
    sfx_play_exclusive(music_track_crimsonquest_id);
  }
  gameplay_render_world();
  ui_elements_update_and_render();
  if (((byte)quest_results_screen_flags & 1) == 0) {
    quest_results_screen_flags._0_1_ = (byte)quest_results_screen_flags | 1;
    DAT_00482526 = 1;
    DAT_00482535 = 0;
    DAT_00482534 = 0;
    _DAT_00482530 = 1.0;
    _DAT_0048252c = 0;
    _DAT_00482520 = (undefined *)0x0;
    DAT_00482524 = 0;
    DAT_00482525 = '\0';
    _DAT_00482528 = 0;
    crt_atexit(&DAT_00412070);
  }
  if (((byte)quest_results_screen_flags & 2) == 0) {
    quest_results_screen_flags._0_1_ = (byte)quest_results_screen_flags | 2;
    _DAT_004826f8 = 1.0;
    _DAT_004826e8 = &DAT_004825dc;
    DAT_004826ec = 0;
    _DAT_004826f0 = 0x18;
    _DAT_004826f4 = 0x60;
    crt_atexit(&DAT_00412060);
  }
  local_4 = _DAT_0048dbdc + DAT_0048dc00;
  w = 0x40;
  y = 0x100;
  local_18 = DAT_0048dbfc + _DAT_0048dbd8 + 180.0;
  local_14 = local_4 + 40.0;
  local_10 = local_18 + _DAT_0048dbc8 + 40.0;
  iVar4 = DAT_0048f804;
  local_c = local_14;
  lVar14 = __ftol();
  iVar8 = (int)lVar14;
  lVar14 = __ftol();
  ui_draw_textured_quad((int)lVar14,iVar8,y,w,iVar4);
  fVar3 = local_c + 56.0;
  local_8 = local_10;
  local_c = fVar3;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  if (((game_state_prev == 0xe) && (ui_transition_direction != '\0')) &&
     (highscore_return_latch != '\0')) {
    highscore_return_latch = '\0';
    ui_screen_phase = 2;
  }
  else {
    if (ui_screen_phase == -2) {
      iVar4 = _quest_stage_minor + -0xb + _quest_stage_major * 10;
      DAT_00482700 = (&quest_selected_meta)[iVar4].unlock_weapon_id;
      DAT_00482704 = (&quest_selected_meta)[iVar4].unlock_perk_id;
      lVar14 = __ftol();
      local_18 = (float)lVar14;
      player_state_table.health = (float)(int)local_18;
      lVar14 = __ftol();
      iVar4 = (int)lVar14;
      if (config_blob.reserved0._20_4_ == 2) {
        DAT_00482600 = iVar4;
        lVar14 = __ftol();
        iVar4 = iVar4 + (int)lVar14;
      }
      DAT_0048270c = (quest_spawn_timeline + perk_pending_count * -1000) - iVar4;
      highscore_active_record.survival_elapsed_ms = DAT_0048270c;
      if (DAT_0048270c == 0) {
        highscore_active_record.survival_elapsed_ms = 1;
      }
      quest_results_anim_timer = 0;
      DAT_00482600 = iVar4;
      highscore_record_init();
      DAT_00482724 = 700;
      ui_screen_phase = ui_screen_phase + 1;
      DAT_00482710 = 0;
      DAT_00482714 = 0;
      DAT_00482718 = 0;
      quest_results_step = 0;
      DAT_00482720 = 0;
    }
    if (ui_screen_phase == -1) {
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
      local_c = local_c + 40.0;
      DAT_00482724 = DAT_00482724 - frame_dt_ms;
      if (DAT_00482724 < 1) {
        if (quest_results_step < 3) {
          if (quest_results_step == 0) {
            DAT_00482710 = DAT_00482710 + 2000;
            DAT_00482724 = 0x28;
            sfx_play(sfx_ui_clink_01);
            DAT_00482720 = DAT_00482710;
            if (quest_spawn_timeline <= (int)DAT_00482710) {
              quest_results_step = quest_results_step + 1;
              DAT_00482710 = quest_spawn_timeline;
              DAT_00482720 = DAT_00482710;
            }
          }
          else if (quest_results_step == 1) {
            DAT_00482714 = DAT_00482714 + 1000;
            DAT_00482724 = 0x96;
            sfx_play(sfx_ui_clink_01);
            DAT_00482720 = DAT_00482720 - 1000;
            if (DAT_00482600 <= DAT_00482714) {
              DAT_00482714 = DAT_00482600;
              quest_results_step = quest_results_step + 1;
            }
          }
          else if (quest_results_step == 2) {
            DAT_00482718 = DAT_00482718 + 1;
            DAT_00482724 = 300;
            sfx_play(sfx_ui_clink_01);
            DAT_00482720 = DAT_00482720 - 1000;
            if (perk_pending_count <= DAT_00482718) {
              DAT_00482718 = perk_pending_count;
              quest_results_step = quest_results_step + 1;
              DAT_00482724 = 1000;
              highscore_active_record.survival_elapsed_ms = DAT_0048270c;
              DAT_00482720 = DAT_0048270c;
            }
          }
        }
        else if (quest_results_step == 3) {
          DAT_00482724 = 0x32;
          quest_results_anim_timer = quest_results_anim_timer + 1;
        }
      }
      local_18 = 1.0 - (float)quest_results_anim_timer * 0.1;
      if (0.0 <= local_18) {
        if (1.0 < local_18) {
          local_18 = 1.0;
        }
      }
      else {
        local_18 = 0.0;
      }
      fVar3 = local_18;
      local_10 = local_10 + 32.0;
      local_c = local_c + 20.0;
      if (quest_results_step == 0) {
        (*grim_interface_ptr->vtable->grim_set_color)(0.1,0.8,0.1,local_18);
      }
      else {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,local_18 * 0.4);
      }
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_10,local_c,s_Base_Time__004732f4);
      pIVar2 = grim_interface_ptr->vtable;
      iVar4 = FUN_0040ff50((int)DAT_00482710 / 1000);
      (*pIVar2->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_10 + 132.0,local_c,&s_fmt_percent_s,iVar4);
      local_c = local_c + 20.0;
      if (quest_results_step == 1) {
        (*grim_interface_ptr->vtable->grim_set_color)(0.1,0.8,0.1,fVar3);
      }
      else {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,local_18 * 0.4);
      }
      if (quest_results_step < 1) {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,local_18 * 0.2);
      }
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_10,local_c,s_Life_Bonus__004732e8);
      pIVar2 = grim_interface_ptr->vtable;
      iVar4 = FUN_0040ff50(DAT_00482714 / 1000);
      (*pIVar2->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_10 + 132.0,local_c,&s_fmt_percent_s,iVar4);
      local_c = local_c + 20.0;
      if (quest_results_step == 2) {
        (*grim_interface_ptr->vtable->grim_set_color)(0.1,0.8,0.1,fVar3);
      }
      else {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,local_18 * 0.4);
      }
      if (quest_results_step < 2) {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,local_18 * 0.2);
      }
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_10,local_c,s_Unpicked_Perk_Bonus__004732d0);
      pIVar2 = grim_interface_ptr->vtable;
      iVar4 = FUN_0040ff50(DAT_00482718);
      (*pIVar2->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_10 + 132.0,local_c,&s_fmt_percent_s,iVar4);
      local_c = local_c + 20.0;
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar3);
      local_18 = local_10 - 4.0;
      local_14 = local_c + 1.0;
      (*grim_interface_ptr->vtable->grim_draw_rect_outline)(&local_18,168.0,1.0);
      local_c = local_c + 8.0;
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_10,local_c,s_Final_Time__004732c4);
      pIVar2 = grim_interface_ptr->vtable;
      iVar4 = FUN_0040ff50((int)DAT_00482720 / 1000);
      (*pIVar2->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_10 + 132.0,local_c,&s_fmt_percent_s,iVar4);
      local_c = local_c + 20.0;
      (*grim_interface_ptr->vtable->grim_flush_input)();
      (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c);
      if ((ui_screen_phase == -1) &&
         ((iVar4 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x39), (char)iVar4 != '\0' ||
          (iVar4 = input_primary_just_pressed(), (char)iVar4 != '\0')))) {
        ui_screen_phase = ui_screen_phase + 1;
        perk_prompt_update_and_render();
        ui_cursor_render();
        return;
      }
      if (10 < quest_results_anim_timer) {
        quest_results_anim_timer = 0;
        ui_screen_phase = ui_screen_phase + 1;
        perk_prompt_update_and_render();
        ui_cursor_render();
        return;
      }
      goto LAB_00412007;
    }
    if (ui_screen_phase == 0) {
      highscore_load_table();
      DAT_00482620 = highscore_rank_index();
      (*grim_interface_ptr->vtable->grim_flush_input)();
      (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c);
      if (99 < DAT_00482620) {
        DAT_004826ec = 0;
        _DAT_004826f0 = 0;
        _DAT_004826e8 = &DAT_004825dc;
        ui_screen_phase = 2;
        perk_prompt_update_and_render();
        ui_cursor_render();
        return;
      }
      uVar6 = 0xffffffff;
      _DAT_004826f0 = 0x14;
      phVar13 = &highscore_active_record;
      do {
        phVar10 = phVar13;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        phVar10 = (highscore_record_t *)(phVar13->player_name + 1);
        pcVar5 = phVar13->player_name;
        phVar13 = phVar10;
      } while (*pcVar5 != '\0');
      uVar6 = ~uVar6;
      _DAT_004826e8 = &DAT_004825dc;
      ui_screen_phase = 1;
      puVar9 = (undefined4 *)((int)phVar10 - uVar6);
      puVar11 = (undefined4 *)&DAT_004825dc;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      uVar6 = 0xffffffff;
      phVar13 = &highscore_active_record;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar5 = phVar13->player_name;
        phVar13 = (highscore_record_t *)(phVar13->player_name + 1);
      } while (*pcVar5 != '\0');
      DAT_004826ec = ~uVar6 - 1;
      perk_prompt_update_and_render();
      ui_cursor_render();
      return;
    }
    if (ui_screen_phase == 1) {
      if (quest_results_anim_timer < 500) {
        quest_results_anim_timer = quest_results_anim_timer + frame_dt_ms;
      }
      else {
        quest_results_anim_timer = 500;
      }
      DAT_00496604 = (float)quest_results_anim_timer * 0.002;
      local_c = local_c + 22.0;
      local_18 = DAT_00496604;
      (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004965f8);
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_10 + 42.0,local_c,s_State_your_name_trooper__004732a8);
      local_c = local_c + 32.0;
      DAT_00496604 = 0.7;
      local_8 = local_10 + 170.0;
      _DAT_004826f4 = 0xa6;
      _DAT_004826f8 = local_18;
      _DAT_00482520 = &DAT_0047318c;
      _DAT_00482530 = local_18;
      local_4 = local_c - 8.0;
      ui_button_update(&local_8,(ui_button_t *)&DAT_00482520);
      iVar4 = ui_text_input_update(&local_10,(int *)&DAT_004826e8);
      if (((char)iVar4 != '\0') || (DAT_00482525 != '\0')) {
        uVar6 = 0xffffffff;
        iVar4 = 0;
        pcVar5 = &DAT_004825dc;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar8 = ~uVar6 - 1;
        if (0 < iVar8) {
          if (0 < iVar8) {
            do {
              if ((&DAT_004825dc)[iVar4] != ' ') break;
              iVar4 = iVar4 + 1;
            } while (iVar4 < iVar8);
          }
          if ((&DAT_004825dc)[iVar4] != '\0') {
            ui_screen_phase = 2;
            sfx_play(sfx_ui_typeenter);
            iVar4 = DAT_004826ec;
            uVar6 = 0xffffffff;
            pcVar5 = &DAT_004825dc;
            do {
              pcVar12 = pcVar5;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar12 = pcVar5 + 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar12;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            player_name_length = DAT_004826ec;
            pcVar5 = pcVar12 + -uVar6;
            phVar13 = &highscore_active_record;
            for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
              *(undefined4 *)phVar13->player_name = *(undefined4 *)pcVar5;
              pcVar5 = pcVar5 + 4;
              phVar13 = (highscore_record_t *)(phVar13->player_name + 4);
            }
            DAT_004826ec = 0;
            _DAT_004826f0 = 0;
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              phVar13->player_name[0] = *pcVar5;
              pcVar5 = pcVar5 + 1;
              phVar13 = (highscore_record_t *)(phVar13->player_name + 1);
            }
            highscore_active_record.player_name[iVar4] = '\0';
            _DAT_004826e8 = &DAT_004825dc;
            highscore_save_active();
            highscore_load_table();
            goto LAB_00411906;
          }
        }
        DAT_00482525 = '\0';
        sfx_play(sfx_shock_hit_01);
      }
LAB_00411906:
      local_c = local_c + 30.0;
      (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004965f8);
      local_8 = local_10 + 26.0;
      local_4 = local_c + 16.0;
      ui_text_input_render(&local_8,6.652423e-39,local_18);
      perk_prompt_update_and_render();
      ui_cursor_render();
      return;
    }
    if (ui_screen_phase != 2) goto LAB_00412007;
  }
  if (quest_results_anim_timer < 500) {
    quest_results_anim_timer = quest_results_anim_timer + frame_dt_ms;
  }
  else {
    quest_results_anim_timer = 500;
  }
  a = (float)quest_results_anim_timer * 0.002;
  local_10 = local_8 + 30.0;
  local_18 = a;
  local_c = fVar3;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,a);
  if (99 < DAT_00482620) {
    local_c = local_c + 6.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,local_10 + 8.0,local_c,s_Score_too_low_for_top_d__00473170,100);
    local_c = local_c + 6.0;
  }
  local_8 = local_10;
  local_4 = local_c + 16.0;
  ui_text_input_render(&local_8,6.652423e-39,a);
  local_c = local_c + 78.0 + 6.0;
  if (DAT_00482700 != 0) {
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.7);
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,local_10,local_c + 1.0,s_Weapon_unlocked__00473294);
    local_c = local_c + 14.0;
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.9);
    pIVar2 = grim_interface_ptr->vtable;
    pcVar5 = weapon_table_entry((&quest_selected_meta)
                                [_quest_stage_minor + -0xb + _quest_stage_major * 10].
                                unlock_weapon_id);
    (*pIVar2->grim_draw_text_small_fmt)(grim_interface_ptr,local_10,local_c,&s_fmt_percent_s,pcVar5)
    ;
    local_c = local_c + 16.0;
  }
  if (DAT_00482704 != perk_id_antiperk) {
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.7);
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,local_10,local_c + 1.0,s_Perk_unlocked__00473284);
    local_c = local_c + 14.0;
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.9);
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,local_10,local_c,&s_fmt_percent_s,
               (&perk_meta_table)
               [(&quest_selected_meta)[_quest_stage_minor + -0xb + _quest_stage_major * 10].
                unlock_perk_id].name);
    local_c = local_c + 16.0;
  }
  if (((byte)quest_results_screen_flags & 4) == 0) {
    quest_results_screen_flags._0_1_ = (byte)quest_results_screen_flags | 4;
    DAT_004825c6 = 1;
    DAT_004825d5 = 0;
    DAT_004825d4 = 0;
    _DAT_004825d0 = 1.0;
    _DAT_004825cc = 0;
    _DAT_004825c0 = (char *)0x0;
    DAT_004825c4 = 0;
    DAT_004825c5 = '\0';
    _DAT_004825c8 = 0;
    crt_atexit(&DAT_00412050);
  }
  _DAT_004825c0 = s_Play_Next_00473278;
  if (((byte)quest_results_screen_flags & 8) == 0) {
    quest_results_screen_flags._0_1_ = (byte)quest_results_screen_flags | 8;
    DAT_0048260e = 1;
    DAT_0048261d = 0;
    DAT_0048261c = 0;
    _DAT_00482618 = 1.0;
    _DAT_00482614 = 0;
    _DAT_00482608 = (char *)0x0;
    DAT_0048260c = 0;
    DAT_0048260d = '\0';
    _DAT_00482610 = 0;
    crt_atexit(&DAT_00412040);
  }
  _DAT_00482608 = s_Play_Again_00473164;
  if (((byte)quest_results_screen_flags & 0x10) == 0) {
    quest_results_screen_flags._0_1_ = (byte)quest_results_screen_flags | 0x10;
    DAT_0048266e = 1;
    DAT_0048267d = 0;
    DAT_0048267c = 0;
    _DAT_00482678 = 1.0;
    _DAT_00482674 = 0;
    _DAT_00482668 = (char *)0x0;
    DAT_0048266c = 0;
    DAT_0048266d = '\0';
    _DAT_00482670 = 0;
    crt_atexit(&DAT_00412030);
  }
  _DAT_00482668 = s_High_scores_00473158;
  if (((byte)quest_results_screen_flags & 0x20) == 0) {
    quest_results_screen_flags._0_1_ = (byte)quest_results_screen_flags | 0x20;
    DAT_004826b6 = 1;
    DAT_004826c5 = 0;
    DAT_004826c4 = 0;
    _DAT_004826c0 = 1.0;
    _DAT_004826bc = 0;
    _DAT_004826b0 = (char *)0x0;
    DAT_004826b4 = 0;
    DAT_004826b5 = '\0';
    _DAT_004826b8 = 0;
    crt_atexit(&DAT_00412020);
  }
  local_c = local_c + 6.0;
  _DAT_004826b0 = s_Main_Menu_00472084;
  if ((_quest_stage_major == 5) && (_quest_stage_minor == 10)) {
    _DAT_004825c0 = s_Show_End_Note_00473268;
  }
  local_10 = local_10 + 20.0;
  _DAT_00482678 = local_18;
  _DAT_004825d0 = local_18;
  _DAT_00482618 = local_18;
  _DAT_004826c0 = local_18;
  ui_button_update(&local_10,(ui_button_t *)&DAT_004825c0);
  local_c = local_c + 32.0;
  ui_button_update(&local_10,(ui_button_t *)&DAT_00482608);
  local_c = local_c + 32.0;
  ui_button_update(&local_10,(ui_button_t *)&DAT_00482668);
  local_c = local_c + 32.0;
  ui_button_update(&local_10,(ui_button_t *)&DAT_004826b0);
  local_c = local_c + 32.0;
  if (DAT_004825c5 != '\0') {
    if ((_quest_stage_major == 5) && (_quest_stage_minor == 10)) {
      render_pass_mode = 0;
      game_state_pending = 0x15;
      ui_transition_direction = '\0';
    }
    else {
      sfx_mute_all(music_track_extra_0);
      sfx_mute_all(music_track_crimson_theme_id);
      sfx_mute_all(music_track_shortie_monk_id);
      _quest_stage_minor = _quest_stage_minor + 1;
      ui_transition_direction = '\0';
      game_state_pending = 9;
      render_pass_mode = 0;
    }
  }
  if (DAT_0048260d != '\0') {
    ui_transition_direction = '\0';
    game_state_pending = 9;
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_mute_all(music_track_extra_0);
    render_pass_mode = 0;
  }
  if (DAT_0048266d != '\0') {
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
  if (DAT_004826b5 != '\0') {
    sfx_mute_all(music_track_extra_0);
    sfx_mute_all(music_track_crimson_theme_id);
    sfx_mute_all(music_track_shortie_monk_id);
    sfx_play_exclusive(music_track_crimson_theme_id);
    ui_transition_direction = '\0';
    game_state_pending = 0;
    ui_sign_crimson_update_disabled = 0;
  }
LAB_00412007:
  perk_prompt_update_and_render();
  ui_cursor_render();
  return;
}



