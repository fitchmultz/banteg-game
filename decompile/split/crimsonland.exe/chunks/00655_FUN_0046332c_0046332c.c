/* FUN_0046332c @ 0046332c */

/* [binja] int32_t sub_46332c(int32_t arg1, void* const arg2) */

int FUN_0046332c(int arg1,void *arg2)

{
  int iVar1;
  
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00463331. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*arg2)();
  return iVar1;
}



