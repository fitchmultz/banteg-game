/* png_error @ 1001e114 */

/* png error handler: call error_fn then longjmp */

void png_error(png_structp png_ptr,char *msg)

{
  if (png_ptr->error_fn != (png_error_ptr)0x0) {
    (*png_ptr->error_fn)(png_ptr,msg);
  }
                    /* WARNING: Subroutine does not return */
  longjmp((int *)png_ptr,1);
}



