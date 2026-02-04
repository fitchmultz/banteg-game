/* creature_spawn @ 00428240 */

/* allocates a creature slot and seeds position, type, and tint defaults */

int __cdecl creature_spawn(float *pos,float *tint_rgba,int type_id)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = creature_alloc_slot();
  (&creature_pool)[iVar3].pos_x = *pos;
  (&creature_pool)[iVar3].pos_y = pos[1];
  (&creature_pool)[iVar3].type_id = type_id;
  (&creature_pool)[iVar3].ai_mode = 0;
  (&creature_pool)[iVar3].collision_flag = '\0';
  (&creature_pool)[iVar3].collision_timer = 0.0;
  (&creature_pool)[iVar3].active = '\x01';
  *(undefined1 *)&(&creature_pool)[iVar3].force_target = 0;
  (&creature_pool)[iVar3].state_flag = '\x01';
  (&creature_pool)[iVar3].hitbox_size = 16.0;
  fVar1 = (float)(int)highscore_active_record.survival_elapsed_ms;
  (&creature_pool)[iVar3].vel_x = 0.0;
  (&creature_pool)[iVar3].vel_y = 0.0;
  (&creature_pool)[iVar3].health = fVar1 * 0.000100000005 + 10.0;
  iVar4 = crt_rand();
  (&creature_pool)[iVar3].heading = (float)(iVar4 % 0x13a) * 0.01;
  (&creature_pool)[iVar3].move_speed =
       (float)(int)highscore_active_record.survival_elapsed_ms * 1.0000001e-05 + 2.5;
  iVar4 = crt_rand();
  (&creature_pool)[iVar3].attack_cooldown = 0.0;
  (&creature_pool)[iVar3].reward_value = (float)(iVar4 % 0x1e + 0x8c);
  (&creature_pool)[iVar3].tint_r = *tint_rgba;
  (&creature_pool)[iVar3].tint_g = tint_rgba[1];
  (&creature_pool)[iVar3].tint_b = tint_rgba[2];
  fVar1 = (&creature_pool)[iVar3].health;
  (&creature_pool)[iVar3].tint_a = tint_rgba[3];
  fVar2 = (float)(int)highscore_active_record.survival_elapsed_ms;
  (&creature_pool)[iVar3].contact_damage = 4.0;
  (&creature_pool)[iVar3].max_health = fVar1;
  (&creature_pool)[iVar3].size = fVar2 * 1.0000001e-05 + 47.0;
  return iVar3;
}



