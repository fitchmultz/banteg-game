/* FUN_00454560 @ 00454560 */

/* [binja] float* __stdcall sub_454560(float* arg1, float arg2) */

float * FUN_00454560(float *arg1,float arg2)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)fcos((float10)arg2);
  fVar2 = (float10)fsin((float10)arg2);
  *arg1 = (float)fVar1;
  arg1[1] = (float)fVar2;
  arg1[2] = 0.0;
  arg1[3] = 0.0;
  arg1[4] = -(float)fVar2;
  arg1[5] = (float)fVar1;
  arg1[6] = 0.0;
  arg1[7] = 0.0;
  arg1[8] = 0.0;
  arg1[9] = 0.0;
  arg1[10] = 1.0;
  arg1[0xb] = 0.0;
  arg1[0xc] = 0.0;
  arg1[0xd] = 0.0;
  arg1[0xe] = 0.0;
  arg1[0xf] = 1.0;
  return arg1;
}



