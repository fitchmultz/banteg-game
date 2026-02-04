/* FUN_0042f3f0 @ 0042f3f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] void* sub_42f3f0(float* arg1, float arg2, int32_t arg3) */

void * __cdecl FUN_0042f3f0(float *arg1,float arg2,int arg3)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  float10 fVar5;
  float10 fVar6;
  longlong lVar7;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 1.0;
  local_c = 0.9;
  local_8 = 0x3dcccccd;
  local_4 = 0x3f800000;
  _effect_template_color_r = 0x3f800000;
  pvVar4 = (void *)0x3f800000;
  _effect_template_flags = 0x19;
  _effect_template_color_g = 0x3f666666;
  _effect_template_color_b = 0x3dcccccd;
  _effect_template_color_a = 0x3f800000;
  _effect_template_half_width = 0x40800000;
  _effect_template_half_height = 0x40800000;
  _effect_template_rotation = 0;
  effect_template_vel_x = 0;
  effect_template_vel_y = 0;
  _effect_template_scale_step = 0x425c0000;
  if (0 < arg3) {
    lVar7 = __ftol();
    do {
      uVar2 = crt_rand();
      fVar1 = (float)(uVar2 & 0x1ff) * 0.001953125 * 6.2831855;
      iVar3 = crt_rand();
      fVar5 = (float10)(iVar3 % (int)lVar7);
      fVar6 = (float10)fcos((float10)fVar1);
      local_10 = (float)(fVar6 * fVar5 + (float10)*arg1);
      fVar6 = (float10)fsin((float10)fVar1);
      local_c = (float)(fVar6 * fVar5 + (float10)arg1[1]);
      uVar2 = crt_rand();
      _effect_template_age = (float)(int)-(uVar2 & 0xff) * 0.0012;
      _effect_template_lifetime = 0.1 - _effect_template_age;
      pvVar4 = effect_spawn(0,&local_10);
      arg3 = arg3 + -1;
    } while (arg3 != 0);
  }
  return pvVar4;
}



