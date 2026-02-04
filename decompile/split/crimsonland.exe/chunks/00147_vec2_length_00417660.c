/* vec2_length @ 00417660 */

/* returns sqrt(x*x + y*y) for a 2-float vector */

float __cdecl vec2_length(float *v)

{
  return SQRT(v[1] * v[1] + *v * *v);
}



