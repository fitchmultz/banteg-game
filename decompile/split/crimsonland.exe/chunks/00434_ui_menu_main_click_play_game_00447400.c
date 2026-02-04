/* ui_menu_main_click_play_game @ 00447400 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* main menu PLAY GAME click callback (sets ui_transition_direction=0 and game_state_pending=1) */

void ui_menu_main_click_play_game(void)

{
  ui_transition_direction = 0;
  game_state_pending = 1;
  return;
}



