/* ui_render_hud @ 0041aed0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders the in-game HUD (health, weapon icons, player UI) */

void ui_render_hud(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  IGrim2D_vtbl *pIVar5;
  float unaff_EBX;
  int iVar6;
  char *pcVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  longlong lVar11;
  undefined1 *puVar12;
  float *rgba;
  uint value;
  char *pcVar13;
  float fVar14;
  float in_stack_ffffff8c;
  float fVar15;
  float fVar16;
  int iVar17;
  float a;
  float fVar18;
  int iVar19;
  float fVar20;
  float fVar21;
  float fStack_4c;
  float fStack_2c;
  float fStack_24;
  float fStack_10;
  
  fStack_4c = 6.032119e-39;
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  fVar20 = 2.94273e-44;
  fVar21 = 1.4013e-45;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_10 * 0.7);
  iVar19 = 0;
  pIVar5 = grim_interface_ptr->vtable;
  iVar2 = (*pIVar5->grim_get_texture_handle)(s_iGameUI_00473894);
  (*pIVar5->grim_bind_texture)(iVar2,iVar19);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.001953125,0.015625,0.9980469,0.984375);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  fVar18 = 512.0;
  a = 0.0;
  (*grim_interface_ptr->vtable->grim_draw_quad)(0.0,0.0,512.0,64.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  if (DAT_004871b0 != '\0') {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
    if (config_blob.reserved0._20_4_ == 1) {
      unaff_EBX = 21.0;
      fStack_2c = 21.0;
    }
    else {
      unaff_EBX = 12.0;
      fStack_2c = 12.0;
    }
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_24 * 0.8);
    iVar19 = 0;
    pIVar5 = grim_interface_ptr->vtable;
    iVar2 = (*pIVar5->grim_get_texture_handle)(s_iHeart_0047388c);
    (*pIVar5->grim_bind_texture)(iVar2,iVar19);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.03125,0.03125,0.96875,0.96875);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    fVar21 = 2.0;
    if (config_blob.reserved0._20_4_ == 1) {
      if (player_state_table.health < 30.0) {
        fVar21 = 5.0;
      }
      fsin((float10)game_time_s * (float10)fVar21);
      crt_ci_pow();
      fVar8 = extraout_ST0 * (float10)4.0 + (float10)14.0;
      pIVar5 = grim_interface_ptr->vtable;
      fVar9 = fVar8 + fVar8;
      fVar10 = (float10)fStack_2c - fVar8;
    }
    else {
      if (player_state_table.health < 30.0) {
        fVar21 = 5.0;
      }
      fsin((float10)game_time_s * (float10)fVar21);
      crt_ci_pow();
      fVar8 = (extraout_ST0_00 * (float10)4.0 + (float10)14.0) * (float10)0.5;
      (*grim_interface_ptr->vtable->grim_draw_quad)
                ((float)((float10)27.0 - fVar8),(float)((float10)fStack_2c - fVar8),
                 (float)(fVar8 + fVar8),(float)(fVar8 + fVar8));
      if (30.0 <= player2_health) {
        fVar8 = (float10)fVar21;
      }
      else {
        fVar8 = (float10)5.0;
      }
      fsin((float10)game_time_s * fVar8 + (float10)1.5707964);
      crt_ci_pow();
      pIVar5 = grim_interface_ptr->vtable;
      fVar8 = (extraout_ST0_01 * (float10)4.0 + (float10)14.0) * (float10)0.5;
      fVar9 = fVar8 + fVar8;
      fVar10 = ((float10)fStack_2c - fVar8) + (float10)15.0;
    }
    in_stack_ffffff8c = (float)fVar9;
    fVar20 = in_stack_ffffff8c;
    (*pIVar5->grim_draw_quad)
              ((float)((float10)27.0 - fVar8),(float)fVar10,in_stack_ffffff8c,in_stack_ffffff8c);
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  if (DAT_004871b1 != '\0') {
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_24 * 0.8);
    (*grim_interface_ptr->vtable->grim_bind_texture)(ui_weapon_icons_texture,0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    if (config_blob.reserved0._20_4_ == 1) {
      (*grim_interface_ptr->vtable->grim_set_sub_rect)
                (8,2,1,(&weapon_table)[player_state_table.weapon_id].hud_icon_id << 1);
      fVar16 = 32.0;
      fVar15 = 64.0;
      fVar14 = 2.0;
      pIVar5 = grim_interface_ptr->vtable;
    }
    else {
      (*grim_interface_ptr->vtable->grim_set_sub_rect)
                (8,2,1,(&weapon_table)[player_state_table.weapon_id].hud_icon_id << 1);
      (*grim_interface_ptr->vtable->grim_draw_quad)(220.0,4.0,32.0,16.0);
      (*grim_interface_ptr->vtable->grim_set_sub_rect)
                (8,2,1,(&weapon_table)[player2_weapon_id].hud_icon_id << 1);
      fVar16 = 16.0;
      fVar15 = 32.0;
      fVar14 = 20.0;
      pIVar5 = grim_interface_ptr->vtable;
    }
    (*pIVar5->grim_draw_quad)(220.0,fVar14,fVar15,fVar16);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    in_stack_ffffff8c = 1.0;
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  if (DAT_004871b0 != '\0') {
    (*grim_interface_ptr->vtable->grim_bind_texture)((int)DAT_0048f7c0,0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    if (config_blob.reserved0._20_4_ == 1) {
      fVar14 = 16.0;
    }
    else {
      fVar14 = 6.0;
    }
    render_overlay_player_index = 0;
    if (0 < (int)config_blob.reserved0._20_4_) {
      fVar18 = unaff_EBX * 0.5;
      do {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,unaff_EBX * 0.5);
        (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  (64.0,(float)(render_overlay_player_index << 4) + fVar14,120.0,9.0);
        fVar15 = (&player_state_table)[render_overlay_player_index].health * 0.01;
        if (fVar15 <= 1.0) {
          if (fVar15 < 0.0) {
            fVar15 = 0.0;
          }
        }
        else {
          fVar15 = 1.0;
        }
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,unaff_EBX * 0.8);
        (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,fVar15,1.0);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  (64.0,(float)(render_overlay_player_index << 4) + fVar14,fVar15 * 120.0,9.0);
        render_overlay_player_index = render_overlay_player_index + 1;
      } while (render_overlay_player_index < (int)config_blob.reserved0._20_4_);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  if (DAT_004871b1 != '\0') {
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    if (config_blob.reserved0._20_4_ == 1) {
      fStack_4c = 10.0;
      fVar14 = 10.0;
      fVar15 = 300.0;
    }
    else {
      fStack_4c = 4.0;
      fVar14 = 4.0;
      fVar15 = 290.0;
    }
    render_overlay_player_index = 0;
    if (0 < (int)config_blob.reserved0._20_4_) {
      do {
        iVar2 = (&weapon_ammo_class)
                [(&player_state_table)[render_overlay_player_index].weapon_id * 0x1f];
        if (iVar2 == 1) {
          pcVar13 = s_ui_ui_indFire_jaz_00473878;
          pIVar5 = grim_interface_ptr->vtable;
        }
        else if (iVar2 == 0) {
          pcVar13 = s_ui_ui_indBullet_jaz_00473864;
          pIVar5 = grim_interface_ptr->vtable;
        }
        else if (iVar2 == 2) {
          pcVar13 = s_ui_ui_indRocket_jaz_00473850;
          pIVar5 = grim_interface_ptr->vtable;
        }
        else {
          pcVar13 = s_ui_ui_indElectric_jaz_00473838;
          pIVar5 = grim_interface_ptr->vtable;
        }
        fVar16 = 0.0;
        iVar2 = (*pIVar5->grim_get_texture_handle)(pcVar13);
        (*pIVar5->grim_bind_texture)(iVar2,(int)fVar16);
        (*grim_interface_ptr->vtable->grim_begin_batch)();
        lVar11 = __ftol();
        iVar2 = (int)lVar11;
        if (0x1e < iVar2) {
          iVar2 = 0x14;
        }
        lVar11 = __ftol();
        iVar19 = (int)lVar11;
        (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
        iVar6 = 0;
        if (0 < iVar2) {
          iVar17 = 0;
          do {
            fVar16 = unaff_EBX;
            if (iVar19 <= iVar6) {
              fVar16 = unaff_EBX * 0.3;
            }
            (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar16);
            (*grim_interface_ptr->vtable->grim_draw_quad)
                      ((float)iVar17 + fVar15,(float)(render_overlay_player_index * 0xe) + fVar14,
                       6.0,16.0);
            iVar6 = iVar6 + 1;
            iVar17 = iVar17 + 6;
          } while (iVar6 < iVar2);
        }
        (*grim_interface_ptr->vtable->grim_end_batch)();
        if (iVar2 < iVar19) {
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,a);
          (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
          a = (float)(iVar6 * 6);
          (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                    (grim_interface_ptr,(float)(int)a + fVar20 + 8.0,
                     (float)(render_overlay_player_index * 0xe) + fVar21 + 1.0,&DAT_00473830,
                     iVar19 - iVar2);
        }
        render_overlay_player_index = render_overlay_player_index + 1;
      } while (render_overlay_player_index < (int)config_blob.reserved0._20_4_);
    }
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,a);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  puVar12 = (undefined1 *)0x41b94d;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  iVar2 = 0x4e;
  value = 0x4e;
  if (DAT_004871b3 != '\0') {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
    (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7c4,0);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,a);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    fVar18 = 0.0;
    if (quest_spawn_timeline < 1000) {
      fVar18 = (float)(1000 - quest_spawn_timeline) * -0.128;
    }
    (*grim_interface_ptr->vtable->grim_draw_quad)(fVar18 - 90.0,67.0,182.0,53.0);
    (*grim_interface_ptr->vtable->grim_draw_quad)(-80.0,107.0,182.0,53.0);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,in_stack_ffffff8c * 0.9);
    (*grim_interface_ptr->vtable->grim_bind_texture)(ui_clock_table_texture,0);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_draw_quad)(fVar18 + 2.0,78.0,32.0,32.0);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,in_stack_ffffff8c * 0.9);
    (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7cc,0);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_set_rotation)
              ((float)(quest_spawn_timeline / 1000) * 0.10471976);
    (*grim_interface_ptr->vtable->grim_draw_quad)(fVar18 + 2.0,78.0,32.0,32.0);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
    if ((quest_spawn_timeline / 1000) % 0x3c < 10) {
      pcVar13 = s__d_0_d_00473150;
    }
    else {
      pcVar13 = s__d__d_00473148;
    }
    in_stack_ffffff8c = (float)((quest_spawn_timeline / 1000) / 0x3c);
    fVar21 = fVar21 + 32.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)(grim_interface_ptr,fVar21,86.0,pcVar13);
    fVar14 = 3.36312e-44;
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3ee66666);
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,18.0,122.0,s_Progress_00473824);
    if ((DAT_0048f528 & 1) == 0) {
      DAT_0048f528 = DAT_0048f528 | 1;
      _DAT_004871a0 = 0x3e4ccccd;
      _DAT_004871a4 = 0x3f4ccccd;
      _DAT_004871a8 = 0x3e99999a;
      _DAT_004871ac = 1.0;
      crt_atexit(&DAT_0041ca80);
    }
    _DAT_004871ac = unaff_EBX * 0.8;
    iVar2 = 0;
    _DAT_004902fc = 0;
    if (0 < quest_spawn_count) {
      piVar3 = &quest_spawn_table.pos_y_block.heading_block.count;
      iVar19 = quest_spawn_count;
      do {
        iVar6 = *piVar3;
        piVar3 = piVar3 + 6;
        iVar2 = iVar2 + iVar6;
        iVar19 = iVar19 + -1;
      } while (iVar19 != 0);
    }
    DAT_004902f8 = (float)(int)highscore_active_record.creature_kill_count /
                   (float)(creature_spawned_count + iVar2);
    ui_draw_progress_bar((float *)&stack0xffffffbc,70.0,DAT_004902f8,(float *)&DAT_004871a0);
    iVar2 = 0x9e;
    if (DAT_00487244 < 500) {
      fVar15 = (float)(DAT_00487244 * 2) * 0.001;
LAB_0041bde3:
      if (1.0 < fVar15) {
LAB_0041bdf8:
        fVar15 = 1.0;
      }
    }
    else {
      if (DAT_00487244 < 0x5dc) goto LAB_0041bdf8;
      if (DAT_00487244 < 2000) {
        fVar15 = 1.0 - (float)(DAT_00487244 * 2 + -3000) * 0.001;
        goto LAB_0041bde3;
      }
      fVar15 = 0.0;
    }
    fVar18 = fVar15 * unaff_EBX;
    fVar16 = 1.0;
    value = 0x3f800000;
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar18);
    if (0.0 <= fVar15) {
      value = 0x3f4ccccd;
      iVar19 = -1;
      pcVar7 = (&quest_selected_meta)[_quest_stage_minor + -0xb + _quest_stage_major * 10].name;
      do {
        if (iVar19 == 0) break;
        iVar19 = iVar19 + -1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (config_blob.screen_width < 0x281) {
        value = 0x3f400000;
      }
      fVar15 = 3.36312e-44;
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,value);
      (*grim_interface_ptr->vtable->grim_draw_text_mono)
                ((float)(config_blob.screen_width / 2) - (float)(int)fVar20 * fVar14 * 8.0,
                 (float)(config_blob.screen_height / 2 + -0x20),
                 (&quest_selected_meta)[_quest_stage_minor + -0xb + _quest_stage_major * 10].name);
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,(uint)(fVar21 - 0.2));
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar16 * 0.5);
      if (10 < _quest_stage_minor) {
        _quest_stage_major = _quest_stage_major + 1;
        _quest_stage_minor = _quest_stage_minor + -10;
      }
      crt_sprintf(&DAT_0048f788,s__d__d_0047381c,_quest_stage_major,_quest_stage_minor);
      puVar12 = &DAT_0048f788;
      uVar4 = 0xffffffff;
      pcVar7 = &DAT_0048f788;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      (*grim_interface_ptr->vtable->grim_draw_text_mono_fmt)
                (grim_interface_ptr,
                 (((float)pcVar13 - (float)(~uVar4 - 1) * fVar15 * 8.0) - fVar15 * 32.0) - 4.0,
                 (fVar15 * 23.36 + (float)(config_blob.screen_height / 2 + -0x20)) - fVar15 * 16.0,
                 &DAT_0048f788);
    }
    if (0 < quest_transition_timer_ms) {
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f800000);
      fVar21 = (float)quest_transition_timer_ms * 0.0004 * 0.13 + 0.95;
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,(float)puVar12 * in_stack_ffffff8c);
      (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7a0,0);
      (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
      (*grim_interface_ptr->vtable->grim_draw_quad)
                ((float)(config_blob.screen_width / 2) - fVar21 * 128.0,
                 (float)(config_blob.screen_height / 2) - fVar21 * 16.0,fVar21 * 256.0,fVar21 * 32.0
                );
      (*grim_interface_ptr->vtable->grim_end_batch)();
    }
  }
  if (DAT_004871b4 != '\0') {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    fVar21 = in_stack_ffffff8c * 0.9;
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar21);
    (*grim_interface_ptr->vtable->grim_bind_texture)(ui_clock_table_texture,0);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_draw_quad)(220.0,2.0,32.0,32.0);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar21);
    (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7cc,0);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_set_rotation)
              ((float)((int)highscore_active_record.survival_elapsed_ms / 1000) * 0.10471976);
    (*grim_interface_ptr->vtable->grim_draw_quad)(220.0,2.0,32.0,32.0);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    value = 0x3f000000;
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,a);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,255.0,10.0,s__d_seconds_00473810,
               (int)highscore_active_record.survival_elapsed_ms / 1000);
  }
  if (DAT_004871b2 == '\0') goto LAB_0041c783;
  (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7c4,0);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,a);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)(-68.0,(float)(iVar2 + -0x12),182.0,53.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  if (player_state_table.experience == 0) {
    survival_xp_smoothed = player_state_table.experience;
  }
  else if (survival_xp_smoothed < player_state_table.experience) {
    iVar19 = frame_dt_ms / 2;
    if (iVar19 < 1) {
      iVar19 = 1;
    }
    uVar4 = survival_xp_smoothed - player_state_table.experience >> 0x1f;
    iVar6 = (survival_xp_smoothed - player_state_table.experience ^ uVar4) - uVar4;
    if (1000 < iVar6) {
      iVar19 = iVar19 * (iVar6 / 100);
    }
    survival_xp_smoothed = survival_xp_smoothed + iVar19;
    if (player_state_table.experience < survival_xp_smoothed) {
LAB_0041c5bf:
      survival_xp_smoothed = player_state_table.experience;
    }
  }
  else if (player_state_table.experience < survival_xp_smoothed) {
    iVar19 = frame_dt_ms / 2;
    if (iVar19 < 1) {
      iVar19 = 1;
    }
    uVar4 = survival_xp_smoothed - player_state_table.experience >> 0x1f;
    iVar6 = (survival_xp_smoothed - player_state_table.experience ^ uVar4) - uVar4;
    if (1000 < iVar6) {
      iVar19 = iVar19 * (iVar6 / 100);
    }
    survival_xp_smoothed = survival_xp_smoothed - iVar19;
    if (survival_xp_smoothed < player_state_table.experience) goto LAB_0041c5bf;
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_4c * 0.9);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,4.0,(float)(int)value,&DAT_0047380c);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,26.0,(float)(iVar2 + -4),&DAT_00471f40,survival_xp_smoothed);
  DAT_00496604 = fVar18;
  (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004965f8);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,85.0,(float)(iVar2 + 1),&DAT_00471f40,player_state_table.level);
  iVar19 = player_state_table.level;
  DAT_00496604 = 0.7;
  crt_ci_pow();
  lVar11 = __ftol();
  iVar6 = 1000 - (int)lVar11;
  if (iVar19 == 1) {
    iVar6 = 0;
  }
  in_stack_ffffff8c = (float)(iVar2 + 0xd);
  rgba = (float *)&stack0xffffff78;
  crt_ci_pow();
  lVar11 = __ftol();
  ui_draw_progress_bar
            ((float *)&stack0xffffff88,54.0,
             (float)(extraout_ST0_02 / (float10)((1000 - (int)lVar11) - iVar6)),rgba);
LAB_0041c783:
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  iVar2 = 0;
  do {
    bonus_hud_slot_update_and_render((float *)&stack0xffffff7c,iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  lVar11 = __ftol();
  iVar2 = (int)lVar11 + 1;
  render_overlay_player_index = 0;
  if (0 < (int)config_blob.reserved0._20_4_) {
    iVar19 = (int)lVar11 + -5;
    iVar6 = iVar2;
    iVar17 = iVar19;
    do {
      if (0.0 < (float)(&player_aux_timer)[render_overlay_player_index]) {
        fVar21 = (float)(&player_aux_timer)[render_overlay_player_index];
        if (1.0 <= fVar21) {
          fVar18 = 1.4;
        }
        else {
          fVar18 = 0.5;
        }
        (&player_aux_timer)[render_overlay_player_index] =
             (float)(&player_aux_timer)[render_overlay_player_index] - frame_dt * fVar18;
        if (1.0 < fVar21) {
          fVar21 = 2.0 - fVar21;
        }
        if (fVar21 < 0.0) {
          fVar21 = 0.0;
        }
        fVar21 = fVar21 * in_stack_ffffff8c;
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar21 * 0.8);
        (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7c4,0);
        (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
        (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
        (*grim_interface_ptr->vtable->grim_begin_batch)();
        (*grim_interface_ptr->vtable->grim_draw_quad)(-12.0,(float)(iVar19 + -0xc),182.0,53.0);
        (*grim_interface_ptr->vtable->grim_end_batch)();
        (*grim_interface_ptr->vtable->grim_bind_texture)(ui_weapon_icons_texture,0);
        (*grim_interface_ptr->vtable->grim_set_sub_rect)
                  (8,2,1,(&weapon_table)
                         [(&player_state_table)[render_overlay_player_index].weapon_id].hud_icon_id
                         << 1);
        (*grim_interface_ptr->vtable->grim_begin_batch)();
        (*grim_interface_ptr->vtable->grim_draw_quad)(105.0,(float)iVar17,60.0,30.0);
        (*grim_interface_ptr->vtable->grim_end_batch)();
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar21);
        (*grim_interface_ptr->vtable->grim_draw_text_small)
                  (8.0,(float)iVar6,
                   (&weapon_table)[(&player_state_table)[render_overlay_player_index].weapon_id].
                   name);
        iVar2 = iVar2 + 0x20;
        iVar19 = iVar19 + 0x20;
        iVar6 = iVar2;
        iVar17 = iVar19;
      }
      render_overlay_player_index = render_overlay_player_index + 1;
    } while (render_overlay_player_index < (int)config_blob.reserved0._20_4_);
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  render_overlay_player_index = 0;
  return;
}



