/* console_command_unregister @ 00402530 */

/* removes a console command entry by name */

char __thiscall console_command_unregister(void *this,char *name)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  
  pvVar3 = console_command_find(this,name);
  if (pvVar3 != (void *)0x0) {
    pvVar1 = *(void **)((int)this + 4);
    if (pvVar3 == pvVar1) {
      *(undefined4 *)((int)this + 4) = *(undefined4 *)((int)pvVar1 + 4);
      return '\x01';
    }
    while (pvVar2 = pvVar1, pvVar2 != (void *)0x0) {
      pvVar1 = *(void **)((int)pvVar2 + 4);
      if (*(void **)((int)pvVar2 + 4) == pvVar3) {
        *(undefined4 *)((int)pvVar2 + 4) = *(undefined4 *)(*(int *)((int)pvVar2 + 4) + 4);
        return '\x01';
      }
    }
  }
  return '\0';
}



