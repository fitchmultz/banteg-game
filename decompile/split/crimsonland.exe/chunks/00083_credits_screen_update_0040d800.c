/* credits_screen_update @ 0040d800 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* credits screen update/render loop; clicks flag lines containing 'o' (lowercase) and misclicks
   clear the last flagged line; when all 'o' lines are flagged, sets DAT_004811c4 and injects secret
   lines at DAT_004811bc; Secret button sets game_state_pending=0x1a (AlienZooKeeper) */

void credits_screen_update(void)

{
  uint uVar1;
  float y;
  float fVar2;
  int iVar3;
  int w;
  int iVar4;
  char *pcVar5;
  IGrim2D_vtbl *pIVar6;
  int index;
  credits_line_t *pcVar7;
  longlong lVar8;
  float r;
  float fVar9;
  float b;
  float fStack_28;
  int iStack_24;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((DAT_00480978 & 1) == 0) {
    DAT_00480978 = DAT_00480978 | 1;
    DAT_004811a6 = 1;
    DAT_004811b5 = 0;
    DAT_004811b4 = 0;
    _DAT_004811b0 = 0x3f800000;
    _DAT_004811ac = 0;
    _credits_back_button = (undefined *)0x0;
    DAT_004811a4 = 0;
    credits_back_button_clicked = '\0';
    _DAT_004811a8 = 0;
    crt_atexit(&DAT_0040df60);
  }
  if ((DAT_00480978 & 2) == 0) {
    DAT_00480978 = DAT_00480978 | 2;
    DAT_0048118e = 1;
    DAT_0048119d = 0;
    DAT_0048119c = 0;
    _DAT_00481198 = 0x3f800000;
    _DAT_00481194 = 0;
    _credits_secret_button = (char *)0x0;
    DAT_0048118c = 0;
    credits_secret_button_clicked = '\0';
    _DAT_00481190 = 0;
    crt_atexit(&DAT_0040df50);
  }
  fStack_4 = _DAT_00489dfc + DAT_00489e20;
  _credits_secret_button = menu_label_secret;
  fStack_c = fStack_4 + 40.0 + 10.0;
  fStack_10 = ((DAT_00489e1c + _DAT_00489df8 + 300.0 + _DAT_00489de8 + 48.0) - 110.0) - 40.0;
  if (ui_screen_phase == 0) {
    ui_screen_phase = 1;
    credits_build_lines();
    _DAT_004811c0 = 0.0;
    DAT_00481184 = 0;
  }
  else if (ui_screen_phase == 1) {
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
    if (DAT_004811b8 + 2 < DAT_00481184) {
      _DAT_004811c0 = 0.0;
      DAT_00481184 = 0;
    }
    fStack_c = fStack_c - 4.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fStack_10 + 4.0,fStack_c,menu_label_credits);
    fStack_c = (fStack_c + 20.0) - 6.0;
    _DAT_004811c0 = frame_dt + _DAT_004811c0;
    lVar8 = __ftol();
    DAT_00481184 = (int)lVar8 + -0xf;
    DAT_00481180 = (int)lVar8 + 1;
    if (DAT_004811b8 < DAT_00481180) {
      DAT_00481180 = DAT_004811b8;
    }
    for (fVar2 = _DAT_004811c0 * 16.0; 16.0 < fVar2; fVar2 = fVar2 - 16.0) {
    }
    iVar3 = 0;
    if (DAT_00481180 != DAT_00481184 && -1 < DAT_00481180 - DAT_00481184) {
      iStack_24 = 0;
      do {
        index = DAT_00481184 + iVar3;
        if (index < 0) {
          index = 0;
        }
        w = (*grim_interface_ptr->vtable->grim_measure_text_width)(credits_line_table[index].text);
        y = ((float)iStack_24 + fStack_c) - fVar2;
        fVar9 = (fStack_c - 16.0) + 24.0;
        if (fVar9 <= y) {
          fVar9 = ((float)(((DAT_00481180 - DAT_00481184) + -1) * 0x10) + fStack_c) - 24.0;
          if (fVar9 < y) {
            fStack_28 = (fVar9 - y) * 0.041666668 + 1.0;
            goto LAB_0040db8e;
          }
          fStack_28 = 1.0;
        }
        else {
          fStack_28 = 1.0 - (fVar9 - y) * 0.041666668;
LAB_0040db8e:
          if (fStack_28 <= 1.0) {
            if (fStack_28 < 0.0) {
              fStack_28 = 0.0;
            }
          }
          else {
            fStack_28 = 1.0;
          }
        }
        fStack_8 = (fStack_10 + 140.0) - (float)(w / 2);
        fStack_4 = y;
        iVar4 = ui_mouse_inside_rect(&fStack_8,0x10,w);
        if (((char)iVar4 != '\0') && (iVar4 = input_primary_just_pressed(), (char)iVar4 != '\0')) {
          pcVar5 = _strchr(credits_line_table[index].text,0x6f);
          if (pcVar5 == (char *)0x0) {
            credits_line_clear_flag(index);
          }
          else {
            if ((credits_line_table[index].flags & 4) == 0) {
              sfx_play(sfx_ui_bonus);
            }
            credits_line_table[index].flags = credits_line_table[index].flags | 4;
          }
        }
        uVar1 = credits_line_table[index].flags;
        if ((uVar1 & 4) == 0) {
          pIVar6 = grim_interface_ptr->vtable;
          if ((uVar1 & 1) == 0) {
            fVar9 = 0.5;
            goto LAB_0040dcc6;
          }
          b = 1.0;
          fVar9 = 1.0;
          r = 1.0;
        }
        else {
          pIVar6 = grim_interface_ptr->vtable;
          if ((uVar1 & 1) == 0) {
            fVar9 = 0.7;
LAB_0040dcc6:
            b = 0.7;
            r = 0.4;
          }
          else {
            b = 0.9;
            fVar9 = 1.0;
            r = 0.9;
          }
        }
        (*pIVar6->grim_set_color)(r,fVar9,b,fStack_28);
        (*grim_interface_ptr->vtable->grim_draw_text_small)
                  ((fStack_10 + 140.0) - (float)(w / 2),y,credits_line_table[index].text);
        iVar3 = iVar3 + 1;
        iStack_24 = iStack_24 + 0x10;
      } while (iVar3 < DAT_00481180 - DAT_00481184);
    }
    fStack_10 = fStack_10 + 100.0;
    _credits_back_button = &DAT_00472e80;
    fStack_c = fStack_c + 250.0;
    ui_button_update(&fStack_10,(ui_button_t *)&credits_back_button);
    pcVar7 = credits_line_table;
    do {
      if (((pcVar7->text != (char *)0x0) &&
          (pcVar5 = _strchr(pcVar7->text,0x6f), pcVar5 != (char *)0x0)) &&
         ((pcVar7->flags & 4) == 0)) goto LAB_0040d970;
      iVar3 = credits_secret_line_base_index;
      pcVar7 = pcVar7 + 1;
    } while ((int)pcVar7 < 0x481180);
    if (credits_secret_unlock_flag == '\0') {
      credits_secret_unlock_flag = '\x01';
      credits_line_table[credits_secret_line_base_index].flags =
           credits_line_table[credits_secret_line_base_index].flags | 4;
      credits_line_table[iVar3 + 1].flags = credits_line_table[iVar3 + 1].flags | 4;
      credits_line_table[iVar3 + 2].flags = credits_line_table[iVar3 + 2].flags | 4;
      credits_line_table[iVar3 + 3].flags = credits_line_table[iVar3 + 3].flags | 4;
      credits_line_table[iVar3 + 4].flags = credits_line_table[iVar3 + 4].flags | 4;
      credits_line_table[iVar3 + 5].flags = credits_line_table[iVar3 + 5].flags | 4;
      credits_line_table[iVar3 + 6].flags = credits_line_table[iVar3 + 6].flags | 4;
      credits_line_table[iVar3 + 7].flags = credits_line_table[iVar3 + 7].flags | 4;
      credits_line_table[iVar3 + 8].flags = credits_line_table[iVar3 + 8].flags | 4;
      credits_line_table[iVar3 + 9].flags = credits_line_table[iVar3 + 9].flags | 4;
      pcVar5 = strdup_malloc(s_Inside_Dead_Let_Mighty_Blood_00472e60);
      credits_line_table[iVar3].text = pcVar5;
      pcVar5 = strdup_malloc(s_Do_Firepower_See_Mark_Of_00472e44);
      credits_line_table[iVar3 + 1].text = pcVar5;
      pcVar5 = strdup_malloc(s_The_Sacrifice_Old_Center_00472e28);
      credits_line_table[iVar3 + 2].text = pcVar5;
      pcVar5 = strdup_malloc(s_Yourself_Ground_First_For_00472e0c);
      credits_line_table[iVar3 + 3].text = pcVar5;
      pcVar5 = strdup_malloc(s_Triangle_Cube_Last_Not_Flee_00472df0);
      credits_line_table[iVar3 + 4].text = pcVar5;
      pcVar5 = strdup_malloc(s_0001001110000010101110011_00472dd4);
      credits_line_table[iVar3 + 5].text = pcVar5;
      pcVar5 = strdup_malloc(s_0101001011100010010101100_00472db8);
      credits_line_table[iVar3 + 6].text = pcVar5;
      pcVar5 = strdup_malloc(s_011111001000111_00472da8);
      credits_line_table[iVar3 + 7].text = pcVar5;
      pcVar5 = strdup_malloc(s__4_bits_for_index__<__OOOPS_I_me_00472d7c);
      credits_line_table[iVar3 + 8].text = pcVar5;
      crt_free(credits_line_table[iVar3 + 9].text);
      pcVar5 = strdup_malloc(s__4_bits_for_index__00472d68);
      credits_line_table[iVar3 + 9].text = pcVar5;
    }
    fStack_8 = fStack_10 + 94.0;
    fStack_4 = fStack_c;
    ui_button_update(&fStack_8,(ui_button_t *)&credits_secret_button);
  }
LAB_0040d970:
  if (credits_back_button_clicked != '\0') {
    ui_transition_direction = 0;
    game_state_pending = 4;
    FUN_00446140();
  }
  if (credits_secret_button_clicked != '\0') {
    ui_transition_direction = 0;
    game_state_pending = 0x1a;
    FUN_00446140();
  }
  iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(1);
  if ((char)iVar3 != '\0') {
    ui_transition_direction = 0;
    game_state_pending = 4;
    FUN_00446140();
  }
  return;
}



