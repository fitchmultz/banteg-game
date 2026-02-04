/* gameplay_render_world @ 00405960 */

/* world render pass: updates gameplay fade and draws fx queue, creatures, players, projectiles,
   bonuses */

void gameplay_render_world(void)

{
  int player_index;
  int *piVar1;
  
  ui_transition_alpha = (float)ui_elements_timeline / (float)(DAT_0048eb48 - DAT_0048eb4c);
  if (quest_unlock_index_full < 0x28) {
    if (player_state_table.weapon_id == 0x1d) {
      weapon_assign_player(0,1);
    }
    if (player2_weapon_id == 0x1d) {
      weapon_assign_player(1,1);
    }
  }
  player_index = 0;
  piVar1 = &player_state_table.weapon_id;
  do {
    if ((*piVar1 == 0x19) && (DAT_00486fb8 != 0x19)) {
      weapon_assign_player(player_index,1);
    }
    if ((*piVar1 == 0x18) && (DAT_00486fb8 != 0x18)) {
      weapon_assign_player(player_index,1);
    }
    piVar1 = piVar1 + 0xd8;
    player_index = player_index + 1;
  } while ((int)piVar1 < 0x491230);
  if (DAT_00487241 == '\0') {
    if (((game_state_id == 9) || (game_state_id == 6)) ||
       ((((game_state_id == 8 || ((game_state_id == 0xc || (game_state_id == 7)))) &&
         (ui_transition_direction != '\0')) ||
        ((((game_state_pending == 9 || (game_state_pending == 6)) || (game_state_pending == 5)) ||
         ((game_state_pending == 2 || (game_state_pending == 3)))))))) {
LAB_00405a7f:
      ui_transition_alpha = 1.0;
      goto LAB_00405a89;
    }
    if (game_state_id != 5) {
      if (((game_state_id != 2) && (game_state_id != 3)) &&
         ((game_state_pending != 0x15 &&
          (((game_state_pending != 7 && (game_state_pending != 8)) && (game_state_pending != 0xc))))
         )) goto LAB_00405a89;
      goto LAB_00405a7f;
    }
    if (game_state_pending != 0) goto LAB_00405a7f;
  }
  else {
LAB_00405a89:
    if ((game_state_id != 5) || (game_state_pending != 0)) goto LAB_00405ab3;
  }
  ui_transition_alpha = (float)ui_elements_timeline / (float)(DAT_0048eb48 - DAT_0048eb4c);
LAB_00405ab3:
  if (ui_transition_alpha <= 1.0) {
    if (ui_transition_alpha < 0.0) {
      ui_transition_alpha = 0.0;
    }
  }
  else {
    ui_transition_alpha = 1.0;
  }
  fx_queue_render();
  terrain_render();
  render_overlay_player_index = 0;
  if (0 < (int)config_blob.reserved0._20_4_) {
    do {
      if ((&player_state_table)[render_overlay_player_index].health <= 0.0) {
        player_render_overlays();
      }
      render_overlay_player_index = render_overlay_player_index + 1;
    } while (render_overlay_player_index < (int)config_blob.reserved0._20_4_);
  }
  creature_render_all();
  render_overlay_player_index = 0;
  if (0 < (int)config_blob.reserved0._20_4_) {
    do {
      if (0.0 < (&player_state_table)[render_overlay_player_index].health) {
        player_render_overlays();
      }
      render_overlay_player_index = render_overlay_player_index + 1;
    } while (render_overlay_player_index < (int)config_blob.reserved0._20_4_);
  }
  projectile_render();
  bonus_render();
  if (0.0 < screen_fade_alpha) {
    (*grim_interface_ptr->vtable->grim_draw_fullscreen_color)(0.0,0.0,0.0,screen_fade_alpha);
  }
  return;
}



