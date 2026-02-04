/* bonus_label_for_entry @ 00429580 */

/* returns the label string for a bonus entry (formatting weapon/score cases) */

char * __cdecl bonus_label_for_entry(bonus_entry_t *bonus_entry)

{
  bonus_id_t bVar1;
  char *pcVar2;
  
  bVar1 = bonus_entry->bonus_id;
  if (bVar1 == BONUS_ID_WEAPON) {
    pcVar2 = weapon_table_entry((bonus_entry->time).amount);
    crt_sprintf(&DAT_0049679c,&s_fmt_percent_s,pcVar2);
    return &DAT_0049679c;
  }
  if (bVar1 == BONUS_ID_POINTS) {
    crt_sprintf(&DAT_0049679c,s__s___d_00473e8c,DAT_004853e4,(bonus_entry->time).amount);
    return &DAT_0049679c;
  }
  return (&bonus_meta_table)[bVar1].label;
}



