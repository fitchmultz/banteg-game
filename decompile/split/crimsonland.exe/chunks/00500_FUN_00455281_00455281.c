/* FUN_00455281 @ 00455281 */

/* [binja] int32_t sub_455281() */

int FUN_00455281(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x00455288. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_FUN_004795f4)();
  return iVar1;
}



