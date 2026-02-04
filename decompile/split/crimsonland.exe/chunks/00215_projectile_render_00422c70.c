/* projectile_render @ 00422c70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders projectiles/secondary projectiles and related beam/trail effects */

void projectile_render(void)

{
  projectile_type_id_t pVar1;
  secondary_projectile_type_id_t sVar2;
  IGrim2D_vtbl *pIVar3;
  projectile_tail_t *ppVar4;
  projectile_vel_y_block_t *ppVar5;
  projectile_t *ppVar6;
  projectile_pos_y_block_t *ppVar7;
  float *pfVar8;
  secondary_projectile_pos_y_block_t *psVar9;
  float unaff_EDI;
  int iVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  ulonglong uVar15;
  longlong lVar16;
  float in_stack_00000004;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float in_stack_fffffe10;
  float fVar23;
  float fVar24;
  int iVar25;
  float in_stack_fffffe20;
  float in_stack_fffffe24;
  float fVar26;
  float in_stack_fffffe34;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_168;
  float fStack_160;
  float fStack_150;
  float fStack_134;
  float fStack_12c;
  float fStack_128;
  float fStack_120;
  float fStack_118;
  float fStack_114;
  float fStack_ec;
  float fStack_c4;
  float fStack_74;
  float fStack_5c;
  float fStack_54;
  float fStack_4c;
  float fStack_24;
  
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.0,0.0,in_stack_00000004 * 0.5);
  (*grim_interface_ptr->vtable->grim_set_color_slot)(2,0.0,0.0,0.0,in_stack_00000004 * 0.2);
  (*grim_interface_ptr->vtable->grim_set_color_slot)(3,0.0,0.0,0.0,in_stack_00000004 * 0.2);
  (*grim_interface_ptr->vtable->grim_bind_texture)((int)bullet_trail_texture,0);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,0.5);
  iVar10 = 0;
  if (0 < (int)config_blob.reserved0._20_4_) {
    pfVar8 = &player_state_table.aim_heading;
    do {
      if (0.0 < pfVar8[-0xb7]) {
        fVar11 = (float10)*pfVar8 - (float10)1.5707964;
        fVar12 = (float10)fcos(fVar11);
        fVar13 = (float10)fsin(fVar11);
        fVar30 = pfVar8[-0xbb];
        fStack_ec = (float)fVar13 * 512.0 + pfVar8[-0xba];
        fVar14 = (float10)fcos(fVar11 - (float10)0.150915);
        fVar28 = (float)(fVar14 * (float10)15.0);
        fVar11 = (float10)fsin(fVar11 - (float10)0.150915);
        fVar29 = (float)((float10)pfVar8[-0xba] + fVar11 * (float10)15.0);
        fVar14 = (float10)fcos((float10)*pfVar8);
        fVar11 = (float10)fsin((float10)*pfVar8);
        fStack_150 = (float)(((float10)(pfVar8[-0xbb] + fVar28) + (float10)_camera_offset_x) -
                            fVar14 * (float10)1.1);
        fStack_114 = fVar29 + _camera_offset_y + (float)(fVar11 * (float10)1.1);
        fVar11 = (float10)_camera_offset_x;
        if (0 < player_state_table.perk_counts[perk_id_sharpshooter]) {
          (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
          (*grim_interface_ptr->vtable->grim_begin_batch)();
          in_stack_fffffe24 = fStack_160;
          (*grim_interface_ptr->vtable->grim_draw_quad_points)
                    (fVar29,fStack_160,fStack_12c,fStack_128,fStack_134,fVar28,(float)fVar13 * 512.0
                     ,(float)((float10)(float)(fVar12 * (float10)512.0 + (float10)fVar30) + fVar11 +
                             fVar14 * (float10)1.1));
          (*grim_interface_ptr->vtable->grim_end_batch)();
          unaff_EDI = 2.8026e-44;
          (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
          in_stack_fffffe20 = fVar29;
          in_stack_fffffe34 = fVar28;
        }
      }
      iVar10 = iVar10 + 1;
      pfVar8 = pfVar8 + 0xd8;
    } while (iVar10 < (int)config_blob.reserved0._20_4_);
  }
  fStack_198 = 0.0;
  (*grim_interface_ptr->vtable->grim_set_color_slot)(0,0.5,0.5,0.5,0.0);
  fVar30 = 0.0;
  fVar29 = 0.5;
  fVar28 = 0.5;
  (*grim_interface_ptr->vtable->grim_set_color_slot)(1,0.5,0.5,0.5,0.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
  ppVar5 = &projectile_pool[0].pos.tail.vy;
  fStack_194 = in_stack_fffffe20;
  fStack_168 = in_stack_fffffe24;
  do {
    if ((*(char *)((int)(ppVar5 + -1) + 8) != '\0') &&
       ((pVar1 = ppVar5->type_id, (int)pVar1 < 8 || (pVar1 == PROJECTILE_TYPE_SPLITTER_GUN)))) {
      if (pVar1 == PROJECTILE_TYPE_NONE) {
        *(undefined1 *)((int)(ppVar5 + -1) + 8) = 0;
      }
      fStack_5c = ppVar5->life_timer;
      if (fStack_5c <= 1.0) {
        if (fStack_5c < 0.0) {
          fStack_5c = 0.0;
        }
      }
      else {
        fStack_5c = 1.0;
      }
      (*grim_interface_ptr->vtable->grim_set_color_slot)(2,0.5,0.5,0.5,fStack_5c * fStack_24);
      (*grim_interface_ptr->vtable->grim_set_color_slot)(3,0.5,0.5,0.5,fStack_5c * fStack_24);
      pVar1 = ppVar5->type_id;
      if (pVar1 == PROJECTILE_TYPE_ASSAULT_RIFLE) {
        fVar27 = _camera_offset_x + *(float *)((int)(ppVar5 + -1) + 0x18);
        fStack_4c = _camera_offset_y + *(float *)((int)(ppVar5 + -1) + 0x1c);
        fVar17 = fVar27 - *(float *)((int)(ppVar5 + -1) + 0x20);
        in_stack_fffffe10 = fStack_4c - ppVar5->vel_y;
        fVar27 = fVar27 + *(float *)((int)(ppVar5 + -1) + 0x20);
        fVar23 = fStack_4c + ppVar5->vel_y;
        fStack_168 = _camera_offset_x + *(float *)((int)(ppVar5 + -1) + 0x10);
        fVar24 = _camera_offset_y + *(float *)((int)(ppVar5 + -1) + 0x14);
        fStack_198 = fStack_168 + *(float *)((int)(ppVar5 + -1) + 0x20);
        fStack_194 = fVar24 + ppVar5->vel_y;
        fStack_168 = fStack_168 - *(float *)((int)(ppVar5 + -1) + 0x20);
        fVar24 = fVar24 - ppVar5->vel_y;
        fStack_114 = fVar23;
      }
      else if (pVar1 == PROJECTILE_TYPE_PISTOL) {
        fVar21 = *(float *)((int)(ppVar5 + -1) + 0x20) * 1.2;
        fVar24 = ppVar5->vel_y * 1.2;
        fVar27 = _camera_offset_x + *(float *)((int)(ppVar5 + -1) + 0x18);
        fStack_54 = _camera_offset_y + *(float *)((int)(ppVar5 + -1) + 0x1c);
        fVar17 = fVar27 - fVar21;
        in_stack_fffffe10 = fStack_54 - fVar24;
        fVar27 = fVar27 + fVar21;
        fVar23 = fStack_54 + fVar24;
        fStack_168 = _camera_offset_x + *(float *)((int)(ppVar5 + -1) + 0x10);
        fStack_74 = _camera_offset_y + *(float *)((int)(ppVar5 + -1) + 0x14);
        fStack_198 = fStack_168 + fVar21;
        fStack_194 = fStack_74 + fVar24;
        fStack_168 = fStack_168 - fVar21;
        fVar24 = fStack_74 - fVar24;
        fStack_190 = fVar17;
      }
      else if (pVar1 == PROJECTILE_TYPE_GAUSS_GUN) {
        (*grim_interface_ptr->vtable->grim_set_color_slot)(2,0.2,0.5,1.0,fStack_5c);
        (*grim_interface_ptr->vtable->grim_set_color_slot)(3,0.2,0.5,1.0,fStack_5c);
        fVar28 = *(float *)((int)(ppVar5 + -1) + 0x20) * 1.1;
        fStack_c4 = ppVar5->vel_y * 1.1;
        fVar27 = _camera_offset_x + *(float *)((int)(ppVar5 + -1) + 0x18);
        fVar23 = _camera_offset_y + *(float *)((int)(ppVar5 + -1) + 0x1c);
        fVar17 = fVar27 - fVar28;
        in_stack_fffffe10 = fVar23 - fStack_c4;
        fVar27 = fVar27 + fVar28;
        fVar23 = fVar23 + fStack_c4;
        fStack_168 = _camera_offset_x + *(float *)((int)(ppVar5 + -1) + 0x10);
        fVar24 = _camera_offset_y + *(float *)((int)(ppVar5 + -1) + 0x14);
        fStack_198 = fStack_168 + fVar28;
        fStack_194 = fVar24 + fStack_c4;
        fStack_168 = fStack_168 - fVar28;
        fVar24 = fVar24 - fStack_c4;
        fVar28 = fVar24;
        fStack_ec = in_stack_fffffe10;
      }
      else {
        fVar30 = *(float *)((int)(ppVar5 + -1) + 0x20) * 0.7;
        unaff_EDI = ppVar5->vel_y * 0.7;
        fVar27 = _camera_offset_x + *(float *)((int)(ppVar5 + -1) + 0x18);
        fVar23 = _camera_offset_y + *(float *)((int)(ppVar5 + -1) + 0x1c);
        fVar17 = fVar27 - fVar30;
        in_stack_fffffe10 = fVar23 - unaff_EDI;
        fVar27 = fVar27 + fVar30;
        fVar23 = fVar23 + unaff_EDI;
        fStack_168 = _camera_offset_x + *(float *)((int)(ppVar5 + -1) + 0x10);
        fVar24 = _camera_offset_y + *(float *)((int)(ppVar5 + -1) + 0x14);
        fStack_198 = fStack_168 + fVar30;
        fStack_194 = fVar24 + unaff_EDI;
        fStack_168 = fStack_168 - fVar30;
        fVar24 = fVar24 - unaff_EDI;
        fStack_150 = fStack_198;
      }
      (*grim_interface_ptr->vtable->grim_draw_quad_points)
                (fVar17,in_stack_fffffe10,fVar27,fVar23,fStack_198,fStack_194,fStack_168,fVar24);
    }
    ppVar5 = (projectile_vel_y_block_t *)((int)(ppVar5 + 1) + 0x1c);
  } while ((int)ppVar5 < 0x493ed4);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  fVar23 = 6.080727e-39;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
  (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
  effect_select_texture(0xd);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  if (0.0 < (&player_state_table)[render_overlay_player_index].muzzle_flash_alpha) {
    fVar11 = ((float10)(&player_state_table)[render_overlay_player_index].aim_heading -
             (float10)1.5707964) - (float10)0.150915;
    fVar12 = (float10)fcos(fVar11);
    fVar24 = (float)(fVar12 * (float10)15.0);
    fVar11 = (float10)fsin(fVar11);
    in_stack_fffffe34 = (float)(fVar11 * (float10)15.0);
    (*grim_interface_ptr->vtable->grim_set_color)
              (1.0,1.0,1.0,
               fStack_4c * (&player_state_table)[render_overlay_player_index].muzzle_flash_alpha);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_draw_quad)
              ((fVar24 + (&player_state_table)[render_overlay_player_index].pos_x + _camera_offset_x
               ) - 80.0,(in_stack_fffffe34 +
                         (&player_state_table)[render_overlay_player_index].pos_y + _camera_offset_y
                        ) - 80.0,160.0,160.0);
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  ppVar7 = &projectile_pool[0].pos;
  do {
    if ((*(char *)((int)(ppVar7 + -1) + 0x28) != '\0') &&
       ((((pVar1 = (ppVar7->tail).vy.type_id, pVar1 == PROJECTILE_TYPE_PLASMA_RIFLE ||
          (pVar1 == PROJECTILE_TYPE_PLASMA_MINIGUN)) || (pVar1 == PROJECTILE_TYPE_SPIDER_PLASMA)) ||
        ((pVar1 == PROJECTILE_TYPE_SHRINKIFIER || (pVar1 == PROJECTILE_TYPE_PLASMA_CANNON)))))) {
      if ((ppVar7->tail).vy.life_timer == 0.4) {
        if (pVar1 == PROJECTILE_TYPE_PLASMA_RIFLE) {
          uVar15 = __ftol();
          lVar16 = __ftol();
          iVar10 = (int)((longlong)
                         ((ulonglong)(uint)((int)uVar15 >> 0x1f) << 0x20 | uVar15 & 0xffffffff) /
                        (longlong)(int)lVar16);
          if (8 < iVar10) {
            iVar10 = 8;
          }
          fVar11 = (float10)*(float *)((int)(ppVar7 + -1) + 0x2c) + (float10)1.5707964;
          fVar12 = (float10)fcos(fVar11);
          fVar30 = (float)(fVar12 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.5);
          fVar11 = (float10)fsin(fVar11);
          fVar23 = (float)(fVar11 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.5);
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_4c * 0.4);
          iVar25 = 0;
          if (0 < iVar10) {
            do {
              (*grim_interface_ptr->vtable->grim_draw_quad)
                        (((float)iVar25 * fVar30 + *(float *)((int)(ppVar7 + -1) + 0x30) +
                         _camera_offset_x) - 11.0,
                         ((float)iVar25 * fVar23 + ppVar7->pos_y + _camera_offset_y) - 11.0,22.0,
                         22.0);
              iVar25 = iVar25 + 1;
            } while (iVar25 < iVar10);
          }
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_4c * 0.45);
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 28.0,
                     (_camera_offset_y + ppVar7->pos_y) - 28.0,56.0,56.0);
          fVar24 = fStack_4c * 0.3;
          pIVar3 = grim_interface_ptr->vtable;
LAB_00423cb4:
          (*pIVar3->grim_set_color)(1.0,1.0,1.0,fVar24);
          if (config_blob.reserved0[0x10] != '\0') {
            (*grim_interface_ptr->vtable->grim_draw_quad)
                      ((_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 128.0,
                       (_camera_offset_y + ppVar7->pos_y) - 128.0,256.0,256.0);
          }
        }
        else {
          if (pVar1 == PROJECTILE_TYPE_PLASMA_MINIGUN) {
            uVar15 = __ftol();
            lVar16 = __ftol();
            iVar10 = (int)((longlong)
                           ((ulonglong)(uint)((int)uVar15 >> 0x1f) << 0x20 | uVar15 & 0xffffffff) /
                          (longlong)(int)lVar16);
            if (3 < iVar10) {
              iVar10 = 3;
            }
            fVar11 = (float10)*(float *)((int)(ppVar7 + -1) + 0x2c) + (float10)1.5707964;
            fVar12 = (float10)fcos(fVar11);
            fVar30 = (float)(fVar12 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.1);
            fVar11 = (float10)fsin(fVar11);
            fVar23 = (float)(fVar11 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.1);
            (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_4c * 0.4);
            iVar25 = 0;
            if (0 < iVar10) {
              do {
                (*grim_interface_ptr->vtable->grim_draw_quad)
                          (((float)iVar25 * fVar30 + *(float *)((int)(ppVar7 + -1) + 0x30) +
                           _camera_offset_x) - 6.0,
                           ((float)iVar25 * fVar23 + ppVar7->pos_y + _camera_offset_y) - 6.0,12.0,
                           12.0);
                iVar25 = iVar25 + 1;
              } while (iVar25 < iVar10);
            }
            (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_168);
            (*grim_interface_ptr->vtable->grim_draw_quad)
                      ((_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 8.0,
                       (_camera_offset_y + ppVar7->pos_y) - 8.0,16.0,16.0);
            pIVar3 = grim_interface_ptr->vtable;
            fVar27 = 1.0;
            fVar24 = 1.0;
            fVar17 = 1.0;
          }
          else {
            if (pVar1 == PROJECTILE_TYPE_PLASMA_CANNON) {
              uVar15 = __ftol();
              lVar16 = __ftol();
              iVar10 = (int)((longlong)
                             ((ulonglong)(uint)((int)uVar15 >> 0x1f) << 0x20 | uVar15 & 0xffffffff)
                            / (longlong)(int)lVar16);
              if (0x12 < iVar10) {
                iVar10 = 0x12;
              }
              fVar11 = (float10)*(float *)((int)(ppVar7 + -1) + 0x2c) + (float10)1.5707964;
              fVar12 = (float10)fcos(fVar11);
              fVar30 = (float)(fVar12 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.6);
              fVar11 = (float10)fsin(fVar11);
              fVar23 = (float)(fVar11 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.6);
              fVar24 = fStack_4c * 0.4;
              (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar24);
              iVar25 = 0;
              if (0 < iVar10) {
                do {
                  (*grim_interface_ptr->vtable->grim_draw_quad)
                            (((float)iVar25 * fVar30 + *(float *)((int)(ppVar7 + -1) + 0x30) +
                             _camera_offset_x) - 22.0,
                             ((float)iVar25 * fVar23 + ppVar7->pos_y + _camera_offset_y) - 22.0,44.0
                             ,44.0);
                  iVar25 = iVar25 + 1;
                } while (iVar25 < iVar10);
              }
              (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_4c * 0.45);
              (*grim_interface_ptr->vtable->grim_draw_quad)
                        ((_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 42.0,
                         (_camera_offset_y + ppVar7->pos_y) - 42.0,84.0,84.0);
              pIVar3 = grim_interface_ptr->vtable;
              goto LAB_00423cb4;
            }
            if (pVar1 == PROJECTILE_TYPE_SPIDER_PLASMA) {
              uVar15 = __ftol();
              lVar16 = __ftol();
              iVar10 = (int)((longlong)
                             ((ulonglong)(uint)((int)uVar15 >> 0x1f) << 0x20 | uVar15 & 0xffffffff)
                            / (longlong)(int)lVar16);
              if (3 < iVar10) {
                iVar10 = 3;
              }
              fVar11 = (float10)*(float *)((int)(ppVar7 + -1) + 0x2c) + (float10)1.5707964;
              fVar12 = (float10)fcos(fVar11);
              fVar30 = (float)(fVar12 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.1);
              fVar11 = (float10)fsin(fVar11);
              fVar23 = (float)(fVar11 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.1);
              (*grim_interface_ptr->vtable->grim_set_color)(0.3,1.0,0.3,fStack_4c * 0.4);
              iVar25 = 0;
              if (0 < iVar10) {
                do {
                  (*grim_interface_ptr->vtable->grim_draw_quad)
                            (((float)iVar25 * fVar30 + *(float *)((int)(ppVar7 + -1) + 0x30) +
                             _camera_offset_x) - 6.0,
                             ((float)iVar25 * fVar23 + ppVar7->pos_y + _camera_offset_y) - 6.0,12.0,
                             12.0);
                  iVar25 = iVar25 + 1;
                } while (iVar25 < iVar10);
              }
              (*grim_interface_ptr->vtable->grim_set_color)(0.3,1.0,0.3,fStack_168);
              (*grim_interface_ptr->vtable->grim_draw_quad)
                        ((_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 8.0,
                         (_camera_offset_y + ppVar7->pos_y) - 8.0,16.0,16.0);
              pIVar3 = grim_interface_ptr->vtable;
              fVar27 = 0.3;
              fVar24 = 1.0;
            }
            else {
              if (pVar1 != PROJECTILE_TYPE_SHRINKIFIER) goto LAB_00424111;
              uVar15 = __ftol();
              lVar16 = __ftol();
              iVar10 = (int)((longlong)
                             ((ulonglong)(uint)((int)uVar15 >> 0x1f) << 0x20 | uVar15 & 0xffffffff)
                            / (longlong)(int)lVar16);
              if (3 < iVar10) {
                iVar10 = 3;
              }
              fVar11 = (float10)*(float *)((int)(ppVar7 + -1) + 0x2c) + (float10)1.5707964;
              fVar12 = (float10)fcos(fVar11);
              fVar30 = (float)(fVar12 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.1);
              fVar11 = (float10)fsin(fVar11);
              fVar23 = (float)(fVar11 * (float10)(ppVar7->tail).vy.speed_scale * (float10)2.1);
              (*grim_interface_ptr->vtable->grim_set_color)(0.3,0.3,1.0,fStack_4c * 0.4);
              iVar25 = 0;
              if (0 < iVar10) {
                do {
                  (*grim_interface_ptr->vtable->grim_draw_quad)
                            (((float)iVar25 * fVar30 + *(float *)((int)(ppVar7 + -1) + 0x30) +
                             _camera_offset_x) - 6.0,
                             ((float)iVar25 * fVar23 + ppVar7->pos_y + _camera_offset_y) - 6.0,12.0,
                             12.0);
                  iVar25 = iVar25 + 1;
                } while (iVar25 < iVar10);
              }
              (*grim_interface_ptr->vtable->grim_set_color)(0.3,0.3,1.0,fStack_168);
              (*grim_interface_ptr->vtable->grim_draw_quad)
                        ((_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 8.0,
                         (_camera_offset_y + ppVar7->pos_y) - 8.0,16.0,16.0);
              pIVar3 = grim_interface_ptr->vtable;
              fVar27 = 1.0;
              fVar24 = 0.3;
            }
            fVar17 = 0.3;
          }
          (*pIVar3->grim_set_color)(fVar17,fVar24,fVar27,fStack_4c * 0.15);
          if (config_blob.reserved0[0x10] != '\0') {
            fVar21 = 120.0;
            fVar17 = 120.0;
            fVar24 = (_camera_offset_y + ppVar7->pos_y) - 60.0;
            pIVar3 = grim_interface_ptr->vtable;
            fVar27 = (_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 60.0;
            goto LAB_00424107;
          }
        }
      }
      else {
        fVar24 = (ppVar7->tail).vy.life_timer * 2.5;
        if (fVar24 <= 1.0) {
          if (fVar24 < 0.0) {
            fVar24 = 0.0;
          }
        }
        else {
          fVar24 = 1.0;
        }
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar24 * fStack_4c);
        fVar21 = 56.0;
        fVar17 = 56.0;
        fVar24 = (_camera_offset_y + ppVar7->pos_y) - 28.0;
        pIVar3 = grim_interface_ptr->vtable;
        fVar27 = (_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 28.0;
LAB_00424107:
        (*pIVar3->grim_draw_quad)(fVar27,fVar24,fVar17,fVar21);
      }
    }
LAB_00424111:
    ppVar7 = (projectile_pos_y_block_t *)((int)(ppVar7 + 1) + 0xc);
  } while ((int)ppVar7 < 0x493ec4);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  fVar24 = 1.0;
  iVar10 = perk_count_get(perk_id_ion_gun_master);
  if (iVar10 != 0) {
    fVar24 = 1.2;
  }
  (*grim_interface_ptr->vtable->grim_bind_texture)(projectile_texture,0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  fVar27 = 0.0;
  ppVar4 = &projectile_pool[0].pos.tail;
  fVar17 = fStack_4c;
  do {
    fVar21 = (float)((int)(ppVar4 + -1) + 0x18);
    fVar26 = in_stack_fffffe34;
    if (*(char *)((int)(ppVar4 + -1) + 0x18) != '\0') {
      pVar1 = (ppVar4->vy).type_id;
      if (pVar1 == PROJECTILE_TYPE_PULSE_GUN) {
        if ((ppVar4->vy).life_timer == 0.4) {
          fVar26 = *(float *)((int)(ppVar4 + -1) + 0x28) - *(float *)((int)(ppVar4 + -1) + 0x20);
          fVar18 = ppVar4->origin_y - *(float *)((int)(ppVar4 + -1) + 0x24);
          fVar18 = SQRT(fVar18 * fVar18 + fVar26 * fVar26) * 0.01;
          (*grim_interface_ptr->vtable->grim_set_rotation)(*(float *)((int)(ppVar4 + -1) + 0x1c));
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(2,0);
          (*grim_interface_ptr->vtable->grim_set_color)(0.1,0.6,0.2,fStack_4c * 0.7);
          fVar26 = fVar18 * 16.0;
          pIVar3 = grim_interface_ptr->vtable;
          fVar18 = fVar18 * 8.0;
LAB_00424257:
          (*pIVar3->grim_draw_quad)
                    ((_camera_offset_x + *(float *)((int)(ppVar4 + -1) + 0x20)) - fVar18,
                     (_camera_offset_y + *(float *)((int)(ppVar4 + -1) + 0x24)) - fVar18,fVar26,
                     fVar26);
          fVar26 = in_stack_fffffe34;
        }
        else {
          (*grim_interface_ptr->vtable->grim_set_rotation)(*(float *)((int)(ppVar4 + -1) + 0x1c));
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(2,0);
          fVar26 = (ppVar4->vy).life_timer * 2.5;
          if (fVar26 <= 1.0) {
            if (fVar26 < 0.0) {
              fVar26 = 0.0;
            }
          }
          else {
            fVar26 = 1.0;
          }
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar26 * fStack_4c);
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + *(float *)((int)(ppVar4 + -1) + 0x20)) - 28.0,
                     (_camera_offset_y + *(float *)((int)(ppVar4 + -1) + 0x24)) - 28.0,56.0,56.0);
          fVar26 = in_stack_fffffe34;
        }
      }
      else if (pVar1 == PROJECTILE_TYPE_SPLITTER_GUN) {
        if ((ppVar4->vy).life_timer == 0.4) {
          fVar26 = *(float *)((int)(ppVar4 + -1) + 0x28) - *(float *)((int)(ppVar4 + -1) + 0x20);
          fVar18 = ppVar4->origin_y - *(float *)((int)(ppVar4 + -1) + 0x24);
          fVar26 = SQRT(fVar18 * fVar18 + fVar26 * fVar26);
          if (20.0 < fVar26) {
            fVar26 = 20.0;
          }
          (*grim_interface_ptr->vtable->grim_set_rotation)(*(float *)((int)(ppVar4 + -1) + 0x1c));
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,3);
          fVar20 = 1.0;
          fVar19 = 1.0;
          pIVar3 = grim_interface_ptr->vtable;
          fVar18 = 1.0;
LAB_00424475:
          (*pIVar3->grim_set_color)(fVar18,fVar19,fVar20,fVar17);
          fVar18 = fVar26 * 0.5;
          pIVar3 = grim_interface_ptr->vtable;
          goto LAB_00424257;
        }
      }
      else if (pVar1 == PROJECTILE_TYPE_BLADE_GUN) {
        if ((ppVar4->vy).life_timer == 0.4) {
          fVar26 = *(float *)((int)(ppVar4 + -1) + 0x28) - *(float *)((int)(ppVar4 + -1) + 0x20);
          fVar18 = ppVar4->origin_y - *(float *)((int)(ppVar4 + -1) + 0x24);
          fVar26 = SQRT(fVar18 * fVar18 + fVar26 * fVar26);
          if (20.0 < fVar26) {
            fVar26 = 20.0;
          }
          (*grim_interface_ptr->vtable->grim_set_rotation)
                    ((float)(int)fVar27 * 0.1 - (float)quest_spawn_timeline * 0.1);
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,6);
          fVar20 = 0.8;
          fVar19 = 0.8;
          pIVar3 = grim_interface_ptr->vtable;
          fVar18 = 0.8;
          goto LAB_00424475;
        }
      }
      else if (((pVar1 == PROJECTILE_TYPE_ION_MINIGUN) || (pVar1 == PROJECTILE_TYPE_ION_RIFLE)) ||
              ((pVar1 == PROJECTILE_TYPE_ION_CANNON || (pVar1 == PROJECTILE_TYPE_FIRE_BULLETS)))) {
        if ((ppVar4->vy).life_timer == 0.4) {
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(2,2);
          thunk_FUN_00452f1d();
          if ((ppVar4->vy).type_id == PROJECTILE_TYPE_FIRE_BULLETS) {
            (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.6,0.1,fVar17);
            fVar21 = in_stack_fffffe34;
          }
          else {
            (*grim_interface_ptr->vtable->grim_set_color)(0.5,0.6,1.0,fVar17);
            fVar21 = in_stack_fffffe34;
          }
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,2);
          fVar17 = fStack_194 * 16.0;
          fVar26 = _camera_offset_x + *(float *)((int)(ppVar4 + -1) + 0x28);
          fVar18 = _camera_offset_y + ppVar4->origin_y;
          if (fStack_190 <= 256.0) {
            fVar19 = 0.0;
            fStack_120 = fStack_190;
          }
          else {
            fVar19 = fStack_190 - 256.0;
            fStack_120 = 256.0;
          }
          fVar23 = fStack_194 * 3.1;
          if (9.0 < fVar23) {
            fVar23 = 9.0;
          }
          fVar28 = fVar19;
          if (fVar19 < fStack_190) {
            fVar20 = fStack_194 * 32.0;
            do {
              if ((ppVar4->vy).type_id == PROJECTILE_TYPE_FIRE_BULLETS) {
                (*grim_interface_ptr->vtable->grim_set_color)
                          (1.0,0.6,0.1,((fVar28 - fVar19) / fStack_120) * fStack_54);
              }
              else {
                (*grim_interface_ptr->vtable->grim_set_color)
                          (0.5,0.6,1.0,((fVar28 - fVar19) / fStack_120) * fStack_54);
              }
              (*grim_interface_ptr->vtable->grim_draw_quad)
                        (fVar30 * fVar28 + (fVar26 - fVar17),unaff_EDI * fVar28 + (fVar18 - fVar17),
                         fVar20,fVar20);
              fVar28 = fVar23 + fVar28;
            } while (fVar28 < fStack_190);
          }
          fVar26 = fVar21;
          (*grim_interface_ptr->vtable->grim_set_rotation)(*(float *)((int)fVar21 + 4));
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,0.7,fStack_54);
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + *(float *)((int)fVar21 + 8)) - fVar17,
                     (_camera_offset_y + *(float *)((int)fVar21 + 0xc)) - fVar17,fStack_194 * 32.0,
                     fStack_194 * 32.0);
          fVar17 = fStack_54;
        }
        else {
          (*grim_interface_ptr->vtable->grim_set_rotation)(*(float *)((int)(ppVar4 + -1) + 0x1c));
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,2);
          thunk_FUN_00452f1d();
          pVar1 = (ppVar4->vy).type_id;
          if (pVar1 == PROJECTILE_TYPE_ION_MINIGUN) {
            fStack_194 = 1.05;
          }
          else if (pVar1 == PROJECTILE_TYPE_ION_RIFLE) {
            fStack_194 = 2.2;
          }
          else {
            fStack_194 = 0.8;
            if (pVar1 != PROJECTILE_TYPE_FIRE_BULLETS) {
              fStack_194 = 3.5;
            }
          }
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,2);
          fVar17 = fStack_194 * 16.0;
          fVar18 = (_camera_offset_x + *(float *)((int)(ppVar4 + -1) + 0x28)) - fVar17;
          fVar21 = _camera_offset_y + ppVar4->origin_y;
          if (fStack_190 <= 256.0) {
            fVar26 = 0.0;
            fStack_118 = fStack_190;
          }
          else {
            fVar26 = fStack_190 - 256.0;
            fStack_118 = 256.0;
          }
          fVar19 = fStack_194 * 3.1;
          if (9.0 < fVar19) {
            fVar19 = 9.0;
          }
          if (fVar26 < fStack_190) {
            fVar20 = fStack_194 * 32.0;
            fVar22 = fVar26;
            do {
              if ((ppVar4->vy).type_id == PROJECTILE_TYPE_FIRE_BULLETS) {
                (*grim_interface_ptr->vtable->grim_set_color)
                          (1.0,0.6,0.1,((fVar22 - fVar26) / fStack_118) * fVar23 * fStack_54);
              }
              else {
                (*grim_interface_ptr->vtable->grim_set_color)
                          (0.5,0.6,1.0,((fVar22 - fVar26) / fStack_118) * fVar23 * fStack_54);
              }
              (*grim_interface_ptr->vtable->grim_draw_quad)
                        (fVar22 * fVar30 + fVar18,fVar22 * unaff_EDI + (fVar21 - fVar17),fVar20,
                         fVar20);
              fVar22 = fVar19 + fVar22;
            } while (fVar22 < fStack_190);
          }
          fVar17 = fVar23 * fStack_54;
          (*grim_interface_ptr->vtable->grim_set_color)(0.5,0.6,1.0,fVar17);
          pfVar8 = (float *)((int)in_stack_fffffe34 + 8);
          fVar21 = in_stack_fffffe34;
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    ((_camera_offset_x + *pfVar8) - 16.0,
                     (_camera_offset_y + *(float *)((int)in_stack_fffffe34 + 0xc)) - 16.0,32.0,32.0)
          ;
          (*grim_interface_ptr->vtable->grim_set_color)(0.5,0.6,1.0,fVar17);
          fStack_190 = fStack_194 * in_stack_fffffe10 * 40.0;
          fVar17 = fStack_54;
          fVar26 = fVar21;
          if (*(int *)((int)in_stack_fffffe34 + 0x20) != 0x2d) {
            iVar10 = creature_find_in_radius(pfVar8,fStack_190,1);
            fVar17 = fVar28;
            while (fVar28 = fVar17, fVar17 = fStack_54, fVar26 = fVar21, iVar10 != -1) {
              (*grim_interface_ptr->vtable->grim_set_uv_point)(0,0.625,0.0);
              (*grim_interface_ptr->vtable->grim_set_uv_point)(1,0.625,0.25);
              (*grim_interface_ptr->vtable->grim_set_uv_point)(2,0.625,0.25);
              (*grim_interface_ptr->vtable->grim_set_uv_point)(3,0.625,0.0);
              thunk_FUN_00452f1d();
              fVar17 = -fVar29;
              fStack_150 = _camera_offset_x + *pfVar8;
              unaff_EDI = _camera_offset_y + *(float *)((int)in_stack_fffffe34 + 0xc);
              fVar29 = fVar17 * fVar24;
              fStack_c4 = fVar24 * fVar28;
              fVar27 = fStack_150 - fVar29 * 10.0;
              fVar20 = unaff_EDI - fStack_c4 * 10.0;
              fVar30 = fStack_150 + fVar29 * 10.0;
              unaff_EDI = fStack_c4 * 10.0 + unaff_EDI;
              fVar26 = _camera_offset_x + (&creature_pool)[iVar10].pos_x;
              fVar22 = _camera_offset_y + (&creature_pool)[iVar10].pos_y;
              fVar19 = fVar29 * 10.0 + fVar26;
              fVar21 = fStack_c4 * 10.0 + fVar22;
              fVar26 = fVar26 - fVar29 * 10.0;
              fVar22 = fVar22 - fStack_c4 * 10.0;
              (*grim_interface_ptr->vtable->grim_draw_quad_points)
                        (fVar27,fVar20,fVar30,unaff_EDI,fVar19,fVar21,fVar26,fVar22);
              fVar29 = fVar17 * fVar24;
              fStack_ec = fVar28 * fVar24;
              fVar21 = fStack_ec * 4.0 + fVar21;
              fVar27 = fVar27 - fVar29 * 4.0;
              fVar30 = fVar30 + fVar29 * 4.0;
              unaff_EDI = fStack_ec * 4.0 + unaff_EDI;
              (*grim_interface_ptr->vtable->grim_draw_quad_points)
                        (fVar27,fVar20 - fStack_ec * 4.0,fVar30,unaff_EDI,fVar19 + fVar29 * 4.0,
                         fVar21,fVar26 - fVar29 * 4.0,fVar22 - fStack_ec * 4.0);
              (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,2);
              (*grim_interface_ptr->vtable->grim_draw_quad)
                        ((_camera_offset_x + (&creature_pool)[iVar10].pos_x) - fVar18,
                         (_camera_offset_y + (&creature_pool)[iVar10].pos_y) - fVar18,fVar23,fVar23)
              ;
              iVar10 = creature_find_in_radius(pfVar8,fStack_198,iVar10 + 1);
              fVar29 = fVar28;
            }
          }
        }
      }
    }
    ppVar4 = (projectile_tail_t *)((int)(ppVar4 + 1) + 0x14);
    fVar27 = (float)((int)fVar27 + 1);
    in_stack_fffffe34 = fVar26;
  } while ((int)ppVar4 < 0x493ecc);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,1);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  iVar10 = 0;
  ppVar7 = &projectile_pool[0].pos;
  do {
    if ((*(char *)((int)(ppVar7 + -1) + 0x28) != '\0') &&
       ((ppVar7->tail).vy.type_id == PROJECTILE_TYPE_PLAGUE_SPREADER)) {
      if ((ppVar7->tail).vy.life_timer == 0.4) {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar17);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 30.0,
                   (_camera_offset_y + ppVar7->pos_y) - 30.0,60.0,60.0);
        fVar11 = (float10)*(float *)((int)(ppVar7 + -1) + 0x2c) + (float10)1.5707964;
        fVar12 = (float10)fsin(fVar11);
        fVar11 = (float10)fcos(fVar11);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((float)((((float10)_camera_offset_x +
                            (float10)*(float *)((int)(ppVar7 + -1) + 0x30)) - (float10)30.0) +
                          fVar11 * (float10)15.0),
                   (float)((((float10)_camera_offset_y + (float10)ppVar7->pos_y) - (float10)30.0) +
                          fVar12 * (float10)15.0),60.0,60.0);
        fVar30 = (float)((float10)iVar10 + (float10)fStack_150);
        fVar11 = (float10)fcos((float10)iVar10 + (float10)fStack_150);
        fVar12 = (float10)fsin((float10)fVar30);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((float)(fVar11 * fVar11 +
                          (((float10)_camera_offset_x +
                           (float10)*(float *)((int)(ppVar7 + -1) + 0x30)) - (float10)31.0)),
                   (float)((((float10)_camera_offset_y + (float10)ppVar7->pos_y) - (float10)31.0) +
                          fVar12 * (float10)11.0),52.0,52.0);
        fVar11 = (float10)fsin((float10)fVar30 + (float10)2.0943952);
        fVar28 = (float)fVar11;
        fVar11 = (float10)fcos((float10)fVar30 + (float10)2.0943952);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((float)((((float10)_camera_offset_x +
                            (float10)*(float *)((int)(ppVar7 + -1) + 0x30)) - (float10)31.0) +
                          fVar11 * (float10)10.0),
                   fVar28 * 10.0 + ((_camera_offset_y + ppVar7->pos_y) - 31.0),62.0,62.0);
        fVar11 = (float10)fsin((float10)fVar30 + (float10)4.1887903);
        fVar12 = (float10)fcos((float10)fVar30 + (float10)4.1887903);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((float)((((float10)_camera_offset_x +
                            (float10)*(float *)((int)(ppVar7 + -1) + 0x30)) - (float10)31.0) +
                          fVar12 * (float10)10.0),
                   (float)((((float10)_camera_offset_y + (float10)ppVar7->pos_y) - (float10)31.0) +
                          fVar11 * (float10)fVar28),62.0,62.0);
      }
      else {
        fVar30 = (ppVar7->tail).vy.life_timer * 2.5;
        if (fVar30 <= 1.0) {
          if (fVar30 < 0.0) {
            fVar30 = 0.0;
          }
        }
        else {
          fVar30 = 1.0;
        }
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar30 * fStack_74);
        fVar28 = fVar30 * 40.0 + 32.0;
        fVar30 = fVar30 * 20.0 + 16.0;
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - fVar30,
                   (_camera_offset_y + ppVar7->pos_y) - fVar30,fVar28,fVar28);
      }
    }
    ppVar7 = (projectile_pos_y_block_t *)((int)(ppVar7 + 1) + 0xc);
    iVar10 = iVar10 + 1;
  } while ((int)ppVar7 < 0x493ec4);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
  (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
  effect_select_texture(0xd);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar17);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  ppVar6 = projectile_pool;
  do {
    if (((ppVar6->active != '\0') && (*(int *)((int)fVar21 + 0x20) == 0x2d)) &&
       ((ppVar6->pos).tail.vy.life_timer == 0.4)) {
      (*grim_interface_ptr->vtable->grim_set_rotation)(ppVar6->angle);
      (*grim_interface_ptr->vtable->grim_draw_quad)
                ((_camera_offset_x + ppVar6->pos_x) - 32.0,
                 (_camera_offset_y + (ppVar6->pos).pos_y) - 32.0,64.0,64.0);
    }
    ppVar6 = ppVar6 + 1;
  } while ((int)ppVar6 < 0x493eb8);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  fVar30 = fStack_c4 * 0.9;
  (*grim_interface_ptr->vtable->grim_set_color)(0.8,0.8,0.8,fVar30);
  (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0049bb30,0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  ppVar7 = &projectile_pool[0].pos;
  do {
    if (((*(char *)((int)(ppVar7 + -1) + 0x28) != '\0') && ((ppVar7->tail).vy.life_timer == 0.4)) &&
       ((pVar1 = (ppVar7->tail).vy.type_id, pVar1 != PROJECTILE_TYPE_PLASMA_RIFLE &&
        ((pVar1 != PROJECTILE_TYPE_PLASMA_MINIGUN && (pVar1 != PROJECTILE_TYPE_PULSE_GUN)))))) {
      (*grim_interface_ptr->vtable->grim_set_rotation)(*(float *)((int)(ppVar7 + -1) + 0x2c));
      pVar1 = (ppVar7->tail).vy.type_id;
      if (pVar1 == PROJECTILE_TYPE_PISTOL) {
        fVar24 = 6.0;
        fVar23 = 6.0;
        pIVar3 = grim_interface_ptr->vtable;
        fVar29 = (_camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30)) - 3.0;
        fVar28 = (_camera_offset_y + ppVar7->pos_y) - 3.0;
      }
      else {
        fVar29 = _camera_offset_x + *(float *)((int)(ppVar7 + -1) + 0x30);
        fVar28 = _camera_offset_y + ppVar7->pos_y;
        if (pVar1 == 4) {
          fVar24 = 8.0;
          fVar29 = fVar29 - 4.0;
          pIVar3 = grim_interface_ptr->vtable;
          fVar23 = 8.0;
          fVar28 = fVar28 - 4.0;
        }
        else {
          fVar24 = 4.0;
          fVar29 = fVar29 - 2.0;
          pIVar3 = grim_interface_ptr->vtable;
          fVar23 = 4.0;
          fVar28 = fVar28 - 2.0;
        }
      }
      (*pIVar3->grim_draw_quad)(fVar29,fVar28,fVar23,fVar24);
    }
    ppVar7 = (projectile_pos_y_block_t *)((int)(ppVar7 + 1) + 0xc);
  } while ((int)ppVar7 < 0x493ec4);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  if (config_blob.reserved0[0x10] != '\0') {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
    (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
    effect_select_texture(0xd);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    pfVar8 = &secondary_projectile_pool[0].angle;
    do {
      if (((secondary_projectile_t *)(pfVar8 + -1))->active != '\0') {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_ec * 0.48);
        fVar11 = (float10)fcos((float10)*pfVar8 - (float10)1.5707964);
        fVar12 = (float10)fsin((float10)*pfVar8 - (float10)1.5707964);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  (((_camera_offset_x + pfVar8[2]) - (float)fVar11 * 5.0) - 70.0,
                   (float)(((float10)(_camera_offset_y +
                                     ((secondary_projectile_pos_y_block_t *)(pfVar8 + 3))->pos_y) -
                           fVar12 * (float10)5.0) - (float10)70.0),140.0,140.0);
      }
      pfVar8 = pfVar8 + 0xb;
    } while ((int)pfVar8 < 0x4965dc);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  (*grim_interface_ptr->vtable->grim_set_color)(0.8,0.8,0.8,fVar30);
  (*grim_interface_ptr->vtable->grim_bind_texture)(projectile_texture,0);
  (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,3);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  psVar9 = &secondary_projectile_pool[0].pos;
  do {
    if ((*(char *)((int)(psVar9 + -1) + 0xc) != '\0') &&
       ((psVar9->vx).vy.type_id != SECONDARY_PROJECTILE_TYPE_EXPLODING)) {
      (*grim_interface_ptr->vtable->grim_set_rotation)(*(float *)((int)(psVar9 + -1) + 0x10));
      sVar2 = (psVar9->vx).vy.type_id;
      if (sVar2 == SECONDARY_PROJECTILE_TYPE_ROCKET) {
        fVar29 = (_camera_offset_x + *(float *)((int)(psVar9 + -1) + 0x18)) - 7.0;
        fVar28 = (_camera_offset_y + psVar9->pos_y) - 7.0;
        (*grim_interface_ptr->vtable->grim_set_color)(0.8,0.8,0.8,fVar30);
        fVar24 = 14.0;
        fVar23 = 14.0;
        pIVar3 = grim_interface_ptr->vtable;
LAB_00425a07:
        (*pIVar3->grim_draw_quad)(fVar29,fVar28,fVar23,fVar24);
      }
      else if (sVar2 == SECONDARY_PROJECTILE_TYPE_SEEKER_ROCKET) {
        fVar29 = (_camera_offset_x + *(float *)((int)(psVar9 + -1) + 0x18)) - 5.0;
        fVar28 = (_camera_offset_y + psVar9->pos_y) - 5.0;
        (*grim_interface_ptr->vtable->grim_set_color)(0.8,0.8,0.8,fVar30);
        (*grim_interface_ptr->vtable->grim_draw_quad)(fVar29,fVar28,10.0,10.0);
      }
      else if (sVar2 == SECONDARY_PROJECTILE_TYPE_ROCKET_MINIGUN) {
        fVar29 = (_camera_offset_x + *(float *)((int)(psVar9 + -1) + 0x18)) - 4.0;
        fVar28 = (_camera_offset_y + psVar9->pos_y) - 4.0;
        (*grim_interface_ptr->vtable->grim_set_color)(0.8,0.8,0.8,fVar30);
        fVar24 = 8.0;
        fVar23 = 8.0;
        pIVar3 = grim_interface_ptr->vtable;
        goto LAB_00425a07;
      }
    }
    psVar9 = (secondary_projectile_pos_y_block_t *)((int)(psVar9 + 1) + 0x10);
  } while ((int)psVar9 < 0x4965e8);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  if (config_blob.reserved0[0x10] != '\0') {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
    (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
    effect_select_texture(0xd);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    psVar9 = &secondary_projectile_pool[0].pos;
    do {
      if (*(char *)((int)(psVar9 + -1) + 0xc) != '\0') {
        sVar2 = (psVar9->vx).vy.type_id;
        if (sVar2 == SECONDARY_PROJECTILE_TYPE_ROCKET_MINIGUN) {
          (*grim_interface_ptr->vtable->grim_set_color)(0.7,0.7,1.0,fStack_114 * 0.158);
          fVar11 = (float10)*(float *)((int)(psVar9 + -1) + 0x10) - (float10)1.5707964;
          fVar29 = 30.0;
          fVar28 = 30.0;
          fVar12 = (float10)fcos(fVar11);
          pIVar3 = grim_interface_ptr->vtable;
          fVar11 = (float10)fsin(fVar11);
          fVar30 = ((_camera_offset_x + *(float *)((int)(psVar9 + -1) + 0x18)) - (float)fVar12 * 9.0
                   ) - 15.0;
          fVar11 = ((float10)(_camera_offset_y + psVar9->pos_y) - fVar11 * (float10)9.0) -
                   (float10)15.0;
LAB_00425d30:
          (*pIVar3->grim_draw_quad)(fVar30,(float)fVar11,fVar28,fVar29);
        }
        else if (sVar2 == SECONDARY_PROJECTILE_TYPE_ROCKET) {
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_114 * 0.68);
          fVar11 = (float10)*(float *)((int)(psVar9 + -1) + 0x10) - (float10)1.5707964;
          fVar12 = (float10)fcos(fVar11);
          fVar11 = (float10)fsin(fVar11);
          (*grim_interface_ptr->vtable->grim_draw_quad)
                    (((_camera_offset_x + *(float *)((int)(psVar9 + -1) + 0x18)) -
                     (float)fVar12 * 9.0) - 30.0,
                     (float)(((float10)(_camera_offset_y + psVar9->pos_y) - fVar11 * (float10)9.0) -
                            (float10)30.0),60.0,60.0);
        }
        else if (sVar2 == SECONDARY_PROJECTILE_TYPE_SEEKER_ROCKET) {
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_114 * 0.58);
          fVar11 = (float10)*(float *)((int)(psVar9 + -1) + 0x10) - (float10)1.5707964;
          fVar29 = 40.0;
          fVar28 = 40.0;
          fVar12 = (float10)fcos(fVar11);
          pIVar3 = grim_interface_ptr->vtable;
          fVar11 = (float10)fsin(fVar11);
          fVar30 = ((_camera_offset_x + *(float *)((int)(psVar9 + -1) + 0x18)) - (float)fVar12 * 9.0
                   ) - 20.0;
          fVar11 = ((float10)(_camera_offset_y + psVar9->pos_y) - fVar11 * (float10)9.0) -
                   (float10)20.0;
          goto LAB_00425d30;
        }
      }
      psVar9 = (secondary_projectile_pos_y_block_t *)((int)(psVar9 + 1) + 0x10);
    } while ((int)psVar9 < 0x4965e8);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  }
  return;
}



