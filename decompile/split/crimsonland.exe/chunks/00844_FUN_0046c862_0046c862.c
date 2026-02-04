/* FUN_0046c862 @ 0046c862 */

bool __cdecl FUN_0046c862(int *param_1)

{
  bool bVar1;
  
  crt_lock(0xb);
  bVar1 = FUN_0046c883(param_1);
  crt_unlock(0xb);
  return bVar1;
}



