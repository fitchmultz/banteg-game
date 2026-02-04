/* demo_setup_variant_3 @ 00403250 */

/* demo setup 3: 1P, quest-selected terrain, templates 0x24/0x25, weapon 0x12 */

void demo_setup_variant_3(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  config_blob.reserved0[0x14] = '\x01';
  config_blob.reserved0[0x15] = '\0';
  config_blob.reserved0[0x16] = '\0';
  config_blob.reserved0[0x17] = '\0';
  terrain_generate(&quest_selected_meta);
  demo_time_limit_ms = 4000;
  iVar3 = 0;
  do {
    iVar1 = crt_rand();
    iVar2 = crt_rand();
    local_c = (float)(iVar2 % 899 + 0x40);
    local_10 = (float)(iVar1 % 200 + 0x20);
    creature_spawn_template(0x24,&local_10,0.0);
    if (iVar3 % 3 != 0) {
      iVar1 = crt_rand();
      iVar2 = crt_rand();
      local_4 = (float)(iVar2 % 899 + 0x40);
      local_8 = (float)(iVar1 % 0x1e + 0x20);
      creature_spawn_template(0x25,&local_8,0.0);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x14);
  player_state_table.pos_x = 512.0;
  player_state_table.pos_y = 512.0;
  weapon_assign_player(0,0x12);
  return;
}



