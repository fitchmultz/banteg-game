/* sfx_play_panned @ 0043d260 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* plays a sound effect with computed pan */

float __cdecl sfx_play_panned(float sfx_id)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  float10 extraout_ST0;
  longlong lVar3;
  
  if ((&sfx_entry_table)[(int)sfx_id].pcm_data == (void *)0x0) {
    return (float)in_ST0;
  }
  if (config_blob.reserved0[0] != '\0') {
    return (float)in_ST0;
  }
  if (0.0 < sfx_cooldown_table[(int)sfx_id]) {
    return (float)in_ST0;
  }
  if (_bonus_reflex_boost_timer <= 0.0) {
    sfx_rate_scale = 0xac44;
  }
  else if (_bonus_reflex_boost_timer <= 1.0) {
    if (_bonus_reflex_boost_timer < 1.0) {
      lVar3 = __ftol();
      sfx_rate_scale = (undefined4)lVar3;
    }
  }
  else {
    sfx_rate_scale = 0x5622;
  }
  if ((sfx_id == sfx_flamer_fire_01) || (sfx_id == sfx_flamer_fire_02)) {
    sfx_cooldown_table[(int)sfx_id] = 0.44;
  }
  else {
    sfx_cooldown_table[(int)sfx_id] = 0.05;
  }
  lVar3 = __ftol();
  iVar2 = (int)lVar3;
  if (iVar2 < -10000) {
    iVar2 = -10000;
  }
  else if (10000 < iVar2) {
    iVar2 = 10000;
  }
  iVar1 = sfx_entry_start_playback((int)(&sfx_entry_table + (int)sfx_id));
  (**(code **)(*(int *)(&sfx_entry_table)[(int)sfx_id].buffers[iVar1] + 0x40))
            ((&sfx_entry_table)[(int)sfx_id].buffers[iVar1],iVar2);
  sfx_entry_set_volume((int)(&sfx_entry_table + (int)sfx_id),config_blob.sfx_volume * sfx_id);
  return (float)extraout_ST0;
}



