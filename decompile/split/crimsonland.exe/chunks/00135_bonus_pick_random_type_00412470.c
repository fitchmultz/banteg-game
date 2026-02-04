/* bonus_pick_random_type @ 00412470 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* rolls a bonus id while respecting timers, perks, quest stage, and enabled flags */

bonus_id_t bonus_pick_random_type(void)

{
  bool bVar1;
  bool bVar2;
  uchar *puVar3;
  int iVar4;
  uint uVar5;
  bonus_id_t bVar6;
  bonus_id_t bVar7;
  bonus_id_t bVar8;
  int local_4;
  
  local_4 = 0;
  bVar2 = false;
  puVar3 = &bonus_pool[0].state;
  do {
    if ((((bonus_entry_t *)(puVar3 + -4))->bonus_id == BONUS_ID_FIRE_BULLETS) && (*puVar3 == '\0'))
    {
      bVar2 = true;
    }
    puVar3 = puVar3 + 0x1c;
  } while ((int)puVar3 < 0x482b0c);
  do {
    iVar4 = crt_rand();
    iVar4 = iVar4 % 0xa2;
    bVar7 = (bonus_id_t)(iVar4 + 1 < 0xe);
    if ((bVar7 == BONUS_ID_NONE) && (iVar4 + -0xc < 2)) {
      bVar7 = BONUS_ID_ENERGIZER;
    }
    iVar4 = iVar4 + -0xd;
    bVar8 = bVar7;
    if (bVar7 == BONUS_ID_ENERGIZER) {
      uVar5 = crt_rand();
      if ((uVar5 & 0x3f) != 0) {
        bVar7 = BONUS_ID_NONE;
LAB_004124e2:
        bVar6 = BONUS_ID_WEAPON;
        do {
          bVar8 = bVar6;
          if (iVar4 < 0xb) break;
          iVar4 = iVar4 + -10;
          bVar6 = bVar6 + BONUS_ID_POINTS;
          bVar8 = bVar7;
        } while ((int)bVar6 < 0xf);
      }
    }
    else if (bVar7 == BONUS_ID_NONE) goto LAB_004124e2;
    if ((shock_chain_links_left < 1) || (bVar8 != BONUS_ID_SHOCK_CHAIN)) {
      if (config_blob.reserved0._24_4_ == 3) {
        if ((((config_blob.hardcore == '\0') || (_quest_stage_major != 3)) &&
            (_quest_stage_major != 2)) || ((_quest_stage_minor != 10 || (bVar8 != BONUS_ID_NUKE))))
        {
          if ((config_blob.hardcore != '\0') && (_quest_stage_major == 2)) {
            if (_quest_stage_minor == 10) {
joined_r0x00412584:
              if (bVar8 == BONUS_ID_FREEZE) goto LAB_00412613;
            }
            goto LAB_0041258a;
          }
          if (_quest_stage_major == 4) {
            if (_quest_stage_minor != 10) goto LAB_0041258a;
            if (bVar8 != BONUS_ID_NUKE) goto joined_r0x00412584;
          }
          else if (((_quest_stage_major != 5) || (_quest_stage_minor != 10)) ||
                  (bVar8 != BONUS_ID_NUKE)) goto LAB_0041258a;
        }
      }
      else {
LAB_0041258a:
        if ((((_bonus_freeze_timer <= 0.0) || (bVar8 != BONUS_ID_FREEZE)) &&
            ((((player_state_table.shield_timer <= 0.0 && (player2_shield_timer <= 0.0)) ||
              (bVar8 != BONUS_ID_SHIELD)) &&
             ((iVar4 = perk_count_get(perk_id_my_favourite_weapon), iVar4 == 0 ||
              (bVar8 != BONUS_ID_WEAPON)))))) &&
           (((iVar4 = perk_count_get(perk_id_death_clock), iVar4 == 0 || (bVar8 != BONUS_ID_MEDIKIT)
             ) && (((bVar8 != BONUS_ID_WEAPON || (!bVar2)) &&
                   ((&bonus_meta_table)[bVar8].enabled != '\0')))))) {
          return bVar8;
        }
      }
    }
LAB_00412613:
    bVar1 = 99 < local_4;
    local_4 = local_4 + 1;
    if (bVar1) {
      return BONUS_ID_POINTS;
    }
  } while( true );
}



