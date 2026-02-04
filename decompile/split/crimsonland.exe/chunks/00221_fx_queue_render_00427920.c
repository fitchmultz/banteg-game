/* fx_queue_render @ 00427920 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* bakes FX queues (DAT_004aaf18/DAT_004aaf3c) into the ground render target (terrain_render_target)
   and clears them */

void fx_queue_render(void)

{
  int iVar1;
  float w;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  float fVar5;
  
  fVar5 = 1.0 / (float)config_blob.reserved0._112_4_;
  if (terrain_texture_failed == '\0') {
    if ((fx_queue_rotated != 0) || (fx_queue_count != 0)) {
      (*grim_interface_ptr->vtable->grim_set_render_target)(terrain_render_target);
      (*grim_interface_ptr->vtable->grim_bind_texture)(particles_texture,0);
      if (0 < fx_queue_count) {
        (*grim_interface_ptr->vtable->grim_begin_batch)();
        (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
        iVar3 = 0;
        if (0 < fx_queue_count) {
          pfVar2 = &fx_queue.rotation;
          do {
            (*grim_interface_ptr->vtable->grim_set_color_ptr)(pfVar2 + 5);
            (*grim_interface_ptr->vtable->grim_set_rotation)(*pfVar2);
            effect_select_texture(((fx_queue_entry_t *)(pfVar2 + -1))->effect_id);
            (*grim_interface_ptr->vtable->grim_draw_quad)
                      ((pfVar2[1] - pfVar2[4] * 0.5) * fVar5,(pfVar2[2] - pfVar2[3] * 0.5) * fVar5,
                       fVar5 * pfVar2[4],fVar5 * pfVar2[3]);
            iVar3 = iVar3 + 1;
            pfVar2 = pfVar2 + 10;
          } while (iVar3 < fx_queue_count);
        }
        (*grim_interface_ptr->vtable->grim_end_batch)();
      }
      if (0 < fx_queue_rotated) {
        (*grim_interface_ptr->vtable->grim_bind_texture)(bodyset_texture,0);
        fVar5 = 2.66247e-44;
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,1);
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
        (*grim_interface_ptr->vtable->grim_begin_batch)();
        iVar3 = 0;
        if (0 < fx_queue_rotated) {
          pfVar2 = (float *)&fx_rotated_pos_x;
          pfVar4 = (float *)&fx_rotated_color_b;
          do {
            iVar1 = (&creature_type_table)[(&fx_rotated_effect_id)[iVar3]].corpse_frame;
            render_scratch_f0 = (&effect_uv4)[iVar1].u;
            render_scratch_f1 = (&effect_uv4)[iVar1].v;
            render_scratch_f2 = (&effect_uv4)[iVar1].u + 0.25;
            render_scratch_f3 = (&effect_uv4)[iVar1].v + 0.25;
            (*grim_interface_ptr->vtable->grim_set_uv)
                      (render_scratch_f0,render_scratch_f1,render_scratch_f2,render_scratch_f3);
            (*grim_interface_ptr->vtable->grim_set_color)
                      (pfVar4[-2],pfVar4[-1],*pfVar4,pfVar4[1] * 0.5);
            (*grim_interface_ptr->vtable->grim_set_rotation)
                      ((float)(&fx_rotated_rotation)[iVar3] - 1.5707964);
            render_scratch_f0 = *pfVar2 - 0.5;
            render_scratch_f1 = pfVar2[1] - 0.5;
            w = (float)(&fx_rotated_scale)[iVar3] * 6.106354e-39 * 1.064;
            (*grim_interface_ptr->vtable->grim_draw_quad)
                      (render_scratch_f0 * 6.106354e-39 - fVar5,
                       render_scratch_f1 * 6.106354e-39 - fVar5,w,w);
            iVar3 = iVar3 + 1;
            pfVar4 = pfVar4 + 4;
            pfVar2 = pfVar2 + 2;
          } while (iVar3 < fx_queue_rotated);
        }
        (*grim_interface_ptr->vtable->grim_end_batch)();
        fVar5 = 2.66247e-44;
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
        (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
        (*grim_interface_ptr->vtable->grim_begin_batch)();
        iVar3 = 0;
        if (0 < fx_queue_rotated) {
          pfVar2 = (float *)&fx_rotated_pos_x;
          pfVar4 = (float *)&fx_rotated_color_b;
          do {
            iVar1 = (&creature_type_table)[(&fx_rotated_effect_id)[iVar3]].corpse_frame;
            render_scratch_f0 = (&effect_uv4)[iVar1].u;
            render_scratch_f1 = (&effect_uv4)[iVar1].v;
            render_scratch_f2 = (&effect_uv4)[iVar1].u + 0.25;
            render_scratch_f3 = (&effect_uv4)[iVar1].v + 0.25;
            (*grim_interface_ptr->vtable->grim_set_uv)
                      (render_scratch_f0,render_scratch_f1,render_scratch_f2,render_scratch_f3);
            (*grim_interface_ptr->vtable->grim_set_color)(pfVar4[-2],pfVar4[-1],*pfVar4,pfVar4[1]);
            (*grim_interface_ptr->vtable->grim_set_rotation)
                      ((float)(&fx_rotated_rotation)[iVar3] - 1.5707964);
            (*grim_interface_ptr->vtable->grim_draw_quad)
                      (*pfVar2 * 6.106968e-39 - fVar5,pfVar2[1] * 6.106968e-39 - fVar5,
                       (float)(&fx_rotated_scale)[iVar3] * 6.106968e-39,
                       (float)(&fx_rotated_scale)[iVar3] * 6.106968e-39);
            iVar3 = iVar3 + 1;
            pfVar4 = pfVar4 + 4;
            pfVar2 = pfVar2 + 2;
          } while (iVar3 < fx_queue_rotated);
        }
        (*grim_interface_ptr->vtable->grim_end_batch)();
      }
      fx_queue_count = 0;
      fx_queue_rotated = 0;
      (*grim_interface_ptr->vtable->grim_set_render_target)(-1);
    }
  }
  else if (0 < fx_queue_rotated) {
    (*grim_interface_ptr->vtable->grim_bind_texture)(bodyset_texture,0);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,1);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    iVar3 = 0;
    if (0 < fx_queue_rotated) {
      pfVar2 = (float *)&fx_rotated_pos_x;
      pfVar4 = (float *)&fx_rotated_color_b;
      do {
        iVar1 = (&creature_type_table)[(&fx_rotated_effect_id)[iVar3]].corpse_frame;
        render_scratch_f0 = (&effect_uv4)[iVar1].u;
        render_scratch_f1 = (&effect_uv4)[iVar1].v;
        render_scratch_f2 = (&effect_uv4)[iVar1].u + 0.25;
        render_scratch_f3 = (&effect_uv4)[iVar1].v + 0.25;
        (*grim_interface_ptr->vtable->grim_set_uv)
                  (render_scratch_f0,render_scratch_f1,render_scratch_f2,render_scratch_f3);
        (*grim_interface_ptr->vtable->grim_set_color)(pfVar4[-2],pfVar4[-1],*pfVar4,pfVar4[1] * 0.5)
        ;
        (*grim_interface_ptr->vtable->grim_set_rotation)
                  ((float)(&fx_rotated_rotation)[iVar3] - 1.5707964);
        render_scratch_f0 = *pfVar2 + 2.0;
        render_scratch_f1 = pfVar2[1] + 2.0;
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  (render_scratch_f0 + _camera_offset_x,render_scratch_f1 + _camera_offset_y,
                   (float)(&fx_rotated_scale)[iVar3] * 1.04,(float)(&fx_rotated_scale)[iVar3] * 1.04
                  );
        iVar3 = iVar3 + 1;
        pfVar4 = pfVar4 + 4;
        pfVar2 = pfVar2 + 2;
      } while (iVar3 < fx_queue_rotated);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    iVar3 = 0;
    if (0 < fx_queue_rotated) {
      pfVar2 = (float *)&fx_rotated_pos_x;
      pfVar4 = (float *)&fx_rotated_color_b;
      do {
        iVar1 = (&creature_type_table)[(&fx_rotated_effect_id)[iVar3]].corpse_frame;
        render_scratch_f0 = (&effect_uv4)[iVar1].u;
        render_scratch_f1 = (&effect_uv4)[iVar1].v;
        render_scratch_f2 = (&effect_uv4)[iVar1].u + 0.25;
        render_scratch_f3 = (&effect_uv4)[iVar1].v + 0.25;
        (*grim_interface_ptr->vtable->grim_set_uv)
                  (render_scratch_f0,render_scratch_f1,render_scratch_f2,render_scratch_f3);
        (*grim_interface_ptr->vtable->grim_set_color)(pfVar4[-2],pfVar4[-1],*pfVar4,pfVar4[1]);
        (*grim_interface_ptr->vtable->grim_set_rotation)
                  ((float)(&fx_rotated_rotation)[iVar3] - 1.5707964);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  (_camera_offset_x + *pfVar2,_camera_offset_y + pfVar2[1],
                   (float)(&fx_rotated_scale)[iVar3],(float)(&fx_rotated_scale)[iVar3]);
        iVar3 = iVar3 + 1;
        pfVar4 = pfVar4 + 4;
        pfVar2 = pfVar2 + 2;
      } while (iVar3 < fx_queue_rotated);
    }
    (*grim_interface_ptr->vtable->grim_end_batch)();
    return;
  }
  return;
}



