/* FUN_1003aac0 @ 1003aac0 */

void __cdecl FUN_1003aac0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[5];
  if (0 < param_2) {
    iVar2 = piVar1[1];
    if (iVar2 < param_2) {
      do {
        param_2 = param_2 - iVar2;
        FUN_1003aa20(param_1);
        iVar2 = piVar1[1];
      } while (iVar2 < param_2);
    }
    *piVar1 = *piVar1 + param_2;
    piVar1[1] = piVar1[1] - param_2;
  }
  return;
}



