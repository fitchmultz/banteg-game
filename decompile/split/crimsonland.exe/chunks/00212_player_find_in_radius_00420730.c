/* player_find_in_radius @ 00420730 */

/* returns a player index in range, skipping owner_id (-1/-2/-3 -> player 0/1/2) */

int __cdecl player_find_in_radius(int owner_id,float *pos,float radius)

{
  int iVar1;
  float *pfVar2;
  
  iVar1 = 0;
  if (0 < (int)config_blob.reserved0._20_4_) {
    pfVar2 = &player_state_table.health;
    do {
      if (iVar1 != -1 - owner_id) {
        if (0.0 < *pfVar2) {
          if (SQRT((pfVar2[-3] - pos[1]) * (pfVar2[-3] - pos[1]) +
                   (pfVar2[-4] - *pos) * (pfVar2[-4] - *pos)) - radius <
              pfVar2[4] * 0.14285715 + 3.0) {
            return iVar1;
          }
        }
      }
      iVar1 = iVar1 + 1;
      pfVar2 = pfVar2 + 0xd8;
    } while (iVar1 < (int)config_blob.reserved0._20_4_);
  }
  return -1;
}



