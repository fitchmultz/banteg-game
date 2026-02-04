/* weapon_pick_random_available @ 00452cd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* selects a random weapon id that is marked available */

int weapon_pick_random_available(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  do {
    iVar1 = crt_rand();
    iVar3 = iVar1 % 0x21 + 1;
    if (game_status_blob.weapon_usage_counts[iVar1 % 0x21 + 1] != 0) {
      uVar2 = crt_rand();
      if ((uVar2 & 1) == 0) {
        iVar1 = crt_rand();
        iVar3 = iVar1 % 0x21 + 1;
      }
    }
  } while (((&weapon_table)[iVar3].unlocked == '\0') ||
          ((((config_blob.reserved0._24_4_ == 3 && (_quest_stage_major == 5)) &&
            (_quest_stage_minor == 10)) && (iVar3 == 0x17))));
  return iVar3;
}



