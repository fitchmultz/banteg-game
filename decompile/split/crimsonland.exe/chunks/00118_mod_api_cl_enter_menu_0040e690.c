/* mod_api_cl_enter_menu @ 0040e690 */

/* mod API vtable 0x84: clAPI_t::CL_EnterMenu (only handles "game_pause") */

void mod_api_cl_enter_menu(char *menu)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  bool bVar4;
  
  if (menu != (char *)0x0) {
    pcVar2 = s_game_pause_00472f60;
    do {
      bVar1 = *pcVar2;
      bVar4 = bVar1 < (byte)*menu;
      if (bVar1 != *menu) {
LAB_0040e6c7:
        iVar3 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
        goto LAB_0040e6cc;
      }
      if (bVar1 == 0) break;
      bVar1 = ((byte *)pcVar2)[1];
      bVar4 = bVar1 < ((byte *)menu)[1];
      if (bVar1 != ((byte *)menu)[1]) goto LAB_0040e6c7;
      pcVar2 = (char *)((byte *)pcVar2 + 2);
      menu = (char *)((byte *)menu + 2);
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0040e6cc:
    if (iVar3 == 0) {
      if (plugin_interface_ptr != (mod_interface_t *)0x0) {
        (plugin_interface_ptr->parms).fields.onPause = '\x01';
      }
      ui_transition_direction = 0;
      game_state_pending = 5;
    }
  }
  return;
}



