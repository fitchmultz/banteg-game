/* FUN_0046cfeb @ 0046cfeb */

uint __cdecl FUN_0046cfeb(LPWSTR param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_004da3b0);
  bVar2 = DAT_004da3ac != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_004da3b0);
    crt_lock(0x13);
  }
  uVar1 = FUN_0046d048(param_1,param_2,param_3);
  if (bVar2) {
    crt_unlock(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_004da3b0);
  }
  return uVar1;
}



