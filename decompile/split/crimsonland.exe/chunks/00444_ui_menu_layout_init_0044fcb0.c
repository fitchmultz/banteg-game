/* ui_menu_layout_init @ 0044fcb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* initializes menu UI element layout and text textures */

void ui_menu_layout_init(void)

{
  char *pcVar1;
  int iVar2;
  ui_element_t *puVar3;
  int *piVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  char *unaff_EBX;
  ui_element_t **ppuVar10;
  uchar *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  char *pcVar14;
  int iVar15;
  float fStack_30;
  float fStack_2c;
  float afStack_28 [2];
  uint local_20 [8];
  
  screen_fade_alpha = 0;
  _DAT_00487288 = (float)config_blob.screen_width * 0.0015625;
  _DAT_0048723c = 0;
  DAT_0048702c = 0;
  _DAT_0048728c = (float)config_blob.screen_height * 0.0020833334;
  ppuVar10 = &ui_element_table_end;
  for (iVar7 = 0x29; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppuVar10 = (ui_element_t *)0x0;
    ppuVar10 = ppuVar10 + 1;
  }
  ui_element_table_end = (ui_element_t *)&ui_sign_crimson;
  DAT_0048f16c = &DAT_004875a8;
  DAT_0048f170 = &DAT_00488208;
  _DAT_0048f174 = &DAT_004878c0;
  _DAT_0048f178 = &DAT_00487bd8;
  _DAT_0048f17c = &DAT_00487ef0;
  pcVar1 = (char *)(*grim_interface_ptr->vtable->grim_get_config_var)(local_20,100);
  if (*pcVar1 == '\0') {
    _DAT_0048f184 = &DAT_00488520;
    _DAT_0048f180 = &DAT_00488838;
  }
  else {
    _DAT_0048f180 = &DAT_00488520;
    _DAT_0048f184 = &DAT_00488838;
  }
  _DAT_0048f1e4 = &DAT_00488b50;
  ui_menu_layout_c = &DAT_00488e68;
  _DAT_0048f190 = &DAT_00489180;
  _DAT_0048f194 = &DAT_00489498;
  ui_menu_layout_a = &DAT_004897b0;
  _DAT_0048f1a4 = &DAT_0048a410;
  _DAT_0048f1a8 = &DAT_0048a728;
  _DAT_0048f1ac = &DAT_0048aa40;
  _DAT_0048f1b4 = &DAT_0048ad58;
  _DAT_0048f1b8 = &DAT_0048b070;
  _DAT_0048f1bc = &DAT_0048b388;
  DAT_0048f1c0 = &DAT_0048b6a0;
  DAT_0048f1c4 = &DAT_0048b9b8;
  _DAT_0048f1c8 = &DAT_0048bcd0;
  _DAT_0048f1cc = &DAT_0048bfe8;
  _DAT_0048f1d0 = &DAT_0048c300;
  _DAT_0048f1d4 = &DAT_0048c618;
  _DAT_0048f1d8 = &DAT_0048eb38;
  _DAT_0048f1dc = &DAT_0048c930;
  _DAT_0048f1e0 = &DAT_0048cc48;
  _DAT_0048f19c = &DAT_0048cf60;
  _DAT_0048f1a0 = &DAT_0048d278;
  ui_menu_layout_b = &DAT_0048d590;
  _DAT_0048f188 = &DAT_00489ac8;
  _DAT_0048f18c = &DAT_00489de0;
  _DAT_0048f1ec = &DAT_0048a0f8;
  _DAT_0048f1f0 = &DAT_0048d8a8;
  _DAT_0048f1f4 = &DAT_0048dbc0;
  _DAT_0048f1f8 = &DAT_0048ded8;
  _DAT_0048f1fc = &DAT_0048e1f0;
  _DAT_0048f200 = &DAT_0048e508;
  DAT_0048f204 = &DAT_0048e820;
  ui_element_table_start = (ui_element_t *)&DAT_0048ee50;
  ppuVar10 = &ui_element_table_end;
  do {
    FUN_0044faa0((char *)*ppuVar10);
    iVar7 = config_blob.screen_width;
    ppuVar10 = ppuVar10 + 1;
  } while ((int)ppuVar10 < 0x48f20c);
  puVar12 = &DAT_0048fac0;
  puVar13 = &DAT_004872cc;
  for (iVar8 = 0x3a; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  _DAT_004872a8 = (float)(iVar7 + 4);
  _DAT_004872ac = 0x428c0000;
  if (iVar7 < 0x281) {
    _DAT_004872ac = 0x42700000;
  }
  pcVar14 = s_ui_ui_itemTexts_jaz_00479318;
  DAT_0048f7f4 = texture_get_or_load_alt(s_ui_ui_itemTexts_jaz_00479318,unaff_EBX);
  pcVar1 = s_ui_ui_textReaper_jaz_00479300;
  DAT_0048f7f8 = texture_get_or_load_alt(s_ui_ui_textReaper_jaz_00479300,pcVar14);
  pcVar14 = s_ui_ui_textControls_jaz_004792e8;
  DAT_0048f7fc = texture_get_or_load_alt(s_ui_ui_textControls_jaz_004792e8,pcVar1);
  pcVar1 = s_ui_ui_textPickAPerk_jaz_004792d0;
  DAT_0048f800 = texture_get_or_load_alt(s_ui_ui_textPickAPerk_jaz_004792d0,pcVar14);
  DAT_0048f804 = texture_get_or_load_alt(s_ui_ui_textWellDone_jaz_004792b8,pcVar1);
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_00488244;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  DAT_00488220 = 0xc2700000;
  DAT_00488224 = 0x43520000;
  afStack_28[0] = 270.0;
  afStack_28[1] = -38.0;
  ui_element_set_rect((ui_element_t *)&DAT_0048832c,124.0,30.0,afStack_28);
  _DAT_00488238 = 0x30;
  _DAT_0048823c = &LAB_0044fc70;
  iVar7 = game_is_full_version();
  if ((char)iVar7 != '\0') {
    _DAT_0048823c = &LAB_00447350;
  }
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_004878fc;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_004878d8 = 0xc2700000;
  _DAT_004878dc = 0x43870000;
  afStack_28[0] = 270.0;
  afStack_28[1] = -38.0;
  ui_element_set_rect((ui_element_t *)&DAT_004879e4,124.0,30.0,afStack_28);
  _DAT_004878f4 = ui_menu_main_click_play_game;
  _DAT_004878f0 = 0x19;
  afStack_28[0] = 270.0;
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_00487c14;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_00487bf0 = 0xc2700000;
  _DAT_00487bf4 = 0x43a50000;
  afStack_28[1] = -38.0;
  ui_element_set_rect((ui_element_t *)&DAT_00487cfc,124.0,30.0,afStack_28);
  _DAT_00487c0c = ui_menu_main_click_options;
  _DAT_00487c08 = 0x18;
  afStack_28[0] = 270.0;
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_00487f2c;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_00487f08 = 0xc2700000;
  _DAT_00487f0c = 0x43c30000;
  afStack_28[1] = -38.0;
  ui_element_set_rect((ui_element_t *)&DAT_00488014,124.0,30.0,afStack_28);
  _DAT_00487f24 = &LAB_00447390;
  _DAT_00487f20 = 0x1f;
  iVar7 = 5;
  pcVar1 = (char *)(*grim_interface_ptr->vtable->grim_get_config_var)((uint *)afStack_28,100);
  if (*pcVar1 != '\0') {
    puVar3 = &ui_menu_item_element;
    puVar12 = &DAT_0048855c;
    for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar12 = *(undefined4 *)puVar3;
      puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
      puVar12 = puVar12 + 1;
    }
    _DAT_00488538 = 0xc2700000;
    _DAT_0048853c = 0x43e10000;
    fStack_30 = 270.0;
    fStack_2c = -38.0;
    ui_element_set_rect((ui_element_t *)&DAT_00488644,124.0,30.0,&fStack_30);
    _DAT_00488550 = 0x30;
    _DAT_00488554 = &LAB_0044fca0;
    iVar7 = 6;
  }
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_00488874;
  for (iVar8 = 0x3a; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  fStack_30 = 270.0;
  _DAT_00488850 = 0xc2700000;
  _DAT_00488854 = (float)(iVar7 * 0x3c + 0x96);
  fStack_2c = -38.0;
  ui_element_set_rect((ui_element_t *)&DAT_0048895c,124.0,30.0,&fStack_30);
  _DAT_0048886c = ui_menu_main_click_quit;
  _DAT_00488868 = 0x10;
  iVar8 = 2;
  iVar7 = 0;
  do {
    iVar15 = iVar7;
    if ((iVar8 == 2) && (iVar2 = game_is_full_version(), (char)iVar2 != '\0')) {
      iVar7 = 4;
      iVar15 = 4;
    }
    pcVar1 = (char *)(*grim_interface_ptr->vtable->grim_get_config_var)(local_20,100);
    if (*pcVar1 == '\0') {
      if (iVar8 == 6) {
        iVar7 = 6;
        iVar15 = 6;
      }
      (&ui_element_table_end)[iVar8]->counter_id = DAT_0048f7f4;
      puVar3 = (&ui_element_table_end)[iVar8];
      puVar3->_pad4[0x14] = '\0';
      puVar3->_pad4[0x15] = '\0';
      puVar3->_pad4[0x16] = '\0';
      puVar3->_pad4[0x17] = '\0';
      *(float *)(puVar3->_pad4 + 0x18) = (float)iVar15 * 0.125;
      puVar3 = (&ui_element_table_end)[iVar8];
      puVar3->_pad4[0x30] = '\0';
      puVar3->_pad4[0x31] = '\0';
      puVar3->_pad4[0x32] = 0x80;
      puVar3->_pad4[0x33] = '?';
      *(float *)(puVar3->_pad4 + 0x34) = (float)iVar15 * 0.125;
      puVar3 = (&ui_element_table_end)[iVar8];
      puVar3->_pad4[0x4c] = '\0';
      puVar3->_pad4[0x4d] = '\0';
      puVar3->_pad4[0x4e] = 0x80;
      puVar3->_pad4[0x4f] = '?';
      fVar9 = (float)(iVar7 + 1) * 0.125;
      *(float *)(puVar3->_pad4 + 0x50) = fVar9;
      puVar3 = (&ui_element_table_end)[iVar8];
      puVar3->_pad4[0x68] = '\0';
      puVar3->_pad4[0x69] = '\0';
      puVar3->_pad4[0x6a] = '\0';
      puVar3->_pad4[0x6b] = '\0';
    }
    else {
      (&ui_element_table_end)[iVar8]->counter_id = DAT_0048f7f4;
      puVar3 = (&ui_element_table_end)[iVar8];
      puVar3->_pad4[0x14] = '\0';
      puVar3->_pad4[0x15] = '\0';
      puVar3->_pad4[0x16] = '\0';
      puVar3->_pad4[0x17] = '\0';
      fStack_30 = 0.0;
      *(float *)(puVar3->_pad4 + 0x18) = (float)iVar15 * 0.125;
      puVar3 = (&ui_element_table_end)[iVar8];
      puVar3->_pad4[0x30] = '\0';
      puVar3->_pad4[0x31] = '\0';
      puVar3->_pad4[0x32] = 0x80;
      puVar3->_pad4[0x33] = '?';
      *(float *)(puVar3->_pad4 + 0x34) = (float)iVar15 * 0.125;
      puVar3 = (&ui_element_table_end)[iVar8];
      puVar3->_pad4[0x4c] = '\0';
      puVar3->_pad4[0x4d] = '\0';
      puVar3->_pad4[0x4e] = 0x80;
      puVar3->_pad4[0x4f] = '?';
      fVar9 = (float)(iVar7 + 1) * 0.125;
      *(float *)(puVar3->_pad4 + 0x50) = fVar9;
      puVar3 = (&ui_element_table_end)[iVar8];
      puVar3->_pad4[0x68] = '\0';
      puVar3->_pad4[0x69] = '\0';
      puVar3->_pad4[0x6a] = '\0';
      puVar3->_pad4[0x6b] = '\0';
      fStack_2c = fVar9;
    }
    *(float *)(puVar3->_pad4 + 0x6c) = fVar9;
    if ((iVar8 == 2) && (iVar15 = game_is_full_version(), (char)iVar15 != '\0')) {
      iVar7 = 0;
    }
    iVar15 = iVar7 + 1;
    if (iVar15 == 4) {
      iVar15 = iVar7 + 2;
    }
    iVar8 = iVar8 + 1;
    iVar7 = iVar15;
  } while (iVar8 < 8);
  if (config_blob.screen_width < 0x281) {
    iVar7 = 0;
    do {
      pfVar6 = (float *)((int)ui_element_table_end->quad0 + iVar7);
      *pfVar6 = *(float *)((int)ui_element_table_end->quad0 + iVar7) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      puVar11 = ui_element_table_end->_pad5 + iVar7 + 4;
      *(float *)puVar11 = *(float *)(ui_element_table_end->_pad5 + iVar7 + 4) * 0.8;
      *(float *)(puVar11 + 4) = *(float *)(puVar11 + 4) * 0.8;
      puVar11 = ui_element_table_end->_pad4 + iVar7;
      iVar8 = iVar7 + 0x1c;
      *(float *)puVar11 = *(float *)(ui_element_table_end->_pad4 + iVar7) * 0.8;
      *(float *)(puVar11 + 4) = *(float *)(puVar11 + 4) * 0.8;
      *(float *)((int)ui_element_table_end->quad0 + iVar7) =
           *(float *)((int)ui_element_table_end->quad0 + iVar7) + 10.0;
      *(float *)(ui_element_table_end->_pad5 + iVar7 + 4) =
           *(float *)(ui_element_table_end->_pad5 + iVar7 + 4) + 10.0;
      *(float *)(ui_element_table_end->_pad4 + iVar7) =
           *(float *)(ui_element_table_end->_pad4 + iVar7) + 10.0;
      *(float *)(DAT_0048f16c + iVar7 + 0x40) = *(float *)(DAT_0048f16c + iVar7 + 0x40) - 14.0;
      *(float *)(DAT_0048f16c + iVar7 + 0x210) = *(float *)(DAT_0048f16c + iVar7 + 0x210) - 14.0;
      *(float *)(DAT_0048f16c + iVar7 + 0x128) = *(float *)(DAT_0048f16c + iVar7 + 0x128) - 14.0;
      iVar7 = iVar8;
    } while (iVar8 < 0x70);
  }
  else if ((800 < config_blob.screen_width) && (config_blob.screen_width < 0x401)) {
    iVar7 = 0;
    do {
      pfVar6 = (float *)((int)ui_element_table_end->quad0 + iVar7);
      *pfVar6 = *(float *)((int)ui_element_table_end->quad0 + iVar7) * 1.2;
      pfVar6[1] = pfVar6[1] * 1.2;
      puVar11 = ui_element_table_end->_pad5 + iVar7 + 4;
      *(float *)puVar11 = *(float *)(ui_element_table_end->_pad5 + iVar7 + 4) * 1.2;
      *(float *)(puVar11 + 4) = *(float *)(puVar11 + 4) * 1.2;
      puVar11 = ui_element_table_end->_pad4 + iVar7;
      iVar8 = iVar7 + 0x1c;
      *(float *)puVar11 = *(float *)(ui_element_table_end->_pad4 + iVar7) * 1.2;
      *(float *)(puVar11 + 4) = *(float *)(puVar11 + 4) * 1.2;
      *(float *)((int)ui_element_table_end->quad0 + iVar7) =
           *(float *)((int)ui_element_table_end->quad0 + iVar7) + 10.0;
      *(float *)(ui_element_table_end->_pad5 + iVar7 + 4) =
           *(float *)(ui_element_table_end->_pad5 + iVar7 + 4) + 10.0;
      *(float *)(ui_element_table_end->_pad4 + iVar7) =
           *(float *)(ui_element_table_end->_pad4 + iVar7) + 10.0;
      iVar7 = iVar8;
    } while (iVar8 < 0x70);
  }
  iVar8 = 100;
  piVar4 = (int *)&DAT_0048f16c;
  iVar7 = -0x14;
  do {
    *(int *)(*piVar4 + 0x14) = *(int *)(*piVar4 + 0x14) + iVar8;
    *(int *)(*piVar4 + 0x10) = *(int *)(*piVar4 + 0x10) + iVar8;
    if (0 < iVar7) {
      *(float *)(*piVar4 + 0x18) = *(float *)(*piVar4 + 0x18) - (float)iVar7;
    }
    iVar7 = iVar7 + 0x14;
    iVar8 = iVar8 + 100;
    piVar4 = piVar4 + 1;
  } while (iVar7 < 0x65);
  iVar7 = game_is_full_version();
  if ((char)iVar7 != '\0') {
    DAT_00486faa = 1;
  }
  puVar11 = ui_menu_item_element._pad3;
  puVar12 = &DAT_00488b8c;
  for (iVar7 = 0x3a; puVar11 = puVar11 + 4, iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar12 = puVar12 + 1;
  }
  _DAT_00488b78 = _DAT_00488b70 + 280.0;
  _DAT_00488b7c = _DAT_00488b74 + 180.0;
  _DAT_00488b68 = 0xc2340000;
  _DAT_00488b6c = 0x43520000;
  _DAT_00488b84 = 0;
  _DAT_00488b88 = &LAB_004475d0;
  _DAT_00488b54 = 1;
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_00488ea4;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_00488e80 = 0xc25c0000;
  _DAT_00488e84 = 0x43d70000;
  fStack_30 = 270.0;
  fStack_2c = -38.0;
  ui_element_set_rect((ui_element_t *)&DAT_00488f8c,124.0,30.0,&fStack_30);
  _DAT_0048906c = DAT_0048f7f4;
  _DAT_00488fa0 = 0;
  _DAT_00488fa4 = 0x3f600000;
  _DAT_00488fc0 = 0x3f600000;
  _DAT_00488fbc = 0x3f800000;
  _DAT_00488fd8 = 0x3f800000;
  _DAT_00488ff4 = 0;
  _DAT_00488fdc = 0x3f800000;
  _DAT_00488ff8 = 0x3f800000;
  _DAT_00488e9c = FUN_00447420;
  _DAT_00488e6c = 1;
  _DAT_00488e98 = 0x30;
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_0048b9f4;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_0048b9d0 = 0xc2700000;
  _DAT_0048b9d4 = 0x43520000;
  puVar12 = &DAT_00487cfc;
  puVar13 = &DAT_0048badc;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  DAT_0048b9c8 = DAT_0048b9c8 + 100;
  DAT_0048b9cc = DAT_0048b9cc + 100;
  _DAT_0048b9ec = ui_menu_main_click_options;
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_0048bd0c;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_0048bce8 = 0xc2a00000;
  _DAT_0048bcec = 0x43870000;
  puVar12 = &DAT_0048895c;
  puVar13 = &DAT_0048bdf4;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  _DAT_0048bd04 = &LAB_004474e0;
  DAT_0048bce0 = DAT_0048bce0 + 200;
  DAT_0048bce4 = DAT_0048bce4 + 200;
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_0048c024;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_0048c000 = 0xc2c80000;
  _DAT_0048c004 = 0x43a50000;
  puVar12 = &DAT_00488f8c;
  puVar13 = &DAT_0048c10c;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  DAT_0048bff8 = DAT_0048bff8 + 300;
  DAT_0048bffc = DAT_0048bffc + 300;
  _DAT_0048c318 = 0xc32f0000;
  _DAT_0048c31c = 0x42340000;
  _DAT_0048c01c = &LAB_00447490;
  _DAT_0048c018 = 0x30;
  _DAT_0048c304 = 1;
  puVar11 = ui_menu_item_element._pad4 + 0xac;
  puVar12 = &DAT_0048c654;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar11 = puVar11 + 4;
    puVar12 = puVar12 + 1;
  }
  _DAT_0048c630 = 0xc2340000;
  DAT_0048c628 = DAT_0048c628 + 100;
  _DAT_0048c634 = 0x42dc0000;
  DAT_0048c62c = DAT_0048c62c + 100;
  _DAT_0048919c = 0x43110000;
  _DAT_0048c61c = 1;
  _DAT_00489198 = 0xc2700000;
  _DAT_00489184 = 1;
  puVar11 = ui_menu_item_element._pad5 + 0xb0;
  puVar12 = &DAT_004894d4;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar11 = puVar11 + 4;
    puVar12 = puVar12 + 1;
  }
  _DAT_004894b0 = 0xc2340000;
  _DAT_004894b4 = 0x43520000;
  pfVar6 = (float *)&DAT_004895bc;
  do {
    pfVar5 = pfVar6 + 7;
    *pfVar6 = *pfVar6 + 10.0;
    pfVar6[1] = pfVar6[1] + 10.0;
    pfVar6 = pfVar5;
  } while ((int)pfVar5 < 0x48962c);
  _DAT_004894d0 = &LAB_0044ed80;
  _DAT_0048949c = 1;
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_004897ec;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_004897cc = 0x43e70000;
  _DAT_004897c8 = 0xc25c0000;
  puVar12 = &DAT_00488f8c;
  puVar13 = &DAT_004898d4;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  _DAT_004897e4 = FUN_00447420;
  _DAT_0048c948 = 0xc32f0000;
  _DAT_004897b4 = 1;
  _DAT_004897e0 = 0x30;
  _DAT_0048c94c = 0x42340000;
  _DAT_0048c934 = 1;
  puVar11 = ui_menu_item_element._pad4 + 0xac;
  puVar12 = &DAT_0048cc84;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar11 = puVar11 + 4;
    puVar12 = puVar12 + 1;
  }
  _DAT_0048cc64 = 0x42dc0000;
  _DAT_0048cc60 = 0xc2340000;
  DAT_0048cc5c = DAT_0048cc5c + 100;
  DAT_0048cc58 = DAT_0048cc58 + 100;
  _DAT_0048cf78 = 0xc3340000;
  _DAT_0048cf7c = 0x43070000;
  puVar11 = ui_menu_item_element._pad3;
  _DAT_0048cc4c = 1;
  _DAT_0048cf64 = 1;
  puVar12 = &DAT_0048d2b4;
  for (iVar7 = 0x3a; iVar8 = config_blob.screen_width, puVar11 = puVar11 + 4, iVar7 != 0;
      iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar12 = puVar12 + 1;
  }
  _DAT_0048d290 = 0xc3250000;
  if (config_blob.screen_width < 0x281) {
    _DAT_0048d290 = 0xc3370000;
  }
  DAT_0048d294 = 0x43480000;
  _DAT_0048d2b0 = &LAB_00448cd0;
  _DAT_0048d27c = 1;
  puVar3 = &ui_menu_item_element;
  puVar12 = &DAT_0048d5cc;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_0048d5a8 = 0xc31b0000;
  _DAT_0048d5ac = 0x43d20000;
  puVar12 = &DAT_00488f8c;
  puVar13 = &DAT_0048d6b4;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  _DAT_0048d8c0 = 0xc32f0000;
  _DAT_0048d8c4 = 0x42340000;
  _DAT_0048d5c4 = ui_menu_main_click_options;
  _DAT_0048d594 = 0;
  _DAT_0048d5c0 = 0x30;
  _DAT_0048d8ac = 1;
  puVar11 = ui_menu_item_element._pad4 + 0xac;
  puVar12 = &DAT_0048dbfc;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar11 = puVar11 + 4;
    puVar12 = puVar12 + 1;
  }
  _DAT_0048dbd8 = 0xc2340000;
  DAT_0048dbd0 = DAT_0048dbd0 + 100;
  _DAT_0048dbdc = 0x42dc0000;
  DAT_0048dbd4 = DAT_0048dbd4 + 100;
  _DAT_0048def4 = 0x42f40000;
  _DAT_0048dbc4 = 1;
  _DAT_0048def0 = 0xc3070000;
  _DAT_0048dedc = 1;
  puVar11 = ui_menu_item_element._pad4 + 0xac;
  puVar12 = &DAT_0048e22c;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar11 = puVar11 + 4;
    puVar12 = puVar12 + 1;
  }
  _DAT_0048e20c = 0x43390000;
  _DAT_0048e208 = 0xc0a00000;
  _DAT_0048e524 = 0x42f40000;
  _DAT_0048e228 = &LAB_00447d40;
  _DAT_0048e1f4 = 1;
  _DAT_0048e520 = 0xc3070000;
  _DAT_0048e50c = 1;
  puVar11 = ui_menu_item_element._pad4 + 0xac;
  puVar12 = &DAT_0048e85c;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar11 = puVar11 + 4;
    puVar12 = puVar12 + 1;
  }
  _DAT_0048e83c = 0x43390000;
  _DAT_0048e838 = 0xc0a00000;
  _DAT_0048e824 = 1;
  puVar11 = ui_menu_item_element._pad3;
  _DAT_0048a110 = (float)(iVar8 + -0x15e);
  puVar12 = &DAT_0048a134;
  for (iVar7 = 0x3a; puVar11 = puVar11 + 4, iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar12 = puVar12 + 1;
  }
  _DAT_0048a114 = 0x43480000;
  if (iVar8 < 0x321) {
    if (iVar8 < 0x281) {
      _DAT_0048a110 = _DAT_0048a110 + 10.0;
    }
    else {
      _DAT_0048a110 = _DAT_0048a110 - 30.0;
    }
  }
  else {
    _DAT_0048a110 = _DAT_0048a110 - 65.0;
  }
  _DAT_0048a0fc = 1;
  DAT_0048a40c = 1;
  _DAT_00489ae4 = 0x42f40000;
  _DAT_00489ae0 = 0xc3250000;
  if (iVar8 < 0x281) {
    _DAT_00489ae0 = 0xc3570000;
  }
  _DAT_00489acc = 1;
  puVar11 = ui_menu_item_element._pad4 + 0xac;
  puVar12 = &DAT_00489e1c;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar11;
    puVar11 = puVar11 + 4;
    puVar12 = puVar12 + 1;
  }
  fStack_30 = -60.0;
  fStack_2c = 185.0;
  _DAT_00489dfc = 0x43390000;
  _DAT_00489df8 = 0xc20c0000;
  if (iVar8 < 0x281) {
    _DAT_00489df8 = 0xc2aa0000;
  }
  DAT_00489de4 = 1;
  DAT_0048eb48 = 500;
  piVar4 = (int *)&DAT_0048f16c;
  iVar7 = -0xb;
  do {
    if (iVar8 < 0x281) {
      fVar9 = (float)iVar7;
      iVar15 = 0;
      do {
        pfVar6 = (float *)(*piVar4 + 0x3c + iVar15);
        *pfVar6 = *(float *)(*piVar4 + 0x3c + iVar15) * 0.9;
        pfVar6[1] = pfVar6[1] * 0.9;
        pfVar6 = (float *)(*piVar4 + 0x20c + iVar15);
        *pfVar6 = *(float *)(*piVar4 + 0x20c + iVar15) * 0.9;
        pfVar6[1] = pfVar6[1] * 0.9;
        pfVar6 = (float *)(*piVar4 + 0x124 + iVar15);
        *pfVar6 = *(float *)(*piVar4 + 0x124 + iVar15) * 0.9;
        pfVar6[1] = pfVar6[1] * 0.9;
        *(float *)(*piVar4 + 0x40 + iVar15) = *(float *)(*piVar4 + 0x40 + iVar15) - fVar9;
        *(float *)(*piVar4 + 0x210 + iVar15) = *(float *)(*piVar4 + 0x210 + iVar15) - fVar9;
        pfVar6 = (float *)(*piVar4 + 0x128 + iVar15);
        pfVar5 = (float *)(*piVar4 + 0x128 + iVar15);
        iVar15 = iVar15 + 0x1c;
        *pfVar5 = *pfVar6 - fVar9;
        iVar8 = config_blob.screen_width;
      } while (iVar15 < 0x70);
    }
    iVar7 = iVar7 + 0xb;
    piVar4 = piVar4 + 1;
  } while (iVar7 < 0x38);
  piVar4 = (int *)&DAT_0048f1c0;
  iVar7 = -5;
  iVar15 = -0xb;
  do {
    if (iVar8 < 0x281) {
      fVar9 = (float)iVar15;
      iVar2 = 0;
      do {
        pfVar6 = (float *)(*piVar4 + 0x3c + iVar2);
        *pfVar6 = *(float *)(*piVar4 + 0x3c + iVar2) * 0.8;
        pfVar6[1] = pfVar6[1] * 0.8;
        pfVar6 = (float *)(*piVar4 + 0x20c + iVar2);
        *pfVar6 = *(float *)(*piVar4 + 0x20c + iVar2) * 0.8;
        pfVar6[1] = pfVar6[1] * 0.8;
        pfVar6 = (float *)(*piVar4 + 0x124 + iVar2);
        *pfVar6 = *(float *)(*piVar4 + 0x124 + iVar2) * 0.8;
        pfVar6[1] = pfVar6[1] * 0.8;
        *(float *)(*piVar4 + 0x40 + iVar2) = *(float *)(*piVar4 + 0x40 + iVar2) - fVar9;
        *(float *)(*piVar4 + 0x210 + iVar2) = *(float *)(*piVar4 + 0x210 + iVar2) - fVar9;
        pfVar6 = (float *)(*piVar4 + 0x128 + iVar2);
        pfVar5 = (float *)(*piVar4 + 0x128 + iVar2);
        iVar2 = iVar2 + 0x1c;
        *pfVar5 = *pfVar6 - fVar9;
        iVar8 = config_blob.screen_width;
      } while (iVar2 < 0x70);
    }
    else if (iVar8 < 0x321) {
      fVar9 = (float)iVar7;
      iVar2 = 0;
      do {
        pfVar6 = (float *)(*piVar4 + 0x3c + iVar2);
        *pfVar6 = *(float *)(*piVar4 + 0x3c + iVar2) * 0.9;
        pfVar6[1] = pfVar6[1] * 0.9;
        pfVar6 = (float *)(*piVar4 + 0x20c + iVar2);
        *pfVar6 = *(float *)(*piVar4 + 0x20c + iVar2) * 0.9;
        pfVar6[1] = pfVar6[1] * 0.9;
        pfVar6 = (float *)(*piVar4 + 0x124 + iVar2);
        *pfVar6 = *(float *)(*piVar4 + 0x124 + iVar2) * 0.9;
        pfVar6[1] = pfVar6[1] * 0.9;
        *(float *)(*piVar4 + 0x40 + iVar2) = *(float *)(*piVar4 + 0x40 + iVar2) - fVar9;
        *(float *)(*piVar4 + 0x210 + iVar2) = *(float *)(*piVar4 + 0x210 + iVar2) - fVar9;
        pfVar6 = (float *)(*piVar4 + 0x128 + iVar2);
        pfVar5 = (float *)(*piVar4 + 0x128 + iVar2);
        iVar2 = iVar2 + 0x1c;
        *pfVar5 = *pfVar6 - fVar9;
        iVar8 = config_blob.screen_width;
      } while (iVar2 < 0x70);
    }
    iVar15 = iVar15 + 0xb;
    iVar7 = iVar7 + 5;
    piVar4 = piVar4 + 1;
  } while (iVar15 < 0x17);
  if (iVar8 < 0x281) {
    iVar7 = 0;
    do {
      pfVar6 = (float *)(ui_menu_layout_c + iVar7 + 0x3c);
      *pfVar6 = *(float *)(ui_menu_layout_c + iVar7 + 0x3c) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      pfVar6 = (float *)(ui_menu_layout_c + iVar7 + 0x20c);
      *pfVar6 = *(float *)(ui_menu_layout_c + iVar7 + 0x20c) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      pfVar6 = (float *)(ui_menu_layout_c + iVar7 + 0x124);
      iVar15 = iVar7 + 0x1c;
      *pfVar6 = *(float *)(ui_menu_layout_c + iVar7 + 0x124) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      *(float *)(ui_menu_layout_c + iVar7 + 0x40) =
           *(float *)(ui_menu_layout_c + iVar7 + 0x40) - 11.0;
      *(float *)(ui_menu_layout_c + iVar7 + 0x210) =
           *(float *)(ui_menu_layout_c + iVar7 + 0x210) - 11.0;
      *(float *)(ui_menu_layout_c + iVar7 + 0x128) =
           *(float *)(ui_menu_layout_c + iVar7 + 0x128) - 11.0;
      iVar7 = iVar15;
      iVar8 = config_blob.screen_width;
    } while (iVar15 < 0x70);
  }
  else if (iVar8 < 0x321) {
    iVar7 = 0;
    do {
      pfVar6 = (float *)(ui_menu_layout_c + iVar7 + 0x3c);
      *pfVar6 = *(float *)(ui_menu_layout_c + iVar7 + 0x3c) * 0.9;
      pfVar6[1] = pfVar6[1] * 0.9;
      pfVar6 = (float *)(ui_menu_layout_c + iVar7 + 0x20c);
      *pfVar6 = *(float *)(ui_menu_layout_c + iVar7 + 0x20c) * 0.9;
      pfVar6[1] = pfVar6[1] * 0.9;
      pfVar6 = (float *)(ui_menu_layout_c + iVar7 + 0x124);
      iVar15 = iVar7 + 0x1c;
      *pfVar6 = *(float *)(ui_menu_layout_c + iVar7 + 0x124) * 0.9;
      pfVar6[1] = pfVar6[1] * 0.9;
      *(float *)(ui_menu_layout_c + iVar7 + 0x40) =
           *(float *)(ui_menu_layout_c + iVar7 + 0x40) - 3.0;
      *(float *)(ui_menu_layout_c + iVar7 + 0x210) =
           *(float *)(ui_menu_layout_c + iVar7 + 0x210) - 3.0;
      *(float *)(ui_menu_layout_c + iVar7 + 0x128) =
           *(float *)(ui_menu_layout_c + iVar7 + 0x128) - 3.0;
      iVar7 = iVar15;
      iVar8 = config_blob.screen_width;
    } while (iVar15 < 0x70);
  }
  if (iVar8 < 0x281) {
    iVar7 = 0;
    do {
      pfVar6 = (float *)(ui_menu_layout_a + iVar7 + 0x3c);
      *pfVar6 = *(float *)(ui_menu_layout_a + iVar7 + 0x3c) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      pfVar6 = (float *)(ui_menu_layout_a + iVar7 + 0x20c);
      *pfVar6 = *(float *)(ui_menu_layout_a + iVar7 + 0x20c) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      pfVar6 = (float *)(ui_menu_layout_a + iVar7 + 0x124);
      iVar15 = iVar7 + 0x1c;
      *pfVar6 = *(float *)(ui_menu_layout_a + iVar7 + 0x124) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      *(float *)(ui_menu_layout_a + iVar7 + 0x40) =
           *(float *)(ui_menu_layout_a + iVar7 + 0x40) - 11.0;
      *(float *)(ui_menu_layout_a + iVar7 + 0x210) =
           *(float *)(ui_menu_layout_a + iVar7 + 0x210) - 11.0;
      *(float *)(ui_menu_layout_a + iVar7 + 0x128) =
           *(float *)(ui_menu_layout_a + iVar7 + 0x128) - 11.0;
      iVar7 = iVar15;
      iVar8 = config_blob.screen_width;
    } while (iVar15 < 0x70);
  }
  else if (iVar8 < 0x321) {
    iVar7 = 0;
    do {
      pfVar6 = (float *)(ui_menu_layout_a + iVar7 + 0x3c);
      *pfVar6 = *(float *)(ui_menu_layout_a + iVar7 + 0x3c) * 0.9;
      pfVar6[1] = pfVar6[1] * 0.9;
      pfVar6 = (float *)(ui_menu_layout_a + iVar7 + 0x20c);
      *pfVar6 = *(float *)(ui_menu_layout_a + iVar7 + 0x20c) * 0.9;
      pfVar6[1] = pfVar6[1] * 0.9;
      pfVar6 = (float *)(ui_menu_layout_a + iVar7 + 0x124);
      iVar15 = iVar7 + 0x1c;
      *pfVar6 = *(float *)(ui_menu_layout_a + iVar7 + 0x124) * 0.9;
      pfVar6[1] = pfVar6[1] * 0.9;
      *(float *)(ui_menu_layout_a + iVar7 + 0x40) =
           *(float *)(ui_menu_layout_a + iVar7 + 0x40) - 3.0;
      *(float *)(ui_menu_layout_a + iVar7 + 0x210) =
           *(float *)(ui_menu_layout_a + iVar7 + 0x210) - 3.0;
      *(float *)(ui_menu_layout_a + iVar7 + 0x128) =
           *(float *)(ui_menu_layout_a + iVar7 + 0x128) - 3.0;
      iVar7 = iVar15;
      iVar8 = config_blob.screen_width;
    } while (iVar15 < 0x70);
  }
  if (iVar8 < 0x281) {
    iVar7 = 0;
    do {
      pfVar6 = (float *)(ui_menu_layout_b + iVar7 + 0x3c);
      *pfVar6 = *(float *)(ui_menu_layout_b + iVar7 + 0x3c) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      pfVar6 = (float *)(ui_menu_layout_b + iVar7 + 0x20c);
      *pfVar6 = *(float *)(ui_menu_layout_b + iVar7 + 0x20c) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      pfVar6 = (float *)(ui_menu_layout_b + iVar7 + 0x124);
      iVar8 = iVar7 + 0x1c;
      *pfVar6 = *(float *)(ui_menu_layout_b + iVar7 + 0x124) * 0.8;
      pfVar6[1] = pfVar6[1] * 0.8;
      *(float *)(ui_menu_layout_b + iVar7 + 0x40) =
           *(float *)(ui_menu_layout_b + iVar7 + 0x40) - 11.0;
      *(float *)(ui_menu_layout_b + iVar7 + 0x210) =
           *(float *)(ui_menu_layout_b + iVar7 + 0x210) - 11.0;
      *(float *)(ui_menu_layout_b + iVar7 + 0x128) =
           *(float *)(ui_menu_layout_b + iVar7 + 0x128) - 11.0;
      iVar7 = iVar8;
    } while (iVar8 < 0x70);
  }
  else if (iVar8 < 0x321) {
    iVar7 = 0;
    do {
      pfVar6 = (float *)(ui_menu_layout_b + iVar7 + 0x3c);
      *pfVar6 = *(float *)(ui_menu_layout_b + iVar7 + 0x3c) * 0.9;
      pfVar6[1] = pfVar6[1] * 0.9;
      pfVar6 = (float *)(ui_menu_layout_b + iVar7 + 0x20c);
      *pfVar6 = *(float *)(ui_menu_layout_b + iVar7 + 0x20c) * 0.9;
      pfVar6[1] = pfVar6[1] * 0.9;
      pfVar6 = (float *)(ui_menu_layout_b + iVar7 + 0x124);
      iVar8 = iVar7 + 0x1c;
      *pfVar6 = *(float *)(ui_menu_layout_b + iVar7 + 0x124) * 0.9;
      pfVar6[1] = pfVar6[1] * 0.9;
      *(float *)(ui_menu_layout_b + iVar7 + 0x40) =
           *(float *)(ui_menu_layout_b + iVar7 + 0x40) - 3.0;
      *(float *)(ui_menu_layout_b + iVar7 + 0x210) =
           *(float *)(ui_menu_layout_b + iVar7 + 0x210) - 3.0;
      *(float *)(ui_menu_layout_b + iVar7 + 0x128) =
           *(float *)(ui_menu_layout_b + iVar7 + 0x128) - 3.0;
      iVar7 = iVar8;
    } while (iVar8 < 0x70);
  }
  FUN_0044faa0(&DAT_0048f20c);
  _DAT_0048f240 = FUN_00446140;
  puVar3 = &ui_menu_item_element;
  puVar12 = &perk_prompt_bounds_min_x;
  for (iVar7 = 0x3a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = *(undefined4 *)puVar3;
    puVar3 = (ui_element_t *)(puVar3->_pad0 + 2);
    puVar12 = puVar12 + 1;
  }
  _DAT_0048f25c = 0x3f800000;
  _DAT_0048f278 = 0;
  _DAT_0048f2b0 = 0x3f800000;
  _DAT_0048f294 = 0;
  ui_element_load((ui_element_t *)&DAT_0048f330,s_ui_ui_textLevelUp_jaz_004792a0);
  fStack_30 = -230.0;
  fStack_2c = -27.0;
  ui_element_set_rect((ui_element_t *)&DAT_0048f330,75.0,25.0,&fStack_30);
  pfVar6 = (float *)&DAT_0048f334;
  do {
    pfVar5 = pfVar6 + 7;
    pfVar6[-0x3b] = pfVar6[-0x3b] - 300.0;
    pfVar6[-0x3b] = pfVar6[-0x3b] * 0.75;
    pfVar6[-0x3a] = pfVar6[-0x3a] * 0.75;
    pfVar6[-1] = pfVar6[-1] * 0.85;
    *pfVar6 = *pfVar6 * 0.85;
    pfVar6[-1] = pfVar6[-1] - 46.0;
    *pfVar6 = *pfVar6 - 4.0;
    pfVar6 = pfVar5;
  } while ((int)pfVar5 < 0x48f3a4);
  if (config_blob.screen_width == 0x280) {
    fStack_30 = 690.0;
    fStack_2c = 80.0;
    _perk_prompt_origin_y = 0x42a00000;
  }
  else {
    fStack_2c = 40.0;
    fStack_30 = (float)(config_blob.screen_width + 0x32);
    _perk_prompt_origin_y = 0x42200000;
  }
  piVar4 = (int *)&DAT_0048f16c;
  _perk_prompt_origin_x = fStack_30;
  do {
    iVar7 = *piVar4;
    piVar4 = piVar4 + 1;
    *(float *)(iVar7 + 0x1c) =
         ((float)config_blob.screen_width * 0.0015625 * 150.0 - 150.0) + *(float *)(iVar7 + 0x1c);
    iVar7 = config_blob.screen_width;
  } while ((int)piVar4 < 0x48f20c);
  _DAT_0048ee68 = (float)(config_blob.screen_width + -0x15e);
  puVar12 = &DAT_00489de0;
  puVar13 = &DAT_0048ee50;
  for (iVar8 = 0xc6; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  _DAT_0048ee6c = 0x43480000;
  if (iVar7 < 0x281) {
    _DAT_0048ee68 = _DAT_0048ee68 + 80.0;
    _DAT_0048ee6c = 0x433a0000;
  }
  DAT_0048ee54 = 1;
  DAT_0048f164 = 1;
  ppuVar10 = &ui_element_table_end;
  do {
    ui_element_layout_calc((float)*ppuVar10);
    ppuVar10 = ppuVar10 + 1;
  } while ((int)ppuVar10 < 0x48f20c);
  return;
}



