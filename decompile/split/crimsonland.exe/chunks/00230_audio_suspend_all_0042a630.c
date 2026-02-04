/* audio_suspend_all @ 0042a630 */

/* suspend active audio channels */

void audio_suspend_all(void)

{
  audio_suspend_channels();
  if (*(float *)((int)cv_verbose + 0xc) != 0.0) {
    console_printf(&console_log_queue,s_<___Suspended_00473ea4);
  }
  audio_suspend_flag = 1;
  return;
}



