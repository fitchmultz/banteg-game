/* bonus_metadata_init @ 00412660 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* builds bonus metadata table (labels, descriptions, durations) */

void bonus_metadata_init(void)

{
  void *this;
  void *this_00;
  void *this_01;
  void *this_02;
  void *this_03;
  void *this_04;
  void *this_05;
  void *this_06;
  void *this_07;
  void *this_08;
  void *this_09;
  void *this_10;
  void *this_11;
  void *this_12;
  
  DAT_004853e4 = strdup_malloc(s_Points_00473604);
  _DAT_004853e8 = wrap_text_to_width_alloc(this,s_You_gain_some_experience_points__004735e0,0x100);
  _DAT_004853ec = 0xc;
  _DAT_004853f4 = 500;
  DAT_004853f0 = 1;
  _DAT_0048540c = strdup_malloc(s_Weapon_004735d8);
  _DAT_00485410 = wrap_text_to_width_alloc(this_00,s_You_get_a_new_weapon__004735c0,0x100);
  _DAT_00485414 = 0xffffffff;
  _DAT_0048541c = 3;
  _DAT_00485434 = strdup_malloc(&DAT_004735b8);
  _DAT_00485438 =
       wrap_text_to_width_alloc(this_01,s_An_amazing_explosion_of_ATOMIC_p_00473590,0x100);
  _DAT_0048543c = 1;
  DAT_00485448 = strdup_malloc(s_Double_Experience_0047357c);
  _DAT_0048544c =
       wrap_text_to_width_alloc(this_02,s_Every_experience_point_you_get_i_00473534,0x100);
  DAT_00485450 = 4;
  _DAT_00485470 = strdup_malloc(s_Fireblast_00473528);
  _DAT_00485474 = wrap_text_to_width_alloc(this_03,s_Fireballs_all_over_the_place__00473508,0x100);
  _DAT_00485478 = 2;
  _DAT_0048545c = strdup_malloc(s_Shock_Chain_004734fc);
  _DAT_00485460 =
       wrap_text_to_width_alloc(this_04,s_Chain_of_shocks_shock_the_crowd__004734d8,0x100);
  _DAT_00485464 = 3;
  DAT_00485484 = strdup_malloc(s_Reflex_Boost_004734c8);
  _DAT_00485488 =
       wrap_text_to_width_alloc(this_05,s_You_get_more_time_to_react_as_th_00473494,0x100);
  DAT_0048548c = 5;
  _DAT_00485494 = 3;
  DAT_00485498 = strdup_malloc(s_Shield_0047348c);
  _DAT_0048549c =
       wrap_text_to_width_alloc(this_06,s_Force_field_protects_you_for_a_w_00473464,0x100);
  DAT_004854a0 = 6;
  _DAT_004854a8 = 7;
  DAT_004854ac = strdup_malloc(s_Freeze_0047345c);
  _DAT_004854b0 = wrap_text_to_width_alloc(this_07,s_Monsters_are_frozen__00473444,0x100);
  DAT_004854b4 = 8;
  _DAT_004854bc = 5;
  DAT_004854d4 = strdup_malloc(s_Speed_0047343c);
  _DAT_004854d8 =
       wrap_text_to_width_alloc(this_08,s_Your_movement_speed_increases_fo_00473410,0x100);
  DAT_004854dc = 9;
  _DAT_004854e4 = 8;
  DAT_004853f8 = strdup_malloc(s_Energizer_00473404);
  _DAT_004853fc =
       wrap_text_to_width_alloc(this_09,s_Suddenly_monsters_run_away_from_y_004733c8,0x100);
  DAT_00485400 = 10;
  _DAT_00485408 = 8;
  DAT_00485420 = strdup_malloc(s_Weapon_Power_Up_004733b8);
  _DAT_00485424 =
       wrap_text_to_width_alloc(this_10,s_Your_firerate_and_load_time_incr_0047337c,0x100);
  DAT_00485428 = 7;
  _DAT_00485430 = 10;
  DAT_004854e8 = strdup_malloc(s_Fire_Bullets_0047336c);
  _DAT_004854ec =
       wrap_text_to_width_alloc(this_11,s_For_few_seconds____make_them_cou_00473348,0x100);
  DAT_004854f0 = 0xb;
  _DAT_004854f8 = 4;
  _DAT_004854c0 = strdup_malloc(s_MediKit_00473340);
  _DAT_004854c4 =
       wrap_text_to_width_alloc(this_12,s__You_regain_some_of_your_health__0047331b + 1,0x100);
  _DAT_004854d0 = 10;
  _DAT_004854c8 = 0xe;
  return;
}



