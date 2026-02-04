/* FUN_00469696 @ 00469696 */

void __cdecl
FUN_00469696(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            char param_6,int param_7,PVOID param_8)

{
  byte *arg1;
  bool bVar1;
  DWORD *pDVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((int)param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    crt_invalid_parameter_noinfo_noreturn();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar2 = crt_get_thread_data();
      if (pDVar2[0x1b] == 0) {
        return;
      }
      pDVar2 = crt_get_thread_data();
      param_1 = (PEXCEPTION_RECORD)pDVar2[0x1b];
      pDVar2 = crt_get_thread_data();
      param_3 = pDVar2[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar1 = FUN_0046d6d3(param_1,1);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        crt_invalid_parameter_noinfo_noreturn();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_0046981e;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        crt_invalid_parameter_noinfo_noreturn();
      }
    }
    iVar4 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar3 = (int *)FUN_0046355c(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_00469d72(param_1);
          return;
        }
        if ((*piVar3 <= iVar4) && (iVar4 <= piVar3[1])) {
          arg1 = (byte *)piVar3[4];
          for (local_10 = piVar3[3]; iVar4 = local_14, 0 < local_10; local_10 = local_10 + -1) {
            piVar5 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar5; 0 < local_c; local_c = local_c + -1) {
              piVar5 = piVar5 + 1;
              iVar4 = FUN_004698f3((char *)arg1,(char *)*piVar5,
                                   (int *)param_1->ExceptionInformation[2]);
              if (iVar4 != 0) {
                FUN_004699ee(param_1,param_2,param_3,param_4,param_5,arg1,(byte *)*piVar5,piVar3,
                             param_7,param_8);
                iVar4 = local_14;
                goto LAB_004697fe;
              }
            }
            arg1 = arg1 + 0x10;
          }
        }
LAB_004697fe:
        local_8 = local_8 + 1;
        piVar3 = piVar3 + 5;
      } while( true );
    }
  }
LAB_0046981e:
  if (param_6 == '\0') {
    FUN_00469849(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  crt_terminate();
  return;
}



