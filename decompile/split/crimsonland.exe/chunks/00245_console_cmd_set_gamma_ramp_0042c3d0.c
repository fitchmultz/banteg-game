/* console_cmd_set_gamma_ramp @ 0042c3d0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* console command handler for setGammaRamp; parses float and calls grim_set_config_var(0x1c) */

void console_cmd_set_gamma_ramp(void)

{
  int iVar1;
  char *str;
  void *this;
  float value;
  float fVar2;
  
  iVar1 = console_cmd_argc_get();
  if (iVar1 != 2) {
    console_printf(&console_log_queue,s_setGammaRamp_<scalar_>_0>_004747e4);
    console_printf(&console_log_queue,s_Command_adjusts_gamma_ramp_linea_0047479c);
    return;
  }
  str = console_cmd_arg_get(1);
  value = crt_atof_l(this,str);
  fVar2 = 3.92364e-44;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x1c,(uint)value);
  console_printf(&console_log_queue,s_Gamma_ramp_regenerated_and_multi_0047476c,(double)fVar2);
  return;
}



