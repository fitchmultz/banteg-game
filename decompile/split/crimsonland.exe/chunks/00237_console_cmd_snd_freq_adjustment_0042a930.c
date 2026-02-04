/* console_cmd_snd_freq_adjustment @ 0042a930 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* console command handler for sndfreqadjustment; toggles DAT_004807a8 and prints status */

void console_cmd_snd_freq_adjustment(void)

{
  config_blob.reserved6[0x10] = config_blob.reserved6[0x10] == '\0';
  if ((bool)config_blob.reserved6[0x10]) {
    console_printf(&console_log_queue,s_Sound_frequency_adjustment_is_no_00473ffc);
    return;
  }
  console_printf(&console_log_queue,s_Sound_frequency_adjustment_is_no_00473fcc);
  return;
}



