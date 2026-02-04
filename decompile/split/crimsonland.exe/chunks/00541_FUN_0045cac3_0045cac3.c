/* FUN_0045cac3 @ 0045cac3 */

void FUN_0045cac3(undefined8 *param_1,ulonglong *param_2)

{
  undefined8 extraout_MM0;
  undefined8 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  ulonglong local_20;
  uint local_18;
  
  local_20 = *param_2;
  local_18 = (uint)param_2[1];
  FUN_0045e832(&local_20,&local_20);
  math_sincos_packed();
  uVar1 = PackedFloatingSUBR(extraout_MM0,0x3f8000003f800000);
  uVar9 = (undefined4)((ulonglong)extraout_MM0 >> 0x20);
  uVar3 = (ulonglong)local_18;
  uVar4 = PackedFloatingMUL(CONCAT44(local_18,local_18),local_20);
  uVar1 = CONCAT44((int)uVar1,(int)uVar1);
  uVar2 = PackedFloatingMUL(CONCAT44(local_18,(int)(local_20 >> 0x20)),local_20);
  uVar8 = CONCAT44((int)extraout_MM0,(int)extraout_MM0);
  uVar2 = PackedFloatingMUL(uVar2,uVar1);
  uVar4 = PackedFloatingMUL(uVar4,uVar1);
  uVar5 = PackedFloatingMUL(local_20,local_20);
  uVar6 = PackedFloatingMUL(uVar3,uVar3);
  uVar5 = PackedFloatingMUL(uVar5,uVar1);
  uVar1 = PackedFloatingMUL(uVar6,uVar1);
  uVar5 = PackedFloatingADD(uVar5,uVar8);
  uVar7 = PackedFloatingADD(uVar1,uVar8);
  uVar1 = CONCAT44(uVar9,uVar9);
  uVar8 = PackedFloatingMUL(local_20,uVar1);
  uVar1 = PackedFloatingMUL(uVar3,uVar1);
  param_1[6] = 0;
  uVar6 = CONCAT44((int)uVar8,(int)uVar1);
  uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
  uVar8 = CONCAT44(uVar9,uVar9);
  param_1[5] = uVar7 & 0xffffffff;
  uVar1 = PackedFloatingSUB(uVar2,uVar6);
  uVar3 = PackedFloatingADD(uVar2,uVar6);
  uVar7 = PackedFloatingSUB(uVar4,uVar8);
  *param_1 = CONCAT44((int)uVar3,(int)uVar5);
  param_1[1] = uVar7 & 0xffffffff;
  uVar8 = PackedFloatingADD(CONCAT44((int)uVar4,(int)uVar4),uVar8);
  param_1[3] = uVar3 >> 0x20;
  param_1[7] = 0x3f80000000000000;
  param_1[4] = CONCAT44((int)((ulonglong)uVar1 >> 0x20),(int)((ulonglong)uVar8 >> 0x20));
  param_1[2] = CONCAT44((int)((ulonglong)uVar5 >> 0x20),(int)uVar1);
  FastExitMediaState();
  return;
}



