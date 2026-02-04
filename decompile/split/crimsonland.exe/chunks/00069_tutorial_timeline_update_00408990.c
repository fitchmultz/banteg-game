/* tutorial_timeline_update @ 00408990 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* drives tutorial stage timing, messages, and scripted spawns */

void tutorial_timeline_update(void)

{
  char *pcVar1;
  int iVar2;
  bonus_entry_t *pbVar3;
  uint uVar4;
  int *piVar5;
  float afStack_5c [6];
  char *local_44 [4];
  char *local_34;
  undefined *local_30;
  undefined *local_2c;
  char *local_28 [4];
  char *local_18;
  char *local_14;
  char *local_10;
  char *local_c;
  char *local_8;
  undefined *local_4;
  
  if (console_open_flag != '\0') {
    return;
  }
  tutorial_stage_timer = tutorial_stage_timer + frame_dt_ms;
  quest_spawn_timeline = quest_spawn_timeline + frame_dt_ms;
  local_44[0] = s_This_is_the_speed_powerup__it_ma_004726c4;
  local_44[1] = s_This_is_a_weapon_powerup__Pickin_00472664;
  local_44[2] = s_This_powerup_doubles_all_experie_00472614;
  local_44[3] = s_This_is_the_nuke_powerup__pickin_004725b8;
  local_34 = s_Reflex_Boost_powerup_slows_down_t_0047256c;
  local_30 = &tutorial_empty_string;
  local_2c = &tutorial_empty_string;
  local_28[0] = s_In_this_tutorial_you_ll_learn_ho_00472534;
  local_28[1] = s_First_learn_to_move_by_pushing_t_00472504;
  local_28[2] = s_Now_pick_up_the_bonuses_by_walki_004724d4;
  local_28[3] = s_Now_learn_to_shoot_and_move_at_t_00472480;
  local_18 = s_Now__move_the_mouse_to_aim_at_th_00472454;
  local_14 = s_It_will_help_you_to_move_and_sho_00472408;
  local_10 = s_Now_let_s_learn_about_Perks__You_0047238c;
  local_c = s_Perks_can_give_you_extra_abiliti_00472340;
  local_8 = s_Great__Now_you_are_ready_to_star_00472308;
  local_4 = &tutorial_empty_string;
  player_state_table.health = 100.0;
  if (tutorial_stage_index != 6) {
    player_state_table.experience = 0;
  }
  if (tutorial_stage_transition_timer < -1) {
    tutorial_stage_transition_timer = tutorial_stage_transition_timer + frame_dt_ms;
    if (tutorial_stage_transition_timer < -1) goto LAB_00408aa2;
    tutorial_stage_index = tutorial_stage_index + 1;
    if (tutorial_stage_index == 9) {
      tutorial_stage_index = 0;
    }
    tutorial_stage_transition_timer = 0;
  }
  else {
    if (-1 < tutorial_stage_transition_timer) {
      tutorial_stage_transition_timer = tutorial_stage_transition_timer + frame_dt_ms;
    }
LAB_00408aa2:
    if (1000 < tutorial_stage_transition_timer) {
      tutorial_stage_transition_timer = -1;
    }
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  iVar2 = tutorial_stage_transition_timer;
  if (tutorial_stage_transition_timer < 0) {
    if (tutorial_stage_transition_timer < -1) {
      iVar2 = -tutorial_stage_transition_timer;
      goto LAB_00408aeb;
    }
    afStack_5c[0] = 1.0;
LAB_00408b06:
    if (tutorial_stage_index != 5) goto LAB_00408b78;
    if ((5000 < tutorial_stage_timer) && (-2 < tutorial_stage_transition_timer)) {
      afStack_5c[0] = 1.0 - (float)(tutorial_stage_timer + -5000) * 0.001;
    }
LAB_00408b66:
    if (tutorial_stage_timer < 0x1771) goto LAB_00408b78;
    afStack_5c[0] = 0.0;
  }
  else {
LAB_00408aeb:
    afStack_5c[0] = (float)iVar2 * 0.001;
    if (1.0 <= afStack_5c[0]) goto LAB_00408b06;
    if (tutorial_stage_index == 5) goto LAB_00408b66;
LAB_00408b78:
    if (afStack_5c[0] <= 1.0) {
      if (afStack_5c[0] < 0.0) {
        afStack_5c[0] = 0.0;
      }
    }
    else {
      afStack_5c[0] = 1.0;
    }
    if ((tutorial_stage_index < 0) || ((tutorial_stage_index == 6 && (perk_pending_count < 1))))
    goto LAB_00408be2;
  }
  tutorial_prompt_dialog(local_28[tutorial_stage_index],afStack_5c[0]);
LAB_00408be2:
  if (DAT_004808b0 == '\0') {
    if ((((tutorial_hint_bonus_ptr != (char *)0x0) && (*tutorial_hint_bonus_ptr == '\0')) &&
        (*(float *)(tutorial_hint_bonus_ptr + 0x24) <= 0.0)) &&
       ((*(uint *)(tutorial_hint_bonus_ptr + 0x8c) & 0x400) != 0)) {
      _DAT_004712f4 = (int)*(short *)(tutorial_hint_bonus_ptr + 0x78);
      _DAT_004712f8 = (int)*(short *)(tutorial_hint_bonus_ptr + 0x7a);
      DAT_004808b0 = '\x01';
      afStack_5c[0] = 128.0;
      afStack_5c[1] = 128.0;
      creature_spawn_template(0x24,afStack_5c,3.1415927);
      afStack_5c[0] = 152.0;
      afStack_5c[1] = 160.0;
      creature_spawn_template(0x26,afStack_5c,3.1415927);
      tutorial_hint_index = tutorial_hint_index + 1;
    }
    tutorial_hint_alpha = tutorial_hint_alpha + frame_dt_ms * -3;
  }
  else {
    tutorial_hint_alpha = tutorial_hint_alpha + frame_dt_ms * 3;
  }
  if (tutorial_hint_alpha < 0x3e9) {
    if (tutorial_hint_alpha < 0) {
      tutorial_hint_alpha = 0;
    }
  }
  else {
    tutorial_hint_alpha = 1000;
  }
  if ((-1 < tutorial_hint_index) && (*local_44[tutorial_hint_index] != -0x59)) {
    tutorial_prompt_dialog(local_44[tutorial_hint_index],(float)tutorial_hint_alpha * 0.001);
  }
  if (tutorial_stage_index == 0) {
    if ((6000 < tutorial_stage_timer) && (tutorial_stage_transition_timer == -1)) {
      tutorial_repeat_spawn_count = 0;
      tutorial_hint_index = tutorial_stage_transition_timer;
      DAT_004808b0 = '\0';
      tutorial_stage_transition_timer = -1000;
      return;
    }
  }
  else {
    if (tutorial_stage_index == 1) {
      piVar5 = &player_state_table.input.move_key_backward;
      while ((((iVar2 = (*grim_interface_ptr->vtable->grim_is_key_active)
                                  (((player_input_t *)(piVar5 + -1))->move_key_forward),
               (char)iVar2 == '\0' &&
               (iVar2 = (*grim_interface_ptr->vtable->grim_is_key_active)(*piVar5),
               (char)iVar2 == '\0')) &&
              ((iVar2 = (*grim_interface_ptr->vtable->grim_is_key_active)(piVar5[1]),
               (char)iVar2 == '\0' &&
               (iVar2 = (*grim_interface_ptr->vtable->grim_is_key_active)(piVar5[2]),
               (char)iVar2 == '\0')))) || (tutorial_stage_transition_timer != -1))) {
        piVar5 = piVar5 + 0xd8;
        if (0x49129f < (int)piVar5) {
          return;
        }
      }
      tutorial_stage_transition_timer = -1000;
      sfx_play(sfx_ui_levelup);
      afStack_5c[0] = 260.0;
      afStack_5c[1] = 260.0;
      bonus_pool[0].bonus_id = BONUS_ID_POINTS;
      bonus_pool[0].time.time_left = 100.0;
      bonus_pool[0].time.time_max = 100.0;
      bonus_pool[0].state = '\0';
      bonus_pool[0].time.amount = 500;
      bonus_pool[0].time.pos_x = 260.0;
      bonus_pool[0].time.pos_y = 260.0;
      effect_spawn_burst(&bonus_pool[0].time.pos_x,0xc);
      afStack_5c[0] = 600.0;
      afStack_5c[1] = 400.0;
      bonus_pool[1].bonus_id = BONUS_ID_POINTS;
      bonus_pool[1].time.time_left = 100.0;
      bonus_pool[1].time.time_max = bonus_pool[0].time.time_left;
      bonus_pool[1].state = '\0';
      bonus_pool[1].time.amount = 1000;
      bonus_pool[1].time.pos_x = 600.0;
      bonus_pool[1].time.pos_y = 400.0;
      effect_spawn_burst(&bonus_pool[1].time.pos_x,0xc);
      afStack_5c[0] = 300.0;
      afStack_5c[1] = 400.0;
      bonus_pool[2].bonus_id = BONUS_ID_POINTS;
      bonus_pool[2].time.time_left = 100.0;
      bonus_pool[2].time.time_max = bonus_pool[0].time.time_left;
      bonus_pool[2].state = '\0';
      bonus_pool[2].time.amount = 500;
      bonus_pool[2].time.pos_x = 300.0;
      bonus_pool[2].time.pos_y = 400.0;
      effect_spawn_burst(&bonus_pool[2].time.pos_x,0xc);
      return;
    }
    if (tutorial_stage_index == 2) {
      iVar2 = 0;
      pbVar3 = bonus_pool;
      do {
        if (pbVar3->bonus_id != BONUS_ID_NONE) break;
        pbVar3 = pbVar3 + 1;
        iVar2 = iVar2 + 1;
      } while ((int)pbVar3 < 0x482b08);
      if ((iVar2 == 0x10) && (tutorial_stage_transition_timer == -1)) {
        tutorial_stage_transition_timer = -1000;
        sfx_play(sfx_ui_levelup);
        return;
      }
    }
    else {
      if (tutorial_stage_index == 3) {
        piVar5 = &player_state_table.input.fire_key;
        do {
          iVar2 = (*grim_interface_ptr->vtable->grim_is_key_active)(*piVar5);
          if (((char)iVar2 != '\0') && (tutorial_stage_transition_timer == -1)) {
            tutorial_stage_transition_timer = -1000;
            sfx_play(sfx_ui_levelup);
            afStack_5c[0] = -164.0;
            afStack_5c[1] = 412.0;
            creature_spawn_template(0x24,afStack_5c,3.1415927);
            afStack_5c[2] = -184.0;
            afStack_5c[3] = 512.0;
            creature_spawn_template(0x26,afStack_5c + 2,3.1415927);
            afStack_5c[4] = -154.0;
            afStack_5c[5] = 612.0;
            creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
          }
          piVar5 = piVar5 + 0xd8;
        } while ((int)piVar5 < 0x4912ac);
        return;
      }
      if (tutorial_stage_index == 4) {
        uVar4 = creatures_none_active();
        if (((char)uVar4 != '\0') && (tutorial_stage_transition_timer == -1)) {
          tutorial_stage_timer = 1000;
          tutorial_stage_transition_timer = -1000;
          sfx_play(sfx_ui_levelup);
          tutorial_repeat_spawn_count = 0;
          afStack_5c[4] = 1188.0;
          afStack_5c[5] = 412.0;
          creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
          afStack_5c[4] = 1208.0;
          afStack_5c[5] = 512.0;
          creature_spawn_template(0x26,afStack_5c + 4,3.1415927);
          afStack_5c[4] = 1178.0;
          afStack_5c[5] = 612.0;
          creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
          return;
        }
      }
      else if (tutorial_stage_index == 5) {
        iVar2 = 0;
        pbVar3 = bonus_pool;
        do {
          if (pbVar3->bonus_id != BONUS_ID_NONE) break;
          pbVar3 = pbVar3 + 1;
          iVar2 = iVar2 + 1;
        } while ((int)pbVar3 < 0x482b08);
        if ((iVar2 == 0x10) && (uVar4 = creatures_none_active(), (char)uVar4 != '\0')) {
          tutorial_repeat_spawn_count = tutorial_repeat_spawn_count + 1;
          if ((int)tutorial_repeat_spawn_count < 8) {
            DAT_004808b0 = '\0';
            if ((tutorial_repeat_spawn_count & 1) == 0) {
              if ((int)tutorial_repeat_spawn_count < 6) {
                afStack_5c[4] = 1056.0;
                afStack_5c[5] = 1056.0;
                tutorial_hint_bonus_ptr = creature_spawn_template(0x27,afStack_5c + 4,3.1415927);
              }
              afStack_5c[4] = 1188.0;
              afStack_5c[5] = 1136.0;
              creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
              afStack_5c[4] = 1208.0;
              afStack_5c[5] = 512.0;
              creature_spawn_template(0x26,afStack_5c + 4,3.1415927);
              afStack_5c[4] = 1178.0;
            }
            else {
              if ((int)tutorial_repeat_spawn_count < 6) {
                afStack_5c[4] = -32.0;
                afStack_5c[5] = 1056.0;
                tutorial_hint_bonus_ptr = creature_spawn_template(0x27,afStack_5c + 4,3.1415927);
              }
              afStack_5c[4] = -164.0;
              afStack_5c[5] = 412.0;
              creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
              afStack_5c[4] = -184.0;
              afStack_5c[5] = 512.0;
              creature_spawn_template(0x26,afStack_5c + 4,3.1415927);
              afStack_5c[4] = -154.0;
            }
            afStack_5c[5] = 612.0;
            creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
            if (tutorial_repeat_spawn_count == 4) {
              afStack_5c[4] = 512.0;
              afStack_5c[5] = 1056.0;
              creature_spawn_template(0x40,afStack_5c + 4,3.1415927);
            }
            if ((int)tutorial_repeat_spawn_count < 6) {
              pcVar1 = tutorial_hint_bonus_ptr;
              switch(tutorial_repeat_spawn_count) {
              case 1:
                pcVar1[0x78] = '\r';
                pcVar1[0x79] = '\0';
                pcVar1 = tutorial_hint_bonus_ptr;
                pcVar1[0x7a] = -1;
                pcVar1[0x7b] = -1;
                return;
              case 2:
                pcVar1[0x78] = '\x03';
                pcVar1[0x79] = '\0';
                pcVar1 = tutorial_hint_bonus_ptr;
                pcVar1[0x7a] = '\x05';
                pcVar1[0x7b] = '\0';
                return;
              case 3:
                pcVar1[0x78] = '\x06';
                pcVar1[0x79] = '\0';
                pcVar1 = tutorial_hint_bonus_ptr;
                pcVar1[0x7a] = -1;
                pcVar1[0x7b] = -1;
                return;
              case 4:
                pcVar1[0x78] = '\x05';
                pcVar1[0x79] = '\0';
                pcVar1 = tutorial_hint_bonus_ptr;
                pcVar1[0x7a] = -1;
                pcVar1[0x7b] = -1;
                return;
              case 5:
                pcVar1[0x78] = '\t';
                pcVar1[0x79] = '\0';
                pcVar1 = tutorial_hint_bonus_ptr;
                pcVar1[0x7a] = -1;
                pcVar1[0x7b] = -1;
                return;
              }
            }
          }
          else if (tutorial_stage_transition_timer == -1) {
            tutorial_stage_transition_timer = -1000;
            sfx_play(sfx_ui_levelup);
            player_state_table.experience = 3000;
            return;
          }
        }
      }
      else if (tutorial_stage_index == 6) {
        if ((perk_pending_count < 1) && (tutorial_stage_transition_timer == -1)) {
          tutorial_stage_transition_timer = -1000;
          afStack_5c[4] = -164.0;
          afStack_5c[5] = 412.0;
          creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
          afStack_5c[4] = -184.0;
          afStack_5c[5] = 512.0;
          creature_spawn_template(0x26,afStack_5c + 4,3.1415927);
          afStack_5c[4] = -154.0;
          afStack_5c[5] = 612.0;
          creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
          afStack_5c[4] = -32.0;
          afStack_5c[5] = -32.0;
          creature_spawn_template(0x28,afStack_5c + 4,3.1415927);
          afStack_5c[4] = 1188.0;
          afStack_5c[5] = 412.0;
          creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
          afStack_5c[4] = 1208.0;
          afStack_5c[5] = 512.0;
          creature_spawn_template(0x26,afStack_5c + 4,3.1415927);
          afStack_5c[4] = 1178.0;
          afStack_5c[5] = 612.0;
          creature_spawn_template(0x24,afStack_5c + 4,3.1415927);
          return;
        }
      }
      else if (tutorial_stage_index == 7) {
        iVar2 = 0;
        pbVar3 = bonus_pool;
        do {
          if (pbVar3->bonus_id != BONUS_ID_NONE) break;
          pbVar3 = pbVar3 + 1;
          iVar2 = iVar2 + 1;
        } while ((int)pbVar3 < 0x482b08);
        if (((iVar2 == 0x10) && (uVar4 = creatures_none_active(), (char)uVar4 != '\0')) &&
           (tutorial_stage_transition_timer == -1)) {
          tutorial_stage_transition_timer = -1000;
        }
      }
    }
  }
  return;
}



