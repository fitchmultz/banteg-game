/* gameplay_reset_state @ 00412dc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* resets gameplay/session globals, pools, and availability tables */

void gameplay_reset_state(void)

{
  undefined4 uVar1;
  bonus_hud_slot_slide_x_block_t *pbVar2;
  uint uVar3;
  float *pfVar4;
  bonus_entry_t *pbVar5;
  projectile_t *ppVar6;
  sprite_effect_t *psVar7;
  secondary_projectile_t *psVar8;
  int iVar9;
  creature_spawn_slot_t *pcVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  undefined4 *puVar14;
  
  pbVar2 = &bonus_hud_slot_table[0].slide;
  DAT_0048727c = 0;
  do {
    pbVar2->field_0x1c = 5.0;
    *(undefined1 *)((int)(pbVar2 + -1) + 0x18) = 0;
    pbVar2->slide_x = 0.0;
    pbVar2->icon_id = 1;
    pbVar2->label = s_Empty_00473764;
    pbVar2->field_0x08 = 1.0;
    pbVar2 = (bonus_hud_slot_slide_x_block_t *)((int)(pbVar2 + 1) + 4);
  } while ((int)pbVar2 < 0x48f78c);
  quest_spawn_timeline = 0;
  shock_chain_links_left = 0;
  DAT_00486fb8 = 1;
  creature_spawned_count = 0;
  survival_recent_death_count = 0;
  survival_reward_damage_seen = 0;
  survival_reward_fire_seen = 0;
  DAT_00486fa9 = 1;
  survival_reward_handout_enabled = 1;
  tutorial_stage_index = 0xffffffff;
  tutorial_stage_timer = 0;
  tutorial_stage_transition_timer = 0xfffffc18;
  quest_transition_timer_ms = -1;
  _bonus_double_xp_timer = 0;
  survival_spawn_stage = 0;
  camera_shake_pulses = 0;
  bonus_reset_availability();
  _DAT_00482940 = 6;
  creature_type_table.texture_handle =
       (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_zombie_0047375c);
  creature_type_table.sfx_bank_b[0] = sfx_zombie_attack_01;
  creature_type_table.sfx_bank_b[1] = sfx_zombie_attack_02;
  creature_type_table.sfx_bank_a[0] = sfx_zombie_die_01;
  creature_type_table.sfx_bank_a[1] = sfx_zombie_die_02;
  creature_type_table.field_0x20 = 1.0;
  creature_type_table.anim_rate = 1.2;
  creature_type_table.sfx_bank_a[2] = sfx_zombie_die_03;
  creature_type_table.sfx_bank_a[3] = sfx_zombie_die_04;
  creature_type_table.base_frame = 0x20;
  creature_type_table.corpse_frame = 0;
  _DAT_0048276c = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_lizard_00473754);
  _DAT_00482784 = sfx_lizard_attack_02;
  _DAT_00482780 = sfx_lizard_attack_01;
  _DAT_00482770 = sfx_lizard_die_01;
  _DAT_00482778 = sfx_lizard_die_03;
  _DAT_0048278c = 0x3f800000;
  _DAT_004827a0 = 0x3fcccccd;
  _DAT_00482774 = sfx_lizard_die_02;
  _DAT_0048277c = sfx_lizard_die_04;
  _DAT_004827ac = 1;
  _DAT_004827a4 = 0x10;
  _DAT_004827a8 = 3;
  _DAT_004827f4 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_spider_sp1_00473748);
  _DAT_00482808 = sfx_spider_attack_01;
  _DAT_0048280c = sfx_spider_attack_02;
  _DAT_00482814 = 0x3f800000;
  _DAT_00482828 = 0x3fc00000;
  _DAT_004827f8 = sfx_spider_die_01;
  _DAT_004827fc = sfx_spider_die_02;
  _DAT_00482800 = sfx_spider_die_03;
  _DAT_00482804 = sfx_spider_die_04;
  _DAT_00482834 = 1;
  _DAT_0048282c = 0x10;
  _DAT_00482830 = 1;
  _DAT_00482838 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_spider_sp2_0047373c);
  _DAT_00482850 = sfx_spider_attack_02;
  _DAT_0048284c = sfx_spider_attack_01;
  _DAT_0048283c = sfx_spider_die_01;
  _DAT_00482844 = sfx_spider_die_03;
  _DAT_00482858 = 0x3f800000;
  _DAT_0048286c = 0x3fc00000;
  _DAT_00482840 = sfx_spider_die_02;
  _DAT_00482848 = sfx_spider_die_04;
  _DAT_00482878 = 1;
  _DAT_00482870 = 0x10;
  _DAT_00482874 = 2;
  DAT_004827b0 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_alien_00473734);
  _DAT_004827c4 = sfx_alien_attack_01;
  _DAT_004827c8 = sfx_alien_attack_02;
  _DAT_004827b4 = sfx_alien_die_01;
  _DAT_004827b8 = sfx_alien_die_02;
  _DAT_004827bc = sfx_alien_die_03;
  _DAT_004827c0 = sfx_alien_die_04;
  _DAT_00482880 = sfx_trooper_die_01;
  _DAT_004827d0 = 0x3f800000;
  _DAT_004827e4 = 0x3faccccd;
  _DAT_004827f0 = 0;
  _DAT_004827e8 = 0x20;
  _DAT_004827ec = 4;
  _DAT_00482884 = sfx_trooper_die_02;
  _DAT_00482888 = sfx_trooper_die_03;
  _DAT_004828b8 = 7;
  DAT_0048287c = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_trooper_0047372c);
  _camera_offset_x = (float)terrain_texture_width * 0.5;
  perk_choices_dirty = 1;
  bonus_spawn_guard = 0;
  puVar14 = &weapon_usage_time;
  for (iVar11 = 0x40; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  _camera_offset_y = (float)terrain_texture_height * 0.5;
  weapon_table_init();
  weapon_refresh_available();
  perks_rebuild_available();
  effect_defaults_reset();
  perk_pending_count = 0;
  survival_spawn_cooldown = 0;
  creatures_any_active_flag = 0;
  time_scale_active = 0;
  _time_scale_factor = 0x3f800000;
  _bonus_reflex_boost_timer = 0;
  _bonus_weapon_power_up_timer = 0;
  _bonus_energizer_timer = 0;
  plaguebearer_infection_count = 0;
  DAT_00487268 = 0xffffffff;
  highscore_active_record.full_version_marker = '\0';
  highscore_active_record.survival_elapsed_ms = 0;
  highscore_active_record.score_xp = 0;
  highscore_active_record.quest_stage_minor = '\0';
  highscore_active_record.quest_stage_major = '\0';
  highscore_active_record.game_mode_id = '\0';
  highscore_active_record.most_used_weapon_id = '\0';
  highscore_active_record.creature_kill_count = 0;
  highscore_active_record.shots_hit = 0;
  highscore_active_record.shots_fired = 0;
  highscore_active_record.date_checksum = '\0';
  highscore_active_record.year_offset = '\0';
  highscore_active_record.month = '\0';
  highscore_active_record.day = '\0';
  highscore_active_record.flags = '\0';
  uVar3 = crt_rand();
  highscore_active_record.reserved0._0_4_ = uVar3 & 0xfee050f;
  _DAT_004aaf24 = 0;
  _bonus_freeze_timer = 0;
  _DAT_004aaf1c = 0;
  _DAT_004aaf2c = 0xbf800000;
  perk_prompt_timer = 0;
  projectile_reset_pools();
  player_reset_all();
  player_aux_timer = 0;
  DAT_004871d4 = 0;
  pfVar4 = &player_state_table.low_health_timer;
  do {
    pfVar4[5] = -1.0;
    pfVar4[6] = -1.0;
    *pfVar4 = 100.0;
    pfVar4[3] = 0.0;
    pfVar4 = pfVar4 + 0xd8;
  } while ((int)pfVar4 < 0x491280);
  pbVar5 = bonus_pool;
  do {
    pbVar5->bonus_id = BONUS_ID_NONE;
    pbVar5 = pbVar5 + 1;
  } while ((int)pbVar5 < 0x482b08);
  ppVar6 = projectile_pool;
  do {
    ppVar6->active = '\0';
    ppVar6 = ppVar6 + 1;
  } while ((int)ppVar6 < 0x493eb8);
  psVar7 = &sprite_effect_pool;
  do {
    *(undefined1 *)&psVar7->active = 0;
    psVar7 = psVar7 + 1;
  } while ((int)psVar7 < 0x49aa20);
  psVar8 = secondary_projectile_pool;
  do {
    psVar8->active = '\0';
    psVar8 = psVar8 + 1;
  } while ((int)psVar8 < 0x4965d8);
  iVar11 = 0;
  piVar12 = &creature_pool.target_player;
  do {
    uVar1 = config_blob.reserved0._20_4_;
    piVar12[-0xe] = 0;
    ((creature_t *)(piVar12 + -0x1c))->active = '\0';
    if (uVar1 == 0) {
      *(undefined1 *)piVar12 = 0;
    }
    else {
      *(char *)piVar12 = (char)(iVar11 % (int)uVar1);
    }
    *(uchar *)(piVar12 + -0x1a) = '\x01';
    piVar12[7] = 0;
    iVar9 = crt_rand();
    piVar13 = piVar12 + 0x26;
    iVar11 = iVar11 + 1;
    piVar12[9] = (int)(float)(iVar9 % 0x1f);
    piVar12 = piVar13;
  } while ((int)piVar13 < 0x4aa3a8);
  pcVar10 = &creature_spawn_slot_table;
  do {
    pcVar10->owner = (creature_t *)0x0;
    pcVar10 = pcVar10 + 1;
  } while ((int)pcVar10 < 0x4852d0);
  fx_queue_rotated = 0;
  fx_queue_count = 0;
  highscore_active_record.full_version_marker = '\0';
  highscore_active_record.survival_elapsed_ms = 0;
  highscore_active_record.score_xp = 0;
  highscore_active_record.quest_stage_minor = '\0';
  highscore_active_record.quest_stage_major = '\0';
  highscore_active_record.game_mode_id = '\0';
  highscore_active_record.most_used_weapon_id = '\0';
  highscore_active_record.creature_kill_count = 0;
  highscore_active_record.shots_hit = 0;
  highscore_active_record.shots_fired = 0;
  highscore_active_record.date_checksum = '\0';
  highscore_active_record.year_offset = '\0';
  highscore_active_record.month = '\0';
  highscore_active_record.day = '\0';
  highscore_active_record.flags = '\0';
  uVar3 = crt_rand();
  highscore_active_record.reserved0._0_4_ = uVar3 & 0xfee050f;
  terrain_generate_random();
  return;
}



