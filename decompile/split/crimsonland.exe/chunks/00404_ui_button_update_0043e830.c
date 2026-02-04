/* ui_button_update @ 0043e830 */

/* draws a UI button, updates hover/press state, and returns 1 when activated */

int __cdecl ui_button_update(float *xy,ui_button_t *button)

{
  float *xy_00;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined3 uVar4;
  IGrim2D_vtbl *pIVar5;
  float unaff_EBP;
  longlong lVar6;
  float y;
  char *fmt;
  float fVar7;
  char *text;
  float fVar8;
  char cVar9;
  float local_18;
  float local_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  xy_00 = xy;
  iVar1 = ui_focus_update((int)button);
  if ((char)iVar1 != '\0') {
    local_18 = *xy - 16.0;
    local_14 = xy[1];
    ui_focus_draw(&local_18);
  }
  iVar2 = (*grim_interface_ptr->vtable->grim_measure_text_width)(button->label);
  if (DAT_00478670 == -1) {
    DAT_00478670 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_ui_buttonSm_00474498);
  }
  if (DAT_00478674 == -1) {
    DAT_00478674 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_ui_buttonMd_00474474);
  }
  if (((float)iVar2 < 40.0) || (xy = (float *)0x43110000, button->force_small != '\0')) {
    xy = (float *)0x42a40000;
  }
  if (button->force_wide != '\0') {
    xy = (float *)0x43110000;
  }
  xy_00[1] = xy_00[1] + 2.0;
  lVar6 = __ftol();
  iVar2 = ui_mouse_inside_rect(xy_00,0x1c,(int)lVar6);
  button->hovered = (uchar)iVar2;
  xy_00[1] = xy_00[1] - 2.0;
  if (button->hovered != '\0') {
    ui_focus_set((int)button,'\0');
  }
  if ((button->enabled == '\0') ||
     ((button->hovered == '\0' && (((char)iVar1 == '\0' || (ui_focus_timer_ms < 0x321)))))) {
    iVar1 = button->hover_anim + frame_dt_ms * -4;
  }
  else {
    iVar1 = button->hover_anim + frame_dt_ms * 6;
  }
  button->hover_anim = iVar1;
  if (0 < button->click_anim) {
    button->click_anim = button->click_anim + frame_dt_ms * -6;
  }
  if (button->click_anim < 0) {
    button->click_anim = 0;
  }
  if (button->hover_anim < 0) {
    button->hover_anim = 0;
  }
  else if (1000 < button->hover_anim) {
    button->hover_anim = 1000;
  }
  fStack_c = 0.5;
  fStack_8 = 0.7;
  fStack_4 = 0.0;
  if (0 < button->click_anim) {
    fVar8 = (float)button->click_anim;
    fStack_c = fVar8 * 0.0005 + 0.5;
    fStack_8 = fVar8 * 0.00070000003 + 0.7;
    if (1.0 < fStack_c) {
      fStack_c = 1.0;
    }
    if (1.0 < fStack_8) {
      fStack_8 = 1.0;
    }
  }
  local_18 = (float)button->hover_anim;
  fStack_10 = fStack_c;
  if (0 < (int)local_18) {
    fStack_4 = (float)(int)local_18 * 0.001 * button->alpha;
    local_18 = *xy_00 + 12.0;
    local_14 = xy_00[1] + 5.0;
    (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&local_18,(float)xy - 24.0,22.0);
  }
  if ((unaff_EBP < 40.0) || (button->force_small != '\0')) {
    pIVar5 = grim_interface_ptr->vtable;
    iVar1 = DAT_00478670;
  }
  else {
    pIVar5 = grim_interface_ptr->vtable;
    iVar1 = DAT_00478674;
  }
  (*pIVar5->grim_bind_texture)(iVar1,0);
  if (button->force_wide != '\0') {
    (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_00478674,0);
  }
  cVar9 = '\0';
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,button->alpha);
  fVar8 = 1.4013e-45;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)(*xy_00,xy_00[1],local_14,32.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  if (button->hovered == '\0') {
    fVar7 = button->alpha * 0.7;
  }
  else {
    fVar7 = button->alpha;
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar7);
  text = button->label;
  y = xy_00[1] + 10.0;
  fmt = &s_fmt_percent_s;
  pIVar5 = grim_interface_ptr->vtable;
  fVar7 = *xy_00;
  iVar1 = (*pIVar5->grim_measure_text_width)(text);
  uVar3 = (*pIVar5->grim_draw_text_small_fmt)
                    (grim_interface_ptr,((fVar8 * 0.5 + fVar7) - (float)(iVar1 / 2)) + 1.0,y,fmt,
                     text);
  uVar4 = (undefined3)((uint)uVar3 >> 8);
  if (button->enabled == '\0') {
    button->activated = '\0';
  }
  else if ((cVar9 == '\0') ||
          ((iVar1 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c), (char)iVar1 == '\0'
           && ((button->hovered == '\0' ||
               (iVar1 = input_primary_just_pressed(), (char)iVar1 == '\0')))))) {
    uVar4 = 0;
    button->activated = '\0';
  }
  else {
    uVar4 = 0;
    button->activated = '\x01';
  }
  iVar1 = CONCAT31(uVar4,button->activated);
  if (button->activated != '\0') {
    button->click_anim = 1000;
    iVar1 = sfx_play(sfx_ui_buttonclick);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),button->activated);
}



