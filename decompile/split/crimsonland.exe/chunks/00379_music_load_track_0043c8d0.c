/* music_load_track @ 0043c8d0 */

/* loads a music track and returns its id */

int __cdecl music_load_track(char *path)

{
  void **ppvVar1;
  int iVar2;
  int iVar3;
  
  DAT_004cc8d8 = DAT_004cc8d8 + 1;
  iVar3 = 0;
  ppvVar1 = &music_entry_table.vorbis_stream;
  while ((ppvVar1[-0x18] != (void *)0x0 || (*ppvVar1 != (void *)0x0))) {
    ppvVar1 = ppvVar1 + 0x21;
    iVar3 = iVar3 + 1;
    if (0x4c84c3 < (int)ppvVar1) {
      return -1;
    }
  }
  if (iVar3 == -1) {
    return -1;
  }
  iVar2 = music_entry_load_ogg(&music_entry_table + iVar3,(byte *)path);
  if ((char)iVar2 == '\0') {
    console_printf(&console_log_queue,s_SFX_Tune__d_<____s__FAILED_00477df4,iVar3,path);
    return iVar3;
  }
  console_printf(&console_log_queue,s_SFX_Tune__d_<____s__ok_00477ddc,iVar3,path);
  return iVar3;
}



