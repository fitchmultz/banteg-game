/* ui_menu_main_click_quit @ 00447450 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* main menu QUIT click callback (clears ui_sign_crimson_update_disabled, sets
   ui_transition_direction=0, game_state_pending=10, mutes music) */

void ui_menu_main_click_quit(void)

{
  game_state_pending = 10;
  ui_sign_crimson_update_disabled = 0;
  ui_transition_direction = 0;
  sfx_mute_all(music_track_crimson_theme_id);
  sfx_mute_all(music_track_extra_0);
  sfx_mute_all(music_track_shortie_monk_id);
  return;
}



