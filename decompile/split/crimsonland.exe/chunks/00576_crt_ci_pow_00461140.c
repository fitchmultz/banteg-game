/* crt_ci_pow @ 00461140 */

/* x87 helper for pow(base, exp) using ST0/ST1 */

void crt_ci_pow(void)

{
  float10 in_ST0;
  float10 in_ST1;
  
  FUN_00461162(SUB84((double)in_ST1,0),(uint)((ulonglong)(double)in_ST1 >> 0x20),
               SUB84((double)in_ST0,0),(uint)((ulonglong)(double)in_ST0 >> 0x20));
  return;
}



