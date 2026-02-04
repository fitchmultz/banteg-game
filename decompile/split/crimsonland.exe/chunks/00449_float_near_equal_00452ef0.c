/* float_near_equal @ 00452ef0 */

/* returns 1 when |a-b| < 1.1920929e-07 (FLT_EPSILON) */

int __cdecl float_near_equal(float a,float b)

{
  float fVar1;
  
  fVar1 = a - b;
  if ((!NAN(fVar1) && -1.1920929e-07 < fVar1 != (fVar1 == -1.1920929e-07)) &&
     (fVar1 < 1.1920929e-07 != (fVar1 == 1.1920929e-07))) {
    return 1;
  }
  return 0;
}



