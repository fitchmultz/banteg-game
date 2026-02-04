/* zcalloc @ 100348eb */

/* zlib (internal): default alloc wrapper (calloc) */

voidpf __cdecl zcalloc(voidpf opaque,uInt items,uInt size)

{
  void *pvVar1;
  
  pvVar1 = calloc(items,size);
  return pvVar1;
}



