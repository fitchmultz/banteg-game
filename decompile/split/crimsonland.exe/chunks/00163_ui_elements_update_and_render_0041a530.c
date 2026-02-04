/* ui_elements_update_and_render @ 0041a530 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* advances UI timeline, handles transitions, updates + renders all UI elements */

void ui_elements_update_and_render(void)

{
  int iVar1;
  ui_element_t **ppuVar2;
  float10 fVar3;
  float10 fVar4;
  
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  if (console_open_flag == '\0') {
    iVar1 = frame_dt_ms;
    if (ui_transition_direction == '\0') {
      iVar1 = -frame_dt_ms;
    }
    ui_elements_timeline = ui_elements_timeline + iVar1;
  }
  if (ui_elements_timeline < 0) {
    ui_elements_timeline = 0;
    if ((demo_mode_active != '\0') && (game_state_pending == 0)) {
      terrain_generate_random();
    }
    game_state_set(game_state_pending);
    game_state_pending = 0x19;
  }
  iVar1 = ui_elements_max_timeline();
  if (iVar1 < ui_elements_timeline) {
    if ((game_state_id == 0) && (demo_mode_active != '\0')) {
      demo_mode_active = '\0';
      config_load_presets();
    }
    fVar3 = (float10)fcos((float10)0.0);
    ui_sign_crimson_update_disabled = 1;
    _DAT_00487594 = (float)fVar3;
    fVar4 = (float10)fsin((float10)0.0);
    _DAT_00487598 = (float)-fVar4;
    _DAT_0048759c = (float)fVar4;
    _DAT_004875a0 = (float)fVar3;
    ui_elements_timeline = ui_elements_max_timeline();
  }
  if (game_state_id != 9) {
    ppuVar2 = &ui_element_table_start;
    do {
      ui_element_update(*ppuVar2);
      ui_element_render(*ppuVar2);
      ppuVar2 = ppuVar2 + -1;
    } while (0x48f167 < (int)ppuVar2);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
    if (game_state_id == 10) {
      DAT_0047ea50 = 1;
    }
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  }
  return;
}



