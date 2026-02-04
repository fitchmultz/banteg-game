/* survival_update @ 00407cd0 */

/* main survival mode update: timers, scripted spawns, and enemy wave spawning */

void survival_update(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (console_open_flag != '\0') {
    return;
  }
  quest_spawn_timeline = quest_spawn_timeline + frame_dt_ms;
  if (demo_mode_active != '\0') {
    if (quest_spawn_timeline <= demo_time_limit_ms) {
      return;
    }
    render_pass_mode = 0;
    demo_mode_start();
    return;
  }
  if (config_blob.reserved0._20_4_ == 1) {
    if ((((survival_reward_damage_seen == '\0') && (survival_reward_fire_seen == '\0')) &&
        (64000 < (int)highscore_active_record.survival_elapsed_ms)) &&
       (survival_reward_handout_enabled != '\0')) {
      if (player_state_table.weapon_id == 1) {
        weapon_assign_player(0,0x18);
        DAT_00486fb8 = 0x18;
      }
      survival_reward_handout_enabled = '\0';
      survival_reward_damage_seen = '\x01';
      survival_reward_fire_seen = '\x01';
    }
    if (((survival_recent_death_count == 3) && (survival_reward_fire_seen == '\0')) &&
       ((local_44 = (survival_recent_death_pos_2.y +
                    survival_recent_death_pos_1.y + survival_recent_death_pos.y) * 0.33333334,
        fVar1 = player_state_table.pos_x -
                (survival_recent_death_pos.x + survival_recent_death_pos_1.x +
                survival_recent_death_pos_2.x) * 0.33333334,
        SQRT(fVar1 * fVar1 +
             (player_state_table.pos_y - local_44) * (player_state_table.pos_y - local_44)) < 16.0
        && (player_state_table.health < 15.0)))) {
      weapon_assign_player(0,0x19);
      DAT_00486fb8 = 0x19;
      survival_reward_fire_seen = '\x01';
      survival_reward_handout_enabled = '\0';
    }
  }
  if (survival_spawn_stage == 0) {
    if (player_state_table.level < 5) goto LAB_004082d6;
    survival_spawn_stage = 1;
    local_48 = -164.0;
    local_44 = 512.0;
    creature_spawn_template(0x12,&local_48,3.1415927);
    local_48 = 1188.0;
    local_44 = 512.0;
    creature_spawn_template(0x12,&local_48,3.1415927);
  }
  if (survival_spawn_stage == 1) {
    if (player_state_table.level < 9) goto LAB_004082d6;
    survival_spawn_stage = 2;
    local_48 = 1088.0;
    local_44 = 512.0;
    creature_spawn_template(0x2c,&local_48,3.1415927);
  }
  if (survival_spawn_stage == 2) {
    if (player_state_table.level < 0xb) goto LAB_004082d6;
    survival_spawn_stage = 3;
    local_48 = 0.0;
    do {
      fVar1 = local_48;
      local_40 = 1088.0;
      local_3c = (float)(int)local_48 * 42.666668 + 256.0;
      creature_spawn_template(0x35,&local_40,3.1415927);
      local_48 = (float)((int)fVar1 + 1);
    } while ((int)local_48 < 0xc);
  }
  if (survival_spawn_stage == 3) {
    if (player_state_table.level < 0xd) goto LAB_004082d6;
    survival_spawn_stage = 4;
    local_48 = 0.0;
    do {
      fVar1 = local_48;
      local_40 = 1088.0;
      local_3c = (float)(int)local_48 * 64.0 + 384.0;
      creature_spawn_template(0x2b,&local_40,3.1415927);
      local_48 = (float)((int)fVar1 + 1);
    } while ((int)local_48 < 4);
  }
  if (survival_spawn_stage == 4) {
    if (player_state_table.level < 0xf) goto LAB_004082d6;
    survival_spawn_stage = 5;
    local_48 = 0.0;
    do {
      fVar1 = local_48;
      local_40 = 1088.0;
      local_3c = (float)(int)local_48 * 64.0 + 384.0;
      creature_spawn_template(0x38,&local_40,3.1415927);
      local_48 = (float)((int)fVar1 + 1);
    } while ((int)local_48 < 4);
    local_48 = 0.0;
    do {
      fVar1 = local_48;
      local_40 = -64.0;
      local_3c = (float)(int)local_48 * 64.0 + 384.0;
      creature_spawn_template(0x38,&local_40,3.1415927);
      local_48 = (float)((int)fVar1 + 1);
    } while ((int)local_48 < 4);
  }
  if (survival_spawn_stage == 5) {
    if (player_state_table.level < 0x11) goto LAB_004082d6;
    survival_spawn_stage = 6;
    local_40 = 1088.0;
    local_3c = 512.0;
    creature_spawn_template(0x3a,&local_40,3.1415927);
  }
  if (survival_spawn_stage == 6) {
    if (player_state_table.level < 0x13) goto LAB_004082d6;
    survival_spawn_stage = 7;
    local_40 = 640.0;
    local_3c = 512.0;
    creature_spawn_template(1,&local_40,3.1415927);
  }
  if (survival_spawn_stage == 7) {
    if (player_state_table.level < 0x15) goto LAB_004082d6;
    survival_spawn_stage = 8;
    local_40 = 384.0;
    local_3c = 256.0;
    creature_spawn_template(1,&local_40,3.1415927);
    local_40 = 640.0;
    local_3c = 768.0;
    creature_spawn_template(1,&local_40,3.1415927);
  }
  if (survival_spawn_stage == 8) {
    if (player_state_table.level < 0x1a) goto LAB_004082d6;
    survival_spawn_stage = 9;
    local_48 = 0.0;
    do {
      fVar1 = local_48;
      local_40 = 1088.0;
      local_3c = (float)(int)local_48 * 64.0 + 384.0;
      creature_spawn_template(0x3c,&local_40,3.1415927);
      local_48 = (float)((int)fVar1 + 1);
    } while ((int)local_48 < 4);
    local_48 = 0.0;
    do {
      fVar1 = local_48;
      local_40 = -64.0;
      local_3c = (float)(int)local_48 * 64.0 + 384.0;
      creature_spawn_template(0x3c,&local_40,3.1415927);
      local_48 = (float)((int)fVar1 + 1);
    } while ((int)local_48 < 4);
  }
  if ((survival_spawn_stage == 9) && (0x1f < player_state_table.level)) {
    survival_spawn_stage = 10;
    local_40 = 1088.0;
    local_3c = 512.0;
    creature_spawn_template(0x3a,&local_40,3.1415927);
    local_40 = -64.0;
    local_3c = 512.0;
    creature_spawn_template(0x3a,&local_40,3.1415927);
    local_48 = 0.0;
    do {
      fVar1 = local_48;
      local_3c = -64.0;
      local_40 = (float)(int)local_48 * 64.0 + 384.0;
      creature_spawn_template(0x3c,&local_40,3.1415927);
      local_48 = (float)((int)fVar1 + 1);
    } while ((int)local_48 < 4);
    local_48 = 0.0;
    do {
      fVar1 = local_48;
      local_3c = 1088.0;
      local_40 = (float)(int)local_48 * 64.0 + 384.0;
      creature_spawn_template(0x3c,&local_40,3.1415927);
      local_48 = (float)((int)fVar1 + 1);
    } while ((int)local_48 < 4);
  }
LAB_004082d6:
  survival_spawn_cooldown = survival_spawn_cooldown - config_blob.reserved0._20_4_ * frame_dt_ms;
  render_overlay_player_index = 0;
joined_r0x004082fb:
  if (-1 < survival_spawn_cooldown) {
    config_blob.reserved0[0x14] = config_blob.reserved0[0x14];
    config_blob.reserved0[0x15] = config_blob.reserved0[0x15];
    config_blob.reserved0[0x16] = config_blob.reserved0[0x16];
    config_blob.reserved0[0x17] = config_blob.reserved0[0x17];
    return;
  }
  iVar5 = 500 - (int)highscore_active_record.survival_elapsed_ms / 0x708;
  if (iVar5 < 0) {
    uVar6 = 1U - iVar5 >> 1;
    iVar5 = iVar5 + uVar6 * 2;
    do {
      uVar2 = crt_rand();
      iVar3 = terrain_texture_height;
      iVar4 = terrain_texture_width;
      switch(uVar2 & 3) {
      case 0:
        iVar3 = crt_rand();
        local_48 = (float)(iVar3 % iVar4);
        local_3c = -40.0;
        pfVar7 = &local_40;
        local_40 = (float)(int)local_48;
        break;
      case 1:
        iVar3 = crt_rand();
        local_48 = (float)(iVar3 % iVar4);
        pfVar7 = &local_38;
        local_38 = (float)(int)local_48;
        local_34 = (float)terrain_texture_height + 40.0;
        break;
      case 2:
        iVar4 = crt_rand();
        local_48 = (float)(iVar4 % iVar3);
        pfVar7 = &local_30;
        local_30 = -40.0;
        local_2c = (float)(int)local_48;
        break;
      case 3:
        iVar4 = crt_rand();
        local_48 = (float)(iVar4 % iVar3);
        pfVar7 = &local_28;
        local_24 = (float)(int)local_48;
        local_28 = (float)terrain_texture_width + 40.0;
        break;
      default:
        goto switchD_00408344_default;
      }
      survival_spawn_creature(pfVar7);
switchD_00408344_default:
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  if (iVar5 < 1) {
    iVar5 = 1;
  }
  survival_spawn_cooldown = survival_spawn_cooldown + iVar5;
  uVar6 = crt_rand();
  iVar4 = terrain_texture_height;
  iVar5 = terrain_texture_width;
  switch(uVar6 & 3) {
  case 0:
    iVar4 = crt_rand();
    local_48 = (float)(iVar4 % iVar5);
    local_1c = 0xc2200000;
    pfVar7 = &local_20;
    local_20 = (float)(int)local_48;
    break;
  case 1:
    iVar4 = crt_rand();
    local_48 = (float)(iVar4 % iVar5);
    pfVar7 = &local_18;
    local_18 = (float)(int)local_48;
    local_14 = (float)terrain_texture_height + 40.0;
    break;
  case 2:
    iVar5 = crt_rand();
    local_48 = (float)(iVar5 % iVar4);
    pfVar7 = &local_10;
    local_10 = -40.0;
    local_c = (float)(int)local_48;
    break;
  case 3:
    iVar5 = crt_rand();
    local_48 = (float)(iVar5 % iVar4);
    pfVar7 = &local_8;
    local_4 = (float)(int)local_48;
    local_8 = (float)terrain_texture_width + 40.0;
    break;
  default:
    goto joined_r0x004082fb;
  }
  survival_spawn_creature(pfVar7);
  goto joined_r0x004082fb;
}



