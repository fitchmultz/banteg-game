/* FUN_1002318f @ 1002318f */

/* [binja] void* sub_1002318f(int32_t* arg1, int32_t* arg2, int32_t* arg3) */

void * __thiscall FUN_1002318f(void *this,int *arg1,int *arg2,int *arg3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  
  iVar3 = arg1[1];
  if ((int *)0x3b9ac9f0 < arg3) {
    FUN_1002317a(this,1);
  }
  piVar6 = arg3;
  if (((uint)arg3 & 7) != 0) {
    piVar6 = (int *)((int)arg3 + (8 - ((uint)arg3 & 7)));
  }
  if (((int)arg2 < 0) || (1 < (int)arg2)) {
    *(undefined4 *)(*arg1 + 0x14) = 0xc;
    *(int **)(*arg1 + 0x18) = arg2;
    (**(code **)*arg1)(arg1);
  }
  arg3 = (int *)0x0;
  piVar2 = (int *)(iVar3 + 0x30 + (int)arg2 * 4);
  piVar5 = (int *)*piVar2;
  if (piVar5 != (int *)0x0) {
    do {
      piVar4 = piVar5;
      piVar5 = piVar4;
      if (piVar6 <= (int *)piVar4[2]) break;
      piVar5 = (int *)*piVar4;
      arg3 = piVar4;
    } while (piVar5 != (int *)0x0);
    if (piVar5 != (int *)0x0) goto LAB_10023275;
  }
  piVar4 = piVar6 + 4;
  if (arg3 == (int *)0x0) {
    uVar7 = *(uint *)(&DAT_1004ea00 + (int)arg2 * 4);
  }
  else {
    uVar7 = *(uint *)(&DAT_1004ea08 + (int)arg2 * 4);
  }
  if (1000000000U - (int)piVar4 < uVar7) {
    uVar7 = 1000000000U - (int)piVar4;
  }
  while( true ) {
    iVar8 = uVar7 + (int)piVar4;
    piVar5 = (int *)FUN_1002e65a((uint)arg1);
    if (piVar5 != (int *)0x0) break;
    uVar7 = uVar7 >> 1;
    if (uVar7 < 0x32) {
      FUN_1002317a(iVar8,2);
    }
  }
  piVar1 = (int *)(iVar3 + 0x48);
  *piVar1 = (int)piVar4 + *piVar1 + uVar7;
  *piVar5 = 0;
  piVar5[1] = 0;
  piVar5[2] = uVar7 + (int)piVar6;
  if (arg3 == (int *)0x0) {
    arg3 = piVar2;
  }
  *arg3 = (int)piVar5;
LAB_10023275:
  iVar3 = piVar5[1];
  piVar5[2] = piVar5[2] - (int)piVar6;
  piVar5[1] = iVar3 + (int)piVar6;
  return (void *)(iVar3 + 0x10 + (int)piVar5);
}



