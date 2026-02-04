/* quest_database_init @ 00439230 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* builds the quest metadata table and registers quest builders */

void quest_database_init(void)

{
  int local_8;
  int local_4;
  
  local_8 = 0;
  local_4 = 0;
  quest_meta_init_entry(&quest_selected_meta,1,1,s_Land_Hostile_00477adc);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 120000;
  quest_meta_cursor->builder = quest_build_land_hostile;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Minor_Alien_Breach_00477ac8);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 120000;
  quest_meta_cursor->builder = quest_build_minor_alien_breach;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Target_Practice_00477ab8);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 65000;
  quest_meta_cursor->builder = quest_build_target_practice;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Frontline_Assault_00477aa4);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_frontline_assault;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Alien_Dens_00477a98);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 180000;
  quest_meta_cursor->builder = quest_build_alien_dens;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Random_Factor_00477a84);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_the_random_factor;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Spider_Wave_Syndrome_00477a6c);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 240000;
  quest_meta_cursor->builder = quest_build_spider_wave_syndrome;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Alien_Squads_00477a5c);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 180000;
  quest_meta_cursor->builder = quest_build_alien_squads;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Nesting_Grounds_00477a4c);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 240000;
  quest_meta_cursor->builder = quest_build_nesting_grounds;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_8_legged_Terror_00477a3c);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 240000;
  quest_meta_cursor->builder = quest_build_8_legged_terror;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Everred_Pastures_00477a28);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_everred_pastures;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Spider_Spawns_00477a18);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_spider_spawns;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Arachnoid_Farm_00477a08);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 240000;
  quest_meta_cursor->builder = quest_build_arachnoid_farm;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Two_Fronts_004779fc);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 240000;
  quest_meta_cursor->builder = quest_build_two_fronts;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Sweep_Stakes_004779ec);
  quest_meta_cursor->start_weapon_id = 6;
  quest_meta_cursor->time_limit_ms = 35000;
  quest_meta_cursor->builder = quest_build_sweep_stakes;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Evil_Zombies_At_Large_004779d4);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 180000;
  quest_meta_cursor->builder = quest_build_evil_zombies_at_large;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Survival_Of_The_Fastest_004779bc);
  quest_meta_cursor->start_weapon_id = 5;
  quest_meta_cursor->time_limit_ms = 120000;
  quest_meta_cursor->builder = quest_build_survival_of_the_fastest;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Land_Of_Lizards_004779ac);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 180000;
  quest_meta_cursor->builder = quest_build_land_of_lizards;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Ghost_Patrols_0047799c);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 180000;
  quest_meta_cursor->builder = quest_build_ghost_patrols;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Spideroids_00477990);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 360000;
  quest_meta_cursor->builder = quest_build_spideroids;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Blighting_00477980);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_the_blighting;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Lizard_Kings_00477970);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 180000;
  quest_meta_cursor->builder = quest_build_lizard_kings;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Killing_00477964);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_the_killing;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Hidden_Evil_00477958);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_hidden_evil;
  quest_monster_vision_meta = quest_meta_cursor;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Surrounded_By_Reptiles_00477940);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_surrounded_by_reptiles;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Lizquidation_0047792c);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_the_lizquidation;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Spiders_Inc__0047791c);
  quest_meta_cursor->start_weapon_id = 0xb;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_spiders_inc;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Lizard_Raze_00477910);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_lizard_raze;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Deja_vu_00477908);
  quest_meta_cursor->start_weapon_id = 6;
  quest_meta_cursor->time_limit_ms = 120000;
  quest_meta_cursor->builder = quest_build_deja_vu;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Zombie_Masters_004778f8);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_zombie_masters;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Major_Alien_Breach_004778e4);
  quest_meta_cursor->start_weapon_id = 0x12;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_major_alien_breach;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Zombie_Time_004778d8);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_zombie_time;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Lizard_Zombie_Pact_004778c4);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_lizard_zombie_pact;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Collaboration_004778b0);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 360000;
  quest_meta_cursor->builder = quest_build_the_collaboration;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Massacre_004778a0);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_the_massacre;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Unblitzkrieg_0047788c);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 600000;
  quest_meta_cursor->builder = quest_build_the_unblitzkrieg;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Gauntlet_00477880);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_gauntlet;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Syntax_Terror_00477870);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_syntax_terror;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Annihilation_0047785c);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 300000;
  quest_meta_cursor->builder = quest_build_the_annihilation;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_End_of_All_0047784c);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_the_end_of_all;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Beating_00477840);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_the_beating;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Spanking_Of_The_Dead_00477824);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_the_spanking_of_the_dead;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Fortress_00477814);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_the_fortress;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Gang_Wars_00477804);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_the_gang_wars;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Knee_deep_in_the_Dead_004777ec);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_knee_deep_in_the_dead;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Cross_Fire_004777e0);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_cross_fire;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Army_of_Three_004777d0);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_army_of_three;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Monster_Blues_004777c0);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_monster_blues;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_Nagolipoli_004777b4);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_nagolipoli;
  quest_database_advance_slot(&local_4,&local_8);
  quest_meta_init_entry
            (&quest_selected_meta + local_8 + local_4 * 10,local_4 + 1,local_8 + 1,
             s_The_Gathering_004777a4);
  quest_meta_cursor->start_weapon_id = 1;
  quest_meta_cursor->time_limit_ms = 480000;
  quest_meta_cursor->builder = quest_build_the_gathering;
  quest_database_advance_slot(&local_4,&local_8);
  quest_selected_meta.unlock_weapon_id = 2;
  DAT_00484780 = 3;
  _DAT_004847ac = 0;
  _DAT_004847d8 = 8;
  _DAT_00484804 = 0;
  _DAT_00484830 = 5;
  _DAT_0048485c = 0;
  _DAT_00484888 = 6;
  _DAT_004848b4 = 0;
  _DAT_004848e0 = 0xc;
  _DAT_0048490c = 0;
  _DAT_00484938 = 9;
  _DAT_00484964 = 0;
  _DAT_00484990 = 0x15;
  _DAT_004849bc = 0;
  _DAT_004849e8 = 7;
  _DAT_00484a14 = 0;
  _DAT_00484a40 = 4;
  _DAT_00484a6c = 0;
  _DAT_00484a98 = 0xb;
  _DAT_00484ac4 = 0;
  _DAT_00484af0 = 10;
  _DAT_00484b1c = 0;
  _DAT_00484b48 = 0xd;
  _DAT_00484b74 = 0;
  _DAT_00484ba0 = 0xf;
  _DAT_00484bcc = 0;
  _DAT_00484bf8 = 0x12;
  _DAT_00484c24 = 0;
  _DAT_00484c50 = 0x14;
  _DAT_00484c7c = 0;
  _DAT_00484ca8 = 0x13;
  _DAT_00484cd4 = 0;
  _DAT_00484d00 = 0xe;
  _DAT_00484d2c = 0;
  _DAT_00484d58 = 0x11;
  _DAT_00484d84 = 0;
  _DAT_00484db0 = 0x16;
  _DAT_00484ddc = 0;
  _DAT_00484e08 = 0x17;
  quest_selected_meta.unlock_perk_id = perk_id_antiperk;
  DAT_0048477c = perk_id_antiperk;
  _DAT_004847a8 = 0x1c;
  _DAT_004847d4 = perk_id_antiperk;
  _DAT_00484800 = 0x1d;
  _DAT_0048482c = perk_id_antiperk;
  _DAT_00484858 = 0x1e;
  _DAT_00484884 = perk_id_antiperk;
  _DAT_004848b0 = 0x1f;
  _DAT_004848dc = perk_id_antiperk;
  _DAT_00484908 = 0x20;
  _DAT_00484934 = perk_id_antiperk;
  _DAT_00484960 = 0x21;
  _DAT_0048498c = perk_id_antiperk;
  _DAT_004849b8 = 0x22;
  _DAT_004849e4 = perk_id_antiperk;
  _DAT_00484a10 = 0x23;
  _DAT_00484a3c = perk_id_antiperk;
  _DAT_00484a68 = 0x24;
  _DAT_00484a94 = perk_id_antiperk;
  _DAT_00484ac0 = 0x25;
  _DAT_00484aec = perk_id_antiperk;
  _DAT_00484b18 = 0x26;
  _DAT_00484b44 = perk_id_antiperk;
  _DAT_00484b70 = 0x27;
  _DAT_00484b9c = perk_id_antiperk;
  _DAT_00484bc8 = 0x28;
  _DAT_00484bf4 = perk_id_antiperk;
  _DAT_00484c20 = 0x29;
  _DAT_00484c4c = perk_id_antiperk;
  _DAT_00484c78 = 0x2a;
  _DAT_00484ca4 = perk_id_antiperk;
  _DAT_00484cd0 = 0x2b;
  _DAT_00484cfc = perk_id_antiperk;
  _DAT_00484d28 = 0x2c;
  _DAT_00484d54 = perk_id_antiperk;
  _DAT_00484d80 = 0x2d;
  _DAT_00484dac = perk_id_antiperk;
  _DAT_00484dd8 = 0x2e;
  _DAT_00484e04 = perk_id_antiperk;
  _DAT_00484e34 = 0x1f;
  _DAT_00484e30 = perk_id_antiperk;
  _DAT_00484e60 = 0;
  _DAT_00484e5c = 0x2f;
  _DAT_00484e8c = 0;
  _DAT_00484e88 = 0x30;
  _DAT_00484eb8 = 0x1e;
  _DAT_00484eb4 = perk_id_antiperk;
  _DAT_00484ee4 = 0;
  _DAT_00484ee0 = 0x31;
  _DAT_00484f10 = 0;
  _DAT_00484f0c = 0x32;
  _DAT_00484f3c = 0;
  _DAT_00484f38 = perk_id_antiperk;
  _DAT_00484f68 = 0;
  _DAT_00484f64 = 0x33;
  _DAT_00484f94 = 0;
  _DAT_00484f90 = 0x34;
  _DAT_00484fc0 = 0x1c;
  _DAT_00484fbc = perk_id_antiperk;
  return;
}



