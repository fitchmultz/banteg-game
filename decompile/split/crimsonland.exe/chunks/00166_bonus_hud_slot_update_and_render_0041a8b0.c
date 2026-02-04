/* bonus_hud_slot_update_and_render @ 0041a8b0 */

/* updates bonus HUD slot animation and renders icon/timers */

void __cdecl bonus_hud_slot_update_and_render(float *xy,int slot)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  IGrim2D_vtbl *pIVar4;
  bonus_hud_slot_t *pbVar5;
  float fVar6;
  bool bVar7;
  float in_stack_0000000c;
  char *text;
  float fStack_18;
  float fStack_14;
  float afStack_10 [4];
  
  if (bonus_hud_slot_table[slot].active != '\0') {
    if ((0.0 < *bonus_hud_slot_table[slot].slide.timer_ptr) ||
       ((pfVar2 = bonus_hud_slot_table[slot].slide.alt_timer_ptr, pfVar2 != (float *)0x0 &&
        (0.0 < *pfVar2)))) {
      fVar6 = frame_dt * 350.0 + bonus_hud_slot_table[slot].slide.slide_x;
    }
    else {
      fVar6 = bonus_hud_slot_table[slot].slide.slide_x - frame_dt * 320.0;
    }
    bonus_hud_slot_table[slot].slide.slide_x = fVar6;
    if (-2.0 < bonus_hud_slot_table[slot].slide.slide_x) {
      bonus_hud_slot_table[slot].slide.slide_x = -2.0;
    }
    if (bonus_hud_slot_table[slot].slide.slide_x < -184.0) {
      iVar3 = 0xf;
      if (slot < 0x10) {
        pbVar5 = bonus_hud_slot_table + 0xf;
        bVar7 = slot == 0xf;
        do {
          if (bVar7) {
            bonus_hud_slot_table[slot].active = '\0';
          }
          else if (pbVar5->active != '\0') break;
          iVar3 = iVar3 + -1;
          pbVar5 = pbVar5 + -1;
          bVar7 = slot == iVar3;
        } while (slot <= iVar3);
      }
      *xy = *xy + 52.0;
      return;
    }
    if (*(float *)((int)cv_uiSmallIndicators + 0xc) == 0.0) {
      (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7c4,0);
      (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
      (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,in_stack_0000000c * 0.7);
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      (*grim_interface_ptr->vtable->grim_draw_quad)
                (bonus_hud_slot_table[slot].slide.slide_x,*xy - 11.0,182.0,53.0);
      (*grim_interface_ptr->vtable->grim_end_batch)();
    }
    else {
      (*grim_interface_ptr->vtable->grim_bind_texture)(DAT_0048f7c4,0);
      (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
      (*grim_interface_ptr->vtable->grim_set_uv)(0.0,0.0,1.0,1.0);
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,in_stack_0000000c * 0.7);
      (*grim_interface_ptr->vtable->grim_begin_batch)();
      (*grim_interface_ptr->vtable->grim_draw_quad)
                ((bonus_hud_slot_table[slot].slide.slide_x - 100.0) + 4.0,*xy + 5.0,182.0,26.5);
      (*grim_interface_ptr->vtable->grim_end_batch)();
    }
    fVar6 = in_stack_0000000c * 0.7;
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,in_stack_0000000c);
    (*grim_interface_ptr->vtable->grim_bind_texture)(bonus_texture,0);
    (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,bonus_hud_slot_table[slot].slide.icon_id);
    (*grim_interface_ptr->vtable->grim_draw_quad)
              (bonus_hud_slot_table[slot].slide.slide_x - 1.0,*xy,32.0,32.0);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    pfVar2 = bonus_hud_slot_table[slot].slide.alt_timer_ptr;
    afStack_10[3] = fVar6;
    if (*(float *)((int)cv_uiSmallIndicators + 0xc) != 0.0) {
      if (pfVar2 == (float *)0x0) {
        fStack_18 = bonus_hud_slot_table[slot].slide.slide_x;
        fStack_14 = *xy + 21.0;
        fVar1 = *bonus_hud_slot_table[slot].slide.timer_ptr;
      }
      else {
        fStack_18 = bonus_hud_slot_table[slot].slide.slide_x + 36.0;
        afStack_10[0] = 0.1;
        afStack_10[1] = 0.3;
        afStack_10[2] = 0.6;
        fStack_14 = ((*xy + 21.0) - 4.0) - 4.0;
        ui_draw_progress_bar
                  (&fStack_18,32.0,*bonus_hud_slot_table[slot].slide.timer_ptr * 0.05,afStack_10);
        fStack_18 = bonus_hud_slot_table[slot].slide.slide_x;
        fStack_14 = *xy + 23.0;
        fVar1 = *bonus_hud_slot_table[slot].slide.alt_timer_ptr;
      }
      fStack_14 = fStack_14 - 4.0;
      fStack_18 = fStack_18 + 36.0;
      afStack_10[2] = 0.6;
      afStack_10[1] = 0.3;
      afStack_10[0] = 0.1;
      afStack_10[3] = fVar6;
      ui_draw_progress_bar(&fStack_18,32.0,fVar1 * 0.05,afStack_10);
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar6);
      *xy = *xy + 52.0;
      return;
    }
    if (pfVar2 == (float *)0x0) {
      fStack_18 = bonus_hud_slot_table[slot].slide.slide_x + 36.0;
      fStack_14 = *xy + 21.0;
      afStack_10[0] = 0.1;
      afStack_10[1] = 0.3;
      afStack_10[2] = 0.6;
      ui_draw_progress_bar
                (&fStack_18,100.0,*bonus_hud_slot_table[slot].slide.timer_ptr * 0.05,afStack_10);
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar6);
      text = bonus_hud_slot_table[slot].slide.label;
      pIVar4 = grim_interface_ptr->vtable;
      fVar6 = *xy + 6.0;
    }
    else {
      fStack_18 = bonus_hud_slot_table[slot].slide.slide_x + 36.0;
      afStack_10[0] = 0.1;
      fStack_14 = (*xy + 21.0) - 4.0;
      afStack_10[1] = 0.3;
      afStack_10[2] = 0.6;
      ui_draw_progress_bar
                (&fStack_18,100.0,*bonus_hud_slot_table[slot].slide.timer_ptr * 0.05,afStack_10);
      fStack_18 = bonus_hud_slot_table[slot].slide.slide_x + 36.0;
      fStack_14 = *xy + 23.0;
      afStack_10[0] = 0.1;
      afStack_10[1] = 0.3;
      afStack_10[2] = 0.6;
      afStack_10[3] = fVar6;
      ui_draw_progress_bar
                (&fStack_18,100.0,*bonus_hud_slot_table[slot].slide.alt_timer_ptr * 0.05,afStack_10)
      ;
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fVar6);
      text = bonus_hud_slot_table[slot].slide.label;
      pIVar4 = grim_interface_ptr->vtable;
      fVar6 = *xy + 2.0;
    }
    (*pIVar4->grim_draw_text_small)(bonus_hud_slot_table[slot].slide.slide_x + 36.0,fVar6,text);
    *xy = *xy + 52.0;
  }
  return;
}



