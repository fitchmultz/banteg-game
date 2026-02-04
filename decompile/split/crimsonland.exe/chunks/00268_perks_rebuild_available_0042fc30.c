/* perks_rebuild_available @ 0042fc30 */

/* rebuilds perk availability/unlock flags */

void perks_rebuild_available(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = DAT_004c2c38 + 1;
  if (0 < iVar5) {
    piVar3 = &perk_meta_table.available;
    do {
      *(undefined1 *)piVar3 = 0;
      piVar3 = piVar3 + 5;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  iVar5 = perk_id_antiperk;
  puVar4 = &DAT_004c2c60;
  *(undefined1 *)&(&perk_meta_table)[perk_id_antiperk].available = 0;
  do {
    *puVar4 = 1;
    iVar1 = perk_id_fire_caugh;
    iVar6 = perk_id_living_fortress;
    iVar2 = quest_unlock_index;
    puVar4 = puVar4 + 0x14;
  } while ((int)puVar4 < 0x4c2e7c);
  *(undefined1 *)&(&perk_meta_table)[perk_id_man_bomb].available = 1;
  *(undefined1 *)&(&perk_meta_table)[iVar6].available = 1;
  *(undefined1 *)&(&perk_meta_table)[iVar1].available = 1;
  *(undefined1 *)&(&perk_meta_table)[perk_id_tough_reloader].available = 1;
  iVar6 = 0;
  if (0 < iVar2) {
    piVar3 = &quest_selected_meta.unlock_perk_id;
    do {
      if (0x484fe7 < (int)piVar3) break;
      iVar1 = *piVar3;
      iVar6 = iVar6 + 1;
      piVar3 = piVar3 + 0xb;
      *(undefined1 *)&(&perk_meta_table)[iVar1].available = 1;
    } while (iVar6 < iVar2);
  }
  *(undefined1 *)&(&perk_meta_table)[iVar5].available = 0;
  return;
}



