/* FUN_0042f270 @ 0042f270 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] void* sub_42f270(float* arg1, float arg2, float arg3) */

void * __cdecl FUN_0042f270(float *arg1,float arg2,float arg3)

{
  void *pvVar1;
  
  _effect_template_lifetime = arg3 * 0.8;
  _effect_template_color_g = 0x3f19999a;
  _effect_template_scale_step = arg2 * 45.0;
  _effect_template_color_r = 0x3f19999a;
  _effect_template_flags = 0x19;
  _effect_template_color_b = 0x3f666666;
  _effect_template_color_a = 0x3f800000;
  _effect_template_age = 0;
  _effect_template_half_width = 0x40800000;
  _effect_template_half_height = 0x40800000;
  _effect_template_rotation = 0;
  effect_template_vel_x = 0;
  effect_template_vel_y = 0;
  pvVar1 = effect_spawn(1,arg1);
  return pvVar1;
}



