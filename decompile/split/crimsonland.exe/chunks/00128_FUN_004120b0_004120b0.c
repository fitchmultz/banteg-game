/* FUN_004120b0 @ 004120b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_4120b0() */

int FUN_004120b0(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  highscore_record_t *phVar7;
  
  phVar7 = &highscore_active_record;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    phVar7->player_name[0] = '\0';
    phVar7->player_name[1] = '\0';
    phVar7->player_name[2] = '\0';
    phVar7->player_name[3] = '\0';
    phVar7 = (highscore_record_t *)(phVar7->player_name + 4);
  }
  uVar3 = 0xffffffff;
  pcVar5 = &default_player_name;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  phVar7 = &highscore_active_record;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)phVar7->player_name = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    phVar7 = (highscore_record_t *)(phVar7->player_name + 4);
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    phVar7->player_name[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    phVar7 = (highscore_record_t *)(phVar7->player_name + 1);
  }
  highscore_active_record.flags = '\0';
  highscore_active_record.sentinel_pipe = '|';
  highscore_active_record.sentinel_ff = 0xff;
  uVar3 = crt_rand();
  uVar3 = uVar3 & 0xfee050f;
  highscore_active_record.reserved0[0] = (char)uVar3;
  highscore_active_record.reserved0[1] = (char)(uVar3 >> 8);
  highscore_active_record.reserved0[2] = (char)(uVar3 >> 0x10);
  highscore_active_record.reserved0[3] = (char)(uVar3 >> 0x18);
  _bonus_energizer_timer = 0;
  survival_spawn_stage = 0;
  _DAT_00487028 = 0;
  quest_fail_retry_count = 0;
  demo_mode_active = 0;
  DAT_00486faa = 0;
  quest_unlock_index = 0;
  creature_active_count = 0;
  DAT_0048718c = 0;
  quest_transition_timer_ms = -1;
  _quest_stage_major = 1;
  _quest_stage_minor = 1;
  return 1;
}



