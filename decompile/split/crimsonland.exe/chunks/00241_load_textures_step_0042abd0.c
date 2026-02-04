/* load_textures_step @ 0042abd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* stage-based texture loading (advances DAT_004aaf88) */

int load_textures_step(void)

{
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  int iVar3;
  int iVar4;
  char *unaff_retaddr;
  char *pcVar1;
  char *pcVar2;
  
  if (startup_texture_load_stage == 0) {
    texture_get_or_load(s_GRIM_Font2_004745d8,s_load_smallWhite_tga_004745e4);
    texture_get_or_load(s_trooper_0047372c,s_game_trooper_jaz_004745c4);
    texture_get_or_load(s_zombie_0047375c,s_game_zombie_jaz_004745b4);
    texture_get_or_load(s_spider_sp1_00473748,s_game_spider_sp1_jaz_004745a0);
    texture_get_or_load(s_spider_sp2_0047373c,s_game_spider_sp2_jaz_0047458c);
    texture_get_or_load(s_alien_00473734,s_game_alien_jaz_0047457c);
    texture_get_or_load(s_lizard_00473754,s_game_lizard_jaz_0047456c);
    in_EDX = extraout_EDX;
  }
  if (startup_texture_load_stage == 1) {
    DAT_0048f7d8 = texture_get_or_load(s_arrow_00474554,s_load_arrow_tga_0047455c);
    texture_get_or_load(s_bullet_i_00474534,s_load_bullet16_tga_00474540);
    bullet_trail_texture =
         texture_get_or_load(s_bulletTrail_00474510,s_load_bulletTrail_tga_0047451c);
    texture_get_or_load(s_bodyset_004744f4,s_game_bodyset_jaz_004744fc);
    bodyset_texture = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_bodyset_004744f4);
    projectile_texture = texture_get_or_load(s_projs_004744dc,s_game_projs_jaz_004744e4);
    in_EDX = extraout_EDX_00;
  }
  if (startup_texture_load_stage == 2) {
    texture_get_or_load(s_ui_iconAim_004744bc,s_ui_ui_iconAim_jaz_004744c8);
    texture_get_or_load(s_ui_buttonSm_00474498,s_ui_ui_button_64x32_jaz_004744a4);
    texture_get_or_load(s_ui_buttonMd_00474474,s_ui_ui_button_128x32_jaz_00474480);
    texture_get_or_load(s_ui_checkOn_00474454,s_ui_ui_checkOn_jaz_00474460);
    texture_get_or_load(s_ui_checkOff_00474434,s_ui_ui_checkOff_jaz_00474440);
    texture_get_or_load(s_ui_rectOff_00474414,s_ui_ui_rectOff_jaz_00474420);
    texture_get_or_load(s_ui_rectOn_004743f4,s_ui_ui_rectOn_jaz_00474400);
    texture_get_or_load(s_bonuses_004743d8,s_game_bonuses_jaz_004743e0);
    in_EDX = extraout_EDX_01;
  }
  if (startup_texture_load_stage == 3) {
    pcVar2 = s_ui_ui_indBullet_jaz_00473864;
    texture_get_or_load_alt(s_ui_ui_indBullet_jaz_00473864,unaff_retaddr);
    pcVar1 = s_ui_ui_indRocket_jaz_00473850;
    texture_get_or_load_alt(s_ui_ui_indRocket_jaz_00473850,pcVar2);
    pcVar2 = s_ui_ui_indElectric_jaz_00473838;
    texture_get_or_load_alt(s_ui_ui_indElectric_jaz_00473838,pcVar1);
    texture_get_or_load_alt(s_ui_ui_indFire_jaz_00473878,pcVar2);
    bonus_texture = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_bonuses_004743d8);
    particles_texture = texture_get_or_load_alt(s_game_particles_jaz_004743c4,unaff_retaddr);
    in_EDX = extraout_EDX_02;
  }
  if (startup_texture_load_stage == 4) {
    pcVar1 = s_ui_ui_indLife_jaz_004743b0;
    DAT_0048f7c0 = texture_get_or_load_alt(s_ui_ui_indLife_jaz_004743b0,unaff_retaddr);
    pcVar2 = s_ui_ui_indPanel_jaz_0047439c;
    DAT_0048f7c4 = texture_get_or_load_alt(s_ui_ui_indPanel_jaz_0047439c,pcVar1);
    pcVar1 = s_ui_ui_arrow_jaz_0047438c;
    DAT_0048f7bc = texture_get_or_load_alt(s_ui_ui_arrow_jaz_0047438c,pcVar2);
    pcVar2 = s_ui_ui_cursor_jaz_00474378;
    DAT_0048f798 = texture_get_or_load_alt(s_ui_ui_cursor_jaz_00474378,pcVar1);
    DAT_0048f79c = texture_get_or_load_alt(s_ui_ui_aim_jaz_00474368,pcVar2);
    in_EDX = extraout_EDX_03;
  }
  if (startup_texture_load_stage == 5) {
    if (terrain_texture_failed == '\0') {
      pcVar2 = s_ter_ter_q1_base_jaz_00474354;
      terrain_texture_handles =
           texture_get_or_load_alt(s_ter_ter_q1_base_jaz_00474354,unaff_retaddr);
      pcVar1 = s_ter_ter_q1_tex1_jaz_00474340;
      DAT_0048f54c = texture_get_or_load_alt(s_ter_ter_q1_tex1_jaz_00474340,pcVar2);
      pcVar2 = s_ter_ter_q2_base_jaz_0047432c;
      _DAT_0048f550 = texture_get_or_load_alt(s_ter_ter_q2_base_jaz_0047432c,pcVar1);
      pcVar1 = s_ter_ter_q2_tex1_jaz_00474318;
      _DAT_0048f554 = texture_get_or_load_alt(s_ter_ter_q2_tex1_jaz_00474318,pcVar2);
      pcVar2 = s_ter_ter_q3_base_jaz_00474304;
      _DAT_0048f558 = texture_get_or_load_alt(s_ter_ter_q3_base_jaz_00474304,pcVar1);
      pcVar1 = s_ter_ter_q3_tex1_jaz_004742f0;
      _DAT_0048f55c = texture_get_or_load_alt(s_ter_ter_q3_tex1_jaz_004742f0,pcVar2);
      pcVar2 = s_ter_ter_q4_base_jaz_004742dc;
      _DAT_0048f560 = texture_get_or_load_alt(s_ter_ter_q4_base_jaz_004742dc,pcVar1);
      _DAT_0048f564 = texture_get_or_load_alt(s_ter_ter_q4_tex1_jaz_004742c8,pcVar2);
      in_EDX = extraout_EDX_04;
    }
    else {
      pcVar2 = s_ter_fb_q1_jaz_004742b8;
      terrain_texture_handles = texture_get_or_load_alt(s_ter_fb_q1_jaz_004742b8,unaff_retaddr);
      pcVar1 = s_ter_fb_q2_jaz_004742a8;
      DAT_0048f54c = texture_get_or_load_alt(s_ter_fb_q2_jaz_004742a8,pcVar2);
      pcVar2 = s_ter_fb_q3_jaz_00474298;
      _DAT_0048f550 = texture_get_or_load_alt(s_ter_fb_q3_jaz_00474298,pcVar1);
      _DAT_0048f554 = texture_get_or_load_alt(s_ter_fb_q4_jaz_00474288,pcVar2);
      terrain_render_target = terrain_texture_handles;
      in_EDX = extraout_EDX_05;
    }
  }
  if (startup_texture_load_stage == 6) {
    pcVar1 = s_ui_ui_textLevComp_jaz_00474270;
    DAT_0048f7a0 = texture_get_or_load_alt(s_ui_ui_textLevComp_jaz_00474270,unaff_retaddr);
    pcVar2 = s_ui_ui_textQuest_jaz_0047425c;
    DAT_0048f7a4 = texture_get_or_load_alt(s_ui_ui_textQuest_jaz_0047425c,pcVar1);
    pcVar1 = s_ui_ui_num1_jaz_0047424c;
    DAT_0048f7a8 = texture_get_or_load_alt(s_ui_ui_num1_jaz_0047424c,pcVar2);
    pcVar2 = s_ui_ui_num2_jaz_0047423c;
    DAT_0048f7ac = texture_get_or_load_alt(s_ui_ui_num2_jaz_0047423c,pcVar1);
    pcVar1 = s_ui_ui_num3_jaz_0047422c;
    _DAT_0048f7b0 = texture_get_or_load_alt(s_ui_ui_num3_jaz_0047422c,pcVar2);
    pcVar2 = s_ui_ui_num4_jaz_0047421c;
    DAT_0048f7b4 = texture_get_or_load_alt(s_ui_ui_num4_jaz_0047421c,pcVar1);
    _DAT_0048f7b8 = texture_get_or_load_alt(s_ui_ui_num5_jaz_0047420c,pcVar2);
    in_EDX = extraout_EDX_06;
  }
  if (startup_texture_load_stage == 7) {
    ui_weapon_icons_texture = texture_get_or_load(s_ui_wicons_004741ec,s_ui_ui_wicons_jaz_004741f8);
    texture_get_or_load(s_iGameUI_00473894,s_ui_ui_gameTop_jaz_004741d8);
    pcVar1 = s_iHeart_0047388c;
    texture_get_or_load(s_iHeart_0047388c,s_ui_ui_lifeHeart_jaz_004741c4);
    pcVar2 = s_ui_ui_clockTable_jaz_004741ac;
    ui_clock_table_texture = texture_get_or_load_alt(s_ui_ui_clockTable_jaz_004741ac,pcVar1);
    DAT_0048f7cc = texture_get_or_load_alt(s_ui_ui_clockPointer_jaz_00474194,pcVar2);
    in_EDX = extraout_EDX_07;
  }
  _iVar3 = CONCAT44(in_EDX,terrain_render_target);
  if (startup_texture_load_stage == 8) {
    DAT_0048f7e0 = texture_get_or_load_alt(s_game_muzzleFlash_jaz_0047417c,unaff_retaddr);
    texture_get_or_load(s_ui_dropOn_00474158,s_ui_ui_dropDownOn_jaz_00474164);
    texture_get_or_load(s_ui_dropOff_00474134,s_ui_ui_dropDownOff_jaz_00474140);
    _iVar3 = CONCAT44(extraout_EDX_08,terrain_render_target);
    if (terrain_texture_failed == '\0') {
      _iVar3 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_ground_004740c4);
    }
  }
  terrain_render_target = (int)_iVar3;
  if (startup_texture_load_stage == 9) {
    game_state_id = 0;
    DAT_0049bb30 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_bullet_i_00474534);
    _iVar4 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_aim64_0047412c);
    _iVar3 = CONCAT44((int)((ulonglong)_iVar4 >> 0x20),terrain_render_target);
    _DAT_00496698 = (int)_iVar4;
    DAT_004aaf86 = 1;
  }
  terrain_render_target = (int)_iVar3;
  startup_texture_load_stage = startup_texture_load_stage + 1;
  DAT_00473a5c = 0xb;
  console_flush_log(&console_log_queue,(char *)((ulonglong)_iVar3 >> 0x20));
  return (uint)(10 < startup_texture_load_stage);
}



