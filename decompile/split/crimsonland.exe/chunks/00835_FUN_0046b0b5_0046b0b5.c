/* FUN_0046b0b5 @ 0046b0b5 */

int __cdecl FUN_0046b0b5(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_004da3b0);
  bVar2 = DAT_004da3ac != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_004da3b0);
    crt_lock(0x13);
  }
  iVar1 = FUN_0046b10e(param_1,param_2);
  if (bVar2) {
    crt_unlock(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_004da3b0);
  }
  return iVar1;
}



