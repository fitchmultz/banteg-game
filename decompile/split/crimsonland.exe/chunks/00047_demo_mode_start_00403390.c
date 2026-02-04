/* demo_mode_start @ 00403390 */

/* starts demo mode and cycles the demo setup */

int demo_mode_start(void)

{
  int iVar1;
  
  if (game_state_id != 9) {
    game_state_set(9);
  }
  demo_purchase_screen_active = 0;
  demo_mode_active = 1;
  gameplay_reset_state();
  config_blob.reserved0[0x18] = '\x01';
  config_blob.reserved0[0x19] = '\0';
  config_blob.reserved0[0x1a] = '\0';
  config_blob.reserved0[0x1b] = '\0';
  if (demo_variant_index == 0) {
    demo_setup_variant_0();
  }
  else if (demo_variant_index == 1) {
    demo_setup_variant_1();
  }
  else if (demo_variant_index == 2) {
    demo_setup_variant_2();
  }
  else if (demo_variant_index == 3) {
    demo_setup_variant_3();
  }
  else if (demo_variant_index == 4) {
    demo_setup_variant_0();
  }
  else {
    demo_purchase_interstitial_begin();
  }
  iVar1 = demo_variant_index + 1;
  quest_spawn_timeline = 0;
  DAT_0048702c = 0;
  demo_variant_index = iVar1 % 6;
  return iVar1 / 6;
}



