/* bonus_spawn_at_pos @ 0041f790 */

/* allocates a bonus slot near pos, enforces spacing/edges, picks bonus type + amount */

bonus_entry_t * __cdecl bonus_spawn_at_pos(float *pos)

{
  float fVar1;
  float fVar2;
  bonus_entry_t *pbVar3;
  bonus_id_t bVar4;
  int iVar5;
  bonus_entry_t *pbVar6;
  
  if ((((*pos < 32.0) || ((float)(terrain_texture_width + -0x20) < *pos)) || (pos[1] < 32.0)) ||
     (((float)(terrain_texture_height + -0x20) < pos[1] || (config_blob.reserved0._24_4_ == 2)))) {
    return &bonus_pool_sentinel;
  }
  pbVar3 = bonus_alloc_slot();
  pbVar6 = bonus_pool;
  while ((pbVar6->bonus_id == BONUS_ID_NONE ||
         (fVar1 = *pos - (pbVar6->time).pos_x, fVar2 = pos[1] - (pbVar6->time).pos_y,
         32.0 <= SQRT(fVar2 * fVar2 + fVar1 * fVar1)))) {
    pbVar6 = pbVar6 + 1;
    if (0x482b07 < (int)pbVar6) {
LAB_0041f853:
      pbVar3->state = '\0';
      (pbVar3->time).pos_x = *pos;
      (pbVar3->time).pos_y = pos[1];
      (pbVar3->time).time_left = 10.0;
      (pbVar3->time).time_max = 10.0;
      bVar4 = bonus_pick_random_type();
      pbVar3->bonus_id = bVar4;
      if (bVar4 == BONUS_ID_WEAPON) {
        iVar5 = weapon_pick_random_available();
        (pbVar3->time).amount = iVar5;
        return pbVar3;
      }
      if (pbVar3->bonus_id == BONUS_ID_POINTS) {
        (pbVar3->time).amount = 500;
        iVar5 = crt_rand();
        if (((byte)iVar5 & 7) < 3) {
          (pbVar3->time).amount = 1000;
          return pbVar3;
        }
      }
      else {
        (pbVar3->time).amount = (&bonus_meta_table)[pbVar3->bonus_id].default_amount;
      }
      return pbVar3;
    }
  }
  pbVar3 = &bonus_pool_sentinel;
  goto LAB_0041f853;
}



