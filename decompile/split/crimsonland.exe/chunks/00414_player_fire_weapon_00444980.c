/* player_fire_weapon @ 00444980 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* handles player firing: cooldowns, ammo, projectiles, and muzzle effects */

void __cdecl player_fire_weapon(char param_1,char param_2)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  float *unaff_retaddr;
  projectile_type_id_t type_id;
  int iVar9;
  float fVar10;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar5 = game_is_full_version();
  if ((char)iVar5 == '\0') {
    crt_exit(0);
  }
  iVar5 = render_overlay_player_index;
  if (console_open_flag == '\0') {
    if ((&player_state_table)[render_overlay_player_index].health <= 0.0) {
      (&player_state_table)[render_overlay_player_index].death_timer =
           (&player_state_table)[render_overlay_player_index].death_timer - frame_dt * 20.0;
      return;
    }
    fVar2 = (&player_state_table)[render_overlay_player_index].muzzle_flash_alpha -
            (frame_dt + frame_dt);
    (&player_state_table)[render_overlay_player_index].muzzle_flash_alpha = fVar2;
    if (fVar2 < 0.0) {
      (&player_state_table)[iVar5].muzzle_flash_alpha = 0.0;
    }
    (&player_state_table)[iVar5].shot_cooldown = 0.0;
    (&player_state_table)[iVar5].move_dx = 0.0;
    (&player_state_table)[iVar5].move_dy = 0.0;
    (&player_state_table)[iVar5].spread_heat = 0.0;
    (&player_state_table)[iVar5].ammo = (&player_state_table)[iVar5].clip_size;
    (&player_state_table)[iVar5].reload_timer = 0.0;
    if (param_2 != '\0') {
      player_start_reload();
      iVar5 = render_overlay_player_index;
    }
    bVar3 = false;
    (&player_state_table)[iVar5].aim_x = *unaff_retaddr;
    (&player_state_table)[iVar5].aim_y = unaff_retaddr[1];
    fVar8 = (float10)fpatan((float10)(&player_state_table)[iVar5].pos_y -
                            (float10)(&player_state_table)[iVar5].aim_y,
                            (float10)(&player_state_table)[iVar5].pos_x -
                            (float10)(&player_state_table)[iVar5].aim_x);
    (&player_state_table)[iVar5].aim_heading = (float)(fVar8 - (float10)1.5707964);
    if (((&player_state_table)[iVar5].shot_cooldown <= 0.0) &&
       ((&player_state_table)[iVar5].reload_timer == 0.0)) {
      bVar3 = true;
      *(undefined1 *)&(&player_state_table)[iVar5].reload_active = 0;
    }
    bVar4 = false;
    if ((((&player_state_table)[iVar5].shot_cooldown <= 0.0) &&
        (0 < (&player_state_table)[iVar5].experience)) &&
       ((iVar5 = perk_count_get(perk_id_regression_bullets), iVar5 != 0 ||
        (iVar6 = perk_count_get(perk_id_ammunition_within), iVar5 = render_overlay_player_index,
        bVar4 = false, iVar6 != 0)))) {
      bVar4 = true;
      iVar5 = render_overlay_player_index;
    }
    if ((bVar3) || (bVar4)) {
      fVar2 = (&player_state_table)[iVar5].aim_heading;
      if (param_1 != '\0') {
        fVar8 = ((float10)fVar2 - (float10)1.5707964) - (float10)0.150915;
        fVar7 = (float10)fcos(fVar8);
        fVar10 = (float)(fVar7 * (float10)16.0);
        fVar8 = (float10)fsin(fVar8);
        fVar1 = (float)(fVar8 * (float10)16.0);
        if (((&weapon_table)[(&player_state_table)[iVar5].weapon_id].flags & 1) != 0) {
          crt_rand();
          crt_rand();
          iVar5 = render_overlay_player_index;
        }
        if (1.0 < (&player_state_table)[iVar5].muzzle_flash_alpha) {
          (&player_state_table)[iVar5].muzzle_flash_alpha = 1.0;
        }
        (&player_state_table)[iVar5].muzzle_flash_alpha =
             (&weapon_table)[(&player_state_table)[iVar5].weapon_id].spread_heat +
             (&player_state_table)[iVar5].muzzle_flash_alpha;
        sfx_play_panned((float)(&weapon_table)[(&player_state_table)[iVar5].weapon_id].
                               shot_sfx_base_id);
        if ((&player_state_table)[render_overlay_player_index].weapon_id == 3) {
          fVar8 = (float10)fcos((float10)fVar2);
          local_14 = (float)(fVar8 * (float10)25.0);
          fVar7 = (float10)fsin((float10)fVar2);
          local_10 = (float)(fVar7 * (float10)25.0);
          local_8 = fVar1 + (&player_state_table)[render_overlay_player_index].pos_y;
          local_c = fVar10 + (&player_state_table)[render_overlay_player_index].pos_x;
          iVar5 = fx_spawn_sprite(&local_c,&local_14,1.0);
          local_c = (float)fVar8 * 15.0;
          (&sprite_effect_pool)[iVar5].color_r = 0.5;
          (&sprite_effect_pool)[iVar5].color_g = 0.5;
          local_8 = (float)fVar7 * 15.0;
          (&sprite_effect_pool)[iVar5].color_b = 0.5;
          (&sprite_effect_pool)[iVar5].color_a = 0.25;
          local_10 = fVar1 + (&player_state_table)[render_overlay_player_index].pos_y;
          local_14 = fVar10 + (&player_state_table)[render_overlay_player_index].pos_x;
          iVar5 = fx_spawn_sprite(&local_14,&local_c,2.0);
          iVar6 = 0xc;
          (&sprite_effect_pool)[iVar5].color_r = 0.5;
          (&sprite_effect_pool)[iVar5].color_g = 0.5;
          (&sprite_effect_pool)[iVar5].color_b = 0.5;
          (&sprite_effect_pool)[iVar5].color_a = 0.223;
          do {
            iVar9 = -100;
            type_id = PROJECTILE_TYPE_SHOTGUN;
            local_8 = fVar1 + (&player_state_table)[render_overlay_player_index].pos_y;
            local_c = fVar10 + (&player_state_table)[render_overlay_player_index].pos_x;
            iVar5 = crt_rand();
            iVar5 = projectile_spawn(&local_c,(float)(iVar5 % 200 + -100) * 0.0013 + fVar2,type_id,
                                     iVar9);
            iVar9 = crt_rand();
            iVar6 = iVar6 + -1;
            projectile_pool[iVar5].pos.tail.vy.speed_scale = (float)(iVar9 % 100) * 0.01 + 1.0;
          } while (iVar6 != 0);
        }
        iVar6 = perk_id_sharpshooter;
        iVar5 = render_overlay_player_index;
        if (player_state_table.perk_counts[perk_id_sharpshooter] < 1) {
          (&player_state_table)[render_overlay_player_index].spread_heat =
               _DAT_00473a40 * frame_dt * 150.0 +
               (&player_state_table)[render_overlay_player_index].spread_heat;
        }
        if (_DAT_00473a40 + _DAT_00473a40 < (&player_state_table)[iVar5].spread_heat) {
          (&player_state_table)[iVar5].spread_heat = _DAT_00473a40 + _DAT_00473a40;
        }
        iVar9 = perk_id_fastshot;
        (&player_state_table)[iVar5].spread_heat =
             _DAT_00473a40 * (&player_state_table)[iVar5].spread_heat;
        if (0 < player_state_table.perk_counts[iVar9]) {
          (&player_state_table)[iVar5].shot_cooldown =
               (&player_state_table)[iVar5].shot_cooldown * 0.88;
        }
        if (0 < player_state_table.perk_counts[iVar6]) {
          (&player_state_table)[iVar5].shot_cooldown =
               (&player_state_table)[iVar5].shot_cooldown * 1.05;
        }
        if ((float)(&player_state_table)[iVar5].ammo <= 0.0) {
          player_start_reload();
          iVar5 = render_overlay_player_index;
        }
      }
    }
    fVar2 = (&player_state_table)[iVar5].move_phase;
    while (14.0 < fVar2) {
      fVar2 = (&player_state_table)[iVar5].move_phase - 14.0;
      (&player_state_table)[iVar5].move_phase = fVar2;
    }
    fVar2 = (&player_state_table)[iVar5].size * 0.5;
    if ((&player_state_table)[iVar5].pos_x < fVar2) {
      (&player_state_table)[iVar5].pos_x = fVar2;
    }
    if ((float)terrain_texture_width - fVar2 < (&player_state_table)[iVar5].pos_x) {
      (&player_state_table)[iVar5].pos_x = (float)terrain_texture_width - fVar2;
    }
    if ((&player_state_table)[iVar5].pos_y < fVar2) {
      (&player_state_table)[iVar5].pos_y = fVar2;
    }
    if ((float)terrain_texture_height - fVar2 < (&player_state_table)[iVar5].pos_y) {
      (&player_state_table)[iVar5].pos_y = (float)terrain_texture_height - fVar2;
    }
    if (0.8 < (&player_state_table)[iVar5].muzzle_flash_alpha) {
      (&player_state_table)[iVar5].muzzle_flash_alpha = 0.8;
    }
  }
  return;
}



