/* audio_resume_all @ 0042a5f0 */

/* resume active audio channels */

int audio_resume_all(void)

{
  float fVar1;
  int iVar2;
  uint3 extraout_var;
  
  audio_resume_channels();
  fVar1 = *(float *)((int)cv_verbose + 0xc);
  iVar2 = CONCAT22((short)((uint)cv_verbose >> 0x10),
                   (ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 |
                   (ushort)(fVar1 == 0.0) << 0xe);
  if ((fVar1 == 0.0) == 0) {
    console_printf(&console_log_queue,s_<___Restored_00473e94);
    iVar2 = (uint)extraout_var << 8;
  }
  audio_suspend_flag = 0;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}



