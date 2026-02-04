/* terrain_generate_random @ 004181b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* selects a terrain variant and generates the terrain texture */

void terrain_generate_random(void)

{
  IGrim2D_vtbl *pIVar1;
  float handle;
  int iVar2;
  int iVar3;
  float fVar4;
  float fStack_64;
  float fStack_60;
  int iStack_54;
  undefined4 in_stack_ffffffbc;
  
  _DAT_0048f53c = crt_rand();
  _DAT_0048f53c = _DAT_0048f53c % 7;
  _DAT_0048f540 = crt_rand();
  _DAT_0048f540 = _DAT_0048f540 % 7;
  crt_rand();
  handle = DAT_0048f54c;
  fVar4 = terrain_texture_handles;
  _DAT_0048f53c = 0;
  _DAT_0048f540 = 1;
  _DAT_0048f544 = 0;
  if ((0x27 < game_status_blob.quest_unlock_index) && (iVar2 = crt_rand(), ((byte)iVar2 & 7) == 3))
  {
    terrain_generate(&DAT_00484c84);
    return;
  }
  if ((0x1d < game_status_blob.quest_unlock_index) && (iVar2 = crt_rand(), ((byte)iVar2 & 7) == 3))
  {
    terrain_generate(&DAT_00484acc);
    return;
  }
  if ((0x13 < game_status_blob.quest_unlock_index) && (iVar2 = crt_rand(), ((byte)iVar2 & 7) == 3))
  {
    terrain_generate(&DAT_00484914);
    return;
  }
  _camera_offset_y = 0;
  _camera_offset_x = 0;
  if (terrain_texture_failed == '\0') {
    (*grim_interface_ptr->vtable->grim_set_config_var)
              (0x12,CONCAT31((int3)((uint)in_stack_ffffffbc >> 8),1));
    fStack_60 = 6.01629e-39;
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
    (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
    (*grim_interface_ptr->vtable->grim_set_render_target)(terrain_render_target);
    (*grim_interface_ptr->vtable->grim_clear_color)(0.24705882,0.21960784,0.09803922,1.0);
    (*grim_interface_ptr->vtable->grim_bind_texture)((int)fVar4,0);
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
        fStack_64 = ((float)(iVar2 % (terrain_texture_width + 0x80)) - 64.0) * 6.016324e-39;
        fStack_60 = fVar4 * 6.016324e-39;
        (*grim_interface_ptr->vtable->grim_draw_quad_xy)(&fStack_64,7.700894e-37,7.700894e-37);
        iVar3 = iVar3 + 1;
        iVar2 = terrain_texture_height * terrain_texture_width * 800;
      } while (iVar3 < (int)(iVar2 + (iVar2 >> 0x1f & 0x7ffffU)) >> 0x13);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_bind_texture)((int)handle,0);
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
        fStack_64 = ((float)(iVar2 % (terrain_texture_width + 0x80)) - 64.0) * 6.016324e-39;
        fStack_60 = fVar4 * 6.016324e-39;
        (*grim_interface_ptr->vtable->grim_draw_quad_xy)(&fStack_64,7.700894e-37,7.700894e-37);
        iVar3 = iVar3 + 1;
        iVar2 = terrain_texture_height * terrain_texture_width * 0x23;
      } while (iVar3 < (int)(iVar2 + (iVar2 >> 0x1f & 0x7ffffU)) >> 0x13);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_bind_texture)(iStack_54,0);
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
        fStack_64 = ((float)(iVar2 % (terrain_texture_width + 0x80)) - 64.0) * 6.016324e-39;
        fStack_60 = fVar4 * 6.016324e-39;
        (*grim_interface_ptr->vtable->grim_draw_quad_xy)(&fStack_64,7.700894e-37,7.700894e-37);
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
    if (*(float *)((int)cv_verbose + 0xc) != 0.0) {
      console_printf(&console_log_queue,s_____Generated_terrain__0047377a + 2);
    }
  }
  return;
}



