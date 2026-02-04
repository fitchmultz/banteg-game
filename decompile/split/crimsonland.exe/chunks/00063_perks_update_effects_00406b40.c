/* perks_update_effects @ 00406b40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* updates perk timers/effects (regen, shields, evil eyes, jinxed, bonus timers) */

void perks_update_effects(void)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  float fVar7;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = perk_count_get(perk_id_regeneration);
  if (((iVar2 != 0) && (uVar3 = crt_rand(), (uVar3 & 1) != 0)) &&
     (iVar2 = config_blob.reserved0._20_4_, 0 < (int)config_blob.reserved0._20_4_)) {
    do {
      if (((player_state_table.health < 100.0) && (0.0 < player_state_table.health)) &&
         (player_state_table.health = player_state_table.health + frame_dt,
         100.0 < player_state_table.health)) {
        player_state_table.health = 100.0;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  _DAT_004808a4 = _DAT_004808a4 - frame_dt;
  if (_DAT_004808a4 < 0.0) {
    _DAT_004808a4 = 0.25;
    if (0 < player_state_table.perk_counts[perk_id_lean_mean_exp_machine]) {
      player_state_table.experience =
           player_state_table.experience +
           player_state_table.perk_counts[perk_id_lean_mean_exp_machine] * 10;
    }
  }
  render_overlay_player_index = 0;
  if (0 < (int)config_blob.reserved0._20_4_) {
    do {
      iVar2 = perk_count_get(perk_id_death_clock);
      if (iVar2 != 0) {
        pfVar1 = &(&player_state_table)[render_overlay_player_index].health;
        if ((&player_state_table)[render_overlay_player_index].health <= 0.0) {
          *pfVar1 = 0.0;
        }
        else {
          *pfVar1 = *pfVar1 - frame_dt * 3.3333333;
        }
      }
      if ((&player_state_table)[render_overlay_player_index].shield_timer <= 0.0) {
        (&player_state_table)[render_overlay_player_index].shield_timer = 0.0;
      }
      else {
        (&player_state_table)[render_overlay_player_index].shield_timer =
             (&player_state_table)[render_overlay_player_index].shield_timer - frame_dt;
      }
      if ((&player_state_table)[render_overlay_player_index].fire_bullets_timer <= 0.0) {
        (&player_state_table)[render_overlay_player_index].fire_bullets_timer = 0.0;
      }
      else {
        (&player_state_table)[render_overlay_player_index].fire_bullets_timer =
             (&player_state_table)[render_overlay_player_index].fire_bullets_timer - frame_dt;
      }
      if ((&player_state_table)[render_overlay_player_index].speed_bonus_timer <= 0.0) {
        (&player_state_table)[render_overlay_player_index].speed_bonus_timer = 0.0;
      }
      else {
        (&player_state_table)[render_overlay_player_index].speed_bonus_timer =
             (&player_state_table)[render_overlay_player_index].speed_bonus_timer - frame_dt;
      }
      render_overlay_player_index = render_overlay_player_index + 1;
    } while (render_overlay_player_index < (int)config_blob.reserved0._20_4_);
  }
  DAT_00487268 = -1;
  if (((0 < player_state_table.perk_counts[perk_id_doctor]) ||
      (0 < player_state_table.perk_counts[perk_id_pyrokinetic])) ||
     (0 < player_state_table.perk_counts[perk_id_evil_eyes])) {
    player_state_table.evil_eyes_target_creature = -1;
    iVar2 = creature_find_in_radius(&player_state_table.aim_x,12.0,0);
    if (iVar2 != -1) {
      iVar4 = perk_count_get(perk_id_doctor);
      if (iVar4 != 0) {
        DAT_00487268 = iVar2;
      }
      iVar4 = perk_count_get(perk_id_pyrokinetic);
      if (iVar4 != 0) {
        fVar7 = (&creature_pool)[iVar2].collision_timer - frame_dt;
        (&creature_pool)[iVar2].collision_timer = fVar7;
        if (fVar7 < 0.0) {
          (&creature_pool)[iVar2].collision_timer = 0.5;
          pfVar1 = &(&creature_pool)[iVar2].pos_x;
          puVar6 = &local_8;
          fVar7 = 0.8;
          local_8 = 0;
          local_4 = 0;
          iVar4 = crt_rand();
          fx_spawn_particle(pfVar1,(float)(iVar4 % 0x274) * 0.01,puVar6,fVar7);
          puVar6 = &local_8;
          local_8 = 0;
          local_4 = 0;
          fVar7 = 0.6;
          iVar4 = crt_rand();
          fx_spawn_particle(pfVar1,(float)(iVar4 % 0x274) * 0.01,puVar6,fVar7);
          puVar6 = &local_8;
          local_8 = 0;
          local_4 = 0;
          fVar7 = 0.4;
          iVar4 = crt_rand();
          fx_spawn_particle(pfVar1,(float)(iVar4 % 0x274) * 0.01,puVar6,fVar7);
          puVar6 = &local_8;
          local_8 = 0;
          local_4 = 0;
          fVar7 = 0.3;
          iVar4 = crt_rand();
          fx_spawn_particle(pfVar1,(float)(iVar4 % 0x274) * 0.01,puVar6,fVar7);
          puVar6 = &local_8;
          local_8 = 0;
          local_4 = 0;
          fVar7 = 0.2;
          iVar4 = crt_rand();
          fx_spawn_particle(pfVar1,(float)(iVar4 % 0x274) * 0.01,puVar6,fVar7);
          fx_queue_add_random(pfVar1);
        }
      }
      iVar4 = perk_count_get(perk_id_evil_eyes);
      if (iVar4 != 0) {
        player_state_table.evil_eyes_target_creature = iVar2;
      }
    }
  }
  iVar2 = perk_count_get(perk_id_evil_eyes);
  if (iVar2 == 0) {
    player_state_table.evil_eyes_target_creature = -1;
  }
  if (((_DAT_004aaf1c < 0.0) || (_DAT_004aaf1c = _DAT_004aaf1c - frame_dt, _DAT_004aaf1c < 0.0)) &&
     (0 < player_state_table.perk_counts[perk_id_jinxed])) {
    iVar2 = crt_rand();
    if (iVar2 % 10 == 3) {
      player_state_table.health = player_state_table.health - 5.0;
      fx_queue_add_random(&player_state_table.pos_x);
      fx_queue_add_random(&player_state_table.pos_x);
    }
    iVar2 = crt_rand();
    _DAT_004aaf1c = (float)(iVar2 % 0x14) * 0.1 + _DAT_004aaf1c + 2.0;
    if (_bonus_freeze_timer <= 0.0) {
      iVar2 = crt_rand();
      render_overlay_player_index = 0;
      iVar2 = iVar2 % 0x17f;
      do {
        if ((&creature_pool)[iVar2].active != '\0') break;
        iVar2 = crt_rand();
        iVar2 = iVar2 % 0x17f;
        render_overlay_player_index = render_overlay_player_index + 1;
      } while (render_overlay_player_index < 10);
      render_overlay_player_index = 0;
      if ((&creature_pool)[iVar2].active != '\0') {
        fVar7 = frame_dt * 20.0;
        (&creature_pool)[iVar2].health = -1.0;
        (&creature_pool)[iVar2].hitbox_size = (&creature_pool)[iVar2].hitbox_size - fVar7;
        lVar5 = __ftol();
        player_state_table.experience = (int)lVar5;
        sfx_play_panned(sfx_trooper_inpain_01_alias_1);
      }
    }
  }
  return;
}



