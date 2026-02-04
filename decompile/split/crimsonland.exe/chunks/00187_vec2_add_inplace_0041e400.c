/* vec2_add_inplace @ 0041e400 */

/* adds delta XY into pos; unused param_1 in decompile */

void __cdecl vec2_add_inplace(int unused,float *pos,float *delta)

{
  *pos = *pos + *delta;
  pos[1] = delta[1] + pos[1];
  return;
}



