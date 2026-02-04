/* FUN_1001ed4a @ 1001ed4a */

void __cdecl FUN_1001ed4a(int param_1,double param_2,double param_3)

{
  if (0.05 < ABS(param_2 * param_3 - 1.0)) {
    *(byte *)(param_1 + 0x61) = *(byte *)(param_1 + 0x61) | 0x20;
  }
  *(float *)(param_1 + 0x130) = (float)param_3;
  *(float *)(param_1 + 0x134) = (float)param_2;
  return;
}



