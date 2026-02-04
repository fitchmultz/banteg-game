/* ui_checkbox_update @ 0043dc80 */

/* draws a checkbox widget, handles hover/focus, toggles on click */

int __cdecl ui_checkbox_update(float *xy,char *checkbox)

{
  IGrim2D_vtbl *pIVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int handle;
  undefined4 uVar5;
  undefined1 uStack_45;
  char *name;
  float fStack_8;
  float fStack_4;
  
  iVar3 = ui_focus_update((int)checkbox);
  checkbox[2] = '\0';
  if (*(char **)(checkbox + 4) == (char *)0x0) {
    iVar4 = ui_mouse_inside_rect(xy,0x10,0x10);
    cVar2 = (char)iVar4;
  }
  else {
    iVar4 = (*grim_interface_ptr->vtable->grim_measure_text_width)(*(char **)(checkbox + 4));
    iVar4 = ui_mouse_inside_rect(xy,0x10,iVar4 + 0x16);
    cVar2 = (char)iVar4;
  }
  if (cVar2 != '\0') {
    checkbox[2] = '\x01';
  }
  if (checkbox[1] != '\0') {
    checkbox[2] = '\0';
  }
  if (checkbox[2] != '\0') {
    ui_focus_set((int)checkbox,'\0');
  }
  if ((char)iVar3 != '\0') {
    fStack_8 = *xy - 16.0;
    fStack_4 = xy[1];
    ui_focus_draw(&fStack_8);
  }
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  pIVar1 = grim_interface_ptr->vtable;
  iVar4 = 0;
  if (*checkbox == '\0') {
    name = s_ui_checkOff_00474434;
  }
  else {
    name = s_ui_checkOn_00474454;
  }
  handle = (*pIVar1->grim_get_texture_handle)(name);
  (*pIVar1->grim_bind_texture)(handle,iVar4);
  if ((DAT_004871ca == '\0') &&
     ((((char)iVar3 != '\0' &&
       (iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c), (char)iVar3 != '\0')) ||
      ((checkbox[2] != '\0' && (iVar3 = input_primary_just_pressed(), (char)iVar3 != '\0')))))) {
    *checkbox = *checkbox == '\0';
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  (*grim_interface_ptr->vtable->grim_draw_quad)(*xy,xy[1],16.0,16.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  if (checkbox[2] == '\0') {
    uVar5 = (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.7);
  }
  else {
    uVar5 = (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  }
  if (*(char **)(checkbox + 4) != (char *)0x0) {
    uVar5 = (*grim_interface_ptr->vtable->grim_draw_text_small)
                      (*xy + 22.0,xy[1] + 1.0,*(char **)(checkbox + 4));
  }
  return CONCAT31((int3)((uint)uVar5 >> 8),uStack_45);
}



