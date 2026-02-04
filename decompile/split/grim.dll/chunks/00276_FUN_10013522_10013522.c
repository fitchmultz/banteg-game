/* FUN_10013522 @ 10013522 */

void FUN_10013522(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = FUN_1001bf5e();
  if (iVar1 == 0) {
    PTR_FUN_10054390 = FUN_10013195;
    UNRECOVERED_JUMPTABLE = FUN_100132ec;
  }
  else {
    UNRECOVERED_JUMPTABLE = FUN_100133d4;
    PTR_FUN_10054390 = FUN_100133d4;
  }
  PTR_FUN_10054394 = UNRECOVERED_JUMPTABLE;
                    /* WARNING: Could not recover jumptable at 0x1001354f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



