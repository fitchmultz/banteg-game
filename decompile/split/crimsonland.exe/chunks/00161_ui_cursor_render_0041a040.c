/* ui_cursor_render @ 0041a040 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders the in-game cursor/crosshair sprites */

void ui_cursor_render(void)

{
  IGrim2D_vtbl *pIVar1;
  float10 extraout_ST0;
  
  _DAT_004902e8 = frame_dt + _DAT_004902e8;
  _DAT_004902ec = frame_dt * 1.1 + _DAT_004902ec;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
  (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
  effect_select_texture(0xd);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  fsin((float10)_DAT_004902ec);
  pIVar1 = grim_interface_ptr->vtable;
  crt_ci_pow();
  (*pIVar1->grim_set_color)(1.0,1.0,1.0,(float)((extraout_ST0 + (float10)2.0) * (float10)0.32));
  (*grim_interface_ptr->vtable->grim_draw_quad)(ui_mouse_x - 28.0,ui_mouse_y - 28.0,64.0,64.0);
  (*grim_interface_ptr->vtable->grim_draw_quad)(ui_mouse_x - 10.0,ui_mouse_y - 18.0,64.0,64.0);
  (*grim_interface_ptr->vtable->grim_draw_quad)(ui_mouse_x - 18.0,ui_mouse_y - 10.0,64.0,64.0);
  (*grim_interface_ptr->vtable->grim_draw_quad)
            ((ui_mouse_x - 64.0) + 16.0,(ui_mouse_y - 64.0) + 16.0,128.0,128.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f798,0);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)(ui_mouse_x - 2.0,ui_mouse_y - 2.0,32.0,32.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  return;
}



