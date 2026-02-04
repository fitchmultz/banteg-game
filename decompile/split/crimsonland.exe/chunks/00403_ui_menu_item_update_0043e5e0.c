/* ui_menu_item_update @ 0043e5e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* draws a text menu item, updates hover/press state, and returns 1 when activated */

int __cdecl ui_menu_item_update(float *xy,int *item)

{
  int *id;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined3 uVar4;
  longlong lVar5;
  float local_8;
  float local_4;
  
  id = item;
  iVar1 = ui_focus_update((int)item);
  if ((DAT_004cc910 & 1) == 0) {
    DAT_004cc910 = DAT_004cc910 | 1;
    _DAT_004ccd40 = 0x3e8c8c8d;
    _DAT_004ccd44 = 0x3f34b4b5;
    _DAT_004ccd48 = 0x3f70f0f1;
    _DAT_004ccd4c = 0x3f19999a;
    crt_atexit(&DAT_0043e820);
  }
  if ((DAT_004cc910 & 2) == 0) {
    DAT_004cc910 = DAT_004cc910 | 2;
    _DAT_004d0e28 = 0x3e8c8c8d;
    _DAT_004d0e2c = 0x3f34b4b5;
    _DAT_004d0e30 = 0x3f70f0f1;
    _DAT_004d0e34 = 0x3f800000;
    crt_atexit(&DAT_0043e810);
  }
  if ((char)iVar1 != '\0') {
    local_8 = *xy - 16.0;
    local_4 = xy[1];
    ui_focus_draw(&local_8);
  }
  iVar2 = (*grim_interface_ptr->vtable->grim_measure_text_width)((char *)*item);
  item = (int *)(float)iVar2;
  if ((float)item <= 0.0) {
    item = (int *)0x41000000;
  }
  lVar5 = __ftol();
  iVar2 = ui_mouse_inside_rect(xy,0x10,(int)lVar5);
  *(char *)(id + 1) = (char)iVar2;
  if ((char)iVar2 == '\0') {
    (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004ccd40);
  }
  else {
    ui_focus_set((int)id,'\0');
    (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004d0e28);
  }
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,*xy,xy[1],&s_fmt_percent_s,*id);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  local_8 = *xy;
  local_4 = xy[1] + 13.0;
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)(&local_8,(float)item,1.0);
  uVar3 = (*grim_interface_ptr->vtable->grim_end_batch)();
  uVar4 = (undefined3)((uint)uVar3 >> 8);
  if (*(char *)((int)id + 6) == '\0') {
    *(undefined1 *)((int)id + 5) = 0;
    goto LAB_0043e7e0;
  }
  if ((char)iVar1 != '\0') {
    iVar1 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c);
    if ((char)iVar1 != '\0') {
LAB_0043e7cb:
      uVar4 = 0;
      *(undefined1 *)((int)id + 5) = 1;
      goto LAB_0043e7e0;
    }
    if ((char)id[1] != '\0') {
      iVar1 = input_primary_just_pressed();
      if ((char)iVar1 != '\0') goto LAB_0043e7cb;
    }
  }
  uVar4 = 0;
  *(undefined1 *)((int)id + 5) = 0;
LAB_0043e7e0:
  iVar1 = CONCAT31(uVar4,*(char *)((int)id + 5));
  if (*(char *)((int)id + 5) != '\0') {
    iVar1 = sfx_play(sfx_ui_buttonclick);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),*(undefined1 *)((int)id + 5));
}



