/* console_init @ 00401560 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* initializes the console state, registers core commands/cvars, and seeds prompt/version strings */

int * __fastcall console_init(int *console_state)

{
  undefined4 *puVar1;
  char *pcVar2;
  
  *(undefined1 *)(console_state + 3) = 1;
  console_state[6] = 300;
  console_state[7] = -0x3c6a0000;
  console_state[9] = 0;
  console_state[2] = 0;
  puVar1 = operator_new(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    pcVar2 = strdup_malloc(s_version_00471264);
    *puVar1 = pcVar2;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
  }
  *console_state = (int)puVar1;
  puVar1[3] = 0x3f800000;
  pcVar2 = strdup_malloc(&DAT_00471260);
  *(char **)(*console_state + 0x10) = pcVar2;
  *(undefined4 *)(*console_state + 0x14) = 1;
  DAT_0047f4d0 = console_register_cvar(console_state,s_con_monoFont_0047124c,&DAT_0047125c);
  DAT_0047eaa0 = 0;
  _DAT_0047eaa4 = 0;
  _DAT_0047eaa8 = 0;
  _DAT_0047eaac = 0;
  console_cmd_argc = 0;
  console_register_command(console_state,console_cmd_cmdlist,console_cmdlist);
  console_register_command(console_state,&console_cmd_vars,console_vars);
  console_register_command(console_state,&console_cmd_echo,console_echo);
  console_register_command(console_state,&console_cmd_set,console_cmd_set);
  console_register_command(console_state,&console_cmd_quit,console_cmd_quit);
  console_register_command(console_state,console_cmd_clear,console_clear_log);
  console_register_command(console_state,console_cmd_extend,console_cmd_extend);
  console_register_command(console_state,console_cmd_minimize,console_cmd_minimize);
  console_register_command(console_state,&console_cmd_exec,console_cmd_exec);
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    *puVar1 = 0;
  }
  console_state[4] = (int)puVar1;
  pcVar2 = strdup_malloc(&s_empty_string);
  *(char **)console_state[4] = pcVar2;
  console_state[5] = 0;
  return console_state;
}



