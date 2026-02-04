/* ui_text_input_render @ 004413a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders a text input field (focus, text, and caret) */

void __cdecl ui_text_input_render(void *input_state,float y,float alpha)

{
  IGrim2D_vtbl *pIVar1;
  float fVar2;
  IGrim2D *self;
  int iVar3;
  char *pcVar4;
  char *text;
  IGrim2D_vtbl *pIVar5;
  longlong lVar6;
  int in_stack_00000010;
  float fVar7;
  float fVar8;
  float h;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fVar2 = alpha * 0.7;
  DAT_00496604 = 0x3f333333;
  _DAT_004ccca8 = DAT_004965f8;
  _DAT_004cccac = DAT_004965fc;
  _DAT_004cccb0 = DAT_00496600;
  _DAT_004cccb4 = fVar2;
  iVar3 = (*grim_interface_ptr->vtable->grim_measure_text_width)((char *)y);
  fStack_c = *(float *)((int)input_state + 4);
  fStack_10 = *(float *)input_state + 4.0;
  if (((game_state_id != 7) && (game_state_id != 8)) && (game_state_id != 0xc)) {
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,alpha);
    (*grim_interface_ptr->vtable->grim_draw_text_small)(fStack_10,fStack_c,(char *)y);
    (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004ccca8);
    fStack_4 = fStack_c + 13.0;
    fStack_8 = fStack_10;
    (*grim_interface_ptr->vtable->grim_draw_rect_outline)(&fStack_8,(float)iVar3,1.0);
    if ((*(byte *)((int)y + 0x44) & 2) == 0) {
      if ((*(byte *)((int)y + 0x44) & 1) == 0) {
        (*grim_interface_ptr->vtable->grim_set_color)(0.8,0.8,0.8,alpha * 0.8);
        pcVar4 = s_Local_score_00478974;
        pIVar5 = grim_interface_ptr->vtable;
      }
      else {
        (*grim_interface_ptr->vtable->grim_set_color)(0.7,1.0,0.7,alpha * 0.8);
        pcVar4 = s_Score_from_the_Internet_00478980;
        pIVar5 = grim_interface_ptr->vtable;
      }
      (*pIVar5->grim_draw_text_small_fmt)(grim_interface_ptr,fStack_10,fStack_c + 14.0,pcVar4);
    }
    else {
      (*grim_interface_ptr->vtable->grim_set_color)(0.8,0.8,0.8,alpha * 0.8);
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,fStack_10,fStack_c + 14.0,
                 s_Internet_score_of_local_origin_004789a0);
      (*grim_interface_ptr->vtable->grim_set_color)(0.5,0.5,0.5,alpha * 0.5);
      (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
                (grim_interface_ptr,fStack_10 + 94.0,fStack_c - 12.0,s_uni__d_00478998);
      (*grim_interface_ptr->vtable->grim_set_color)(0.8,0.8,0.8,alpha * 0.8);
    }
    (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,alpha * 0.8);
    pIVar5 = grim_interface_ptr->vtable;
    pcVar4 = FUN_00441270((uint)*(byte *)((int)y + 0x40),(uint)*(byte *)((int)y + 0x42));
    fVar7 = fStack_c + 15.0 + 13.0;
    pIVar1 = grim_interface_ptr->vtable;
    text = FUN_00441270((uint)*(byte *)((int)y + 0x40),(uint)*(byte *)((int)y + 0x42));
    iVar3 = (*pIVar1->grim_measure_text_width)(text);
    (*pIVar5->grim_draw_text_small)
              ((((fStack_10 + 192.0) - 32.0) - 8.0) - (float)(iVar3 / 2),fVar7,pcVar4);
    fStack_10 = *(float *)input_state + 16.0;
    FUN_004411c0();
    fStack_c = fStack_c + 15.0 + 13.0 + 14.0;
  }
  fVar7 = alpha * 0.8;
  (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,fVar7);
  pIVar5 = grim_interface_ptr->vtable;
  pcVar4 = s_Score_0047896c;
  fVar8 = fStack_c;
  iVar3 = (*pIVar5->grim_measure_text_width)(s_Score_0047896c);
  (*pIVar5->grim_draw_text_small)((fStack_10 + 32.0) - (float)(iVar3 / 2),fVar8,pcVar4);
  if (*(char *)((int)y + 0x28) == '\x02') {
    crt_sprintf(&DAT_004d0da0,s___2f_secs_00478960,(double)((float)*(int *)((int)y + 0x20) * 0.001))
    ;
  }
  else if (*(char *)((int)y + 0x28) == '\x03') {
    crt_sprintf(&DAT_004d0da0,s___2f_secs_00478960,(double)((float)*(int *)((int)y + 0x20) * 0.001))
    ;
  }
  else {
    crt_sprintf(&DAT_004d0da0,&DAT_00471f40);
  }
  (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,1.0,alpha);
  iVar3 = (*grim_interface_ptr->vtable->grim_measure_text_width)(&DAT_004d0da0);
  (*grim_interface_ptr->vtable->grim_draw_text_small)
            ((fStack_10 + 32.0) - (float)(iVar3 / 2),fStack_c + 15.0,&DAT_004d0da0);
  if (game_state_id != 0xc) {
    format_ordinal(in_stack_00000010);
    crt_sprintf(&DAT_004d0da0,s_Rank___s_00478954);
    iVar3 = (*grim_interface_ptr->vtable->grim_measure_text_width)(&DAT_004d0da0);
    (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,fVar7);
    (*grim_interface_ptr->vtable->grim_draw_text_small)
              ((fStack_10 + 32.0) - (float)(iVar3 / 2),fStack_c + 30.0,&DAT_004d0da0);
  }
  fStack_10 = fStack_10 + 96.0;
  FUN_00441220();
  if (*(char *)((int)y + 0x28) == '\x03') {
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fStack_10,fStack_c,s_Experience_00478948);
    crt_sprintf(&DAT_004d0da0,&DAT_00471f40);
    iVar3 = (*grim_interface_ptr->vtable->grim_measure_text_width)(&DAT_004d0da0);
    (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,fVar7);
    (*grim_interface_ptr->vtable->grim_draw_text_small)
              ((fStack_10 + 32.0) - (float)(iVar3 / 2),fStack_c + 15.0,&DAT_004d0da0);
    ui_stats_hover_time = ui_stats_hover_time - (frame_dt + frame_dt);
  }
  else {
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fStack_10 + 6.0,fStack_c,s_Game_time_0047893c);
    __ftol();
    __ftol();
    ui_draw_clock_gauge();
    if (((ui_mouse_x <= fStack_10 + 8.0) || (fStack_10 + 72.0 <= ui_mouse_x)) ||
       ((ui_mouse_y <= fStack_c + 16.0 || (fStack_c + 45.0 <= ui_mouse_y)))) {
      ui_stats_hover_time = ui_stats_hover_time - (frame_dt + frame_dt);
    }
    else {
      ui_stats_hover_time = frame_dt + frame_dt + ui_stats_hover_time;
    }
    (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,fVar7);
    iVar3 = *(int *)((int)y + 0x20) / 1000;
    if (iVar3 % 0x3c < 10) {
      pcVar4 = s__d_0_d_00473150;
    }
    else {
      pcVar4 = s__d__d_00473148;
    }
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fStack_10 + 40.0,fStack_c + 19.0,pcVar4,iVar3 / 0x3c);
  }
  fStack_c = fStack_c + 52.0;
  fStack_10 = fStack_10 - 96.0;
  if (((ui_screen_phase == 2) && (game_state_id == 8)) ||
     (((game_state_id == 7 || ((game_state_id == 8 || (game_state_id == 0xc)))) &&
      (ui_screen_phase == 0)))) {
    ui_stats_hover_hit_ratio = 0.0;
  }
  else {
    FUN_004411c0();
    (*grim_interface_ptr->vtable->grim_bind_texture)(ui_weapon_icons_texture,0);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,1);
    (*grim_interface_ptr->vtable->grim_set_sub_rect)
              (8,2,1,(&weapon_table)[*(byte *)((int)y + 0x2b)].hud_icon_id << 1);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,alpha);
    h = 32.0;
    pIVar5 = grim_interface_ptr->vtable;
    fVar8 = 64.0;
    lVar6 = __ftol();
    fVar7 = (float)(int)lVar6;
    lVar6 = __ftol();
    fStack_c = (float)lVar6;
    (*pIVar5->grim_draw_quad)((float)(int)fStack_c,fVar7,fVar8,h);
    (*grim_interface_ptr->vtable->grim_end_batch)();
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
    if ((((ui_mouse_x <= fStack_10) || (fStack_10 + 64.0 <= ui_mouse_x)) || (ui_mouse_y <= fStack_c)
        ) || (fStack_c + 32.0 <= ui_mouse_y)) {
      ui_stats_hover_weapon = ui_stats_hover_weapon - (frame_dt + frame_dt);
    }
    else {
      ui_stats_hover_weapon = frame_dt + frame_dt + ui_stats_hover_weapon;
    }
    (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,fVar2);
    iVar3 = (*grim_interface_ptr->vtable->grim_measure_text_width)
                      ((&weapon_table)[*(byte *)((int)y + 0x2b)].name);
    fVar7 = (float)(0x20 - iVar3 / 2);
    if (fVar7 < 0.0) {
      fVar7 = 0.0;
    }
    (*grim_interface_ptr->vtable->grim_draw_text_small)
              (fVar7 + fStack_10,fStack_c + 32.0,(&weapon_table)[*(byte *)((int)y + 0x2b)].name);
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,fStack_10 + 110.0,fStack_c + 1.0,s_Frags___d_00478930);
    self = grim_interface_ptr;
    pIVar5 = grim_interface_ptr->vtable;
    __ftol();
    (*pIVar5->grim_draw_text_small_fmt)
              (self,fStack_10 + 110.0,(fStack_c + 16.0) - 1.0,s_Hit______d___00478920);
    if (((ui_mouse_x <= fStack_10 + 110.0) || (fStack_10 + 174.0 <= ui_mouse_x)) ||
       ((ui_mouse_y <= (fStack_c + 16.0) - 1.0 || (fStack_c + 32.0 <= ui_mouse_y)))) {
      ui_stats_hover_hit_ratio = ui_stats_hover_hit_ratio - (frame_dt + frame_dt);
    }
    else {
      ui_stats_hover_hit_ratio = frame_dt + frame_dt + ui_stats_hover_hit_ratio;
    }
    fStack_c = fStack_c + 48.0;
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,alpha);
  FUN_004411c0();
  if (ui_stats_hover_weapon <= 1.0) {
    if (ui_stats_hover_weapon < 0.0) {
      ui_stats_hover_weapon = 0.0;
    }
  }
  else {
    ui_stats_hover_weapon = 1.0;
  }
  if (ui_stats_hover_time <= 1.0) {
    if (ui_stats_hover_time < 0.0) {
      ui_stats_hover_time = 0.0;
    }
  }
  else {
    ui_stats_hover_time = 1.0;
  }
  if (ui_stats_hover_hit_ratio <= 1.0) {
    if (ui_stats_hover_hit_ratio < 0.0) {
      ui_stats_hover_hit_ratio = 0.0;
    }
  }
  else {
    ui_stats_hover_hit_ratio = 1.0;
  }
  if (((game_state_id == 7) || (game_state_id == 8)) || (game_state_id == 0xc)) {
    (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,fVar2);
    if (0.5 < ui_stats_hover_weapon) {
      fVar2 = (ui_stats_hover_weapon - 0.5) * alpha;
      (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,fVar2 + fVar2);
      (*grim_interface_ptr->vtable->grim_draw_text_small)
                (fStack_10 - 20.0,fStack_c,s_Most_used_weapon_during_the_game_004788fc);
    }
    if (0.5 < ui_stats_hover_time) {
      fVar2 = (ui_stats_hover_time - 0.5) * alpha;
      (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,fVar2 + fVar2);
      (*grim_interface_ptr->vtable->grim_draw_text_small)
                (fStack_10 + 12.0,fStack_c,s_The_time_the_game_lasted_004788e0);
    }
    if (0.5 < ui_stats_hover_hit_ratio) {
      fVar2 = (ui_stats_hover_hit_ratio - 0.5) * alpha;
      (*grim_interface_ptr->vtable->grim_set_color)(0.9,0.9,0.9,fVar2 + fVar2);
      (*grim_interface_ptr->vtable->grim_draw_text_small)
                (fStack_10 - 22.0,fStack_c,s_The___of_shot_bullets_hit_the_ta_004788b8);
    }
  }
  return;
}



