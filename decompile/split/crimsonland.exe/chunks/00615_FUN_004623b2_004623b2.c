/* FUN_004623b2 @ 004623b2 */

/* [binja] int32_t sub_4623b2(int32_t* arg1) */

int __cdecl FUN_004623b2(int *arg1)

{
  DWORD DVar1;
  long lVar2;
  _TIME_ZONE_INFORMATION local_d0;
  _SYSTEMTIME local_24;
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  GetSystemTime(&local_24);
  if (local_24.wMinute == DAT_004d9978._2_2_) {
    if (local_24.wHour == (WORD)DAT_004d9978) {
      if (local_24.wDay == DAT_004d9974._2_2_) {
        if (local_24.wMonth == DAT_004d9970._2_2_) {
          if (local_24.wYear == (WORD)DAT_004d9970) goto LAB_0046245c;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_d0);
  if (DVar1 == 0xffffffff) {
    DAT_004d9968 = -1;
  }
  else if (((DVar1 == 2) && (local_d0.DaylightDate.wMonth != 0)) && (local_d0.DaylightBias != 0)) {
    DAT_004d9968 = 1;
  }
  else {
    DAT_004d9968 = 0;
  }
  DAT_004d9970._0_2_ = local_24.wYear;
  DAT_004d9970._2_2_ = local_24.wMonth;
  DAT_004d9974._0_2_ = local_24.wDayOfWeek;
  DAT_004d9974._2_2_ = local_24.wDay;
  DAT_004d9978._0_2_ = local_24.wHour;
  DAT_004d9978._2_2_ = local_24.wMinute;
  DAT_004d997c._0_2_ = local_24.wSecond;
  DAT_004d997c._2_2_ = local_24.wMilliseconds;
LAB_0046245c:
  lVar2 = crt_mktime((uint)local_14.wYear,(uint)local_14.wMonth,(uint)local_14.wDay,
                     (uint)local_14.wHour,(uint)local_14.wMinute,(uint)local_14.wSecond,DAT_004d9968
                    );
  if (arg1 != (int *)0x0) {
    *arg1 = lVar2;
  }
  return lVar2;
}



