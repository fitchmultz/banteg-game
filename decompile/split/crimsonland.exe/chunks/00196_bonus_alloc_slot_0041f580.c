/* bonus_alloc_slot @ 0041f580 */

/* returns a free bonus slot in DAT_00482948 (or DAT_00490630 sentinel) */

bonus_entry_t * bonus_alloc_slot(void)

{
  bonus_entry_t *pbVar1;
  int iVar2;
  
  iVar2 = 0;
  pbVar1 = bonus_pool;
  do {
    if (pbVar1->bonus_id == BONUS_ID_NONE) {
      return bonus_pool + iVar2;
    }
    pbVar1 = pbVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)pbVar1 < 0x482b08);
  return &bonus_pool_sentinel;
}



