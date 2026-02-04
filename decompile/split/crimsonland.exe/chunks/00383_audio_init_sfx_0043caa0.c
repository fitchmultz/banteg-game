/* audio_init_sfx @ 0043caa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* loads sfx pack and registers sound effect ids */

void audio_init_sfx(void)

{
  int iVar1;
  DWORD DVar2;
  DWORD DVar3;
  void **ppvVar4;
  char *fmt;
  
  if (config_blob.reserved0[0] == '\0') {
    iVar1 = resource_pack_set(s_sfx_paq_004784f4);
    DAT_004cc8d5 = (char)iVar1;
    if (DAT_004cc8d5 == '\0') {
      fmt = s____failed_to_set_sound_resource_p_0047849c;
    }
    else {
      fmt = s____set_sound_resource_paq__sfx_p_004784cc;
    }
    console_printf(&console_log_queue,fmt);
    DVar2 = timeGetTime();
    sfx_trooper_inpain_01 = sfx_load_sample(s_trooper_inPain_01_ogg_00477d98);
    sfx_trooper_inpain_02 = sfx_load_sample(s_trooper_inPain_02_ogg_00478484);
    _sfx_trooper_inpain_03 = sfx_load_sample(s_trooper_inPain_03_ogg_0047846c);
    sfx_trooper_die_01 = sfx_load_sample(s_trooper_die_01_ogg_00478458);
    sfx_trooper_die_02 = sfx_load_sample(s_trooper_die_02_ogg_00478444);
    sfx_trooper_die_03 = sfx_load_sample(s_trooper_die_03_ogg_00478430);
    sfx_zombie_die_01 = sfx_load_sample(s_zombie_die_01_ogg_0047841c);
    sfx_zombie_die_02 = sfx_load_sample(s_zombie_die_02_ogg_00478408);
    sfx_zombie_die_03 = sfx_load_sample(s_zombie_die_03_ogg_004783f4);
    sfx_zombie_die_04 = sfx_load_sample(s_zombie_die_04_ogg_004783e0);
    sfx_zombie_attack_01 = sfx_load_sample(s_zombie_attack_01_ogg_004783c8);
    sfx_zombie_attack_02 = sfx_load_sample(s_zombie_attack_02_ogg_004783b0);
    sfx_alien_die_01 = sfx_load_sample(s_alien_die_01_ogg_0047839c);
    sfx_alien_die_02 = sfx_load_sample(s_alien_die_02_ogg_00478388);
    sfx_alien_die_03 = sfx_load_sample(s_alien_die_03_ogg_00478374);
    sfx_alien_die_04 = sfx_load_sample(s_alien_die_04_ogg_00478360);
    sfx_alien_attack_01 = sfx_load_sample(s_alien_attack_01_ogg_0047834c);
    sfx_alien_attack_02 = sfx_load_sample(s_alien_attack_02_ogg_00478338);
    sfx_lizard_die_01 = sfx_load_sample(s_lizard_die_01_ogg_00478324);
    sfx_lizard_die_02 = sfx_load_sample(s_lizard_die_02_ogg_00478310);
    sfx_lizard_die_03 = sfx_load_sample(s_lizard_die_03_ogg_004782fc);
    sfx_lizard_die_04 = sfx_load_sample(s_lizard_die_04_ogg_004782e8);
    sfx_lizard_attack_01 = sfx_load_sample(s_lizard_attack_01_ogg_004782d0);
    sfx_lizard_attack_02 = sfx_load_sample(s_lizard_attack_02_ogg_004782b8);
    sfx_spider_die_01 = sfx_load_sample(s_spider_die_01_ogg_004782a4);
    sfx_spider_die_02 = sfx_load_sample(s_spider_die_02_ogg_00478290);
    sfx_spider_die_03 = sfx_load_sample(s_spider_die_03_ogg_0047827c);
    sfx_spider_die_04 = sfx_load_sample(s_spider_die_04_ogg_00478268);
    sfx_spider_attack_01 = sfx_load_sample(s_spider_attack_01_ogg_00478250);
    sfx_spider_attack_02 = sfx_load_sample(s_spider_attack_02_ogg_00478238);
    sfx_pistol_fire = sfx_load_sample(s_pistol_fire_ogg_00478228);
    sfx_pistol_reload = sfx_load_sample(s_pistol_reload_ogg_00478214);
    sfx_shotgun_fire = sfx_load_sample(s_shotgun_fire_ogg_00478200);
    sfx_shotgun_reload = sfx_load_sample(s_shotgun_reload_ogg_004781ec);
    sfx_autorifle_fire = sfx_load_sample(s_autorifle_fire_ogg_004781d8);
    sfx_autorifle_reload = sfx_load_sample(s_autorifle_reload_ogg_004781c0);
    sfx_gauss_fire = sfx_load_sample(s_gauss_fire_ogg_004781b0);
    sfx_hrpm_fire = sfx_load_sample(s_hrpm_fire_ogg_004781a0);
    sfx_shock_fire = sfx_load_sample(s_shock_fire_ogg_00478190);
    sfx_plasmaminigun_fire = sfx_load_sample(s_plasmaMinigun_fire_ogg_00478178);
    sfx_plasmashotgun_fire = sfx_load_sample(s_plasmaShotgun_fire_ogg_00478160);
    sfx_pulse_fire = sfx_load_sample(s_pulse_fire_ogg_00478150);
    sfx_flamer_fire_01 = sfx_load_sample(s_flamer_fire_01_ogg_0047813c);
    sfx_flamer_fire_02 = sfx_load_sample(s_flamer_fire_02_ogg_00478128);
    sfx_shock_reload = sfx_load_sample(s_shock_reload_ogg_00478114);
    sfx_shock_fire_alt = sfx_load_sample(s_shock_fire_ogg_00478190);
    sfx_shockminigun_fire = sfx_load_sample(s_shockMinigun_fire_ogg_004780fc);
    sfx_rocket_fire = sfx_load_sample(s_rocket_fire_ogg_004780ec);
    sfx_rocketmini_fire = sfx_load_sample(s_rocketmini_fire_ogg_004780d8);
    sfx_autorifle_reload_alt = sfx_load_sample(s_autorifle_reload_ogg_004781c0);
    sfx_bullet_hit_01 = sfx_load_sample(s_bullet_hit_01_ogg_004780c4);
    _sfx_bullet_hit_02 = sfx_load_sample(s_bullet_hit_02_ogg_004780b0);
    _sfx_bullet_hit_03 = sfx_load_sample(s_bullet_hit_03_ogg_0047809c);
    _sfx_bullet_hit_04 = sfx_load_sample(s_bullet_hit_04_ogg_00478088);
    _sfx_bullet_hit_05 = sfx_load_sample(s_bullet_hit_05_ogg_00478074);
    _sfx_bullet_hit_06 = sfx_load_sample(s_bullet_hit_06_ogg_00478060);
    sfx_shock_hit_01 = sfx_load_sample(s_shock_hit_01_ogg_0047804c);
    sfx_explosion_small = sfx_load_sample(s_explosion_small_ogg_00478038);
    sfx_explosion_medium = sfx_load_sample(s_explosion_medium_ogg_00478020);
    sfx_explosion_large = sfx_load_sample(s_explosion_large_ogg_0047800c);
    sfx_shockwave = sfx_load_sample(s_shockwave_ogg_00477ffc);
    sfx_questhit = sfx_load_sample(s_questHit_ogg_00477fec);
    sfx_ui_bonus = sfx_load_sample(s_ui_bonus_ogg_00477fdc);
    _sfx_trooper_inpain_01_alias_0 = sfx_trooper_inpain_01;
    sfx_trooper_inpain_01_alias_1 = sfx_trooper_inpain_01;
    _sfx_trooper_inpain_01_alias_2 = sfx_trooper_inpain_01;
    sfx_ui_buttonclick = sfx_load_sample(s_ui_buttonClick_ogg_00477fc8);
    sfx_ui_panelclick = sfx_load_sample(s_ui_panelClick_ogg_00477fb4);
    sfx_ui_levelup = sfx_load_sample(s_ui_levelUp_ogg_00477fa4);
    _sfx_ui_typeclick_01 = sfx_load_sample(s_ui_typeClick_01_ogg_00477f90);
    _sfx_ui_typeclick_02 = sfx_load_sample(s_ui_typeClick_02_ogg_00477f7c);
    sfx_ui_typeenter = sfx_load_sample(s_ui_typeEnter_ogg_00477f68);
    sfx_ui_clink_01 = sfx_load_sample(s_ui_clink_01_ogg_00477f58);
    sfx_bloodspill_01 = sfx_load_sample(s_bloodSpill_01_ogg_00477f44);
    _sfx_bloodspill_02 = sfx_load_sample(s_bloodSpill_02_ogg_00477f30);
    DVar3 = timeGetTime();
    iVar1 = 0;
    ppvVar4 = &sfx_entry_table.pcm_data;
    do {
      if (*ppvVar4 == (void *)0x0) break;
      ppvVar4 = ppvVar4 + 0x21;
      iVar1 = iVar1 + 1;
    } while ((int)ppvVar4 < 0x4cc6e4);
    console_printf(&console_log_queue,s__d_samples_loaded_to_sound_libra_00477ef8,iVar1,
                   (double)((float)(int)(DVar3 - DVar2) * 0.001));
  }
  return;
}



