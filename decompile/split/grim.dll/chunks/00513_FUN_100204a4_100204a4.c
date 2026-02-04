/* FUN_100204a4 @ 100204a4 */

void __cdecl FUN_100204a4(png_structp png_ptr,png_voidp param_2,png_rw_ptr param_3)

{
  png_ptr->io_ptr = param_2;
  png_ptr->read_data_fn = param_3;
  if (png_ptr->write_data_fn != (png_rw_ptr)0x0) {
    png_ptr->write_data_fn = (png_rw_ptr)0x0;
    png_warning(png_ptr,"It\'s an error to set both read_data_fn and write_data_fn in the ");
    png_warning(png_ptr,"same structure.  Resetting write_data_fn to NULL.");
  }
  png_ptr[1].jmpbuf[0] = 0;
  return;
}



