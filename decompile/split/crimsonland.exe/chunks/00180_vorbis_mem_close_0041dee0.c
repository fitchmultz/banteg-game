/* vorbis_mem_close @ 0041dee0 */

/* frees memory buffer and ov_clear */

void __fastcall vorbis_mem_close(void *stream)

{
  crt_free(*(void **)((int)stream + 0x2ec));
  ov_clear((OggVorbis_File *)((int)stream + 0x10));
  return;
}



