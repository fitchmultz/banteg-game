/* inflate_blocks_free @ 1003479e */

/* zlib (internal): free inflate blocks state */

void __cdecl inflate_blocks_free(void *s,z_streamp z)

{
  inflate_blocks_reset(s,z,(uLongf *)0x0);
  (*z->zfree)(z->opaque,*(voidpf *)((int)s + 0x28));
  (*z->zfree)(z->opaque,*(voidpf *)((int)s + 0x24));
  (*z->zfree)(z->opaque,s);
  return;
}



