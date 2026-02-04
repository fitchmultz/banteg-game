/* FUN_00467d9e @ 00467d9e */

/* [binja] int32_t sub_467d9e(void* arg1, void** arg2, char* arg3, int32_t arg4) */

int __cdecl FUN_00467d9e(void *arg1,void **arg2,char *arg3,int arg4)

{
  void **ppvVar1;
  int *piVar2;
  char cVar3;
  void **ppvVar4;
  void *pvVar5;
  uint uVar6;
  
  uVar6 = (uint)(byte)*arg3;
  piVar2 = (int *)((int)arg1 + ((int)arg2 - *(int *)((int)arg1 + 0x10) >> 0xc) * 8 + 0x18);
  if ((uint)arg4 < uVar6) {
    *arg3 = (char)arg4;
    *piVar2 = *piVar2 + (uVar6 - arg4);
    piVar2[1] = 0xf1;
  }
  else {
    if ((uint)arg4 <= uVar6) {
      return 0;
    }
    ppvVar1 = (void **)(arg3 + arg4);
    if (arg2 + 0x3e < ppvVar1) {
      return 0;
    }
    for (ppvVar4 = (void **)(arg3 + uVar6); (ppvVar4 < ppvVar1 && (*(char *)ppvVar4 == '\0'));
        ppvVar4 = (void **)((int)ppvVar4 + 1)) {
    }
    if (ppvVar4 != ppvVar1) {
      return 0;
    }
    *arg3 = (char)arg4;
    if ((arg3 <= *arg2) && (*arg2 < ppvVar1)) {
      if (ppvVar1 < arg2 + 0x3e) {
        pvVar5 = (void *)0x0;
        *arg2 = ppvVar1;
        cVar3 = *(char *)ppvVar1;
        while (cVar3 == '\0') {
          pvVar5 = (void *)((int)pvVar5 + 1);
          cVar3 = *(char *)((int)ppvVar1 + (int)pvVar5);
        }
        arg2[1] = pvVar5;
      }
      else {
        arg2[1] = (void *)0x0;
        *arg2 = arg2 + 2;
      }
    }
    *piVar2 = *piVar2 + (uVar6 - arg4);
  }
  return 1;
}



