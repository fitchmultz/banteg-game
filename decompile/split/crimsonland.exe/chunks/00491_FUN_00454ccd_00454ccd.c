/* FUN_00454ccd @ 00454ccd */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_454ccd() */

int FUN_00454ccd(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x00454cd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*_DAT_004795ec)();
  return iVar1;
}



