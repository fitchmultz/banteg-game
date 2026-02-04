/* ui_menu_assets_init @ 00419dd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* loads menu UI elements and seeds layout copies */

void ui_menu_assets_init(void)

{
  uchar *puVar1;
  int iVar2;
  uchar *puVar3;
  float local_8 [2];
  
  ui_element_load((ui_element_t *)&DAT_0048fac0,s_ui_ui_signCrimson_jaz_004737f4);
  local_8[0] = -577.44;
  local_8[1] = -62.0;
  ui_element_set_rect((ui_element_t *)&DAT_0048fac0,573.44,143.36,local_8);
  ui_element_load(&ui_menu_item_element,s_ui_ui_menuItem_jaz_004737e0);
  local_8[0] = -72.0;
  local_8[1] = -60.0;
  ui_element_set_rect(&ui_menu_item_element,512.0,64.0,local_8);
  ui_element_load((ui_element_t *)(ui_menu_item_element._pad3 + 4),s_ui_ui_menuPanel_jaz_004737cc);
  local_8[0] = 20.0;
  local_8[1] = -82.0;
  ui_element_set_rect((ui_element_t *)(ui_menu_item_element._pad3 + 4),512.0,256.0,local_8);
  puVar1 = ui_menu_item_element._pad3;
  puVar3 = ui_menu_item_element._pad4 + 0xac;
  for (iVar2 = 0x3a; puVar1 = puVar1 + 4, iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)puVar3 = *(undefined4 *)puVar1;
    puVar3 = puVar3 + 4;
  }
  ui_menu_item_element._pad5[0xac] = '\b';
  ui_menu_item_element._pad5[0xad] = '\0';
  ui_menu_item_element._pad5[0xae] = '\0';
  ui_menu_item_element._pad5[0xaf] = '\0';
  puVar1 = ui_menu_item_element._pad5 + 0x1c;
  puVar3 = ui_menu_item_element._pad5 + 0x8c;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)puVar3 = *(undefined4 *)puVar1;
    puVar1 = puVar1 + 4;
    puVar3 = puVar3 + 4;
  }
  puVar1 = ui_menu_item_element._pad5;
  puVar3 = ui_menu_item_element._pad5 + 0x70;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)puVar3 = *(undefined4 *)puVar1;
    puVar1 = puVar1 + 4;
    puVar3 = puVar3 + 4;
  }
  ui_menu_item_element._pad5._4_4_ = (float)ui_menu_item_element._pad5._4_4_ - 116.0;
  ui_menu_item_element._pad5._32_4_ = (float)ui_menu_item_element._pad5._32_4_ - 116.0;
  ui_menu_item_element._pad5[0x18] = '\0';
  ui_menu_item_element._pad5[0x19] = '\0';
  ui_menu_item_element._pad5[0x1a] = '\x02';
  ui_menu_item_element._pad5[0x1b] = '?';
  ui_menu_item_element._pad5[0x34] = '\0';
  ui_menu_item_element._pad5[0x35] = '\0';
  ui_menu_item_element._pad5[0x36] = '\x02';
  ui_menu_item_element._pad5[0x37] = '?';
  puVar1 = ui_menu_item_element._pad5 + 0x1c;
  puVar3 = ui_menu_item_element._pad5 + 0x38;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)puVar3 = *(undefined4 *)puVar1;
    puVar1 = puVar1 + 4;
    puVar3 = puVar3 + 4;
  }
  puVar1 = ui_menu_item_element._pad5;
  puVar3 = ui_menu_item_element._pad5 + 0x54;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)puVar3 = *(undefined4 *)puVar1;
    puVar1 = puVar1 + 4;
    puVar3 = puVar3 + 4;
  }
  ui_menu_item_element._pad5._60_4_ = (float)ui_menu_item_element._pad5._60_4_ + 124.0;
  ui_menu_item_element._pad5._88_4_ = (float)ui_menu_item_element._pad5._88_4_ + 124.0;
  ui_menu_item_element._pad5._116_4_ = (float)ui_menu_item_element._pad5._116_4_ + 124.0;
  ui_menu_item_element._pad5[0x50] = '\0';
  ui_menu_item_element._pad5[0x51] = '\0';
  ui_menu_item_element._pad5[0x52] = '\x16';
  ui_menu_item_element._pad5[0x53] = '?';
  ui_menu_item_element._pad5[0x6c] = '\0';
  ui_menu_item_element._pad5[0x6d] = '\0';
  ui_menu_item_element._pad5[0x6e] = '\x16';
  ui_menu_item_element._pad5[0x6f] = '?';
  ui_menu_item_element._pad5._144_4_ = (float)ui_menu_item_element._pad5._144_4_ + 124.0;
  puVar1 = ui_menu_item_element._pad4 + 0xac;
  do {
    *(float *)(puVar1 + 4) = *(float *)(puVar1 + 4);
    puVar3 = puVar1 + 0x1c;
    *(float *)puVar1 = *(float *)puVar1 - 84.0;
    puVar1 = puVar3;
  } while ((int)puVar3 < 0x48fe58);
  puVar1 = ui_menu_item_element._pad4 + 0xac;
  puVar3 = ui_menu_item_element._pad5 + 0xb0;
  for (iVar2 = 0x3a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)puVar3 = *(undefined4 *)puVar1;
    puVar1 = puVar1 + 4;
    puVar3 = puVar3 + 4;
  }
  _DAT_0048fed4 = (float)ui_menu_item_element._pad5._60_4_ - 100.0;
  _DAT_0048fef0 = _DAT_0048fef0 - 100.0;
  _DAT_0048ff0c = _DAT_0048ff0c - 100.0;
  _DAT_0048ff28 = _DAT_0048ff28 - 100.0;
  ui_menu_layout_init();
  return;
}



