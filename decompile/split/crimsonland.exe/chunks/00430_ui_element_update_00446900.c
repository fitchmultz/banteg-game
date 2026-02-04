/* ui_element_update @ 00446900 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* updates hover/click/animation for a UI element and fires callbacks */

void __cdecl ui_element_update(ui_element_t *element)

{
  uchar uVar1;
  ui_element_t *puVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  ui_element_t *puVar6;
  int iVar7;
  int iVar8;
  ui_element_t **ppuVar9;
  float10 fVar10;
  float10 fVar11;
  
  puVar6 = element;
  if ((element->_pad0[0] == '\0') && (element->active != '\0')) {
    if (((ui_mouse_x <= *(float *)element->_pad1) ||
        (((ui_mouse_y <= *(float *)(element->_pad1 + 4) ||
          (*(float *)(element->_pad1 + 8) <= ui_mouse_x)) ||
         (*(float *)(element->_pad1 + 0xc) <= ui_mouse_y)))) ||
       ((ui_mouse_blocked != '\0' || (DAT_004871ca != '\0')))) {
      element->_pad5[0xec] = '\0';
    }
    else {
      uVar1 = element->enabled;
      element->_pad5[0xec] = '\x01';
      if ((uVar1 != '\0') && (element->on_activate != (_func_1 *)0x0)) {
        _DAT_0048723c = element;
        _DAT_00487238 = 0;
        ppuVar9 = &ui_element_table_end;
        do {
          puVar2 = *ppuVar9;
          if ((puVar2->enabled != '\0') &&
             ((game_state_id != 0 || (puVar2->on_activate != (_func_1 *)0x0)))) {
            if (element == puVar2) break;
            _DAT_00487238 = _DAT_00487238 + 1;
          }
          ppuVar9 = ppuVar9 + 1;
        } while ((int)ppuVar9 < 0x48f20c);
      }
    }
    element->counter_timer = element->counter_timer + frame_dt_ms;
    uVar1 = element->_pad5[0xec];
    if (uVar1 == '\0') {
      element->counter_value = element->counter_value + frame_dt_ms * -2;
    }
    else {
      element->counter_value = element->counter_value + frame_dt_ms * 6;
    }
    if (element->counter_value < 0) {
      element->counter_value = 0;
    }
    if (1000 < element->counter_value) {
      element->counter_value = 1000;
    }
    if ((((element->on_activate != (_func_1 *)0x0) && (0xfe < element->counter_timer)) &&
        (uVar1 != '\0')) && (iVar7 = input_primary_just_pressed(), (char)iVar7 != '\0')) {
      sfx_play(sfx_ui_buttonclick);
      (*element->on_activate)();
    }
    iVar7 = *(int *)(element->_pad0 + 0xe);
    if (ui_elements_timeline < iVar7) {
      iVar3 = *(int *)(element->_pad0 + 0x12);
      if (ui_elements_timeline < iVar3) {
        uVar1 = element[1].active;
        element = (ui_element_t *)0x3fc90fdb;
        fVar4 = puVar6->quad0[0] - puVar6->quad0[7];
        puVar6->_pad0[10] = '\0';
        puVar6->_pad0[0xb] = '\0';
        puVar6->_pad0[0xc] = '\0';
        puVar6->_pad0[0xd] = '\0';
        if (uVar1 == '\0') {
          *(float *)(puVar6->_pad0 + 6) = -ABS(fVar4);
        }
        else {
          *(float *)(puVar6->_pad0 + 6) = ABS(fVar4);
        }
      }
      else {
        iVar8 = ui_elements_timeline - iVar3;
        puVar6->_pad0[10] = '\0';
        puVar6->_pad0[0xb] = '\0';
        puVar6->_pad0[0xc] = '\0';
        puVar6->_pad0[0xd] = '\0';
        fVar5 = (float)(iVar7 - iVar3);
        puVar2 = (ui_element_t *)(1.5707964 - ((float)iVar8 * 1.5707964) / fVar5);
        fVar4 = element->quad0[0] - element->quad0[7];
        if (element[1].active == '\0') {
          *(float *)(element->_pad0 + 6) =
               -((1.0 - ((float)ui_elements_timeline - (float)iVar3) / fVar5) * ABS(fVar4));
          element = puVar2;
        }
        else {
          *(float *)(element->_pad0 + 6) =
               (1.0 - ((float)ui_elements_timeline - (float)iVar3) / fVar5) * ABS(fVar4);
          element = puVar2;
        }
      }
    }
    else {
      if (element->enabled == '\0') {
        sfx_play(sfx_ui_panelclick);
        element->enabled = '\x01';
      }
      if (element->counter_timer < 0x100) {
        element->counter_timer = element->counter_timer + frame_dt_ms;
      }
      puVar6->_pad0[6] = '\0';
      puVar6->_pad0[7] = '\0';
      puVar6->_pad0[8] = '\0';
      puVar6->_pad0[9] = '\0';
      element = (ui_element_t *)0x0;
      puVar6->_pad0[10] = '\0';
      puVar6->_pad0[0xb] = '\0';
      puVar6->_pad0[0xc] = '\0';
      puVar6->_pad0[0xd] = '\0';
    }
    iVar7 = ui_get_element_index(puVar6);
    if (iVar7 == 0) {
      element = (ui_element_t *)-ABS((float)element);
    }
    if ((ui_elements_timeline < *(int *)(puVar6->_pad0 + 0xe)) && (puVar6->enabled != '\0')) {
      puVar6->enabled = '\0';
    }
    fVar10 = (float10)fcos((float10)(float)element);
    puVar6->rot_m00 = (float)fVar10;
    fVar11 = (float10)fsin((float10)(float)element);
    puVar6->rot_m01 = (float)-fVar11;
    puVar6->rot_m10 = (float)fVar11;
    puVar6->rot_m11 = (float)fVar10;
  }
  return;
}



