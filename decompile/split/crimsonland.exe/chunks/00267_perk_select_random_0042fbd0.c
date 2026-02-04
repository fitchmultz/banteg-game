/* perk_select_random @ 0042fbd0 */

/* randomly selects an eligible perk index */

int perk_select_random(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  do {
    iVar1 = crt_rand();
    iVar1 = iVar1 % DAT_004c2c38 + 1;
    if ((char)(&perk_meta_table)[iVar1].available != '\0') {
      iVar2 = perk_can_offer(iVar1);
      if ((char)iVar2 != '\0') {
        return iVar1;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x3e9);
  console_printf(&console_log_queue,s___Perk_Randomizer_failed_to_gene_00475696 + 2);
  return perk_id_instant_winner;
}



