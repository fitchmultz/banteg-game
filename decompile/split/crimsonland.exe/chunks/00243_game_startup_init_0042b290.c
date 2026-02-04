/* game_startup_init @ 0042b290 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* startup init: logs, builds perks/weapons, seeds UI/effects, loads registry time; triggers intro
   music then switches to crimson_theme */

void game_startup_init(void)

{
  int handle;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  IGrim2D_vtbl *pIVar4;
  float10 extraout_ST0;
  longlong lVar5;
  float fVar6;
  char *in_stack_ffffffd8;
  char *pcVar7;
  float fVar8;
  float fVar9;
  
  (*grim_interface_ptr->vtable->grim_get_frame_dt)();
  frame_dt = (float)extraout_ST0;
  if ((float10)0.1 < extraout_ST0) {
    frame_dt = 0.1;
  }
  if (DAT_00473a60 != '\0') {
    DAT_00473a60 = '\0';
  }
  if (DAT_004aaf9c == '\0') {
    load_textures_step();
  }
  if ((DAT_00473a60 == '\0') && (DAT_004aaf86 != '\0')) {
    texture_get_or_load(s_splashReflexive_00474714,s_load_splashReflexive_jpg_00474724);
    in_stack_ffffffd8 = s_splash10Tons_004746ec;
    texture_get_or_load(s_splash10Tons_004746ec,s_load_splash10tons_jaz_004746fc);
    game_startup_init_prelude();
    crt_beginthread(&LAB_0042b250,0,(void *)0x0);
    DAT_004aaf86 = '\0';
    DAT_004aaf9c = '\x01';
    if (0.5 < startup_splash_timer) {
      startup_splash_timer = 0.5;
    }
LAB_0042b35f:
    if ((DAT_004aaf8c != '\0') && (DAT_004aaf9d != '\0')) {
      if (DAT_004aaf98 < 5) {
        DAT_004aaf98 = DAT_004aaf98 + 1;
        Sleep(5);
        (*grim_interface_ptr->vtable->grim_clear_color)(0.0,0.0,0.0,1.0);
        audio_update();
        console_update(0x47eea0);
        console_render(&console_log_queue);
        if (*(float *)((int)cv_showFPS + 0xc) != 0.0) {
          (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.6);
          (*grim_interface_ptr->vtable->grim_get_fps)();
          lVar5 = __ftol();
          pIVar4 = grim_interface_ptr->vtable;
          if ((int)lVar5 < 400) {
            (*pIVar4->grim_get_fps)();
            __ftol();
            pcVar7 = &DAT_00471f40;
            iVar2 = config_blob.screen_width + -0x2d;
          }
          else {
            (*pIVar4->grim_get_fps)();
            __ftol();
            pcVar7 = &DAT_00472990;
            iVar2 = config_blob.screen_width + -0x33;
          }
          (*pIVar4->grim_draw_text_small_fmt)
                    (grim_interface_ptr,(float)iVar2,(float)(config_blob.screen_height + -0x18),
                     pcVar7);
        }
        iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x10);
        if (((char)iVar2 != '\0') &&
           (iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x38), (char)iVar2 != '\0')) {
          return;
        }
        return;
      }
      if (14.0 < startup_splash_timer) {
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x2d,(uint)in_stack_ffffffd8);
        pIVar4 = grim_interface_ptr->vtable;
        iVar2 = (*pIVar4->grim_get_texture_handle)(s_splashReflexive_00474714);
        (*pIVar4->grim_destroy_texture)(iVar2);
        pIVar4 = grim_interface_ptr->vtable;
        iVar2 = (*pIVar4->grim_get_texture_handle)(s_splash10Tons_004746ec);
        (*pIVar4->grim_destroy_texture)(iVar2);
        sfx_mute_all(music_track_intro_id);
        iVar2 = game_is_full_version();
        if ((char)iVar2 == '\0') {
          sfx_play_exclusive(music_track_crimsonquest_id);
          demo_mode_start();
        }
        else {
          sfx_play_exclusive(music_track_crimson_theme_id);
        }
        (*grim_interface_ptr->vtable->grim_clear_color)(0.0,0.0,0.0,1.0);
        return;
      }
      iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(1);
      if (((((char)iVar2 != '\0') ||
           (iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x39), (char)iVar2 != '\0')) ||
          (iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x1c), (char)iVar2 != '\0')) ||
         ((iVar2 = input_primary_just_pressed(), (char)iVar2 != '\0' ||
          (iVar2 = (*grim_interface_ptr->vtable->grim_was_mouse_button_pressed)(1),
          (char)iVar2 != '\0')))) {
        DAT_004aaf94 = '\x01';
        goto LAB_0042bd39;
      }
      if (DAT_004aaed9 != '\0') goto LAB_0042bd39;
      iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x29);
      if ((char)iVar2 != '\0') {
        console_set_open(&console_log_queue,console_open_flag == '\0');
      }
      game_time_s = game_time_s + frame_dt;
      _DAT_0047ea48 = frame_dt;
      (*grim_interface_ptr->vtable->grim_clear_color)(0.0,0.0,0.0,1.0);
      if (DAT_004aaf85 != '\0') {
        iVar2 = sfx_is_unmuted(music_track_intro_id);
        if ((char)iVar2 == '\0') {
          sfx_play_exclusive(music_track_intro_id);
        }
        startup_splash_timer = frame_dt * 1.1 + startup_splash_timer;
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
        startup_splash_timer = startup_splash_timer - 2.0;
        if (DAT_004aaf94 != '\0') {
          if ((startup_splash_timer < 1.0) ||
             ((5.0 <= startup_splash_timer &&
              ((startup_splash_timer < 7.0 || (11.0 <= startup_splash_timer)))))) {
            startup_splash_timer = 16.0;
          }
          else {
            startup_splash_timer = frame_dt * 4.0 + startup_splash_timer;
          }
        }
        uVar3 = 0x40;
        iVar2 = 0x40;
        (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
        (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
        if ((startup_splash_timer <= 1.0) || (5.0 <= startup_splash_timer)) {
          if (6.0 < startup_splash_timer) {
            handle = (*grim_interface_ptr->vtable->grim_get_texture_handle)
                               (s_splashReflexive_00474714);
            uVar3 = 0x100;
            iVar2 = 0x100;
            goto LAB_0042b800;
          }
        }
        else {
          uVar3 = 0x80;
          iVar2 = 0x80;
          handle = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_splash10Tons_004746ec);
LAB_0042b800:
          if (-1 < handle) {
            (*grim_interface_ptr->vtable->grim_bind_texture)(handle,0);
          }
        }
        (*grim_interface_ptr->vtable->grim_begin_batch)();
        if (startup_splash_timer <= 1.0) {
          if (2.0 <= startup_splash_timer) goto LAB_0042b8d9;
          if (4.0 <= startup_splash_timer) goto LAB_0042b97b;
LAB_0042ba4c:
          if (7.0 < startup_splash_timer) {
            if (8.0 <= startup_splash_timer) goto LAB_0042bb08;
            (*grim_interface_ptr->vtable->grim_set_color)
                      (1.0,1.0,1.0,(startup_splash_timer - 6.0) - 1.0);
            fVar9 = (float)iVar2;
            pIVar4 = grim_interface_ptr->vtable;
            fVar6 = (float)(int)(config_blob.screen_height / 2 - uVar3 / 2);
            fVar8 = (float)(config_blob.screen_width / 2 + -0x100);
            goto LAB_0042bc9a;
          }
          if (8.0 <= startup_splash_timer) {
LAB_0042bb08:
            if (10.0 <= startup_splash_timer) goto LAB_0042bbaa;
            (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
            fVar9 = (float)iVar2;
            pIVar4 = grim_interface_ptr->vtable;
            fVar6 = (float)(int)(config_blob.screen_height / 2 - uVar3 / 2);
            fVar8 = (float)(config_blob.screen_width / 2 + -0x100);
            goto LAB_0042bc9a;
          }
          if (10.0 <= startup_splash_timer) {
LAB_0042bbaa:
            if (startup_splash_timer < 11.0) {
              fVar9 = 1.0 - ((startup_splash_timer - 6.0) - 4.0);
              if (0.0 <= fVar9) {
                if (1.0 < fVar9) {
                  fVar9 = 1.0;
                }
              }
              else {
                fVar9 = 0.0;
              }
              (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar9);
              (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar9);
              fVar9 = (float)iVar2;
              pIVar4 = grim_interface_ptr->vtable;
              fVar6 = (float)(int)(config_blob.screen_height / 2 - uVar3 / 2);
              fVar8 = (float)(config_blob.screen_width / 2 + -0x100);
              goto LAB_0042bc9a;
            }
          }
        }
        else {
          if (2.0 <= startup_splash_timer) {
LAB_0042b8d9:
            if (4.0 <= startup_splash_timer) {
LAB_0042b97b:
              if (5.0 <= startup_splash_timer) goto LAB_0042ba4c;
              fVar9 = 1.0 - (startup_splash_timer - 4.0);
              if (0.0 <= fVar9) {
                if (1.0 < fVar9) {
                  fVar9 = 1.0;
                }
              }
              else {
                fVar9 = 0.0;
              }
              (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar9);
              fVar9 = (float)iVar2;
              pIVar4 = grim_interface_ptr->vtable;
              fVar6 = (float)(int)(config_blob.screen_height / 2 - uVar3 / 2);
              fVar8 = (float)(config_blob.screen_width / 2 + -0x100);
            }
            else {
              (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
              fVar9 = (float)iVar2;
              pIVar4 = grim_interface_ptr->vtable;
              fVar6 = (float)(int)(config_blob.screen_height / 2 - uVar3 / 2);
              fVar8 = (float)(config_blob.screen_width / 2 + -0x100);
            }
          }
          else {
            (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,startup_splash_timer - 1.0);
            fVar9 = (float)iVar2;
            pIVar4 = grim_interface_ptr->vtable;
            fVar6 = (float)(int)(config_blob.screen_height / 2 - uVar3 / 2);
            fVar8 = (float)(config_blob.screen_width / 2 + -0x100);
          }
LAB_0042bc9a:
          (*pIVar4->grim_draw_quad)(fVar8,fVar6,512.0,fVar9);
        }
        startup_splash_timer = startup_splash_timer + 2.0;
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
        (*grim_interface_ptr->vtable->grim_end_batch)();
        audio_update();
      }
      console_update(0x47eea0);
      console_render(&console_log_queue);
      iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x10);
      if (((char)iVar2 != '\0') &&
         (iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x38), (char)iVar2 != '\0')) {
        return;
      }
      if (DAT_0047ea50 != '\0') {
        return;
      }
LAB_0042bd39:
      if (*(float *)((int)cv_showFPS + 0xc) == 0.0) {
        return;
      }
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.6);
      (*grim_interface_ptr->vtable->grim_get_fps)();
      lVar5 = __ftol();
      pIVar4 = grim_interface_ptr->vtable;
      if ((int)lVar5 < 400) {
        (*pIVar4->grim_get_fps)();
        __ftol();
        pcVar7 = &DAT_00471f40;
        iVar2 = config_blob.screen_width + -0x2d;
      }
      else {
        (*pIVar4->grim_get_fps)();
        __ftol();
        pcVar7 = &DAT_00472990;
        iVar2 = config_blob.screen_width + -0x33;
      }
      (*pIVar4->grim_draw_text_small_fmt)
                (grim_interface_ptr,(float)iVar2,(float)(config_blob.screen_height + -0x18),pcVar7);
      return;
    }
    if ((DAT_004aaf9c != '\0') && (DAT_004aaf8c != '\0')) {
      startup_splash_timer = startup_splash_timer - frame_dt;
      if (startup_splash_timer < 0.0) {
        startup_splash_timer = 0.0;
        DAT_004aaf9d = '\x01';
        pIVar4 = grim_interface_ptr->vtable;
        iVar2 = (*pIVar4->grim_get_texture_handle)(s_loading_004746e4);
        (*pIVar4->grim_destroy_texture)(iVar2);
        pIVar4 = grim_interface_ptr->vtable;
        iVar2 = (*pIVar4->grim_get_texture_handle)(s_logo_esrb_004746d8);
        (*pIVar4->grim_destroy_texture)(iVar2);
      }
      goto LAB_0042bea6;
    }
  }
  else if (DAT_004aaf9c != '\0') goto LAB_0042b35f;
  startup_splash_timer = startup_splash_timer + frame_dt;
LAB_0042bea6:
  (*grim_interface_ptr->vtable->grim_clear_color)(0.0,0.0,0.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  fVar9 = startup_splash_timer + startup_splash_timer;
  if (fVar9 <= 1.0) {
    if (fVar9 < 0.0) {
      fVar9 = 0.0;
    }
  }
  else {
    fVar9 = 1.0;
  }
  fVar8 = fVar9;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar9);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  fVar6 = 0.0;
  pIVar4 = grim_interface_ptr->vtable;
  iVar2 = (*pIVar4->grim_get_texture_handle)(s_logo_esrb_004746d8);
  (*pIVar4->grim_bind_texture)(iVar2,(int)fVar6);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)
            ((screen_width_f - 256.0) - 1.0,(_DAT_00471144 - 128.0) - 1.0,256.0,128.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  fVar6 = 0.0;
  pIVar4 = grim_interface_ptr->vtable;
  iVar2 = (*pIVar4->grim_get_texture_handle)(s_loading_004746e4);
  (*pIVar4->grim_bind_texture)(iVar2,(int)fVar6);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)
            (screen_width_f * 0.5 + 128.0,_DAT_00471144 * 0.5 + 16.0,128.0,32.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  pIVar4 = grim_interface_ptr->vtable;
  fVar6 = 0.0;
  iVar2 = (*pIVar4->grim_get_texture_handle)(s_cl_logo_00471f70);
  (*pIVar4->grim_bind_texture)(iVar2,(int)fVar6);
  (*grim_interface_ptr->vtable->grim_draw_quad)
            (screen_width_f * 0.5 - 256.0,_DAT_00471144 * 0.5 - 32.0,512.0,64.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  fVar6 = 1.0;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar9);
  if (*(float *)((int)cv_silentloads + 0xc) == 0.0) {
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar8 * 0.7);
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,screen_width_f * 0.5 - 246.0,_DAT_00471144 * 0.5 + 32.0,
               s_Grim_GFX__d__d_004746c8,startup_texture_load_stage);
    fVar6 = DAT_004cc8d8;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,screen_width_f * 0.5 - 246.0,_DAT_00471144 * 0.5 + 45.0,
               s_Grim_SFX___d__d_004746b8);
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  DAT_00496604 = fVar6 * 0.7;
  (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004965f8);
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)
            ((float *)&stack0xffffffd0,screen_width_f + 8.0,128.0);
  console_update(0x47eea0);
  console_render(&console_log_queue);
  if (*(float *)((int)cv_showFPS + 0xc) != 0.0) {
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.6);
    (*grim_interface_ptr->vtable->grim_get_fps)();
    lVar5 = __ftol();
    pIVar4 = grim_interface_ptr->vtable;
    if ((int)lVar5 < 400) {
      (*pIVar4->grim_get_fps)();
      lVar5 = __ftol();
      uVar1 = (undefined4)lVar5;
      pcVar7 = &DAT_00471f40;
      iVar2 = config_blob.screen_width + -0x2d;
    }
    else {
      (*pIVar4->grim_get_fps)();
      lVar5 = __ftol();
      uVar1 = (undefined4)lVar5;
      pcVar7 = &DAT_00472990;
      iVar2 = config_blob.screen_width + -0x33;
    }
    (*pIVar4->grim_draw_text_small_fmt)
              (grim_interface_ptr,(float)iVar2,(float)(config_blob.screen_height + -0x18),pcVar7,
               uVar1);
  }
  Sleep(0x32);
  return;
}



