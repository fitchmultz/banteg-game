/* ui_profile_menu_update @ 004443c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_4443c0(float* arg1, char arg2) */

int __cdecl ui_profile_menu_update(float *arg1,char arg2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint extraout_EAX;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char (*pacVar9) [27];
  char (*pacVar10) [27];
  int local_c;
  float local_8;
  float local_4;
  
  if ((DAT_004cccd8 & 1) == 0) {
    DAT_004cccd8 = DAT_004cccd8 | 1;
    _DAT_004d0f38 = 0x3f800000;
    _DAT_004d0f28 = &DAT_004ccb18;
    _DAT_004d0f2c = 0;
    _DAT_004d0f30 = 0x1b;
    _DAT_004d0f34 = 0x60;
    crt_atexit(&DAT_00444800);
  }
  local_c = 0;
  if (0 < (int)config_blob.reserved0._132_4_) {
    piVar4 = &DAT_004ccb5c;
    iVar2 = 0x4803f0;
    local_c._0_1_ = config_blob.reserved0[0x84];
    local_c._1_1_ = config_blob.reserved0[0x85];
    local_c._2_1_ = config_blob.reserved0[0x86];
    local_c._3_1_ = config_blob.reserved0[0x87];
    iVar7 = config_blob.reserved0._132_4_;
    do {
      *piVar4 = iVar2;
      iVar2 = iVar2 + 0x1b;
      piVar4 = piVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  pcVar3 = strdup_malloc(s_<add_new_named_list>_00478c6c);
  (&DAT_004ccb5c)[local_c] = pcVar3;
  if ((DAT_004cccd8 & 2) == 0) {
    DAT_004cccd8 = DAT_004cccd8 | 2;
    DAT_004ccc96 = 1;
    DAT_004ccca5 = 0;
    DAT_004ccca4 = 0;
    _DAT_004ccca0 = 0x3f800000;
    _DAT_004ccc9c = 0;
    _DAT_004ccc90 = (undefined *)0x0;
    DAT_004ccc94 = 0;
    DAT_004ccc95 = 0;
    _DAT_004ccc98 = 0;
    crt_atexit(&DAT_004447f0);
  }
  _DAT_004ccc90 = &DAT_00478c68;
  if ((DAT_004cccd8 & 4) == 0) {
    DAT_004cccd8 = DAT_004cccd8 | 4;
    DAT_004ccb06 = 1;
    DAT_004ccb15 = 0;
    DAT_004ccb14 = 0;
    _DAT_004ccb10 = 0x3f800000;
    _DAT_004ccb0c = 0;
    _DAT_004ccb00 = (char *)0x0;
    DAT_004ccb04 = 0;
    DAT_004ccb05 = 0;
    _DAT_004ccb08 = 0;
    crt_atexit(&DAT_004447e0);
  }
  _DAT_004ccb00 = s_Delete_00478c60;
  _DAT_004d0f34 = 0xae;
  if (DAT_004d1220 == '\0') {
    if ((DAT_004d121c != 0) || (config_blob.reserved0._128_4_ == 0)) goto LAB_004446ac;
    local_8 = *arg1;
    local_4 = arg1[1] + 22.0;
    iVar7 = ui_button_update(&local_8,(ui_button_t *)&DAT_004ccb00);
    if ((char)iVar7 == '\0') goto LAB_004446ac;
    uVar5 = 0xffffffff;
    pacVar9 = config_blob.saved_names + config_blob.reserved0._132_4_ + -1;
    do {
      pacVar10 = pacVar9;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pacVar10 = (char (*) [27])(*pacVar9 + 1);
      pcVar3 = *pacVar9;
      pacVar9 = pacVar10;
    } while (*pcVar3 != '\0');
    uVar5 = ~uVar5;
    pcVar3 = (char *)((int)pacVar10 - uVar5);
    pacVar9 = config_blob.saved_names + config_blob.reserved0._128_4_;
    config_blob.reserved0._132_4_ = config_blob.reserved0._132_4_ + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)*pacVar9 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pacVar9 = (char (*) [27])(*pacVar9 + 4);
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      (*pacVar9)[0] = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pacVar9 = (char (*) [27])(*pacVar9 + 1);
    }
    config_blob.reserved0[0x80] = '\0';
    config_blob.reserved0[0x81] = '\0';
    config_blob.reserved0[0x82] = '\0';
    config_blob.reserved0[0x83] = '\0';
  }
  else {
    local_8 = *arg1;
    local_4 = arg1[1] + 29.0;
    iVar7 = ui_text_input_update(&local_8,(int *)&DAT_004d0f28);
    if ((char)iVar7 == '\0') {
      local_8 = *arg1 + 180.0;
      local_4 = arg1[1] + 22.0;
      iVar7 = ui_button_update(&local_8,(ui_button_t *)&DAT_004ccc90);
      if ((char)iVar7 == '\0') goto LAB_004446ac;
    }
    uVar5 = 0xffffffff;
    pcVar3 = &DAT_004ccb18;
    do {
      pcVar8 = pcVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar3 = pcVar8 + -uVar5;
    pacVar9 = config_blob.saved_names + config_blob.reserved0._132_4_;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)*pacVar9 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pacVar9 = (char (*) [27])(*pacVar9 + 4);
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      (*pacVar9)[0] = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pacVar9 = (char (*) [27])(*pacVar9 + 1);
    }
    config_blob.reserved0[0x80] = config_blob.reserved0[0x84];
    config_blob.reserved0[0x81] = config_blob.reserved0[0x85];
    config_blob.reserved0[0x82] = config_blob.reserved0[0x86];
    config_blob.reserved0[0x83] = config_blob.reserved0[0x87];
    config_blob.reserved0._132_4_ = config_blob.reserved0._132_4_ + 1;
    if (7 < (int)config_blob.reserved0._132_4_) {
      uVar5 = 0xffffffff;
      pcVar3 = &DAT_004ccb18;
      do {
        pcVar8 = pcVar3;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar8 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar8;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar3 = pcVar8 + -uVar5;
      pacVar9 = config_blob.saved_names + 1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)*pacVar9 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pacVar9 = (char (*) [27])(*pacVar9 + 4);
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        (*pacVar9)[0] = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pacVar9 = (char (*) [27])(*pacVar9 + 1);
      }
      config_blob.reserved0._132_4_ = config_blob.reserved0._132_4_ + -1;
    }
    DAT_004ccb18 = 0;
    _DAT_004d0f2c = 0;
    DAT_004d1220 = '\0';
  }
  highscore_load_table();
LAB_004446ac:
  if ((DAT_004cccd8 & 8) == 0) {
    DAT_004cccd8 = DAT_004cccd8 | 8;
    DAT_004d0ee8 = 1;
    _DAT_004d0f00 = 0;
    DAT_004d0efc = 0;
    _DAT_004d0ef0 = 0;
    _DAT_004d0eec = 0;
    _DAT_004d0ef8 = 0;
    _DAT_004d0ef4 = (undefined4 *)0x0;
    crt_atexit(&DAT_004447d0);
  }
  _DAT_004d0ef8 = local_c + 1;
  _DAT_004d0ef4 = &DAT_004ccb5c;
  DAT_004d0ee8 = arg2;
  DAT_004d0ef0 = config_blob.reserved0[0x80];
  DAT_004d0ef0_1._0_1_ = config_blob.reserved0[0x81];
  DAT_004d0ef0_1._1_1_ = config_blob.reserved0[0x82];
  DAT_004d0ef0_1._2_1_ = config_blob.reserved0[0x83];
  iVar7 = ui_list_widget_update(arg1,&DAT_004d0ee8);
  if ((-2 < iVar7) &&
     ((iVar2 = input_primary_just_pressed(), (char)iVar2 != '\0' ||
      (iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c), (char)iVar2 != '\0')))) {
    DAT_004d121c = 1 - DAT_004d121c;
    if (-1 < iVar7) {
      config_blob.reserved0._128_4_ = iVar7;
      _DAT_004d0ef0 = iVar7;
      if (iVar7 != local_c) {
        highscore_load_table();
      }
      DAT_004d1221 = 1;
      DAT_004d1222 = 1;
    }
    DAT_004d1220 = iVar7 == local_c;
  }
  _DAT_004d0eec = DAT_004d121c;
  crt_free((void *)(&DAT_004ccb5c)[local_c]);
  return extraout_EAX & 0xffffff00;
}



