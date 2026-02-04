/* quest_spawn_timeline_update @ 00434250 */

/* WARNING: Type propagation algorithm not settling */
/* updates quest spawn entries based on the quest timer */

void quest_spawn_timeline_update(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  quest_spawn_entry_t *pqVar4;
  int iVar5;
  int local_1c;
  float local_18;
  float local_14;
  float local_8;
  float local_4;
  
  if (creatures_any_active_flag == '\0') {
    DAT_004c3654 = 0;
  }
  else {
    DAT_004c3654 = DAT_004c3654 + frame_dt_ms;
  }
  iVar3 = 0;
  if (0 < quest_spawn_count) {
    piVar1 = &quest_spawn_table.pos_y_block.heading_block.trigger_time_ms;
    do {
      if ((0 < piVar1[1]) &&
         ((*piVar1 < quest_spawn_timeline ||
          (((creatures_any_active_flag != '\0' && (3000 < DAT_004c3654)) &&
           (0x6a4 < quest_spawn_timeline)))))) {
        pqVar4 = &quest_spawn_table + iVar3;
        iVar5 = quest_spawn_count;
        while( true ) {
          uVar2 = 0;
          local_18 = 0.0;
          local_14 = 0.0;
          if (0 < (pqVar4->pos_y_block).heading_block.count) {
            local_1c = 0;
            do {
              if ((pqVar4->pos_x < 0.0) || ((float)terrain_texture_width < pqVar4->pos_x)) {
                local_14 = (float)local_1c;
                if ((uVar2 & 1) != 0) {
                  local_14 = -local_14;
                }
              }
              else {
                local_18 = (float)local_1c;
                if ((uVar2 & 1) != 0) {
                  local_18 = -local_18;
                }
              }
              local_8 = local_18 + pqVar4->pos_x;
              local_4 = local_14 + (pqVar4->pos_y_block).pos_y;
              creature_spawn_template
                        ((pqVar4->pos_y_block).heading_block.template_id,&local_8,
                         (pqVar4->pos_y_block).heading_block.heading);
              uVar2 = uVar2 + 1;
              local_1c = local_1c + 0x28;
              iVar5 = quest_spawn_count;
            } while ((int)uVar2 < (pqVar4->pos_y_block).heading_block.count);
          }
          (pqVar4->pos_y_block).heading_block.count = 0;
          creatures_any_active_flag = '\0';
          if (iVar5 + -1 <= iVar3) break;
          if ((pqVar4->pos_y_block).heading_block.trigger_time_ms !=
              pqVar4[1].pos_y_block.heading_block.trigger_time_ms) {
            creatures_any_active_flag = 0;
            return;
          }
          iVar3 = iVar3 + 1;
          pqVar4 = pqVar4 + 1;
        }
        creatures_any_active_flag = 0;
        return;
      }
      iVar3 = iVar3 + 1;
      piVar1 = piVar1 + 6;
    } while (iVar3 < quest_spawn_count);
  }
  return;
}



