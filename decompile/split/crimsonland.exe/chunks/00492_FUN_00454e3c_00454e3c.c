/* FUN_00454e3c @ 00454e3c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_454e3c() */

int FUN_00454e3c(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x00454e43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*_DAT_00479650)();
  return iVar1;
}



