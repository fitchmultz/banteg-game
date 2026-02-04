/* demo_setup_variant_2 @ 00402fe0 */

/* demo setup 2: 1P, spawns template 0x41 columns, assigns weapon 0x15 */

void demo_setup_variant_2(void)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int local_28;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  config_blob.reserved0[0x14] = '\x01';
  config_blob.reserved0[0x15] = '\0';
  config_blob.reserved0[0x16] = '\0';
  config_blob.reserved0[0x17] = '\0';
  demo_time_limit_ms = 5000;
  uVar2 = 0;
  local_28 = 0x80;
  do {
    uVar3 = uVar2 & 0x80000001;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
    }
    local_20 = (float)(int)(uVar3 * 0x40 + 0x20);
    fVar1 = (float)local_28;
    local_1c = fVar1;
    creature_spawn_template(0x41,&local_20,-100.0);
    local_18 = (float)(int)((uVar3 + 2) * 0x40);
    local_14 = fVar1;
    creature_spawn_template(0x41,&local_18,-100.0);
    local_10 = (float)(int)(uVar3 * 0x40 + -0x40);
    local_c = fVar1;
    creature_spawn_template(0x41,&local_10,-100.0);
    local_8 = (float)(int)((uVar3 + 0xc) * 0x40);
    local_4 = fVar1;
    creature_spawn_template(0x41,&local_8,-100.0);
    local_28 = local_28 + 0x3c;
    uVar2 = uVar2 + 1;
  } while (local_28 < 0x350);
  weapon_assign_player(0,0x15);
  return;
}



