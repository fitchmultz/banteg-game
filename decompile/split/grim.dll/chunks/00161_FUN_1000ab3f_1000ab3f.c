/* FUN_1000ab3f @ 1000ab3f */

int __cdecl FUN_1000ab3f(int *param_1,int param_2,int *param_3)

{
  int *arg2;
  uint uVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = 0xffffffff;
  piVar3 = &DAT_1004c388;
  do {
    if (*param_1 == 0) {
      return *piVar3;
    }
    arg2 = grim_format_info_lookup(*param_1);
    if ((*arg2 != 0) && ((arg2[1] != 1 || (param_2 != 0)))) {
      if (*param_3 == *arg2) {
        return *param_3;
      }
      uVar1 = FUN_1000aaca(param_3,(int)arg2);
      if (((uVar1 != 0xffffffff) && (uVar1 <= uVar2)) &&
         ((uVar1 != uVar2 || ((uint)arg2[2] < (uint)piVar3[2])))) {
        uVar2 = uVar1;
        piVar3 = arg2;
      }
    }
    param_1 = param_1 + 1;
  } while( true );
}



