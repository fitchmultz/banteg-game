/* highscore_record_init @ 0043b750 */

/* fills the active high score record metadata for the current run */

void highscore_record_init(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = 1;
  iVar3 = 4;
  do {
    if (*(int *)((int)&weapon_usage_time + iVar3) < (int)(&weapon_usage_time)[iVar1]) {
      iVar3 = iVar1 * 4;
      iVar4 = iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  highscore_active_record.most_used_weapon_id = (uchar)iVar4;
  if ((int)highscore_active_record.shots_fired < (int)highscore_active_record.shots_hit) {
    highscore_active_record.shots_hit = highscore_active_record.shots_fired;
  }
  highscore_active_record.game_mode_id = config_blob.reserved0[0x18];
  highscore_active_record.quest_stage_major = quest_stage_major;
  highscore_active_record.quest_stage_minor = quest_stage_minor;
  highscore_active_record.flags = '\0';
  uVar2 = crt_rand();
  uVar2 = uVar2 & 0x8fffffff;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xf0000000) + 1;
  }
  highscore_active_record.reserved0._0_4_ = uVar2 + 0x310;
  highscore_active_record.full_version_marker = -(config_blob.hardcore != '\0') & 0x75;
  return;
}



