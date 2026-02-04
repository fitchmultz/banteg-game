/* FUN_004551b6 @ 004551b6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_4551b6() */

int FUN_004551b6(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x004551c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*_DAT_00479654)();
  return iVar1;
}



