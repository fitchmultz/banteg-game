/* FUN_10023aef @ 10023aef */

void __cdecl FUN_10023aef(int *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  param_1[1] = 0;
  uVar1 = FUN_1002e689();
  puVar2 = (undefined4 *)FUN_1002e65a((uint)param_1);
  if (puVar2 == (undefined4 *)0x0) {
    piVar5 = param_1;
    FUN_10016c3b();
    *(undefined4 *)(*param_1 + 0x14) = 0x35;
    *(undefined4 *)(*param_1 + 0x18) = 0;
    (**(code **)*param_1)(param_1,piVar5);
  }
  else {
    *puVar2 = FUN_1002318f;
    puVar2[1] = FUN_1002328b;
    puVar2[2] = FUN_10023319;
    puVar2[3] = FUN_100233ab;
    puVar2[4] = FUN_10023449;
    puVar2[5] = FUN_100234aa;
    puVar2[6] = FUN_1002350b;
    puVar2[7] = FUN_1002379d;
    puVar2[8] = FUN_100238bb;
    puVar2[9] = FUN_100239de;
    puVar2[10] = FUN_10023abf;
    puVar2[0xb] = uVar1;
    puVar3 = puVar2 + 0xf;
    iVar4 = 2;
    do {
      puVar3[-2] = 0;
      *puVar3 = 0;
      puVar3 = puVar3 + -1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    puVar2[0x12] = 0x50;
    param_1[1] = (int)puVar2;
  }
  return;
}



