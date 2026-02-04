/* demo_setup_variant_1 @ 004030f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* demo setup 1: 2P, terrain preset DAT_00484914, templates 0x34/0x35, weapon 5, power-up timer */

void demo_setup_variant_1(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  config_blob.reserved0[0x14] = '\x02';
  config_blob.reserved0[0x15] = '\0';
  config_blob.reserved0[0x16] = '\0';
  config_blob.reserved0[0x17] = '\0';
  terrain_generate(&DAT_00484914);
  demo_time_limit_ms = 5000;
  iVar3 = 0;
  do {
    iVar1 = crt_rand();
    iVar2 = crt_rand();
    local_c = (float)(iVar2 % 899 + 0x40);
    local_10 = (float)(iVar1 % 200 + 0x20);
    creature_spawn_template(0x34,&local_10,-100.0);
    if (iVar3 % 3 != 0) {
      iVar1 = crt_rand();
      iVar2 = crt_rand();
      local_4 = (float)(iVar2 % 899 + 0x40);
      local_8 = (float)(iVar1 % 0x1e + 0x20);
      creature_spawn_template(0x35,&local_8,-100.0);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x14);
  player_state_table.pos_x = 490.0;
  player_state_table.pos_y = 448.0;
  player2_pos_x = 0x43f00000;
  player2_pos_y = 0x44100000;
  weapon_assign_player(0,5);
  weapon_assign_player(1,5);
  _bonus_weapon_power_up_timer = 0x41700000;
  return;
}



