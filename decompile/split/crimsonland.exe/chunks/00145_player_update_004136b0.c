/* player_update @ 004136b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* per-player gameplay update: movement, firing, status timers, and effects */

void player_update(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  player_state_t *ppVar6;
  int iVar7;
  bool bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  creature_t *pcVar13;
  float fVar14;
  float *unaff_EBP;
  float fVar15;
  int iVar16;
  float *pfVar17;
  float10 fVar18;
  float10 fVar19;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  longlong lVar20;
  float *player_index;
  projectile_type_id_t pVar21;
  float *delta;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_30 [2];
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar7 = render_overlay_player_index;
  if (console_open_flag != '\0') {
    return;
  }
  (&player_aim_screen_x)[render_overlay_player_index * 2] = ui_mouse_x;
  (&player_aim_screen_y)[iVar7 * 2] = ui_mouse_y;
  local_28 = (&player_state_table)[iVar7].pos_x;
  pfVar17 = &(&player_state_table)[iVar7].pos_x;
  local_24 = (&player_state_table)[iVar7].pos_y;
  if ((&player_state_table)[iVar7].health <= 0.0) {
    (&player_state_table)[iVar7].death_timer =
         (&player_state_table)[iVar7].death_timer - frame_dt * 20.0;
    return;
  }
  if (0.0 < (&player_state_table)[iVar7].speed_bonus_timer) {
    (&player_state_table)[iVar7].speed_multiplier =
         (&player_state_table)[iVar7].speed_multiplier + 1.0;
  }
  if ((((&player_state_table)[iVar7].low_health_timer != 100.0) &&
      ((&player_state_table)[iVar7].health < 20.0)) &&
     (fVar15 = (&player_state_table)[iVar7].low_health_timer - frame_dt,
     (&player_state_table)[iVar7].low_health_timer = fVar15, fVar15 < 0.0)) {
    fVar18 = (float10)fcos(((float10)(&player_state_table)[iVar7].aim_heading + (float10)1.5707964)
                           - (float10)0.5);
    fVar19 = (float10)fsin(((float10)(&player_state_table)[iVar7].aim_heading + (float10)1.5707964)
                           - (float10)0.5);
    fVar15 = (&player_state_table)[iVar7].aim_heading;
    local_18 = (float)(fVar18 * (float10)-6.0 + (float10)*pfVar17);
    local_14 = (float)(fVar19 * (float10)-6.0) + (&player_state_table)[iVar7].pos_y;
    effect_spawn_blood_splatter(&local_18,fVar15,0.0);
    effect_spawn_blood_splatter(&local_18,fVar15,0.0);
    effect_spawn_blood_splatter(&local_18,fVar15,0.0);
    uVar9 = crt_rand();
    sfx_play_panned((float)((uVar9 & 1) + sfx_bloodspill_01));
    (&player_state_table)[iVar7].low_health_timer = 1.0;
  }
  pfVar1 = &(&player_state_table)[iVar7].muzzle_flash_alpha;
  fVar15 = *pfVar1 - (frame_dt + frame_dt);
  *pfVar1 = fVar15;
  if (fVar15 < 0.0) {
    *pfVar1 = 0.0;
  }
  if (_bonus_weapon_power_up_timer <= 0.0) {
    fVar15 = (&player_state_table)[iVar7].shot_cooldown - frame_dt;
  }
  else {
    fVar15 = (&player_state_table)[iVar7].shot_cooldown - frame_dt * 1.5;
  }
  (&player_state_table)[iVar7].shot_cooldown = fVar15;
  if ((&player_state_table)[iVar7].shot_cooldown < 0.0) {
    (&player_state_table)[iVar7].shot_cooldown = 0.0;
  }
  iVar10 = perk_count_get(perk_id_man_bomb);
  if (iVar10 == 0) {
    (&player_state_table)[iVar7].man_bomb_timer = 0.0;
  }
  else {
    fVar15 = frame_dt + (&player_state_table)[iVar7].man_bomb_timer;
    (&player_state_table)[iVar7].man_bomb_timer = fVar15;
    if (_DAT_00473310 < fVar15) {
      if (*(float *)((int)cv_friendlyFire + 0xc) == 0.0) {
        iVar10 = -100;
      }
      else {
        iVar10 = -1 - render_overlay_player_index;
      }
      local_38 = 0.0;
      do {
        iVar16 = iVar10;
        if (((uint)local_38 & 1) == 0) {
          pVar21 = PROJECTILE_TYPE_ION_MINIGUN;
          iVar11 = crt_rand();
        }
        else {
          pVar21 = PROJECTILE_TYPE_ION_RIFLE;
          iVar11 = crt_rand();
        }
        projectile_spawn(pfVar17,((float)(int)local_38 * 0.7853982 + (float)(iVar11 % 0x32) * 0.01)
                                 - 0.25,pVar21,iVar16);
        local_38 = (float)((int)local_38 + 1);
      } while ((int)local_38 < 8);
      sfx_play_panned(sfx_explosion_small);
      (&player_state_table)[iVar7].man_bomb_timer =
           (&player_state_table)[iVar7].man_bomb_timer - _DAT_00473310;
      _DAT_00473310 = 4.0;
    }
  }
  iVar10 = perk_count_get(perk_id_living_fortress);
  if (iVar10 == 0) {
    (&player_state_table)[iVar7].living_fortress_timer = 0.0;
  }
  else {
    fVar15 = frame_dt + (&player_state_table)[iVar7].living_fortress_timer;
    (&player_state_table)[iVar7].living_fortress_timer = fVar15;
    if (30.0 < fVar15) {
      (&player_state_table)[iVar7].living_fortress_timer = 30.0;
    }
  }
  iVar10 = perk_count_get(perk_id_fire_caugh);
  if (iVar10 == 0) {
    (&player_state_table)[iVar7].fire_cough_timer = 0.0;
  }
  else {
    fVar15 = frame_dt + (&player_state_table)[iVar7].fire_cough_timer;
    (&player_state_table)[iVar7].fire_cough_timer = fVar15;
    if (_DAT_00473314 < fVar15) {
      if (*(float *)((int)cv_friendlyFire + 0xc) == 0.0) {
        local_40 = -NAN;
      }
      else {
        local_40 = (float)(-1 - render_overlay_player_index);
      }
      sfx_play_panned(DAT_004d9050);
      sfx_play_panned(DAT_004d7fd8);
      iVar10 = render_overlay_player_index;
      fVar15 = (&player_state_table)[iVar7].aim_heading;
      fVar18 = ((float10)fVar15 - (float10)1.5707964) - (float10)0.150915;
      fVar19 = (float10)fcos(fVar18);
      local_1c = (&player_state_table)[render_overlay_player_index].aim_y;
      local_20 = (&player_state_table)[render_overlay_player_index].aim_x;
      ppVar6 = &player_state_table + render_overlay_player_index;
      local_18 = (float)(fVar19 * (float10)16.0);
      fVar18 = (float10)fsin(fVar18);
      local_14 = (float)(fVar18 * (float10)16.0);
      local_c = local_1c - (&player_state_table)[render_overlay_player_index].pos_y;
      local_10 = local_20 - ppVar6->pos_x;
      local_30[0] = vec2_length(&local_10);
      local_30[0] = local_30[0] * 0.5;
      uVar9 = crt_rand();
      fVar14 = (float)(uVar9 & 0x1ff) * 0.012271847;
      uVar9 = crt_rand();
      local_44 = (float)(uVar9 & 0x1ff);
      fVar18 = (float10)local_30[0] * (float10)(&player_state_table)[iVar10].spread_heat *
               (float10)(int)local_44 * (float10)0.001953125;
      fVar19 = (float10)fcos((float10)fVar14);
      local_20 = (float)(fVar19 * fVar18 + (float10)local_20);
      fVar19 = (float10)fsin((float10)fVar14);
      local_1c = (float)(fVar19 * fVar18 + (float10)local_1c);
      pfVar12 = vec2_sub(&ppVar6->pos_x,local_30,&local_20,unaff_EBP);
      fVar18 = (float10)fpatan((float10)pfVar12[1],(float10)*pfVar12);
      local_30[0] = (float)(fVar18 - (float10)1.5707964);
      local_c = local_14 + (&player_state_table)[iVar7].pos_y;
      local_10 = local_18 + *pfVar17;
      projectile_spawn(&local_10,local_30[0],PROJECTILE_TYPE_FIRE_BULLETS,(int)local_40);
      fVar18 = (float10)fcos((float10)fVar15);
      local_10 = (float)(fVar18 * (float10)25.0);
      fVar18 = (float10)fsin((float10)fVar15);
      local_c = (float)(fVar18 * (float10)25.0);
      local_14 = local_14 + (&player_state_table)[iVar7].pos_y;
      local_18 = local_18 + *pfVar17;
      iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
      (&sprite_effect_pool)[iVar10].color_r = 0.5;
      (&sprite_effect_pool)[iVar10].color_g = 0.5;
      (&sprite_effect_pool)[iVar10].color_b = 0.5;
      (&sprite_effect_pool)[iVar10].color_a = 0.413;
      (&player_state_table)[iVar7].fire_cough_timer =
           (&player_state_table)[iVar7].fire_cough_timer - _DAT_00473314;
      uVar9 = crt_rand();
      local_30[0] = (float)(uVar9 & 0x80000003);
      if ((int)local_30[0] < 0) {
        local_30[0] = (float)(((int)local_30[0] - 1U | 0xfffffffc) + 1);
      }
      _DAT_00473314 = (float)(int)local_30[0] + 2.0;
    }
  }
  iVar10 = perk_count_get(perk_id_hot_tempered);
  if (iVar10 == 0) {
    (&player_state_table)[iVar7].hot_tempered_timer = 0.0;
  }
  else {
    fVar15 = frame_dt + (&player_state_table)[iVar7].hot_tempered_timer;
    (&player_state_table)[iVar7].hot_tempered_timer = fVar15;
    if (_DAT_00473318 < fVar15) {
      if (*(float *)((int)cv_friendlyFire + 0xc) == 0.0) {
        iVar10 = -100;
      }
      else {
        iVar10 = -1 - render_overlay_player_index;
      }
      local_38 = 0.0;
      do {
        if (((uint)local_38 & 1) == 0) {
          pVar21 = PROJECTILE_TYPE_PLASMA_MINIGUN;
        }
        else {
          pVar21 = PROJECTILE_TYPE_PLASMA_RIFLE;
        }
        projectile_spawn(pfVar17,(float)(int)local_38 * 0.7853982,pVar21,iVar10);
        local_38 = (float)((int)local_38 + 1);
      } while ((int)local_38 < 8);
      sfx_play_panned(sfx_explosion_small);
      (&player_state_table)[iVar7].hot_tempered_timer =
           (&player_state_table)[iVar7].hot_tempered_timer - _DAT_00473318;
      uVar9 = crt_rand();
      local_30[0] = (float)(uVar9 & 0x80000007);
      if ((int)local_30[0] < 0) {
        local_30[0] = (float)(((int)local_30[0] - 1U | 0xfffffff8) + 1);
      }
      _DAT_00473318 = (float)(int)local_30[0] + 2.0;
    }
  }
  if (_DAT_004aaf34 <= 0.0) {
    _DAT_00473a40 = frame_dt * 0.8 + _DAT_00473a40;
    if (1.0 < _DAT_00473a40) {
      _DAT_00473a40 = 1.0;
    }
  }
  else {
    _DAT_00473a40 = _DAT_00473a40 - frame_dt;
    if (_DAT_00473a40 < 0.3) {
      _DAT_00473a40 = 0.3;
    }
  }
  fVar15 = (&player_state_table)[iVar7].speed_multiplier;
  local_18 = 0.0;
  local_14 = 0.0;
  (&player_state_table)[iVar7].move_dx = 0.0;
  (&player_state_table)[iVar7].move_dy = 0.0;
  if (time_scale_active != '\0') {
    frame_dt = (0.6 / _time_scale_factor) * frame_dt;
  }
  pfVar12 = pfVar17;
  if (((demo_mode_active == '\0') &&
      (*(int *)(config_blob.reserved0 + render_overlay_player_index * 4 + 0x1c) != 5)) &&
     (*(int *)(config_blob.reserved0 + render_overlay_player_index * 4 + 0x44) != 5)) {
LAB_00413f2d:
    iVar10 = *(int *)(config_blob.reserved0 + render_overlay_player_index * 4 + 0x1c);
    if (iVar10 == 5) goto LAB_00414c7f;
    if (iVar10 == 4) {
      iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(config_blob.key_reload);
      if ((char)iVar10 != '\0') {
        local_14 = (float)(&player_aim_screen_y)[render_overlay_player_index * 2] - _camera_offset_y
        ;
        local_18 = (float)(&player_aim_screen_x)[render_overlay_player_index * 2] - _camera_offset_x
        ;
        (&player_state_table)[iVar7].move_target_x = local_18;
        (&player_state_table)[iVar7].move_target_y = local_14;
      }
      if ((&player_state_table)[iVar7].move_target_x == -1.0) {
LAB_0041412c:
        fVar14 = (&player_state_table)[iVar7].move_speed - frame_dt * 15.0;
        (&player_state_table)[iVar7].move_speed = fVar14;
        if (fVar14 < 0.0) {
          (&player_state_table)[iVar7].move_speed = 0.0;
        }
        delta = &local_10;
        fVar18 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dx =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                    (float10)25.0);
        fVar18 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dy =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                    (float10)25.0);
        local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
        local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
        player_index = (float *)render_overlay_player_index;
        goto LAB_00414f1c;
      }
      fVar18 = (float10)(&player_state_table)[iVar7].pos_y -
               (float10)(&player_state_table)[iVar7].move_target_y;
      fVar19 = (float10)*pfVar17 - (float10)(&player_state_table)[iVar7].move_target_x;
      if (SQRT(fVar18 * fVar18 + fVar19 * fVar19) <= (float10)20.0) goto LAB_0041412c;
      fVar18 = (float10)fpatan(fVar18,fVar19);
      fVar18 = fVar18 - (float10)1.5707964;
      if (fVar18 < (float10)0.0) {
        do {
          fVar18 = fVar18 + (float10)6.2831855;
        } while (fVar18 < (float10)0.0);
      }
      local_38 = (float)fVar18;
      if (fVar18 == (float10)-1.0) goto LAB_0041412c;
      fVar18 = (float10)FUN_00413540(local_38);
      if (player_state_table.perk_counts[perk_id_long_distance_runner] < 1) {
        fVar14 = frame_dt * 5.0 + (&player_state_table)[iVar7].move_speed;
        (&player_state_table)[iVar7].move_speed = fVar14;
        if (2.0 < fVar14) {
          (&player_state_table)[iVar7].move_speed = 2.0;
        }
      }
      else {
        if ((&player_state_table)[iVar7].move_speed < 2.0) {
          (&player_state_table)[iVar7].move_speed =
               frame_dt * 4.0 + (&player_state_table)[iVar7].move_speed;
        }
        fVar14 = frame_dt + (&player_state_table)[iVar7].move_speed;
        (&player_state_table)[iVar7].move_speed = fVar14;
        if (2.8 < fVar14) {
          (&player_state_table)[iVar7].move_speed = 2.8;
        }
      }
      if (((&player_state_table)[iVar7].weapon_id == 7) &&
         (0.8 < (&player_state_table)[iVar7].move_speed)) {
        (&player_state_table)[iVar7].move_speed = 0.8;
      }
      fVar19 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
      (&player_state_table)[iVar7].move_dx =
           (float)(fVar19 * (float10)(&player_state_table)[iVar7].move_speed *
                   (float10)(float)((float10)3.1415927 - fVar18) * (float10)fVar15 *
                  (float10)7.957747);
      fVar19 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
      (&player_state_table)[iVar7].move_dy =
           (float)(fVar19 * (float10)(&player_state_table)[iVar7].move_speed *
                   (float10)(float)((float10)3.1415927 - fVar18) * (float10)fVar15 *
                  (float10)7.957747);
      local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
      local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
      goto LAB_00414f13;
    }
    if (iVar10 == 3) {
      (*grim_interface_ptr->vtable->grim_get_config_float)
                ((&player_state_table)[iVar7].input.axis_move_y);
      fVar14 = (float)-extraout_ST0;
      (*grim_interface_ptr->vtable->grim_get_config_float)
                ((&player_state_table)[iVar7].input.axis_move_x);
      local_20 = (float)-extraout_ST0_00;
      local_1c = fVar14;
      if (SQRT(fVar14 * fVar14 + local_20 * local_20) <= 0.2) {
LAB_00414390:
        fVar14 = (&player_state_table)[iVar7].move_speed - frame_dt * 15.0;
        (&player_state_table)[iVar7].move_speed = fVar14;
        if (fVar14 < 0.0) {
          (&player_state_table)[iVar7].move_speed = 0.0;
        }
        delta = &local_10;
        fVar18 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dx =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                    (float10)25.0);
        fVar18 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dy =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                    (float10)25.0);
        local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
        local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
        player_index = (float *)render_overlay_player_index;
        pfVar12 = pfVar17;
      }
      else {
        delta = &local_20;
        pfVar12 = &local_20;
        thunk_FUN_00452f1d();
        fVar18 = (float10)fpatan((float10)local_24,(float10)local_28);
        fVar18 = fVar18 - (float10)1.5707964;
        if (fVar18 < (float10)0.0) {
          do {
            fVar18 = fVar18 + (float10)6.2831855;
          } while (fVar18 < (float10)0.0);
        }
        local_40 = (float)fVar18;
        if (fVar18 == (float10)-1.0) goto LAB_00414390;
        fVar18 = (float10)FUN_00413540(local_40);
        if (player_state_table.perk_counts[perk_id_long_distance_runner] < 1) {
          fVar15 = frame_dt * 5.0 + (&player_state_table)[iVar7].move_speed;
          (&player_state_table)[iVar7].move_speed = fVar15;
          if (2.0 < fVar15) {
            (&player_state_table)[iVar7].move_speed = 2.0;
          }
        }
        else {
          if ((&player_state_table)[iVar7].move_speed < 2.0) {
            (&player_state_table)[iVar7].move_speed =
                 frame_dt * 4.0 + (&player_state_table)[iVar7].move_speed;
          }
          fVar15 = frame_dt + (&player_state_table)[iVar7].move_speed;
          (&player_state_table)[iVar7].move_speed = fVar15;
          if (2.8 < fVar15) {
            (&player_state_table)[iVar7].move_speed = 2.8;
          }
        }
        if (((&player_state_table)[iVar7].weapon_id == 7) &&
           (0.8 < (&player_state_table)[iVar7].move_speed)) {
          (&player_state_table)[iVar7].move_speed = 0.8;
        }
        local_40 = (float)((float10)3.1415927 - fVar18);
        fVar18 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dx =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)local_40 *
                     (float10)local_44 * (float10)7.957747);
        fVar18 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dy =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)local_40 *
                     (float10)local_44 * (float10)7.957747);
        local_14 = frame_dt * (&player_state_table)[iVar7].move_dy;
        local_18 = frame_dt * (&player_state_table)[iVar7].move_dx;
        player_index = &local_18;
      }
      goto LAB_00414f1c;
    }
    if (iVar10 == 1) {
      bVar4 = false;
      if ((&player_state_table)[iVar7].turn_speed < 1.0) {
        (&player_state_table)[iVar7].turn_speed = 1.0;
      }
      if (7.0 < (&player_state_table)[iVar7].turn_speed) {
        (&player_state_table)[iVar7].turn_speed = 7.0;
      }
      iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                         ((&player_state_table)[iVar7].input.turn_key_left);
      if ((char)iVar10 == '\0') {
        if (config_blob.reserved0._20_4_ == 1) {
          iVar10 = (*grim_interface_ptr->vtable->grim_is_key_down)
                             (CONCAT31((int3)((uint)iVar10 >> 8),
                                       (undefined1)player_alt_turn_key_left));
          if ((char)iVar10 != '\0') goto LAB_00414520;
        }
        iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                           ((&player_state_table)[iVar7].input.turn_key_right);
        if ((char)iVar10 != '\0') {
LAB_004144dc:
          fVar14 = frame_dt * 10.0 + (&player_state_table)[iVar7].turn_speed;
          (&player_state_table)[iVar7].turn_speed = fVar14;
          (&player_state_table)[iVar7].heading =
               fVar14 * frame_dt * 0.5 + (&player_state_table)[iVar7].heading;
          fVar14 = frame_dt * (&player_state_table)[iVar7].turn_speed * 0.5 +
                   (&player_state_table)[iVar7].aim_heading;
          goto LAB_00414562;
        }
        if (config_blob.reserved0._20_4_ == 1) {
          iVar10 = (*grim_interface_ptr->vtable->grim_is_key_down)
                             (CONCAT31((int3)((uint)iVar10 >> 8),
                                       (undefined1)player_alt_turn_key_right));
          if ((char)iVar10 != '\0') goto LAB_004144dc;
        }
      }
      else {
LAB_00414520:
        fVar14 = frame_dt * 10.0 + (&player_state_table)[iVar7].turn_speed;
        (&player_state_table)[iVar7].turn_speed = fVar14;
        (&player_state_table)[iVar7].heading =
             (&player_state_table)[iVar7].heading - fVar14 * frame_dt * 0.5;
        fVar14 = (&player_state_table)[iVar7].aim_heading -
                 frame_dt * (&player_state_table)[iVar7].turn_speed * 0.5;
LAB_00414562:
        (&player_state_table)[iVar7].aim_heading = fVar14;
        bVar4 = true;
      }
      local_38 = 1.0;
      iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                         ((&player_state_table)[iVar7].input.move_key_forward);
      if ((char)iVar10 == '\0') {
        if (config_blob.reserved0._20_4_ == 1) {
          iVar10 = (*grim_interface_ptr->vtable->grim_is_key_down)
                             (CONCAT31((int3)((uint)iVar10 >> 8),
                                       (undefined1)player_alt_move_key_forward));
          if ((char)iVar10 != '\0') goto LAB_00414750;
        }
        iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                           ((&player_state_table)[iVar7].input.move_key_backward);
        if ((char)iVar10 == '\0') {
          if (config_blob.reserved0._20_4_ == 1) {
            iVar10 = (*grim_interface_ptr->vtable->grim_is_key_down)
                               (CONCAT31((int3)((uint)iVar10 >> 8),
                                         (undefined1)player_alt_move_key_backward));
            if ((char)iVar10 != '\0') goto LAB_0041467b;
          }
          if (!bVar4) {
            (&player_state_table)[iVar7].turn_speed = 1.0;
          }
          fVar14 = (&player_state_table)[iVar7].move_speed - frame_dt * 15.0;
          (&player_state_table)[iVar7].move_speed = fVar14;
          if (fVar14 < 0.0) {
            (&player_state_table)[iVar7].move_speed = 0.0;
          }
          fVar18 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964)
          ;
          (&player_state_table)[iVar7].move_dx =
               (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                      (float10)25.0);
          fVar18 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964)
          ;
          (&player_state_table)[iVar7].move_dy =
               (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                      (float10)25.0);
          local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
          local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
        }
        else {
LAB_0041467b:
          if (player_state_table.perk_counts[perk_id_long_distance_runner] < 1) {
            fVar14 = frame_dt * 5.0 + (&player_state_table)[iVar7].move_speed;
            (&player_state_table)[iVar7].move_speed = fVar14;
            if (2.0 < fVar14) {
              (&player_state_table)[iVar7].move_speed = 2.0;
            }
          }
          else {
            if ((&player_state_table)[iVar7].move_speed < 2.0) {
              (&player_state_table)[iVar7].move_speed =
                   frame_dt * 4.0 + (&player_state_table)[iVar7].move_speed;
            }
            fVar14 = frame_dt + (&player_state_table)[iVar7].move_speed;
            (&player_state_table)[iVar7].move_speed = fVar14;
            if (2.8 < fVar14) {
              (&player_state_table)[iVar7].move_speed = 2.8;
            }
          }
          local_38 = -1.0;
          fVar18 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964)
          ;
          (&player_state_table)[iVar7].move_dx =
               (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                      (float10)-25.0);
          fVar18 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964)
          ;
          (&player_state_table)[iVar7].move_dy =
               (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                      (float10)-25.0);
          local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
          local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
        }
      }
      else {
LAB_00414750:
        if (player_state_table.perk_counts[perk_id_long_distance_runner] < 1) {
          fVar14 = frame_dt * 5.0 + (&player_state_table)[iVar7].move_speed;
          (&player_state_table)[iVar7].move_speed = fVar14;
          if (2.0 < fVar14) {
            (&player_state_table)[iVar7].move_speed = 2.0;
          }
        }
        else {
          if ((&player_state_table)[iVar7].move_speed < 2.0) {
            (&player_state_table)[iVar7].move_speed =
                 frame_dt * 4.0 + (&player_state_table)[iVar7].move_speed;
          }
          fVar14 = frame_dt + (&player_state_table)[iVar7].move_speed;
          (&player_state_table)[iVar7].move_speed = fVar14;
          if (2.8 < fVar14) {
            (&player_state_table)[iVar7].move_speed = 2.8;
          }
        }
        if (((&player_state_table)[iVar7].weapon_id == 7) &&
           (0.8 < (&player_state_table)[iVar7].move_speed)) {
          (&player_state_table)[iVar7].move_speed = 0.8;
        }
        fVar18 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dx =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                    (float10)25.0);
        fVar18 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dy =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                    (float10)25.0);
        local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
        local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
      }
      player_apply_move_with_spawn_avoidance(render_overlay_player_index,pfVar17,&local_10);
      fVar15 = local_38 * (&player_state_table)[iVar7].move_speed * frame_dt;
      goto LAB_00414f2d;
    }
    if (iVar10 == 2) {
      local_40 = -1.0;
      iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                         ((&player_state_table)[iVar7].input.turn_key_left);
      if (((char)iVar10 != '\0') ||
         ((config_blob.reserved0._20_4_ == 1 &&
          (iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_alt_turn_key_left),
          (char)iVar10 != '\0')))) {
        local_40 = 4.712389;
      }
      iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                         ((&player_state_table)[iVar7].input.turn_key_right);
      if (((char)iVar10 != '\0') ||
         ((config_blob.reserved0._20_4_ == 1 &&
          (iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_alt_turn_key_right),
          (char)iVar10 != '\0')))) {
        local_40 = 1.5707964;
      }
      iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                         ((&player_state_table)[iVar7].input.move_key_forward);
      if (((char)iVar10 != '\0') ||
         ((config_blob.reserved0._20_4_ == 1 &&
          (iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_alt_move_key_forward),
          (char)iVar10 != '\0')))) {
        iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                           ((&player_state_table)[iVar7].input.turn_key_left);
        if (((char)iVar10 == '\0') &&
           ((config_blob.reserved0._20_4_ != 1 ||
            (iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_alt_turn_key_left),
            (char)iVar10 == '\0')))) {
          iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                             ((&player_state_table)[iVar7].input.turn_key_right);
          if (((char)iVar10 == '\0') &&
             ((config_blob.reserved0._20_4_ != 1 ||
              (iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_alt_turn_key_right)
              , (char)iVar10 == '\0')))) {
            local_40 = 0.0;
          }
          else {
            local_40 = 0.7853982;
          }
        }
        else {
          local_40 = 5.4977875;
        }
      }
      iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                         ((&player_state_table)[iVar7].input.move_key_backward);
      if (((char)iVar10 == '\0') &&
         ((config_blob.reserved0._20_4_ != 1 ||
          (iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_alt_move_key_backward),
          (char)iVar10 == '\0')))) {
        if (local_40 != -1.0) goto LAB_00414aab;
        fVar14 = (&player_state_table)[iVar7].move_speed - frame_dt * 15.0;
        (&player_state_table)[iVar7].move_speed = fVar14;
        if (fVar14 < 0.0) {
          (&player_state_table)[iVar7].move_speed = 0.0;
        }
        fVar18 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dx =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                    (float10)25.0);
        fVar18 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dy =
             (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                    (float10)25.0);
        local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
        local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
      }
      else {
        iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                           ((&player_state_table)[iVar7].input.turn_key_left);
        if (((char)iVar10 == '\0') &&
           ((config_blob.reserved0._20_4_ != 1 ||
            (iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_alt_turn_key_left),
            (char)iVar10 == '\0')))) {
          iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                             ((&player_state_table)[iVar7].input.turn_key_right);
          if (((char)iVar10 == '\0') &&
             ((config_blob.reserved0._20_4_ != 1 ||
              (iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_alt_turn_key_right)
              , (char)iVar10 == '\0')))) {
            local_40 = 3.1415927;
          }
          else {
            local_40 = 2.3561945;
          }
        }
        else {
          local_40 = 3.926991;
        }
LAB_00414aab:
        fVar18 = (float10)FUN_00413540(local_40);
        (&player_state_table)[iVar7].aim_heading =
             _DAT_00487198 + (&player_state_table)[iVar7].aim_heading;
        if (player_state_table.perk_counts[perk_id_long_distance_runner] < 1) {
          fVar14 = frame_dt * 5.0 + (&player_state_table)[iVar7].move_speed;
          (&player_state_table)[iVar7].move_speed = fVar14;
          if (2.0 < fVar14) {
            (&player_state_table)[iVar7].move_speed = 2.0;
          }
        }
        else {
          if ((&player_state_table)[iVar7].move_speed < 2.0) {
            (&player_state_table)[iVar7].move_speed =
                 frame_dt * 4.0 + (&player_state_table)[iVar7].move_speed;
          }
          fVar14 = frame_dt + (&player_state_table)[iVar7].move_speed;
          (&player_state_table)[iVar7].move_speed = fVar14;
          if (2.8 < fVar14) {
            (&player_state_table)[iVar7].move_speed = 2.8;
          }
        }
        if (((&player_state_table)[iVar7].weapon_id == 7) &&
           (0.8 < (&player_state_table)[iVar7].move_speed)) {
          (&player_state_table)[iVar7].move_speed = 0.8;
        }
        fVar19 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dx =
             (float)(fVar19 * (float10)(&player_state_table)[iVar7].move_speed *
                     (float10)(float)((float10)3.1415927 - fVar18) * (float10)fVar15 *
                    (float10)7.957747);
        fVar19 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
        (&player_state_table)[iVar7].move_dy =
             (float)(fVar19 * (float10)(&player_state_table)[iVar7].move_speed *
                     (float10)(float)((float10)3.1415927 - fVar18) * (float10)fVar15 *
                    (float10)7.957747);
        local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
        local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
      }
      player_apply_move_with_spawn_avoidance(render_overlay_player_index,pfVar17,&local_10);
      (&player_state_table)[iVar7].move_phase =
           frame_dt * (&player_state_table)[iVar7].move_speed * 19.0 +
           (&player_state_table)[iVar7].move_phase;
    }
  }
  else {
    if ((&player_state_table)[iVar7].auto_target < 0) {
      (&player_state_table)[iVar7].auto_target = 0;
    }
    iVar10 = (&player_state_table)[iVar7].auto_target;
    if (((&creature_pool)[iVar10].active == '\0') || ((&creature_pool)[iVar10].health <= 0.0)) {
      fVar14 = 100000.0;
    }
    else {
      fVar14 = (&player_state_table)[iVar7].pos_y - (&creature_pool)[iVar10].pos_y;
      fVar2 = *pfVar17 - (&creature_pool)[iVar10].pos_x;
      fVar14 = SQRT(fVar14 * fVar14 + fVar2 * fVar2);
    }
    iVar10 = 0;
    pcVar13 = &creature_pool;
    do {
      if (((pcVar13->active != '\0') && (0.0 < pcVar13->health)) &&
         (fVar3 = (&player_state_table)[iVar7].pos_y - pcVar13->pos_y,
         fVar2 = *pfVar17 - pcVar13->pos_x, local_30[0] = SQRT(fVar3 * fVar3 + fVar2 * fVar2),
         local_30[0] < fVar14 - 64.0)) {
        (&player_state_table)[iVar7].auto_target = iVar10;
        fVar14 = local_30[0];
      }
      pcVar13 = pcVar13 + 1;
      iVar10 = iVar10 + 1;
    } while ((int)pcVar13 < 0x4aa338);
    if (demo_mode_active == '\0') goto LAB_00413f2d;
LAB_00414c7f:
    if (((&player_state_table)[iVar7].auto_target < 0) ||
       ((&creature_pool)[(&player_state_table)[iVar7].auto_target].health <= 0.0)) {
      fVar18 = (float10)fpatan((float10)(&player_state_table)[iVar7].pos_y - (float10)512.0,
                               (float10)*pfVar17 - (float10)512.0);
      fVar18 = fVar18 + (float10)3.1415927;
    }
    else {
      fVar14 = (&player_state_table)[iVar7].pos_y - 512.0;
      if (SQRT(fVar14 * fVar14 + (*pfVar17 - 512.0) * (*pfVar17 - 512.0)) <= 300.0) {
        local_14 = (&player_state_table)[iVar7].pos_y -
                   (&creature_pool)[(&player_state_table)[iVar7].auto_target].pos_y;
        local_18 = *pfVar17 - (&creature_pool)[(&player_state_table)[iVar7].auto_target].pos_x;
      }
      else {
        local_14 = (&player_state_table)[iVar7].pos_y - 512.0;
        local_18 = *pfVar17 - 512.0;
      }
      fVar18 = (float10)fpatan((float10)local_14,(float10)local_18);
      fVar18 = fVar18 - (float10)1.5707964;
      local_20 = local_18;
      local_1c = local_14;
    }
    if (fVar18 == (float10)-1.0) {
      fVar14 = (&player_state_table)[iVar7].move_speed - frame_dt * 15.0;
      (&player_state_table)[iVar7].move_speed = fVar14;
      if (fVar14 < 0.0) {
        (&player_state_table)[iVar7].move_speed = 0.0;
      }
      fVar18 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
      (&player_state_table)[iVar7].move_dx =
           (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                  (float10)25.0);
      fVar18 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
      (&player_state_table)[iVar7].move_dy =
           (float)(fVar18 * (float10)(&player_state_table)[iVar7].move_speed * (float10)fVar15 *
                  (float10)25.0);
      local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
      local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
LAB_00414f13:
      delta = &local_10;
      player_index = (float *)render_overlay_player_index;
    }
    else {
      fVar18 = (float10)FUN_00413540((float)fVar18);
      if (player_state_table.perk_counts[perk_id_long_distance_runner] < 1) {
        fVar14 = frame_dt * 5.0 + (&player_state_table)[iVar7].move_speed;
        (&player_state_table)[iVar7].move_speed = fVar14;
        if (2.0 < fVar14) {
          (&player_state_table)[iVar7].move_speed = 2.0;
        }
      }
      else {
        if ((&player_state_table)[iVar7].move_speed < 2.0) {
          (&player_state_table)[iVar7].move_speed =
               frame_dt * 4.0 + (&player_state_table)[iVar7].move_speed;
        }
        fVar14 = frame_dt + (&player_state_table)[iVar7].move_speed;
        (&player_state_table)[iVar7].move_speed = fVar14;
        if (2.8 < fVar14) {
          (&player_state_table)[iVar7].move_speed = 2.8;
        }
      }
      if (((&player_state_table)[iVar7].weapon_id == 7) &&
         (0.8 < (&player_state_table)[iVar7].move_speed)) {
        (&player_state_table)[iVar7].move_speed = 0.8;
      }
      delta = &local_10;
      fVar19 = (float10)fcos((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
      (&player_state_table)[iVar7].move_dx =
           (float)(fVar19 * (float10)(&player_state_table)[iVar7].move_speed *
                   (float10)(float)((float10)3.1415927 - fVar18) * (float10)fVar15 *
                  (float10)7.957747);
      fVar19 = (float10)fsin((float10)(&player_state_table)[iVar7].heading - (float10)1.5707964);
      (&player_state_table)[iVar7].move_dy =
           (float)(fVar19 * (float10)(&player_state_table)[iVar7].move_speed *
                   (float10)(float)((float10)3.1415927 - fVar18) * (float10)fVar15 *
                  (float10)7.957747);
      local_c = frame_dt * (&player_state_table)[iVar7].move_dy;
      local_10 = frame_dt * (&player_state_table)[iVar7].move_dx;
      player_index = (float *)render_overlay_player_index;
    }
LAB_00414f1c:
    player_apply_move_with_spawn_avoidance((int)player_index,pfVar12,delta);
    fVar15 = frame_dt * (&player_state_table)[iVar7].move_speed;
LAB_00414f2d:
    (&player_state_table)[iVar7].move_phase =
         fVar15 * 19.0 + (&player_state_table)[iVar7].move_phase;
  }
  if (time_scale_active != '\0') {
    frame_dt = _time_scale_factor * frame_dt * 1.6666666;
  }
  iVar10 = perk_count_get(perk_id_sharpshooter);
  if (iVar10 == 0) {
    fVar15 = (&player_state_table)[iVar7].spread_heat - frame_dt * 0.4;
    (&player_state_table)[iVar7].spread_heat = fVar15;
    if (fVar15 < 0.01) {
      (&player_state_table)[iVar7].spread_heat = 0.01;
    }
  }
  else {
    fVar15 = (&player_state_table)[iVar7].spread_heat - (frame_dt + frame_dt);
    (&player_state_table)[iVar7].spread_heat = fVar15;
    if (fVar15 < 0.25) {
      (&player_state_table)[iVar7].spread_heat = 0.25;
    }
    (&player_state_table)[iVar7].spread_heat = 0.02;
  }
  iVar10 = perk_count_get(perk_id_anxious_loader);
  if ((((iVar10 != 0) && (iVar10 = input_primary_just_pressed(), (char)iVar10 != '\0')) &&
      (0.0 < (&player_state_table)[iVar7].reload_timer)) &&
     (fVar15 = (&player_state_table)[iVar7].reload_timer - 0.05,
     (&player_state_table)[iVar7].reload_timer = fVar15, fVar15 <= 0.0)) {
    (&player_state_table)[iVar7].reload_timer = frame_dt * 0.8;
  }
  if (((&player_state_table)[iVar7].reload_timer - frame_dt < 0.0) &&
     (0.0 <= (&player_state_table)[iVar7].reload_timer)) {
    (&player_state_table)[iVar7].ammo = (&player_state_table)[iVar7].clip_size;
  }
  local_38 = 1.0;
  if ((*pfVar17 == local_28) && ((&player_state_table)[iVar7].pos_y == local_24)) {
    iVar10 = perk_count_get(perk_id_stationary_reloader);
    if (iVar10 != 0) {
      local_38 = 3.0;
    }
  }
  else {
    (&player_state_table)[iVar7].man_bomb_timer = 0.0;
    (&player_state_table)[iVar7].living_fortress_timer = 0.0;
  }
  iVar10 = perk_count_get(perk_id_angry_reloader);
  if (((iVar10 == 0) || ((&player_state_table)[iVar7].reload_timer_max <= 0.5)) ||
     (fVar15 = (&player_state_table)[iVar7].reload_timer_max * 0.5,
     (&player_state_table)[iVar7].reload_timer <= fVar15)) {
    (&player_state_table)[iVar7].reload_timer =
         (&player_state_table)[iVar7].reload_timer - local_38 * frame_dt;
  }
  else {
    fVar14 = (&player_state_table)[iVar7].reload_timer - local_38 * frame_dt;
    (&player_state_table)[iVar7].reload_timer = fVar14;
    if (fVar14 <= fVar15) {
      bonus_spawn_guard = 1;
      if (*(float *)((int)cv_friendlyFire + 0xc) == 0.0) {
        local_38 = -NAN;
      }
      else {
        local_38 = (float)(-1 - render_overlay_player_index);
      }
      lVar20 = __ftol();
      fVar15 = (float)(7 - (int)lVar20);
      local_3c = 0.0;
      local_30[0] = fVar15;
      if (0 < (int)fVar15) {
        local_30[0] = 6.2831855 / (float)(int)fVar15;
        do {
          projectile_spawn(pfVar17,(float)(int)local_3c * local_30[0] + 0.1,
                           PROJECTILE_TYPE_PLASMA_MINIGUN,(int)local_38);
          local_3c = (float)((int)local_3c + 1);
        } while ((int)local_3c < (int)fVar15);
      }
      bonus_spawn_guard = 0;
      sfx_play_panned(sfx_explosion_small);
    }
  }
  if ((&player_state_table)[iVar7].reload_timer < 0.0) {
    (&player_state_table)[iVar7].reload_timer = 0.0;
  }
  if ((((demo_mode_active == '\0') &&
       (iVar10 = perk_count_get(perk_id_alternate_weapon), iVar10 == 0)) &&
      ((*(int *)(config_blob.reserved0 + render_overlay_player_index * 4 + 0x1c) != 4 &&
       ((iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(config_blob.key_reload),
        (char)iVar10 != '\0' && ((&player_state_table)[iVar7].reload_timer == 0.0)))))) &&
     (config_blob.reserved0._20_4_ == 1)) {
    player_start_reload();
  }
  bVar4 = false;
  if ((demo_mode_active == '\0') &&
     (iVar10 = *(int *)(config_blob.reserved0 + render_overlay_player_index * 4 + 0x44), iVar10 != 5
     )) {
    if (iVar10 == 0) {
      local_14 = (float)(&player_aim_screen_y)[render_overlay_player_index * 2] - _camera_offset_y;
      local_18 = (float)(&player_aim_screen_x)[render_overlay_player_index * 2] - _camera_offset_x;
      (&player_state_table)[iVar7].aim_x = local_18;
      (&player_state_table)[iVar7].aim_y = local_14;
    }
    else {
      if (iVar10 != 4) {
        if (iVar10 == 3) {
          fVar18 = (float10)(float)(&player_aim_screen_y)[render_overlay_player_index * 2] -
                   (float10)200.0;
          local_20 = (float)(&player_aim_screen_x)[render_overlay_player_index * 2] - 200.0;
          local_1c = (float)fVar18;
          if ((local_20 != 0.0) || (fVar18 != (float10)0.0)) {
            fVar18 = (float10)fpatan(fVar18,(float10)local_20);
            (&player_state_table)[iVar7].aim_heading = (float)(fVar18 + (float10)1.5707964);
            fVar18 = (fVar18 + (float10)1.5707964) - (float10)1.5707964;
            local_30[0] = (float)fVar18;
            fVar18 = (float10)fcos(fVar18);
            fVar19 = (float10)fsin((float10)local_30[0]);
            local_c = (float)fVar19;
            local_14 = local_c * 60.0 + (&player_state_table)[iVar7].pos_y;
            local_18 = (float)(fVar18 * (float10)60.0 + (float10)*pfVar17);
            (&player_state_table)[iVar7].aim_x = local_18;
            (&player_state_table)[iVar7].aim_y = local_14;
          }
          if (30.0 < SQRT(local_20 * local_20 + local_1c * local_1c)) {
            thunk_FUN_00452f1d();
            iVar10 = render_overlay_player_index;
            local_14 = local_24 * 30.0;
            local_20 = local_28 * 30.0 + 200.0;
            local_1c = local_14 + 200.0;
            (&player_aim_screen_x)[render_overlay_player_index * 2] = local_20;
            (&player_aim_screen_y)[iVar10 * 2] = local_1c;
          }
        }
        else if (iVar10 == 1) {
          if ((*(int *)(config_blob.reserved0 + render_overlay_player_index * 4 + 0x1c) == 1) ||
             (*(int *)(config_blob.reserved0 + render_overlay_player_index * 4 + 0x1c) == 2)) {
            iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                               ((&player_state_table)[iVar7].input.aim_key_right);
            if ((char)iVar10 != '\0') {
              (&player_state_table)[iVar7].aim_heading =
                   frame_dt * 3.0 + (&player_state_table)[iVar7].aim_heading;
            }
            iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                               ((&player_state_table)[iVar7].input.aim_key_left);
            if ((char)iVar10 != '\0') {
              (&player_state_table)[iVar7].aim_heading =
                   (&player_state_table)[iVar7].aim_heading - frame_dt * 3.0;
            }
            fVar18 = (float10)(&player_state_table)[iVar7].aim_heading - (float10)1.5707964;
            local_30[0] = (float)fVar18;
            fVar18 = (float10)fcos(fVar18);
            fVar19 = (float10)fsin((float10)local_30[0]);
            local_c = (float)fVar19;
            local_14 = local_c * 60.0 + (&player_state_table)[iVar7].pos_y;
            local_18 = (float)(fVar18 * (float10)60.0 + (float10)*pfVar17);
            (&player_state_table)[iVar7].aim_x = local_18;
            (&player_state_table)[iVar7].aim_y = local_14;
          }
        }
        else {
          bVar8 = FUN_0041e8d0();
          if (bVar8) {
            (&player_state_table)[iVar7].aim_heading =
                 (&player_state_table)[iVar7].aim_heading - frame_dt * 4.0;
          }
          bVar8 = FUN_0041e8f0();
          if (bVar8) {
            (&player_state_table)[iVar7].aim_heading =
                 frame_dt * 4.0 + (&player_state_table)[iVar7].aim_heading;
          }
          fVar18 = (float10)(&player_state_table)[iVar7].aim_heading - (float10)1.5707964;
          local_30[0] = (float)fVar18;
          fVar18 = (float10)fcos(fVar18);
          fVar19 = (float10)fsin((float10)local_30[0]);
          local_c = (float)fVar19;
          local_14 = local_c * 60.0 + (&player_state_table)[iVar7].pos_y;
          local_18 = (float)(fVar18 * (float10)60.0 + (float10)*pfVar17);
          (&player_state_table)[iVar7].aim_x = local_18;
          (&player_state_table)[iVar7].aim_y = local_14;
        }
        goto LAB_0041572e;
      }
      (*grim_interface_ptr->vtable->grim_get_config_float)
                ((&player_state_table)[iVar7].input.axis_aim_y);
      (*grim_interface_ptr->vtable->grim_get_config_float)
                ((&player_state_table)[iVar7].input.axis_aim_x);
      local_20 = (float)extraout_ST0_02;
      local_1c = (float)extraout_ST0_01;
      thunk_FUN_00452f1d();
      fVar15 = local_40 * *(float *)((int)cv_padAimDistMul + 0xc) + 42.0;
      local_18 = fVar15 * local_28;
      local_1c = fVar15 * local_24 + (&player_state_table)[iVar7].pos_y;
      local_20 = local_18 + *pfVar17;
      (&player_state_table)[iVar7].aim_x = local_20;
      (&player_state_table)[iVar7].aim_y = local_1c;
    }
    fVar18 = (float10)fpatan((float10)(&player_state_table)[iVar7].pos_y -
                             (float10)(&player_state_table)[iVar7].aim_y,
                             (float10)*pfVar17 - (float10)(&player_state_table)[iVar7].aim_x);
    (&player_state_table)[iVar7].aim_heading = (float)(fVar18 - (float10)1.5707964);
  }
  else {
    pfVar12 = &(&player_state_table)[iVar7].aim_x;
    local_1c = (&creature_pool)[(&player_state_table)[iVar7].auto_target].pos_y -
               (&player_state_table)[iVar7].aim_y;
    local_20 = (&creature_pool)[(&player_state_table)[iVar7].auto_target].pos_x - *pfVar12;
    fVar15 = SQRT(local_1c * local_1c + local_20 * local_20);
    if (4.0 <= fVar15) {
      thunk_FUN_00452f1d();
      fVar14 = local_40 * 6.0 * frame_dt;
      local_18 = local_28 * fVar14;
      *pfVar12 = local_18 + *pfVar12;
      (&player_state_table)[iVar7].aim_y = fVar14 * local_24 + (&player_state_table)[iVar7].aim_y;
    }
    else {
      iVar10 = (&player_state_table)[iVar7].auto_target;
      *pfVar12 = (&creature_pool)[iVar10].pos_x;
      (&player_state_table)[iVar7].aim_y = (&creature_pool)[iVar10].pos_y;
    }
    if ((fVar15 < 128.0) &&
       (0.0 < (&creature_pool)[(&player_state_table)[iVar7].auto_target].health)) {
      bVar4 = true;
    }
  }
LAB_0041572e:
  fVar18 = (float10)fpatan((float10)(&player_state_table)[iVar7].pos_y -
                           (float10)(&player_state_table)[iVar7].aim_y,
                           (float10)*pfVar17 - (float10)(&player_state_table)[iVar7].aim_x);
  pfVar12 = &(&player_state_table)[iVar7].shot_cooldown;
  bVar8 = false;
  bVar5 = false;
  (&player_state_table)[iVar7].aim_heading = (float)(fVar18 - (float10)1.5707964);
  if ((*pfVar12 <= 0.0) && ((&player_state_table)[iVar7].reload_timer == 0.0)) {
    bVar8 = true;
    *(undefined1 *)&(&player_state_table)[iVar7].reload_active = 0;
  }
  if (((*pfVar12 <= 0.0) && (0 < (&player_state_table)[iVar7].experience)) &&
     ((iVar10 = perk_count_get(perk_id_regression_bullets), iVar10 != 0 ||
      (iVar10 = perk_count_get(perk_id_ammunition_within), iVar10 != 0)))) {
    bVar5 = true;
  }
  iVar10 = perk_count_get(perk_id_alternate_weapon);
  if (iVar10 != 0) {
    if (((DAT_0048719c < 1) || (DAT_0048719c = DAT_0048719c - frame_dt_ms, DAT_0048719c < 1)) &&
       (iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(config_blob.key_reload),
       (char)iVar10 != '\0')) {
      iVar10 = (&player_state_table)[iVar7].alt_weapon_id;
      (&player_state_table)[iVar7].alt_weapon_id = (&player_state_table)[iVar7].weapon_id;
      (&player_state_table)[iVar7].weapon_id = iVar10;
      iVar10 = (&player_state_table)[iVar7].alt_clip_size;
      (&player_state_table)[iVar7].alt_clip_size = (&player_state_table)[iVar7].clip_size;
      (&player_state_table)[iVar7].clip_size = iVar10;
      iVar10 = (&player_state_table)[iVar7].alt_reload_active;
      *(char *)&(&player_state_table)[iVar7].alt_reload_active =
           (char)(&player_state_table)[iVar7].reload_active;
      *(char *)&(&player_state_table)[iVar7].reload_active = (char)iVar10;
      iVar10 = (&player_state_table)[iVar7].alt_ammo;
      (&player_state_table)[iVar7].alt_ammo = (&player_state_table)[iVar7].ammo;
      (&player_state_table)[iVar7].ammo = iVar10;
      fVar15 = (&player_state_table)[iVar7].alt_reload_timer;
      (&player_state_table)[iVar7].alt_reload_timer = (&player_state_table)[iVar7].reload_timer;
      (&player_state_table)[iVar7].reload_timer = fVar15;
      fVar15 = (&player_state_table)[iVar7].alt_shot_cooldown;
      (&player_state_table)[iVar7].alt_shot_cooldown = *pfVar12;
      *pfVar12 = fVar15;
      fVar15 = (&player_state_table)[iVar7].alt_reload_timer_max;
      (&player_state_table)[iVar7].alt_reload_timer_max =
           (&player_state_table)[iVar7].reload_timer_max;
      (&player_state_table)[iVar7].reload_timer_max = fVar15;
      sfx_play_panned((float)(&weapon_table)[(&player_state_table)[iVar7].weapon_id].reload_sfx_id);
      *pfVar12 = *pfVar12 + 0.1;
      DAT_0048719c = 200;
    }
    else {
      iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(config_blob.key_reload);
      if ((char)iVar10 == '\0') {
        DAT_0048719c = 0;
      }
    }
  }
  if ((!bVar8) && (!bVar5)) goto LAB_0041753e;
  fVar15 = (&player_state_table)[iVar7].aim_heading;
  iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)
                     ((&player_state_table)[iVar7].input.fire_key);
  if (((char)iVar10 == '\0') && (!bVar4)) goto LAB_0041753e;
  survival_reward_fire_seen = 1;
  if (!bVar8) {
    iVar10 = perk_count_get(perk_id_regression_bullets);
    if (iVar10 == 0) {
      iVar10 = perk_count_get(perk_id_ammunition_within);
      if (iVar10 != 0) {
        if ((&weapon_ammo_class)[(&player_state_table)[iVar7].weapon_id * 0x1f] == 1) {
          fVar14 = 0.15;
        }
        else {
          fVar14 = 1.0;
        }
        player_take_damage(render_overlay_player_index,fVar14);
      }
    }
    else if ((&weapon_ammo_class)[(&player_state_table)[iVar7].weapon_id * 0x1f] == 1) {
      lVar20 = __ftol();
      (&player_state_table)[iVar7].experience = (int)lVar20;
    }
    else {
      lVar20 = __ftol();
      (&player_state_table)[iVar7].experience = (int)lVar20;
    }
    if ((&player_state_table)[iVar7].experience < 0) {
      (&player_state_table)[iVar7].experience = 0;
    }
  }
  fVar14 = (float)((float10)fVar15 - (float10)1.5707964);
  fVar18 = ((float10)fVar15 - (float10)1.5707964) - (float10)0.150915;
  fVar19 = (float10)fcos(fVar18);
  local_20 = (float)(fVar19 * (float10)16.0);
  fVar18 = (float10)fsin(fVar18);
  local_1c = (float)(fVar18 * (float10)16.0);
  if (((&weapon_table)[(&player_state_table)[iVar7].weapon_id].flags & 1) != 0) {
    uVar9 = crt_rand();
    local_30[0] = (float)(uVar9 & 0x3f);
    fVar2 = (float)(int)local_30[0] * 0.01 + fVar15;
    uVar9 = crt_rand();
    local_30[0] = (float)(uVar9 & 0x3f);
    local_10 = 1.0;
    local_c = 1.0;
    uStack_8 = 0x3f800000;
    uStack_4 = 0x3f19999a;
    _effect_template_color_r = 0x3f800000;
    _effect_template_flags = 0x1c5;
    fVar18 = (float10)(int)local_30[0] * (float10)0.022727273 + (float10)1.0;
    fVar19 = (float10)fcos((float10)fVar2);
    _effect_template_color_g = 0x3f800000;
    _effect_template_color_b = 0x3f800000;
    _effect_template_color_a = 0x3f19999a;
    _effect_template_lifetime = 0x3e19999a;
    _effect_template_age = 0;
    local_18 = (float)(fVar19 * fVar18);
    fVar19 = (float10)fsin((float10)fVar2);
    local_14 = (float)(fVar19 * fVar18);
    uVar9 = crt_rand();
    _effect_template_half_height = 0x40000000;
    local_30[0] = (float)((uVar9 & 0x3f) - 0x20);
    _effect_template_half_width = 0x40000000;
    _effect_template_rotation = (float)(int)local_30[0] * 0.1;
    effect_template_vel_x = local_18 * 100.0;
    effect_template_vel_y = local_14 * 100.0;
    iVar10 = crt_rand();
    _effect_template_scale_step = 0;
    local_30[0] = (float)(iVar10 % 0x14);
    _effect_template_rotation_step = ((float)(int)local_30[0] * 0.1 - 1.0) * 14.0;
    local_c = local_1c + (&player_state_table)[iVar7].pos_y;
    local_10 = local_20 + *pfVar17;
    effect_spawn(0x12,&local_10);
  }
  if (1.0 < *pfVar1) {
    *pfVar1 = 1.0;
  }
  iVar10 = render_overlay_player_index;
  local_38 = 1.0;
  if (*(float *)((int)cv_friendlyFire + 0xc) == 0.0) {
    iVar16 = -100;
  }
  else {
    iVar16 = -1 - render_overlay_player_index;
  }
  local_14 = (&player_state_table)[render_overlay_player_index].aim_y;
  local_18 = (&player_state_table)[render_overlay_player_index].aim_x;
  local_c = local_14 - (&player_state_table)[render_overlay_player_index].pos_y;
  local_10 = local_18 - (&player_state_table)[render_overlay_player_index].pos_x;
  local_28 = vec2_length(&local_10);
  local_28 = local_28 * 0.5;
  uVar9 = crt_rand();
  local_30[0] = (float)(uVar9 & 0x1ff);
  fVar2 = (float)(int)local_30[0];
  uVar9 = crt_rand();
  local_30[0] = (float)(uVar9 & 0x1ff);
  fVar18 = (float10)local_28 * (float10)(&player_state_table)[iVar10].spread_heat *
           (float10)(int)local_30[0] * (float10)0.001953125;
  fVar19 = (float10)fcos((float10)(fVar2 * 0.012271847));
  local_18 = (float)(fVar19 * fVar18 + (float10)local_18);
  fVar19 = (float10)fsin((float10)(fVar2 * 0.012271847));
  fVar18 = (float10)fpatan((float10)(&player_state_table)[iVar10].pos_y -
                           (fVar19 * fVar18 + (float10)local_14),
                           (float10)(&player_state_table)[iVar10].pos_x - (float10)local_18);
  fVar2 = (float)(fVar18 - (float10)1.5707964);
  iVar10 = (*grim_interface_ptr->vtable->grim_is_key_active)(0x22);
  if ((char)iVar10 != '\0') {
    (&player_state_table)[iVar7].fire_bullets_timer = 10.0;
  }
  if ((&player_state_table)[iVar7].fire_bullets_timer <= 0.0) {
    (&player_state_table)[iVar7].shot_cooldown =
         (&weapon_table)[(&player_state_table)[iVar7].weapon_id].shot_cooldown;
    *pfVar1 = (&weapon_table)[(&player_state_table)[iVar7].weapon_id].spread_heat + *pfVar1;
    iVar10 = (&player_state_table)[iVar7].weapon_id;
    iVar11 = crt_rand();
    sfx_play_panned((float)(iVar11 % (&weapon_table)[iVar10].shot_sfx_variant_count +
                           (&weapon_table)[iVar10].shot_sfx_base_id));
    iVar10 = (&player_state_table)[iVar7].weapon_id;
    if (iVar10 == 0x18) {
      local_c = local_1c + (&player_state_table)[iVar7].pos_y;
      local_10 = local_20 + *pfVar17;
      projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_SHRINKIFIER,iVar16);
      fVar18 = (float10)fcos((float10)fVar15);
      local_10 = (float)(fVar18 * (float10)25.0);
      fVar19 = (float10)fsin((float10)fVar15);
      local_c = (float)(fVar19 * (float10)25.0);
      local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
      local_18 = local_20 + *pfVar17;
      iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
      (&sprite_effect_pool)[iVar10].color_r = 0.5;
      (&sprite_effect_pool)[iVar10].color_g = 0.5;
      (&sprite_effect_pool)[iVar10].color_b = 0.5;
      (&sprite_effect_pool)[iVar10].color_a = 0.23;
      local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
      local_18 = local_20 + *pfVar17;
LAB_0041600e:
      local_3c = (float)fVar19;
      local_40 = (float)fVar18;
      local_c = local_3c * 15.0;
      local_10 = local_40 * 15.0;
      iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
      (&sprite_effect_pool)[iVar10].color_r = 0.5;
      (&sprite_effect_pool)[iVar10].color_g = 0.5;
      (&sprite_effect_pool)[iVar10].color_b = 0.5;
      (&sprite_effect_pool)[iVar10].color_a = 0.213;
    }
    else {
      if (iVar10 == 1) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_PISTOL,iVar16);
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.23;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        goto LAB_0041600e;
      }
      if (iVar10 == 2) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        local_10 = (float)fVar18 * 15.0;
        local_c = (float)fVar19 * 15.0;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.23;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.213;
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_ASSAULT_RIFLE,iVar16);
      }
      else if (iVar10 == 3) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        local_10 = (float)fVar18 * 15.0;
        local_c = (float)fVar19 * 15.0;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.25;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        local_3c = 1.68156e-44;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.223;
        do {
          pVar21 = PROJECTILE_TYPE_SHOTGUN;
          local_c = local_1c + (&player_state_table)[iVar7].pos_y;
          local_10 = local_20 + *pfVar17;
          iVar10 = iVar16;
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 200 + -100);
          iVar10 = projectile_spawn(&local_10,(float)(int)local_28 * 0.0013 + fVar2,pVar21,iVar10);
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 100);
          local_3c = (float)((int)local_3c + -1);
          projectile_pool[iVar10].pos.tail.vy.speed_scale = (float)(int)local_28 * 0.01 + 1.0;
        } while (local_3c != 0.0);
      }
      else if (iVar10 == 0x14) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)15.0);
        fVar18 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar18 * (float10)15.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        local_3c = 5.60519e-45;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.223;
        do {
          pVar21 = PROJECTILE_TYPE_SHOTGUN;
          local_c = local_1c + (&player_state_table)[iVar7].pos_y;
          local_10 = local_20 + *pfVar17;
          iVar10 = iVar16;
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 200 + -100);
          iVar10 = projectile_spawn(&local_10,(float)(int)local_28 * 0.0013 + fVar2,pVar21,iVar10);
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 100);
          local_3c = (float)((int)local_3c + -1);
          projectile_pool[iVar10].pos.tail.vy.speed_scale = (float)(int)local_28 * 0.01 + 1.0;
        } while (local_3c != 0.0);
      }
      else if (iVar10 == 4) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        local_10 = (float)fVar18 * 15.0;
        local_c = (float)fVar19 * 15.0;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.26;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        local_3c = 1.68156e-44;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.233;
        do {
          pVar21 = PROJECTILE_TYPE_SHOTGUN;
          local_c = local_1c + (&player_state_table)[iVar7].pos_y;
          local_10 = local_20 + *pfVar17;
          iVar10 = iVar16;
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 200 + -100);
          iVar10 = projectile_spawn(&local_10,(float)(int)local_28 * 0.004 + fVar2,pVar21,iVar10);
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 100);
          local_3c = (float)((int)local_3c + -1);
          projectile_pool[iVar10].pos.tail.vy.speed_scale = (float)(int)local_28 * 0.01 + 1.0;
        } while (local_3c != 0.0);
      }
      else if (iVar10 == 8) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        fx_spawn_particle(&local_10,fVar14,&(&player_state_table)[iVar7].move_dx,1.0);
        local_38 = 0.1;
      }
      else if (iVar10 == 0x10) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        iVar10 = fx_spawn_particle(&local_10,fVar14,&(&player_state_table)[iVar7].move_dx,1.0);
        if (iVar10 != -1) {
          *(undefined1 *)&(&particle_pool)[iVar10].style_id = 2;
        }
        local_38 = 0.1;
      }
      else if (iVar10 == 0xf) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        iVar10 = fx_spawn_particle(&local_10,fVar14,&(&player_state_table)[iVar7].move_dx,1.0);
        if (iVar10 != -1) {
          *(undefined1 *)&(&particle_pool)[iVar10].style_id = 1;
        }
        local_38 = 0.05;
      }
      else if (iVar10 == 5) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        local_10 = (float)fVar18 * 15.0;
        local_c = (float)fVar19 * 15.0;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.23;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.213;
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_SUBMACHINE_GUN,iVar16);
      }
      else if (iVar10 == 9) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_PLASMA_RIFLE,iVar16);
      }
      else if (iVar10 == 10) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2 - 0.31415927,PROJECTILE_TYPE_PLASMA_RIFLE,iVar16);
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2 - 0.5235988,PROJECTILE_TYPE_PLASMA_MINIGUN,iVar16);
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_PLASMA_RIFLE,iVar16);
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2 + 0.5235988,PROJECTILE_TYPE_PLASMA_MINIGUN,iVar16);
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2 + 0.31415927,PROJECTILE_TYPE_PLASMA_RIFLE,iVar16);
      }
      else if (iVar10 == 0x13) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_PULSE_GUN,iVar16);
      }
      else if (iVar10 == 0x19) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_BLADE_GUN,iVar16);
      }
      else if (iVar10 == 0x1d) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_SPLITTER_GUN,iVar16);
      }
      else if (iVar10 == 0x15) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_ION_RIFLE,iVar16);
      }
      else if (iVar10 == 0x16) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_ION_MINIGUN,iVar16);
      }
      else if (iVar10 == 0x17) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_ION_CANNON,iVar16);
      }
      else if (iVar10 == 0x1c) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_PLASMA_CANNON,iVar16);
      }
      else if (iVar10 == 0x1f) {
        local_3c = 1.12104e-44;
        do {
          pVar21 = PROJECTILE_TYPE_ION_MINIGUN;
          local_c = local_1c + (&player_state_table)[iVar7].pos_y;
          local_10 = local_20 + *pfVar17;
          iVar10 = iVar16;
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 200 + -100);
          iVar10 = projectile_spawn(&local_10,(float)(int)local_28 * 0.0026 + fVar2,pVar21,iVar10);
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 0x50);
          local_3c = (float)((int)local_3c + -1);
          projectile_pool[iVar10].pos.tail.vy.speed_scale = (float)(int)local_28 * 0.01 + 1.4;
        } while (local_3c != 0.0);
      }
      else if (iVar10 == 0xb) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_PLASMA_MINIGUN,iVar16);
      }
      else if (iVar10 == 0x1e) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        local_10 = (float)fVar18 * 15.0;
        local_c = (float)fVar19 * 15.0;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.33;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        local_3c = 8.40779e-45;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.263;
        do {
          pVar21 = PROJECTILE_TYPE_GAUSS_GUN;
          local_c = local_1c + (&player_state_table)[iVar7].pos_y;
          local_10 = local_20 + *pfVar17;
          iVar10 = iVar16;
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 200 + -100);
          iVar10 = projectile_spawn(&local_10,(float)(int)local_28 * 0.002 + fVar2,pVar21,iVar10);
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 0x50);
          local_3c = (float)((int)local_3c + -1);
          projectile_pool[iVar10].pos.tail.vy.speed_scale = (float)(int)local_28 * 0.01 + 1.4;
        } while (local_3c != 0.0);
      }
      else if (iVar10 == 6) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        local_10 = (float)fVar18 * 15.0;
        local_c = (float)fVar19 * 15.0;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.33;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.263;
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_GAUSS_GUN,iVar16);
      }
      else if (iVar10 == 0xc) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        local_10 = (float)fVar18 * 15.0;
        local_c = (float)fVar19 * 15.0;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.34;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.283;
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        fx_spawn_secondary_projectile(&local_10,fVar2,SECONDARY_PROJECTILE_TYPE_ROCKET);
      }
      else if (iVar10 == 0x11) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        local_10 = (float)fVar18 * 15.0;
        local_c = (float)fVar19 * 15.0;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.34;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.283;
        fVar15 = (float)(&player_state_table)[iVar7].ammo * 1.0471976;
        fVar14 = 0.0;
        local_3c = (fVar2 - 3.1415927) - fVar15 * (float)(&player_state_table)[iVar7].ammo * 0.5;
        if (0.0 < (float)(&player_state_table)[iVar7].ammo) {
          do {
            local_c = local_1c + (&player_state_table)[iVar7].pos_y;
            local_10 = local_20 + *pfVar17;
            fx_spawn_secondary_projectile
                      (&local_10,local_3c,SECONDARY_PROJECTILE_TYPE_SEEKER_ROCKET);
            local_3c = local_3c + fVar15;
            fVar14 = (float)((int)fVar14 + 1);
            local_28 = fVar14;
          } while ((float)(int)fVar14 < (float)(&player_state_table)[iVar7].ammo);
        }
        local_38 = (float)(&player_state_table)[iVar7].ammo;
      }
      else if (iVar10 == 0x12) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar18 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar18 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.34;
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        fx_spawn_secondary_projectile(&local_10,fVar2,SECONDARY_PROJECTILE_TYPE_ROCKET_MINIGUN);
      }
      else if (iVar10 == 0xd) {
        fVar18 = (float10)fcos((float10)fVar15);
        local_10 = (float)(fVar18 * (float10)25.0);
        fVar19 = (float10)fsin((float10)fVar15);
        local_c = (float)(fVar19 * (float10)25.0);
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,1.0);
        local_10 = (float)fVar18 * 15.0;
        local_c = (float)fVar19 * 15.0;
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.31;
        local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
        local_18 = local_20 + *pfVar17;
        iVar10 = fx_spawn_sprite(&local_18,&local_10,2.0);
        (&sprite_effect_pool)[iVar10].color_r = 0.5;
        (&sprite_effect_pool)[iVar10].color_g = 0.5;
        (&sprite_effect_pool)[iVar10].color_b = 0.5;
        (&sprite_effect_pool)[iVar10].color_a = 0.243;
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        fx_spawn_secondary_projectile(&local_10,fVar2,SECONDARY_PROJECTILE_TYPE_SEEKER_ROCKET);
      }
      else if (iVar10 == 7) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_PISTOL,iVar16);
      }
      else if (iVar10 == 0xe) {
        local_3c = 1.96182e-44;
        do {
          pVar21 = PROJECTILE_TYPE_PLASMA_MINIGUN;
          local_c = local_1c + (&player_state_table)[iVar7].pos_y;
          local_10 = local_20 + *pfVar17;
          iVar10 = iVar16;
          uVar9 = crt_rand();
          local_28 = (float)((uVar9 & 0xff) - 0x80);
          iVar10 = projectile_spawn(&local_10,(float)(int)local_28 * 0.002 + fVar2,pVar21,iVar10);
          iVar11 = crt_rand();
          local_28 = (float)(iVar11 % 100);
          local_3c = (float)((int)local_3c + -1);
          projectile_pool[iVar10].pos.tail.vy.speed_scale = (float)(int)local_28 * 0.01 + 1.0;
        } while (local_3c != 0.0);
      }
      else if (iVar10 == 0x29) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_PLAGUE_SPREADER,iVar16);
      }
      else if (iVar10 == 0x2b) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,fVar2,PROJECTILE_TYPE_RAINBOW_GUN,iVar16);
      }
      else if (iVar10 == 0x2a) {
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        fx_spawn_particle_slow(&local_10,fVar2 - 1.5707964);
        local_38 = 0.15;
      }
    }
    iVar10 = perk_count_get(perk_id_sharpshooter);
    if (iVar10 == 0) {
      (&player_state_table)[iVar7].spread_heat =
           (&weapon_table)[(&player_state_table)[iVar7].weapon_id].spread_heat * 1.3 +
           (&player_state_table)[iVar7].spread_heat;
    }
    if (_bonus_reflex_boost_timer <= 0.0) {
      (&player_state_table)[iVar7].ammo = (int)((float)(&player_state_table)[iVar7].ammo - local_38)
      ;
    }
  }
  else {
    sfx_play_panned(DAT_004d9050);
    sfx_play_panned(DAT_004d7fd8);
    if ((&weapon_table)[(&player_state_table)[iVar7].weapon_id].pellet_count == 1) {
      (&player_state_table)[iVar7].shot_cooldown = DAT_004d9040;
      fVar14 = _DAT_004d9048;
    }
    else {
      (&player_state_table)[iVar7].shot_cooldown =
           (&weapon_table)[(&player_state_table)[iVar7].weapon_id].shot_cooldown;
      fVar14 = (&weapon_table)[(&player_state_table)[iVar7].weapon_id].spread_heat;
    }
    iVar10 = 0;
    *pfVar1 = fVar14 + *pfVar1;
    if (0 < (&weapon_table)[(&player_state_table)[iVar7].weapon_id].pellet_count) {
      do {
        iVar11 = crt_rand();
        local_28 = (float)(iVar11 % 200 + -100) * 0.0015 + fVar2;
        local_c = local_1c + (&player_state_table)[iVar7].pos_y;
        local_10 = local_20 + *pfVar17;
        projectile_spawn(&local_10,local_28,PROJECTILE_TYPE_FIRE_BULLETS,iVar16);
        iVar10 = iVar10 + 1;
      } while (iVar10 < (&weapon_table)[(&player_state_table)[iVar7].weapon_id].pellet_count);
    }
    fVar18 = (float10)fcos((float10)fVar15);
    local_10 = (float)(fVar18 * (float10)25.0);
    fVar18 = (float10)fsin((float10)fVar15);
    local_c = (float)(fVar18 * (float10)25.0);
    local_14 = local_1c + (&player_state_table)[iVar7].pos_y;
    local_18 = local_20 + *pfVar17;
    iVar16 = fx_spawn_sprite(&local_18,&local_10,1.0);
    iVar10 = perk_id_sharpshooter;
    (&sprite_effect_pool)[iVar16].color_r = 0.5;
    (&sprite_effect_pool)[iVar16].color_g = 0.5;
    (&sprite_effect_pool)[iVar16].color_b = 0.5;
    (&sprite_effect_pool)[iVar16].color_a = 0.413;
    iVar10 = perk_count_get(iVar10);
    if (iVar10 == 0) {
      (&player_state_table)[iVar7].spread_heat =
           _DAT_004d9048 * 1.3 + (&player_state_table)[iVar7].spread_heat;
    }
  }
  if (0.48 < (&player_state_table)[iVar7].spread_heat) {
    (&player_state_table)[iVar7].spread_heat = 0.48;
  }
  if (0 < player_state_table.perk_counts[perk_id_fastshot]) {
    (&player_state_table)[iVar7].shot_cooldown = (&player_state_table)[iVar7].shot_cooldown * 0.88;
  }
  if (0 < player_state_table.perk_counts[perk_id_sharpshooter]) {
    (&player_state_table)[iVar7].shot_cooldown = (&player_state_table)[iVar7].shot_cooldown * 1.05;
  }
  if ((float)(&player_state_table)[iVar7].ammo <= 0.0) {
    player_start_reload();
  }
LAB_0041753e:
  fVar15 = (&player_state_table)[iVar7].move_phase;
  while (14.0 < fVar15) {
    fVar15 = (&player_state_table)[iVar7].move_phase - 14.0;
    (&player_state_table)[iVar7].move_phase = fVar15;
  }
  fVar15 = (&player_state_table)[iVar7].move_phase;
  while (fVar15 < 0.0) {
    fVar15 = (&player_state_table)[iVar7].move_phase + 14.0;
    (&player_state_table)[iVar7].move_phase = fVar15;
  }
  if (0.0 < (&player_state_table)[iVar7].speed_bonus_timer) {
    (&player_state_table)[iVar7].speed_multiplier =
         (&player_state_table)[iVar7].speed_multiplier - 1.0;
  }
  fVar15 = (&player_state_table)[iVar7].size * 0.5;
  if (*pfVar17 < fVar15) {
    *pfVar17 = fVar15;
  }
  if ((float)terrain_texture_width - fVar15 < *pfVar17) {
    *pfVar17 = (float)terrain_texture_width - fVar15;
  }
  pfVar17 = &(&player_state_table)[iVar7].pos_y;
  if ((&player_state_table)[iVar7].pos_y < fVar15) {
    *pfVar17 = fVar15;
  }
  if ((float)terrain_texture_height - fVar15 < *pfVar17) {
    *pfVar17 = (float)terrain_texture_height - fVar15;
  }
  if (0.8 < *pfVar1) {
    *pfVar1 = 0.8;
  }
  return;
}



