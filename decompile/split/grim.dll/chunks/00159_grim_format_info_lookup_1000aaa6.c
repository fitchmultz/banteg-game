/* grim_format_info_lookup @ 1000aaa6 */

/* returns pointer to the D3D format descriptor entry (fallbacks to default) */

int * __cdecl grim_format_info_lookup(int format)

{
  int *piVar1;
  
  piVar1 = &DAT_1004c3b0;
  while( true ) {
    if (PTR_DAT_10053c50 <= piVar1) {
      return &DAT_1004c388;
    }
    if (format == *piVar1) break;
    piVar1 = piVar1 + 9;
  }
  return piVar1;
}



