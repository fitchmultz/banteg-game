/* quest_build_arachnoid_farm @ 00436820 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 3 (Arachnoid Farm) */

void quest_build_arachnoid_farm(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iStack_c;
  
  iVar3 = 0;
  iStack_c = 0;
  if (config_blob.reserved0._20_4_ != -4 && -1 < config_blob.reserved0._20_4_ + 4) {
    iVar4 = 500;
    piVar2 = &(entries->pos_y_block).heading_block.trigger_time_ms;
    do {
      iVar3 = iStack_c + 1;
      piVar2[-4] = (int)((float)iStack_c * 102.4 + 256.0);
      piVar2[-3] = 0x43800000;
      piVar2[-1] = 10;
      *piVar2 = iVar4;
      piVar2[1] = 1;
      iVar4 = iVar4 + 500;
      piVar2 = piVar2 + 6;
      iStack_c = iVar3;
    } while (iVar3 < config_blob.reserved0._20_4_ + 4);
  }
  iStack_c = 0;
  if (config_blob.reserved0._20_4_ != -4 && -1 < config_blob.reserved0._20_4_ + 4) {
    iVar4 = 0x2904;
    piVar2 = &entries[iVar3].pos_y_block.heading_block.trigger_time_ms;
    do {
      fVar1 = (float)iStack_c;
      iVar3 = iVar3 + 1;
      iStack_c = iStack_c + 1;
      piVar2[-4] = (int)(fVar1 * 102.4 + 256.0);
      piVar2[-3] = 0x44400000;
      piVar2[-1] = 10;
      *piVar2 = iVar4;
      piVar2[1] = 1;
      iVar4 = iVar4 + 500;
      piVar2 = piVar2 + 6;
    } while (iStack_c < config_blob.reserved0._20_4_ + 4);
  }
  iStack_c = 0;
  if (config_blob.reserved0._20_4_ != -7 && -1 < config_blob.reserved0._20_4_ + 7) {
    iVar4 = 0x9e34;
    piVar2 = &entries[iVar3].pos_y_block.heading_block.trigger_time_ms;
    do {
      fVar1 = (float)iStack_c;
      iVar3 = iVar3 + 1;
      iStack_c = iStack_c + 1;
      piVar2[-4] = (int)(fVar1 * 64.0 + 256.0);
      piVar2[-3] = 0x44000000;
      piVar2[-1] = 0x10;
      *piVar2 = iVar4;
      piVar2[1] = 1;
      iVar4 = iVar4 + 0xdac;
      piVar2 = piVar2 + 6;
    } while (iStack_c < config_blob.reserved0._20_4_ + 7);
    *count = iVar3;
    return;
  }
  *count = iVar3;
  return;
}



