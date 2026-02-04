/* weapon_table_init @ 004519b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* initializes the weapon stats table at DAT_004d7a28 */

void weapon_table_init(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  iVar4 = 0;
  piVar3 = &weapon_table.pellet_count;
  do {
    iVar1 = iVar4 + -1;
    iVar4 = iVar4 + 1;
    piVar3[-4] = iVar1;
    *piVar3 = 1;
    piVar3 = piVar3 + 0x1f;
  } while ((int)piVar3 < 0x4d99a0);
  uVar5 = 0xffffffff;
  weapon_table.hud_icon_id = 0;
  pcVar7 = s_Fire_bullets_0047958c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d7ef4 = 0x41f00000;
  _DAT_004d7fec = 0x420c0000;
  _DAT_004d84c4 = 0x41700000;
  _DAT_004d8540 = 0x41a00000;
  _DAT_004d85bc = 0x41200000;
  _DAT_004d8828 = 0x41200000;
  _DAT_004d83cc = 0x41a00000;
  _DAT_004d7d80 = 0x43570000;
  _DAT_004d8e74 = 0x41700000;
  _DAT_004d8f6c = 0x41200000;
  _DAT_004d7c0c = 0x42700000;
  DAT_004d7b14 = 0x425c0000;
  _DAT_004d7b90 = 0x42480000;
  _DAT_004d86b4 = 0x41a00000;
  _DAT_004d86b8 = 0x41300000;
  DAT_004d9064 = 0x42700000;
  _DAT_004d9068 = 0x3e800000;
  _DAT_004d8730 = 0x41200000;
  _DAT_004d8734 = 0x3f000000;
  _DAT_004d7ef8 = 0x40a00000;
  _DAT_004d7ff0 = 0x40066666;
  _DAT_004d84c8 = 0x40400000;
  _DAT_004d8544 = 0x3fb33333;
  _DAT_004d85c0 = 0x4185999a;
  _DAT_004d882c = 0x41e00000;
  _DAT_004d83d0 = 0x3f800000;
  _DAT_004d8e78 = 0;
  _DAT_004d7c10 = 0x3f99999a;
  DAT_004d7b18 = 0x40833333;
  _DAT_004d863c = 0;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8ff8;
  for (uVar6 = uVar5 >> 2; _DAT_004d7b7c = sfx_autorifle_fire, uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; _DAT_004d7b08 = sfx_pistol_reload, uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s_Pistol_00479584;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d9060 = 1;
  _DAT_004d903c = 0x70;
  DAT_004d9040 = 0x3e0f5c29;
  _DAT_004d9044 = 0x3f99999a;
  _DAT_004d9048 = 0x3e6147ae;
  DAT_004d9050 = _DAT_004d7b7c;
  _DAT_004d9058 = sfx_pistol_reload;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7aa8;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  DAT_004d7b10 = 5;
  _DAT_004d7aec = 0xc;
  _DAT_004d7af0 = 0x3f3631f9;
  DAT_004d7af4 = 0x3f99999a;
  _DAT_004d7af8 = 0x3e6147ae;
  _DAT_004d7b00 = sfx_pistol_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Assault_Rifle_00479574;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7b24;
  for (uVar6 = uVar5 >> 2; _DAT_004d93bc = sfx_shotgun_reload, uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; _DAT_004d83c0 = sfx_autorifle_reload, uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &DAT_0047956c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d7b8c = 1;
  _DAT_004d7b68 = 0x19;
  _DAT_004d7b6c = 0x3def9db2;
  _DAT_004d7b70 = 0x3f99999a;
  _DAT_004d7b74 = 0x3db851ec;
  _DAT_004d7b84 = sfx_autorifle_reload;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7ba0;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; _DAT_004d8434 = sfx_shotgun_fire, uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d7be4 = 0xc;
  _DAT_004d7c14 = 0xc;
  uVar5 = 0xffffffff;
  _DAT_004d7c08 = 1;
  pcVar7 = s_Sawed_off_Shotgun_00479558;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  _DAT_004d7be8 = 0x3f59999a;
  uVar5 = ~uVar5;
  _DAT_004d7bec = 0x3ff33333;
  _DAT_004d7bf0 = 0x3e8a3d71;
  _DAT_004d7bf8 = sfx_shotgun_fire;
  _DAT_004d7c00 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7c1c;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d7c60 = 0xc;
  _DAT_004d7c90 = 0xc;
  uVar5 = 0xffffffff;
  _DAT_004d7c84 = 1;
  pcVar7 = s_Jackhammer_0047954c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d7c64 = 0x3f5eb852;
  _DAT_004d7c68 = 0x3ff33333;
  _DAT_004d7c6c = 0x3e051eb8;
  _DAT_004d7c74 = _DAT_004d8434;
  _DAT_004d7c7c = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d83dc;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s_Submachine_Gun_0047953c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8444 = 1;
  _DAT_004d8420 = 0x10;
  _DAT_004d8424 = 0x3e0f5c29;
  _DAT_004d8428 = 0x40400000;
  _DAT_004d842c = 0x3e23d70a;
  _DAT_004d8450 = 4;
  _DAT_004d843c = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7c98;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d7cf0 = sfx_hrpm_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Flamethrower_0047952c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d7d00 = 5;
  _DAT_004d7cdc = 0x1e;
  _DAT_004d7ce0 = 0x3db476b0;
  _DAT_004d7ce4 = 0x3f99999a;
  _DAT_004d7ce8 = 0x3da7ef9e;
  _DAT_004d7cf8 = _DAT_004d83c0;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7e0c;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d7e64 = sfx_flamer_fire_01;
  uVar5 = 0xffffffff;
  pcVar7 = s_Plasma_Rifle_0047951c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d7e74 = 8;
  _DAT_004d7e68 = 2;
  _DAT_004d7e50 = 0x1e;
  _DAT_004d7e54 = 0x3c04ec63;
  _DAT_004d7e58 = 0x40000000;
  _DAT_004d7e5c = 0x3c75c28f;
  _DAT_004d7e08 = 1;
  _DAT_004d7e6c = _DAT_004d83c0;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7e88;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d7ecc = 0x14;
  _DAT_004d7ee0 = sfx_shock_fire;
  uVar5 = 0xffffffff;
  _DAT_004d7ed0 = 0x3e94e545;
  _DAT_004d7ed4 = 0x3f99999a;
  _DAT_004d7ed8 = 0x3e3a5e35;
  _DAT_004d7ee8 = _DAT_004d83c0;
  pcVar7 = s_Multi_Plasma_0047950c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7f04;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d7f5c = sfx_shock_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Plasma_Minigun_004794fc;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d7f48 = 8;
  _DAT_004d7f4c = 0x3f1eed84;
  _DAT_004d7f50 = 0x3fb33333;
  _DAT_004d7f54 = 0x3ea3d70a;
  _DAT_004d7f78 = 3;
  _DAT_004d7f64 = _DAT_004d83c0;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7f80;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  DAT_004d7fd8 = sfx_plasmaminigun_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Gauss_Gun_004794f0;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d7fc4 = 0x1e;
  _DAT_004d7fc8 = 0x3de147ae;
  _DAT_004d7fcc = 0x3fa66666;
  _DAT_004d7fd0 = 0x3dc6a7f0;
  _DAT_004d7fe0 = _DAT_004d83c0;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7d14;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d7d6c = sfx_gauss_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Rocket_Launcher_004794e0;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d7d7c = 1;
  _DAT_004d7d58 = 6;
  _DAT_004d7d5c = 0x3f19999a;
  _DAT_004d7d60 = 0x3fcccccd;
  _DAT_004d7d64 = 0x3ed70a3d;
  _DAT_004d7d74 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7ffc;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8064 = 8;
  _DAT_004d8040 = 5;
  _DAT_004d8044 = 0x3f3da5d6;
  _DAT_004d8048 = 0x3f99999a;
  _DAT_004d804c = 0x3ed70a3d;
  _DAT_004d8054 = sfx_rocket_fire;
  _DAT_004d805c = sfx_autorifle_reload_alt;
  uVar5 = 0xffffffff;
  _DAT_004d7ff8 = 2;
  pcVar7 = s_Seeker_Rockets_004794d0;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8078;
  for (uVar6 = uVar5 >> 2; _DAT_004d80d8 = sfx_autorifle_reload_alt, uVar6 != 0; uVar6 = uVar6 - 1)
  {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d80d0 = sfx_rocket_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Mean_Minigun_004794c0;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d80e0 = 8;
  _DAT_004d80bc = 8;
  _DAT_004d80c0 = 0x3e9f22b6;
  _DAT_004d80c4 = 0x3f99999a;
  _DAT_004d80c8 = 0x3ea3d70a;
  _DAT_004d8074 = 2;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d7d90;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d7de8 = sfx_autorifle_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Plasma_Shotgun_004794b0;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d7df8 = 3;
  _DAT_004d7dd4 = 0x78;
  _DAT_004d7dd8 = 0x3db851ec;
  _DAT_004d7ddc = 0x40800000;
  _DAT_004d7de0 = 0x3d7df3b6;
  _DAT_004d7df0 = _DAT_004d83c0;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d80f4;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d814c = sfx_plasmashotgun_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Blow_Torch_004794a4;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8138 = 8;
  _DAT_004d813c = 0x3ef5c28f;
  _DAT_004d8140 = 0x40466666;
  _DAT_004d8144 = 0x3de147ae;
  _DAT_004d8168 = 0xe;
  _DAT_004d8154 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8170;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d81c8 = sfx_flamer_fire_01;
  uVar5 = 0xffffffff;
  pcVar7 = s_HR_Flamer_00479498;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d81d8 = 8;
  _DAT_004d81cc = 2;
  _DAT_004d81b4 = 0x1e;
  _DAT_004d81b8 = 0x3bc84f90;
  _DAT_004d81bc = 0x3fc00000;
  _DAT_004d81c0 = 0x3c23d70a;
  _DAT_004d816c = 1;
  _DAT_004d81d0 = _DAT_004d83c0;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d81ec;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8244 = sfx_flamer_fire_01;
  uVar5 = 0xffffffff;
  pcVar7 = s_Mini_Rocket_Swarmers_00479480;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8254 = 8;
  _DAT_004d8248 = 2;
  _DAT_004d8230 = 0x1e;
  _DAT_004d8234 = 0x3c0b4396;
  _DAT_004d8238 = 0x3fe66666;
  _DAT_004d823c = 0x3c23d70a;
  _DAT_004d81e8 = 1;
  _DAT_004d824c = _DAT_004d83c0;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8268;
  for (uVar6 = uVar5 >> 2; _DAT_004d82c8 = sfx_autorifle_reload_alt, uVar6 != 0; uVar6 = uVar6 - 1)
  {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d82c0 = sfx_rocket_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Rocket_Minigun_00479470;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d82d0 = 8;
  _DAT_004d82ac = 5;
  _DAT_004d82b0 = 0x3fe66666;
  _DAT_004d82b4 = 0x3fe66666;
  _DAT_004d82b8 = 0x3df5c28f;
  _DAT_004d8264 = 2;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d82e4;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d834c = 8;
  _DAT_004d8328 = 0x10;
  _DAT_004d832c = 0x3df5c28f;
  _DAT_004d833c = sfx_rocketmini_fire;
  _DAT_004d8344 = sfx_autorifle_reload_alt;
  uVar5 = 0xffffffff;
  _DAT_004d8330 = 0x3fe66666;
  pcVar7 = s_Pulse_Gun_00479464;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8334 = 0x3df5c28f;
  _DAT_004d82e0 = 2;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8360;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; _DAT_004d86a8 = sfx_shock_reload, uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d83b8 = sfx_pulse_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Ion_Rifle_00479458;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d83c8 = 8;
  _DAT_004d83a4 = 0x10;
  _DAT_004d83a8 = 0x3dcccccd;
  _DAT_004d83ac = 0x3dcccccd;
  _DAT_004d83b0 = 0;
  _DAT_004d835c = 3;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8458;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d84b0 = sfx_shock_fire_alt;
  uVar5 = 0xffffffff;
  pcVar7 = s_Ion_Minigun_0047944c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d84c0 = 8;
  _DAT_004d849c = 8;
  _DAT_004d84a0 = 0x3ecccccd;
  _DAT_004d84a4 = 0x3faccccd;
  _DAT_004d84a8 = 0x3de56042;
  _DAT_004d8454 = 4;
  _DAT_004d84b8 = _DAT_004d86a8;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d84d4;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d852c = sfx_shockminigun_fire;
  uVar5 = 0xffffffff;
  _DAT_004d853c = 8;
  _DAT_004d8518 = 0x14;
  _DAT_004d851c = 0x3dcccccd;
  _DAT_004d8520 = 0x3fe66666;
  _DAT_004d8524 = 0x3db851ec;
  _DAT_004d84d0 = 4;
  _DAT_004d8534 = _DAT_004d86a8;
  pcVar7 = s_Ion_Cannon_00479440;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8550;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d85a8 = sfx_shock_fire_alt;
  uVar5 = 0xffffffff;
  pcVar7 = s_Ion_Shotgun_00479434;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8594 = 3;
  _DAT_004d8598 = 0x3f800000;
  _DAT_004d859c = 0x40400000;
  _DAT_004d85a0 = 0x3f2e147b;
  _DAT_004d854c = 4;
  _DAT_004d85b0 = _DAT_004d86a8;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8930;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8988 = sfx_shock_fire_alt;
  uVar5 = 0xffffffff;
  pcVar7 = s_Gauss_Shotgun_00479424;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8998 = 1;
  _DAT_004d8974 = 10;
  _DAT_004d8978 = 0x3f59999a;
  _DAT_004d897c = 0x3ff33333;
  _DAT_004d8980 = 0x3e8a3d71;
  _DAT_004d89a4 = 8;
  _DAT_004d892c = 4;
  _DAT_004d8990 = _DAT_004d86a8;
  _DAT_004d8994 = 0x1f;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d88b4;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d890c = sfx_gauss_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Plasma_Cannon_00479414;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d891c = 1;
  _DAT_004d88f8 = 4;
  _DAT_004d88fc = 0x3f866666;
  _DAT_004d8900 = 0x40066666;
  _DAT_004d8904 = 0x3e8a3d71;
  _DAT_004d88b0 = 0;
  _DAT_004d8914 = _DAT_004d93bc;
  _DAT_004d8918 = 0x1e;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d87bc;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8814 = sfx_shock_fire;
  uVar5 = 0xffffffff;
  _DAT_004d8800 = 3;
  pcVar7 = s_Evil_Scythe_00479408;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8804 = 0x3f666666;
  _DAT_004d8808 = 0x402ccccd;
  _DAT_004d880c = 0x3f19999a;
  _DAT_004d881c = _DAT_004d86a8;
  _DAT_004d8820 = 0x19;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8740;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8798 = sfx_shock_fire_alt;
  uVar5 = 0xffffffff;
  pcVar7 = s_Flameburst_004793fc;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8784 = 3;
  _DAT_004d8788 = 0x3f800000;
  _DAT_004d878c = 0x40400000;
  _DAT_004d8790 = 0x3f2e147b;
  _DAT_004d873c = 4;
  _DAT_004d87a0 = _DAT_004d86a8;
  _DAT_004d87a4 = 0x19;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d89ac;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8a04 = sfx_flamer_fire_01;
  uVar5 = 0xffffffff;
  pcVar7 = &DAT_004793f4;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d89f0 = 0x3c;
  _DAT_004d89f4 = 0x3ca3d70a;
  _DAT_004d89f8 = 0x40400000;
  _DAT_004d89fc = 0x3e3851ec;
  _DAT_004d89a8 = 4;
  _DAT_004d8a0c = _DAT_004d86a8;
  _DAT_004d8a10 = 0x1d;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8a28;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8a80 = sfx_shock_fire_alt;
  uVar5 = 0xffffffff;
  _DAT_004d8a6c = 0xc;
  _DAT_004d8a70 = 0x3f333333;
  _DAT_004d8a74 = 0x40000000;
  _DAT_004d8a78 = 0x3ec28f5c;
  _DAT_004d8a24 = 4;
  _DAT_004d8a88 = _DAT_004d86a8;
  _DAT_004d8a8c = 0x1e;
  pcVar7 = s_Splitter_Gun_004793e4;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8838;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8890 = sfx_shock_fire_alt;
  uVar5 = 0xffffffff;
  pcVar7 = s_Shrinkifier_5k_004793d4;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d887c = 6;
  _DAT_004d8880 = 0x3f333333;
  _DAT_004d8884 = 0x400ccccd;
  _DAT_004d8888 = 0x3e8f5c29;
  _DAT_004d8834 = 0;
  _DAT_004d8898 = _DAT_004d86a8;
  _DAT_004d88a8 = 0x40c00000;
  _DAT_004d88a4 = 0x41f00000;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d85cc;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8624 = sfx_shock_fire_alt;
  uVar5 = 0xffffffff;
  pcVar7 = s_Blade_Gun_004793c8;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8634 = 8;
  _DAT_004d8610 = 8;
  _DAT_004d8614 = 0x3e570a3d;
  _DAT_004d8618 = 0x3f9c28f6;
  _DAT_004d861c = 0x3d23d70a;
  _DAT_004d862c = _DAT_004d86a8;
  _DAT_004d8630 = 0x17;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8648;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d86a0 = sfx_shock_fire_alt;
  uVar5 = 0xffffffff;
  pcVar7 = s_Plague_Sphreader_Gun_004793b0;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d86b0 = 8;
  _DAT_004d868c = 6;
  _DAT_004d8690 = 0x3eb33333;
  _DAT_004d8694 = 0x40600000;
  _DAT_004d8698 = 0x3d23d70a;
  _DAT_004d86ac = 0x18;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8e08;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; _DAT_004d92bc = sfx_bloodspill_01, uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d8e70 = 8;
  uVar5 = 0xffffffff;
  pcVar7 = s_Rainbow_Gun_004793a4;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8e4c = 5;
  _DAT_004d8e50 = 0x3e4ccccd;
  _DAT_004d8e54 = 0x3f99999a;
  _DAT_004d8e58 = 0x3d23d70a;
  _DAT_004d8e60 = sfx_bloodspill_01;
  _DAT_004d8e68 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8f00;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s_Grim_Weapon_00479398;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8f68 = 8;
  _DAT_004d8f44 = 10;
  _DAT_004d8f48 = 0x3e4ccccd;
  _DAT_004d8f4c = 0x3f99999a;
  _DAT_004d8f50 = 0x3db851ec;
  _DAT_004d8f58 = _DAT_004d92bc;
  _DAT_004d8f60 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8f7c;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s_Bubblegun_0047938c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8fc0 = 3;
  _DAT_004d8fc4 = 0x3f000000;
  _DAT_004d8fc8 = 0x3f99999a;
  _DAT_004d8fcc = 0x3ecccccd;
  _DAT_004d8fd4 = _DAT_004d92bc;
  _DAT_004d8fdc = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d8e84;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s_Spider_Plasma_0047937c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d8eec = 8;
  _DAT_004d8ec8 = 0xf;
  _DAT_004d8ecc = 0x3e252bd4;
  _DAT_004d8ed0 = 0x3f99999a;
  _DAT_004d8ed4 = 0x3d4ccccd;
  _DAT_004d8edc = _DAT_004d92bc;
  _DAT_004d8ee4 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d86c4;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s_Transmutator_0047936c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d872c = 8;
  _DAT_004d8708 = 5;
  _DAT_004d870c = 0x3e4ccccd;
  _DAT_004d8710 = 0x3f99999a;
  _DAT_004d8714 = 0x3d23d70a;
  _DAT_004d871c = _DAT_004d92bc;
  _DAT_004d8724 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d9264;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; _DAT_004d93b4 = sfx_explosion_large, uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s_Blaster_R_300_0047935c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d92cc = 9;
  _DAT_004d92a8 = 0x32;
  _DAT_004d92ac = 0x3d23d70a;
  _DAT_004d92b0 = 0x40a00000;
  _DAT_004d92b4 = 0x3d23d70a;
  _DAT_004d92c4 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d92e0;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d9338 = sfx_shock_fire;
  uVar5 = 0xffffffff;
  pcVar7 = s_Nuke_Launcher_0047934c;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d9348 = 9;
  _DAT_004d9324 = 0x14;
  _DAT_004d9328 = 0x3da3d70a;
  _DAT_004d932c = 0x40000000;
  _DAT_004d9330 = 0x3d4ccccd;
  _DAT_004d9340 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d93d8;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s___Lighting_Rifle_0047933a + 2;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  _DAT_004d9440 = 8;
  _DAT_004d941c = 1;
  _DAT_004d9420 = 0x40800000;
  _DAT_004d9424 = 0x41000000;
  _DAT_004d9428 = 0x3f800000;
  _DAT_004d9430 = _DAT_004d93b4;
  _DAT_004d9438 = _DAT_004d93bc;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_004d935c;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  _DAT_004d93c4 = 8;
  _DAT_004d93a0 = 500;
  _DAT_004d93a4 = 0x40800000;
  _DAT_004d93a8 = 0x41000000;
  _DAT_004d93ac = 0x3f800000;
  return;
}



