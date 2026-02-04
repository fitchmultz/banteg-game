/* vorbis_read_pcm16 @ 0041df00 */

/* decode PCM16 samples via ov_read */

int __thiscall vorbis_read_pcm16(void *this,void *stream,char *dst,int bytes)

{
  uint uVar1;
  
  uVar1 = ov_read((OggVorbis_File *)((int)this + 0x10),stream,(int)dst,0,2,1,
                  (int *)((int)this + 0x2e0));
  if (uVar1 == 0) {
    return 0;
  }
  return uVar1 & ((int)uVar1 < 0) - 1;
}



