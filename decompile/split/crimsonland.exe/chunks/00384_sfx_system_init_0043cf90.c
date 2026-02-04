/* sfx_system_init @ 0043cf90 */

/* initializes the Grim SFX system and clears per-sfx state */

int sfx_system_init(void)

{
  undefined4 in_EAX;
  HWND hwnd;
  int iVar1;
  uint3 extraout_var;
  undefined3 extraout_var_00;
  float *pfVar2;
  LPDIRECTSOUNDBUFFER *ppIVar3;
  uint coop_level;
  
  if (config_blob.reserved0[0] != '\0') {
    return CONCAT31((int3)((uint)in_EAX >> 8),1);
  }
  console_printf(&console_log_queue,s_Initializing_Grim_SFX_sound_syst_004785c8);
  coop_level = 2;
  hwnd = GetForegroundWindow();
  iVar1 = dsound_init(hwnd,coop_level);
  if ((char)iVar1 == '\0') {
    console_printf(&console_log_queue,s____FAILED__unable_to_init_Grim_S_00478590);
    config_blob.reserved0[0] = '\x01';
    config_blob.reserved0[1] = '\x01';
    return (uint)extraout_var << 8;
  }
  console_printf(&console_log_queue,s____init_44100_Hz_16_bit_ok_00478574);
  console_printf(&console_log_queue,s____using_DirectSound_output_00478554);
  console_printf(&console_log_queue,s____using_default_speaker_config_00478530);
  console_printf(&console_log_queue,s____saying_hello_to_the_Ogg__00478510);
  pfVar2 = sfx_cooldown_table;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar2 = 0.0;
    pfVar2 = pfVar2 + 1;
  }
  ppIVar3 = sfx_voice_table;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppIVar3 = (LPDIRECTSOUNDBUFFER)0x0;
    ppIVar3 = ppIVar3 + 1;
  }
  console_printf(&console_log_queue,s_Init_Grim_SFX_done_004784fc);
  return CONCAT31(extraout_var_00,1);
}



