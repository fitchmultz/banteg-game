/* creature_render_all @ 00419680 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* creature render pass: overlays + per-type draws via creature_render_type */

void creature_render_all(void)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fStack_30;
  
  if ((((0.0 < ui_transition_alpha) && (game_state_id != 0x14)) && (game_state_id != 0x16)) &&
     ((game_state_prev != 0x14 && (game_state_prev != 0x16)))) {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
    effect_select_texture(0x10);
    (*grim_interface_ptr->vtable->grim_set_color)(0.0,0.0,0.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    pfVar2 = &creature_pool.hitbox_size;
    do {
      if (((creature_t *)(pfVar2 + -4))->active != '\0') {
        iVar1 = perk_count_get(perk_id_monster_vision);
        if (iVar1 != 0) {
          if ((0.0 <= *pfVar2) || (fVar4 = (*pfVar2 + 10.0) * 0.1, 1.0 < fVar4)) {
            fVar4 = 1.0;
          }
          else if (fVar4 < 0.0) {
            fVar4 = 0.0;
          }
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,0.0,fVar4 * fStack_30);
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + pfVar2[1]) - 45.0,(_camera_offset_y + pfVar2[2]) - 45.0,
                     90.0,90.0);
        }
        if (*(uchar *)((int)pfVar2 + -7) != '\0') {
          if (0.0 <= *pfVar2) {
            fVar4 = 1.0;
          }
          else {
            fVar4 = (*pfVar2 + 10.0) * 0.1;
          }
          (*grim_interface_ptr->vtable->grim_set_color)(0.0,0.0,0.0,fVar4 * fStack_30);
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + pfVar2[1]) - 40.0,(_camera_offset_y + pfVar2[2]) - 40.0,
                     80.0,80.0);
        }
        if (((uint)pfVar2[0x1f] & 1) != 0) {
          if (0.0 <= *pfVar2) {
            fVar4 = 1.0;
          }
          else {
            fVar4 = (*pfVar2 + 10.0) * 0.1;
          }
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.0,0.0,fVar4 * fStack_30);
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + pfVar2[1]) - 30.0,(_camera_offset_y + pfVar2[2]) - 30.0,
                     60.0,60.0);
        }
      }
      pfVar2 = pfVar2 + 0x26;
    } while ((int)pfVar2 < 0x4aa348);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    creature_render_type(0);
    fVar4 = fStack_30;
    creature_render_type(3);
    creature_render_type(4);
    fVar3 = 2.8026e-45;
    creature_render_type(2);
    creature_render_type(1);
    if (0.0 < _bonus_freeze_timer) {
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5,fVar4);
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6,fVar3,fStack_30);
      (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
      effect_select_texture(0xe);
      (*grim_interface_ptr->vtable->grim_set_color)(0.0,0.0,0.0,1.0);
      (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
      fVar4 = 1.0;
      if (_bonus_freeze_timer < 1.0) {
        if (_bonus_freeze_timer <= 1.0) {
          fVar4 = _bonus_freeze_timer;
          if (_bonus_freeze_timer < 0.0) {
            fVar4 = 0.0;
          }
        }
        else {
          fVar4 = 1.0;
        }
      }
      fVar4 = fVar4 * fVar3 * 0.7;
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      iVar1 = 0;
      pfVar2 = &creature_pool.size;
      do {
        if (((creature_t *)(pfVar2 + -0xd))->active != '\0') {
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar4);
          (*grim_interface_ptr->vtable->grim_set_rotation)((float)iVar1 * 0.01 + pfVar2[-2]);
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + pfVar2[-8]) - *pfVar2 * 0.5,
                     (_camera_offset_y + pfVar2[-7]) - *pfVar2 * 0.5,*pfVar2,*pfVar2);
        }
        pfVar2 = pfVar2 + 0x26;
        iVar1 = iVar1 + 1;
      } while ((int)pfVar2 < 0x4aa36c);
      (*grim_interface_ptr->vtable->grim_end_batch)();
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    }
    (*grim_interface_ptr->vtable->grim_set_color)(0.0,1.0,1.0,1.0);
  }
  return;
}



