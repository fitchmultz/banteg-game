/* bonus_apply @ 00409890 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* applies a picked bonus to the player and spawns related effects */

void __cdecl bonus_apply(int player_index,bonus_entry_t *bonus_entry)

{
  float fVar1;
  bonus_id_t bVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  float *pfVar8;
  creature_t *pcVar9;
  float10 fVar10;
  projectile_type_id_t pVar11;
  int owner_id;
  float local_10 [4];
  
  sfx_play(sfx_ui_bonus);
  local_10[0] = 1.0;
  iVar4 = perk_count_get(perk_id_bonus_economist);
  if (iVar4 != 0) {
    local_10[0] = 1.5;
  }
  bVar2 = bonus_entry->bonus_id;
  if (bVar2 == BONUS_ID_WEAPON) {
    weapon_assign_player(player_index,(bonus_entry->time).amount);
  }
  else if (bVar2 == BONUS_ID_MEDIKIT) {
    pfVar8 = &(&player_state_table)[player_index].health;
    if (((&player_state_table)[player_index].health < 100.0) &&
       (fVar1 = *pfVar8, *pfVar8 = fVar1 + 10.0, 100.0 < fVar1 + 10.0)) {
      *pfVar8 = 100.0;
    }
  }
  else if (bVar2 == BONUS_ID_REFLEX_BOOST) {
    if (_bonus_reflex_boost_timer <= 0.0) {
      FUN_0041a810(DAT_00485484,DAT_0048548c,&bonus_reflex_boost_timer,0);
    }
    _bonus_reflex_boost_timer =
         (float)(bonus_entry->time).amount * local_10[0] + _bonus_reflex_boost_timer;
    if (0 < (int)config_blob.reserved0._20_4_) {
      piVar5 = &player_state_table.ammo;
      iVar4 = config_blob.reserved0._20_4_;
      do {
        *piVar5 = piVar5[-2];
        piVar5[1] = 0;
        piVar5 = piVar5 + 0xd8;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    local_10[1] = 0.6;
    local_10[0] = 0.6;
    _effect_template_color_g = 0x3f19999a;
    local_10[2] = 1.0;
    local_10[3] = 1.0;
    _effect_template_color_r = 0x3f19999a;
    _effect_template_flags = 0x19;
    _effect_template_color_b = 0x3f800000;
    _effect_template_color_a = 0x3f800000;
    _effect_template_lifetime = 0x3e800000;
    _effect_template_age = 0;
    _effect_template_half_width = 0x42000000;
    _effect_template_half_height = 0x42000000;
    _effect_template_rotation = 0.0;
    effect_template_vel_x = 0.0;
    effect_template_vel_y = 0.0;
    _effect_template_scale_step = 0x42480000;
    effect_spawn(1,&(bonus_entry->time).pos_x);
    _effect_template_rotation = 0.0;
    effect_template_vel_x = 0.0;
    effect_template_vel_y = 0.0;
  }
  else if (bVar2 == BONUS_ID_WEAPON_POWER_UP) {
    if (_bonus_weapon_power_up_timer <= 0.0) {
      FUN_0041a810(DAT_00485420,DAT_00485428,&bonus_weapon_power_up_timer,0);
    }
    _bonus_weapon_power_up_timer =
         (float)(bonus_entry->time).amount * local_10[0] + _bonus_weapon_power_up_timer;
    (&player_state_table)[player_index].weapon_reset_latch = 0;
    (&player_state_table)[player_index].shot_cooldown = 0.0;
    (&player_state_table)[player_index].reload_timer = 0.0;
    (&player_state_table)[player_index].ammo = (&player_state_table)[player_index].clip_size;
  }
  else if (bVar2 == BONUS_ID_SPEED) {
    if ((player_state_table.speed_bonus_timer <= 0.0) && (player2_speed_bonus_timer <= 0.0)) {
      FUN_0041a810(DAT_004854d4,DAT_004854dc,0x490bc4,&player2_speed_bonus_timer);
    }
    (&player_state_table)[player_index].speed_bonus_timer =
         (float)(bonus_entry->time).amount * local_10[0] +
         (&player_state_table)[player_index].speed_bonus_timer;
  }
  else if (bVar2 == BONUS_ID_FREEZE) {
    if (_bonus_freeze_timer <= 0.0) {
      FUN_0041a810(DAT_004854ac,DAT_004854b4,&bonus_freeze_timer,0);
    }
    pfVar8 = &creature_pool.pos_x;
    _bonus_freeze_timer = (float)(bonus_entry->time).amount * local_10[0] + _bonus_freeze_timer;
    do {
      if ((((creature_t *)(pfVar8 + -5))->active != '\0') && (pfVar8[4] <= 0.0)) {
        iVar4 = 8;
        do {
          iVar6 = crt_rand();
          effect_spawn_freeze_shard(pfVar8,(float)(iVar6 % 0x264) * 0.01);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        iVar4 = crt_rand();
        effect_spawn_freeze_shatter(pfVar8,(float)(iVar4 % 0x264) * 0.01);
        ((creature_t *)(pfVar8 + -5))->active = '\0';
      }
      pfVar8 = pfVar8 + 0x26;
    } while ((int)pfVar8 < 0x4aa34c);
    local_10[0] = 0.3;
    local_10[1] = 0.5;
    local_10[2] = 0.8;
    local_10[3] = 1.0;
    _effect_template_color_r = 0x3e99999a;
    _effect_template_flags = 0x19;
    _effect_template_color_g = 0x3f000000;
    _effect_template_color_b = 0x3f4ccccd;
    _effect_template_color_a = 0x3f800000;
    _effect_template_lifetime = 0x3e800000;
    _effect_template_age = 0;
    _effect_template_half_width = 0x42000000;
    _effect_template_half_height = 0x42000000;
    _effect_template_rotation = 0.0;
    effect_template_vel_x = 0.0;
    effect_template_vel_y = 0.0;
    _effect_template_scale_step = 0x42480000;
    effect_spawn(1,&(bonus_entry->time).pos_x);
    sfx_play_panned(sfx_shockwave);
    _effect_template_rotation = 0.0;
    effect_template_vel_x = 0.0;
    effect_template_vel_y = 0.0;
  }
  else if (bVar2 == BONUS_ID_SHIELD) {
    if ((player_state_table.shield_timer <= 0.0) && (player2_shield_timer <= 0.0)) {
      FUN_0041a810(DAT_00485498,DAT_004854a0,0x490bc8,&player2_shield_timer);
    }
    (&player_state_table)[player_index].shield_timer =
         (float)(bonus_entry->time).amount * local_10[0] +
         (&player_state_table)[player_index].shield_timer;
  }
  else if (bVar2 == BONUS_ID_SHOCK_CHAIN) {
    bonus_spawn_guard = 1;
    if (*(float *)((int)cv_friendlyFire + 0xc) == 0.0) {
      iVar4 = -100;
    }
    else {
      iVar4 = -1 - player_index;
    }
    pfVar8 = &(bonus_entry->time).pos_x;
    shock_chain_links_left = 0x20;
    iVar6 = creature_find_nearest(pfVar8,-1,0.0);
    fVar10 = (float10)fpatan((float10)(&creature_pool)[iVar6].pos_y -
                             (float10)(bonus_entry->time).pos_y,
                             (float10)(&creature_pool)[iVar6].pos_x - (float10)*pfVar8);
    shock_chain_projectile_id =
         projectile_spawn(pfVar8,(float)((fVar10 - (float10)1.5707964) - (float10)3.1415927),
                          PROJECTILE_TYPE_ION_RIFLE,iVar4);
    bonus_spawn_guard = 0;
    sfx_play_panned(sfx_shock_hit_01);
  }
  else if (bVar2 == BONUS_ID_FIREBLAST) {
    bonus_spawn_guard = 1;
    if (*(float *)((int)cv_friendlyFire + 0xc) == 0.0) {
      iVar4 = -100;
    }
    else {
      iVar4 = -1 - player_index;
    }
    player_index = 0;
    do {
      projectile_spawn(&(bonus_entry->time).pos_x,(float)player_index * 0.3926991,
                       PROJECTILE_TYPE_PLASMA_RIFLE,iVar4);
      player_index = player_index + 1;
    } while (player_index < 0x10);
    bonus_spawn_guard = 0;
    sfx_play_panned(sfx_explosion_medium);
  }
  else if (bVar2 == BONUS_ID_FIRE_BULLETS) {
    if ((player_state_table.fire_bullets_timer <= 0.0) && (player2_fire_bullets_timer <= 0.0)) {
      FUN_0041a810(DAT_004854e8,DAT_004854f0,0x490bcc,&player2_fire_bullets_timer);
    }
    (&player_state_table)[player_index].fire_bullets_timer =
         local_10[0] * 5.0 + (&player_state_table)[player_index].fire_bullets_timer;
    (&player_state_table)[player_index].weapon_reset_latch = 0;
    (&player_state_table)[player_index].shot_cooldown = 0.0;
    (&player_state_table)[player_index].reload_timer = 0.0;
    (&player_state_table)[player_index].ammo = (&player_state_table)[player_index].clip_size;
  }
  else if (bVar2 == BONUS_ID_ENERGIZER) {
    if (_bonus_energizer_timer <= 0.0) {
      FUN_0041a810(DAT_004853f8,DAT_00485400,&bonus_energizer_timer,0);
    }
    _bonus_energizer_timer = local_10[0] * 8.0 + _bonus_energizer_timer;
  }
  else if (bVar2 == BONUS_ID_DOUBLE_EXPERIENCE) {
    if (_bonus_double_xp_timer <= 0.0) {
      FUN_0041a810(DAT_00485448,DAT_00485450,&bonus_double_xp_timer,0);
    }
    _bonus_double_xp_timer = local_10[0] * 6.0 + _bonus_double_xp_timer;
  }
  else if (bVar2 == BONUS_ID_NUKE) {
    uVar7 = crt_rand();
    iVar4 = (uVar7 & 3) + 4;
    if (iVar4 != 0) {
      do {
        owner_id = -100;
        pVar11 = PROJECTILE_TYPE_PISTOL;
        iVar6 = crt_rand();
        iVar6 = projectile_spawn(&(bonus_entry->time).pos_x,(float)(iVar6 % 0x274) * 0.01,pVar11,
                                 owner_id);
        if (iVar6 != -1) {
          pfVar8 = &projectile_pool[iVar6].pos.tail.vy.speed_scale;
          iVar6 = crt_rand();
          *pfVar8 = ((float)(iVar6 % 0x32) * 0.01 + 0.5) * *pfVar8;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    iVar6 = -100;
    pVar11 = PROJECTILE_TYPE_GAUSS_GUN;
    pfVar8 = &(bonus_entry->time).pos_x;
    iVar4 = crt_rand();
    projectile_spawn(pfVar8,(float)(iVar4 % 0x274) * 0.01,pVar11,iVar6);
    iVar6 = -100;
    pVar11 = PROJECTILE_TYPE_GAUSS_GUN;
    iVar4 = crt_rand();
    projectile_spawn(pfVar8,(float)(iVar4 % 0x274) * 0.01,pVar11,iVar6);
    effect_spawn_explosion_burst(pfVar8,1.0);
    camera_shake_pulses = 0x14;
    _camera_shake_timer = 0x3e4ccccd;
    bonus_spawn_guard = 1;
    iVar4 = 0;
    pcVar9 = &creature_pool;
    do {
      if ((((pcVar9->active != '\0') && (ABS(pcVar9->pos_x - *pfVar8) <= 256.0)) &&
          (ABS(pcVar9->pos_y - (bonus_entry->time).pos_y) <= 256.0)) &&
         (fVar1 = pcVar9->pos_x - *pfVar8, fVar3 = pcVar9->pos_y - (bonus_entry->time).pos_y,
         fVar1 = 256.0 - SQRT(fVar3 * fVar3 + fVar1 * fVar1), 0.0 < fVar1)) {
        local_10[0] = 0.0;
        local_10[1] = 0.0;
        creature_apply_damage(iVar4,fVar1 * 5.0,3,local_10);
      }
      pcVar9 = pcVar9 + 1;
      iVar4 = iVar4 + 1;
    } while ((int)pcVar9 < 0x4aa338);
    bonus_spawn_guard = 0;
    sfx_play_panned(sfx_explosion_large);
    sfx_play_panned(sfx_shockwave);
  }
  else if (bVar2 == BONUS_ID_POINTS) {
    player_state_table.experience = player_state_table.experience + (bonus_entry->time).amount;
  }
  local_10[0] = 0.4;
  local_10[1] = 0.5;
  local_10[2] = 1.0;
  local_10[3] = 0.5;
  _effect_template_color_r = 0x3ecccccd;
  _effect_template_flags = 0x1d;
  _effect_template_color_g = 0x3f000000;
  _effect_template_color_b = 0x3f800000;
  _effect_template_color_a = 0x3f000000;
  _effect_template_lifetime = 0x3ecccccd;
  _effect_template_half_width = 0x42000000;
  _effect_template_half_height = 0x42000000;
  if (bonus_entry->bonus_id != BONUS_ID_NUKE) {
    iVar4 = 0xc;
    do {
      uVar7 = crt_rand();
      _effect_template_rotation = (float)(uVar7 & 0x7f) * 0.049087387;
      uVar7 = crt_rand();
      uVar7 = uVar7 & 0x8000007f;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xffffff80) + 1;
      }
      effect_template_vel_x = (float)(int)(uVar7 - 0x40);
      uVar7 = crt_rand();
      uVar7 = uVar7 & 0x8000007f;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xffffff80) + 1;
      }
      effect_template_vel_y = (float)(int)(uVar7 - 0x40);
      _effect_template_scale_step = 0x3dcccccd;
      effect_spawn(0,&(bonus_entry->time).pos_x);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}



