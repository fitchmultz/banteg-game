/* console_push_line @ 004017a0 */

/* pushes line into console queue */

char __thiscall console_push_line(void *this,char *line)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  uint uVar6;
  
  uVar6 = (uint)*(byte *)((int)this + 0xc);
  if (*(byte *)((int)this + 0xc) != 0) {
    if (*(int *)((int)this + 0x20) == 0x1000) {
      iVar1 = *(int *)(*(int *)((int)this + 8) + 4);
      iVar2 = *(int *)(iVar1 + 4);
      iVar3 = *(int *)((int)this + 8);
      while (iVar2 != 0) {
        iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);
        iVar3 = iVar1;
        iVar1 = *(int *)(iVar1 + 4);
      }
      puVar4 = *(undefined4 **)(iVar3 + 4);
      if (puVar4 != (undefined4 *)0x0) {
        if ((void *)*puVar4 != (void *)0x0) {
          crt_free((void *)*puVar4);
        }
        *puVar4 = 0;
        if ((void *)puVar4[1] != (void *)0x0) {
          console_log_node_free((void *)puVar4[1],'\x01');
        }
        puVar4[1] = 0;
        crt_free(puVar4);
      }
      *(undefined4 *)(iVar3 + 4) = 0;
      *(int *)((int)this + 0x20) = *(int *)((int)this + 0x20) + -1;
    }
    puVar4 = operator_new(8);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[1] = 0;
      *puVar4 = 0;
    }
    pcVar5 = strdup_malloc(line);
    *puVar4 = pcVar5;
    puVar4[1] = *(undefined4 *)((int)this + 8);
    uVar6 = *(int *)((int)this + 0x20) + 1;
    *(undefined4 **)((int)this + 8) = puVar4;
    *(uint *)((int)this + 0x20) = uVar6;
  }
  return (char)uVar6;
}



