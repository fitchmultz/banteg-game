/* inflateInit2_ @ 1002428f */

/* zlib: init inflate with window bits */

int __cdecl inflateInit2_(z_streamp strm,int windowBits,char *version,int stream_size)

{
  internal_state *piVar1;
  void *pvVar2;
  int iVar3;
  
  if (((version == (char *)0x0) || (*version != '1')) || (stream_size != 0x38)) {
    iVar3 = -6;
  }
  else if (strm == (z_streamp)0x0) {
    iVar3 = -2;
  }
  else {
    strm->msg = (char *)0x0;
    if (strm->zalloc == (alloc_func)0x0) {
      strm->zalloc = zcalloc;
      strm->opaque = (voidpf)0x0;
    }
    if (strm->zfree == (free_func)0x0) {
      strm->zfree = zcfree;
    }
    piVar1 = (*strm->zalloc)(strm->opaque,1,0x18);
    strm->state = piVar1;
    if (piVar1 == (internal_state *)0x0) {
      iVar3 = -4;
    }
    else {
      piVar1[5].dummy = 0;
      strm->state[3].dummy = 0;
      if (windowBits < 0) {
        windowBits = -windowBits;
        strm->state[3].dummy = 1;
      }
      if ((windowBits < 8) || (0xf < windowBits)) {
        iVar3 = -2;
      }
      else {
        strm->state[4].dummy = windowBits;
        pvVar2 = inflate_blocks_new(strm,(void *)(~-(uint)(strm->state[3].dummy != 0) & 0x100347d2),
                                    1 << ((byte)windowBits & 0x1f));
        strm->state[5].dummy = (int)pvVar2;
        if (strm->state[5].dummy != 0) {
          inflateReset(strm);
          return 0;
        }
        iVar3 = -4;
      }
      inflateEnd(strm);
    }
  }
  return iVar3;
}



