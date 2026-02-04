/* quest_build_the_spanking_of_the_dead @ 004358a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 2 (The Spanking Of The Dead) */

void quest_build_the_spanking_of_the_dead(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int *piVar2;
  int iVar3;
  quest_spawn_entry_t *pqVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  pqVar1 = entries;
  entries->pos_x = 256.0;
  (entries->pos_y_block).pos_y = 512.0;
  (entries->pos_y_block).heading_block.template_id = 0x27;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = 768.0;
  entries[1].pos_y_block.pos_y = 512.0;
  entries[1].pos_y_block.heading_block.template_id = 0x27;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 500;
  entries[1].pos_y_block.heading_block.count = 1;
  entries = (quest_spawn_entry_t *)0x0;
  iVar3 = 5000;
  piVar2 = &pqVar1[2].pos_y_block.heading_block.template_id;
  do {
    pqVar4 = (quest_spawn_entry_t *)((int)&entries->pos_x + 1);
    fVar5 = (float10)(int)entries * (float10)0.33333334;
    fVar6 = (float10)512.0 - (float10)(int)entries * (float10)3.8;
    fVar7 = (float10)fcos(fVar5);
    fVar8 = (float10)fsin(fVar5);
    piVar2[-3] = (int)(float)(fVar7 * fVar6 + (float10)512.0);
    piVar2[-2] = (int)(float)(fVar8 * fVar6 + (float10)512.0);
    ((quest_spawn_entry_heading_block_t *)(piVar2 + -1))->heading = (float)fVar5;
    *piVar2 = 0x41;
    piVar2[1] = iVar3;
    piVar2[2] = 1;
    iVar3 = iVar3 + 300;
    piVar2 = piVar2 + 6;
    entries = pqVar4;
  } while (iVar3 < 0xa988);
  pqVar1[0x82].pos_x = 1280.0;
  pqVar1[0x82].pos_y_block.pos_y = 512.0;
  iVar3 = (int)pqVar4 * 300;
  pqVar1[0x82].pos_y_block.heading_block.template_id = 0x42;
  pqVar1[0x82].pos_y_block.heading_block.trigger_time_ms = iVar3 + 10000;
  pqVar1[0x82].pos_y_block.heading_block.count = 0x10;
  pqVar1[0x83].pos_x = -256.0;
  pqVar1[0x83].pos_y_block.pos_y = 512.0;
  pqVar1[0x83].pos_y_block.heading_block.template_id = 0x42;
  pqVar1[0x83].pos_y_block.heading_block.trigger_time_ms = iVar3 + 20000;
  pqVar1[0x83].pos_y_block.heading_block.count = 0x10;
  *count = 0x84;
  return;
}



