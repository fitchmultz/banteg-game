/* FUN_0046319d @ 0046319d */

void __cdecl FUN_0046319d(int param_1,uint param_2)

{
  uint in_EAX;
  bool in_ZF;
  ushort in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  undefined4 unaff_retaddr;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
      FUN_0046515c();
    }
LAB_0046322c:
    if (DAT_004d9960 == 0) {
      __startOneArgErrorHandling(&DAT_0047b190,0xd,in_FPUControlWord,unaff_retaddr,param_1,param_2);
      return;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      in_EAX = FUN_00465145();
      in_ST0 = extraout_ST0;
    }
    if (in_EAX < 0x3ff00000) {
      fpatan(SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)),in_ST0);
    }
    else if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_0046322c;
    if (DAT_004d9960 == 0) {
      __math_exit(&DAT_0047b190,0xd,unaff_retaddr,param_1,param_2);
      return;
    }
  }
  return;
}



