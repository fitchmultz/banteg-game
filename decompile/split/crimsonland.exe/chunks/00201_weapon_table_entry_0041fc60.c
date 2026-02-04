/* weapon_table_entry @ 0041fc60 */

/* returns the entry base (&DAT_004d7a2c + weapon_id * 0x1f) */

char * __cdecl weapon_table_entry(int weapon_id)

{
  return (&weapon_table)[weapon_id].name;
}



