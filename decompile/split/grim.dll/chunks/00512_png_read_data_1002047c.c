/* png_read_data @ 1002047c */

/* png read callback wrapper (errors if NULL) */

void __cdecl png_read_data(png_structp png_ptr,png_bytep data,png_uint_32 length)

{
  if (png_ptr->read_data_fn != (png_rw_ptr)0x0) {
    (*png_ptr->read_data_fn)(png_ptr,data,length);
    return;
  }
  png_error(png_ptr,"Call to NULL read function");
  return;
}



