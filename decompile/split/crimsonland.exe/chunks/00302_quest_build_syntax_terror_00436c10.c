/* quest_build_syntax_terror @ 00436c10 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 4 Quest 8 (Syntax Terror) */

void quest_build_syntax_terror(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  iVar4 = 0;
  iStack_1c = 0;
  if (config_blob.hardcore != '\0') {
    config_blob.reserved0._20_4_ = config_blob.reserved0._20_4_ + 4;
  }
  iStack_18 = 0;
  iStack_10 = 0x5dc;
  iStack_14 = 0x14c9;
  iVar1 = config_blob.reserved0._20_4_;
  do {
    iVar5 = 0;
    if (iVar1 != -9 && -1 < iVar1 + 9) {
      piVar2 = &entries[iVar4].pos_y_block.heading_block.template_id;
      iVar3 = 0x4c5;
      iVar6 = iStack_10;
      do {
        iVar1 = iVar3 * iVar5;
        piVar2[-3] = (int)(float)(((iVar5 * iVar5 * 0x4c + 0xec) * iVar5 + iStack_14 * iStack_18) %
                                  0x380 + 0x40);
        iVar4 = iStack_1c + 1;
        iVar5 = iVar5 + 1;
        piVar2[-2] = (int)(float)((iVar1 + (iStack_18 * iStack_18 * 0x4c + 0x1b) * iStack_18) %
                                  0x380 + 0x40);
        *piVar2 = 7;
        piVar2[1] = iVar6;
        piVar2[2] = 1;
        iVar6 = iVar6 + 300;
        iVar1 = config_blob.reserved0._20_4_;
        piVar2 = piVar2 + 6;
        iVar3 = iVar3 + 0x15;
        iStack_1c = iVar4;
      } while (iVar5 < config_blob.reserved0._20_4_ + 9);
    }
    iStack_14 = iStack_14 + 0x35;
    iStack_18 = iStack_18 + 1;
    iStack_10 = iStack_10 + 30000;
  } while (iStack_14 < 0x159d);
  if (config_blob.hardcore == '\0') {
    *count = iVar4;
    return;
  }
  config_blob.reserved0._20_4_ = iVar1 + -4;
  *count = iVar4;
  return;
}



