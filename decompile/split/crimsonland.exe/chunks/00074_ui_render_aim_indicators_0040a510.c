/* ui_render_aim_indicators @ 0040a510 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders aim reticles, reload gauges, and player HUD indicators */

void ui_render_aim_indicators(void)

{
  IGrim2D_vtbl *pIVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  float a;
  float fStack_60;
  
  if (demo_mode_active == '\0') {
    if ((DAT_00480340 & 1) == 0) {
      DAT_00480340 = DAT_00480340 | 1;
      crt_atexit(&DAT_0040aaa0);
    }
    if ((DAT_00480340 & 2) == 0) {
      DAT_00480340 = DAT_00480340 | 2;
      crt_atexit(&DAT_0040aa90);
    }
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    render_overlay_player_index = 0;
    iVar2 = config_blob.reserved0._20_4_;
    if (0 < (int)config_blob.reserved0._20_4_) {
      do {
        if (0.0 < (&player_state_table)[render_overlay_player_index].health) {
          fVar5 = (&player_state_table)[render_overlay_player_index].aim_x -
                  (&player_state_table)[render_overlay_player_index].pos_x;
          fVar6 = (&player_state_table)[render_overlay_player_index].aim_y -
                  (&player_state_table)[render_overlay_player_index].pos_y;
          fStack_60 = SQRT(fVar5 * fVar5 + fVar6 * fVar6) *
                      (&player_state_table)[render_overlay_player_index].spread_heat * 0.5;
          if (fStack_60 < 6.0) {
            fStack_60 = 6.0;
          }
          (*grim_interface_ptr->vtable->grim_set_uv)(0.5,0.5,0.5,0.5);
          (*grim_interface_ptr->vtable->grim_set_color)(0.0,0.0,0.1,0.3);
          aim_screen_x = _camera_offset_x + (&player_state_table)[render_overlay_player_index].aim_x
          ;
          aim_screen_y = _camera_offset_y + (&player_state_table)[render_overlay_player_index].aim_y
          ;
          (*grim_interface_ptr->vtable->grim_draw_circle_filled)
                    (aim_screen_x,aim_screen_y,fStack_60);
          (*grim_interface_ptr->vtable->grim_bind_texture)(bullet_trail_texture,0);
          (*grim_interface_ptr->vtable->grim_set_uv)(0.5,0.0,0.5,1.0);
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.55);
          (*grim_interface_ptr->vtable->grim_draw_circle_outline)
                    (aim_screen_x,aim_screen_y,fStack_60);
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.7,0.1,0.8);
          aim_screen_x = _camera_offset_x + (&player_state_table)[render_overlay_player_index].aim_x
          ;
          aim_screen_y = _camera_offset_y + (&player_state_table)[render_overlay_player_index].aim_y
          ;
          ui_draw_clock_gauge_at
                    (&aim_screen_x,48.0,
                     (&player_state_table)[render_overlay_player_index].reload_timer /
                     (&player_state_table)[render_overlay_player_index].reload_timer_max);
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.7);
          iVar2 = config_blob.reserved0._20_4_;
        }
        render_overlay_player_index = render_overlay_player_index + 1;
      } while (render_overlay_player_index < iVar2);
    }
    render_overlay_player_index = 0;
    if (0 < iVar2) {
      do {
        if ((0.0 < (&player_state_table)[render_overlay_player_index].health) &&
           (config_blob.reserved0[render_overlay_player_index + 4] != '\0')) {
          (*grim_interface_ptr->vtable->grim_set_rotation)
                    ((&player_state_table)[render_overlay_player_index].heading);
          (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7d8,0);
          (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
          if (config_blob.reserved0._20_4_ == 2) {
            if (render_overlay_player_index == 0) {
              pIVar1 = grim_interface_ptr->vtable;
              a = 0.6;
              fVar6 = 0.9;
              fVar5 = 0.8;
              goto LAB_0040a8dc;
            }
            (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.9,0.8,0.6);
          }
          else {
            a = 0.3;
            fVar6 = 1.0;
            pIVar1 = grim_interface_ptr->vtable;
            fVar5 = 1.0;
LAB_0040a8dc:
            (*pIVar1->grim_set_color)(fVar5,fVar6,1.0,a);
          }
          (*grim_interface_ptr->vtable->grim_begin_batch)();
          if (*(int *)(config_blob.reserved0 + render_overlay_player_index * 4 + 0x1c) == 4) {
            fVar5 = _camera_offset_x +
                    (&player_state_table)[render_overlay_player_index].move_target_x;
            aim_screen_y = (_camera_offset_y +
                           (&player_state_table)[render_overlay_player_index].move_target_y) - 16.0;
          }
          else {
            fVar3 = (float10)(&player_state_table)[render_overlay_player_index].heading -
                    (float10)1.5707964;
            fVar4 = (float10)fcos(fVar3);
            fVar3 = (float10)fsin(fVar3);
            fVar5 = _camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x +
                    (float)fVar4 * 60.0;
            aim_screen_y = (float)((fVar3 * (float10)60.0 +
                                   (float10)(_camera_offset_y +
                                            (&player_state_table)[render_overlay_player_index].pos_y
                                            )) - (float10)16.0);
          }
          aim_screen_x = fVar5 - 16.0;
          (*grim_interface_ptr->vtable->grim_draw_quad)(aim_screen_x,aim_screen_y,32.0,32.0);
          (*grim_interface_ptr->vtable->grim_end_batch)();
          iVar2 = config_blob.reserved0._20_4_;
        }
        render_overlay_player_index = render_overlay_player_index + 1;
      } while (render_overlay_player_index < iVar2);
    }
    render_overlay_player_index = 0;
    if (0 < iVar2) {
      do {
        if (0.0 < (&player_state_table)[render_overlay_player_index].health) {
          ui_render_aim_enhancement();
          iVar2 = config_blob.reserved0._20_4_;
        }
        render_overlay_player_index = render_overlay_player_index + 1;
      } while (render_overlay_player_index < iVar2);
    }
    render_overlay_player_index = 0;
  }
  return;
}



