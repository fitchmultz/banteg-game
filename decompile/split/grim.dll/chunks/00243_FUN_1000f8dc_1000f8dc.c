/* FUN_1000f8dc @ 1000f8dc */

/* [binja] float* __stdcall sub_1000f8dc(float* arg1, float arg2) */

float * FUN_1000f8dc(float *arg1,float arg2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar2 = *(float *)((int)arg2 + 0xc) * *(float *)((int)arg2 + 0xc) +
          *(float *)((int)arg2 + 8) * *(float *)((int)arg2 + 8) +
          *(float *)((int)arg2 + 4) * *(float *)((int)arg2 + 4) + *(float *)arg2 * *(float *)arg2;
  iVar3 = float_near_equal(fVar2,1.0);
  if (iVar3 == 0) {
    if (fVar2 <= 1.1754944e-38) {
      *arg1 = 0.0;
      arg1[1] = 0.0;
      arg1[2] = 0.0;
      arg1[3] = 0.0;
      return arg1;
    }
    fVar2 = 1.0 / SQRT(fVar2);
    local_14 = fVar2 * *(float *)arg2;
    local_10 = fVar2 * *(float *)((int)arg2 + 4);
    local_c = fVar2 * *(float *)((int)arg2 + 8);
    pfVar1 = (float *)((int)arg2 + 0xc);
    arg2 = (float)&local_14;
    local_8 = fVar2 * *pfVar1;
  }
  else if (arg1 == (float *)arg2) {
    return arg1;
  }
  *arg1 = *(float *)arg2;
  arg1[1] = *(float *)((int)arg2 + 4);
  arg1[2] = *(float *)((int)arg2 + 8);
  arg1[3] = *(float *)((int)arg2 + 0xc);
  return arg1;
}



