/* console_cmd_snd_add_game_tune @ 0042c360 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* console command handler for snd_addGameTune; loads music\%s and queues the track */

void console_cmd_snd_add_game_tune(void)

{
  int iVar1;
  char *pcVar2;
  char acStack_400 [1024];
  
  iVar1 = console_cmd_argc_get();
  if (iVar1 != 2) {
    console_printf(&console_log_queue,s_snd_addGameTune_<tuneName_ogg>_0047474c);
    return;
  }
  pcVar2 = console_cmd_arg_get(1);
  crt_sprintf(acStack_400,s_music__s_00474740,pcVar2);
  iVar1 = music_load_track(acStack_400);
  if (-1 < iVar1) {
    music_queue_track(iVar1);
  }
  return;
}



