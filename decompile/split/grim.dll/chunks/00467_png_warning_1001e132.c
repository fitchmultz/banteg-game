/* png_warning @ 1001e132 */

/* png warning handler: call warning_fn */

void __cdecl png_warning(png_structp png_ptr,char *msg)

{
  if (png_ptr->warning_fn != (png_error_ptr)0x0) {
    (*png_ptr->warning_fn)(png_ptr,msg);
  }
  return;
}



