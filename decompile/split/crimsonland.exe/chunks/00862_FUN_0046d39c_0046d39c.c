/* FUN_0046d39c @ 0046d39c */

int __cdecl FUN_0046d39c(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_004d9cb0 = 1;
                    /* WARNING: Could not recover jumptable at 0x0046d3b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_004d9cb0 = 1;
                    /* WARNING: Could not recover jumptable at 0x0046d3cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_004d9a5c;
  }
  DAT_004d9cb0 = (uint)bVar2;
  return param_1;
}



