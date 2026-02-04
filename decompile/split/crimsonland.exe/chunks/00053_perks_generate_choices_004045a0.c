/* perks_generate_choices @ 004045a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* builds the current perk choice list */

void perks_generate_choices(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  puVar6 = &perk_choice_ids;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
LAB_004045be:
  if ((((iVar5 == 0) && (_quest_stage_major == quest_monster_vision_meta->tier)) &&
      (_quest_stage_minor == quest_monster_vision_meta->index)) &&
     (iVar3 = perk_count_get(perk_id_monster_vision), iVar3 == 0)) {
    iVar5 = 1;
    perk_choice_ids = perk_id_monster_vision;
  }
  iVar3 = 0;
LAB_00404603:
  do {
    iVar3 = iVar3 + 1;
    iVar1 = perk_select_random();
    iVar2 = perk_id_pyromaniac;
    (&perk_choice_ids)[iVar5] = iVar1;
    if (iVar1 == iVar2) {
      if (player_state_table.weapon_id != 8) goto LAB_00404603;
    }
    iVar2 = perk_count_get(perk_id_death_clock);
    if (((iVar2 == 0) ||
        ((((((iVar2 = (&perk_choice_ids)[iVar5], iVar2 != perk_id_jinxed &&
             (iVar2 != perk_id_breathing_room)) &&
            ((iVar2 != perk_id_grim_deal &&
             ((iVar2 != perk_id_highlander && (iVar2 != perk_id_fatal_lottery)))))) &&
           (iVar2 != DAT_004c2b8c)) &&
          (((iVar2 != perk_id_ammunition_within && (iVar2 != perk_id_infernal_contract)) &&
           (iVar2 != perk_id_regeneration)))) &&
         (((iVar2 != perk_id_greater_regeneration && (iVar2 != perk_id_thick_skinned)) &&
          (iVar2 != perk_id_bandage)))))) &&
       ((((iVar2 = (&perk_choice_ids)[iVar5], iVar2 != perk_id_jinxed &&
          (iVar2 != perk_id_ammunition_within)) &&
         ((iVar2 != perk_id_anxious_loader && (iVar2 != perk_id_monster_vision)))) ||
        (iVar2 = crt_rand(), ((byte)iVar2 & 3) != 1)))) {
      if ((10000 < iVar3) && (((&perk_meta_table)[(&perk_choice_ids)[iVar5]].flags & 4) != 0))
      break;
      piVar4 = &perk_choice_ids;
      for (iVar2 = 0; iVar2 < iVar5; iVar2 = iVar2 + 1) {
        if (*piVar4 == (&perk_choice_ids)[iVar5]) goto LAB_00404603;
        piVar4 = piVar4 + 1;
      }
      if (((((&perk_meta_table)[(&perk_choice_ids)[iVar5]].flags & 4) != 0) ||
          (player_state_table.perk_counts[(&perk_choice_ids)[iVar5]] < 1)) || (29999 < iVar3))
      break;
    }
  } while( true );
  if (24999 < iVar3) {
    console_printf(&console_log_queue,s_Perk_Randomizer_failed_to_genera_00471afc);
  }
  iVar5 = iVar5 + 1;
  if (6 < iVar5) {
    if (config_blob.reserved0._24_4_ == 8) {
      perk_choice_ids = perk_id_sharpshooter;
      DAT_004807ec = perk_id_long_distance_runner;
      _DAT_004807f0 = perk_id_evil_eyes;
      _DAT_004807f4 = perk_id_radioactive;
      _DAT_004807f8 = perk_id_fastshot;
      _DAT_004807fc = perk_id_fastshot;
      _DAT_00480800 = perk_id_fastshot;
    }
    return;
  }
  goto LAB_004045be;
}



