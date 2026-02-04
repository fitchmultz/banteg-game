/* highscore_load_table @ 0043afa0 */

/* loads, filters, and sorts the high score table */

void highscore_load_table(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  FILE *fp;
  byte *pbVar4;
  highscore_record_t *phVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uchar *puVar12;
  int iVar13;
  byte *pbVar14;
  char *pcVar15;
  highscore_record_t *phVar16;
  bool bVar17;
  code *cmp;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  byte local_48 [40];
  uint local_20;
  uint local_10;
  byte local_8;
  undefined1 local_7;
  byte bStack_6;
  undefined1 uStack_5;
  byte bStack_4;
  char cStack_3;
  undefined1 uStack_2;
  undefined1 local_1;
  
  pbVar4 = local_48;
  for (iVar8 = 0x12; iVar8 != 0; iVar8 = iVar8 + -1) {
    pbVar4[0] = 0;
    pbVar4[1] = 0;
    pbVar4[2] = 0;
    pbVar4[3] = 0;
    pbVar4 = pbVar4 + 4;
  }
  uVar9 = 0xffffffff;
  pcVar3 = &default_player_name;
  do {
    pcVar6 = pcVar3;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar6 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar6;
  } while (cVar1 != '\0');
  uVar9 = ~uVar9;
  pbVar4 = (byte *)(pcVar6 + -uVar9);
  pbVar14 = local_48;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pbVar14 = *(undefined4 *)pbVar4;
    pbVar4 = pbVar4 + 4;
    pbVar14 = pbVar14 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pbVar14 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    pbVar14 = pbVar14 + 1;
  }
  bStack_4 = 0;
  uStack_2 = 0x7c;
  local_1 = 0xff;
  local_10 = crt_rand();
  local_10 = local_10 & 0xfee050f;
  pcVar3 = highscore_build_path();
  highscore_table_count = 0;
  puVar12 = &highscore_table.sentinel_pipe;
  do {
    phVar16 = (highscore_record_t *)(puVar12 + -0x46);
    for (iVar8 = 0x12; iVar8 != 0; iVar8 = iVar8 + -1) {
      phVar16->player_name[0] = '\0';
      phVar16->player_name[1] = '\0';
      phVar16->player_name[2] = '\0';
      phVar16->player_name[3] = '\0';
      phVar16 = (highscore_record_t *)(phVar16->player_name + 4);
    }
    uVar9 = 0xffffffff;
    pcVar6 = &default_player_name;
    do {
      pcVar15 = pcVar6;
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      pcVar15 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar15;
    } while (cVar1 != '\0');
    uVar9 = ~uVar9;
    pcVar6 = pcVar15 + -uVar9;
    phVar16 = (highscore_record_t *)(puVar12 + -0x46);
    for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)phVar16->player_name = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      phVar16 = (highscore_record_t *)(phVar16->player_name + 4);
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      phVar16->player_name[0] = *pcVar6;
      pcVar6 = pcVar6 + 1;
      phVar16 = (highscore_record_t *)(phVar16->player_name + 1);
    }
    puVar12[-2] = '\0';
    *puVar12 = '|';
    puVar12[1] = 0xff;
    uVar9 = crt_rand();
    *(uint *)(puVar12 + -0xe) = uVar9 & 0xfee050f;
    puVar12 = puVar12 + 0x48;
  } while ((int)puVar12 < 0x484776);
  iVar8 = 0;
  fp = (FILE *)crt_fopen(pcVar3,&file_mode_read_binary);
  if (fp != (FILE *)0x0) {
    uVar9 = highscore_date_checksum
                      (local_system_time & 0xffff,local_system_time >> 0x10,(uint)local_system_day);
    bVar2 = (byte)fp->_flag;
    while ((bVar2 & 0x10) == 0) {
      pcVar3 = highscore_read_record((char *)local_48,(int *)fp);
      if ((pcVar3 == (char *)0x0) || ((local_20 & 0xff) != config_blob.reserved0._24_4_))
      goto LAB_0043b2ba;
      if (config_blob.reserved0._24_4_ == 3) {
        if (config_blob.hardcore == '\0') {
          if (cStack_3 == '\0') goto LAB_0043b0ff;
        }
        else if (cStack_3 == 'u') goto LAB_0043b0ff;
      }
      else {
LAB_0043b0ff:
        if (((config_blob.score_load_gate != '\0') || ((bStack_4 & 1) == 0)) ||
           ((bStack_4 & 2) != 0)) {
          if (config_blob.reserved0[2] == '\x03') {
            if (((local_system_day == local_8) &&
                ((local_system_time & 0xffff) - 2000 ==
                 (CONCAT12(cStack_3,CONCAT11(bStack_4,uStack_5)) & 0xff))) &&
               (local_system_time._2_2_ == bStack_6)) goto LAB_0043b1df;
          }
          else if (config_blob.reserved0[2] == '\x02') {
            if ((uVar9 == (CONCAT12(uStack_5,CONCAT11(bStack_6,local_7)) & 0xff)) &&
               ((local_system_time & 0xffff) ==
                (CONCAT12(cStack_3,CONCAT11(bStack_4,uStack_5)) & 0xff) + 2000)) {
LAB_0043b1df:
              if ((config_blob.reserved0[3] == '\x01') &&
                 (pbVar4 = highscore_find_name_entry(local_48,iVar8), pbVar4 != (byte *)0x0)) {
                pbVar14 = local_48;
                for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {
                  *(undefined4 *)pbVar4 = *(undefined4 *)pbVar14;
                  pbVar14 = pbVar14 + 4;
                  pbVar4 = pbVar4 + 4;
                }
              }
              else if (iVar8 == 99) {
                phVar16 = &highscore_table;
                if (config_blob.reserved0._24_4_ == 2) {
                  phVar5 = (highscore_record_t *)&DAT_00482b58;
                  do {
                    if ((int)phVar5->survival_elapsed_ms < (int)phVar16->survival_elapsed_ms) {
                      phVar16 = phVar5;
                    }
                    phVar5 = phVar5 + 1;
                  } while ((int)phVar5 < 0x484730);
                  pbVar4 = local_48;
                  for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {
                    *(undefined4 *)phVar16->player_name = *(undefined4 *)pbVar4;
                    pbVar4 = pbVar4 + 4;
                    phVar16 = (highscore_record_t *)(phVar16->player_name + 4);
                  }
                }
                else {
                  phVar5 = (highscore_record_t *)&DAT_00482b58;
                  if (config_blob.reserved0._24_4_ == 3) {
                    do {
                      if ((int)phVar16->survival_elapsed_ms < (int)phVar5->survival_elapsed_ms) {
                        phVar16 = phVar5;
                      }
                      phVar5 = phVar5 + 1;
                    } while ((int)phVar5 < 0x484730);
                    pbVar4 = local_48;
                    for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {
                      *(undefined4 *)phVar16->player_name = *(undefined4 *)pbVar4;
                      pbVar4 = pbVar4 + 4;
                      phVar16 = (highscore_record_t *)(phVar16->player_name + 4);
                    }
                  }
                  else {
                    do {
                      if ((int)phVar5->score_xp < (int)phVar16->score_xp) {
                        phVar16 = phVar5;
                      }
                      phVar5 = phVar5 + 1;
                    } while ((int)phVar5 < 0x484730);
                    pbVar4 = local_48;
                    for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {
                      *(undefined4 *)phVar16->player_name = *(undefined4 *)pbVar4;
                      pbVar4 = pbVar4 + 4;
                      phVar16 = (highscore_record_t *)(phVar16->player_name + 4);
                    }
                  }
                }
              }
              else {
                iVar13 = iVar8 + 1;
                pbVar4 = local_48;
                phVar16 = &highscore_table + iVar8;
                highscore_table_count = iVar13;
                for (iVar11 = 0x12; iVar8 = iVar13, iVar11 != 0; iVar11 = iVar11 + -1) {
                  *(undefined4 *)phVar16->player_name = *(undefined4 *)pbVar4;
                  pbVar4 = pbVar4 + 4;
                  phVar16 = (highscore_record_t *)(phVar16->player_name + 4);
                }
              }
            }
          }
          else if ((config_blob.reserved0[2] != '\x01') ||
                  ((local_system_time._2_2_ == bStack_6 &&
                   ((local_system_time & 0xffff) - 2000 ==
                    (CONCAT12(cStack_3,CONCAT11(bStack_4,uStack_5)) & 0xff))))) goto LAB_0043b1df;
        }
      }
LAB_0043b2ba:
      bVar2 = (byte)fp->_flag;
    }
    crt_fclose(fp);
    if (100 < highscore_table_count) {
      highscore_table_count = 100;
    }
    if (config_blob.reserved0._24_4_ == 2) {
      cmp = highscore_compare_rush_field32_desc;
    }
    else if (config_blob.reserved0._24_4_ == 3) {
      cmp = highscore_compare_quest_field32_asc_nonzero_first;
    }
    else {
      cmp = highscore_compare_survival_score_desc;
    }
    crt_qsort(&highscore_table,100,0x48,cmp);
    if (config_blob.reserved0._128_4_ == 0) {
      local_4c = 0;
      if (0 < highscore_table_count) {
        local_50 = 0;
        iVar8 = highscore_table_count;
        do {
          iVar11 = highscore_table_count;
          if (((highscore_table.reserved0[local_50 + 0xc] & 4) == 0) &&
             ((highscore_table.reserved0[local_50 + 0xc] & 1) != 0)) {
            iVar8 = 0;
            iVar13 = 0;
            local_58 = local_50;
            local_54 = local_4c;
            do {
              pcVar3 = highscore_table.player_name + iVar13;
              if ((highscore_table.reserved0[iVar13 + 0xc] & 1) != 0) {
                pcVar6 = highscore_table.player_name + local_50;
                do {
                  bVar2 = *pcVar6;
                  bVar17 = bVar2 < (byte)*pcVar3;
                  if (bVar2 != *pcVar3) {
LAB_0043b39e:
                    iVar7 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
                    goto LAB_0043b3a3;
                  }
                  if (bVar2 == 0) break;
                  bVar2 = pcVar6[1];
                  bVar17 = bVar2 < (byte)pcVar3[1];
                  if (bVar2 != pcVar3[1]) goto LAB_0043b39e;
                  pcVar6 = pcVar6 + 2;
                  pcVar3 = pcVar3 + 2;
                } while (bVar2 != 0);
                iVar7 = 0;
LAB_0043b3a3:
                if (iVar7 == 0) {
                  if (highscore_table.reserved0[local_58 + -0x10] == '\x02') {
                    if (*(int *)(highscore_table.reserved0 + local_58 + -0x18) <
                        *(int *)(highscore_table.reserved0 + iVar13 + -0x18)) {
LAB_0043b3d0:
                      local_58 = iVar13;
                      local_54 = iVar8;
                    }
                  }
                  else if (*(int *)(highscore_table.reserved0 + local_58 + -0x14) <
                           *(int *)(highscore_table.reserved0 + iVar13 + -0x14)) goto LAB_0043b3d0;
                }
              }
              iVar8 = iVar8 + 1;
              iVar13 = iVar13 + 0x48;
            } while (iVar8 < highscore_table_count);
            (&highscore_table)[local_54].flags = (&highscore_table)[local_54].flags | 4;
            iVar8 = iVar11;
          }
          local_4c = local_4c + 1;
          local_50 = local_50 + 0x48;
          if (iVar8 <= local_4c) {
            return;
          }
        } while( true );
      }
    }
    else if (0 < highscore_table_count) {
      puVar12 = &highscore_table.flags;
      iVar8 = highscore_table_count;
      do {
        if ((*puVar12 & 1) != 0) {
          *puVar12 = *puVar12 | 4;
        }
        puVar12 = puVar12 + 0x48;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  return;
}



