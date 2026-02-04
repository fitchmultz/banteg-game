/* FUN_1000f296 @ 1000f296 */

/* [binja] int32_t* __stdcall sub_1000f296(int32_t* arg1, float arg2) */

int * FUN_1000f296(int *arg1,float arg2)

{
  float a;
  int iVar1;
  float *extraout_ECX;
  float fVar2;
  
  a = *(float *)((int)arg2 + 4) * *(float *)((int)arg2 + 4) + *(float *)arg2 * *(float *)arg2;
  iVar1 = float_near_equal(a,1.0);
  if (iVar1 == 0) {
    if (a <= 1.1754944e-38) {
      *arg1 = 0;
      arg1[1] = 0;
      return arg1;
    }
    fVar2 = (1.0 / SQRT(a)) * extraout_ECX[1];
    *arg1 = (int)((1.0 / SQRT(a)) * *extraout_ECX);
  }
  else {
    if ((float *)arg1 == extraout_ECX) {
      return arg1;
    }
    *arg1 = (int)*extraout_ECX;
    fVar2 = extraout_ECX[1];
  }
  arg1[1] = (int)fVar2;
  return arg1;
}



