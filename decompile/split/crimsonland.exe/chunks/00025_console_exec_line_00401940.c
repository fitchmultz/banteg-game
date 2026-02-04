/* console_exec_line @ 00401940 */

/* executes a console command or cvar assignment from a line */

char __thiscall console_exec_line(void *this,char *line)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  char *pcVar4;
  float fVar5;
  
  console_tokenize_line(line);
  if (console_cmd_argc != 0) {
    puVar2 = console_cvar_find(this,console_cmd_name);
    pvVar3 = console_command_find(this,console_cmd_name);
    if (puVar2 == (undefined4 *)0x0) {
      if (pvVar3 == (void *)0x0) {
        cVar1 = console_printf(this,s_Unknown_command___s__0047126c);
        return cVar1;
      }
      cVar1 = (**(code **)((int)pvVar3 + 8))();
      return cVar1;
    }
    if (console_cmd_argc == 2) {
      if ((void *)puVar2[4] != (void *)0x0) {
        crt_free((void *)puVar2[4]);
      }
      puVar2[4] = 0;
      pcVar4 = strdup_malloc(console_cmd_arg1);
      puVar2[4] = pcVar4;
      fVar5 = crt_atof_l(console_cmd_arg1,console_cmd_arg1);
      puVar2[3] = fVar5;
      if (*(char *)((int)this + 0xc) != '\0') {
        cVar1 = console_printf(this,s___s__set_to___s____ff__00471298,*puVar2,puVar2[4],
                               (double)fVar5);
        return cVar1;
      }
    }
    else if (*(char *)((int)this + 0xc) != '\0') {
      cVar1 = console_printf(this,s___s__is___s____ff__00471284,*puVar2,puVar2[4],
                             (double)(float)puVar2[3]);
      return cVar1;
    }
  }
  return '\0';
}



