/* format_ordinal @ 00406180 */

/* formats an integer as an English ordinal (e.g. 1st/2nd/3rd/4th) into a global scratch buffer */

char * format_ordinal(int n)

{
  int iVar1;
  undefined *puVar2;
  
  if ((n < 8) || (0x14 < n)) {
    iVar1 = n % 10;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        puVar2 = &DAT_00472080;
        goto LAB_004061c7;
      }
      if (iVar1 == 2) {
        puVar2 = &DAT_0047207c;
        goto LAB_004061c7;
      }
      if (iVar1 == 3) {
        puVar2 = &DAT_00472078;
        goto LAB_004061c7;
      }
    }
  }
  puVar2 = &DAT_00472074;
LAB_004061c7:
  crt_sprintf(&DAT_004802c8,&DAT_0047206c,n,puVar2);
  return &DAT_004802c8;
}



