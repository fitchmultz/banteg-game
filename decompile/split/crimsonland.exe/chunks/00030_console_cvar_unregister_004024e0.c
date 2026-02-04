/* console_cvar_unregister @ 004024e0 */

/* removes a cvar entry by name */

char __thiscall console_cvar_unregister(void *this,char *name)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  
  pvVar3 = console_cvar_find(this,name);
  if (pvVar3 != (void *)0x0) {
    pvVar1 = *(void **)this;
    if (pvVar3 == pvVar1) {
      *(undefined4 *)this = *(undefined4 *)((int)pvVar1 + 4);
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



