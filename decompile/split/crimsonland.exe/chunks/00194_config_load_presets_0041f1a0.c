/* config_load_presets @ 0041f1a0 */

/* loads config presets into globals */

uint config_load_presets(void)

{
  char *pcVar1;
  FILE *fp;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  highscore_record_t *phVar8;
  undefined4 in_stack_ffffff70;
  undefined4 in_stack_ffffffc0;
  undefined4 uVar9;
  char cVar10;
  char *pcVar11;
  
  pcVar11 = &file_mode_read_binary;
  player_state_table.input.move_key_forward = 0x11;
  player_state_table.input.move_key_backward = 0x1f;
  player_state_table.input.turn_key_left = 0x1e;
  player_state_table.input.turn_key_right = 0x20;
  player_state_table.input.fire_key = 0xf;
  player_state_table.input.key_reserved_0 = 0x11;
  player_state_table.input.key_reserved_1 = 0x1f;
  player_state_table.input.aim_key_left = 0x10;
  player_state_table.input.aim_key_right = 0x12;
  player_alt_move_key_forward = 200;
  player_alt_move_key_backward = 0xd0;
  player_alt_turn_key_left = 0xcb;
  player_alt_turn_key_right = 0xcd;
  player_alt_fire_key = 0x9d;
  player_alt_key_reserved_0 = 0x11;
  player_alt_key_reserved_1 = 0x1f;
  player_alt_key_reserved_2 = 0xd3;
  player_alt_key_reserved_3 = 0xc9;
  pcVar1 = game_build_path(config_filename);
  fp = (FILE *)crt_fopen(pcVar1,pcVar11);
  if (fp == (FILE *)0x0) {
    return 0;
  }
  crt_fseek((int *)fp,0,2);
  iVar2 = crt_ftell((char *)fp);
  if (iVar2 != 0x480) {
    crt_fclose(fp);
    uVar3 = config_sync_from_grim();
    return uVar3 & 0xffffff00;
  }
  cVar10 = '\0';
  crt_fseek((int *)fp,0,0);
  crt_fread((char *)&config_blob,0x480,1,(int *)fp);
  uVar9 = 0x41f2ba;
  crt_fclose(fp);
  piVar6 = &player_state_table.input.move_key_backward;
  piVar4 = config_blob.keybinds_p1 + 0xc;
  do {
    piVar5 = piVar4 + 0x10;
    ((player_input_t *)(piVar6 + -1))->move_key_forward = piVar4[-0xc];
    *piVar6 = piVar4[-0xb];
    piVar6[1] = piVar4[-10];
    piVar6[2] = piVar4[-9];
    piVar6[3] = piVar4[-8];
    piVar6[4] = piVar4[-7];
    piVar6[5] = piVar4[-6];
    piVar6[6] = piVar4[-5];
    piVar6[7] = piVar4[-4];
    piVar6[9] = piVar4[-3];
    piVar6[8] = piVar4[-2];
    piVar6[0xb] = piVar4[-1];
    piVar6[10] = *piVar4;
    piVar6 = piVar6 + 0xd8;
    piVar4 = piVar5;
  } while ((int)piVar5 < 0x4805c0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x59,config_blob.reserved0._112_4_);
  if (cVar10 == '\0') {
    (*grim_interface_ptr->vtable->grim_set_config_var)
              (0x54,CONCAT31((int3)((uint)uVar9 >> 8),config_blob.reserved7[0]));
    (*grim_interface_ptr->vtable->grim_set_config_var)
              (8,CONCAT31((int3)((uint)in_stack_ffffffc0 >> 8),(undefined1)config_blob.windowed));
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x2b,config_blob.display_bpp);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x29,config_blob.screen_width);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x2a,config_blob.screen_height);
    (*grim_interface_ptr->vtable->grim_set_config_var)
              (0x53,CONCAT31((int3)((uint)in_stack_ffffff70 >> 8),config_blob.reserved0[0]));
  }
  uVar3 = 0xffffffff;
  pcVar1 = config_blob.player_name;
  do {
    pcVar11 = pcVar1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar11 = pcVar1 + 1;
    cVar10 = *pcVar1;
    pcVar1 = pcVar11;
  } while (cVar10 != '\0');
  uVar3 = ~uVar3;
  pcVar1 = pcVar11 + -uVar3;
  phVar8 = &highscore_active_record;
  for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)phVar8->player_name = *(undefined4 *)pcVar1;
    pcVar1 = pcVar1 + 4;
    phVar8 = (highscore_record_t *)(phVar8->player_name + 4);
  }
  for (uVar7 = uVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    phVar8->player_name[0] = *pcVar1;
    pcVar1 = pcVar1 + 1;
    phVar8 = (highscore_record_t *)(phVar8->player_name + 1);
  }
  player_name_length = config_blob.player_name_length;
  config_blob.reserved0[2] = '\0';
  config_blob.reserved0[0x80] = '\0';
  config_blob.reserved0[0x81] = '\0';
  config_blob.reserved0[0x82] = '\0';
  config_blob.reserved0[0x83] = '\0';
  return CONCAT31((int3)(uVar3 >> 8),1);
}



