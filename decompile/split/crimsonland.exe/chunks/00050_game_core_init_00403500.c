/* game_core_init @ 00403500 */

/* initializes core game systems (quests, effects, UI assets) and sets initial state */

int game_core_init(void)

{
  undefined3 extraout_var;
  
  console_printf(&console_log_queue,s_GDI_initializing_UI_elements__00471468);
  quest_database_init();
  effect_defaults_reset();
  ui_menu_assets_init();
  bonus_metadata_init();
  render_pass_mode = 0;
  game_state_set(0);
  console_printf(&console_log_queue,s_Core_Init_done__00471454);
  return CONCAT31(extraout_var,1);
}



