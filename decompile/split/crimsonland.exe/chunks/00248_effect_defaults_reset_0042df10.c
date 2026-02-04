/* effect_defaults_reset @ 0042df10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* resets global effect template values */

void effect_defaults_reset(void)

{
  undefined4 *puVar1;
  
  _effect_template_color_r = 0x3f800000;
  _effect_template_color_g = 0x3f800000;
  _effect_template_color_b = 0x3f800000;
  _effect_template_color_a = 0x3f800000;
  _DAT_004ab1b0 = 0;
  _effect_template_flags = 1;
  _effect_template_rotation = 0;
  _effect_template_scale = 0x3f800000;
  _effect_template_age = 0;
  _effect_template_lifetime = 0x3f000000;
  _effect_template_half_height = 0x42000000;
  _effect_template_half_width = 0x42000000;
  _DAT_004ab1b4 = 0;
  _effect_template_rotation_step = 0x3f800000;
  _effect_template_scale_step = 0x3f800000;
  effect_template_vel_x = 0;
  effect_template_vel_y = 0;
  _DAT_004ab268 = 0;
  effect_pool_pos_x.quad_data[0x1c] = (float)&DAT_004ab3ec;
  effect_init_entry(&effect_pool_pos_x);
  puVar1 = &DAT_004ab4a4;
  do {
    *puVar1 = puVar1 + 1;
    effect_init_entry(puVar1 + -0x2e);
    puVar1 = puVar1 + 0x2f;
  } while ((int)puVar1 < 0x4c2b2c);
  _DAT_004c2a70 = &DAT_004c2a74;
  effect_init_entry(&DAT_004c29b8);
  effect_free_list_head = &effect_pool_pos_x;
  _DAT_004c2b34 = 0;
  return;
}



