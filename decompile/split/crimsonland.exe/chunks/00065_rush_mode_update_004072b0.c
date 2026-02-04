/* rush_mode_update @ 004072b0 */

/* rush mode update: spawns edge waves and handles demo exit */

void rush_mode_update(void)

{
  int iVar1;
  float10 fVar2;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  player_state_table.weapon_id = 2;
  player_state_table.ammo = 0x41f00000;
  player2_weapon_id = 2;
  player2_ammo = 0x41f00000;
  if (console_open_flag == '\0') {
    survival_spawn_cooldown = survival_spawn_cooldown - config_blob.reserved0._20_4_ * frame_dt_ms;
    while (survival_spawn_cooldown < 0) {
      survival_spawn_cooldown = survival_spawn_cooldown + 0xfa;
      fVar2 = (float10)(int)(highscore_active_record.survival_elapsed_ms + 1);
      local_4 = 0x3f800000;
      local_10 = (float)(fVar2 * (float10)8.333333e-06 + (float10)0.3);
      local_c = (float)(fVar2 * (float10)10000.0 + (float10)0.3);
      fVar2 = (float10)fsin(fVar2 * (float10)0.000100000005);
      local_8 = (float)(fVar2 + (float10)0.3);
      if (0.0 <= local_10) {
        if (1.0 < local_10) {
          local_10 = 1.0;
        }
      }
      else {
        local_10 = 0.0;
      }
      if (0.0 <= local_c) {
        if (1.0 < local_c) {
          local_c = 1.0;
        }
      }
      else {
        local_c = 0.0;
      }
      if (0.0 <= local_8) {
        if (1.0 < local_8) {
          local_8 = 1.0;
        }
      }
      else {
        local_8 = 0.0;
      }
      local_20 = (float)terrain_texture_width + 64.0;
      fVar2 = (float10)fcos((float10)(int)highscore_active_record.survival_elapsed_ms *
                            (float10)0.001);
      local_1c = (float)((float10)terrain_texture_height * (float10)0.5 + fVar2 * (float10)256.0);
      iVar1 = creature_spawn(&local_20,&local_10,2);
      local_18 = -64.0;
      fVar2 = (float10)fsin((float10)(int)highscore_active_record.survival_elapsed_ms *
                            (float10)0.001);
      (&creature_pool)[iVar1].ai_mode = 8;
      local_14 = (float)((float10)terrain_texture_height * (float10)0.5 + fVar2 * (float10)256.0);
      iVar1 = creature_spawn(&local_18,&local_10,3);
      (&creature_pool)[iVar1].ai_mode = 8;
      (&creature_pool)[iVar1].flags = (&creature_pool)[iVar1].flags | 0x80;
      (&creature_pool)[iVar1].move_speed = (&creature_pool)[iVar1].move_speed * 1.4;
    }
    if ((demo_mode_active != '\0') && (demo_time_limit_ms < quest_spawn_timeline)) {
      render_pass_mode = 0;
      demo_mode_start();
    }
  }
  return;
}



