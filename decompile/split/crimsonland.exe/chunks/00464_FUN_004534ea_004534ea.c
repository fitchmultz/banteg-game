/* FUN_004534ea @ 004534ea */

/* [binja] int32_t sub_4534ea() */

int FUN_004534ea(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x004534f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_FUN_004795d8)();
  return iVar1;
}



