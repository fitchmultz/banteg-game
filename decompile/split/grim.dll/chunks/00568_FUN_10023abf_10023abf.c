/* FUN_10023abf @ 10023abf */

void __cdecl FUN_10023abf(int *param_1)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    FUN_100239de(param_1,iVar1);
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  zcfree(param_1,(voidpf)param_1[1]);
  param_1[1] = 0;
  FUN_10016c3b();
  return;
}



