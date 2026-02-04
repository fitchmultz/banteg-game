/* quest_build_major_alien_breach @ 00437af0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 4 Quest 1 (Major Alien Breach) */

void quest_build_major_alien_breach(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = 4000;
  iVar3 = 0;
  do {
    entries->pos_x = 1088.0;
    (entries->pos_y_block).pos_y = 512.0;
    (entries->pos_y_block).heading_block.template_id = 0x20;
    (entries->pos_y_block).heading_block.trigger_time_ms = iVar1;
    (entries->pos_y_block).heading_block.count = 2;
    iVar2 = iVar2 + 2;
    entries[1].pos_x = 512.0;
    entries[1].pos_y_block.pos_y = -64.0;
    entries[1].pos_y_block.heading_block.template_id = 0x20;
    entries[1].pos_y_block.heading_block.trigger_time_ms = iVar1;
    entries[1].pos_y_block.heading_block.count = 2;
    iVar1 = iVar1 + (2000 - iVar3);
    entries = entries + 2;
    if (iVar1 < 1000) {
      iVar1 = 1000;
    }
    iVar3 = iVar3 + 0xf;
  } while (iVar3 < 0x5dc);
  *count = iVar2;
  return;
}



