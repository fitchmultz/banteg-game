/* FUN_004546fe @ 004546fe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_4546fe() */

int FUN_004546fe(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x00454705. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*_DAT_00479638)();
  return iVar1;
}



