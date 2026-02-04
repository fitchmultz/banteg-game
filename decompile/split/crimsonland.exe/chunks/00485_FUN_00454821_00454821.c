/* FUN_00454821 @ 00454821 */

/* [binja] int32_t sub_454821() */

int FUN_00454821(void)

{
  int iVar1;
  
  renderer_select_backend(1);
                    /* WARNING: Could not recover jumptable at 0x0045482c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_FUN_0047963c)();
  return iVar1;
}



