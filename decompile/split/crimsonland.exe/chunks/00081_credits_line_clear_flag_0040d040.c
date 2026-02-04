/* credits_line_clear_flag @ 0040d040 */

/* walks backward to find the last line with flag 0x4 and clears it (penalty for wrong click; plays
   sfx) */

void __cdecl credits_line_clear_flag(int index)

{
  int *piVar1;
  
  if (-1 < index) {
    piVar1 = &credits_line_table[index].flags;
    while ((*piVar1 & 4) == 0) {
      index = index + -1;
      piVar1 = piVar1 + -2;
      if (index < 0) {
        return;
      }
    }
    credits_line_table[index].flags = credits_line_table[index].flags & 0xfffffffb;
    sfx_play(sfx_trooper_inpain_01);
  }
  return;
}



