/* png_get_uint_32 @ 100247e4 */

/* read big-endian 32-bit value */

png_uint_32 __cdecl png_get_uint_32(png_bytep buf)

{
  return CONCAT31(CONCAT21(CONCAT11(*buf,buf[1]),buf[2]),buf[3]);
}



