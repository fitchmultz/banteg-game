/* FUN_00463325 @ 00463325 */

/* [binja] int32_t sub_463325(int32_t arg1, void* const arg2) */

int FUN_00463325(int arg1,void *arg2)

{
  int iVar1;
  
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0046332a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*arg2)();
  return iVar1;
}



