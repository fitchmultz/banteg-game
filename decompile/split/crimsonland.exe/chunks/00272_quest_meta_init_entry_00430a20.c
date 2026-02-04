/* quest_meta_init_entry @ 00430a20 */

/* initializes a quest metadata entry (name copy, terrain ids, defaults) and updates
   quest_meta_cursor */

int __cdecl quest_meta_init_entry(quest_meta_t *meta,int tier,int index,char *name)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  
  if (meta->name != (char *)0x0) {
    crt_free(meta->name);
    console_printf(&console_log_queue,s___Quest_overwritten__00477742 + 2);
  }
  pcVar2 = strdup_malloc(name);
  meta->name = pcVar2;
  meta->unlock_perk_id = perk_id_antiperk;
  iVar1 = tier * 2 + -2;
  meta->unlock_weapon_id = 0;
  meta->tier = tier;
  meta->index = index;
  meta->terrain_id = iVar1;
  if (index < 6) {
    meta->terrain_id_b = tier * 2 + -1;
    meta->terrain_id_c = iVar1;
  }
  else {
    meta->terrain_id_b = iVar1;
    meta->terrain_id_c = tier * 2 + -1;
  }
  if (4 < tier) {
    uVar3 = index & 0x80000003;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
    }
    meta->terrain_id = uVar3;
    meta->terrain_id_b = 1;
    meta->terrain_id_c = 3;
    meta->builder = (quest_builder_fn_t)0x5;
  }
  quest_meta_cursor = meta;
  return tier;
}



