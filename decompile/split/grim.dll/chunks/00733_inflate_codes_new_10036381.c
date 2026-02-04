/* inflate_codes_new @ 10036381 */

/* zlib (internal): allocate codes state */

void * __cdecl inflate_codes_new(uInt bl,uInt bd,void *tl,void *td,z_streamp z)

{
  undefined4 *puVar1;
  
  puVar1 = (*z->zalloc)(z->opaque,1,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 4) = (undefined1)bl;
    *(undefined1 *)((int)puVar1 + 0x11) = (undefined1)bd;
    puVar1[5] = tl;
    puVar1[6] = td;
  }
  return puVar1;
}



