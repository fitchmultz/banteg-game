/* FUN_1002290c @ 1002290c */

/* [binja] float* __stdcall sub_1002290c(float* arg1, float* arg2) */

float * FUN_1002290c(float *arg1,float *arg2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float10 fVar5;
  
  fVar5 = (float10)*arg2 * (float10)*arg2 + (float10)arg2[1] * (float10)arg2[1] +
          (float10)arg2[2] * (float10)arg2[2];
  fVar1 = (float)fVar5;
  if (fVar1 == 0.0) {
    ffree(fVar5);
    *arg1 = 0.0;
    arg1[1] = 0.0;
    arg1[2] = 0.0;
  }
  else if ((uint)ABS((float)(fVar5 - (float10)1)) < 0x3727c5ad) {
    if (arg1 != arg2) {
      *arg1 = *arg2;
      arg1[1] = arg2[1];
      arg1[2] = arg2[2];
    }
  }
  else {
    uVar4 = (uint)fVar1 >> 0xc & 0xff8;
    fVar3 = ((float)((uint)fVar1 & 0xffffff | 0x3f000000) * *(float *)(&DAT_100544e0 + uVar4) +
            *(float *)(&DAT_100544e4 + uVar4)) * (float)(0xbeffffffU - (int)fVar1 >> 1 & 0xff800000)
    ;
    fVar1 = arg2[1];
    fVar2 = arg2[2];
    *arg1 = *arg2 * fVar3;
    arg1[1] = fVar1 * fVar3;
    arg1[2] = fVar2 * fVar3;
  }
  return arg1;
}



