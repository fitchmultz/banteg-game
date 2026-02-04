/* FUN_00453f63 @ 00453f63 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_453f63() */

int FUN_00453f63(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x00453f6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*_DAT_004795e8)();
  return iVar1;
}



