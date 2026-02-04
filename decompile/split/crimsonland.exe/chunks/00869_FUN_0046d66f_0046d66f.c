/* FUN_0046d66f @ 0046d66f */

/* [binja] int32_t __stdcall sub_46d66f(int32_t* arg1) */

int FUN_0046d66f(int *arg1)

{
  int *piVar1;
  bool bVar2;
  int extraout_EAX;
  undefined3 extraout_var;
  int iVar3;
  
  piVar1 = (int *)*arg1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    crt_terminate();
    return extraout_EAX;
  }
  if ((DAT_004d9cc0 != (FARPROC)0x0) &&
     (bVar2 = FUN_0046d70b(DAT_004d9cc0), CONCAT31(extraout_var,bVar2) != 0)) {
    iVar3 = (*DAT_004d9cc0)(arg1);
    return iVar3;
  }
  return 0;
}



