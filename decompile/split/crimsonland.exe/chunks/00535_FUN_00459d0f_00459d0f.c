/* FUN_00459d0f @ 00459d0f */

void FUN_00459d0f(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined8 *param_5,uint param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 local_20 [2];
  undefined8 local_10 [2];
  
  FUN_00459b4b(local_20,param_2,param_5,param_6);
  FUN_00459b4b(local_10,param_3,param_4,param_6);
  uVar1 = (ulonglong)param_6;
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar2 = PackedFloatingSUB(uVar1,uVar2);
  uVar2 = PackedFloatingMUL(uVar2,0x4000000040000000);
  FUN_00459b4b(param_1,local_20,local_10,(uint)uVar2);
  FastExitMediaState();
  return;
}



