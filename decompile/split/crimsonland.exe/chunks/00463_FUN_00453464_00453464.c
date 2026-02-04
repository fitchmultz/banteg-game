/* FUN_00453464 @ 00453464 */

/* [binja] int32_t sub_453464() */

int FUN_00453464(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x0045346b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_FUN_004795c8)();
  return iVar1;
}



