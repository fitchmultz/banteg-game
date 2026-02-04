/* FUN_1002856f @ 1002856f */

void FUN_1002856f(undefined8 *param_1,ulonglong *param_2,uint param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 local_18;
  uint local_10;
  
  FastExitMediaState();
  FUN_1002d2c2(&local_18,param_2);
  PackedFloatingMUL((ulonglong)param_3,0x3f0000003f000000);
  uVar1 = FUN_100354e0();
  uVar4 = (undefined4)(uVar1 >> 0x20);
  uVar3 = CONCAT44(uVar4,uVar4);
  uVar2 = PackedFloatingMUL(local_18,uVar3);
  uVar3 = PackedFloatingMUL((ulonglong)local_10,uVar3);
  *param_1 = uVar2;
  param_1[1] = CONCAT44((int)uVar1,(int)uVar3);
  FastExitMediaState();
  return;
}



