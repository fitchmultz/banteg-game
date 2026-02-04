/* init_audio_and_terrain @ 0042a9f0 */

/* sound init + terrain texture setup */

void init_audio_and_terrain(void)

{
  IGrim2D_vtbl *pIVar1;
  undefined4 uVar2;
  int iVar3;
  char *extraout_EDX;
  char *extraout_EDX_00;
  char *extraout_EDX_01;
  longlong lVar4;
  char *pcVar5;
  
  console_printf(&console_log_queue,s_Init_Grim_successful__00474114);
  console_printf(&console_log_queue,&DAT_004711c0);
  console_printf(&console_log_queue,s________________________004740fc);
  console_printf(&console_log_queue,s___Sound_init___________004740e4);
  console_printf(&console_log_queue,s________________________004740fc);
  if (DAT_004aaeea == '\0') {
    iVar3 = sfx_system_init();
    if ((char)iVar3 == '\0') {
      DAT_004aaeea = '\x01';
    }
  }
  else {
    console_printf(&console_log_queue,s____no_sounds_selected_004740cc);
  }
  console_printf(&console_log_queue,&DAT_004711c0);
  terrain_texture_width = 0x400;
  terrain_texture_height = 0x400;
  if (0.5 <= (float)config_blob.reserved0._112_4_) {
    if (4.0 < (float)config_blob.reserved0._112_4_) {
      config_blob.reserved0[0x70] = '\0';
      config_blob.reserved0[0x71] = '\0';
      config_blob.reserved0[0x72] = 0x80;
      config_blob.reserved0[0x73] = '@';
    }
  }
  else {
    config_blob.reserved0[0x70] = '\0';
    config_blob.reserved0[0x71] = '\0';
    config_blob.reserved0[0x72] = '\0';
    config_blob.reserved0[0x73] = '?';
  }
  if (terrain_texture_failed == '\0') {
    lVar4 = __ftol();
    iVar3 = (*grim_interface_ptr->vtable->grim_create_texture)
                      (s_ground_004740c4,(int)lVar4,(int)lVar4);
    uVar2 = config_blob.reserved0._112_4_;
    pcVar5 = extraout_EDX;
    if ((char)iVar3 == '\0') {
      config_blob.reserved0._112_4_ =
           (float)config_blob.reserved0._112_4_ + (float)config_blob.reserved0._112_4_;
      pIVar1 = grim_interface_ptr->vtable;
      lVar4 = __ftol();
      iVar3 = (int)lVar4;
      lVar4 = __ftol();
      iVar3 = (*pIVar1->grim_create_texture)(s_ground_004740c4,(int)lVar4,iVar3);
      if ((char)iVar3 == '\0') {
        terrain_texture_failed = '\x01';
        config_blob.reserved0._112_4_ = uVar2;
        console_printf(&console_log_queue,s_Failed_to_create_terrain_texture_004740a0);
        pcVar5 = s___>_entering_safemode__00474088;
      }
      else {
        pcVar5 = s_Created_terrain_texture__0047406c;
      }
      console_printf(&console_log_queue,pcVar5);
      pcVar5 = extraout_EDX_00;
    }
    if (terrain_texture_failed == '\0') goto LAB_0042abbf;
  }
  console_printf(&console_log_queue,s_Running_in_safemode__using_stati_00474034);
  pcVar5 = extraout_EDX_01;
LAB_0042abbf:
  console_flush_log(&console_log_queue,pcVar5);
  return;
}



