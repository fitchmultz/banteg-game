/* inflate_codes_free @ 10036919 */

/* zlib (internal): free codes state */

void __cdecl inflate_codes_free(void *c,z_streamp z)

{
  (*z->zfree)(z->opaque,c);
  return;
}



