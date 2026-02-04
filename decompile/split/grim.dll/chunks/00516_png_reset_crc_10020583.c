/* png_reset_crc @ 10020583 */

/* reset png CRC state */

void __cdecl png_reset_crc(png_structp png_ptr)

{
  png_colorp ppVar1;
  
  ppVar1 = (png_colorp)FUN_10025aec(0,(byte *)0x0,0);
  png_ptr->palette = ppVar1;
  return;
}



