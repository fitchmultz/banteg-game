/* perk_count_get @ 0042fcf0 */

/* returns perk count from DAT_00490968 */

int __cdecl perk_count_get(int perk_id)

{
  return player_state_table.perk_counts[perk_id];
}



