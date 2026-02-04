/* FUN_00452f1d @ 00452f1d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_452f1d() */

int FUN_00452f1d(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x00452f24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*_DAT_00479658)();
  return iVar1;
}



