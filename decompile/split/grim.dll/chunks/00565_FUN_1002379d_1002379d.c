/* FUN_1002379d @ 1002379d */

int __cdecl FUN_1002379d(int *param_1,int *param_2,uint param_3,uint param_4,char param_5)

{
  uint uVar1;
  uint size;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_3 + param_4;
  if ((((uint)param_2[1] < uVar1) || ((uint)param_2[3] < param_4)) || (*param_2 == 0)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 < (uint)param_2[6]) || ((uint)(param_2[4] + param_2[6]) < uVar1)) {
    if (*(char *)((int)param_2 + 0x22) == '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 0x44;
      (**(code **)*param_1)(param_1);
    }
    if (*(char *)((int)param_2 + 0x21) != '\0') {
      FUN_1002368a(param_1,'\x01');
      *(undefined1 *)((int)param_2 + 0x21) = 0;
    }
    uVar3 = param_3;
    if ((param_3 <= (uint)param_2[6]) && (uVar3 = uVar1 - param_2[4], (int)uVar3 < 0)) {
      uVar3 = 0;
    }
    param_2[6] = uVar3;
    FUN_1002368a(param_1,'\0');
  }
  uVar3 = param_2[7];
  if (uVar3 < uVar1) {
    if ((uVar3 < param_3) && (uVar3 = param_3, param_5 != '\0')) {
      *(undefined4 *)(*param_1 + 0x14) = 0x14;
      (**(code **)*param_1)(param_1);
    }
    if (param_5 != '\0') {
      param_2[7] = uVar1;
    }
    if ((char)param_2[8] != '\0') {
      size = param_2[2];
      iVar2 = param_2[6];
      for (uVar3 = uVar3 - iVar2; uVar3 < uVar1 - iVar2; uVar3 = uVar3 + 1) {
        memzero(*(void **)(*param_2 + uVar3 * 4),size);
      }
      goto LAB_100238a1;
    }
    if (param_5 == '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 0x14;
      (**(code **)*param_1)(param_1);
      goto LAB_100238a1;
    }
  }
  else {
LAB_100238a1:
    if (param_5 == '\0') goto LAB_100238ab;
  }
  *(undefined1 *)((int)param_2 + 0x21) = 1;
LAB_100238ab:
  return *param_2 + (param_3 - param_2[6]) * 4;
}



