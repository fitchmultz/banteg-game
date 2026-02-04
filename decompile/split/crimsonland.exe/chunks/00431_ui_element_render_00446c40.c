/* ui_element_render @ 00446c40 */

/* updates focus/click handling and renders a UI element */

void __cdecl ui_element_render(ui_element_t *element)

{
  float *pfVar1;
  float *matrix;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  char cVar5;
  float fStack_5c;
  float fStack_58;
  
  cVar5 = '\0';
  if (element->active == '\0') {
    return;
  }
  if ((element->render_scale == 0.0) && (*(float *)((int)cv_uiPointFilterPanels + 0xc) != 0.0)) {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  }
  if ((element->on_activate != (_func_1 *)0x0) && (element != (ui_element_t *)&DAT_0048f20c)) {
    iVar3 = ui_focus_update((int)element);
    cVar5 = (char)iVar3;
    if (((cVar5 != '\0') &&
        (((iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c), (char)iVar3 != '\0' &&
          (console_open_flag == '\0')) && (element->enabled != '\0')))) &&
       (element->on_activate != (_func_1 *)0x0)) {
      (*element->on_activate)();
    }
  }
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  if (element->counter_id != -1) {
    if ((cVar5 != '\0') && (0 < ui_focus_timer_ms)) {
      element->counter_value = ui_focus_timer_ms;
    }
    if (element->on_activate == (_func_1 *)0x0) {
      puVar4 = element->_pad4 + 0x13;
      iVar3 = 4;
      do {
        *puVar4 = 200;
        puVar4 = puVar4 + 0x1c;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    else {
      iVar3 = 4;
      puVar4 = element->_pad4 + 0x13;
      do {
        iVar2 = element->counter_value * 0x9b;
        iVar3 = iVar3 + -1;
        *puVar4 = (((char)(iVar2 / 1000) + (char)(iVar2 >> 0x1f)) -
                  (char)((longlong)iVar2 * 0x10624dd3 >> 0x3f)) + 'd';
        puVar4 = puVar4 + 0x1c;
      } while (iVar3 != 0);
    }
  }
  fStack_58 = 6.28412e-39;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  if (element->texture_handle != -1) {
    (*grim_interface_ptr->vtable->grim_bind_texture)(element->texture_handle,0);
    if (*(int *)(element->_pad0 + 2) == 0) {
      if (config_blob.reserved0[0xe] != '\0') {
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,1);
        (*grim_interface_ptr->vtable->grim_begin_batch)();
        pfVar1 = &element->rot_m00;
        (*grim_interface_ptr->vtable->grim_submit_vertices_transform_color)
                  (element->quad0,4,(float *)&stack0xffffff90,pfVar1,(float *)&stack0xffffffb4);
        if (element->quad_mode == 8) {
          (*grim_interface_ptr->vtable->grim_submit_vertices_transform_color)
                    (element->quad1,4,(float *)&stack0xffffff90,pfVar1,(float *)&stack0xffffffb4);
          (*grim_interface_ptr->vtable->grim_submit_vertices_transform_color)
                    (element->quad2,4,(float *)&stack0xffffff90,pfVar1,(float *)&stack0xffffffb4);
        }
        (*grim_interface_ptr->vtable->grim_end_batch)();
      }
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      matrix = &element->rot_m00;
      pfVar1 = &element->pos_x;
      (*grim_interface_ptr->vtable->grim_submit_vertices_transform)(element->quad0,4,pfVar1,matrix);
      if (element->quad_mode == 8) {
        (*grim_interface_ptr->vtable->grim_submit_vertices_transform)
                  (element->quad1,4,pfVar1,matrix);
        (*grim_interface_ptr->vtable->grim_submit_vertices_transform)
                  (element->quad2,4,pfVar1,matrix);
      }
    }
    else {
      if (*(int *)(element->_pad0 + 2) != 1) goto LAB_00447154;
      if (config_blob.reserved0[0xe] != '\0') {
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,1);
        (*grim_interface_ptr->vtable->grim_begin_batch)();
        (*grim_interface_ptr->vtable->grim_submit_vertices_offset_color)
                  (element->quad0,4,(float *)&stack0xffffff90,(float *)&stack0xffffffb4);
        if (element->quad_mode == 8) {
          (*grim_interface_ptr->vtable->grim_submit_vertices_offset_color)
                    (element->quad1,4,(float *)&stack0xffffff90,(float *)&stack0xffffffb4);
          (*grim_interface_ptr->vtable->grim_submit_vertices_offset_color)
                    (element->quad2,4,(float *)&stack0xffffff90,(float *)&stack0xffffffb4);
        }
        (*grim_interface_ptr->vtable->grim_end_batch)();
      }
      (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      (*grim_interface_ptr->vtable->grim_submit_vertices_offset)
                (element->quad0,4,(float *)&stack0xffffff90);
      if (element->quad_mode == 8) {
        (*grim_interface_ptr->vtable->grim_submit_vertices_offset)
                  (element->quad1,4,(float *)&stack0xffffff90);
        (*grim_interface_ptr->vtable->grim_submit_vertices_offset)
                  (element->quad2,4,(float *)&stack0xffffff90);
      }
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
LAB_00447154:
  if (element->counter_id != -1) {
    (*grim_interface_ptr->vtable->grim_bind_texture)(element->counter_id,0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    if (*(int *)(element->_pad0 + 2) == 0) {
      (*grim_interface_ptr->vtable->grim_submit_vertices_transform)
                ((float *)element->_pad4,4,&element->pos_x,&element->rot_m00);
    }
    else {
      fStack_5c = *(float *)(element->_pad0 + 6) + element->pos_x;
      fStack_58 = *(float *)(element->_pad0 + 10) + element->pos_y;
      (*grim_interface_ptr->vtable->grim_submit_vertices_offset)
                ((float *)element->_pad4,4,&fStack_5c);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
  if ((-1 < element->counter_timer) && (element->counter_timer < 0x100)) {
    iVar3 = 4;
    puVar4 = element->_pad5 + 0x17;
    do {
      puVar4[-0xe8] = 0xff - (char)(element->counter_timer / 2);
      iVar3 = iVar3 + -1;
      *puVar4 = 0xff - (char)(element->counter_timer / 2);
      puVar4 = puVar4 + 0x1c;
    } while (iVar3 != 0);
  }
  if (((element->enabled != '\0') && (element->counter_id != -1)) &&
     (element->on_activate != (_func_1 *)0x0)) {
    (*grim_interface_ptr->vtable->grim_bind_texture)(element->counter_id,0);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_submit_vertices_transform)
              ((float *)element->_pad4,4,&element->pos_x,(float *)&stack0xffffff8c);
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  if (*(code **)element->_pad2 != (code *)0x0) {
    (**(code **)element->_pad2)();
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  return;
}



