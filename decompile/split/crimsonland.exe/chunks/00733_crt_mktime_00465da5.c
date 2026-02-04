/* crt_mktime @ 00465da5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CRT: convert date/time to timestamp (mktime) */

long __cdecl crt_mktime(int year,int month,int day,int hour,int min,int sec,int dst)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_28 [2];
  int local_20;
  int local_18;
  uint local_14;
  int local_c;
  
  uVar3 = year - 0x76c;
  if (((int)uVar3 < 0x46) || (0x8a < (int)uVar3)) {
    iVar2 = -1;
  }
  else {
    iVar4 = *(int *)(&DAT_0047df54 + month * 4) + day;
    if (((uVar3 & 3) == 0) && (2 < month)) {
      iVar4 = iVar4 + 1;
    }
    FUN_0046c5ad();
    local_20 = hour;
    local_18 = month + -1;
    iVar2 = ((hour + (uVar3 * 0x16d + iVar4 + (year + -0x76d >> 2)) * 0x18) * 0x3c + min) * 0x3c +
            DAT_0047de70 + 0x7c558180 + sec;
    if ((dst == 1) ||
       (((dst == -1 && (DAT_0047de74 != 0)) &&
        (local_14 = uVar3, local_c = iVar4, bVar1 = FUN_0046c862(local_28),
        CONCAT31(extraout_var,bVar1) != 0)))) {
      iVar2 = iVar2 + _DAT_0047de78;
    }
  }
  return iVar2;
}



