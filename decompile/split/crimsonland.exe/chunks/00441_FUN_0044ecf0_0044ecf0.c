/* FUN_0044ecf0 @ 0044ecf0 */

/* [binja] float* __thiscall sub_44ecf0(float* arg1, float* arg2, float* arg3) */

float * __thiscall FUN_0044ecf0(void *this,float *arg1,float *arg2,float *arg3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = arg2[1];
  fVar2 = *(float *)((int)this + 4);
  *arg1 = *arg2 + *(float *)this;
  arg1[1] = fVar1 + fVar2;
  return arg1;
}



