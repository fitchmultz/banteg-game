/* bonus_render @ 004295f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders bonus icons and labels from the pickup pool */

void bonus_render(void)

{
  int iVar1;
  char *text;
  uint uVar2;
  bonus_entry_t *pbVar3;
  int iVar4;
  float *pfVar5;
  bonus_entry_time_block_t *pbVar6;
  int iVar7;
  int *piVar8;
  secondary_projectile_vel_x_block_t *psVar9;
  uint uVar10;
  bool bVar11;
  float10 extraout_ST0;
  float10 fVar12;
  float10 extraout_ST0_00;
  float10 fVar13;
  int *piStack_8c;
  int iStack_84;
  float fVar14;
  float fVar15;
  float fStack_70;
  float fVar16;
  float fVar17;
  
  if ((((0.0 < ui_transition_alpha) && (game_state_id != 0x14)) && (game_state_id != 0x16)) &&
     ((game_state_prev != 0x14 && (game_state_prev != 0x16)))) {
    _DAT_004aaf5c = frame_dt * 1.3 + _DAT_004aaf5c;
    (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
    effect_select_texture(0x10);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    fStack_70 = 6.11523e-39;
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
    fVar14 = 2.66247e-44;
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_bind_texture)((int)bonus_texture,0);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    fStack_70 = 1.0;
    fVar16 = 1.0;
    fVar17 = 1.0;
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    iStack_84 = 0;
    pbVar6 = &bonus_pool[0].time;
    do {
      if (*(int *)((int)(pbVar6 + -1) + 0xc) != 0) {
        if (pbVar6->time_left < 2.0) {
          fsin((float10)pbVar6->time_left * (float10)18.849556);
        }
        if (0.0 <= fStack_70) {
          if (1.0 < fStack_70) {
            fStack_70 = 1.0;
          }
        }
        else {
          fStack_70 = 0.0;
        }
        if (0.0 <= fVar16) {
          if (1.0 < fVar16) {
            fVar16 = 1.0;
          }
        }
        else {
          fVar16 = 0.0;
        }
        if (0.0 <= fVar17) {
          if (1.0 < fVar17) {
            fVar17 = 1.0;
          }
        }
        else {
          fVar17 = 0.0;
        }
        (*grim_interface_ptr->vtable->grim_set_color_ptr)(&fStack_70);
        (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
        (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,0);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + pbVar6->pos_x) - 16.0,
                   (_camera_offset_y + pbVar6->pos_y) - 16.0,32.0,32.0);
        iVar4 = (&bonus_meta_table)[*(int *)((int)(pbVar6 + -1) + 0xc)].icon_id;
        if (-1 < iVar4) {
          if (0.5 <= pbVar6->time_left) {
            fVar15 = pbVar6->time_max - pbVar6->time_left;
            if (0.5 <= fVar15) {
              fVar15 = 1.0;
            }
            else {
              fVar15 = fVar15 + fVar15;
            }
          }
          else {
            fVar15 = pbVar6->time_left + pbVar6->time_left;
          }
          fVar15 = fVar15 * fVar14;
          if (0.0 <= fStack_70) {
            if (1.0 < fStack_70) {
              fStack_70 = 1.0;
            }
          }
          else {
            fStack_70 = 0.0;
          }
          if (0.0 <= fVar16) {
            if (1.0 < fVar16) {
              fVar16 = 1.0;
            }
          }
          else {
            fVar16 = 0.0;
          }
          if (0.0 <= fVar17) {
            if (1.0 < fVar17) {
              fVar17 = 1.0;
            }
          }
          else {
            fVar17 = 0.0;
          }
          (*grim_interface_ptr->vtable->grim_set_color_ptr)(&fStack_70);
          fsin((float10)iStack_84 + (float10)_DAT_004aaf5c);
          crt_ci_pow();
          fVar15 = (float)((extraout_ST0 * (float10)0.25 + (float10)0.75) * (float10)fVar15);
          (*grim_interface_ptr->vtable->grim_set_color_ptr)(&fStack_70);
          fVar12 = (float10)fsin((float10)iStack_84 -
                                 (float10)(int)highscore_active_record.survival_elapsed_ms *
                                 (float10)0.003);
          (*grim_interface_ptr->vtable->grim_set_rotation)((float)(fVar12 * (float10)0.2));
          if ((*(int *)((int)(pbVar6 + -1) + 0xc) == 1) && (pbVar6->amount == 1000)) {
            (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,iVar4 + 1);
          }
          else {
            (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,iVar4);
          }
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + pbVar6->pos_x) - fVar15 * 16.0,
                     (_camera_offset_y + pbVar6->pos_y) - fVar15 * 16.0,fVar15 * 32.0,fVar15 * 32.0)
          ;
        }
      }
      pbVar6 = (bonus_entry_time_block_t *)((int)(pbVar6 + 1) + 8);
      iStack_84 = iStack_84 + 1;
    } while ((int)pbVar6 < 0x482b10);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    iVar4 = 0;
    (*grim_interface_ptr->vtable->grim_bind_texture)(ui_weapon_icons_texture,0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    iStack_84 = 0;
    pbVar6 = &bonus_pool[0].time;
    do {
      if (*(int *)((int)(pbVar6 + -1) + 0xc) == 3) {
        if (0.5 <= pbVar6->time_left) {
          fVar16 = pbVar6->time_max - pbVar6->time_left;
          if (0.5 <= fVar16) {
            fVar16 = 1.0;
          }
          else {
            fVar16 = fVar16 + fVar16;
          }
        }
        else {
          fVar16 = pbVar6->time_left + pbVar6->time_left;
        }
        fVar16 = fVar16 * fVar14;
        (*grim_interface_ptr->vtable->grim_set_color_ptr)(&fStack_70);
        fsin((float10)_DAT_004aaf5c);
        crt_ci_pow();
        fVar16 = (float)((extraout_ST0_00 * (float10)0.25 + (float10)0.75) * (float10)fVar16);
        (*grim_interface_ptr->vtable->grim_set_color_ptr)(&fStack_70);
        fVar12 = (float10)fsin((float10)iStack_84 -
                               (float10)(int)highscore_active_record.survival_elapsed_ms *
                               (float10)0.003);
        (*grim_interface_ptr->vtable->grim_set_rotation)((float)fVar12);
        (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
        (*grim_interface_ptr->vtable->grim_set_sub_rect)
                  (8,2,1,(&weapon_table)[pbVar6->amount].hud_icon_id << 1);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + pbVar6->pos_x) - fVar16 * 30.0,
                   (_camera_offset_y + pbVar6->pos_y) - fVar16 * 15.0,fVar16 * 60.0,fVar16 * 30.0);
      }
      pbVar6 = (bonus_entry_time_block_t *)((int)(pbVar6 + 1) + 8);
      iStack_84 = iStack_84 + 1;
    } while ((int)pbVar6 < 0x482b10);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.7);
    if (0 < (int)config_blob.reserved0._20_4_) {
      pfVar5 = &player_state_table.aim_x;
      piStack_8c = &DAT_004aaf60;
      do {
        if (0.0 < pfVar5[-0xb]) {
          iVar7 = 0;
          pbVar3 = bonus_pool;
          do {
            if ((pbVar3->bonus_id != BONUS_ID_NONE) &&
               (fVar14 = *pfVar5 - (pbVar3->time).pos_x, fVar16 = pfVar5[1] - (pbVar3->time).pos_y,
               SQRT(fVar14 * fVar14 + fVar16 * fVar16) < 24.0)) {
              if (game_state_id == 9) {
                *piStack_8c = *piStack_8c + frame_dt_ms;
              }
              text = bonus_label_for_entry(bonus_pool + iVar7);
              fVar14 = _camera_offset_x + *pfVar5 + 16.0;
              fVar16 = (_camera_offset_y + pfVar5[1]) - 7.0;
              iVar1 = (*grim_interface_ptr->vtable->grim_measure_text_width)(text);
              if ((float)config_blob.screen_width < (float)iVar1 + fVar14) {
                fVar14 = (float)config_blob.screen_width - (float)iVar1;
              }
              (*grim_interface_ptr->vtable->grim_draw_text_small)(fVar14,fVar16,text);
              goto LAB_00429df8;
            }
            pbVar3 = pbVar3 + 1;
            iVar7 = iVar7 + 1;
          } while ((int)pbVar3 < 0x482b08);
          *piStack_8c = 0;
LAB_00429df8:
          if (((0x28a < *piStack_8c) && (iVar1 = perk_count_get(perk_id_telekinetic), iVar1 != 0))
             && (bonus_pool[iVar7].state == '\0')) {
            bonus_apply(iVar4,bonus_pool + iVar7);
            bonus_pool[iVar7].state = '\x01';
            bonus_pool[iVar7].time.time_left = 0.5;
            (&DAT_004aaf60)[iVar4] = 0;
            break;
          }
        }
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 0xd8;
        piStack_8c = piStack_8c + 1;
      } while (iVar4 < (int)config_blob.reserved0._20_4_);
    }
    if (config_blob.reserved0[0x10] != '\0') {
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
      (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
      effect_select_texture(0xd);
      (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.065);
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      uVar10 = 0;
      piVar8 = &particle_pool.style_id;
      do {
        if (((particle_t *)(piVar8 + -0xc))->active != '\0') {
          uVar2 = uVar10 & 0x80000001;
          bVar11 = uVar2 == 0;
          if ((int)uVar2 < 0) {
            bVar11 = (uVar2 - 1 | 0xfffffffe) == 0xffffffff;
          }
          if ((bVar11) && ((char)*piVar8 != '\b')) {
            fVar12 = (float10)fsin(((float10)1.0 - (float10)(float)piVar8[-3]) * (float10)1.5707964)
            ;
            fVar12 = (fVar12 + (float10)0.1) * (float10)55.0 + (float10)4.0;
            if (fVar12 < (float10)16.0) {
              fVar12 = (float10)16.0;
            }
            (*grim_interface_ptr->vtable->grim_draw_quad)
                      ((float)(((float10)_camera_offset_x + (float10)(float)piVar8[-0xb]) - fVar12),
                       (float)(((float10)_camera_offset_y + (float10)(float)piVar8[-10]) - fVar12),
                       (float)(fVar12 + fVar12),(float)(fVar12 + fVar12));
          }
        }
        piVar8 = piVar8 + 0xe;
        uVar10 = uVar10 + 1;
      } while ((int)piVar8 < 0x495ae8);
      (*grim_interface_ptr->vtable->grim_end_batch)();
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    }
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
    (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
    effect_select_texture(0xc);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    pfVar5 = &particle_pool.spin;
    do {
      if ((((particle_t *)(pfVar5 + -0xb))->active != '\0') && (SUB41(pfVar5[1],0) != '\b')) {
        (*grim_interface_ptr->vtable->grim_set_rotation)(*pfVar5);
        (*grim_interface_ptr->vtable->grim_set_color)(pfVar5[-6],pfVar5[-5],pfVar5[-4],pfVar5[-3]);
        fVar12 = (float10)fsin(((float10)1.0 - (float10)pfVar5[-2]) * (float10)1.5707964);
        fVar12 = fVar12 * (float10)24.0;
        if (SUB41(pfVar5[1],0) == '\x01') {
          fVar12 = fVar12 * (float10)0.8;
        }
        if (fVar12 < (float10)2.0) {
          fVar12 = (float10)2.0;
        }
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((float)(((float10)_camera_offset_x + (float10)pfVar5[-10]) - fVar12),
                   (float)(((float10)_camera_offset_y + (float10)pfVar5[-9]) - fVar12),
                   (float)(fVar12 + fVar12),(float)(fVar12 + fVar12));
      }
      pfVar5 = pfVar5 + 0xe;
    } while ((int)pfVar5 < 0x495ae4);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    effect_select_texture(2);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    piVar8 = &particle_pool.style_id;
    do {
      if ((((particle_t *)(piVar8 + -0xc))->active != '\0') && ((char)*piVar8 == '\b')) {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,(float)piVar8[-4]);
        fVar12 = (float10)fsin((float10)(float)piVar8[-1]);
        fVar13 = (fVar12 * (float10)3.0 + (float10)15.0) * (float10)(float)piVar8[-7] * (float10)7.0
        ;
        fVar14 = (float)((float10)15.0 - fVar12 * (float10)3.0) * (float)piVar8[-7] * 7.0;
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + (float)piVar8[-0xb]) - fVar14,
                   (float)(((float10)_camera_offset_y + (float10)(float)piVar8[-10]) - fVar13),
                   fVar14 + fVar14,(float)(fVar13 + fVar13));
      }
      piVar8 = piVar8 + 0xe;
    } while ((int)piVar8 < 0x495ae8);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    psVar9 = &secondary_projectile_pool[0].pos.vx;
    do {
      if ((*(char *)((int)(psVar9 + -1) + 4) != '\0') &&
         ((psVar9->vy).type_id == SECONDARY_PROJECTILE_TYPE_EXPLODING)) {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.6,0.1,1.0 - psVar9->vel_x);
        fVar14 = (psVar9->vy).vel_y * psVar9->vel_x * 64.0;
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + *(float *)((int)(psVar9 + -1) + 0x10)) - fVar14 * 0.5,
                   (_camera_offset_y + *(float *)((int)(psVar9 + -1) + 0x14)) - fVar14 * 0.5,fVar14,
                   fVar14);
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.6,0.1,(1.0 - psVar9->vel_x) * 0.3);
        fVar14 = (psVar9->vy).vel_y * psVar9->vel_x * 200.0;
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + *(float *)((int)(psVar9 + -1) + 0x10)) - fVar14 * 0.5,
                   (_camera_offset_y + *(float *)((int)(psVar9 + -1) + 0x14)) - fVar14 * 0.5,fVar14,
                   fVar14);
      }
      psVar9 = (secondary_projectile_vel_x_block_t *)((int)(psVar9 + 1) + 0x14);
    } while ((int)psVar9 < 0x4965ec);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    if (config_blob.reserved0[0x11] != '\0') {
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
      (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
      (*grim_interface_ptr->vtable->grim_set_uv)
                (DAT_00491248,DAT_0049124c,DAT_00491248 + 0.25,DAT_0049124c + 0.25);
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      pfVar5 = &sprite_effect_pool.scale;
      do {
        if ((char)((sprite_effect_t *)(pfVar5 + -10))->active != '\0') {
          fVar14 = *pfVar5;
          (*grim_interface_ptr->vtable->grim_set_rotation)(pfVar5[-5]);
          (*grim_interface_ptr->vtable->grim_set_color)(pfVar5[-9],pfVar5[-8],pfVar5[-7],pfVar5[-6])
          ;
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + pfVar5[-4]) - fVar14 * 0.5,
                     (_camera_offset_y + pfVar5[-3]) - fVar14 * 0.5,fVar14,fVar14);
        }
        pfVar5 = pfVar5 + 0xb;
      } while ((int)pfVar5 < 0x49aa48);
      (*grim_interface_ptr->vtable->grim_end_batch)();
    }
    effects_render();
  }
  return;
}



