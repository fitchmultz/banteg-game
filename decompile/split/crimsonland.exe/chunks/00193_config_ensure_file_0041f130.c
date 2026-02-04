/* config_ensure_file @ 0041f130 */

/* creates crimson.cfg when missing (writes default config blob) */

void config_ensure_file(void)

{
  char *pcVar1;
  FILE *pFVar2;
  char *pcVar3;
  
  pcVar3 = &file_mode_read_binary;
  pcVar1 = game_build_path(config_filename);
  pFVar2 = (FILE *)crt_fopen(pcVar1,pcVar3);
  if (pFVar2 != (FILE *)0x0) {
    crt_fclose(pFVar2);
    return;
  }
  pcVar3 = &file_mode_write_binary;
  config_blob.fx_toggle = '\x01';
  pcVar1 = game_build_path(config_filename);
  pFVar2 = (FILE *)crt_fopen(pcVar1,pcVar3);
  if (pFVar2 != (FILE *)0x0) {
    crt_fwrite((char *)&config_blob,0x480,1,(int *)pFVar2);
    crt_fclose(pFVar2);
  }
  return;
}



