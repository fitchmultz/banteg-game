/* png_check_chunk_name @ 1002487f */

/* validate PNG chunk type characters */

void __cdecl png_check_chunk_name(png_structp png_ptr,png_bytep chunk_name)

{
  byte bVar1;
  
  bVar1 = *chunk_name;
  if (((((((bVar1 < 0x29) || (0x7a < bVar1)) || ((0x5a < bVar1 && (bVar1 < 0x61)))) ||
        ((bVar1 = chunk_name[1], bVar1 < 0x29 || (0x7a < bVar1)))) ||
       ((0x5a < bVar1 && (bVar1 < 0x61)))) ||
      ((((bVar1 = chunk_name[2], bVar1 < 0x29 || (0x7a < bVar1)) ||
        ((0x5a < bVar1 && (bVar1 < 0x61)))) ||
       ((bVar1 = chunk_name[3], bVar1 < 0x29 || (0x7a < bVar1)))))) ||
     ((0x5a < bVar1 && (bVar1 < 0x61)))) {
    FUN_1001e147(png_ptr,(undefined4 *)"invalid chunk type");
  }
  return;
}



