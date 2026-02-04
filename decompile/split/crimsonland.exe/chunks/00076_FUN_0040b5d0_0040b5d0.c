/* FUN_0040b5d0 @ 0040b5d0 */

/* [binja] int32_t* sub_40b5d0() */

int * FUN_0040b5d0(void)

{
  bonus_entry_t *pbVar1;
  projectile_t *ppVar2;
  float *pfVar3;
  
  pbVar1 = bonus_pool;
  do {
    pbVar1->bonus_id = BONUS_ID_NONE;
    pbVar1 = pbVar1 + 1;
  } while ((int)pbVar1 < 0x482b08);
  pfVar3 = &creature_pool.health;
  do {
    ((creature_t *)(pfVar3 + -9))->active = '\0';
    *pfVar3 = -1.0;
    pfVar3 = pfVar3 + 0x26;
  } while ((int)pfVar3 < 0x4aa35c);
  ppVar2 = projectile_pool;
  do {
    ppVar2->active = '\0';
    ppVar2 = ppVar2 + 1;
  } while ((int)ppVar2 < 0x493eb8);
  pfVar3 = &player_state_table.health;
  do {
    *(undefined1 *)(pfVar3 + -9) = 0;
    *pfVar3 = -1.0;
    pfVar3 = pfVar3 + 0xd8;
  } while ((int)pfVar3 < 0x490f94);
  return (int *)pfVar3;
}



