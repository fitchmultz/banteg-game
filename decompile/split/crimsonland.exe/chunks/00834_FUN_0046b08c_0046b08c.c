/* FUN_0046b08c @ 0046b08c */

byte __cdecl FUN_0046b08c(uint param_1)

{
  if ((uint)crt_nhandle <= param_1) {
    return 0;
  }
  return *(byte *)((&crt_pioinfo_table)[(int)param_1 >> 5] + (param_1 & 0x1f) * 9 + 1) & 0x40;
}



