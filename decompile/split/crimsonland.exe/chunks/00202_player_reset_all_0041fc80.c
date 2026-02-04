/* player_reset_all @ 0041fc80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] void* sub_41fc80() */

void * player_reset_all(void)

{
  float fVar1;
  float fVar2;
  player_state_t *ppVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uchar *puVar7;
  uint uVar8;
  int *piVar9;
  bool bVar10;
  
  if (*(float *)((int)cv_verbose + 0xc) != 0.0) {
    console_printf(&console_log_queue,s___Reseting_players__00473e54);
  }
  render_overlay_player_index = 0;
  do {
    uVar5 = render_overlay_player_index;
    fVar1 = (float)terrain_texture_width;
    _DAT_004aaf30 = 0;
    iVar6 = render_overlay_player_index * 0x360;
    fVar2 = (float)terrain_texture_height;
    (&player_state_table)[render_overlay_player_index].speed_bonus_timer = 0.0;
    (&player_state_table)[uVar5].shield_timer = 0.0;
    (&player_state_table)[uVar5].state_aux = 0;
    (&player_plaguebearer_active)[iVar6] = 0;
    (&player_state_table)[uVar5].pos_x = fVar1 * 0.5;
    (&player_state_table)[uVar5].pos_y = fVar2 * 0.5;
    uVar8 = uVar5 & 0x80000001;
    bVar10 = uVar8 == 0;
    (&player_state_table)[uVar5].health = 100.0;
    if ((int)uVar8 < 0) {
      bVar10 = (uVar8 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar10) {
      (&player_state_table)[uVar5].pos_x =
           (float)(int)(uVar5 * 0x50) + (&player_state_table)[uVar5].pos_x;
      (&player_state_table)[uVar5].pos_y =
           (float)(int)(uVar5 * 0x50) + (&player_state_table)[uVar5].pos_y;
    }
    else {
      (&player_state_table)[uVar5].pos_x =
           (&player_state_table)[uVar5].pos_x - (float)(int)(uVar5 * 0x50);
      (&player_state_table)[uVar5].pos_y =
           (&player_state_table)[uVar5].pos_y - (float)(int)(uVar5 * 0x50);
    }
    fVar1 = (float)_DAT_004d7aec;
    (&player_state_table)[render_overlay_player_index].size = 48.0;
    (&player_state_table)[render_overlay_player_index].speed_multiplier = 2.0;
    (&player_state_table)[render_overlay_player_index].level = 1;
    (&player_state_table)[render_overlay_player_index].heading = 0.0;
    (&player_state_table)[render_overlay_player_index].experience = 0;
    ppVar3 = &player_state_table + render_overlay_player_index;
    ppVar3->_pad5[0] = '\0';
    ppVar3->_pad5[1] = '\0';
    ppVar3->_pad5[2] = '\0';
    ppVar3->_pad5[3] = '\0';
    (&player_state_table)[render_overlay_player_index].spread_heat = 0.0;
    (&player_state_table)[render_overlay_player_index].move_speed = 0.0;
    (&player_state_table)[render_overlay_player_index].ammo = 0x41200000;
    (&player_state_table)[render_overlay_player_index].clip_size = 0x41200000;
    (&player_state_table)[render_overlay_player_index].reload_timer_max = 1.0;
    (&player_state_table)[render_overlay_player_index].reload_timer = 0.0;
    (&player_state_table)[render_overlay_player_index].alt_weapon_id = 1;
    (&player_state_table)[render_overlay_player_index].alt_clip_size = (int)fVar1;
    *(undefined1 *)&(&player_state_table)[render_overlay_player_index].alt_reload_active = 0;
    (&player_state_table)[render_overlay_player_index].alt_ammo =
         (&player_state_table)[render_overlay_player_index].alt_clip_size;
    fVar1 = DAT_004d7af4;
    (&player_state_table)[render_overlay_player_index].alt_reload_timer = 0.0;
    (&player_state_table)[render_overlay_player_index].alt_shot_cooldown = 0.0;
    (&player_state_table)[render_overlay_player_index].alt_reload_timer_max = fVar1;
    cVar4 = demo_mode_active;
    (&player_state_table)[render_overlay_player_index].shot_cooldown = 0.8;
    (&player_state_table)[render_overlay_player_index].weapon_id = 1;
    ppVar3 = &player_state_table + render_overlay_player_index;
    ppVar3->_pad7[0] = '\0';
    ppVar3->_pad7[1] = '\0';
    ppVar3->_pad7[2] = '\0';
    ppVar3->_pad7[3] = '\0';
    (&player_state_table)[render_overlay_player_index].death_timer = 16.0;
    if (cVar4 == '\0') {
      ui_mouse_x = 0x43a00000;
      ui_mouse_y = 0x430c0000;
    }
    piVar9 = (&player_state_table)[render_overlay_player_index].perk_counts;
    for (iVar6 = 0x80; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar9 = 0;
      piVar9 = piVar9 + 1;
    }
    puVar7 = &creature_pool.collision_flag;
    do {
      *puVar7 = '\0';
      puVar7 = puVar7 + 0x98;
    } while ((int)puVar7 < 0x4aa341);
    render_overlay_player_index = render_overlay_player_index + 1;
  } while ((int)render_overlay_player_index < 2);
  render_overlay_player_index = 0;
  return puVar7;
}



