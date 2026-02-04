/* FUN_1002d7a7 @ 1002d7a7 */

ulonglong *
FUN_1002d7a7(ulonglong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            undefined8 *param_5,undefined8 *param_6)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar8;
  undefined8 uVar7;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = (undefined8 *)&local_44;
  switch(((param_6 != (undefined8 *)0x0) << 1 | param_5 != (undefined8 *)0x0) << 1 |
         param_4 != (undefined8 *)0x0) {
  case '\0':
    uStack_c = 0;
    uStack_10 = 0;
    uStack_14 = 0;
    uStack_18 = 0;
    uStack_20 = 0;
    uStack_24 = 0;
    uStack_28 = 0;
    uStack_2c = 0;
    uStack_34 = 0;
    uStack_38 = 0;
    uStack_3c = 0;
    uStack_40 = 0;
    uStack_8 = 0x3f800000;
    uStack_1c = 0x3f800000;
    uStack_30 = 0x3f800000;
    local_44 = 0x3f800000;
    break;
  case '\x01':
    puVar1 = param_4;
    break;
  case '\x02':
    puVar1 = param_5;
    break;
  case '\x03':
    FastExitMediaState();
    FUN_1002d5db((undefined8 *)&local_44,param_5,param_4);
    FastExitMediaState();
    break;
  case '\x04':
    puVar1 = param_6;
    break;
  case '\x05':
    FastExitMediaState();
    FUN_1002d5db((undefined8 *)&local_44,param_6,param_4);
    FastExitMediaState();
    break;
  case '\x06':
    FastExitMediaState();
    FUN_1002d5db((undefined8 *)&local_44,param_6,param_5);
    FastExitMediaState();
    break;
  case '\a':
    FastExitMediaState();
    FUN_1002d5db((undefined8 *)&local_44,param_6,param_5);
    FUN_1002d5db((undefined8 *)&local_44,(undefined8 *)&local_44,param_4);
    FastExitMediaState();
  }
  FUN_1002d550(param_1,param_2,puVar1);
  if (param_3 != (undefined8 *)0x0) {
    FastExitMediaState();
    uVar4 = param_3[2];
    uVar5 = PackedIntToFloatingDwordConv(*param_3,*param_3);
    uVar6 = PackedIntToFloatingDwordConv(param_3[1],param_3[1]);
    uVar2 = PackedFloatingADD(*param_1 ^ 0x8000000000000000,0x3f8000003f800000);
    uVar6 = PackedFloatingMUL(uVar6,0x3f0000003f000000);
    uVar8 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar7 = PackedFloatingSUB(CONCAT44(uVar8,uVar8),uVar4);
    uVar2 = PackedFloatingMUL(uVar2,uVar6);
    uVar6 = PackedFloatingMUL((ulonglong)(uint)param_1[1],uVar7);
    uVar4 = PackedFloatingADD(uVar6,uVar4);
    uVar3 = PackedFloatingADD(uVar2,uVar5);
    *param_1 = uVar3;
    *(int *)(param_1 + 1) = (int)uVar4;
    FastExitMediaState();
  }
  return param_1;
}



