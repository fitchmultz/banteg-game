/* weapon_refresh_available @ 00452e40 */

/* rebuilds availability flags from the unlock list */

void weapon_refresh_available(void)

{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  puVar2 = &weapon_table.unlocked;
  do {
    *puVar2 = '\0';
    iVar3 = quest_unlock_index;
    puVar2 = puVar2 + 0x7c;
  } while ((int)puVar2 < 0x4d996c);
  iVar5 = 0;
  DAT_004d7ae8 = 1;
  if (0 < quest_unlock_index) {
    piVar4 = &quest_selected_meta.unlock_weapon_id;
    do {
      if (0x484feb < (int)piVar4) break;
      iVar1 = *piVar4;
      piVar4 = piVar4 + 0xb;
      iVar5 = iVar5 + 1;
      (&weapon_table)[iVar1].unlocked = '\x01';
    } while (iVar5 < iVar3);
  }
  if (config_blob.reserved0._24_4_ == 1) {
    DAT_004d7b64 = 1;
    DAT_004d7be0 = 1;
    DAT_004d7cd8 = 1;
  }
  iVar3 = game_is_full_version();
  if ((uchar)iVar3 == '\0') {
    quest_unlock_index_full = 0;
    weapon_table.unlocked = (uchar)iVar3;
    return;
  }
  if (0x27 < quest_unlock_index_full) {
    DAT_004d8878 = 1;
  }
  weapon_table.unlocked = '\0';
  return;
}



