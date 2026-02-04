/* terrain_generate @ 00417b80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* generates terrain texture into a render target using a level descriptor */

void __cdecl terrain_generate(void *desc)

{
  IGrim2D_vtbl *pIVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fStack_58;
  float fStack_54;
  undefined4 uStack_50;
  int iVar5;
  undefined4 in_stack_ffffffcc;
  
  _camera_offset_x = 0;
  _camera_offset_y = 0;
  if (terrain_texture_failed == '\0') {
    (*grim_interface_ptr->vtable->grim_set_config_var)
              (0x12,CONCAT31((int3)((uint)in_stack_ffffffcc >> 8),1));
    iVar5 = 0x13;
    uStack_50 = 0x417c0c;
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_render_target)((int)terrain_render_target);
    (*grim_interface_ptr->vtable->grim_clear_color)(0.24705882,0.21960784,0.09803922,1.0);
    (*grim_interface_ptr->vtable->grim_bind_texture)
              ((&terrain_texture_handles)[*(int *)(iVar5 + 0x10)],0);
    (*grim_interface_ptr->vtable->grim_set_color)(0.7,0.7,0.7,0.9);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    iVar3 = 0;
    iVar2 = terrain_texture_height * terrain_texture_width * 800;
    if (0 < (int)(iVar2 + (iVar2 >> 0x1f & 0x7ffffU)) >> 0x13) {
      do {
        pIVar1 = grim_interface_ptr->vtable;
        iVar2 = crt_rand();
        (*pIVar1->grim_set_rotation)((float)(iVar2 % 0x13a) * 0.01);
        iVar2 = crt_rand();
        fVar4 = (float)(iVar2 % (terrain_texture_width + 0x80)) - 64.0;
        iVar2 = crt_rand();
        fStack_58 = ((float)(iVar2 % (terrain_texture_width + 0x80)) - 64.0) * 6.01384e-39;
        fStack_54 = fVar4 * 6.01384e-39;
        (*grim_interface_ptr->vtable->grim_draw_quad_xy)(&fStack_58,7.697716e-37,7.697716e-37);
        iVar3 = iVar3 + 1;
        iVar2 = terrain_texture_height * terrain_texture_width * 800;
      } while (iVar3 < (int)(iVar2 + (iVar2 >> 0x1f & 0x7ffffU)) >> 0x13);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_bind_texture)
              ((&terrain_texture_handles)[*(int *)(iVar5 + 0x14)],0);
    (*grim_interface_ptr->vtable->grim_set_color)(0.7,0.7,0.7,0.9);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    iVar3 = 0;
    iVar2 = terrain_texture_height * terrain_texture_width * 0x23;
    if (0 < (int)(iVar2 + (iVar2 >> 0x1f & 0x7ffffU)) >> 0x13) {
      do {
        pIVar1 = grim_interface_ptr->vtable;
        iVar2 = crt_rand();
        (*pIVar1->grim_set_rotation)((float)(iVar2 % 0x13a) * 0.01);
        iVar2 = crt_rand();
        fVar4 = (float)(iVar2 % (terrain_texture_width + 0x80)) - 64.0;
        iVar2 = crt_rand();
        fStack_58 = ((float)(iVar2 % (terrain_texture_width + 0x80)) - 64.0) * 6.01384e-39;
        fStack_54 = fVar4 * 6.01384e-39;
        (*grim_interface_ptr->vtable->grim_draw_quad_xy)(&fStack_58,7.697716e-37,7.697716e-37);
        iVar3 = iVar3 + 1;
        iVar2 = terrain_texture_height * terrain_texture_width * 0x23;
      } while (iVar3 < (int)(iVar2 + (iVar2 >> 0x1f & 0x7ffffU)) >> 0x13);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_bind_texture)
              ((&terrain_texture_handles)[*(int *)(iVar5 + 0x18)],0);
    (*grim_interface_ptr->vtable->grim_set_color)(0.7,0.7,0.7,0.6);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    iVar3 = 0;
    iVar2 = terrain_texture_height * terrain_texture_width * 0xf;
    if (0 < (int)(iVar2 + (iVar2 >> 0x1f & 0x7ffffU)) >> 0x13) {
      do {
        pIVar1 = grim_interface_ptr->vtable;
        iVar2 = crt_rand();
        (*pIVar1->grim_set_rotation)((float)(iVar2 % 0x13a) * 0.01);
        iVar2 = crt_rand();
        fVar4 = (float)(iVar2 % (terrain_texture_width + 0x80)) - 64.0;
        iVar2 = crt_rand();
        fStack_58 = ((float)(iVar2 % (terrain_texture_width + 0x80)) - 64.0) * 6.01384e-39;
        fStack_54 = fVar4 * 6.01384e-39;
        (*grim_interface_ptr->vtable->grim_draw_quad_xy)(&fStack_58,7.697716e-37,7.697716e-37);
        iVar3 = iVar3 + 1;
        iVar2 = terrain_texture_height * terrain_texture_width * 0xf;
      } while (iVar3 < (int)(iVar2 + (iVar2 >> 0x1f & 0x7ffffU)) >> 0x13);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
    _camera_offset_x = 0;
    _camera_offset_y = 0;
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,1);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
    (*grim_interface_ptr->vtable->grim_set_render_target)(-1);
    return;
  }
  terrain_render_target = (float)(&terrain_texture_handles)[*(int *)((int)desc + 0x10)];
  return;
}



