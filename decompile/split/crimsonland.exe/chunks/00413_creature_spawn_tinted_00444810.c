/* creature_spawn_tinted @ 00444810 */

/* spawns a creature with tint and default stats */

int __cdecl creature_spawn_tinted(float *pos,float *rgba,int type_id)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = creature_alloc_slot();
  (&creature_pool)[iVar3].pos_x = *pos;
  (&creature_pool)[iVar3].pos_y = pos[1];
  (&creature_pool)[iVar3].active = '\x01';
  (&creature_pool)[iVar3].state_flag = '\x01';
  (&creature_pool)[iVar3].vel_x = 0.0;
  (&creature_pool)[iVar3].ai_mode = 2;
  (&creature_pool)[iVar3].collision_flag = '\0';
  (&creature_pool)[iVar3].collision_timer = 0.0;
  (&creature_pool)[iVar3].type_id = type_id;
  *(undefined1 *)&(&creature_pool)[iVar3].force_target = 0;
  (&creature_pool)[iVar3].hitbox_size = 16.0;
  (&creature_pool)[iVar3].health = 1.0;
  (&creature_pool)[iVar3].vel_y = 0.0;
  iVar4 = crt_rand();
  (&creature_pool)[iVar3].move_speed = 1.7;
  (&creature_pool)[iVar3].reward_value = 1.0;
  (&creature_pool)[iVar3].attack_cooldown = 0.0;
  (&creature_pool)[iVar3].heading = (float)(iVar4 % 0x13a) * 0.01;
  (&creature_pool)[iVar3].tint_r = *rgba;
  (&creature_pool)[iVar3].tint_g = rgba[1];
  (&creature_pool)[iVar3].tint_b = rgba[2];
  (&creature_pool)[iVar3].tint_a = rgba[3];
  iVar4 = crt_rand();
  (&creature_pool)[iVar3].contact_damage = 100.0;
  (&creature_pool)[iVar3].max_health = (&creature_pool)[iVar3].health;
  fVar2 = (float)(iVar4 % 0x14) + 47.0;
  (&creature_pool)[iVar3].size = fVar2;
  if ((type_id != 3) && (type_id != 4)) {
    return iVar3;
  }
  fVar1 = (&creature_pool)[iVar3].move_speed;
  (&creature_pool)[iVar3].flags = (&creature_pool)[iVar3].flags | 0x80;
  (&creature_pool)[iVar3].move_speed = fVar1 * 1.2;
  (&creature_pool)[iVar3].size = fVar2 * 0.8;
  return iVar3;
}



