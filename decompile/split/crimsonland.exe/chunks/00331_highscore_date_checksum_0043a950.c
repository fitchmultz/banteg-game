/* highscore_date_checksum @ 0043a950 */

/* computes a week-of-year style checksum for high score validation */

int __cdecl highscore_date_checksum(int year,int month,int day)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (0xe - month) / 0xc;
  iVar2 = (year - iVar1) + 0x12c0;
  iVar1 = ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) + -0x7d2d +
          day + ((iVar2 / 400 + ((month + iVar1 * 0xc) * 0x99 + -0x1c9) / 5 + iVar2 * 0x16d) -
                iVar2 / 100);
  iVar2 = ((((iVar1 - iVar1 % 7) + 0x7bfd) % 0x23ab1) % 0x8eac) % 0x5b5;
  iVar1 = iVar2 / 0x5b4;
  return ((iVar2 - iVar1) % 0x16d + iVar1) / 7 + 1;
}



