/* FUN_100134ea @ 100134ea */

void FUN_100134ea(void)

{
  int iVar1;
  
  iVar1 = FUN_1001bf5e();
  if (iVar1 == 0) {
    PTR_FUN_10054390 = FUN_10013195;
    PTR_FUN_10054394 = FUN_100132ec;
  }
  else {
    PTR_FUN_10054390 = FUN_100133d4;
    PTR_FUN_10054394 = FUN_100133d4;
  }
                    /* WARNING: Could not recover jumptable at 0x1001351c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_10054390)();
  return;
}



