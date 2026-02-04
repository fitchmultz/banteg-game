/* FUN_1000b3b5 @ 1000b3b5 */

float10 __fastcall FUN_1000b3b5(int param_1)

{
  float *in_EAX;
  
  if (param_1 == 1) {
    return (float10)*in_EAX;
  }
  if (param_1 == 2) {
    return (float10)in_EAX[2];
  }
  if (param_1 == 4) {
    return (float10)in_EAX[1];
  }
  if (param_1 != 8) {
    if (param_1 != 0x10) {
      return (float10)0.0;
    }
    return (float10)*in_EAX * (float10)0.2125 +
           (float10)in_EAX[1] * (float10)0.7154 + (float10)in_EAX[2] * (float10)0.0721;
  }
  return (float10)in_EAX[3];
}



