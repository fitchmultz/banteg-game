/* png_malloc @ 10024741 */

/* png malloc wrapper (errors on OOM) */

void * __cdecl png_malloc(png_structp png_ptr,png_uint_32 size)

{
  void *pvVar1;
  
  if ((png_ptr != (png_structp)0x0) && (size != 0)) {
    pvVar1 = malloc(size);
    if (pvVar1 == (void *)0x0) {
      png_error(png_ptr,"Out of Memory");
    }
    return pvVar1;
  }
  return (void *)0x0;
}



