/* FUN_1003d210 @ 1003d210 */

int __cdecl FUN_1003d210(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = param_1[1];
  if (0xffe0 < param_3) {
    *(undefined4 *)(*param_1 + 0x14) = 0x35;
    *(undefined4 *)(*param_1 + 0x18) = 1;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 & 7) != 0) {
    param_3 = param_3 + (8 - (param_3 & 7));
  }
  if ((param_2 < 0) || (1 < param_2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0xc;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  puVar3 = *(undefined4 **)(iVar1 + 0x30 + param_2 * 4);
  puVar2 = (undefined4 *)0x0;
  do {
    puVar4 = puVar3;
    if (puVar4 == (undefined4 *)0x0) {
LAB_1003d2a1:
      iVar6 = param_3 + 0x10;
      if (puVar2 == (undefined4 *)0x0) {
        uVar5 = *(uint *)(&DAT_10050540 + param_2 * 4);
      }
      else {
        uVar5 = *(uint *)(&DAT_10050548 + param_2 * 4);
      }
      if (0xfff0U - iVar6 < uVar5) {
        uVar5 = 0xfff0U - iVar6;
      }
      puVar4 = operator_new(uVar5 + iVar6);
      while (puVar4 == (undefined4 *)0x0) {
        uVar5 = uVar5 >> 1;
        if (uVar5 < 0x32) {
          *(undefined4 *)(*param_1 + 0x14) = 0x35;
          *(undefined4 *)(*param_1 + 0x18) = 2;
          (**(code **)*param_1)(param_1);
        }
        puVar4 = operator_new(uVar5 + iVar6);
      }
      *(uint *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) + uVar5 + iVar6;
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = uVar5 + param_3;
      if (puVar2 == (undefined4 *)0x0) {
        *(undefined4 **)(iVar1 + 0x30 + param_2 * 4) = puVar4;
      }
      else {
        *puVar2 = puVar4;
      }
LAB_1003d340:
      iVar1 = puVar4[1];
      puVar4[1] = iVar1 + param_3;
      puVar4[2] = puVar4[2] - param_3;
      return iVar1 + 0x10 + (int)puVar4;
    }
    if (param_3 <= (uint)puVar4[2]) {
      if (puVar4 != (undefined4 *)0x0) goto LAB_1003d340;
      goto LAB_1003d2a1;
    }
    puVar3 = (undefined4 *)*puVar4;
    puVar2 = puVar4;
  } while( true );
}



