/* inflate_blocks_new @ 10033f76 */

/* zlib (internal): allocate inflate blocks state */

void * __cdecl inflate_blocks_new(z_streamp z,void *check_func,uInt w)

{
  undefined4 *s;
  voidpf pvVar1;
  
  s = (*z->zalloc)(z->opaque,1,0x40);
  if (s != (undefined4 *)0x0) {
    pvVar1 = (*z->zalloc)(z->opaque,8,0x5a0);
    s[9] = pvVar1;
    if (pvVar1 != (voidpf)0x0) {
      pvVar1 = (*z->zalloc)(z->opaque,1,w);
      s[10] = pvVar1;
      if (pvVar1 == (voidpf)0x0) {
        (*z->zfree)(z->opaque,(voidpf)s[9]);
        (*z->zfree)(z->opaque,s);
        return (void *)0x0;
      }
      *s = 0;
      s[0xb] = (int)pvVar1 + w;
      s[0xe] = check_func;
      inflate_blocks_reset(s,z,(uLongf *)0x0);
      return s;
    }
    (*z->zfree)(z->opaque,s);
  }
  return (void *)0x0;
}



