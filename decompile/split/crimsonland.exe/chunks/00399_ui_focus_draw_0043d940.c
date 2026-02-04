/* ui_focus_draw @ 0043d940 */

/* draws the focus highlight for the active menu item */

void __cdecl ui_focus_draw(float *xy)

{
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  local_10 = 0x3f4ccccd;
  local_4 = (float)ui_focus_timer_ms * 0.00080000004;
  local_c = 0x3f4ccccd;
  local_8 = 0x3f19999a;
  local_18 = *xy;
  local_14 = xy[1] + 4.0;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&local_18,6.0,6.0);
  return;
}



