/* ui_text_input_update @ 0043ecf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* updates a text input field: focus, input polling, sfx, and rendering */

int __cdecl ui_text_input_update(float *xy,int *input_state)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  float local_18;
  float local_14;
  float fStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = ui_focus_update((int)input_state);
  iVar4 = input_state[3];
  lVar6 = __ftol();
  iVar2 = ui_mouse_inside_rect(xy,0x12,(int)lVar6);
  if ((char)iVar2 != '\0') {
    ui_focus_set((int)input_state,'\0');
  }
  if ((char)iVar1 != '\0') {
    local_18 = *xy - 16.0;
    local_14 = xy[1];
    ui_focus_draw(&local_18);
  }
  *(undefined1 *)(*input_state + 1 + input_state[1]) = 0;
  iVar1 = console_input_poll();
  if (iVar1 == 0xd) {
    (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c);
    (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x9c);
    sfx_play(sfx_ui_typeenter);
  }
  else {
    (*grim_interface_ptr->vtable->grim_set_key_char_buffer)
              ((uchar *)*input_state,input_state + 1,input_state[2]);
    if (iVar1 != 0) {
      uVar3 = crt_rand();
      uVar3 = uVar3 & 0x80000001;
      if ((int)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
      }
      sfx_play(uVar3 + _sfx_ui_typeclick_01);
    }
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)(xy,(float)iVar4,18.0);
  local_18 = *xy + 1.0;
  uVar7 = 0x41800000;
  local_14 = xy[1] + 1.0;
  fStack_10 = 0.0;
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0x3f800000;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&local_18,(float)iVar4 - 2.0,16.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  iVar4 = 0;
  fStack_10 = (fStack_10 - 8.0) - 2.0;
  while( true ) {
    local_14 = (float)(*grim_interface_ptr->vtable->grim_measure_text_width)
                                ((char *)(*input_state + iVar4));
    uVar8 = (undefined1)((uint)uVar7 >> 0x18);
    if ((float)(int)local_14 <= fStack_10) break;
    iVar4 = iVar4 + 1;
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.8);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,*xy + 4.0,xy[1] + 2.0,&s_fmt_percent_s,*input_state + iVar4);
  fStack_10 = 1.0;
  fVar5 = (float10)fsin((float10)game_time_s * (float10)4.0);
  if ((float10)0.0 < fVar5) {
    fStack_10 = 0.4;
  }
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_10);
  uVar7 = (*grim_interface_ptr->vtable->grim_draw_rect_outline)((float *)&stack0xffffffd0,1.0,14.0);
  return CONCAT31((int3)((uint)uVar7 >> 8),uVar8);
}



