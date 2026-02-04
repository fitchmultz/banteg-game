/* weapon_assign_player @ 00452d40 */

/* assigns a weapon to a player and resets ammo timers */

void __cdecl weapon_assign_player(int player_index,int weapon_id)

{
  float sfx_id;
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  iVar1 = weapon_id;
  if (demo_mode_active == '\0') {
    game_status_blob.weapon_usage_counts[weapon_id] =
         game_status_blob.weapon_usage_counts[weapon_id] + 1;
  }
  (&player_state_table)[player_index].weapon_id = weapon_id;
  iVar2 = perk_id_ammo_maniac;
  (&player_state_table)[player_index].clip_size = (int)(float)(&weapon_table)[weapon_id].clip_size;
  iVar2 = perk_count_get(iVar2);
  if (iVar2 != 0) {
    lVar3 = __ftol();
    weapon_id = (int)lVar3;
    if (weapon_id < 2) {
      weapon_id = 1;
    }
    (&player_state_table)[player_index].clip_size =
         (int)((float)weapon_id + (float)(&player_state_table)[player_index].clip_size);
  }
  iVar2 = perk_count_get(perk_id_my_favourite_weapon);
  if (iVar2 != 0) {
    (&player_state_table)[player_index].clip_size =
         (int)((float)(&player_state_table)[player_index].clip_size + 2.0);
  }
  sfx_id = (float)(&weapon_table)[iVar1].reload_sfx_id;
  (&player_state_table)[player_index].ammo = (&player_state_table)[player_index].clip_size;
  (&player_state_table)[player_index].weapon_reset_latch = 0;
  (&player_state_table)[player_index].shot_cooldown = 0.0;
  (&player_state_table)[player_index].reload_timer = 0.0;
  (&player_aux_timer)[player_index] = 0x40000000;
  sfx_play_panned(sfx_id);
  return;
}



