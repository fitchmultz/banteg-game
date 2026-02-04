/* ui_render_aim_enhancement @ 0041a320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders the aim enhancement overlay (cv_aimEnhancementFade-driven) */

void ui_render_aim_enhancement(void)

{
  float *pfStack_24;
  
  _DAT_004902f0 = frame_dt + _DAT_004902f0;
  _DAT_004902f4 = frame_dt * 0.6 + _DAT_004902f4;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
  (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
  effect_select_texture(0xd);
  if (1.0 < *(float *)((int)cv_aimEnhancementFade + 0xc)) {
    *(undefined4 *)((int)cv_aimEnhancementFade + 0xc) = 0x3f800000;
  }
  if (*(float *)((int)cv_aimEnhancementFade + 0xc) < 0.0) {
    *(undefined4 *)((int)cv_aimEnhancementFade + 0xc) = 0;
  }
  (*grim_interface_ptr->vtable->grim_set_color)
            (1.0,1.0,1.0,*(float *)((int)cv_aimEnhancementFade + 0xc));
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)(*pfStack_24 - 32.0,pfStack_24[1] - 32.0,64.0,64.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f79c,0);
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_color)
            (1.0,1.0,1.0,*(float *)((int)cv_aimEnhancementFade + 0xc));
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  (*grim_interface_ptr->vtable->grim_draw_quad)(*pfStack_24 - 10.0,pfStack_24[1] - 10.0,20.0,20.0);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  return;
}



