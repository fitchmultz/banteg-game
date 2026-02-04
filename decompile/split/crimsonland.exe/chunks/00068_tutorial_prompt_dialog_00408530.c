/* tutorial_prompt_dialog @ 00408530 */

/* renders tutorial prompt text + Repeat/Play/Skip buttons and handles selections */

void __cdecl tutorial_prompt_dialog(char *text,float alpha)

{
  float h;
  float w;
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  longlong lVar6;
  char *unaff_retaddr;
  char in_stack_0000000c;
  undefined4 *puVar7;
  float fStack_24;
  float afStack_20 [3];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = (*grim_interface_ptr->vtable->grim_measure_text_width)(text);
  iVar4 = 1;
  pcVar2 = _strchr(text,10);
  if (pcVar2 != (char *)0x0) {
    iVar4 = 2;
  }
  if (in_stack_0000000c != '\0') {
    iVar4 = 4;
  }
  lVar6 = __ftol();
  iVar3 = (int)lVar6;
  fStack_4 = alpha * 0.8;
  fStack_24 = (float)iVar3;
  puVar7 = &uStack_10;
  h = (float)(iVar4 * 0x10 + 6);
  uStack_10 = 0;
  uStack_c = 0;
  fStack_8 = 0.0;
  w = (float)(iVar1 + 0x28);
  afStack_20[1] = 64.0;
  afStack_20[0] = fStack_24;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(afStack_20,w,h);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,(float)text);
  afStack_20[0] = 64.0;
  fStack_24 = w;
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)(&fStack_24,w,h);
  afStack_20[2] = (float)text * 0.9;
  fStack_24 = 1.0;
  afStack_20[1] = 1.0;
  uStack_14 = 0x3f800000;
  afStack_20[0] = 1.0;
  uStack_c = 0x3f800000;
  uStack_10 = 0x3f800000;
  fStack_8 = afStack_20[2];
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,(float)(iVar3 + 0x14),68.0,unaff_retaddr,puVar7);
  if ((DAT_00480148 & 1) == 0) {
    DAT_00480148 = DAT_00480148 | 1;
    ui_button_table_b.enabled = '\x01';
    ui_button_table_b.force_wide = '\0';
    ui_button_table_b.force_small = '\0';
    ui_button_table_b.alpha = 1.0;
    ui_button_table_b.click_anim = 0;
    ui_button_table_b.label = (char *)0x0;
    ui_button_table_b.hovered = '\0';
    ui_button_table_b.activated = '\0';
    ui_button_table_b.hover_anim = 0;
    crt_atexit(&DAT_00408980);
  }
  ui_button_table_b.label = s_Repeat_tutorial_004722f8;
  if ((DAT_00480148 & 2) == 0) {
    DAT_00480148 = DAT_00480148 | 2;
    ui_button_table_c.enabled = '\x01';
    ui_button_table_c.force_wide = '\0';
    ui_button_table_c.force_small = '\0';
    ui_button_table_c.alpha = 1.0;
    ui_button_table_c.click_anim = 0;
    ui_button_table_c.label = (char *)0x0;
    ui_button_table_c.hovered = '\0';
    ui_button_table_c.activated = '\0';
    ui_button_table_c.hover_anim = 0;
    crt_atexit(&DAT_00408970);
  }
  ui_button_table_c.label = s_Play_a_game_004722ec;
  if (alpha._0_1_ == '\0') {
    ui_button_table_c.alpha = (float)(tutorial_stage_timer + -1000) * 0.001;
    if (ui_button_table_c.alpha <= 1.0) {
      if (ui_button_table_c.alpha < 0.0) {
        ui_button_table_c.alpha = 0.0;
      }
    }
    else {
      ui_button_table_c.alpha = 1.0;
    }
    afStack_20[0] = (float)(config_blob.screen_height + -0x32);
    ui_button_table_c.label = s_Skip_tutorial_004722dc;
    fStack_24 = 10.0;
    ui_button_update(&fStack_24,&ui_button_table_c);
    if (ui_button_table_c.activated != '\0') {
      ui_sign_crimson_update_disabled = 0;
      game_state_pending = 1;
      render_pass_mode = 0;
      ui_transition_direction = 0;
      (*grim_interface_ptr->vtable->grim_flush_input)();
      console_input_poll();
      tutorial_stage_transition_timer = 0xfffffc18;
    }
  }
  else {
    ui_button_table_c.alpha = (float)text;
    fStack_24 = (float)(iVar3 + 0x20);
    ui_button_table_b.alpha = (float)text;
    afStack_20[0] = 90.0;
    ui_button_update(&fStack_24,&ui_button_table_c);
    fStack_24 = (float)(iVar3 + 0xc0);
    afStack_20[0] = 90.0;
    ui_button_update(&fStack_24,&ui_button_table_b);
    if (ui_button_table_c.activated != '\0') {
      ui_sign_crimson_update_disabled = 0;
      game_state_pending = 1;
      render_pass_mode = 0;
      ui_transition_direction = 0;
      (*grim_interface_ptr->vtable->grim_flush_input)();
      console_input_poll();
      tutorial_stage_transition_timer = 0xfffffc18;
    }
    if (ui_button_table_b.activated != '\0') {
      player_state_table.level = 1;
      piVar5 = player_state_table.perk_counts;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar5 = 0;
        piVar5 = piVar5 + 1;
      }
      tutorial_stage_transition_timer = 0xfffffc18;
      perk_pending_count = 0;
      tutorial_stage_timer = 2000;
      return;
    }
  }
  return;
}



