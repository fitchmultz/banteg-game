/* FUN_004698f3 @ 004698f3 */

/* [binja] int32_t sub_4698f3(char* arg1, char* arg2, int32_t* arg3) */

int __cdecl FUN_004698f3(char *arg1,char *arg2,int *arg3)

{
  int iVar1;
  
  iVar1 = *(int *)(arg1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_0046994a:
    iVar1 = 1;
  }
  else {
    if (iVar1 == *(int *)(arg2 + 4)) {
LAB_00469924:
      if (((((*arg2 & 2U) == 0) || ((*arg1 & 8U) != 0)) &&
          (((*arg3 & 1U) == 0 || ((*arg1 & 1U) != 0)))) &&
         (((*arg3 & 2U) == 0 || ((*arg1 & 2U) != 0)))) goto LAB_0046994a;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(arg2 + 4) + 8));
      if (iVar1 == 0) goto LAB_00469924;
    }
    iVar1 = 0;
  }
  return iVar1;
}



