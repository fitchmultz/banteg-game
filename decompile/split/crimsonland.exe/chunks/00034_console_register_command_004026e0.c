/* console_register_command @ 004026e0 */

/* registers a console command and handler */

void __thiscall console_register_command(void *this,char *name,void *handler)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  
  puVar3 = operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    pcVar4 = strdup_malloc(name);
    *puVar3 = pcVar4;
    puVar3[1] = 0;
    puVar3[2] = 0;
  }
  puVar3[2] = handler;
  iVar1 = *(int *)((int)this + 4);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      iVar1 = iVar2;
    }
    *(undefined4 **)(iVar1 + 4) = puVar3;
    return;
  }
  *(undefined4 **)((int)this + 4) = puVar3;
  return;
}



