/* game_update_generic_menu @ 00406af0 */

/* [binja] int32_t sub_406af0() */

int game_update_generic_menu(void)

{
  int extraout_EAX;
  
  if ((render_pass_mode == '\0') && (game_state_id != 5)) {
    terrain_render();
  }
  else {
    gameplay_render_world();
  }
  (*grim_interface_ptr->vtable->grim_draw_fullscreen_color)(0.0,0.0,0.0,screen_fade_alpha);
  ui_elements_update_and_render();
  perk_prompt_update_and_render();
  ui_cursor_render();
  return extraout_EAX;
}



