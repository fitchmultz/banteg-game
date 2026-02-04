/* player_render_overlays @ 00428390 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Renders per-player overlays/indicators using player_state_table + effect_uv8. Runtime
   (analysis/frida/player_sprite_trace_summary.json): when alive (health>0) draws 2 sprite layers
   per call from effect_uv8[frame] (0–14) and effect_uv8[frame+0x10] (16–30) using heading vs
   aim_heading rotations, with a shadow/outline pass (scale ~1.02/1.03 and offset +3,+3 / +1,+1)
   before the main pass. When dead, draws a single layer from effect_uv8[ftol(death_timer)]
   (32–51) with 0x34 fallback, also with shadow+main passes. */

void player_render_overlays(void)

{
  uv2f_t *puVar1;
  int iVar2;
  int iVar3;
  IGrim2D_vtbl *pIVar4;
  int *piVar5;
  float10 fVar6;
  float10 fVar7;
  longlong lVar8;
  float *pfVar9;
  float fStack_a4;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fVar14;
  float fStack_5c;
  
  if (((((DAT_0048727c != '\0') || (ui_transition_alpha <= 0.0)) || (game_state_id == 0x14)) ||
      ((game_state_id == 0x16 || (game_state_prev == 0x14)))) || (game_state_prev == 0x16)) {
    return;
  }
  iVar2 = perk_count_get(perk_id_radioactive);
  if (iVar2 != 0) {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
    (*grim_interface_ptr->vtable->grim_bind_texture)((int)particles_texture,0);
    effect_select_texture(0x10);
    fVar6 = (float10)fsin((float10)game_time_s);
    (*grim_interface_ptr->vtable->grim_set_color)
              (0.3,0.6,0.3,
               (float)(((fVar6 + (float10)1.0) * (float10)0.1875 + (float10)0.25) *
                      (float10)6.108539e-39));
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_draw_quad)
              ((_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) - 50.0,
               (_camera_offset_y + (&player_state_table)[render_overlay_player_index].pos_y) - 50.0,
               100.0,100.0);
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048287c,0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,1);
  fVar14 = 8.40779e-45;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  iVar2 = render_overlay_player_index;
  if (0.0 < (&player_state_table)[render_overlay_player_index].health) {
    lVar8 = __ftol();
    iVar3 = (int)lVar8;
    fVar6 = (float10)(&player_state_table)[iVar2].aim_heading + (float10)1.5707964;
    fVar7 = (float10)fcos(fVar6);
    fVar12 = (&player_state_table)[iVar2].muzzle_flash_alpha;
    fVar6 = (float10)fsin(fVar6);
    fVar13 = (&player_state_table)[iVar2].muzzle_flash_alpha;
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,2.138129e-39);
    (*grim_interface_ptr->vtable->grim_set_rotation)
              ((&player_state_table)[render_overlay_player_index].heading);
    render_scratch_f0 = (&effect_uv8)[iVar3].u;
    render_scratch_f1 = (&effect_uv8)[iVar3].v;
    puVar1 = &effect_uv8 + iVar3;
    render_scratch_f2 = puVar1->u + 0.125;
    render_scratch_f3 = (&effect_uv8)[iVar3].v + 0.125;
    (*grim_interface_ptr->vtable->grim_set_uv)
              (render_scratch_f0,render_scratch_f1,render_scratch_f2,render_scratch_f3);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    fVar10 = (&player_state_table)[render_overlay_player_index].size * 0.5 - 2.0;
    render_scratch_f0 =
         (_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) - fVar10;
    render_scratch_f1 =
         (_camera_offset_y + (&player_state_table)[render_overlay_player_index].pos_y) - fVar10;
    fVar10 = (&player_state_table)[render_overlay_player_index].size * 1.02;
    (*grim_interface_ptr->vtable->grim_draw_quad)
              (render_scratch_f0 + 1.0,render_scratch_f1 + 1.0,fVar10,fVar10);
    render_scratch_f0 = *(float *)(&DAT_00491090 + iVar3 * 8);
    render_scratch_f1 = *(float *)(&DAT_00491094 + iVar3 * 8);
    iVar2 = iVar3 * 8;
    pfVar9 = (float *)(&DAT_00491090 + iVar2);
    render_scratch_f2 = *pfVar9 + 0.125;
    render_scratch_f3 = *(float *)(&DAT_00491094 + iVar2) + 0.125;
    (*grim_interface_ptr->vtable->grim_set_uv)
              (render_scratch_f0,render_scratch_f1,render_scratch_f2,render_scratch_f3);
    (*grim_interface_ptr->vtable->grim_set_rotation)
              ((&player_state_table)[render_overlay_player_index].aim_heading);
    fVar10 = (&player_state_table)[render_overlay_player_index].size * 0.5;
    render_scratch_f0 =
         ((_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) - fVar10) +
         (float)(fVar7 * (float10)fVar12 * (float10)12.0);
    render_scratch_f1 =
         ((_camera_offset_y + (&player_state_table)[render_overlay_player_index].pos_y) - fVar10) +
         (float)(fVar6 * (float10)fVar13 * (float10)12.0);
    fVar12 = (&player_state_table)[render_overlay_player_index].size * 1.03;
    (*grim_interface_ptr->vtable->grim_draw_quad)
              (render_scratch_f0 + 1.0,render_scratch_f1 + 1.0,fVar12,fVar12);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048287c,0);
    fStack_7c = 6.111067e-39;
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    fVar13 = 8.40779e-45;
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_7c);
    (*grim_interface_ptr->vtable->grim_set_rotation)
              ((&player_state_table)[render_overlay_player_index].heading);
    render_scratch_f0 = puVar1->u;
    render_scratch_f1 = (&effect_uv8)[iVar3].v;
    render_scratch_f2 = puVar1->u + 0.125;
    render_scratch_f3 = (&effect_uv8)[iVar3].v + 0.125;
    (*grim_interface_ptr->vtable->grim_set_uv)
              (render_scratch_f0,render_scratch_f1,render_scratch_f2,render_scratch_f3);
    fVar12 = (&player_state_table)[render_overlay_player_index].size * 0.5;
    render_scratch_f0 =
         (_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) - fVar12;
    render_scratch_f1 =
         (_camera_offset_y + (&player_state_table)[render_overlay_player_index].pos_y) - fVar12;
    (*grim_interface_ptr->vtable->grim_draw_quad)
              (render_scratch_f0,render_scratch_f1,
               (&player_state_table)[render_overlay_player_index].size,
               (&player_state_table)[render_overlay_player_index].size);
    fVar12 = fStack_7c;
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_7c);
    if (1 < (int)config_blob.reserved0._20_4_) {
      if (render_overlay_player_index == 0) {
        (*grim_interface_ptr->vtable->grim_set_color)(0.3,0.3,1.0,fVar12);
      }
      else {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.55,0.35,fVar12);
      }
    }
    render_scratch_f0 = *pfVar9;
    render_scratch_f1 = *(float *)(&DAT_00491094 + iVar2);
    render_scratch_f2 = *pfVar9 + 0.125;
    render_scratch_f3 = *(float *)(&DAT_00491094 + iVar2) + 0.125;
    (*grim_interface_ptr->vtable->grim_set_uv)
              (render_scratch_f0,render_scratch_f1,render_scratch_f2,render_scratch_f3);
    (*grim_interface_ptr->vtable->grim_set_rotation)
              ((&player_state_table)[render_overlay_player_index].aim_heading);
    fVar12 = (&player_state_table)[render_overlay_player_index].size * 0.5;
    render_scratch_f0 =
         ((_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) - fVar12) +
         fVar14;
    render_scratch_f1 =
         ((_camera_offset_y + (&player_state_table)[render_overlay_player_index].pos_y) - fVar12) +
         fStack_5c;
    fVar14 = render_scratch_f1;
    (*grim_interface_ptr->vtable->grim_draw_quad)
              (render_scratch_f0,render_scratch_f1,
               (&player_state_table)[render_overlay_player_index].size,
               (&player_state_table)[render_overlay_player_index].size);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    if (0.0 < (&player_state_table)[render_overlay_player_index].shield_timer) {
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
      (*grim_interface_ptr->vtable->grim_bind_texture)((int)particles_texture,0);
      effect_select_texture(2);
      fVar6 = (float10)fsin((float10)game_time_s);
      pfVar9 = &(&player_state_table)[render_overlay_player_index].shield_timer;
      fVar6 = (fVar6 + (float10)1.0) * (float10)0.25 + (float10)*pfVar9;
      if (*pfVar9 < 1.0) {
        fVar6 = fVar6 * (float10)*pfVar9;
      }
      if ((float10)1.0 < fVar6) {
        fVar6 = (float10)1.0;
      }
      fVar14 = (float)(fVar6 * (float10)6.112132e-39);
      (*grim_interface_ptr->vtable->grim_set_color)(0.35686275,0.7058824,1.0,fVar14 * 0.4);
      fVar6 = (float10)fsin((float10)game_time_s * (float10)3.0);
      fVar12 = (float)(fVar6 + (float10)17.5);
      fVar6 = (float10)(&player_state_table)[render_overlay_player_index].aim_heading -
              (float10)1.5707964;
      fVar7 = (float10)fcos(fVar6);
      fStack_80 = (float)(fVar7 * (float10)3.0);
      fVar6 = (float10)fsin(fVar6);
      fStack_7c = (float)(fVar6 * (float10)3.0);
      (*grim_interface_ptr->vtable->grim_set_rotation)(game_time_s + game_time_s);
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      (*grim_interface_ptr->vtable->grim_draw_quad)
                (((_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) -
                 fVar12) + fStack_80,
                 (fStack_7c + (&player_state_table)[render_overlay_player_index].pos_y +
                 _camera_offset_y) - fVar12,fVar12 + fVar12,fVar12 + fVar12);
      (*grim_interface_ptr->vtable->grim_set_color)(0.35686275,0.7058824,1.0,fVar14 * 0.3);
      fVar6 = (float10)fsin((float10)game_time_s * (float10)3.0);
      fVar12 = (float)(fVar6 * (float10)4.0 + (float10)24.0);
      (*grim_interface_ptr->vtable->grim_set_rotation)(game_time_s * -2.0);
      fVar14 = fVar12 + fVar12;
      (*grim_interface_ptr->vtable->grim_draw_quad)
                (((_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) -
                 fVar12) + fStack_80,
                 (fStack_7c + (&player_state_table)[render_overlay_player_index].pos_y +
                 _camera_offset_y) - fVar12,fVar14,fVar14);
      (*grim_interface_ptr->vtable->grim_end_batch)();
      fVar13 = 8.40779e-45;
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    }
    if (((&weapon_table)[(&player_state_table)[render_overlay_player_index].weapon_id].flags & 8) ==
        0) {
      fVar6 = (float10)(&player_state_table)[render_overlay_player_index].aim_heading +
              (float10)1.5707964;
      fcos(fVar6);
      fsin(fVar6);
      fVar14 = 6.113207e-39;
      (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7e0,0);
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,2);
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
      (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
      fVar12 = (&player_state_table)[render_overlay_player_index].muzzle_flash_alpha * 0.8;
      if (1.0 < fVar12) {
        fVar12 = 1.0;
      }
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar12 * 6.11324e-39);
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      (*grim_interface_ptr->vtable->grim_set_rotation)
                ((&player_state_table)[render_overlay_player_index].aim_heading);
      if (((&weapon_table)[(&player_state_table)[render_overlay_player_index].weapon_id].flags & 4)
          == 0) {
        fStack_7c = (&player_state_table)[render_overlay_player_index].size * 0.5;
        fVar12 = (&player_state_table)[render_overlay_player_index].size;
        fStack_80 = (_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) -
                    fStack_7c;
        fStack_7c = (_camera_offset_y + (&player_state_table)[render_overlay_player_index].pos_y) -
                    fStack_7c;
        pIVar4 = grim_interface_ptr->vtable;
      }
      else {
        fStack_7c = (&player_state_table)[render_overlay_player_index].size * 0.25;
        fStack_80 = (_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) -
                    fStack_7c;
        fStack_7c = (_camera_offset_y + (&player_state_table)[render_overlay_player_index].pos_y) -
                    fStack_7c;
        fVar12 = (&player_state_table)[render_overlay_player_index].size * 0.5;
        pIVar4 = grim_interface_ptr->vtable;
      }
      fStack_7c = fStack_7c + fStack_84;
      fStack_80 = fStack_80 + fVar13;
      render_scratch_f0 = fStack_80;
      render_scratch_f1 = fStack_7c;
      (*pIVar4->grim_draw_quad)(fStack_80,fStack_7c,fVar12,fVar12);
      (*grim_interface_ptr->vtable->grim_end_batch)();
    }
    iVar2 = perk_count_get(DAT_004c2bcc);
    if (iVar2 != 0) {
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
      pfVar9 = (float *)0x14;
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
      (*grim_interface_ptr->vtable->grim_bind_texture)(projectile_texture,0);
      (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,2);
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      iVar2 = 0;
      if (0 < (int)config_blob.reserved0._20_4_) {
        piVar5 = &player_state_table.auto_target;
        do {
          if ((0.25 < (float)piVar5[-0xa2]) &&
             (iVar3 = *piVar5, fVar12 = (&creature_pool)[iVar3].pos_x - (float)piVar5[-0xc3],
             fVar13 = (&creature_pool)[iVar3].pos_y - (float)piVar5[-0xc2],
             SQRT(fVar12 * fVar12 + fVar13 * fVar13) <= 80.0)) {
            fVar12 = (&creature_pool)[iVar3].pos_x - (float)piVar5[-0xc3];
            fVar13 = (&creature_pool)[iVar3].pos_y - (float)piVar5[-0xc2];
            pfVar9 = &fStack_80;
            fStack_80 = fVar12;
            fStack_7c = fVar13;
            thunk_FUN_00452f1d();
            fVar10 = (_camera_offset_x + (float)piVar5[-0xc3]) - 16.0;
            fVar11 = (_camera_offset_y + (float)piVar5[-0xc2]) - 16.0;
            (*grim_interface_ptr->vtable->grim_set_color)(0.5,0.6,1.0,6.113987e-39);
            fStack_a4 = 0.0;
            if (0.0 < fVar14) {
              do {
                (*grim_interface_ptr->vtable->grim_draw_quad)
                          (fVar12 * fStack_a4 + fVar10,fVar13 * fStack_a4 + fVar11,32.0,32.0);
                fStack_a4 = fStack_a4 + 8.0;
              } while (fStack_a4 < fVar14);
            }
          }
          iVar2 = iVar2 + 1;
          piVar5 = piVar5 + 0xd8;
        } while (iVar2 < (int)config_blob.reserved0._20_4_);
      }
      (*grim_interface_ptr->vtable->grim_end_batch)(pfVar9);
    }
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    return;
  }
  if (0.0 <= (&player_state_table)[render_overlay_player_index].death_timer) {
    lVar8 = __ftol();
    iVar2 = (int)lVar8;
  }
  else {
    iVar2 = 0x34;
  }
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  render_scratch_f0 = (&effect_uv8)[iVar2].u;
  render_scratch_f1 = (&effect_uv8)[iVar2].v;
  render_scratch_f2 = (&effect_uv8)[iVar2].u + 0.125;
  render_scratch_f3 = (&effect_uv8)[iVar2].v + 0.125;
  (*grim_interface_ptr->vtable->grim_set_uv)
            (render_scratch_f0,render_scratch_f1,render_scratch_f2,render_scratch_f3);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,2.138129e-39);
  (*grim_interface_ptr->vtable->grim_set_rotation)
            ((&player_state_table)[render_overlay_player_index].aim_heading);
  fVar14 = (&player_state_table)[render_overlay_player_index].size * 0.5;
  render_scratch_f0 =
       (_camera_offset_x + (&player_state_table)[render_overlay_player_index].pos_x) - fVar14;
  render_scratch_f1 =
       (_camera_offset_y + (&player_state_table)[render_overlay_player_index].pos_y) - fVar14;
  fVar14 = (&player_state_table)[render_overlay_player_index].size * 1.03;
  (*grim_interface_ptr->vtable->grim_draw_quad)
            (render_scratch_f0 + 1.0,render_scratch_f1 + 1.0,fVar14,fVar14);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  fStack_7c = 6.10966e-39;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  if (config_blob.reserved0._20_4_ == 1) {
    fVar13 = 1.0;
    pIVar4 = grim_interface_ptr->vtable;
    fVar12 = 1.0;
  }
  else {
    pIVar4 = grim_interface_ptr->vtable;
    if (render_overlay_player_index == 0) {
      fVar13 = 1.0;
      fVar12 = 0.3;
      fVar14 = 0.3;
      goto LAB_004287af;
    }
    fVar13 = 0.35;
    fVar12 = 0.55;
  }
  fVar14 = 1.0;
LAB_004287af:
  (*pIVar4->grim_set_color)(fVar14,fVar12,fVar13,fStack_7c);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)
            (render_scratch_f0,render_scratch_f1,
             (&player_state_table)[render_overlay_player_index].size,
             (&player_state_table)[render_overlay_player_index].size);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  return;
}



