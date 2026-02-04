/* ui_draw_clock_gauge @ 004061e0 */

/* draws the 32x32 clock gauge at the current transform */

void ui_draw_clock_gauge(void)

{
  float unaff_EBX;
  int unaff_EDI;
  int iVar1;
  int iStack_10;
  
  iVar1 = 1;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  (*grim_interface_ptr->vtable->grim_bind_texture)(ui_clock_table_texture,0);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,unaff_EBX);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)((float)iStack_10,(float)unaff_EDI,32.0,32.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7cc,0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_set_rotation)((float)(iVar1 / 1000) * 0.10471976);
  (*grim_interface_ptr->vtable->grim_draw_quad)((float)iStack_10,(float)unaff_EDI,32.0,32.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  return;
}



