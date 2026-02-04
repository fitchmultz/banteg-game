/* png_free @ 10024777 */

/* png free callback wrapper */

void __cdecl png_free(png_structp png_ptr,void *ptr)

{
  if ((png_ptr != (png_structp)0x0) && (ptr != (void *)0x0)) {
    free(ptr);
  }
  return;
}



