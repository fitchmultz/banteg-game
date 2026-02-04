/* demo_setup_variant_0 @ 00402ed0 */

/* demo setup 0: 2P, spawns template 0x38 grid, assigns weapon 0xb */

void demo_setup_variant_0(void)

{
  uint uVar1;
  uint uVar2;
  int local_1c;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  config_blob.reserved0[0x14] = '\x02';
  config_blob.reserved0[0x15] = '\0';
  config_blob.reserved0[0x16] = '\0';
  config_blob.reserved0[0x17] = '\0';
  demo_time_limit_ms = 4000;
  uVar2 = 0;
  local_1c = 0x100;
  do {
    uVar1 = uVar2 & 0x80000001;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    local_10 = (float)(int)((uVar1 + 2) * 0x40);
    local_c = (float)local_1c;
    creature_spawn_template(0x38,&local_10,-100.0);
    local_8 = (float)(int)(uVar1 * 0x40 + 0x31e);
    local_4 = (float)local_1c;
    creature_spawn_template(0x38,&local_8,-100.0);
    local_1c = local_1c + 0x50;
    uVar2 = uVar2 + 1;
  } while (local_1c < 0x6a0);
  player_state_table.pos_x = 448.0;
  player_state_table.pos_y = 384.0;
  player2_pos_x = 0x44088000;
  player2_pos_y = 0x44238000;
  weapon_assign_player(0,0xb);
  weapon_assign_player(1,0xb);
  return;
}



