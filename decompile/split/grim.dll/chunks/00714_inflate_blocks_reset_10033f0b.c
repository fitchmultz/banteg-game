/* inflate_blocks_reset @ 10033f0b */

/* zlib (internal): reset inflate blocks state */

void __cdecl inflate_blocks_reset(void *s,z_streamp z,uLongf *c)

{
  uLong uVar1;
  
  if (c != (uLongf *)0x0) {
    *c = *(uLongf *)((int)s + 0x3c);
  }
  if ((*(int *)s == 4) || (*(int *)s == 5)) {
    (*z->zfree)(z->opaque,*(voidpf *)((int)s + 0xc));
  }
  if (*(int *)s == 6) {
    inflate_codes_free(*(void **)((int)s + 4),z);
  }
  *(undefined4 *)((int)s + 0x34) = *(undefined4 *)((int)s + 0x28);
  *(undefined4 *)((int)s + 0x30) = *(undefined4 *)((int)s + 0x28);
  *(undefined4 *)s = 0;
  *(undefined4 *)((int)s + 0x1c) = 0;
  *(undefined4 *)((int)s + 0x20) = 0;
  if (*(code **)((int)s + 0x38) != (code *)0x0) {
    uVar1 = (**(code **)((int)s + 0x38))(0,0,0);
    *(uLong *)((int)s + 0x3c) = uVar1;
    z->adler = uVar1;
  }
  return;
}



