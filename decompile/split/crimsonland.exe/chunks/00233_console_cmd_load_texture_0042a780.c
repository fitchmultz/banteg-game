/* console_cmd_load_texture @ 0042a780 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* console command handler for loadtexture; calls texture_get_or_load(name, path) */

void console_cmd_load_texture(void)

{
  int iVar1;
  char *path;
  char *name;
  
  iVar1 = console_cmd_argc_get();
  if (iVar1 != 2) {
    console_printf(&console_log_queue,s_loadtexture_<texturefileid>_00473ef0);
    return;
  }
  path = console_cmd_arg_get(2);
  name = console_cmd_arg_get(2);
  texture_get_or_load(name,path);
  return;
}



