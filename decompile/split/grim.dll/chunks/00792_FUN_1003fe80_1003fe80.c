/* FUN_1003fe80 @ 1003fe80 */

undefined4 __cdecl FUN_1003fe80(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = param_1[1];
  pbVar3 = (byte *)*param_1;
  for (; param_3 < 0x19; param_3 = param_3 + 8) {
    in_EAX = param_1[2];
    if (in_EAX == 0) {
      if (iVar2 == 0) {
        uVar1 = (**(code **)(*(int *)(param_1[5] + 0x14) + 0xc))(param_1[5]);
        if ((char)uVar1 == '\0') {
LAB_1003ff70:
          return uVar1 & 0xffffff00;
        }
        pbVar3 = (byte *)**(undefined4 **)(param_1[5] + 0x14);
        iVar2 = (*(undefined4 **)(param_1[5] + 0x14))[1];
      }
      in_EAX = (uint)*pbVar3;
      iVar2 = iVar2 + -1;
      pbVar3 = pbVar3 + 1;
      if (in_EAX == 0xff) {
        do {
          if (iVar2 == 0) {
            uVar1 = (**(code **)(*(int *)(param_1[5] + 0x14) + 0xc))(param_1[5]);
            if ((char)uVar1 == '\0') goto LAB_1003ff70;
            pbVar3 = (byte *)**(undefined4 **)(param_1[5] + 0x14);
            iVar2 = (*(undefined4 **)(param_1[5] + 0x14))[1];
          }
          in_EAX = (uint)*pbVar3;
          iVar2 = iVar2 + -1;
          pbVar3 = pbVar3 + 1;
        } while (in_EAX == 0xff);
        if (in_EAX != 0) {
          param_1[2] = in_EAX;
          goto LAB_1003ff11;
        }
        in_EAX = 0xff;
      }
    }
    else {
LAB_1003ff11:
      if (param_4 <= param_3) break;
      if (*(char *)param_1[6] == '\0') {
        *(undefined4 *)(*(int *)param_1[5] + 0x14) = 0x71;
        (**(code **)(*(int *)param_1[5] + 4))((int *)param_1[5],0xffffffff);
        *(undefined1 *)param_1[6] = 1;
      }
      in_EAX = 0;
    }
    param_2 = param_2 << 8 | in_EAX;
  }
  *param_1 = pbVar3;
  param_1[1] = iVar2;
  param_1[4] = param_3;
  param_1[3] = param_2;
  return CONCAT31((int3)(in_EAX >> 8),1);
}



