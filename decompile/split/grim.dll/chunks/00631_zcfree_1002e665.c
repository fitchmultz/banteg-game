/* zcfree @ 1002e665 */

/* zlib (internal): default free wrapper */

void __cdecl zcfree(voidpf opaque,voidpf ptr)

{
  free(ptr);
  return;
}



