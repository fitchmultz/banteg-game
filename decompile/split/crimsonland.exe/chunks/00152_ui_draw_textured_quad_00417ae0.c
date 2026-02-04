/* ui_draw_textured_quad @ 00417ae0 */

/* binds a texture and draws a screen-space quad */

void ui_draw_textured_quad(int texture_id,int x,int y,int w,int h)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  (*grim_interface_ptr->vtable->grim_bind_texture)(h,0);
  iVar4 = 0x3f800000;
  iVar3 = 0x3f800000;
  iVar2 = 0;
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  iVar1 = 1;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  (*grim_interface_ptr->vtable->grim_draw_quad)((float)iVar1,(float)iVar2,(float)iVar3,(float)iVar4)
  ;
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  return;
}



