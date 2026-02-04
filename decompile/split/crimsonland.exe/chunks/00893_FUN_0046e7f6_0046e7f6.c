/* FUN_0046e7f6 @ 0046e7f6 */

/* [binja] void* sub_46e7f6(int32_t* arg1) */

void * __cdecl FUN_0046e7f6(int *arg1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  if (arg1 != (int *)0x0) {
    iVar1 = *arg1;
    piVar2 = arg1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = _malloc(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    pcVar4 = (char *)*arg1;
    puVar6 = puVar3;
    while (pcVar4 != (char *)0x0) {
      arg1 = arg1 + 1;
      pcVar4 = strdup_malloc(pcVar4);
      *puVar6 = pcVar4;
      puVar6 = puVar6 + 1;
      pcVar4 = (char *)*arg1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (void *)0x0;
}



