/* FUN_00459536 @ 00459536 */

ulonglong FUN_00459536(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 extraout_MM0;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  
  uVar4 = *param_1;
  uVar1 = param_1[1];
  uVar5 = PackedFloatingMUL(uVar4,uVar4);
  uVar3 = PackedFloatingMUL(uVar1,uVar1);
  uVar5 = PackedFloatingADD(uVar5,uVar3);
  uVar5 = PackedFloatingAccumulate(uVar5,uVar5);
  uVar6 = PackedFloatingCompareGE(0x80000000800000,uVar5);
  uVar3 = PackedFloatingReciprocalSQRAprox(uVar3,uVar5);
  iVar2 = (int)uVar6;
  if (iVar2 == 0) {
    uVar6 = PackedFloatingMUL(uVar3,uVar3);
    if (param_2 != (undefined8 *)0x0) {
      uVar5 = PackedFloatingReciprocalSQRIter1(uVar6,uVar5);
      uVar3 = PackedFloatingReciprocalIter2(uVar5,uVar3);
      uVar5 = PackedFloatingMUL(uVar4,uVar3);
      uVar4 = PackedFloatingMUL(uVar3,uVar1);
      *param_2 = uVar5;
      *(int *)(param_2 + 1) = (int)uVar4;
    }
    uVar7 = CONCAT44(param_2,iVar2);
    if (param_3 != (undefined4 *)0x0) {
      uVar7 = math_acos_packed();
      uVar4 = PackedFloatingMUL(extraout_MM0,0x4000000040000000);
      *param_3 = (int)uVar4;
    }
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      *(undefined8 *)((int)param_2 + 4) = 0;
      *(undefined4 *)param_2 = 0x3f800000;
    }
    uVar7 = CONCAT44(param_2,iVar2);
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
      uVar7 = CONCAT44(param_2,iVar2);
    }
  }
  FastExitMediaState();
  return uVar7;
}



