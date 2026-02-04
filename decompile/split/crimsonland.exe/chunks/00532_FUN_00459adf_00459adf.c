/* FUN_00459adf @ 00459adf */

void FUN_00459adf(undefined8 *param_1,ulonglong *param_2,uint param_3)

{
  undefined8 extraout_MM0;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined8 local_18;
  uint local_10;
  
  FastExitMediaState();
  FUN_0045e832(&local_18,param_2);
  PackedFloatingMUL((ulonglong)param_3,0x3f0000003f000000);
  math_sincos_packed();
  uVar3 = (undefined4)((ulonglong)extraout_MM0 >> 0x20);
  uVar2 = CONCAT44(uVar3,uVar3);
  uVar1 = PackedFloatingMUL(local_18,uVar2);
  uVar2 = PackedFloatingMUL((ulonglong)local_10,uVar2);
  *param_1 = uVar1;
  param_1[1] = CONCAT44((int)extraout_MM0,(int)uVar2);
  FastExitMediaState();
  return;
}



