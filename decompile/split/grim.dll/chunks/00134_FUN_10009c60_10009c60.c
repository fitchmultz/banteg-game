/* FUN_10009c60 @ 10009c60 */

void __cdecl FUN_10009c60(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_1[8];
  if (iVar1 == 1) {
    param_1[9] = 1;
    param_1[10] = 1;
    goto LAB_10009daf;
  }
  if (iVar1 != 3) {
    if (iVar1 == 4) {
      if ((*(char *)((int)param_1 + 0x106) == '\0') || (*(char *)((int)param_1 + 0x107) == '\0')) {
        param_1[9] = 4;
        param_1[10] = 4;
      }
      else {
        if (*(char *)((int)param_1 + 0x107) != '\x02') {
          *(undefined4 *)(*param_1 + 0x14) = 0x6e;
          *(uint *)(*param_1 + 0x18) = (uint)*(byte *)((int)param_1 + 0x107);
          (**(code **)(*param_1 + 4))(param_1,0xffffffff);
        }
        param_1[9] = 5;
        param_1[10] = 4;
      }
    }
    else {
      param_1[9] = 0;
      param_1[10] = 0;
    }
    goto LAB_10009daf;
  }
  if ((char)param_1[0x40] == '\0') {
    if (*(char *)((int)param_1 + 0x106) == '\0') {
      piVar2 = (int *)param_1[0x31];
      iVar1 = *piVar2;
      iVar3 = piVar2[0x15];
      iVar4 = piVar2[0x2a];
      if (iVar1 == 1) {
        if ((iVar3 == 2) && (iVar4 == 3)) {
          param_1[9] = 3;
          param_1[10] = 2;
          goto LAB_10009daf;
        }
      }
      else if (((iVar1 == 0x52) && (iVar3 == 0x47)) && (iVar4 == 0x42)) goto LAB_10009d62;
      iVar5 = *param_1;
      *(int *)(iVar5 + 0x18) = iVar1;
      *(int *)(iVar5 + 0x1c) = iVar3;
      *(int *)(iVar5 + 0x20) = iVar4;
      *(undefined4 *)(*param_1 + 0x14) = 0x6b;
      (**(code **)(*param_1 + 4))(param_1,1);
    }
    else {
      if (*(char *)((int)param_1 + 0x107) == '\0') {
LAB_10009d62:
        param_1[9] = 2;
        param_1[10] = 2;
        goto LAB_10009daf;
      }
      if (*(char *)((int)param_1 + 0x107) != '\x01') {
        *(undefined4 *)(*param_1 + 0x14) = 0x6e;
        *(uint *)(*param_1 + 0x18) = (uint)*(byte *)((int)param_1 + 0x107);
        (**(code **)(*param_1 + 4))(param_1,0xffffffff);
      }
    }
  }
  param_1[9] = 3;
  param_1[10] = 2;
LAB_10009daf:
  param_1[0xe] = 0;
  param_1[0xb] = 1;
  param_1[0xc] = 1;
  param_1[0xf] = 0x3ff00000;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 0;
  param_1[0x11] = 0;
  *(undefined1 *)(param_1 + 0x12) = 1;
  *(undefined1 *)((int)param_1 + 0x49) = 1;
  *(undefined1 *)((int)param_1 + 0x4a) = 0;
  param_1[0x13] = 2;
  *(undefined1 *)(param_1 + 0x14) = 1;
  param_1[0x15] = 0x100;
  param_1[0x1d] = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x59) = 0;
  *(undefined1 *)((int)param_1 + 0x5a) = 0;
  return;
}



