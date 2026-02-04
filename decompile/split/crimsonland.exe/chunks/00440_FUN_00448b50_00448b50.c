/* FUN_00448b50 @ 00448b50 */

undefined4 __fastcall FUN_00448b50(undefined4 param_1)

{
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  
  (*grim_interface_ptr->vtable->grim_get_config_float)(0x13f);
  if (0.5 < ABS((float)extraout_ST0)) {
    return 0x13f;
  }
  (*grim_interface_ptr->vtable->grim_get_config_float)(0x140);
  if (0.5 < ABS((float)extraout_ST0_00)) {
    return 0x140;
  }
  (*grim_interface_ptr->vtable->grim_get_config_float)(0x141);
  if (0.5 < ABS((float)extraout_ST0_01)) {
    return 0x141;
  }
  (*grim_interface_ptr->vtable->grim_get_config_float)(0x153);
  if (0.5 < ABS((float)extraout_ST0_02)) {
    return 0x153;
  }
  (*grim_interface_ptr->vtable->grim_get_config_float)(0x154);
  if (0.5 < ABS((float)extraout_ST0_03)) {
    return 0x154;
  }
  (*grim_interface_ptr->vtable->grim_get_config_float)(0x155);
  if (0.5 < ABS((float)extraout_ST0_04)) {
    return 0x155;
  }
  (*grim_interface_ptr->vtable->grim_flush_input)();
  return 0;
}



