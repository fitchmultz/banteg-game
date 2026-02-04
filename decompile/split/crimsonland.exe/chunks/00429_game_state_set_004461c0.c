/* game_state_set @ 004461c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* resets UI state, updates game_state_prev/id, and seeds UI elements for the new state */

void __cdecl game_state_set(int state_id)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  ui_element_t *puVar6;
  float fVar7;
  uint auStack_10 [4];
  
  iVar1 = state_id;
  ui_elements_reset_state();
  game_paused_flag = 0;
  game_state_prev = game_state_id;
  game_state_id = state_id;
  _DAT_00487238 = 0;
  DAT_00487241 = 0;
  (*grim_interface_ptr->vtable->grim_flush_input)();
  console_input_poll();
  if (state_id == 0) {
    highscore_return_latch = '\0';
    render_pass_mode = '\0';
    ui_sign_crimson = 1;
    iVar3 = game_is_full_version();
    if ((char)iVar3 != '\0') {
      bVar2 = mods_any_available();
      if (bVar2) {
        DAT_00488208 = 1;
      }
    }
    iVar3 = game_is_full_version();
    if ((char)iVar3 == '\0') {
      DAT_00488208 = 1;
    }
    else {
      _DAT_0048823c = &LAB_00447350;
    }
    state_id = 0;
    iVar3 = 2;
    do {
      if (iVar3 == 2) {
        iVar4 = game_is_full_version();
        if ((char)iVar4 != '\0') {
          state_id = 4;
        }
      }
      pcVar5 = (char *)(*grim_interface_ptr->vtable->grim_get_config_var)(auStack_10,100);
      if (*pcVar5 == '\0') {
        if (iVar3 == 6) {
          state_id = 6;
        }
        (&ui_element_table_end)[iVar3]->counter_id = DAT_0048f7f4;
        puVar6 = (&ui_element_table_end)[iVar3];
        puVar6->_pad4[0x14] = '\0';
        puVar6->_pad4[0x15] = '\0';
        puVar6->_pad4[0x16] = '\0';
        puVar6->_pad4[0x17] = '\0';
        *(float *)(puVar6->_pad4 + 0x18) = (float)state_id * 0.125;
        puVar6 = (&ui_element_table_end)[iVar3];
        puVar6->_pad4[0x30] = '\0';
        puVar6->_pad4[0x31] = '\0';
        puVar6->_pad4[0x32] = 0x80;
        puVar6->_pad4[0x33] = '?';
        *(float *)(puVar6->_pad4 + 0x34) = (float)state_id * 0.125;
        puVar6 = (&ui_element_table_end)[iVar3];
        puVar6->_pad4[0x4c] = '\0';
        puVar6->_pad4[0x4d] = '\0';
        puVar6->_pad4[0x4e] = 0x80;
        puVar6->_pad4[0x4f] = '?';
        fVar7 = (float)(state_id + 1) * 0.125;
        *(float *)(puVar6->_pad4 + 0x50) = fVar7;
        puVar6 = (&ui_element_table_end)[iVar3];
        puVar6->_pad4[0x68] = '\0';
        puVar6->_pad4[0x69] = '\0';
        puVar6->_pad4[0x6a] = '\0';
        puVar6->_pad4[0x6b] = '\0';
      }
      else {
        (&ui_element_table_end)[iVar3]->counter_id = DAT_0048f7f4;
        puVar6 = (&ui_element_table_end)[iVar3];
        puVar6->_pad4[0x14] = '\0';
        puVar6->_pad4[0x15] = '\0';
        puVar6->_pad4[0x16] = '\0';
        puVar6->_pad4[0x17] = '\0';
        *(float *)(puVar6->_pad4 + 0x18) = (float)state_id * 0.125;
        puVar6 = (&ui_element_table_end)[iVar3];
        puVar6->_pad4[0x30] = '\0';
        puVar6->_pad4[0x31] = '\0';
        puVar6->_pad4[0x32] = 0x80;
        puVar6->_pad4[0x33] = '?';
        *(float *)(puVar6->_pad4 + 0x34) = (float)state_id * 0.125;
        puVar6 = (&ui_element_table_end)[iVar3];
        puVar6->_pad4[0x4c] = '\0';
        puVar6->_pad4[0x4d] = '\0';
        puVar6->_pad4[0x4e] = 0x80;
        puVar6->_pad4[0x4f] = '?';
        fVar7 = (float)(state_id + 1) * 0.125;
        *(float *)(puVar6->_pad4 + 0x50) = fVar7;
        puVar6 = (&ui_element_table_end)[iVar3];
        puVar6->_pad4[0x68] = '\0';
        puVar6->_pad4[0x69] = '\0';
        puVar6->_pad4[0x6a] = '\0';
        puVar6->_pad4[0x6b] = '\0';
      }
      *(float *)(puVar6->_pad4 + 0x6c) = fVar7;
      if (iVar3 == 2) {
        iVar4 = game_is_full_version();
        if ((char)iVar4 != '\0') {
          state_id = 0;
        }
      }
      iVar4 = state_id + 1;
      if (iVar4 == 4) {
        iVar4 = state_id + 2;
      }
      iVar3 = iVar3 + 1;
      state_id = iVar4;
    } while (iVar3 < 8);
    iVar3 = game_is_full_version();
    if ((char)iVar3 == '\0') {
      DAT_00488208 = 1;
    }
    DAT_004878c0 = 1;
    DAT_00487bd8 = 1;
    DAT_00487ef0 = 1;
    DAT_00488520 = 1;
    pcVar5 = (char *)(*grim_interface_ptr->vtable->grim_get_config_var)(auStack_10,100);
    if (*pcVar5 == '\0') {
      DAT_00488520 = 0;
    }
    DAT_00488838 = 1;
  }
  else if (state_id == 0x16) {
    render_pass_mode = '\0';
    ui_sign_crimson_update_disabled = 0;
  }
  else if (state_id == 9) {
    DAT_0048eb38 = 1;
    DAT_0048702c = 0;
    if (render_pass_mode == '\0') {
      highscore_return_latch = '\0';
      gameplay_reset_state();
      iVar4 = _quest_stage_minor;
      iVar3 = _quest_stage_major;
      if (config_blob.reserved0._24_4_ == 3) {
        game_status_blob.quest_play_counts[_quest_stage_minor + _quest_stage_major * 10] =
             game_status_blob.quest_play_counts[_quest_stage_minor + _quest_stage_major * 10] + 1;
        quest_start_selected(iVar3,iVar4);
        render_pass_mode = '\x01';
        DAT_00487241 = 1;
      }
      else if (config_blob.reserved0._24_4_ == 2) {
        render_pass_mode = '\x01';
        game_status_blob.mode_play_rush = game_status_blob.mode_play_rush + 1;
        DAT_00487241 = 1;
      }
      else if (config_blob.reserved0._24_4_ == 1) {
        render_pass_mode = '\x01';
        game_status_blob.mode_play_survival = game_status_blob.mode_play_survival + 1;
        DAT_00487241 = 1;
      }
      else if (config_blob.reserved0._24_4_ == 4) {
        render_pass_mode = '\x01';
        game_status_blob.mode_play_typo = game_status_blob.mode_play_typo + 1;
        DAT_00487241 = 1;
      }
      else {
        render_pass_mode = '\x01';
        game_status_blob.mode_play_other = game_status_blob.mode_play_other + 1;
        DAT_00487241 = 1;
      }
    }
  }
  else if (state_id == 0x12) {
    config_blob.reserved0[0x14] = '\x01';
    config_blob.reserved0[0x15] = '\0';
    config_blob.reserved0[0x16] = '\0';
    config_blob.reserved0[0x17] = '\0';
    DAT_00478c94 = 1;
    DAT_0048eb38 = 1;
    DAT_0048702c = 0;
    if (render_pass_mode == '\0') {
      highscore_return_latch = '\0';
      gameplay_reset_state();
      render_pass_mode = '\x01';
      DAT_00487241 = 1;
    }
  }
  else if (state_id == 1) {
    ui_sign_crimson = 1;
    DAT_00489498 = 1;
    DAT_004897b0 = 1;
  }
  else if (state_id == 2) {
    if (DAT_004824d1 == '\0') {
      ui_sign_crimson = 1;
    }
    DAT_00488b50 = 1;
    _DAT_0048cf78 = 0xc2680000;
    DAT_00488e68 = 1;
    ui_screen_phase = 0;
    _DAT_0048cf7c = (((float)config_blob.screen_width * 0.0015625 * 150.0 + 10.0) - 150.0) + 135.0;
  }
  else if (state_id == 4) {
    highscore_return_latch = '\0';
    ui_sign_crimson = 1;
    DAT_0048e820 = 1;
    _DAT_0048e858 = &LAB_0043f550;
  }
  else if (state_id == 0xd) {
    _DAT_00489e18 = FUN_00446140;
LAB_00446764:
    DAT_00489de0._0_1_ = 1;
    ui_sign_crimson = 1;
    highscore_load_table();
  }
  else if (state_id == 3) {
    ui_sign_crimson = 1;
    _DAT_0048cf78 = 0xc3340000;
    DAT_0048d278 = 1;
    DAT_0048d590 = 1;
    DAT_0048ee50._0_1_ = 1;
    _DAT_0048cf7c = ((float)config_blob.screen_width * 0.0015625 * 150.0 - 150.0) + 139.0;
  }
  else if (state_id == 0xe) {
    DAT_0048a0f8 = 1;
    _DAT_00489e18 = (code *)&LAB_004423d0;
    goto LAB_00446764;
  }
  _DAT_0048a130 = 0;
  if (iVar1 == 0x13) {
    ui_sign_crimson = 1;
    DAT_00489de0._0_1_ = 1;
  }
  else if (iVar1 == 0x1a) {
    ui_sign_crimson = 1;
    DAT_00489de0._0_1_ = 1;
    _DAT_00489e18 = credits_secret_alien_zookeeper_update;
  }
  else if (iVar1 == 0x14) {
    ui_sign_crimson = 1;
    DAT_00489de0._0_1_ = 1;
    _DAT_00489e18 = (code *)&LAB_0040e9a0;
  }
  else if (iVar1 == 0xf) {
    ui_sign_crimson = 1;
    DAT_00489de0._0_1_ = 1;
    DAT_0048a0f8 = 1;
    _DAT_00489e18 = (code *)&LAB_00440110;
  }
  else if (iVar1 == 0x10) {
    ui_sign_crimson = 1;
    DAT_00489de0._0_1_ = 1;
    DAT_0048a0f8 = 1;
    _DAT_00489e18 = (code *)&LAB_00440960;
  }
  else if (iVar1 == 0x11) {
    ui_screen_phase = 0;
    ui_sign_crimson = 1;
    DAT_00489de0._0_1_ = 1;
    _DAT_00489e18 = credits_screen_update;
  }
  else if (iVar1 == 0xb) {
    ui_sign_crimson = 1;
    DAT_0048e1f0 = 1;
  }
  else if (iVar1 == 5) {
    if (DAT_004824d1 == '\0') {
      ui_sign_crimson = 1;
    }
    ui_sign_crimson_update_disabled = 0;
    DAT_0048b9b8 = 1;
    DAT_0048bcd0 = 1;
    DAT_0048bfe8 = 1;
  }
  else if (iVar1 == 6) {
    DAT_0048c618 = 1;
  }
  else if (iVar1 == 8) {
    DAT_0048dbc0 = 1;
    game_save_status();
    ui_screen_phase = -2;
  }
  else {
    if (iVar1 == 0x15) {
      DAT_0048dbc0 = 1;
    }
    else if (iVar1 == 0xc) {
      DAT_0048dbc0 = 1;
    }
    else {
      if (iVar1 != 7) goto LAB_004468da;
      DAT_0048cc48 = 1;
      _DAT_00487260 = 0;
    }
    ui_screen_phase = -1;
  }
LAB_004468da:
  if (highscore_return_latch != '\0') {
    ui_sign_crimson = 0;
  }
  ui_elements_timeline = 0;
  ui_transition_direction = 1;
  return;
}



