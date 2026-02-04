/* creature_render_type @ 00418b60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders active creatures matching type_id using 8x8 atlases and animation strips */

void __cdecl creature_render_type(int type_id)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int frame;
  IGrim2D_vtbl *pIVar4;
  float fVar5;
  float *pfVar6;
  longlong lVar7;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_24;
  float fStack_20;
  
  (*grim_interface_ptr->vtable->grim_bind_texture)((&creature_type_table)[type_id].texture_handle,0)
  ;
  (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
  fVar5 = (float)type_id;
  if ((config_blob.reserved0[0xe] != '\0') &&
     (iVar2 = perk_count_get(perk_id_monster_vision), iVar2 == 0)) {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,1);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    pfVar6 = &creature_pool.hitbox_size;
    do {
      if ((((creature_t *)(pfVar6 + -4))->active != '\0') && (pfVar6[0x17] == fVar5)) {
        fVar5 = pfVar6[0x1f];
        fStack_38 = pfVar6[0xb];
        fStack_34 = pfVar6[0xc];
        fStack_30 = pfVar6[0xd];
        fStack_2c = pfVar6[0xe] * 0.4;
        if ((((uint)fVar5 & 4) == 0) || (((uint)fVar5 & 0x40) != 0)) {
          if (16.0 <= *pfVar6) {
            lVar7 = __ftol();
            iVar2 = (int)lVar7;
            if ((((&creature_type_table)[type_id].anim_flags & 1) != 0) && (0xf < iVar2)) {
              iVar2 = 0x1f - iVar2;
            }
          }
          else if (0.0 <= *pfVar6) {
            lVar7 = __ftol();
            iVar2 = (int)lVar7;
          }
          else {
            iVar2 = (&creature_type_table)[type_id].base_frame + 0xf;
            fStack_2c = *pfVar6 * 0.5 + fStack_2c;
            if (fStack_2c < 0.0) {
              fStack_2c = 0.0;
            }
          }
          if (((uint)fVar5 & 0x10) != 0) {
            iVar2 = iVar2 + 0x20;
          }
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(8,iVar2);
        }
        else {
          lVar7 = __ftol();
          uVar3 = (uint)lVar7 & 0x8000000f;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
          }
          if (7 < (int)uVar3) {
            uVar3 = 0xf - uVar3;
          }
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)
                    (8,(&creature_type_table)[type_id].base_frame + 0x10 + uVar3);
          if ((*pfVar6 < 0.0) && (fStack_2c = *pfVar6 * 0.1 + fStack_2c, fStack_2c < 0.0)) {
            fStack_2c = 0.0;
          }
        }
        fStack_2c = fStack_2c * fStack_20;
        (*grim_interface_ptr->vtable->grim_set_color_ptr)(&fStack_38);
        (*grim_interface_ptr->vtable->grim_set_rotation)(pfVar6[7] - 1.5707964);
        fVar5 = pfVar6[9] * 0.5 + 0.7;
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + pfVar6[1]) - fVar5,(_camera_offset_y + pfVar6[2]) - fVar5,
                   pfVar6[9] * 1.07,pfVar6[9] * 1.07);
        fVar5 = fStack_24;
      }
      pfVar6 = pfVar6 + 0x26;
    } while ((int)pfVar6 < 0x4aa348);
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  if (_bonus_energizer_timer <= 0.0) {
    iVar2 = 0x49bfcc;
    do {
      if ((*(char *)(iVar2 + -0x94) != '\0') && (*(float *)(iVar2 + -0x28) == fStack_24)) {
        uVar3 = *(uint *)(iVar2 + -8);
        fStack_38 = *(float *)(iVar2 + -0x58);
        fStack_34 = *(float *)(iVar2 + -0x54);
        fStack_30 = *(float *)(iVar2 + -0x50);
        fStack_2c = *(float *)(iVar2 + -0x4c);
        if (((uVar3 & 4) == 0) || ((uVar3 & 0x40) != 0)) {
          if (16.0 <= *(float *)(iVar2 + -0x84)) {
            lVar7 = __ftol();
            frame = (int)lVar7;
            if ((((&creature_type_table)[type_id].anim_flags & 1) != 0) && (0xf < frame)) {
              frame = 0x1f - frame;
            }
          }
          else if (0.0 <= *(float *)(iVar2 + -0x84)) {
            lVar7 = __ftol();
            frame = (int)lVar7;
          }
          else {
            frame = (&creature_type_table)[type_id].base_frame + 0xf;
            fStack_2c = *(float *)(iVar2 + -0x84) * 0.1 + fStack_2c;
            if (fStack_2c < 0.0) {
              fStack_2c = 0.0;
            }
          }
          if ((uVar3 & 0x10) != 0) {
            frame = frame + 0x20;
          }
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(8,frame);
        }
        else {
          lVar7 = __ftol();
          uVar3 = (uint)lVar7 & 0x8000000f;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
          }
          if (7 < (int)uVar3) {
            uVar3 = 0xf - uVar3;
          }
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)
                    (8,(&creature_type_table)[type_id].base_frame + 0x10 + uVar3);
          if ((*(float *)(iVar2 + -0x84) < 0.0) &&
             (fStack_2c = *(float *)(iVar2 + -0x84) * 0.1 + fStack_2c, fStack_2c < 0.0)) {
            fStack_2c = 0.0;
          }
        }
        fStack_2c = fStack_2c * fStack_20;
        (*grim_interface_ptr->vtable->grim_set_color_ptr)(&fStack_38);
        (*grim_interface_ptr->vtable->grim_set_rotation)(*(float *)(iVar2 + -0x68) - 1.5707964);
        fVar5 = *(float *)(iVar2 + -0x60) * 0.5;
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + *(float *)(iVar2 + -0x80)) - fVar5,
                   (_camera_offset_y + *(float *)(iVar2 + -0x7c)) - fVar5,*(float *)(iVar2 + -0x60),
                   *(float *)(iVar2 + -0x60));
        if ((*(float *)(iVar2 + -0x84) < -10.0) &&
           (*(undefined1 *)(iVar2 + -0x94) = 0, (*(byte *)(iVar2 + -8) & 4) != 0)) {
          (&creature_spawn_slot_table)[*(int *)(iVar2 + -0x1c)].owner = (creature_t *)0x0;
        }
      }
      iVar2 = iVar2 + 0x98;
    } while (iVar2 < 0x4aa3cc);
  }
  else {
    pfVar6 = &creature_pool.max_health;
    do {
      if ((((creature_t *)(pfVar6 + -10))->active != '\0') && (pfVar6[0x11] == fVar5)) {
        if (500.0 <= *pfVar6) {
          fStack_38 = pfVar6[5];
          fStack_34 = pfVar6[6];
          fStack_30 = pfVar6[7];
          fStack_2c = pfVar6[8];
        }
        else {
          fStack_2c = _bonus_energizer_timer;
          if (1.0 <= _bonus_energizer_timer) {
            fStack_2c = 1.0;
          }
          fVar1 = 1.0 - fStack_2c;
          fStack_38 = fVar1 * pfVar6[5] + fStack_2c * 0.5;
          fStack_34 = fVar1 * pfVar6[6] + fStack_2c * 0.5;
          fStack_30 = fVar1 * pfVar6[7] + fStack_2c;
          fStack_2c = fVar1 * pfVar6[8] + fStack_2c;
        }
        fVar1 = pfVar6[0x19];
        if ((((uint)fVar1 & 4) == 0) || (((uint)fVar1 & 0x40) != 0)) {
          if (16.0 <= pfVar6[-6]) {
            lVar7 = __ftol();
            iVar2 = (int)lVar7;
            if ((((&creature_type_table)[type_id].anim_flags & 1) != 0) && (0xf < iVar2)) {
              iVar2 = 0x1f - iVar2;
            }
          }
          else if (0.0 <= pfVar6[-6]) {
            lVar7 = __ftol();
            iVar2 = (int)lVar7;
          }
          else {
            iVar2 = (&creature_type_table)[type_id].base_frame + 0xf;
            fStack_2c = pfVar6[-6] * 0.1 + fStack_2c;
            if (fStack_2c < 0.0) {
              fStack_2c = 0.0;
            }
          }
          if (((uint)fVar1 & 0x10) != 0) {
            iVar2 = iVar2 + 0x20;
          }
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)(8,iVar2);
        }
        else {
          lVar7 = __ftol();
          uVar3 = (uint)lVar7 & 0x8000000f;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
          }
          if (7 < (int)uVar3) {
            uVar3 = 0xf - uVar3;
          }
          (*grim_interface_ptr->vtable->grim_set_atlas_frame)
                    (8,(&creature_type_table)[type_id].base_frame + 0x10 + uVar3);
          if ((pfVar6[-6] < 0.0) && (fStack_2c = pfVar6[-6] * 0.1 + fStack_2c, fStack_2c < 0.0)) {
            fStack_2c = 0.0;
          }
        }
        fStack_2c = fStack_2c * fStack_20;
        (*grim_interface_ptr->vtable->grim_set_color_ptr)(&fStack_38);
        (*grim_interface_ptr->vtable->grim_set_rotation)(pfVar6[1] - 1.5707964);
        (*grim_interface_ptr->vtable->grim_draw_quad)
                  ((_camera_offset_x + pfVar6[-5]) - pfVar6[3] * 0.5,
                   (_camera_offset_y + pfVar6[-4]) - pfVar6[3] * 0.5,pfVar6[3],pfVar6[3]);
        if ((pfVar6[-6] < -10.0) &&
           (iVar2 = (int)pfVar6[0x19], ((creature_t *)(pfVar6 + -10))->active = '\0',
           (iVar2 & 4) != 0)) {
          (&creature_spawn_slot_table)[(int)pfVar6[0x14]].owner = (creature_t *)0x0;
        }
      }
      pfVar6 = pfVar6 + 0x26;
    } while ((int)pfVar6 < 0x4aa360);
  }
  (*grim_interface_ptr->vtable->grim_end_batch)();
  if (config_blob.fx_toggle != '\0') {
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
    (*grim_interface_ptr->vtable->grim_begin_batch)();
    pfVar6 = &creature_pool.hitbox_size;
    do {
      if (((((creature_t *)(pfVar6 + -4))->active != '\0') && (pfVar6[0x17] == fStack_38)) &&
         (0.0 < pfVar6[10])) {
        fVar5 = pfVar6[0x1f];
        if ((((uint)fVar5 & 4) == 0) || (((uint)fVar5 & 0x40) != 0)) {
          if (16.0 <= *pfVar6) {
            lVar7 = __ftol();
            iVar2 = (int)lVar7;
            if ((((&creature_type_table)[type_id].anim_flags & 1) != 0) && (0xf < iVar2)) {
              iVar2 = 0x1f - iVar2;
            }
            if (((uint)fVar5 & 0x10) != 0) {
              iVar2 = iVar2 + 0x20;
            }
          }
          else if (0.0 <= *pfVar6) {
            lVar7 = __ftol();
            iVar2 = (int)lVar7;
          }
          else {
            iVar2 = (&creature_type_table)[type_id].base_frame + 0xf;
          }
          pIVar4 = grim_interface_ptr->vtable;
        }
        else {
          lVar7 = __ftol();
          uVar3 = (uint)lVar7 & 0x8000000f;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
          }
          if (7 < (int)uVar3) {
            uVar3 = 0xf - uVar3;
          }
          pIVar4 = grim_interface_ptr->vtable;
          iVar2 = (&creature_type_table)[type_id].base_frame + 0x10 + uVar3;
        }
        (*pIVar4->grim_set_atlas_frame)(8,iVar2);
        (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&stack0xffffffb4);
        (*grim_interface_ptr->vtable->grim_set_rotation)(pfVar6[7] - 1.5707964);
        fVar1 = (_camera_offset_x + pfVar6[1]) - pfVar6[9] * 0.5;
        fVar5 = (_camera_offset_y + pfVar6[2]) - pfVar6[9] * 0.5;
        (*grim_interface_ptr->vtable->grim_draw_quad)(fVar1,fVar5,pfVar6[9],pfVar6[9]);
        (*grim_interface_ptr->vtable->grim_draw_quad)(fVar1,fVar5,pfVar6[9],pfVar6[9]);
      }
      pfVar6 = pfVar6 + 0x26;
    } while ((int)pfVar6 < 0x4aa348);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  }
  return;
}



