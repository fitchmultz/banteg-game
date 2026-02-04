/* FUN_0045573b @ 0045573b */

/* [binja] float* __stdcall sub_45573b(float* arg1, float arg2) */

float * FUN_0045573b(float *arg1,float arg2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  
  fVar2 = *(float *)((int)arg2 + 8) * *(float *)((int)arg2 + 8) +
          *(float *)((int)arg2 + 4) * *(float *)((int)arg2 + 4) + *(float *)arg2 * *(float *)arg2;
  iVar3 = float_near_equal(fVar2,1.0);
  if (iVar3 == 0) {
    if (fVar2 <= 1.1754944e-38) {
      *arg1 = 0.0;
      arg1[1] = 0.0;
      arg1[2] = 0.0;
      return arg1;
    }
    fVar2 = 1.0 / SQRT(fVar2);
    local_10 = fVar2 * *(float *)arg2;
    local_c = fVar2 * *(float *)((int)arg2 + 4);
    pfVar1 = (float *)((int)arg2 + 8);
    arg2 = (float)&local_10;
    local_8 = fVar2 * *pfVar1;
  }
  else if (arg1 == (float *)arg2) {
    return arg1;
  }
  *arg1 = *(float *)arg2;
  arg1[1] = *(float *)((int)arg2 + 4);
  arg1[2] = *(float *)((int)arg2 + 8);
  return arg1;
}



