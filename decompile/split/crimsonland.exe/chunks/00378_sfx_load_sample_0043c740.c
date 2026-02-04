/* sfx_load_sample @ 0043c740 */

/* loads an sfx sample and returns its id */

int __cdecl sfx_load_sample(char *path)

{
  byte bVar1;
  void **ppvVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  byte local_80 [128];
  
  if (config_blob.reserved0[0] != '\0') {
    return 1;
  }
  iVar6 = 0;
  ppvVar2 = &sfx_entry_table.pcm_data;
  while (*ppvVar2 != (void *)0x0) {
    ppvVar2 = ppvVar2 + 0x21;
    iVar6 = iVar6 + 1;
    if (0x4cc6e3 < (int)ppvVar2) {
      return -1;
    }
  }
  if (iVar6 != -1) {
    pbVar7 = &DAT_00477dd4;
    pbVar3 = (byte *)path;
    do {
      bVar1 = *pbVar3;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_0043c7c5:
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0043c7ca;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_0043c7c5;
      pbVar3 = pbVar3 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_0043c7ca:
    if (iVar4 == 0) {
      console_printf(&console_log_queue,s_Warning__sample___s__not_accepte_00477db0,path);
      path = s_trooper_inPain_01_ogg_00477d98;
    }
    pcVar5 = _strstr(path,&DAT_00477dd4);
    if (pcVar5 == (char *)0x0) {
      iVar4 = sfx_entry_load_wav(&sfx_entry_table + iVar6,(byte *)path);
      if ((char)iVar4 != '\0') goto LAB_0043c885;
      pcVar5 = s____loading_wav_sample___s__faile_00477d48;
    }
    else {
      if (DAT_004cc8d5 == '\0') {
        pcVar5 = s_sfx__s_00477d90;
      }
      else {
        pcVar5 = &s_fmt_percent_s;
      }
      crt_sprintf((char *)local_80,pcVar5,path);
      iVar4 = sfx_entry_load_ogg(&sfx_entry_table + iVar6,local_80);
      if ((char)iVar4 != '\0') {
LAB_0043c885:
        if (*(float *)((int)cv_silentloads + 0xc) == 0.0) {
          console_printf(&console_log_queue,s_SFX_Sample__d_<____s__ok_00477d2c,iVar6,path);
        }
        DAT_004cc8d8 = DAT_004cc8d8 + 1;
        return iVar6;
      }
      pcVar5 = s____loading_ogg_sample___s__faile_00477d6c;
    }
    console_printf(&console_log_queue,pcVar5,path);
  }
  return -1;
}



