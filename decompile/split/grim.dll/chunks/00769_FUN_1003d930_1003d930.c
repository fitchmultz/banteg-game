/* FUN_1003d930 @ 1003d930 */

/* [binja] int32_t sub_1003d930(int32_t* arg1) */

int __cdecl FUN_1003d930(int *arg1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *in_stack_00000008;
  char in_stack_0000000c;
  
  iVar1 = in_stack_00000008[2];
  iVar3 = in_stack_00000008[4];
  iVar4 = in_stack_00000008[6] * iVar1;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      iVar2 = iVar3 - iVar5;
      if (in_stack_00000008[5] < iVar3 - iVar5) {
        iVar2 = in_stack_00000008[5];
      }
      iVar3 = in_stack_00000008[7] - (in_stack_00000008[6] + iVar5);
      if (iVar3 <= iVar2) {
        iVar2 = iVar3;
      }
      iVar3 = in_stack_00000008[1] - (in_stack_00000008[6] + iVar5);
      if (iVar3 <= iVar2) {
        iVar2 = iVar3;
      }
      if (iVar2 < 1) {
        return iVar2;
      }
      iVar2 = iVar2 * iVar1;
      if (in_stack_0000000c == '\0') {
        (*(code *)in_stack_00000008[10])
                  (arg1,in_stack_00000008 + 10,*(undefined4 *)(*in_stack_00000008 + iVar5 * 4),iVar4
                   ,iVar2);
      }
      else {
        (*(code *)in_stack_00000008[0xb])
                  (arg1,in_stack_00000008 + 10,*(undefined4 *)(*in_stack_00000008 + iVar5 * 4),iVar4
                   ,iVar2);
      }
      iVar3 = in_stack_00000008[4];
      iVar5 = iVar5 + in_stack_00000008[5];
      iVar4 = iVar4 + iVar2;
    } while (iVar5 < iVar3);
  }
  return iVar3;
}



