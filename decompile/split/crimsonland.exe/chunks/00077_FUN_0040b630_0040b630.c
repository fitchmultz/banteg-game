/* FUN_0040b630 @ 0040b630 */

void FUN_0040b630(void)

{
  uchar uVar1;
  mod_interface_t *unaff_EBX;
  mod_interface_t *unaff_retaddr;
  
  if (plugin_interface_ptr == (mod_interface_t *)0x0) {
    game_state_pending = 0x14;
    ui_transition_direction = '\0';
    ui_elements_update_and_render();
    DAT_00471304 = '\x01';
    return;
  }
  if ((game_state_id == 0x16) && (DAT_00471304 != '\0')) {
    DAT_00471304 = '\0';
    DAT_004824d1 = '\0';
    sfx_mute_all(music_track_extra_0);
    FUN_0040b5d0();
    (*plugin_interface_ptr->vtable->Init)(unaff_EBX);
    (plugin_interface_ptr->parms).fields.onPause = '\0';
  }
  else {
    uVar1 = (*plugin_interface_ptr->vtable->Frame)(frame_dt_ms,(int)unaff_EBX);
    if (uVar1 == '\0') {
      DAT_004824d1 = '\0';
      (*plugin_interface_ptr->vtable->Shutdown)(unaff_retaddr);
      sfx_mute_all(music_track_extra_0);
      plugin_interface_ptr = (mod_interface_t *)0x0;
      FreeLibrary((HMODULE)plugin_module_handle);
      plugin_module_handle = (HMODULE)0x0;
      DAT_00471304 = '\x01';
      game_state_pending = 0x14;
      ui_transition_direction = '\0';
    }
    else {
      DAT_004824d1 = '\x01';
    }
  }
  ui_elements_update_and_render();
  if (((ui_transition_direction == '\0') && (game_state_id == 0x16)) ||
     ((plugin_interface_ptr != (mod_interface_t *)0x0 &&
      ((DAT_004824d1 != '\0' && ((plugin_interface_ptr->parms).fields.drawMouseCursor != '\0'))))))
  {
    ui_cursor_render();
  }
  return;
}



