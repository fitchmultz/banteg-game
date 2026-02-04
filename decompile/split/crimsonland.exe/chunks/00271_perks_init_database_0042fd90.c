/* perks_init_database @ 0042fd90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* builds the perk table (ids, names, descriptions) */

void __fastcall perks_init_database(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  void *in_ECX;
  void *this;
  void *this_00;
  void *this_01;
  void *this_02;
  void *this_03;
  char *this_04;
  void *this_05;
  void *this_06;
  void *this_07;
  void *this_08;
  void *this_09;
  void *this_10;
  void *this_11;
  void *this_12;
  void *this_13;
  void *this_14;
  void *this_15;
  void *this_16;
  void *this_17;
  void *this_18;
  void *this_19;
  void *this_20;
  void *this_21;
  void *this_22;
  void *this_23;
  void *this_24;
  void *this_25;
  void *this_26;
  void *this_27;
  void *this_28;
  void *this_29;
  void *this_30;
  void *this_31;
  void *this_32;
  void *this_33;
  void *this_34;
  void *this_35;
  void *this_36;
  void *this_37;
  void *this_38;
  void *this_39;
  void *this_40;
  void *this_41;
  void *this_42;
  void *this_43;
  void *this_44;
  void *this_45;
  void *this_46;
  void *this_47;
  void *this_48;
  void *this_49;
  void *this_50;
  void *this_51;
  void *this_52;
  void *this_53;
  void *this_54;
  void *this_55;
  void *this_56;
  void *this_57;
  void *this_58;
  void *this_59;
  void *this_60;
  void *this_61;
  void *this_62;
  void *this_63;
  void *this_64;
  void *this_65;
  void *this_66;
  void *this_67;
  void *this_68;
  void *this_69;
  void *this_70;
  void *this_71;
  void *this_72;
  void *this_73;
  void *this_74;
  void *this_75;
  void *this_76;
  void *this_77;
  void *this_78;
  void *this_79;
  void *this_80;
  void *this_81;
  void *this_82;
  void *this_83;
  void *this_84;
  void *this_85;
  void *this_86;
  void *this_87;
  void *this_88;
  void *this_89;
  void *this_90;
  void *this_91;
  void *this_92;
  void *this_93;
  void *this_94;
  void *this_95;
  void *this_96;
  void *this_97;
  void *this_98;
  void *this_99;
  void *this_x00100;
  void *this_x00101;
  void *this_x00102;
  void *this_x00103;
  void *this_x00104;
  void *this_x00105;
  void *this_x00106;
  void *this_x00107;
  void *this_x00108;
  void *this_x00109;
  void *this_x00110;
  void *this_x00111;
  void *this_x00112;
  void *this_x00113;
  
  perk_id_antiperk = 0;
  perk_meta_table.name = wrap_text_to_width_alloc(in_ECX,s_AntiPerk_00477728,0x100);
  perk_meta_table.description =
       wrap_text_to_width_alloc(this,s_You_shouldn_t_be_seeing_this___00477708,0x100);
  perk_id_bloody_mess_quick_learner = 1;
  DAT_004c3640 = wrap_text_to_width_alloc(this_00,s_Bloody_Mess_004776fc,0x100);
  DAT_004c3648 = wrap_text_to_width_alloc(this_01,s_More_the_merrier__More_blood_gua_00477684,0x100)
  ;
  DAT_004c3644 = wrap_text_to_width_alloc(this_02,s_Quick_Learner_00477674,0x100);
  pcVar3 = wrap_text_to_width_alloc(this_03,s_You_learn_things_faster_than_a_r_00477600,0x100);
  pcVar2 = DAT_004c3648;
  this_04 = DAT_004c3640;
  iVar1 = perk_id_bloody_mess_quick_learner;
  DAT_004c364c = pcVar3;
  if (config_blob.fx_toggle == '\0') {
    (&perk_meta_table)[perk_id_bloody_mess_quick_learner].name = DAT_004c3640;
    (&perk_meta_table)[iVar1].description = pcVar2;
  }
  else {
    this_04 = (char *)(perk_id_bloody_mess_quick_learner * 0x14);
    *(char **)(this_04 + 0x4c2c40) = DAT_004c3644;
    *(char **)(this_04 + 0x4c2c44) = pcVar3;
  }
  perk_id_sharpshooter = 2;
  _DAT_004c2c68 = wrap_text_to_width_alloc(this_04,s_Sharpshooter_004775f0,0x100);
  _DAT_004c2c6c =
       wrap_text_to_width_alloc(this_05,s_Miraculously_your_aiming_improve_00477538,0x100);
  perk_id_fastloader = 3;
  _DAT_004c2c7c = wrap_text_to_width_alloc(this_06,s_Fastloader_0047752c,0x100);
  _DAT_004c2c80 =
       wrap_text_to_width_alloc(this_07,s_Man__you_sure_know_how_to_load_a_00477504,0x100);
  perk_id_lean_mean_exp_machine = 4;
  _DAT_004c2c90 = wrap_text_to_width_alloc(this_08,s_Lean_Mean_Exp_Machine_004774ec,0x100);
  _DAT_004c2c94 =
       wrap_text_to_width_alloc(this_09,s_Why_kill_for_experience_when_you_0047745c,0x100);
  perk_id_long_distance_runner = 5;
  _DAT_004c2ca4 = wrap_text_to_width_alloc(this_10,s_Long_Distance_Runner_00477444,0x100);
  _DAT_004c2ca8 =
       wrap_text_to_width_alloc(this_11,s_You_move_like_a_train_that_has_f_004773a4,0x100);
  perk_id_pyrokinetic = 6;
  _DAT_004c2cb8 = wrap_text_to_width_alloc(this_12,s_Pyrokinetic_00477398,0x100);
  _DAT_004c2cbc =
       wrap_text_to_width_alloc(this_13,s_You_see_flames_everywhere__Bare_a_0047734c,0x100);
  perk_id_instant_winner = 7;
  _DAT_004c2ccc = wrap_text_to_width_alloc(this_14,s_Instant_Winner_0047733c,0x100);
  _DAT_004c2cd0 =
       wrap_text_to_width_alloc(this_15,s_2500_experience_points__Right_aw_00477300,0x100);
  DAT_004c2cd4 = (void *)((uint)DAT_004c2cd4 | 4);
  perk_id_grim_deal = 8;
  _DAT_004c2ce8 = 0;
  _DAT_004c2ce0 = wrap_text_to_width_alloc(DAT_004c2cd4,s_Grim_Deal_004772f4,0x100);
  _DAT_004c2ce4 =
       wrap_text_to_width_alloc(this_16,s_I_ll_make_you_a_deal__I_ll_give_y_00477258,0x100);
  perk_id_alternate_weapon = 9;
  _DAT_004c2cfc = 1;
  _DAT_004c2cf4 = wrap_text_to_width_alloc(this_17,s_Alternate_Weapon_00477244,0x100);
  _DAT_004c2cf8 =
       wrap_text_to_width_alloc(this_18,s_Ever_fancied_about_having_two_we_00477140,0x100);
  perk_id_plaguebearer = 10;
  _DAT_004c2d08 = wrap_text_to_width_alloc(this_19,s_Plaguebearer_00477130,0x100);
  _DAT_004c2d0c =
       wrap_text_to_width_alloc(this_20,s_You_carry_a_horrible_disease__Go_004770a4,0x100);
  perk_id_evil_eyes = 0xb;
  _DAT_004c2d1c = wrap_text_to_width_alloc(this_21,s_Evil_Eyes_00477098,0x100);
  _DAT_004c2d20 =
       wrap_text_to_width_alloc(this_22,s_No_living__nor_dead__can_resist_t_0047702c,0x100);
  perk_id_ammo_maniac = 0xc;
  _DAT_004c2d30 = wrap_text_to_width_alloc(this_23,s_Ammo_Maniac_00477020,0x100);
  _DAT_004c2d34 =
       wrap_text_to_width_alloc(this_24,s_You_squeeze_and_you_push_and_you_00476f80,0x100);
  perk_id_radioactive = 0xd;
  _DAT_004c2d44 = wrap_text_to_width_alloc(this_25,s_Radioactive_00476f74,0x100);
  _DAT_004c2d48 =
       wrap_text_to_width_alloc(this_26,s_You_are_the_Radioactive_man__you_00476eb0,0x100);
  perk_id_fastshot = 0xe;
  _DAT_004c2d58 = wrap_text_to_width_alloc(this_27,s_Fastshot_00476ea4,0x100);
  _DAT_004c2d5c =
       wrap_text_to_width_alloc(this_28,s_Funny_how_you_make_your_gun_spit_00476e28,0x100);
  perk_id_fatal_lottery = 0xf;
  _DAT_004c2d74 = 4;
  _DAT_004c2d6c = wrap_text_to_width_alloc(this_29,s_Fatal_Lottery_00476e18,0x100);
  _DAT_004c2d70 =
       wrap_text_to_width_alloc(this_30,s_Fifty_fifty_chance_of_dying_OR_g_00476db4,0x100);
  perk_id_random_weapon = 0x10;
  _DAT_004c2d88 = 5;
  _DAT_004c2d80 = wrap_text_to_width_alloc(this_31,s_Random_Weapon_00476da4,0x100);
  _DAT_004c2d84 =
       wrap_text_to_width_alloc(this_32,s_Here__have_this_weapon__No_quest_00476d78,0x100);
  perk_id_mr_melee = 0x11;
  _DAT_004c2d94 = wrap_text_to_width_alloc(this_33,s_Mr__Melee_00476d6c,0x100);
  _DAT_004c2d98 =
       wrap_text_to_width_alloc(this_34,s_You_master_the_art_of_melee_figh_00476cfc,0x100);
  perk_id_anxious_loader = 0x12;
  _DAT_004c2da8 = wrap_text_to_width_alloc(this_35,s_Anxious_Loader_00476cec,0x100);
  _DAT_004c2dac =
       wrap_text_to_width_alloc(this_36,s_When_you_can_t_stand_waiting_you_00476c5c,0x100);
  perk_id_final_revenge = 0x13;
  _DAT_004c2dc4 = 0;
  _DAT_004c2dbc = wrap_text_to_width_alloc(this_37,s_Final_Revenge_00476c4c,0x100);
  _DAT_004c2dc0 =
       wrap_text_to_width_alloc(this_38,s_Pick_this_and_you_ll_get_your_re_00476c14,0x100);
  perk_id_telekinetic = 0x14;
  _DAT_004c2dd0 = wrap_text_to_width_alloc(this_39,s_Telekinetic_00476c08,0x100);
  _DAT_004c2dd4 =
       wrap_text_to_width_alloc(this_40,s_Picking_up_bonuses_has_never_bee_00476b8c,0x100);
  perk_id_perk_expert = 0x15;
  _DAT_004c2de4 = wrap_text_to_width_alloc(this_41,s_Perk_Expert_00476b80,0x100);
  _DAT_004c2de8 =
       wrap_text_to_width_alloc(this_42,s_You_sure_know_how_to_pick_a_perk_00476acc,0x100);
  perk_id_unstoppable = 0x16;
  _DAT_004c2df8 = wrap_text_to_width_alloc(this_43,s_Unstoppable_00476ac0,0x100);
  _DAT_004c2dfc =
       wrap_text_to_width_alloc(this_44,s_Monsters_can_t_slow_you_down_wit_00476a4c,0x100);
  perk_id_regression_bullets = 0x17;
  _DAT_004c2e0c = wrap_text_to_width_alloc(this_45,s_Regression_Bullets_00476a38,0x100);
  _DAT_004c2e10 =
       wrap_text_to_width_alloc(this_46,s_Attempt_to_shoot_with_an_empty_c_004769c0,0x100);
  perk_id_infernal_contract = 0x18;
  _DAT_004c2e20 = wrap_text_to_width_alloc(this_47,s_Infernal_Contract_004769ac,0x100);
  _DAT_004c2e24 =
       wrap_text_to_width_alloc(this_48,s_In_exchange_for_your_soul__a_dar_004768d0,0x100);
  perk_id_poison_bullets = 0x19;
  _DAT_004c2e34 = wrap_text_to_width_alloc(this_49,s_Poison_Bullets_004768c0,0x100);
  _DAT_004c2e38 =
       wrap_text_to_width_alloc(this_50,s_You_tend_to_explicitly_treat_eac_00476834,0x100);
  perk_id_dodger = (void *)0x1a;
  _DAT_004c2e48 = wrap_text_to_width_alloc(this_51,s_Dodger_0047682c,0x100);
  _DAT_004c2e4c =
       wrap_text_to_width_alloc(this_52,s_It_seems_so_stupid_just_to_take_t_004767b8,0x100);
  perk_id_bonus_magnet = 0x1b;
  _DAT_004c2e5c = wrap_text_to_width_alloc(this_53,s_Bonus_Magnet_004767a8,0x100);
  _DAT_004c2e60 =
       wrap_text_to_width_alloc(this_54,s_You_somehow_seem_to_lure_all_kin_00476758,0x100);
  perk_id_uranium_filled_bullets = 0x1c;
  _DAT_004c2e70 = wrap_text_to_width_alloc(this_55,s_Uranium_Filled_Bullets_00476740,0x100);
  _DAT_004c2e74 =
       wrap_text_to_width_alloc(this_56,s_Your_bullets_have_a_nice_creamy_u_004766d8,0x100);
  perk_id_doctor = 0x1d;
  _DAT_004c2e84 = wrap_text_to_width_alloc(this_57,s_Doctor_004766d0,0x100);
  _DAT_004c2e88 =
       wrap_text_to_width_alloc(this_58,s_With_a_single_glance_you_can_tel_0047660c,0x100);
  perk_id_monster_vision = 0x1e;
  _DAT_004c2e98 = wrap_text_to_width_alloc(this_59,s_Monster_Vision_004765fc,0x100);
  _DAT_004c2e9c =
       wrap_text_to_width_alloc(this_60,s_With_your_newly_enhanced_senses_y_00476598,0x100);
  perk_id_hot_tempered = 0x1f;
  _DAT_004c2eac = wrap_text_to_width_alloc(this_61,s_Hot_Tempered_00476588,0x100);
  _DAT_004c2eb0 =
       wrap_text_to_width_alloc(this_62,s_It_literally_boils_inside_you__T_0047650c,0x100);
  perk_id_bonus_economist = 0x20;
  _DAT_004c2ec0 = wrap_text_to_width_alloc(this_63,s_Bonus_Economist_004764fc,0x100);
  _DAT_004c2ec4 =
       wrap_text_to_width_alloc(this_64,s_Your_bonus_power_ups_last_50__lo_004764bc,0x100);
  DAT_004c2bcc = 0;
  perk_id_thick_skinned = 0x21;
  _DAT_004c2ed4 = wrap_text_to_width_alloc(this_65,s_Thick_Skinned_004764ac,0x100);
  _DAT_004c2ed8 =
       wrap_text_to_width_alloc(this_66,s_Trade_1_3_of_your_health_for_onl_00476464,0x100);
  perk_id_barrel_greaser = 0x22;
  _DAT_004c2ee8 = wrap_text_to_width_alloc(this_67,s_Barrel_Greaser_00476454,0x100);
  _DAT_004c2eec =
       wrap_text_to_width_alloc(this_68,s_After_studying_a_lot_of_physics_a_004763d0,0x100);
  perk_id_ammunition_within = 0x23;
  _DAT_004c2efc = wrap_text_to_width_alloc(this_69,s_Ammunition_Within_004763bc,0x100);
  _DAT_004c2f00 =
       wrap_text_to_width_alloc(this_70,s_Empty_clip_doesn_t_prevent_you_f_00476334,0x100);
  perk_id_veins_of_poison = 0x24;
  _DAT_004c2f10 = wrap_text_to_width_alloc(this_71,s_Veins_of_Poison_00476324,0x100);
  _DAT_004c2f14 =
       wrap_text_to_width_alloc(this_72,s_A_strong_poison_runs_through_you_004762ac,0x100);
  perk_id_toxic_avenger = 0x25;
  _DAT_004c2f24 = wrap_text_to_width_alloc(this_73,s_Toxic_Avenger_0047629c,0x100);
  _DAT_004c2f28 =
       wrap_text_to_width_alloc(this_74,s_You_started_out_just_by_being_po_004761dc,0x100);
  perk_id_regeneration = 0x26;
  _DAT_004c2f34 = perk_id_veins_of_poison;
  _DAT_004c2f38 = wrap_text_to_width_alloc(this_75,s_Regeneration_004761cc,0x100);
  _DAT_004c2f3c =
       wrap_text_to_width_alloc(this_76,s_Your_health_replenishes_but_very_00476188,0x100);
  perk_id_pyromaniac = 0x27;
  _DAT_004c2f4c = wrap_text_to_width_alloc(this_77,s_Pyromaniac_0047617c,0x100);
  _DAT_004c2f50 =
       wrap_text_to_width_alloc(this_78,s_You_just_enjoy_using_fire_as_you_004760fc,0x100);
  perk_id_ninja = 0x28;
  _DAT_004c2f60 = wrap_text_to_width_alloc(this_79,s_Ninja_004760f4,0x100);
  _DAT_004c2f64 =
       wrap_text_to_width_alloc(this_80,s_You_ve_taken_your_dodging_abilit_00476090,0x100);
  _DAT_004c2f70 = perk_id_dodger;
  perk_id_highlander = 0x29;
  _DAT_004c2f7c = 0;
  _DAT_004c2f74 = wrap_text_to_width_alloc(perk_id_dodger,s_Highlander_00476084,0x100);
  _DAT_004c2f78 =
       wrap_text_to_width_alloc(this_81,s_You_are_immortal__Well__almost_i_00475fb8,0x100);
  perk_id_jinxed = 0x2a;
  _DAT_004c2f88 = wrap_text_to_width_alloc(this_82,s_Jinxed_00475fb0,0x100);
  _DAT_004c2f8c =
       wrap_text_to_width_alloc(this_83,s_Things_happen_near_you__Stranges_00475f4c,0x100);
  perk_id_perk_master = 0x2b;
  _DAT_004c2f9c = wrap_text_to_width_alloc(this_84,s_Perk_Master_00475f40,0x100);
  _DAT_004c2fa0 =
       wrap_text_to_width_alloc(this_85,s_Being_the_Perk_Expert_taught_you_00475eb4,0x100);
  _DAT_004c2fac = perk_id_perk_expert;
  perk_id_reflex_boosted = 0x2c;
  _DAT_004c2fb0 = wrap_text_to_width_alloc(this_86,s_Reflex_Boosted_00475ea4,0x100);
  _DAT_004c2fb4 =
       wrap_text_to_width_alloc(this_87,s_To_you_the_world_seems_to_go_on_a_00475e00,0x100);
  perk_id_greater_regeneration = 0x2d;
  _DAT_004c2fc4 = wrap_text_to_width_alloc(this_88,s_Greater_Regeneration_00475de8,0x100);
  _DAT_004c2fc8 =
       wrap_text_to_width_alloc(this_89,s_Your_health_replenishes_faster_t_00475dbc,0x100);
  perk_id_breathing_room = 0x2e;
  _DAT_004c2fd4 = perk_id_regeneration;
  _DAT_004c2fe0 = 2;
  _DAT_004c2fd8 = wrap_text_to_width_alloc(this_90,s_Breathing_Room_00475dac,0x100);
  _DAT_004c2fdc =
       wrap_text_to_width_alloc(this_91,s_Trade_2_3rds_of_your_health_for_t_00475d34,0x100);
  perk_id_death_clock = 0x2f;
  _DAT_004c2fec = wrap_text_to_width_alloc(this_92,s_Death_Clock_00475d28,0x100);
  _DAT_004c2ff0 =
       wrap_text_to_width_alloc(this_93,s_You_die_exactly_in_30_seconds__Y_00475cbc,0x100);
  perk_id_my_favourite_weapon = 0x30;
  _DAT_004c3000 = wrap_text_to_width_alloc(this_94,s_My_Favourite_Weapon_00475ca8,0x100);
  _DAT_004c3004 =
       wrap_text_to_width_alloc(this_95,s_You_ve_grown_very_fond_of_your_p_00475c14,0x100);
  perk_id_bandage = 0x31;
  _DAT_004c3014 = wrap_text_to_width_alloc(this_96,s_Bandage_00475c0c,0x100);
  _DAT_004c3018 =
       wrap_text_to_width_alloc(this_97,s_Here__eat_this_bandage_and_you_l_00475bb0,0x100);
  perk_id_angry_reloader = 0x32;
  _DAT_004c3028 = wrap_text_to_width_alloc(this_98,s_Angry_Reloader_00475ba0,0x100);
  _DAT_004c302c =
       wrap_text_to_width_alloc(this_99,s_You_hate_it_when_you_run_out_of_s_00475ab4,0x100);
  perk_id_ion_gun_master = 0x33;
  _DAT_004c303c = wrap_text_to_width_alloc(this_x00100,s_Ion_Gun_Master_00475aa4,0x100);
  _DAT_004c3040 =
       wrap_text_to_width_alloc(this_x00101,s_You_re_good_with_ion_weapons__Yo_00475a18,0x100);
  perk_id_stationary_reloader = 0x34;
  _DAT_004c3050 = wrap_text_to_width_alloc(this_x00102,s_Stationary_Reloader_00475a04,0x100);
  _DAT_004c3054 =
       wrap_text_to_width_alloc(this_x00103,s_It_s_incredibly_hard_to_reload_y_0047594c,0x100);
  perk_id_man_bomb = 0x35;
  _DAT_004c3064 = wrap_text_to_width_alloc(this_x00104,s_Man_Bomb_00475940,0x100);
  _DAT_004c3068 =
       wrap_text_to_width_alloc(this_x00105,s_You_have_the_ability_to_go_boom_f_004758a8,0x100);
  perk_id_fire_caugh = 0x36;
  _DAT_004c3078 = wrap_text_to_width_alloc(this_x00106,s_Fire_Caugh_0047589c,0x100);
  _DAT_004c307c =
       wrap_text_to_width_alloc(this_x00107,s_You_have_a_fireball_stuck_in_you_00475850,0x100);
  perk_id_living_fortress = 0x37;
  _DAT_004c308c = wrap_text_to_width_alloc(this_x00108,s_Living_Fortress_00475840,0x100);
  _DAT_004c3090 =
       wrap_text_to_width_alloc(this_x00109,s_It_comes_a_time_in_each_man_s_li_0047577c,0x100);
  perk_id_tough_reloader = 0x38;
  _DAT_004c30a0 = wrap_text_to_width_alloc(this_x00110,s_Tough_Reloader_0047576c,0x100);
  _DAT_004c30a4 =
       wrap_text_to_width_alloc(this_x00111,s_Damage_received_during_reloading_00475734,0x100);
  perk_id_lifeline_50_50 = 0x39;
  _DAT_004c30b4 = wrap_text_to_width_alloc(this_x00112,s_Lifeline_50_50_00475724,0x100);
  _DAT_004c30b8 =
       wrap_text_to_width_alloc(this_x00113,s_The_computer_removes_half_of_the_004756cc,0x100);
  DAT_004c2c38 = 0x39;
  DAT_004c2b8c = 0x3a;
  perks_rebuild_available();
  return;
}



