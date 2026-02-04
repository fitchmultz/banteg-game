/* survival_spawn_creature @ 00407510 */

/* spawns a creature at the given position, selecting type/stats based on DAT_0049095c */

void __cdecl survival_spawn_creature(float *pos)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  
  iVar3 = creature_alloc_slot();
  (&creature_pool)[iVar3].pos_x = *pos;
  (&creature_pool)[iVar3].pos_y = pos[1];
  (&creature_pool)[iVar3].collision_flag = '\0';
  (&creature_pool)[iVar3].collision_timer = 0.0;
  (&creature_pool)[iVar3].ai_mode = 0;
  iVar4 = crt_rand();
  iVar4 = iVar4 % 10;
  if (player_state_table.experience < 12000) {
    if (iVar4 < 9) {
      (&creature_pool)[iVar3].type_id = 2;
    }
    else {
      (&creature_pool)[iVar3].type_id = 3;
    }
  }
  else if (player_state_table.experience < 25000) {
    if (iVar4 < 4) {
      (&creature_pool)[iVar3].type_id = 0;
    }
    else {
      (&creature_pool)[iVar3].type_id = 3;
    }
    if (8 < iVar4) {
      (&creature_pool)[iVar3].type_id = 2;
    }
  }
  else if (player_state_table.experience < 42000) {
    if (iVar4 < 5) {
      (&creature_pool)[iVar3].type_id = 2;
    }
    else {
      uVar5 = crt_rand();
      uVar5 = uVar5 & 0x80000001;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
      }
      (&creature_pool)[iVar3].type_id = uVar5 + 3;
    }
  }
  else if (player_state_table.experience < 50000) {
    (&creature_pool)[iVar3].type_id = 2;
  }
  else if (player_state_table.experience < 90000) {
    (&creature_pool)[iVar3].type_id = 4;
  }
  else {
    if (109999 < player_state_table.experience) {
      if (iVar4 < 6) {
        (&creature_pool)[iVar3].type_id = 2;
        goto LAB_00407611;
      }
      if (iVar4 < 9) {
        (&creature_pool)[iVar3].type_id = 4;
        goto LAB_00407611;
      }
    }
    (&creature_pool)[iVar3].type_id = 0;
  }
LAB_00407611:
  iVar4 = crt_rand();
  if (((byte)iVar4 & 0x1f) == 2) {
    (&creature_pool)[iVar3].type_id = 3;
  }
  iVar4 = crt_rand();
  (&creature_pool)[iVar3].active = '\x01';
  *(undefined1 *)&(&creature_pool)[iVar3].force_target = 0;
  (&creature_pool)[iVar3].hitbox_size = 16.0;
  (&creature_pool)[iVar3].vel_x = 0.0;
  (&creature_pool)[iVar3].vel_y = 0.0;
  (&creature_pool)[iVar3].size = (float)(iVar4 % 0x14 + 0x2c);
  iVar4 = crt_rand();
  (&creature_pool)[iVar3].heading = (float)(iVar4 % 0x13a) * 0.01;
  iVar4 = (&creature_pool)[iVar3].type_id;
  (&creature_pool)[iVar3].move_speed = (float)(player_state_table.experience / 4000) * 0.045 + 0.9;
  if (iVar4 == 3) {
    fVar1 = (&creature_pool)[iVar3].move_speed;
    (&creature_pool)[iVar3].flags = (&creature_pool)[iVar3].flags | 0x80;
    (&creature_pool)[iVar3].move_speed = fVar1 * 1.3;
  }
  uVar5 = crt_rand();
  iVar4 = (&creature_pool)[iVar3].type_id;
  (&creature_pool)[iVar3].health =
       (float)player_state_table.experience * 0.00125 + (float)(uVar5 & 0xf) + 52.0;
  if (iVar4 == 0) {
    fVar1 = (&creature_pool)[iVar3].move_speed * 0.6;
    (&creature_pool)[iVar3].move_speed = fVar1;
    if (fVar1 < 1.3) {
      (&creature_pool)[iVar3].move_speed = 1.3;
    }
    (&creature_pool)[iVar3].health = (&creature_pool)[iVar3].health * 1.5;
  }
  if (3.5 < (&creature_pool)[iVar3].move_speed) {
    (&creature_pool)[iVar3].move_speed = 3.5;
  }
  (&creature_pool)[iVar3].attack_cooldown = 0.0;
  (&creature_pool)[iVar3].reward_value = 0.0;
  if (player_state_table.experience < 50000) {
    (&creature_pool)[iVar3].tint_r =
         1.0 - 1.0 / ((float)(player_state_table.experience / 1000) + 10.0);
    iVar4 = crt_rand();
    (&creature_pool)[iVar3].tint_g =
         ((float)(iVar4 % 10) * 0.01 + 0.9) -
         1.0 / ((float)(player_state_table.experience / 10000) + 10.0);
    iVar4 = crt_rand();
    (&creature_pool)[iVar3].tint_b = (float)(iVar4 % 10) * 0.01 + 0.7;
  }
  else if (player_state_table.experience < 100000) {
    (&creature_pool)[iVar3].tint_r =
         0.9 - 1.0 / ((float)(player_state_table.experience / 1000) + 10.0);
    iVar4 = crt_rand();
    (&creature_pool)[iVar3].tint_g =
         ((float)(iVar4 % 10) * 0.01 + 0.8) -
         1.0 / ((float)(player_state_table.experience / 10000) + 10.0);
    iVar4 = crt_rand();
    (&creature_pool)[iVar3].tint_b =
         (float)(player_state_table.experience + -50000) * 6e-06 + (float)(iVar4 % 10) * 0.01 + 0.7;
  }
  else {
    (&creature_pool)[iVar3].tint_r =
         1.0 - 1.0 / ((float)(player_state_table.experience / 1000) + 10.0);
    iVar4 = crt_rand();
    (&creature_pool)[iVar3].tint_g =
         ((float)(iVar4 % 10) * 0.01 + 0.9) -
         1.0 / ((float)(player_state_table.experience / 10000) + 10.0);
    iVar4 = crt_rand();
    fVar1 = ((float)(iVar4 % 10) * 0.01 + 1.0) -
            (float)(player_state_table.experience + -100000) * 3e-06;
    (&creature_pool)[iVar3].tint_b = fVar1;
    if (fVar1 < 0.5) {
      (&creature_pool)[iVar3].tint_b = 0.5;
    }
  }
  pfVar6 = &(&creature_pool)[iVar3].tint_r;
  fVar1 = (&creature_pool)[iVar3].size;
  (&creature_pool)[iVar3].tint_a = 1.0;
  (&creature_pool)[iVar3].contact_damage = fVar1 * 0.0952381;
  if ((&creature_pool)[iVar3].reward_value == 0.0) {
    iVar4 = crt_rand();
    (&creature_pool)[iVar3].reward_value =
         (&creature_pool)[iVar3].health * 0.4 +
         (&creature_pool)[iVar3].contact_damage * 0.8 +
         (&creature_pool)[iVar3].move_speed * 5.0 + (float)(iVar4 % 10 + 10);
  }
  iVar4 = crt_rand();
  if (iVar4 % 0xb4 < 2) {
    *pfVar6 = 0.9;
    (&creature_pool)[iVar3].health = 65.0;
    (&creature_pool)[iVar3].tint_g = 0.4;
    (&creature_pool)[iVar3].reward_value = 320.0;
    (&creature_pool)[iVar3].tint_b = 0.4;
    (&creature_pool)[iVar3].tint_a = 1.0;
  }
  else {
    iVar4 = crt_rand();
    if (iVar4 % 0xf0 < 2) {
      *pfVar6 = 0.4;
      (&creature_pool)[iVar3].health = 85.0;
      (&creature_pool)[iVar3].tint_g = 0.9;
      (&creature_pool)[iVar3].reward_value = 420.0;
      (&creature_pool)[iVar3].tint_b = 0.4;
      (&creature_pool)[iVar3].tint_a = 1.0;
    }
    else {
      iVar4 = crt_rand();
      if (iVar4 % 0x168 < 2) {
        *pfVar6 = 0.4;
        (&creature_pool)[iVar3].health = 125.0;
        (&creature_pool)[iVar3].tint_g = 0.4;
        (&creature_pool)[iVar3].reward_value = 520.0;
        (&creature_pool)[iVar3].tint_b = 0.9;
        (&creature_pool)[iVar3].tint_a = 1.0;
      }
    }
  }
  iVar4 = crt_rand();
  if (iVar4 % 0x528 < 4) {
    fVar1 = (&creature_pool)[iVar3].health;
    *pfVar6 = 0.84;
    (&creature_pool)[iVar3].health = fVar1 + 230.0;
    (&creature_pool)[iVar3].tint_g = 0.24;
    (&creature_pool)[iVar3].size = 80.0;
    (&creature_pool)[iVar3].tint_b = 0.89;
    (&creature_pool)[iVar3].reward_value = 600.0;
    (&creature_pool)[iVar3].tint_a = 1.0;
  }
  else {
    iVar4 = crt_rand();
    if (iVar4 % 0x654 < 4) {
      fVar1 = (&creature_pool)[iVar3].health;
      *pfVar6 = 0.94;
      (&creature_pool)[iVar3].health = fVar1 + 2230.0;
      (&creature_pool)[iVar3].tint_g = 0.84;
      (&creature_pool)[iVar3].size = 85.0;
      (&creature_pool)[iVar3].tint_b = 0.29;
      (&creature_pool)[iVar3].reward_value = 900.0;
      (&creature_pool)[iVar3].tint_a = 1.0;
    }
  }
  fVar1 = (&creature_pool)[iVar3].reward_value;
  fVar2 = (&creature_pool)[iVar3].health;
  (&creature_pool)[iVar3].state_flag = '\x01';
  (&creature_pool)[iVar3].max_health = fVar2;
  (&creature_pool)[iVar3].reward_value = fVar1 * 0.8;
  if (0.0 <= *pfVar6) {
    if (1.0 < *pfVar6) {
      *pfVar6 = 1.0;
    }
  }
  else {
    *pfVar6 = 0.0;
  }
  if (0.0 <= (&creature_pool)[iVar3].tint_g) {
    if (1.0 < (&creature_pool)[iVar3].tint_g) {
      (&creature_pool)[iVar3].tint_g = 1.0;
    }
  }
  else {
    (&creature_pool)[iVar3].tint_g = 0.0;
  }
  if (0.0 <= (&creature_pool)[iVar3].tint_b) {
    if (1.0 < (&creature_pool)[iVar3].tint_b) {
      (&creature_pool)[iVar3].tint_b = 1.0;
    }
  }
  else {
    (&creature_pool)[iVar3].tint_b = 0.0;
  }
  if ((&creature_pool)[iVar3].tint_a < 0.0) {
    (&creature_pool)[iVar3].tint_a = 0.0;
    return;
  }
  if (1.0 < (&creature_pool)[iVar3].tint_a) {
    (&creature_pool)[iVar3].tint_a = 1.0;
  }
  return;
}



