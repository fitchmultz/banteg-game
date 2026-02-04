/* FUN_0045315a @ 0045315a */

/* [binja] int32_t sub_45315a() */

int FUN_0045315a(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x00453161. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_FUN_004795bc)();
  return iVar1;
}



