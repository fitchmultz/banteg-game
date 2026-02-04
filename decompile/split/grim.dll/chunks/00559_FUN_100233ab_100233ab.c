/* FUN_100233ab @ 100233ab */

int __cdecl FUN_100233ab(int *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  int *piVar5;
  int *this;
  void *extraout_ECX;
  void *this_00;
  void *extraout_ECX_00;
  uint uVar6;
  uint uVar7;
  
  piVar5 = (int *)(param_3 * 0x80);
  uVar2 = (uint)(0x3b9ac9f0 / ZEXT48(piVar5));
  iVar1 = param_1[1];
  this = piVar5;
  if (uVar2 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x45;
    this = param_1;
    (**(code **)*param_1)();
  }
  if ((int)param_4 <= (int)uVar2) {
    uVar2 = param_4;
  }
  *(uint *)(iVar1 + 0x4c) = uVar2;
  pvVar3 = FUN_1002318f(this,param_1,(int *)param_2,(int *)(param_4 << 2));
  uVar7 = 0;
  this_00 = extraout_ECX;
  if (param_4 != 0) {
    do {
      if (param_4 - uVar7 <= uVar2) {
        uVar2 = param_4 - uVar7;
      }
      pvVar4 = FUN_1002328b(this_00,(uint)param_1,param_2,uVar2 * param_3 * 0x80);
      this_00 = extraout_ECX_00;
      for (uVar6 = uVar2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(void **)((int)pvVar3 + uVar7 * 4) = pvVar4;
        pvVar4 = (void *)((int)pvVar4 + (int)piVar5);
        uVar7 = uVar7 + 1;
        this_00 = (void *)0x0;
      }
    } while (uVar7 < param_4);
  }
  return (int)pvVar3;
}



