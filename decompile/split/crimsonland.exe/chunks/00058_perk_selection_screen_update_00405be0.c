/* perk_selection_screen_update @ 00405be0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* perk selection screen: list choices, preview text, and selection handling */

void perk_selection_screen_update(void)

{
  int x;
  undefined4 *puVar1;
  int iVar2;
  float unaff_EBX;
  int *piVar3;
  int *item;
  longlong lVar4;
  int y;
  int w;
  char cVar5;
  undefined4 uStack_28;
  uint local_24;
  float local_20;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_4;
  
  gameplay_render_world();
  ui_elements_update_and_render();
  local_4 = _DAT_0048c634 + DAT_0048c658;
  local_20 = 19.0;
  uStack_28 = (float)(uint)(uint3)uStack_28;
  local_24 = 5;
  local_14 = local_4 + 40.0;
  local_18 = _DAT_0048c620 + DAT_0048c654 + _DAT_0048c630 + 180.0 + 44.0;
  local_10 = local_18;
  local_c = local_14;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  w = 0x20;
  y = 0x80;
  iVar2 = DAT_0048f800;
  lVar4 = __ftol();
  x = (int)lVar4;
  lVar4 = __ftol();
  ui_draw_textured_quad((int)lVar4,x,y,w,iVar2);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.5);
  if (player_state_table.perk_counts[perk_id_perk_master] < 1) {
    if (0 < player_state_table.perk_counts[perk_id_perk_expert]) {
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,local_18 - 26.0,local_14 - 8.0,
                 s_extra_perk_sponsored_by_the_Perk_00472018);
      local_24 = 6;
    }
  }
  else {
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,local_18 - 28.0,local_14 - 8.0,
               s_extra_perks_sponsored_by_the_Per_00472040);
    local_24 = 7;
  }
  if (player_state_table.perk_counts[perk_id_perk_expert] < 1) {
    local_14 = local_14 + 50.0;
  }
  else {
    local_14 = local_14 + 40.0;
    local_20 = 18.0;
  }
  if (((byte)perk_selection_screen_flags & 1) == 0) {
    perk_selection_screen_flags._0_1_ = (byte)perk_selection_screen_flags | 1;
    _DAT_00480298 = 0x3e8c8c8d;
    _DAT_0048029c = 0x3f34b4b5;
    _DAT_004802a0 = 0x3f70f0f1;
    _DAT_004802a4 = 0x3f19999a;
    crt_atexit(&DAT_00406170);
  }
  if (((byte)perk_selection_screen_flags & 2) == 0) {
    perk_selection_screen_flags._0_1_ = (byte)perk_selection_screen_flags | 2;
    _DAT_00480310 = 0x3e8c8c8d;
    _DAT_00480314 = 0x3f34b4b5;
    _DAT_00480318 = 0x3f70f0f1;
    _DAT_0048031c = 0x3f800000;
    crt_atexit(&DAT_00406160);
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  if (((byte)perk_selection_screen_flags & 4) == 0) {
    perk_selection_screen_flags._0_1_ = (byte)perk_selection_screen_flags | 4;
    iVar2 = 10;
    puVar1 = &DAT_004800b4;
    do {
      *(undefined1 *)((int)puVar1 + -6) = 1;
      *puVar1 = 0x3f800000;
      puVar1[-3] = 0;
      *(undefined1 *)(puVar1 + -2) = 0;
      *(undefined1 *)((int)puVar1 + -7) = 0;
      puVar1[-1] = 0;
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    crt_atexit(&DAT_00406150);
  }
  iVar2 = 0;
  if (local_24 != 0) {
    item = &DAT_004800a8;
    piVar3 = &perk_choice_ids;
    do {
      *item = (int)(&perk_meta_table)[*piVar3].name;
      ui_menu_item_update(&local_18,item);
      if ((char)item[1] != '\0') {
        uStack_28 = (float)CONCAT13(1,(uint3)uStack_28);
        perk_selection_index = iVar2;
      }
      local_14 = local_14 + local_20;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
      item = item + 4;
    } while (iVar2 < (int)local_24);
  }
  local_14 = local_14 + 32.0;
  if (5 < local_24) {
    local_14 = local_14 - 20.0;
  }
  local_18 = local_18 - 28.0;
  cVar5 = '?';
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  (*grim_interface_ptr->vtable->grim_draw_text_small)
            (unaff_EBX + 16.0,uStack_28,
             (&perk_meta_table)[(&perk_choice_ids)[perk_selection_index]].description);
  if (((byte)perk_selection_screen_flags & 8) == 0) {
    perk_selection_screen_flags._0_1_ = (byte)perk_selection_screen_flags | 8;
    DAT_00480096 = 1;
    DAT_004800a5 = 0;
    DAT_004800a4 = 0;
    _DAT_004800a0 = 0x3f800000;
    _DAT_0048009c = 0;
    _DAT_00480090 = (char *)0x0;
    DAT_00480094 = 0;
    DAT_00480095 = 0;
    _DAT_00480098 = 0;
    crt_atexit(&DAT_00406140);
  }
  _DAT_00480090 = s_Cancel_00472010;
  if (((byte)perk_selection_screen_flags & 0x10) == 0) {
    perk_selection_screen_flags._0_1_ = (byte)perk_selection_screen_flags | 0x10;
    DAT_00480826 = 1;
    DAT_00480835 = 0;
    DAT_00480834 = 0;
    _DAT_00480830 = 0x3f800000;
    _DAT_0048082c = 0;
    _DAT_00480820 = (char *)0x0;
    DAT_00480824 = 0;
    DAT_00480825 = 0;
    _DAT_00480828 = 0;
    crt_atexit(&DAT_00406130);
  }
  _DAT_00480820 = s_Select_00472008;
  iVar2 = ui_button_update((float *)&stack0xffffffcc,(ui_button_t *)&DAT_00480090);
  if ((char)iVar2 != '\0') {
    ui_transition_direction = 0;
    game_state_pending = 9;
  }
  perk_prompt_update_and_render();
  ui_cursor_render();
  if (((cVar5 != '\0') && (-1 < perk_selection_index)) &&
     ((&DAT_004800ad)[perk_selection_index * 0x10] != '\0')) {
    sfx_play(sfx_ui_buttonclick);
    perk_apply((&perk_choice_ids)[perk_selection_index]);
    perk_pending_count = perk_pending_count + -1;
    ui_transition_direction = 0;
    game_state_pending = 9;
    perk_choices_dirty = 1;
  }
  return;
}



