/* game_mode_label @ 00412960 */

/* returns a display label for the current game mode */

char * game_mode_label(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (config_blob.reserved0._24_4_ == 2) {
    pcVar4 = &DAT_00473614;
  }
  else {
    if (config_blob.reserved0._24_4_ == 1) {
      uVar2 = 0xffffffff;
      pcVar4 = s_Survival_004720ac;
      do {
        pcVar5 = pcVar4;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar5 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar5;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      pcVar4 = pcVar5 + -uVar2;
      pcVar5 = (char *)&DAT_004854fc;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar5 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      }
      return (char *)&DAT_004854fc;
    }
    if (config_blob.reserved0._24_4_ == 3) {
      pcVar4 = s_Quests_0047360c;
    }
    else {
      if (config_blob.reserved0._24_4_ == 4) {
        uVar2 = 0xffffffff;
        pcVar4 = s_Typ_o_Shooter_00472090;
        do {
          pcVar5 = pcVar4;
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          pcVar5 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar5;
        } while (cVar1 != '\0');
        uVar2 = ~uVar2;
        pcVar4 = pcVar5 + -uVar2;
        pcVar5 = (char *)&DAT_004854fc;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
          pcVar4 = pcVar4 + 4;
          pcVar5 = pcVar5 + 4;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar5 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        }
        return (char *)&DAT_004854fc;
      }
      pcVar4 = s_Unknown_004714a0;
    }
  }
  uVar2 = 0xffffffff;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = (char *)&DAT_004854fc;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return (char *)&DAT_004854fc;
}



