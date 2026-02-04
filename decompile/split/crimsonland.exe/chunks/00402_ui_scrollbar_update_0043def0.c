/* ui_scrollbar_update @ 0043def0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* updates and renders a scroll bar (wheel, drag, key input) */

void __cdecl ui_scrollbar_update(float *xy,float *state)

{
  char cVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *text;
  float unaff_ESI;
  int iVar7;
  char *pcVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  longlong lVar9;
  undefined4 *h;
  undefined4 *puVar10;
  float *pfVar11;
  float *pfVar12;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfVar12 = xy;
  lVar9 = __ftol();
  *xy = (float)(int)lVar9;
  lVar9 = __ftol();
  xy[1] = (float)(int)lVar9;
  state[1] = -NAN;
  iVar4 = ui_focus_update((int)state);
  xy = (float *)CONCAT31((int3)((ulonglong)lVar9 >> 8),(char)iVar4);
  if ((char)iVar4 != '\0') {
    local_30 = *pfVar12 - 16.0;
    local_2c = pfVar12[1];
    ui_focus_draw(&local_30);
  }
  pfVar11 = &local_30;
  fVar2 = (float)((int)state[3] * 0x10 + 4);
  local_30 = 1.0;
  local_2c = 1.0;
  local_28 = 1.0;
  local_24 = 1.0;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(pfVar12,250.0,fVar2);
  fStack_34 = *pfVar12 + 1.0;
  puVar10 = &uStack_14;
  uStack_14 = 0;
  local_30 = pfVar12[1] + 1.0;
  fStack_10 = 0.0;
  fStack_c = 0.0;
  fStack_8 = 1.0;
  h = (undefined4 *)((float)xy - 2.0);
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&fStack_34,248.0,(float)h);
  if ((int)state[3] < (int)state[0xd]) {
    fStack_38 = *pfVar12 + 240.0;
    h = &uStack_18;
    uStack_18 = 0x3f800000;
    fStack_34 = pfVar12[1];
    uStack_14 = 0x3f800000;
    fStack_10 = 1.0;
    fStack_c = 0.8;
    (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&fStack_38,1.0,fVar2);
  }
  (*grim_interface_ptr->vtable->grim_get_mouse_wheel_delta)(h,puVar10,pfVar11);
  if ((float10)0.0 < extraout_ST0) {
    *state = *state - 1.0;
  }
  (*grim_interface_ptr->vtable->grim_get_mouse_wheel_delta)();
  if (extraout_ST0_00 < (float10)0.0) {
    *state = *state + 1.0;
  }
  if (fStack_8._0_1_ != '\0') {
    iVar4 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(200);
    if ((char)iVar4 != '\0') {
      *state = *state - 1.0;
    }
    iVar4 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xd0);
    if ((char)iVar4 != '\0') {
      *state = *state + 1.0;
    }
  }
  iVar4 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xc9);
  if ((char)iVar4 != '\0') {
    fStack_8 = (float)((int)state[3] + -1);
    *state = *state - (float)(int)fStack_8;
  }
  iVar4 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xd1);
  if ((char)iVar4 != '\0') {
    *state = (float)((int)state[3] + -1) + *state;
  }
  fVar2 = state[0xd];
  fVar3 = state[3];
  fStack_40 = (float)((int)fVar2 - (int)fVar3);
  if ((float)(int)fStack_40 < *state) {
    *state = (float)(int)fStack_40;
  }
  if (*state < 0.0) {
    *state = 0.0;
  }
  fStack_8 = fVar2;
  lVar9 = __ftol();
  fStack_40 = (float)lVar9;
  fStack_8 = ((float)(int)fVar3 / (float)(int)fStack_8) * unaff_ESI;
  if (unaff_ESI < fStack_8) {
    fStack_8 = fStack_4 - 3.0;
  }
  local_24 = *pfVar12 + 241.0;
  fStack_20 = (float)(((((float10)fStack_4 - (float10)3.0) - (float10)fStack_8) / extraout_ST0_01) *
                      (float10)(int)fStack_40 + (float10)1.0 + (float10)pfVar12[1]);
  if ((int)fVar3 < (int)fVar2) {
    uStack_1c = 0x3f800000;
    uStack_18 = 0x3f800000;
    uStack_14 = 0x3f800000;
    fStack_10 = 0.8;
    (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&local_24,8.0,fStack_8 + 1.0);
    fStack_40 = *pfVar12 + 240.0;
    iVar4 = 10;
    fStack_3c = pfVar12[1];
    lVar9 = __ftol();
    iVar4 = ui_mouse_inside_rect(&fStack_40,(int)lVar9,iVar4);
    if ((char)iVar4 == '\0') {
      fStack_40 = local_28 + 1.0;
      fStack_3c = local_24 + 1.0;
      fStack_20 = 0.1;
      uStack_1c = 0x3e4ccccd;
      uStack_18 = 0x3ecccccd;
      uStack_14 = 0x3f800000;
      (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&fStack_40,6.0,fStack_c - 1.0);
      iVar4 = input_primary_is_down();
      if ((char)iVar4 == '\0') {
        DAT_004d11fa = '\0';
        goto LAB_0043e37f;
      }
    }
    else {
      fStack_40 = local_28 + 1.0;
      fStack_3c = local_24 + 1.0;
      fStack_20 = 0.2;
      uStack_1c = 0x3ecccccd;
      uStack_18 = 0x3f4ccccd;
      uStack_14 = 0x3f800000;
      (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&fStack_40,6.0,fStack_c - 1.0);
      DAT_004d11fa = '\x01';
      iVar4 = input_primary_just_pressed();
      if ((char)iVar4 != '\0') {
        iVar4 = 8;
        lVar9 = __ftol();
        iVar4 = ui_mouse_inside_rect(&local_2c,(int)lVar9,iVar4);
        if ((char)iVar4 == '\0') {
          _DAT_004d11fc = 0.0;
        }
        else {
          _DAT_004d11fc = (ui_mouse_y - pfVar12[1]) - (*state / (float)(int)state[0xd]) * fStack_c;
        }
      }
    }
    if ((DAT_004d11fa != '\0') && (iVar4 = input_primary_is_down(), (char)iVar4 != '\0')) {
      fVar2 = (((ui_mouse_y - pfVar12[1]) - _DAT_004d11fc) / fStack_c) * (float)(int)state[0xd];
      *state = fVar2;
      fStack_10 = (float)((int)state[0xd] - (int)state[3]);
      if (fStack_10 < fVar2) {
        *state = fStack_10;
      }
      if (*state < 0.0) {
        *state = 0.0;
      }
    }
  }
LAB_0043e37f:
  local_28 = pfVar12[1];
  local_2c = *pfVar12 - 2.0;
  iVar4 = 0;
  if (0 < (int)state[3]) {
    iVar7 = (int)fStack_40 * 4;
    do {
      fVar2 = fStack_40;
      if ((int)state[0xd] <= iVar4) {
        return;
      }
      iVar5 = ui_mouse_inside_rect(&local_2c,0x11,0xf0);
      if ((char)iVar5 == '\0') {
        fStack_8 = 0.9;
        if (state[2] != fVar2) {
          fStack_8 = 0.7;
        }
      }
      else {
        fStack_8 = 1.0;
        state[1] = fVar2;
        iVar5 = input_primary_just_pressed();
        if ((char)iVar5 != '\0') {
          state[2] = fVar2;
        }
      }
      text = *(char **)((int)state[0xc] + iVar7);
      if (*text == '\\') {
        if (text[1] == 'g') {
          (*grim_interface_ptr->vtable->grim_set_color)(0.7,1.0,0.7,fStack_8);
          text = text + 2;
        }
      }
      else {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_8);
      }
      uVar6 = 0xffffffff;
      iVar5 = 0;
      pcVar8 = text;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      fStack_4 = 0.0;
      if (0 < (int)uVar6) {
        pfVar12 = state + 4;
        do {
          if ((text[iVar5] == '\t') || (text[iVar5] == '\0')) {
            text[iVar5] = '\0';
            fStack_3c = (float)((int)*pfVar12 * (int)fStack_4);
            (*grim_interface_ptr->vtable->grim_draw_text_small)
                      ((float)(int)fStack_3c + local_2c + 8.0,local_28 + 2.0,text);
            fStack_4 = (float)((int)fStack_4 + 1);
            pfVar12 = pfVar12 + 1;
            text = text + iVar5 + 1;
            uVar6 = uVar6 - (iVar5 + 1);
            iVar5 = 0;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)uVar6);
      }
      local_28 = local_28 + 16.0;
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 4;
      fStack_40 = (float)((int)fStack_40 + 1);
    } while (iVar4 < (int)state[3]);
  }
  return;
}



