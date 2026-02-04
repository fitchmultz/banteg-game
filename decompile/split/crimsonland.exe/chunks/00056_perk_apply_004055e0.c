/* perk_apply @ 004055e0 */

/* applies perk effects and increments perk counter */

void __cdecl perk_apply(int perk_id)

{
  float fVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  int *piVar5;
  creature_t *pcVar6;
  int iVar7;
  bool bVar8;
  longlong lVar9;
  
  sfx_play(sfx_ui_bonus);
  bVar8 = perk_id == perk_id_instant_winner;
  player_state_table.perk_counts[perk_id] = player_state_table.perk_counts[perk_id] + 1;
  iVar4 = config_blob.reserved0._20_4_;
  if (bVar8) {
    player_state_table.experience = player_state_table.experience + 0x9c4;
  }
  else if (perk_id == perk_id_fatal_lottery) {
    uVar2 = crt_rand();
    iVar4 = config_blob.reserved0._20_4_;
    if ((uVar2 & 1) == 0) {
      player_state_table.experience = player_state_table.experience + 10000;
    }
    else {
      player_state_table.health = -1.0;
    }
  }
  else if (perk_id == perk_id_lifeline_50_50) {
    bVar8 = false;
    pcVar6 = &creature_pool;
    do {
      if ((((bVar8) && (pcVar6->active != '\0')) && (pcVar6->health <= 500.0)) &&
         ((pcVar6->flags & 4) == 0)) {
        pcVar6->active = '\0';
        effect_spawn_burst(&pcVar6->pos_x,4);
      }
      pcVar6 = pcVar6 + 1;
      bVar8 = (bool)(bVar8 ^ 1);
      iVar4 = config_blob.reserved0._20_4_;
    } while ((int)pcVar6 < 0x4aa338);
  }
  else if (perk_id == perk_id_thick_skinned) {
    if (0 < (int)config_blob.reserved0._20_4_) {
      pfVar3 = &player_state_table.health;
      iVar7 = config_blob.reserved0._20_4_;
      do {
        if ((0.0 < *pfVar3) &&
           (fVar1 = *pfVar3 - *pfVar3 * 0.33333334, *pfVar3 = fVar1, fVar1 <= 0.0)) {
          *pfVar3 = 1.0;
        }
        pfVar3 = pfVar3 + 0xd8;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  else if (perk_id == perk_id_breathing_room) {
    if (0 < (int)config_blob.reserved0._20_4_) {
      pfVar3 = &player_state_table.health;
      iVar7 = config_blob.reserved0._20_4_;
      do {
        iVar7 = iVar7 + -1;
        *pfVar3 = *pfVar3 - *pfVar3 * 0.6666667;
        pfVar3 = pfVar3 + 0xd8;
      } while (iVar7 != 0);
    }
    pfVar3 = &creature_pool.hitbox_size;
    do {
      if (((creature_t *)(pfVar3 + -4))->active != '\0') {
        *pfVar3 = *pfVar3 - frame_dt;
      }
      pfVar3 = pfVar3 + 0x26;
    } while ((int)pfVar3 < 0x4aa348);
    bonus_spawn_guard = 0;
  }
  else if (perk_id == perk_id_random_weapon) {
    iVar4 = 0;
    do {
      iVar7 = weapon_pick_random_available();
      iVar4 = iVar4 + 1;
      if ((iVar7 != 1) && (iVar7 != player_state_table.weapon_id)) break;
    } while (iVar4 < 100);
    weapon_assign_player(0,iVar7);
    iVar4 = config_blob.reserved0._20_4_;
  }
  if (perk_id == perk_id_infernal_contract) {
    player_state_table.level = player_state_table.level + 3;
    perk_pending_count = perk_pending_count + 3;
    if (0.0 < player_state_table.health) {
      player_state_table.health = 0.1;
    }
    if (0.0 < player2_health) {
      player2_health = 0.1;
    }
  }
  if (perk_id == perk_id_grim_deal) {
    lVar9 = __ftol();
    player_state_table.health = -1.0;
    player_state_table.experience = player_state_table.experience + (int)lVar9;
  }
  if ((perk_id == perk_id_ammo_maniac) && (iVar7 = 0, 0 < iVar4)) {
    piVar5 = &player_state_table.weapon_id;
    do {
      weapon_assign_player(iVar7,*piVar5);
      iVar7 = iVar7 + 1;
      piVar5 = piVar5 + 0xd8;
      iVar4 = config_blob.reserved0._20_4_;
    } while (iVar7 < (int)config_blob.reserved0._20_4_);
  }
  iVar7 = perk_id_regeneration;
  if (perk_id == perk_id_death_clock) {
    player_state_table.perk_counts[perk_id_greater_regeneration] = 0;
    player_state_table.perk_counts[iVar7] = 0;
    if (0 < iVar4) {
      pfVar3 = &player_state_table.health;
      iVar7 = iVar4;
      do {
        if (0.0 < *pfVar3) {
          *pfVar3 = 100.0;
        }
        pfVar3 = pfVar3 + 0xd8;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  if ((perk_id == perk_id_bandage) && (iVar7 = 0, 0 < iVar4)) {
    pfVar3 = &player_state_table.health;
    do {
      iVar4 = crt_rand();
      fVar1 = ((float)(iVar4 % 0x32) + 1.0) * *pfVar3;
      *pfVar3 = fVar1;
      if (100.0 < fVar1) {
        *pfVar3 = 100.0;
      }
      effect_spawn_burst(pfVar3 + -4,8);
      iVar7 = iVar7 + 1;
      pfVar3 = pfVar3 + 0xd8;
      iVar4 = config_blob.reserved0._20_4_;
    } while (iVar7 < (int)config_blob.reserved0._20_4_);
  }
  if ((perk_id == perk_id_my_favourite_weapon) && (0 < iVar4)) {
    piVar5 = &player_state_table.clip_size;
    do {
      iVar4 = iVar4 + -1;
      *piVar5 = (int)((float)*piVar5 + 2.0);
      piVar5 = piVar5 + 0xd8;
    } while (iVar4 != 0);
  }
  if (perk_id == perk_id_plaguebearer) {
    player_plaguebearer_active = 1;
  }
  return;
}



