/* FUN_00453ca0 @ 00453ca0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_453ca0() */

int FUN_00453ca0(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x00453ca7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*_DAT_00479634)();
  return iVar1;
}



