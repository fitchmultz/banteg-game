/* png_crc_read @ 10024807 */

/* read PNG chunk data and update CRC */

void __cdecl png_crc_read(png_structp png_ptr,png_bytep buf,png_uint_32 length)

{
  png_read_data(png_ptr,buf,length);
  png_calculate_crc(png_ptr,buf,length);
  return;
}



