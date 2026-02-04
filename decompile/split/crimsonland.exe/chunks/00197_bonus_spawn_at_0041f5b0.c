/* bonus_spawn_at @ 0041f5b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* clamps position, fills bonus entry fields, and spawns pickup effect */

bonus_entry_t * __cdecl bonus_spawn_at(float *pos,bonus_id_t bonus_id,int duration_override)

{
  bonus_entry_t *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (*pos < 32.0) {
    *pos = 32.0;
  }
  if (pos[1] < 32.0) {
    pos[1] = 32.0;
  }
  if ((float)(terrain_texture_width + -0x20) < *pos) {
    *pos = (float)(terrain_texture_width + -0x20);
  }
  if ((float)(terrain_texture_height + -0x20) < pos[1]) {
    pos[1] = (float)(terrain_texture_height + -0x20);
  }
  if (config_blob.reserved0._24_4_ != 2) {
    pbVar1 = bonus_alloc_slot();
    pbVar1->state = '\0';
    (pbVar1->time).pos_x = *pos;
    (pbVar1->time).pos_y = pos[1];
    (pbVar1->time).time_left = 10.0;
    (pbVar1->time).time_max = 10.0;
    pbVar1->bonus_id = bonus_id;
    (pbVar1->time).amount = duration_override;
    if (duration_override == -1) {
      (pbVar1->time).amount = (&bonus_meta_table)[bonus_id].default_amount;
    }
    _effect_template_color_r = 0x3ecccccd;
    _effect_template_flags = 0x1d;
    _effect_template_color_g = 0x3f000000;
    _effect_template_color_b = 0x3f800000;
    _effect_template_color_a = 0x3f000000;
    _effect_template_lifetime = 0x3f000000;
    _effect_template_half_width = 0x42000000;
    _effect_template_half_height = 0x42000000;
    iVar4 = 0x10;
    do {
      uVar2 = crt_rand();
      _effect_template_rotation = (float)(uVar2 & 0x7f) * 0.049087387;
      uVar2 = crt_rand();
      uVar2 = uVar2 & 0x8000007f;
      if ((int)uVar2 < 0) {
        uVar2 = (uVar2 - 1 | 0xffffff80) + 1;
      }
      effect_template_vel_x = (float)(int)(uVar2 - 0x40);
      uVar2 = crt_rand();
      uVar2 = uVar2 & 0x8000007f;
      if ((int)uVar2 < 0) {
        uVar2 = (uVar2 - 1 | 0xffffff80) + 1;
      }
      effect_template_vel_y = (float)(int)(uVar2 - 0x40);
      iVar3 = crt_rand();
      _effect_template_scale_step = (float)(iVar3 % 100) * 0.01 + 0.1;
      effect_spawn(0,pos);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    return pbVar1;
  }
  return &bonus_pool_sentinel;
}



