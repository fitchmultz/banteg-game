/* FUN_10004970 @ 10004970 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004970(void)

{
  ulonglong uVar1;
  uint uVar2;
  
  DAT_10059dc4 = DAT_1005bad0;
  do {
    DAT_1005bad0 = timeGetTime();
    uVar2 = DAT_1005bad0 - DAT_10059dc4;
  } while (uVar2 < 2);
  if (DAT_1005a470 == '\0') {
    grim_time_ms = grim_time_ms + uVar2;
    DAT_1005d814 = DAT_1005d814 + 1;
    _grim_frame_dt = (float)uVar2 * _DAT_1005d3b0;
    DAT_1005d818 = DAT_1005d818 + uVar2;
  }
  else {
    _grim_frame_dt = 0.0;
    DAT_1005bad4 = DAT_1005bad4 + uVar2;
  }
  uVar2 = DAT_1005d814;
  if (500 < DAT_1005d818) {
    DAT_1005d814 = 0;
    uVar1 = (ulonglong)DAT_1005d818;
    DAT_1005d818 = DAT_1005d818 - 500;
    _grim_fps = (float)uVar2 / ((float)uVar1 * _DAT_1005d3b0);
  }
  return;
}



