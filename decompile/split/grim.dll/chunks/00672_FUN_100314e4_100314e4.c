/* FUN_100314e4 @ 100314e4 */

/* [binja] int32_t* sub_100314e4(void* arg1, int32_t* arg2, int32_t* arg3) */

int * __cdecl FUN_100314e4(void *arg1,int *arg2,int *arg3)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  int *in_stack_00000010;
  
  iVar2 = *in_stack_00000010;
  iVar7 = 0;
  piVar4 = in_stack_00000010;
  if (0 < *(int *)((int)arg1 + 0x110)) {
    in_stack_00000010 = arg3;
    do {
      puVar6 = (undefined1 *)*in_stack_00000010;
      puVar5 = *(undefined1 **)(iVar2 + iVar7 * 4);
      puVar3 = puVar5 + *(int *)((int)arg1 + 0x5c);
      for (; puVar5 < puVar3; puVar5 = puVar5 + 2) {
        uVar1 = *puVar6;
        puVar6 = puVar6 + 1;
        *puVar5 = uVar1;
        puVar5[1] = uVar1;
      }
      piVar4 = (int *)FUN_10022bab(iVar2,iVar7,iVar2,iVar7 + 1,1,*(uint *)((int)arg1 + 0x5c));
      in_stack_00000010 = in_stack_00000010 + 1;
      iVar7 = iVar7 + 2;
    } while (iVar7 < *(int *)((int)arg1 + 0x110));
  }
  return piVar4;
}



