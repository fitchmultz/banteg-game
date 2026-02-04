/* config_sync_from_grim @ 0041ec60 */

/* syncs Grim config values into config blob and writes crimson.cfg */

int config_sync_from_grim(void)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  uchar *puVar4;
  char *pcVar5;
  FILE *pFVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  highscore_record_t *phVar10;
  highscore_record_t *phVar11;
  uchar *puVar12;
  char *pcVar13;
  char *pcStack_494;
  uint local_490 [4];
  char acStack_480 [14];
  undefined1 uStack_472;
  undefined1 uStack_471;
  undefined1 uStack_470;
  undefined1 uStack_46f;
  undefined4 uStack_46c;
  undefined4 uStack_468;
  undefined4 uStack_464;
  undefined4 uStack_460;
  undefined4 uStack_43c;
  undefined4 uStack_438;
  undefined4 uStack_414;
  undefined4 uStack_410;
  char acStack_40c [12];
  undefined4 uStack_400;
  undefined4 uStack_3fc;
  int aiStack_3f8 [8];
  char acStack_3d8 [216];
  char acStack_300 [36];
  undefined4 uStack_2dc;
  undefined4 uStack_2d8;
  undefined4 uStack_2d4;
  undefined4 uStack_2d0;
  undefined4 uStack_2cc;
  undefined4 uStack_2c8;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined1 uStack_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  undefined4 uStack_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  undefined4 uStack_29c;
  undefined4 uStack_298;
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  undefined4 uStack_288;
  undefined4 uStack_284;
  undefined4 uStack_280;
  undefined4 uStack_27c;
  undefined4 uStack_278;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uchar uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar2 = (undefined1 *)(*grim_interface_ptr->vtable->grim_get_config_var)(local_490,8);
  config_blob.windowed._0_1_ = *puVar2;
  piVar3 = (int *)(*grim_interface_ptr->vtable->grim_get_config_var)(local_490,0x2b);
  config_blob.display_bpp = *piVar3;
  piVar3 = (int *)(*grim_interface_ptr->vtable->grim_get_config_var)(local_490,0x29);
  config_blob.screen_width = *piVar3;
  piVar3 = (int *)(*grim_interface_ptr->vtable->grim_get_config_var)(local_490,0x2a);
  config_blob.screen_height = *piVar3;
  puVar4 = (uchar *)(*grim_interface_ptr->vtable->grim_get_config_var)(local_490,0x59);
  config_blob.reserved0._112_4_ = *(undefined4 *)puVar4;
  puVar4 = (uchar *)(*grim_interface_ptr->vtable->grim_get_config_var)(local_490,0x54);
  config_blob.player_name_length = player_name_length;
  config_blob.reserved7[0] = *puVar4;
  uVar7 = 0xffffffff;
  phVar10 = &highscore_active_record;
  do {
    phVar11 = phVar10;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    phVar11 = (highscore_record_t *)(phVar10->player_name + 1);
    pcVar5 = phVar10->player_name;
    phVar10 = phVar11;
  } while (*pcVar5 != '\0');
  uVar7 = ~uVar7;
  pcVar5 = (char *)((int)phVar11 - uVar7);
  pcVar13 = config_blob.player_name;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar13 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar13 = pcVar13 + 1;
  }
  if (grim_config_invoked != '\0') {
    pcStack_494 = acStack_3d8;
    acStack_40c[0] = '\0';
    acStack_40c[1] = '\0';
    acStack_40c[2] = '\0';
    acStack_40c[3] = '\0';
    uStack_38 = 0;
    acStack_40c[4] = '\0';
    acStack_40c[5] = '\0';
    acStack_40c[6] = '\0';
    acStack_40c[7] = '\0';
    uStack_37 = 1;
    uStack_34 = 0;
    uStack_c = 0x3f000000;
    uStack_30 = 1;
    uStack_8 = 0x101;
    uStack_4 = 0x102;
    uStack_12 = 0;
    uStack_410 = 0x3f800000;
    uStack_13 = 0;
    acStack_40c[8] = 0;
    iVar9 = 0;
    piVar3 = aiStack_3f8;
    do {
      uVar7 = 0xffffffff;
      *piVar3 = iVar9;
      pcVar5 = s_default_0047131c;
      do {
        pcVar13 = pcVar5;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar13 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar13;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      piVar3 = piVar3 + 1;
      pcVar5 = pcVar13 + -uVar7;
      pcVar13 = pcStack_494;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar13 = pcVar13 + 4;
      }
      iVar9 = iVar9 + 1;
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar13 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar13 = pcVar13 + 1;
      }
      pcStack_494 = pcStack_494 + 0x1b;
    } while (iVar9 < 8);
    acStack_480[3] = 0;
    acStack_480[2] = 0;
    pcVar5 = acStack_300;
    for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
      pcVar5[0] = '\0';
      pcVar5[1] = '\0';
      pcVar5[2] = '\0';
      pcVar5[3] = '\0';
      pcVar5 = pcVar5 + 4;
    }
    uVar7 = 0xffffffff;
    pcVar5 = &default_player_name;
    do {
      pcVar13 = pcVar5;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar13 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar13;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    pcVar5 = pcVar13 + -uVar7;
    pcVar13 = acStack_300;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar13 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar13 = pcVar13 + 1;
    }
    uStack_3fc = 1;
    uStack_20 = 1;
    uStack_2c8 = 0x20;
    uStack_468 = 1;
    uStack_472 = 1;
    uStack_470 = 1;
    uStack_46f = 1;
    uStack_46c = 1;
    uStack_2ac = 0x20;
    uStack_400 = 0;
    uStack_10 = 5;
    acStack_480[0] = '\0';
    acStack_480[1] = 0;
    uStack_14 = '\0';
    uStack_2d8 = 0;
    uStack_2d4 = 0;
    uStack_2d0 = 9000;
    uStack_2cc = 27000;
    uStack_2dc = 100;
    uStack_414 = 0;
    uStack_2c4 = 800;
    uStack_2c0 = 600;
    uStack_2bc = 0;
    uStack_471 = 0;
    uStack_464 = 2;
    uStack_460 = 2;
    uStack_43c = 0;
    uStack_438 = 0;
    uStack_1c = 0x3f800000;
    uStack_18 = 0x3f800000;
    uStack_2b8 = 0x11;
    uStack_2b4 = 0x1f;
    uStack_2b0 = 0x1e;
    uStack_2a8 = 0x100;
    uStack_2a4 = 0x17e;
    uStack_2a0 = 0x17e;
    uStack_29c = 0x10;
    uStack_298 = 0x12;
    uStack_294 = 0x13f;
    uStack_290 = 0x140;
    uStack_28c = 0x141;
    uStack_288 = 0x153;
    uStack_284 = 0x17e;
    uStack_280 = 0x17e;
    uStack_27c = 0x17e;
    uStack_278 = 200;
    uStack_274 = 0xd0;
    uStack_270 = 0xcb;
    uStack_26c = 0xcd;
    uStack_268 = 0x9d;
    uStack_264 = 0x17e;
    uStack_260 = 0x17e;
    uStack_25c = 0xd3;
    pcVar13 = &file_mode_read_binary;
    uStack_258 = 0xd1;
    uStack_254 = 0x13f;
    uStack_250 = 0x140;
    uStack_24c = 0x141;
    uStack_248 = 0x153;
    uStack_244 = 0x17e;
    uStack_240 = 0x17e;
    uStack_23c = 0x17e;
    acStack_480[4] = '\x01';
    acStack_480[5] = '\x01';
    pcVar5 = game_build_path(config_filename);
    pFVar6 = (FILE *)crt_fopen(pcVar5,pcVar13);
    if (pFVar6 != (FILE *)0x0) {
      crt_fseek((int *)pFVar6,0,2);
      iVar9 = crt_ftell((char *)pFVar6);
      if (iVar9 == 0x480) {
        crt_fseek((int *)pFVar6,0,0);
        crt_fread(acStack_480,0x480,1,(int *)pFVar6);
        uVar7 = 0xffffffff;
        pcVar5 = acStack_40c;
        do {
          pcVar13 = pcVar5;
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          pcVar13 = pcVar5 + 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar13;
        } while (cVar1 != '\0');
        uVar7 = ~uVar7;
        config_blob.fx_toggle = uStack_14;
        puVar4 = (uchar *)(pcVar13 + -uVar7);
        puVar12 = config_blob.reserved0 + 0x74;
        for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)puVar12 = *(undefined4 *)puVar4;
          puVar4 = puVar4 + 4;
          puVar12 = puVar12 + 4;
        }
        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar12 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar12 = puVar12 + 1;
        }
      }
      crt_fclose(pFVar6);
    }
  }
  pcVar13 = &file_mode_write_binary;
  pcVar5 = game_build_path(config_filename);
  pFVar6 = (FILE *)crt_fopen(pcVar5,pcVar13);
  iVar9 = 0;
  if (pFVar6 != (FILE *)0x0) {
    crt_fwrite((char *)&config_blob,0x480,1,(int *)pFVar6);
    iVar9 = crt_fclose(pFVar6);
  }
  return CONCAT31((int3)((uint)iVar9 >> 8),1);
}



