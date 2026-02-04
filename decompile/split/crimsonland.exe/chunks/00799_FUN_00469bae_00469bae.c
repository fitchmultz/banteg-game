/* FUN_00469bae @ 00469bae */

/* [binja] void* sub_469bae(void* arg1, int32_t arg2, char* arg3, char* arg4) */

void * __cdecl FUN_00469bae(void *arg1,int arg2,char *arg3,char *arg4)

{
  int *dst;
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  void *pvVar3;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  void *extraout_EAX;
  size_t size;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0046fff8;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  pvVar3 = *(void **)(arg3 + 4);
  if (pvVar3 == (void *)0x0) {
    return (void *)0x0;
  }
  if (*(char *)((int)pvVar3 + 8) == '\0') {
    return pvVar3;
  }
  if (*(int *)(arg3 + 8) == 0) {
    return (void *)0x0;
  }
  dst = (int *)(*(int *)(arg3 + 8) + 0xc + arg2);
  local_8 = 0;
  if ((*arg3 & 8U) == 0) {
    if ((*arg4 & 1U) == 0) {
      if (*(int *)(arg4 + 0x18) == 0) {
        ExceptionList = &local_14;
        bVar1 = FUN_0046d6d3(*(void **)((int)arg1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar1) != 0) &&
           (bVar1 = FUN_0046d6ef(dst,1), CONCAT31(extraout_var_04,bVar1) != 0)) {
          size = *(size_t *)(arg4 + 0x14);
          pvVar3 = (void *)FUN_00469dd9(*(int *)((int)arg1 + 0x18),(int *)(arg4 + 8));
          pvVar3 = crt_memmove(dst,pvVar3,size);
          ExceptionList = local_14;
          return pvVar3;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar1 = FUN_0046d6d3(*(void **)((int)arg1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar1) != 0) &&
            (bVar1 = FUN_0046d6ef(dst,1), CONCAT31(extraout_var_06,bVar1) != 0)) &&
           (bVar1 = FUN_0046d70b(*(FARPROC *)(arg4 + 0x18)), CONCAT31(extraout_var_07,bVar1) != 0))
        {
          if ((*arg4 & 4U) != 0) {
            FUN_00469dd9(*(int *)((int)arg1 + 0x18),(int *)(arg4 + 8));
            pvVar3 = (void *)FUN_0046332c((int)dst,*(void **)(arg4 + 0x18));
            ExceptionList = local_14;
            return pvVar3;
          }
          FUN_00469dd9(*(int *)((int)arg1 + 0x18),(int *)(arg4 + 8));
          pvVar3 = (void *)FUN_00463325((int)dst,*(void **)(arg4 + 0x18));
          ExceptionList = local_14;
          return pvVar3;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar1 = FUN_0046d6d3(*(void **)((int)arg1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar1) != 0) &&
         (bVar1 = FUN_0046d6ef(dst,1), CONCAT31(extraout_var_02,bVar1) != 0)) {
        pvVar3 = crt_memmove(dst,*(void **)((int)arg1 + 0x18),*(size_t *)(arg4 + 0x14));
        if (*(int *)(arg4 + 0x14) != 4) {
          ExceptionList = local_14;
          return pvVar3;
        }
        iVar2 = *dst;
        if (iVar2 == 0) {
          ExceptionList = local_14;
          return (void *)0x0;
        }
        goto LAB_00469c3c;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar1 = FUN_0046d6d3(*(void **)((int)arg1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar1) != 0) &&
       (bVar1 = FUN_0046d6ef(dst,1), CONCAT31(extraout_var_00,bVar1) != 0)) {
      iVar2 = *(int *)((int)arg1 + 0x18);
      *dst = iVar2;
LAB_00469c3c:
      pvVar3 = (void *)FUN_00469dd9(iVar2,(int *)(arg4 + 8));
      *dst = (int)pvVar3;
      ExceptionList = local_14;
      return pvVar3;
    }
  }
  crt_invalid_parameter_noinfo_noreturn();
  ExceptionList = local_14;
  return extraout_EAX;
}



