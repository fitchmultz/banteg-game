/* highscore_init_sentinels @ 00412360 */

/* [binja] int32_t sub_412360() */

int highscore_init_sentinels(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uchar *puVar6;
  char *pcVar7;
  char *pcVar8;
  highscore_record_t *phVar9;
  
  puVar6 = &highscore_table.sentinel_pipe;
  iVar5 = 100;
  do {
    phVar9 = (highscore_record_t *)(puVar6 + -0x46);
    for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
      phVar9->player_name[0] = '\0';
      phVar9->player_name[1] = '\0';
      phVar9->player_name[2] = '\0';
      phVar9->player_name[3] = '\0';
      phVar9 = (highscore_record_t *)(phVar9->player_name + 4);
    }
    uVar3 = 0xffffffff;
    pcVar7 = &default_player_name;
    do {
      pcVar8 = pcVar7;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar7 = pcVar8 + -uVar3;
    phVar9 = (highscore_record_t *)(puVar6 + -0x46);
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)phVar9->player_name = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      phVar9 = (highscore_record_t *)(phVar9->player_name + 4);
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      phVar9->player_name[0] = *pcVar7;
      pcVar7 = pcVar7 + 1;
      phVar9 = (highscore_record_t *)(phVar9->player_name + 1);
    }
    puVar6[-2] = '\0';
    *puVar6 = '|';
    puVar6[1] = 0xff;
    uVar3 = crt_rand();
    *(uint *)(puVar6 + -0xe) = uVar3 & 0xfee050f;
    puVar6 = puVar6 + 0x48;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return uVar3 & 0xfee050f;
    }
  } while( true );
}



