/* FUN_0043d9b0 @ 0043d9b0 */

/* [binja] int32_t sub_43d9b0(int32_t* arg1, int32_t arg2) */

int __cdecl FUN_0043d9b0(int *arg1,int arg2)

{
  float y;
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  longlong lVar5;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = arg2;
  iVar2 = ui_focus_update(arg2);
  local_8 = (float)*arg1;
  local_10 = (float)*arg1 - 3.0;
  y = (float)arg1[1];
  local_c = (float)arg1[1] - 1.0;
  lVar5 = __ftol();
  iVar3 = ui_mouse_inside_rect(&local_10,0x12,(int)lVar5);
  bVar4 = (char)iVar3 != '\0';
  if (bVar4) {
    ui_focus_set(arg2,'\0');
  }
  if ((char)iVar2 != '\0') {
    local_10 = (float)*arg1 - 16.0;
    local_c = (float)arg1[1];
    ui_focus_draw(&local_10);
    if (*(char *)(arg2 + 0xc) != '\0') {
      iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xcd);
      if ((char)iVar2 != '\0') {
        iVar2 = *(int *)arg2;
        *(int *)arg2 = iVar2 + 1;
        if (*(int *)(arg2 + 4) < iVar2 + 1) {
          *(int *)arg2 = *(int *)(arg2 + 4);
        }
      }
      iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xcb);
      if (((char)iVar2 != '\0') && (iVar2 = *(int *)arg2, *(int *)arg2 = iVar2 + -1, iVar2 + -1 < 0)
         ) {
        *(undefined4 *)arg2 = 0;
      }
    }
  }
  if (bVar4) {
    iVar2 = input_primary_is_down();
    if (((char)iVar2 != '\0') && (*(char *)(arg2 + 0xc) != '\0')) {
      lVar5 = __ftol();
      *(int *)arg2 = (int)lVar5;
      if ((int)lVar5 < *(int *)(arg2 + 8)) {
        *(int *)arg2 = *(int *)(arg2 + 8);
      }
      if (*(int *)(arg2 + 4) < *(int *)arg2) {
        *(int *)arg2 = *(int *)(arg2 + 4);
      }
    }
  }
  if (DAT_00478668 == -1) {
    DAT_00478668 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_ui_rectOn_004743f4);
  }
  if (DAT_0047866c == -1) {
    DAT_0047866c = (*grim_interface_ptr->vtable->grim_get_texture_handle)(s_ui_rectOff_00474414);
  }
  (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0047866c,0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.5);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  iVar2 = 0;
  if (0 < *(int *)(arg2 + 4)) {
    arg2 = 0;
    do {
      (*grim_interface_ptr->vtable->grim_draw_quad)((float)arg2 + local_8,y,8.0,16.0);
      iVar2 = iVar2 + 1;
      arg2 = arg2 + 8;
    } while (iVar2 < *(int *)(iVar1 + 4));
  }
  iVar2 = (*grim_interface_ptr->vtable->grim_end_batch)();
  if (0 < *(int *)iVar1) {
    (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_00478668,0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
    iVar2 = 0;
    if (0 < *(int *)iVar1) {
      arg2 = 0;
      do {
        (*grim_interface_ptr->vtable->grim_draw_quad)((float)arg2 + local_8,y,8.0,16.0);
        iVar2 = iVar2 + 1;
        arg2 = arg2 + 8;
      } while (iVar2 < *(int *)iVar1);
    }
    iVar2 = (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  return iVar2;
}



