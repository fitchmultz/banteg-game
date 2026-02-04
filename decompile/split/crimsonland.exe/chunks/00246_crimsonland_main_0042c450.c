/* crimsonland_main @ 0042c450 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* primary game init/run/shutdown sequence */

int crimsonland_main(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  HRESULT HVar4;
  IDirect3D8 *This;
  char *pcVar5;
  uchar *puVar6;
  float *pfVar7;
  int *piVar8;
  void *pvVar9;
  int *piVar10;
  LONG LVar11;
  uint uVar12;
  int *piVar13;
  char *filename;
  char *filename_00;
  char *filename_01;
  char *extraout_EDX;
  char *extraout_EDX_00;
  char *filename_02;
  char *filename_03;
  char *filename_04;
  char *filename_05;
  char *extraout_EDX_01;
  char *extraout_EDX_02;
  char *extraout_EDX_03;
  char *extraout_EDX_04;
  char *filename_06;
  char *filename_07;
  char *extraout_EDX_05;
  char *extraout_EDX_06;
  char *extraout_EDX_07;
  undefined4 *puVar14;
  LPCCH pCVar15;
  HKEY key;
  undefined4 uVar16;
  uint in_stack_fffffad0;
  undefined4 uStack_52c;
  undefined4 in_stack_fffffb20;
  char *lpCaption;
  UINT uType;
  undefined4 in_stack_fffffb34;
  undefined4 in_stack_fffffb48;
  uint in_stack_fffffb70;
  undefined4 in_stack_fffffb84;
  uint in_stack_fffffb98;
  uint in_stack_fffffbac;
  uint local_420;
  uint auStack_41c [4];
  char local_40c [12];
  WCHAR local_400 [512];
  
  uVar2 = FUN_004623b2((int *)0x0);
  crt_srand(uVar2);
  local_420 = 0;
  iVar3 = dx_get_version((int *)&local_420,local_40c,10);
  if (iVar3 < 0) {
    iVar3 = MessageBoxA((HWND)0x0,s_Unknown_DirectX_version_detected_00474d74,s_Crimsonland_00472d5c
                        ,4);
    if (iVar3 == 7) {
      return 0;
    }
  }
  else if (local_420 < 0x80100) {
    iVar3 = MessageBoxA((HWND)0x0,s_DirectX8_1_or_newer_not_detected_00474e60,s_Crimsonland_00472d5c
                        ,0x23);
    if (iVar3 != 6) {
      return 0;
    }
    MultiByteToWideChar(0,0,s_http___www_microsoft_com_windows_00474e28,-1,local_400,0x104);
    HVar4 = HlinkNavigateString((IUnknown *)0x0,local_400);
    if (-1 < HVar4) {
      return 0;
    }
    MessageBoxA((HWND)0x0,s_Failed_to_launch_web_browser__00474e08,s_Crimsonland_00472d5c,0);
    return 0;
  }
  crt_getcwd(&game_base_path,0x103);
  GetCommandLineA();
  DAT_00473a64 = 0x7b;
  This = Direct3DCreate8(0xdc);
  console_printf(&console_log_queue,s_Crimsonland_00474d64);
  console_printf(&console_log_queue,s_____________00474d54);
  console_printf(&console_log_queue,&DAT_004711c0);
  console_flush_log(&console_log_queue,filename);
  if (This == (IDirect3D8 *)0x0) {
    MessageBoxA((HWND)0x0,s_DirectX8_1_not_detected__Crimson_00474cb8,s_Crimsonland_00472d5c,0);
    return 0;
  }
  (*This->lpVtbl->Release)(This);
  console_printf(&console_log_queue,s_Game_base_path____s__00474ca0);
  console_flush_log(&console_log_queue,filename_00);
  config_ensure_file();
  console_register_command(&console_log_queue,s_setGammaRamp_00474c90,console_cmd_set_gamma_ramp);
  console_register_command
            (&console_log_queue,s_snd_addGameTune_00474c80,console_cmd_snd_add_game_tune);
  console_register_command
            (&console_log_queue,s_generateterrain_00474c70,console_cmd_generate_terrain);
  console_register_command
            (&console_log_queue,s_telltimesurvived_00474c5c,console_cmd_tell_time_survived);
  console_register_command
            (&console_log_queue,s_setresourcepaq_00474c4c,console_cmd_set_resource_paq);
  console_register_command(&console_log_queue,s_loadtexture_00474c40,console_cmd_load_texture);
  console_register_command(&console_log_queue,s_openurl_00474c38,console_cmd_open_url);
  console_register_command
            (&console_log_queue,s_sndfreqadjustment_00474c24,console_cmd_snd_freq_adjustment);
  puVar14 = &DAT_004852d0;
  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  *(undefined2 *)puVar14 = 0;
  *(undefined1 *)((int)puVar14 + 2) = 0;
  DAT_004852d0._0_1_ = 0x53;
  DAT_004852d0._1_1_ = 0x6f;
  DAT_004852d0._2_1_ = 0x66;
  DAT_004852d0._3_1_ = 0x74;
  DAT_004852d4._0_1_ = 0x77;
  DAT_004852d4._1_1_ = 0x61;
  DAT_004852d6 = 0x72;
  DAT_004852d7 = 0x65;
  DAT_004852d8 = 0x5c;
  DAT_004852d9 = 0x53;
  DAT_004852da = 0x6f;
  DAT_004852db = 99;
  DAT_004852dc = 0x6b;
  grim_interface_ptr = (IGrim2D *)grim_load_interface(s____grim_grSystem_c_Release_grim__00474c00);
  console_printf(&console_log_queue,s________________________004740fc);
  console_printf(&console_log_queue,s_______Grim2D_API_______00474be8);
  console_printf(&console_log_queue,s________________________004740fc);
  console_printf(&console_log_queue,s_Initiating_Grim_00474bd4);
  console_flush_log(&console_log_queue,filename_01);
  DAT_004852e1 = 0x75;
  DAT_004852eb = 0x75;
  DAT_004852dd = 0x65;
  DAT_004852de = 0x74;
  DAT_004852df = 0x50;
  DAT_004852e0 = 0x6c;
  DAT_004852e2 = 0x67;
  DAT_004852e3 = 0x69;
  DAT_004852e4 = 0x6e;
  DAT_004852e5 = 0x73;
  DAT_004852e6 = 0x5c;
  DAT_004852e7 = 0x44;
  DAT_004852e8 = 0x65;
  DAT_004852e9 = 0x66;
  DAT_004852ea = 0x61;
  DAT_004852ec = 0x6c;
  DAT_004852ed = 0x74;
  DAT_004852ee = 0x5c;
  pcVar5 = extraout_EDX;
  if (grim_interface_ptr == (IGrim2D *)0x0) {
    console_printf(&console_log_queue,s____DEV_dll_not_found__trying_to_f_00474ba4);
    grim_interface_ptr = (IGrim2D *)grim_load_interface(s_grim_dll_00474b98);
    pcVar5 = extraout_EDX_00;
  }
  console_flush_log(&console_log_queue,pcVar5);
  if (grim_interface_ptr == grim_interface_ptr + 1) {
    console_printf(&console_log_queue,PTR_DAT_00473a14);
    console_printf(&console_log_queue,PTR_secret_hint_secret_weapons_00473a18);
    console_printf(&console_log_queue,PTR_secret_hint_redistr_build_00473a10);
    console_printf(&console_log_queue,PTR_secret_hint_not_meant_to_see_00473a1c);
    console_printf(&console_log_queue,PTR_secret_hint_alienzookeeper_00473a20);
    console_printf(&console_log_queue,PTR_secret_hint_secret_path_00473a24);
    console_printf(&console_log_queue,PTR_secret_hint_magic_paint_00473a28);
    console_printf(&console_log_queue,PTR_secret_hint_haxx0r_00473a34);
    console_printf(&console_log_queue,PTR_DAT_00473a2c);
  }
  if (grim_interface_ptr == (IGrim2D *)0x0) {
    MessageBoxA((HWND)0x0,s_Grim_dll_is_corrupted_or_missing_00474b10,&DAT_00474b90,0);
    return 0;
  }
  console_printf(&console_log_queue,s____interface_created_00474af8);
  console_printf(&console_log_queue,s____registering_core_variables_00474ad8);
  register_core_cvars();
  if (DAT_00473a64 != 0x7b) {
    grim_interface_ptr = (IGrim2D *)0x0;
  }
  console_flush_log(&console_log_queue,filename_02);
  console_printf(&console_log_queue,s____loading_config_pre_sets_00474abc);
  uVar2 = 0x42c954;
  config_load_presets();
  game_load_status();
  game_sequence_load();
  console_flush_log(&console_log_queue,filename_03);
  console_printf(&console_log_queue,s____invoking_grim_config_00474aa0);
  console_flush_log(&console_log_queue,filename_04);
  iVar3 = (*grim_interface_ptr->vtable->grim_apply_config)();
  grim_config_invoked = 1;
  if ((char)iVar3 == '\0') {
    config_sync_from_grim();
    grim_config_invoked = 0;
    (*grim_interface_ptr->vtable->grim_release)();
    return 0;
  }
  config_sync_from_grim();
  grim_config_invoked = 0;
  config_load_presets();
  console_printf(&console_log_queue,s____setting_system_states_00474a84);
  console_flush_log(&console_log_queue,filename_05);
  pcVar5 = (char *)(*grim_interface_ptr->vtable->grim_get_config_var)(auStack_41c,0x54);
  terrain_texture_failed = *pcVar5;
  puVar6 = (uchar *)(*grim_interface_ptr->vtable->grim_get_config_var)(auStack_41c,0x53);
  DAT_004aaeea = *puVar6;
  pfVar7 = (float *)(*grim_interface_ptr->vtable->grim_get_config_var)(auStack_41c,0x59);
  config_blob.reserved0._112_4_ = *pfVar7;
  if (((((float)config_blob.reserved0._112_4_ != 0.5) &&
       ((float)config_blob.reserved0._112_4_ != 1.0)) &&
      ((float)config_blob.reserved0._112_4_ != 2.0)) &&
     ((float)config_blob.reserved0._112_4_ != 4.0)) {
    config_blob.reserved0[0x70] = '\0';
    config_blob.reserved0[0x71] = '\0';
    config_blob.reserved0[0x72] = 0x80;
    config_blob.reserved0[0x73] = '?';
  }
  config_blob.reserved0[0] = DAT_004aaeea;
  pcVar5 = (char *)(*grim_interface_ptr->vtable->grim_get_config_var)(auStack_41c,8);
  config_blob.windowed._0_1_ = *pcVar5;
  if (terrain_texture_failed == '\0') {
    pcVar5 = s____using_PRIMARY_backend_00474a44;
  }
  else {
    pcVar5 = s____using_SAFEMODE_fallback_backe_00474a60;
  }
  console_printf(&console_log_queue,pcVar5);
  pcVar5 = extraout_EDX_01;
  if (grim_interface_ptr == (IGrim2D *)0x0) {
    console_printf(&console_log_queue,s____using_DEVELOPER_backend_00474a28);
    pcVar5 = extraout_EDX_02;
  }
  console_flush_log(&console_log_queue,pcVar5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x2d,uVar2);
  (*grim_interface_ptr->vtable->grim_set_config_var)(5,in_stack_fffffbac);
  (*grim_interface_ptr->vtable->grim_set_config_var)(6,in_stack_fffffb98);
  (*grim_interface_ptr->vtable->grim_set_config_var)
            (0x42,CONCAT31((int3)((uint)in_stack_fffffb84 >> 8),1));
  console_printf(&console_log_queue,s____setting_system_states_00474a84);
  (*grim_interface_ptr->vtable->grim_set_config_var)(7,in_stack_fffffb70);
  piVar8 = (int *)(*grim_interface_ptr->vtable->grim_get_config_var)((uint *)&stack0xfffffb80,0x29);
  config_blob.screen_width = *piVar8;
  piVar8 = (int *)(*grim_interface_ptr->vtable->grim_get_config_var)((uint *)&stack0xfffffb80,0x2a);
  config_blob.screen_height = *piVar8;
  if ((char)config_blob.windowed == '\0') {
    pcVar5 = s____selected_fullscreen_mode__dx__004749d0;
    console_printf(&console_log_queue,s____selected_fullscreen_mode__dx__004749d0);
  }
  else {
    pcVar5 = (char *)&console_log_queue;
    console_printf(&console_log_queue,s____selected_windowed_mode__windo_004749f8);
  }
  DAT_004aaeda = config_blob.reserved0[1];
  (*grim_interface_ptr->vtable->grim_set_config_var)(0xb,CONCAT31((int3)((uint)pcVar5 >> 8),1));
  console_printf(&console_log_queue,s____using_keyboard_004749bc);
  (*grim_interface_ptr->vtable->grim_set_config_var)
            (0xc,CONCAT31((int3)((uint)in_stack_fffffb48 >> 8),1));
  console_printf(&console_log_queue,s____using_mouse_004749ac);
  (*grim_interface_ptr->vtable->grim_set_config_var)
            (0xe,CONCAT31((int3)((uint)in_stack_fffffb34 >> 8),1));
  console_printf(&console_log_queue,s____using_joystick_00474998);
  console_printf(&console_log_queue,s____initiating_Grim_system_0047497c);
  iVar3 = (*grim_interface_ptr->vtable->grim_init_system)();
  if ((char)iVar3 == '\0') {
    console_printf(&console_log_queue,s_Critical_failure__00474968);
    uType = 0;
    lpCaption = s_Crimsonland__00474958;
    pcVar5 = (*grim_interface_ptr->vtable->grim_get_error_text)();
    MessageBoxA((HWND)0x0,pcVar5,lpCaption,uType);
    (*grim_interface_ptr->vtable->grim_release)();
    return 0;
  }
  console_exec_line(&console_log_queue,s_exec_autoexec_txt_00474944);
  (*grim_interface_ptr->vtable->grim_set_config_var)
            (0x12,CONCAT31((int3)((uint)in_stack_fffffb20 >> 8),1));
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f800000);
  screen_width_f = (float)config_blob.screen_width;
  _DAT_00471144 = (float)config_blob.screen_height;
  uStack_52c = 0x42cd8d;
  pvVar9 = console_register_cvar(&console_log_queue,s_v_width_00474938,&DAT_00474940);
  *(float *)((int)pvVar9 + 0xc) = (float)config_blob.screen_width;
  uStack_52c = 0x42cdaa;
  pvVar9 = console_register_cvar(&console_log_queue,s_v_height_00474928,&DAT_00474934);
  *(float *)((int)pvVar9 + 0xc) = (float)config_blob.screen_height;
  init_audio_and_terrain();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x10,in_stack_fffffad0);
  console_printf(&console_log_queue,s_Set_resource_paq_to__crimson_paq_004748f8);
  texture_get_or_load(s_backplasma_0047296c,s_load_backplasma_jaz_004748e4);
  texture_get_or_load(s_mockup_00472964,s_load_mockup_jaz_004748d4);
  texture_get_or_load(s_logo_esrb_004746d8,s_load_esrb_mature_jaz_004748bc);
  texture_get_or_load(s_loading_004746e4,s_load_loading_jaz_004748a8);
  texture_get_or_load(s_cl_logo_00471f70,s_load_logo_crimsonland_tga_0047488c);
  uVar16 = 0;
  (*grim_interface_ptr->vtable->grim_clear_color)(0.0,0.0,0.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x36,CONCAT31((int3)((uint)uVar16 >> 8),1));
  key = (HKEY)0x0;
  uVar16 = 0;
  (*grim_interface_ptr->vtable->grim_clear_color)(0.0,0.0,0.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x36,CONCAT31((int3)((uint)uVar16 >> 8),1));
  (*grim_interface_ptr->vtable->grim_clear_color)(0.0,0.0,0.0,1.0);
  uVar2 = DAT_00473a30;
  _key_char_count = 0;
  puVar14 = &key_char_buffer;
  for (uVar12 = DAT_00473a30 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  for (uVar12 = uVar2 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar14 = 0;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
  }
  (*grim_interface_ptr->vtable->grim_set_key_char_buffer)
            ((uchar *)&key_char_buffer,(int *)&key_char_count,uVar2);
  config_sync_from_grim();
  piVar13 = &player_state_table.input.move_key_backward;
  piVar8 = config_blob.keybinds_p1 + 0xc;
  do {
    piVar10 = piVar8 + 0x10;
    ((player_input_t *)(piVar13 + -1))->move_key_forward = piVar8[-0xc];
    *piVar13 = piVar8[-0xb];
    piVar13[1] = piVar8[-10];
    piVar13[2] = piVar8[-9];
    piVar13[3] = piVar8[-8];
    piVar13[4] = piVar8[-7];
    piVar13[5] = piVar8[-6];
    piVar13[6] = piVar8[-5];
    piVar13[7] = piVar8[-4];
    piVar13[9] = piVar8[-3];
    piVar13[8] = piVar8[-2];
    piVar13[0xb] = piVar8[-1];
    piVar13[10] = *piVar8;
    piVar13 = piVar13 + 0xd8;
    piVar8 = piVar10;
  } while ((int)piVar10 < 0x4805c0);
  (*grim_interface_ptr->vtable->grim_apply_settings)();
  LVar11 = RegCreateKeyExA((HKEY)0x80000001,s_Software_10tons_entertainment_Cr_00474604,0,(LPSTR)0x0
                           ,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,(PHKEY)&stack0xfffffab0,
                           (LPDWORD)0x0);
  if (LVar11 == 0) {
    reg_write_dword((HKEY)key,s_timePlayed_004745f8,DAT_0048718c);
    RegCloseKey(key);
  }
  else {
    console_printf(&console_log_queue,s_Kameli_was_NOT_hairy__00474874);
  }
  game_save_status();
  console_printf(&console_log_queue,s_Leaving_Crimsonland___0047485c);
  pcVar5 = extraout_EDX_03;
  if (DAT_004aaee4 != (void *)0x0) {
    crt_free(DAT_004aaee4);
    pcVar5 = extraout_EDX_04;
  }
  console_flush_log(&console_log_queue,pcVar5);
  audio_shutdown_all();
  console_printf(&console_log_queue,s_Shutdown_Grim___00474848);
  (*grim_interface_ptr->vtable->grim_shutdown)();
  console_flush_log(&console_log_queue,filename_06);
  (*grim_interface_ptr->vtable->grim_release)();
  console_printf(&console_log_queue,s_Waving_the_Grim_Reaper_goodbye___00474824);
  console_flush_log(&console_log_queue,filename_07);
  pcVar5 = extraout_EDX_05;
  if (((DAT_004d11f0 == 0) && (DAT_004d11f8 != '\0')) && (DAT_004d11f4 != (LPCCH)0x0)) {
    Sleep(200);
    uStack_52c = uStack_52c & 0xffff0000;
    puVar14 = (undefined4 *)((int)&uStack_52c + 2);
    for (iVar3 = 0xff; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    *(undefined2 *)puVar14 = 0;
    uVar2 = 0xffffffff;
    pCVar15 = DAT_004d11f4;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pCVar15;
      pCVar15 = pCVar15 + 1;
    } while (cVar1 != '\0');
    MultiByteToWideChar(0,1,DAT_004d11f4,~uVar2 - 1,(LPWSTR)&uStack_52c,0x1ff);
    HVar4 = HlinkNavigateString((IUnknown *)0x0,(LPCWSTR)&uStack_52c);
    pcVar5 = extraout_EDX_06;
    if (HVar4 < 0) {
      console_printf(&console_log_queue,s_Failed_to_open_browser_at___s___00474800,DAT_004d11f4);
      pcVar5 = extraout_EDX_07;
    }
    DAT_004d11f8 = '\0';
  }
  console_flush_log(&console_log_queue,pcVar5);
  return 0;
}



