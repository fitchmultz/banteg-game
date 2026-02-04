/* inflateEnd @ 10024251 */

/* zlib: free inflate state */

int __cdecl inflateEnd(z_streamp strm)

{
  void *s;
  
  if (((strm != (z_streamp)0x0) && (strm->state != (internal_state *)0x0)) &&
     (strm->zfree != (free_func)0x0)) {
    s = (void *)strm->state[5].dummy;
    if (s != (void *)0x0) {
      inflate_blocks_free(s,strm);
    }
    (*strm->zfree)(strm->opaque,strm->state);
    strm->state = (internal_state *)0x0;
    return 0;
  }
  return -2;
}



