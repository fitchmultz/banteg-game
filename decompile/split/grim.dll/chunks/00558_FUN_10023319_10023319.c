/* FUN_10023319 @ 10023319 */

int __cdecl FUN_10023319(int *param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  int *this;
  void *extraout_ECX;
  void *this_00;
  void *extraout_ECX_00;
  uint uVar5;
  uint uVar6;
  
  uVar2 = (uint)(0x3b9ac9f0 / (ulonglong)param_3);
  iVar1 = param_1[1];
  this = param_1;
  if (uVar2 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x45;
    (**(code **)*param_1)();
  }
  if ((int)param_4 <= (int)uVar2) {
    uVar2 = param_4;
  }
  *(uint *)(iVar1 + 0x4c) = uVar2;
  pvVar3 = FUN_1002318f(this,param_1,(int *)param_2,(int *)(param_4 << 2));
  uVar6 = 0;
  this_00 = extraout_ECX;
  if (param_4 != 0) {
    do {
      if (param_4 - uVar6 <= uVar2) {
        uVar2 = param_4 - uVar6;
      }
      pvVar4 = FUN_1002328b(this_00,(uint)param_1,param_2,uVar2 * param_3);
      this_00 = extraout_ECX_00;
      for (uVar5 = uVar2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(void **)((int)pvVar3 + uVar6 * 4) = pvVar4;
        pvVar4 = (void *)((int)pvVar4 + param_3);
        uVar6 = uVar6 + 1;
        this_00 = (void *)0x0;
      }
    } while (uVar6 < param_4);
  }
  return (int)pvVar3;
}



