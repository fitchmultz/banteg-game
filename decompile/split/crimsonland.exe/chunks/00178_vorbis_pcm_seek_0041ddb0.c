/* vorbis_pcm_seek @ 0041ddb0 */

/* wrapper around ov_pcm_seek for memory stream */

int __thiscall vorbis_pcm_seek(void *this,void *stream,uint sample_offset)

{
  int iVar1;
  uint unaff_retaddr;
  
  iVar1 = ov_pcm_seek((OggVorbis_File *)((int)this + 0x10),(ulonglong)unaff_retaddr << 0x20);
  return iVar1;
}



