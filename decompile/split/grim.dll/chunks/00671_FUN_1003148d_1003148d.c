/* FUN_1003148d @ 1003148d */

/* [binja] int32_t* sub_1003148d(int32_t* arg1, int32_t arg2, int32_t* arg3) */

int * __cdecl FUN_1003148d(int *arg1,int arg2,int *arg3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int *piVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int *in_stack_00000010;
  
  piVar3 = in_stack_00000010;
  in_stack_00000010 = (int *)0x0;
  puVar6 = (undefined4 *)*piVar3;
  if (0 < arg1[0x44]) {
    iVar5 = (int)arg3 - (int)puVar6;
    do {
      puVar2 = (undefined1 *)*puVar6;
      puVar7 = *(undefined1 **)(iVar5 + (int)puVar6);
      puVar4 = puVar2 + arg1[0x17];
      for (; puVar2 < puVar4; puVar2 = puVar2 + 2) {
        uVar1 = *puVar7;
        puVar7 = puVar7 + 1;
        *puVar2 = uVar1;
        puVar2[1] = uVar1;
      }
      piVar3 = (int *)((int)in_stack_00000010 + 1);
      puVar6 = puVar6 + 1;
      in_stack_00000010 = piVar3;
    } while ((int)piVar3 < arg1[0x44]);
  }
  return piVar3;
}



