/* FUN_00417690 @ 00417690 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_417690() */

int FUN_00417690(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  ui_element_t *puVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = &DAT_0048f808;
  iVar4 = 8;
  do {
    FUN_00417a90(puVar1);
    puVar1 = puVar1 + 0x1c;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar1 = &DAT_0048f8f0;
  _DAT_0048f8ec = 4;
  iVar4 = 8;
  do {
    FUN_00417a90(puVar1);
    puVar1 = puVar1 + 0x1c;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  _DAT_0048f9d4 = 4;
  puVar1 = &DAT_0048f9d8;
  iVar4 = 8;
  do {
    FUN_00417a90(puVar1);
    puVar1 = puVar1 + 0x1c;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  _DAT_0048fabc = 4;
  puVar2 = &DAT_0048fac0;
  iVar4 = 8;
  do {
    FUN_00417a90(puVar2);
    puVar2 = puVar2 + 7;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  _DAT_0048fba4 = 4;
  puVar3 = &ui_menu_item_element;
  iVar4 = 8;
  do {
    FUN_00417a90(puVar3);
    puVar3 = (ui_element_t *)&puVar3->pos_y;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  ui_menu_item_element._pad3[0] = '\x04';
  ui_menu_item_element._pad3[1] = '\0';
  ui_menu_item_element._pad3[2] = '\0';
  ui_menu_item_element._pad3[3] = '\0';
  iVar4 = 0x48fc90;
  iVar5 = 8;
  do {
    FUN_00417a90(iVar4);
    iVar4 = iVar4 + 0x1c;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  ui_menu_item_element._pad4[0xa8] = '\x04';
  ui_menu_item_element._pad4[0xa9] = '\0';
  ui_menu_item_element._pad4[0xaa] = '\0';
  ui_menu_item_element._pad4[0xab] = '\0';
  FUN_004010f0(0x48fd78,0x1c,8,0x417a90);
  ui_menu_item_element._pad5[0xac] = '\x04';
  ui_menu_item_element._pad5[0xad] = '\0';
  ui_menu_item_element._pad5[0xae] = '\0';
  ui_menu_item_element._pad5[0xaf] = '\0';
  FUN_004010f0(0x48fe60,0x1c,8,0x417a90);
  _DAT_0048ff44 = 4;
  FUN_004010f0(0x48ff48,0x1c,8,0x417a90);
  _DAT_0049002c = 4;
  FUN_004010f0(0x490030,0x1c,8,0x417a90);
  _DAT_00490114 = 4;
  FUN_004010f0(0x490118,0x1c,8,0x417a90);
  _DAT_004901fc = 4;
  iVar4 = FUN_004010f0(0x490200,0x1c,8,0x417a90);
  _DAT_004902e4 = 4;
  return iVar4;
}



