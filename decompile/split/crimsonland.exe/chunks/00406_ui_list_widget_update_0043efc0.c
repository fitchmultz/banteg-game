/* ui_list_widget_update @ 0043efc0 */

/* draws a list widget and updates selection/hover state */

int __cdecl ui_list_widget_update(float *xy,char *list)

{
  float *xy_00;
  int iVar1;
  int iVar2;
  int iVar3;
  float unaff_EBX;
  int iVar4;
  IGrim2D_vtbl *pIVar5;
  char unaff_DI;
  int iVar6;
  longlong lVar7;
  float unaff_retaddr;
  char *xy_01;
  char *stage;
  float local_1c;
  float fStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  xy_00 = xy;
  iVar4 = 0;
  iVar1 = ui_focus_update((int)list);
  iVar6 = 0;
  if (0 < *(int *)(list + 0x10)) {
    do {
      iVar2 = (*grim_interface_ptr->vtable->grim_measure_text_width)
                        (*(char **)(*(int *)(list + 0xc) + iVar6 * 4));
      if (iVar4 < iVar2) {
        iVar4 = iVar2;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(list + 0x10));
  }
  if (*list == '\0') {
    local_1c = 16.0;
    list[0x14] = '\0';
    list[4] = '\0';
    list[5] = '\0';
    list[6] = '\0';
    list[7] = '\0';
    xy = (float *)(float)(iVar4 + 0x30);
  }
  else if (*(int *)(list + 4) < 1) {
    local_1c = 16.0;
    list[0x14] = '\0';
    xy = (float *)(float)(iVar4 + 0x30);
  }
  else {
    local_1c = (float)(*(int *)(list + 0x10) * 0x10 + 0x18);
    lVar7 = __ftol();
    iVar6 = (int)lVar7;
    lVar7 = __ftol();
    iVar6 = ui_mouse_inside_rect(xy,(int)lVar7,iVar6);
    list[0x14] = (char)iVar6;
    xy = (float *)(float)(iVar4 + 0x30);
  }
  if (list[0x14] != '\0') {
    ui_focus_set((int)list,'\0');
  }
  if ((char)iVar1 != '\0') {
    fStack_18 = *xy_00 - 16.0;
    fStack_14 = xy_00[1];
    ui_focus_draw(&fStack_18);
    iVar4 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(200);
    if ((char)iVar4 != '\0') {
      if (*(int *)(list + 4) == 0) {
        list[4] = '\x01';
        list[5] = '\0';
        list[6] = '\0';
        list[7] = '\0';
      }
      else {
        iVar4 = *(int *)(list + 0x18);
        *(int *)(list + 0x18) = iVar4 + -1;
        if (iVar4 + -1 < 0) {
          list[0x18] = '\0';
          list[0x19] = '\0';
          list[0x1a] = '\0';
          list[0x1b] = '\0';
        }
      }
    }
    iVar4 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xd0);
    if ((char)iVar4 != '\0') {
      if (*(int *)(list + 4) == 0) {
        list[4] = '\x01';
        list[5] = '\0';
        list[6] = '\0';
        list[7] = '\0';
      }
      else {
        iVar4 = *(int *)(list + 0x18);
        *(int *)(list + 0x18) = iVar4 + 1;
        if (*(int *)(list + 0x10) + -1 < iVar4 + 1) {
          *(int *)(list + 0x18) = *(int *)(list + 0x10) + -1;
        }
      }
    }
  }
  uStack_10 = 0x3f800000;
  uStack_c = 0x3f800000;
  uStack_8 = 0x3f800000;
  uStack_4 = 0x3f800000;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(xy_00,(float)xy,local_1c);
  local_1c = *xy_00 + 1.0;
  fStack_18 = xy_00[1] + 1.0;
  fStack_14 = 0.0;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0x3f800000;
  xy_01 = (char *)&local_1c;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)
            ((float *)xy_01,unaff_retaddr - 2.0,unaff_EBX - 2.0);
  if ((*(int *)(list + 4) < 1) && (list[0x14] == '\0')) {
    stage = s_ui_dropOff_00474134;
    pIVar5 = grim_interface_ptr->vtable;
  }
  else {
    local_1c = xy_00[1] + 15.0;
    fStack_18 = 1.0;
    fStack_14 = 1.0;
    uStack_10 = 0x3f800000;
    uStack_c = 0x3f000000;
    (*grim_interface_ptr->vtable->grim_draw_rect_filled)((float *)&stack0xffffffe0,(float)xy,1.0);
    stage = (char *)0x0;
    xy_01 = s_ui_dropOn_00474158;
    pIVar5 = grim_interface_ptr->vtable;
  }
  iVar4 = (*pIVar5->grim_get_texture_handle)(xy_01);
  (*pIVar5->grim_bind_texture)(iVar4,(int)stage);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)
            (((local_1c + *xy_00) - 16.0) - 1.0,xy_00[1],16.0,16.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  iVar4 = -2;
  if (*list != '\0') {
    lVar7 = __ftol();
    iVar1 = FUN_00403430(xy_00,0xe,(int)lVar7);
    if ((char)iVar1 != '\0') {
      iVar4 = -1;
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.95);
      goto LAB_0043f3aa;
    }
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.75);
LAB_0043f3aa:
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,*xy_00 + 4.0,xy_00[1] + 1.0,&s_fmt_percent_s,
             *(undefined4 *)(*(int *)(list + 0xc) + *(int *)(list + 8) * 4));
  if (*(int *)(list + 4) < 1) {
    return iVar4;
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.7);
  iVar4 = 0;
  if (0 < *(int *)(list + 0x10)) {
    lVar7 = __ftol();
    iVar1 = (int)lVar7;
    iVar6 = 0;
    do {
      iVar2 = iVar6;
      iVar3 = FUN_00403430((float *)&stack0xffffffbc,0xe,iVar1);
      if ((char)iVar3 == '\0') {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.6);
      }
      else {
        *(int *)(list + 0x18) = iVar4;
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.95);
      }
      if ((unaff_DI != '\0') && (*(int *)(list + 0x18) == iVar4)) {
        (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.96);
      }
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,*xy_00 + 4.0,(float)iVar2 + xy_00[1] + 17.0,&s_fmt_percent_s,
                 *(undefined4 *)(*(int *)(list + 0xc) + iVar4 * 4));
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0x10;
    } while (iVar4 < *(int *)(list + 0x10));
  }
  if ((list[0x14] == '\0') && (unaff_DI == '\0')) {
    list[4] = '\0';
    list[5] = '\0';
    list[6] = '\0';
    list[7] = '\0';
  }
  return *(int *)(list + 0x18);
}



