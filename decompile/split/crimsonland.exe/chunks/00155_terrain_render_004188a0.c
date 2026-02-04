/* terrain_render @ 004188a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders the terrain layer from terrain_render_target (ground RT) with UV scrolling; honors
   cv_terrainFilter (point filter when value==2.0); tiles fallback when texture missing */

void terrain_render(void)

{
  float v0;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 in_stack_ffffff9c;
  uint in_stack_ffffffc4;
  int iVar5;
  float fVar6;
  
  if (*(int *)((int)cv_terrainFilter + 0xc) == 0x40000000) {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
  }
  if (terrain_texture_failed != '\0') {
    (*grim_interface_ptr->vtable->grim_bind_texture)(terrain_render_target,0);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x12,in_stack_ffffffc4 & 0xffffff00);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    iVar4 = 0;
    iVar1 = (int)(terrain_texture_height + (terrain_texture_height >> 0x1f & 0xffU)) >> 8;
    if (iVar1 != -1 && -1 < iVar1 + 1) {
      iVar5 = 0;
      iVar1 = terrain_texture_width;
      do {
        iVar3 = 0;
        iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 0xffU)) >> 8;
        if (iVar2 != -1 && -1 < iVar2 + 1) {
          fVar6 = (float)iVar5;
          iVar2 = 0;
          do {
            (*grim_interface_ptr->vtable->grim_draw_quad)
                      ((float)iVar2 + _camera_offset_x,fVar6 + _camera_offset_y,256.0,256.0);
            iVar2 = iVar2 + 0x100;
            iVar3 = iVar3 + 1;
            iVar1 = terrain_texture_width;
          } while (iVar3 < ((int)(terrain_texture_width + (terrain_texture_width >> 0x1f & 0xffU))
                           >> 8) + 1);
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x100;
      } while (iVar4 < ((int)(terrain_texture_height + (terrain_texture_height >> 0x1f & 0xffU)) >>
                       8) + 1);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
    (*grim_interface_ptr->vtable->grim_set_config_var)
              (0x12,CONCAT31((int3)((uint)in_stack_ffffff9c >> 8),1));
    return;
  }
  (*grim_interface_ptr->vtable->grim_bind_texture)(terrain_render_target,0);
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  fVar6 = -(_camera_offset_x / (float)terrain_texture_width);
  v0 = -(_camera_offset_y / (float)terrain_texture_height);
  (*grim_interface_ptr->vtable->grim_set_uv)
            (fVar6,v0,(float)config_blob.screen_width / (float)terrain_texture_width + fVar6,
             (float)config_blob.screen_height / (float)terrain_texture_height + v0);
  (*grim_interface_ptr->vtable->grim_draw_fullscreen_quad)(0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  return;
}



