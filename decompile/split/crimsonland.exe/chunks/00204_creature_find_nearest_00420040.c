/* creature_find_nearest @ 00420040 */

/* returns nearest creature index; uses hitbox-size sentinel when exclude_id == -1 */

int __cdecl creature_find_nearest(float *pos,int exclude_id,float min_dist)

{
  float fVar1;
  float fVar2;
  float fVar3;
  creature_t *pcVar4;
  int iVar5;
  int iVar6;
  
  fVar1 = 1e+06;
  iVar6 = 0;
  if (exclude_id == -1) {
    iVar5 = 0;
    pcVar4 = &creature_pool;
    do {
      if (((pcVar4->active != '\0') && (pcVar4->hitbox_size == 16.0)) &&
         (fVar2 = *pos - pcVar4->pos_x, fVar3 = pos[1] - pcVar4->pos_y,
         fVar2 = SQRT(fVar3 * fVar3 + fVar2 * fVar2), fVar2 < fVar1)) {
        iVar6 = iVar5;
        fVar1 = fVar2;
      }
      pcVar4 = pcVar4 + 1;
      iVar5 = iVar5 + 1;
    } while ((int)pcVar4 < 0x4aa338);
    return iVar6;
  }
  iVar5 = 0;
  pcVar4 = &creature_pool;
  do {
    if ((((pcVar4->active != '\0') && (iVar5 != exclude_id)) &&
        (fVar2 = *pos - pcVar4->pos_x, fVar3 = pos[1] - pcVar4->pos_y,
        fVar2 = SQRT(fVar2 * fVar2 + fVar3 * fVar3), min_dist < fVar2)) && (fVar2 < fVar1)) {
      iVar6 = iVar5;
      fVar1 = fVar2;
    }
    pcVar4 = pcVar4 + 1;
    iVar5 = iVar5 + 1;
  } while ((int)pcVar4 < 0x4aa338);
  return iVar6;
}



