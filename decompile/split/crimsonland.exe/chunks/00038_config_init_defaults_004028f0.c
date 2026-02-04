/* config_init_defaults @ 004028f0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* initializes default config globals, key bindings, and name slots */

int config_init_defaults(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char (*pacVar7) [27];
  char *pcVar8;
  char (*pacStack_4) [27];
  
  config_blob.reserved0[0x74] = '\0';
  config_blob.reserved0[0x75] = '\0';
  config_blob.reserved0[0x76] = '\0';
  config_blob.reserved0[0x77] = '\0';
  config_blob.reserved0[0x78] = '\0';
  config_blob.reserved0[0x79] = '\0';
  config_blob.reserved0[0x7a] = '\0';
  config_blob.reserved0[0x7b] = '\0';
  config_blob.hardcore = '\0';
  config_blob.full_version = '\x01';
  config_blob.perk_prompt_counter = 0;
  config_blob.reserved8[0] = '\0';
  config_blob.reserved8[1] = '\0';
  config_blob.reserved8[2] = '\0';
  config_blob.reserved8[3] = '?';
  config_blob.reserved6[0] = '\x01';
  config_blob.reserved6[1] = '\0';
  config_blob.reserved6[2] = '\0';
  config_blob.reserved6[3] = '\0';
  config_blob.key_pick_perk = 0x101;
  config_blob.key_reload = 0x102;
  config_blob.reserved7[0] = '\0';
  config_blob.reserved0[0x70] = '\0';
  config_blob.reserved0[0x71] = '\0';
  config_blob.reserved0[0x72] = 0x80;
  config_blob.reserved0[0x73] = '?';
  config_blob.score_load_gate = '\0';
  config_blob.reserved0[0x7c] = '\0';
  iVar4 = 0;
  pacStack_4 = config_blob.saved_names;
  iVar5 = 0x88;
  do {
    uVar2 = 0xffffffff;
    *(int *)(config_blob.reserved0 + iVar5) = iVar4;
    pcVar6 = s_default_0047131c;
    do {
      pcVar8 = pcVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    iVar5 = iVar5 + 4;
    pcVar6 = pcVar8 + -uVar2;
    pacVar7 = pacStack_4;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)*pacVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pacVar7 = (char (*) [27])(*pacVar7 + 4);
    }
    iVar4 = iVar4 + 1;
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      (*pacVar7)[0] = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pacVar7 = (char (*) [27])(*pacVar7 + 1);
    }
    pacStack_4 = pacStack_4 + 1;
  } while (iVar5 < 0xa8);
  config_blob.reserved0[3] = '\0';
  config_blob.reserved0[2] = '\0';
  pcVar6 = config_blob.player_name;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  uVar2 = 0xffffffff;
  pcVar6 = &default_player_name;
  do {
    pcVar8 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar6 = pcVar8 + -uVar2;
  pcVar8 = config_blob.player_name;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar8 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  }
  config_blob.reserved0[0x84] = '\x01';
  config_blob.reserved0[0x85] = '\0';
  config_blob.reserved0[0x86] = '\0';
  config_blob.reserved0[0x87] = '\0';
  config_blob.reserved0[0x80] = '\0';
  config_blob.reserved0[0x81] = '\0';
  config_blob.reserved0[0x82] = '\0';
  config_blob.reserved0[0x83] = '\0';
  config_blob.reserved0[0] = '\0';
  config_blob.reserved0[1] = '\0';
  config_blob.fx_toggle = '\0';
  config_blob.reserved6[0x10] = '\x01';
  config_blob.reserved1[4] = '\0';
  config_blob.reserved1[5] = '\0';
  config_blob.reserved1[6] = '\0';
  config_blob.reserved1[7] = '\0';
  config_blob.reserved1[8] = '\0';
  config_blob.reserved1[9] = '\0';
  config_blob.reserved1[10] = '\0';
  config_blob.reserved1[0xb] = '\0';
  config_blob.reserved0[0x6c] = '\0';
  config_blob.reserved0[0x6d] = '\0';
  config_blob.reserved0[0x6e] = '\0';
  config_blob.reserved0[0x6f] = '\0';
  config_blob.display_bpp = 0x20;
  config_blob.windowed._0_1_ = 0;
  config_blob.reserved0[0x18] = '\x01';
  config_blob.reserved0[0x19] = '\0';
  config_blob.reserved0[0x1a] = '\0';
  config_blob.reserved0[0x1b] = '\0';
  config_blob.reserved0[0xe] = '\x01';
  config_blob.reserved0[0xf] = '\0';
  config_blob.reserved0[0x10] = '\x01';
  config_blob.reserved0[0x1c] = '\x02';
  config_blob.reserved0[0x1d] = '\0';
  config_blob.reserved0[0x1e] = '\0';
  config_blob.reserved0[0x1f] = '\0';
  config_blob.reserved0[0x20] = '\x02';
  config_blob.reserved0[0x21] = '\0';
  config_blob.reserved0[0x22] = '\0';
  config_blob.reserved0[0x23] = '\0';
  config_blob.reserved0[0x44] = '\0';
  config_blob.reserved0[0x45] = '\0';
  config_blob.reserved0[0x46] = '\0';
  config_blob.reserved0[0x47] = '\0';
  config_blob.reserved0[0x48] = '\0';
  config_blob.reserved0[0x49] = '\0';
  config_blob.reserved0[0x4a] = '\0';
  config_blob.reserved0[0x4b] = '\0';
  config_blob.reserved0[0x11] = '\x01';
  config_blob.reserved0[0x14] = '\x01';
  config_blob.reserved0[0x15] = '\0';
  config_blob.reserved0[0x16] = '\0';
  config_blob.reserved0[0x17] = '\0';
  config_blob.keybinds_p1[3] = 0x20;
  config_blob.detail_preset = 5;
  config_blob.reserved1[0xc] = '(';
  config_blob.reserved1[0xd] = '#';
  config_blob.reserved1[0xe] = '\0';
  config_blob.reserved1[0xf] = '\0';
  config_blob.reserved1[0x10] = 'x';
  config_blob.reserved1[0x11] = 'i';
  config_blob.reserved1[0x12] = '\0';
  config_blob.reserved1[0x13] = '\0';
  config_blob.reserved1[0] = 'd';
  config_blob.reserved1[1] = '\0';
  config_blob.reserved1[2] = '\0';
  config_blob.reserved1[3] = '\0';
  config_blob.screen_width = 800;
  config_blob.screen_height = 600;
  config_blob.sfx_volume = 1.0;
  config_blob.music_volume = 1.0;
  config_blob.keybinds_p1[0] = 0x11;
  config_blob.keybinds_p1[1] = 0x1f;
  config_blob.keybinds_p1[2] = 0x1e;
  config_blob.keybinds_p1[4] = 0x100;
  config_blob.keybinds_p1[5] = 0x17e;
  config_blob.keybinds_p1[6] = 0x17e;
  config_blob.keybinds_p1[7] = 0x10;
  config_blob.keybinds_p1[8] = 0x12;
  config_blob.keybinds_p1[9] = 0x13f;
  config_blob.keybinds_p1[10] = 0x140;
  config_blob.keybinds_p1[0xb] = 0x141;
  config_blob.keybinds_p1[0xc] = 0x153;
  config_blob.reserved2[0] = '~';
  config_blob.reserved2[1] = '\x01';
  config_blob.reserved2[2] = '\0';
  config_blob.reserved2[3] = '\0';
  config_blob.reserved2[4] = '~';
  config_blob.reserved2[5] = '\x01';
  config_blob.reserved2[6] = '\0';
  config_blob.reserved2[7] = '\0';
  config_blob.reserved2[8] = '~';
  config_blob.reserved2[9] = '\x01';
  config_blob.reserved2[10] = '\0';
  config_blob.reserved2[0xb] = '\0';
  config_blob.keybinds_p2[0] = 200;
  config_blob.keybinds_p2[1] = 0xd0;
  config_blob.keybinds_p2[2] = 0xcb;
  config_blob.keybinds_p2[3] = 0xcd;
  config_blob.keybinds_p2[4] = 0x9d;
  config_blob.keybinds_p2[5] = 0x17e;
  config_blob.keybinds_p2[6] = 0x17e;
  config_blob.keybinds_p2[7] = 0xd3;
  config_blob.keybinds_p2[8] = 0xd1;
  config_blob.keybinds_p2[9] = 0x13f;
  config_blob.keybinds_p2[10] = 0x140;
  config_blob.keybinds_p2[0xb] = 0x141;
  config_blob.keybinds_p2[0xc] = 0x153;
  config_blob.reserved3[0] = '~';
  config_blob.reserved3[1] = '\x01';
  config_blob.reserved3[2] = '\0';
  config_blob.reserved3[3] = '\0';
  config_blob.reserved3[4] = '~';
  config_blob.reserved3[5] = '\x01';
  config_blob.reserved3[6] = '\0';
  config_blob.reserved3[7] = '\0';
  config_blob.reserved3[8] = '~';
  config_blob.reserved3[9] = '\x01';
  config_blob.reserved3[10] = '\0';
  config_blob.reserved3[0xb] = '\0';
  config_blob.reserved0[4] = '\x01';
  config_blob.reserved0[5] = '\x01';
  return 0x17e;
}



