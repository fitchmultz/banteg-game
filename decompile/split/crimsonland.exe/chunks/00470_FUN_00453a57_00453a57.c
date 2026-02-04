/* FUN_00453a57 @ 00453a57 */

/* [binja] int32_t sub_453a57() */

int FUN_00453a57(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x00453a5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_FUN_004795ac)();
  return iVar1;
}



