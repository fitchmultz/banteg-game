/* sfx_play @ 0043d120 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* plays a sound effect with centered pan */

int __cdecl sfx_play(int sfx_id)

{
  int iVar1;
  longlong lVar2;
  float unaff_retaddr;
  
  if ((&sfx_entry_table)[sfx_id].pcm_data == (void *)0x0) {
    return -1;
  }
  if (config_blob.reserved0[0] != '\0') {
    return -1;
  }
  if (0.0 < sfx_cooldown_table[sfx_id]) {
    return -1;
  }
  if (_bonus_reflex_boost_timer <= 0.0) {
    sfx_rate_scale = 0xac44;
  }
  else if (_bonus_reflex_boost_timer <= 1.0) {
    if (_bonus_reflex_boost_timer < 1.0) {
      lVar2 = __ftol();
      sfx_rate_scale = (undefined4)lVar2;
    }
  }
  else {
    sfx_rate_scale = 0x5622;
  }
  if ((sfx_id == sfx_flamer_fire_01) || (sfx_id == sfx_flamer_fire_02)) {
    sfx_cooldown_table[sfx_id] = 0.44;
  }
  else {
    sfx_cooldown_table[sfx_id] = 0.05;
  }
  iVar1 = sfx_entry_start_playback((int)(&sfx_entry_table + sfx_id));
  (**(code **)(*(int *)(&sfx_entry_table)[sfx_id].buffers[iVar1] + 0x40))
            ((&sfx_entry_table)[sfx_id].buffers[iVar1],0);
  sfx_entry_set_volume((int)(&sfx_entry_table + sfx_id),config_blob.sfx_volume * unaff_retaddr);
  return sfx_id;
}



