/* sfx_entry_load_wav @ 0043c020 */

/* loads a WAV sample into an sfx entry */

int __cdecl sfx_entry_load_wav(void *entry,byte *path)

{
  int iVar1;
  uint extraout_EAX;
  uint local_4;
  
  iVar1 = resource_read_alloc(path,&path,&local_4);
  if ((char)iVar1 == '\0') {
    return iVar1;
  }
  iVar1 = wav_parse_into_entry(entry,path,local_4);
  if ((char)iVar1 == '\0') {
    crt_free(path);
    return extraout_EAX & 0xffffff00;
  }
  crt_free(path);
  iVar1 = sfx_entry_create_buffers((int)entry);
  return CONCAT31((int3)((uint)iVar1 >> 8),(char)iVar1 != '\0');
}



