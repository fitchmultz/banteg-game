/* FUN_100161b6 @ 100161b6 */

/* [binja] int32_t __fastcall j_sub_10016131(char* arg1) */

int __fastcall FUN_100161b6(char *arg1)

{
  int *piVar1;
  
  piVar1 = *(int **)(arg1 + 8);
  if ((piVar1 != (int *)0x0) || (piVar1 = *(int **)(arg1 + 4), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x28))(piVar1);
  }
  if ((((*(int *)(arg1 + 4) != 0) && (*(int *)(arg1 + 8) != 0)) &&
      (piVar1 = *(int **)(arg1 + 0xc), piVar1 != (int *)0x0)) && ((*arg1 & 1U) == 0)) {
    (**(code **)(*piVar1 + 0x70))(piVar1,*(int *)(arg1 + 8),0,0,*(int *)(arg1 + 4),0);
  }
  piVar1 = *(int **)(arg1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    arg1[8] = '\0';
    arg1[9] = '\0';
    arg1[10] = '\0';
    arg1[0xb] = '\0';
  }
  piVar1 = *(int **)(arg1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    arg1[0xc] = '\0';
    arg1[0xd] = '\0';
    arg1[0xe] = '\0';
    arg1[0xf] = '\0';
  }
  arg1[4] = '\0';
  arg1[5] = '\0';
  arg1[6] = '\0';
  arg1[7] = '\0';
  return 0;
}



