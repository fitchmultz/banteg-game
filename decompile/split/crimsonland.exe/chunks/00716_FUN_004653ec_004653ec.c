/* FUN_004653ec @ 004653ec */

undefined4 __cdecl FUN_004653ec(double param_1)

{
  uint uVar1;
  float10 fVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_0046325f(SUB84(param_1,0),(uint)((ulonglong)param_1 >> 0x20));
  if ((uVar1 & 0x90) == 0) {
    fVar2 = __frnd(param_1);
    if ((double)fVar2 == param_1) {
      fVar2 = __frnd(param_1 / 2.0);
      if (fVar2 == (float10)(param_1 / 2.0)) {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      return uVar3;
    }
  }
  return 0;
}



