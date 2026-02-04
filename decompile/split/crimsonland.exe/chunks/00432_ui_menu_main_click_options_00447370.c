/* ui_menu_main_click_options @ 00447370 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* main menu OPTIONS click callback (sets ui_transition_direction=0 and game_state_pending=2) */

void ui_menu_main_click_options(void)

{
  ui_transition_direction = 0;
  game_state_pending = 2;
  return;
}



