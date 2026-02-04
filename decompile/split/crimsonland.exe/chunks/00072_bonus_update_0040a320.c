/* bonus_update @ 0040a320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* updates bonus lifetimes and handles player pickups */

void bonus_update(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  bonus_entry_time_block_t *pbVar5;
  
  if (render_pass_mode != '\0') {
    pbVar5 = &bonus_pool[0].time;
    iVar4 = config_blob.reserved0._20_4_;
    do {
      if (*(int *)((int)(pbVar5 + -1) + 0xc) != 0) {
        cVar1 = *(char *)((int)(pbVar5 + -1) + 0x10);
        if (cVar1 == '\0') {
          fVar2 = pbVar5->time_left - frame_dt;
        }
        else {
          fVar2 = pbVar5->time_left - frame_dt * 3.0;
        }
        pbVar5->time_left = fVar2;
        if ((cVar1 == '\0') && (config_blob.reserved0._24_4_ == 8)) {
          pbVar5->time_left = 5.0;
        }
        if (pbVar5->time_left < 0.0) {
          ((bonus_entry_t *)((int)(pbVar5 + -1) + 0xc))->bonus_id = BONUS_ID_NONE;
        }
        if (cVar1 == '\0') {
          render_overlay_player_index = 0;
          if (0 < iVar4) {
            do {
              fVar2 = pbVar5->pos_x - (&player_state_table)[render_overlay_player_index].pos_x;
              fVar3 = pbVar5->pos_y - (&player_state_table)[render_overlay_player_index].pos_y;
              if (SQRT(fVar3 * fVar3 + fVar2 * fVar2) < 26.0) {
                bonus_apply(render_overlay_player_index,(bonus_entry_t *)((int)(pbVar5 + -1) + 0xc))
                ;
                iVar4 = config_blob.reserved0._20_4_;
                *(undefined1 *)((int)(pbVar5 + -1) + 0x10) = 1;
                pbVar5->time_left = 0.5;
              }
              render_overlay_player_index = render_overlay_player_index + 1;
            } while (render_overlay_player_index < iVar4);
          }
        }
      }
      pbVar5 = (bonus_entry_time_block_t *)((int)(pbVar5 + 1) + 8);
    } while ((int)pbVar5 < 0x482b10);
    render_overlay_player_index = 0;
    if (_bonus_freeze_timer <= 0.0) {
      _bonus_freeze_timer = 0.0;
    }
    else {
      _bonus_freeze_timer = _bonus_freeze_timer - frame_dt;
    }
    if (_bonus_double_xp_timer <= 0.0) {
      _bonus_double_xp_timer = 0.0;
    }
    else {
      _bonus_double_xp_timer = _bonus_double_xp_timer - frame_dt;
    }
    if (0.0 <= _DAT_004aaf2c) {
      _DAT_004aaf2c = (_DAT_004aaf2c + 1.0) * frame_dt * 1.8 + _DAT_004aaf2c;
    }
  }
  return;
}



