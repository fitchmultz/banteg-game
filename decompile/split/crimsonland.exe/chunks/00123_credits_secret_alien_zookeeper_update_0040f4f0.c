/* credits_secret_alien_zookeeper_update @ 0040f4f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* updates and renders the AlienZooKeeper credits secret; drives match-3 board state and UI */

void credits_secret_alien_zookeeper_update(void)

{
  IGrim2D_vtbl *pIVar1;
  uint uVar2;
  float unaff_EBX;
  int iVar3;
  int *piVar4;
  int *piVar5;
  float10 fVar6;
  float g;
  float b;
  uchar uVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fStack_54;
  float fStack_44;
  float fStack_40;
  
  fVar15 = 1.0;
  fVar14 = 1.0;
  fVar13 = 1.0;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  fVar12 = 0.8;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f4ccccd);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,fStack_44,fStack_40 - 14.0,s_AlienZooKeeper_00473128);
  fVar10 = 0.45;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3ee66666);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,unaff_EBX + 12.0,fStack_54 + 10.0,
             s_a_puzzle_game_unfinished_0047310c);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,unaff_EBX + 18.0,fStack_54 + 23.0,s___or_something_more__004730f4);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.8);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3ed70a3d);
  credits_secret_anim_time_ms = credits_secret_anim_time_ms + frame_dt_ms;
  if (0 < credits_secret_timer_ms) {
    credits_secret_timer_ms = credits_secret_timer_ms - frame_dt_ms;
    if (0 < credits_secret_timer_ms) goto LAB_0040f6cc;
    sfx_play(sfx_trooper_die_01);
  }
  if (credits_secret_timer_ms < 0) {
    credits_secret_timer_ms = 0;
  }
LAB_0040f6cc:
  fVar15 = fVar15 + 40.0;
  fVar14 = fVar14 + 22.0;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.7);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,fVar14 + 124.0,fVar15 - 16.0,s_score___d_004730e8,
             credits_secret_score);
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)((float *)&stack0xffffff94,192.0,192.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)((float *)&stack0xffffff90,192.0,192.0);
  iVar11 = credits_secret_timer_ms / 100;
  if (0xc0 < iVar11) {
    iVar11 = 0xc0;
  }
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)((float *)&stack0xffffff80,(float)iVar11,6.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)((float *)&stack0xffffff84,192.0,6.0);
  iVar11 = 0;
  iVar3 = 0;
  do {
    iVar8 = 0;
    do {
      if (credits_secret_selected_index == iVar3) {
        fVar10 = (float)iVar11 * 32.0 + fVar13;
        (*grim_interface_ptr->vtable->grim_draw_rect_filled)((float *)&stack0xffffff84,24.0,24.0);
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
        (*grim_interface_ptr->vtable->grim_draw_rect_outline)((float *)&stack0xffffff80,24.0,24.0);
      }
      iVar8 = iVar8 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar8 < 6);
    iVar11 = iVar11 + 1;
  } while (iVar3 < 0x24);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_004827b0,0);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  fVar15 = 0.0;
  fVar14 = 0.0;
  piVar4 = &credits_secret_board;
  do {
    iVar3 = 0;
    iVar11 = 0;
    do {
      if (*piVar4 != -3) {
        uVar2 = credits_secret_anim_time_ms / 0x32 + *piVar4 * 2 & 0x8000001f;
        if ((int)uVar2 < 0) {
          uVar2 = (uVar2 - 1 | 0xffffffe0) + 1;
        }
        iVar9 = iVar11;
        (*grim_interface_ptr->vtable->grim_set_atlas_frame)(8,uVar2);
        iVar8 = *piVar4;
        if (iVar8 == 0) {
          b = 0.5;
          g = 0.5;
          pIVar1 = grim_interface_ptr->vtable;
LAB_0040fae2:
          (*pIVar1->grim_set_color)(1.0,g,b,1.0);
        }
        else if (iVar8 == 1) {
          (*grim_interface_ptr->vtable->grim_set_color)(0.5,0.5,1.0,1.0);
        }
        else {
          if (iVar8 == 2) {
            b = 1.0;
            g = 0.5;
            pIVar1 = grim_interface_ptr->vtable;
            goto LAB_0040fae2;
          }
          if (iVar8 == 3) {
            (*grim_interface_ptr->vtable->grim_set_color)(0.5,1.0,1.0,1.0);
          }
          else if (iVar8 == 4) {
            b = 0.5;
            g = 1.0;
            pIVar1 = grim_interface_ptr->vtable;
            goto LAB_0040fae2;
          }
        }
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((float)iVar9 + fVar12,(float)(int)fVar15 + fVar13,32.0,32.0);
        if (((0 < credits_secret_timer_ms) &&
            (iVar8 = ui_mouse_inside_rect((float *)&stack0xffffff9c,0x20,0x20), (char)iVar8 != '\0')
            ) && (iVar8 = input_primary_just_pressed(), (char)iVar8 != '\0')) {
          sfx_play(sfx_ui_clink_01);
          if (credits_secret_selected_index == -1) {
            credits_secret_selected_index = (int)fVar14 + iVar3;
          }
          else {
            iVar8 = *piVar4;
            *piVar4 = (&credits_secret_board)[credits_secret_selected_index];
            (&credits_secret_board)[credits_secret_selected_index] = iVar8;
            credits_secret_selected_index = -1;
            iVar8 = 0;
            uVar7 = '\0';
            uVar2 = credits_secret_match3_find
                              (&credits_secret_board,(int *)&stack0xffffff74,&stack0xffffff6b);
            if ((char)uVar2 != '\0') {
              (&credits_secret_board)[iVar8] = 0xfffffffd;
              if (uVar7 == '\0') {
                *(undefined4 *)(&credits_secret_match_mask_v0 + iVar8 * 4) = 0xfffffffd;
                *(undefined4 *)(&credits_secret_match_mask_v1 + iVar8 * 4) = 0xfffffffd;
              }
              else {
                (&credits_secret_match_mask_h0)[iVar8] = 0xfffffffd;
                (&credits_secret_match_mask_h1)[iVar8] = 0xfffffffd;
              }
              credits_secret_score = credits_secret_score + 1;
              sfx_play(sfx_ui_bonus);
              credits_secret_timer_ms = credits_secret_timer_ms + 2000;
            }
          }
        }
      }
      iVar11 = iVar11 + 0x20;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar11 < 0xc0);
    fVar14 = (float)((int)fVar14 + 6);
    fVar15 = (float)((int)fVar15 + 0x20);
    if (0x481a7b < (int)piVar4) {
      (*grim_interface_ptr->vtable->grim_end_batch)();
      if (credits_secret_timer_ms == 0) {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f800000);
        fVar6 = (float10)fcos((float10)credits_secret_anim_time_ms * (float10)0.005);
        if ((float10)0.0 < fVar6) {
          (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                    (grim_interface_ptr,fVar10 + 38.0,(fVar14 + 96.0) - 22.0,s_Game_Over_004730dc);
        }
      }
      piVar4 = &credits_secret_board;
      do {
        iVar11 = 6;
        do {
          if (*piVar4 == -1) {
            iVar3 = crt_rand();
            *piVar4 = iVar3 % 5;
          }
          piVar4 = piVar4 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      } while ((int)piVar4 < 0x481a7c);
      if ((credits_secret_flags & 1) == 0) {
        credits_secret_flags = credits_secret_flags | 1;
        DAT_004819d6 = 1;
        DAT_004819e5 = 0;
        DAT_004819e4 = 0;
        _DAT_004819e0 = 0x3f800000;
        _DAT_004819dc = 0;
        _credits_secret_reset_button = (char *)0x0;
        DAT_004819d4 = 0;
        DAT_004819d5 = 0;
        _DAT_004819d8 = 0;
        crt_atexit(&DAT_0040ff40);
      }
      _credits_secret_reset_button = s_Reset_004730d4;
      iVar11 = ui_button_update((float *)&stack0xffffff9c,
                                (ui_button_t *)&credits_secret_reset_button);
      if ((char)iVar11 != '\0') {
        do {
          piVar4 = &credits_secret_board;
          do {
            iVar11 = 6;
            piVar5 = piVar4;
            do {
              iVar3 = crt_rand();
              piVar4 = piVar5 + 1;
              iVar11 = iVar11 + -1;
              *piVar5 = iVar3 % 5;
              piVar5 = piVar4;
            } while (iVar11 != 0);
          } while ((int)piVar4 < 0x481a7c);
          uVar2 = credits_secret_match3_find
                            (&credits_secret_board,(int *)&stack0xffffff84,&stack0xffffff6b);
        } while ((char)uVar2 != '\0');
        credits_secret_selected_index = -1;
        credits_secret_score = 0;
        credits_secret_timer_ms = 0x2580;
      }
      if ((credits_secret_flags & 2) == 0) {
        credits_secret_flags = credits_secret_flags | 2;
        DAT_00481bc6 = 1;
        DAT_00481bd5 = 0;
        DAT_00481bd4 = 0;
        _DAT_00481bd0 = 0x3f800000;
        _DAT_00481bcc = 0;
        _credits_secret_back_button = (undefined *)0x0;
        DAT_00481bc4 = 0;
        DAT_00481bc5 = 0;
        _DAT_00481bc8 = 0;
        crt_atexit(&DAT_0040ff30);
      }
      _credits_secret_back_button = &DAT_00472e80;
      iVar11 = ui_button_update((float *)&stack0xffffff9c,(ui_button_t *)&credits_secret_back_button
                               );
      if ((char)iVar11 != '\0') {
        ui_transition_direction = 0;
        game_state_pending = 4;
      }
      return;
    }
  } while( true );
}



