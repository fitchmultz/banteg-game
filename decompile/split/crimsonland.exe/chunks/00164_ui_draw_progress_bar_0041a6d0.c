/* ui_draw_progress_bar @ 0041a6d0 */

/* draws a filled progress bar with a tinted background */

void __cdecl ui_draw_progress_bar(float *xy,float width,float ratio,float *rgba)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_10 = *rgba * 0.6;
  local_c = rgba[1] * 0.6;
  local_8 = rgba[2] * 0.6;
  local_4 = rgba[3] * 0.4;
  local_18 = *xy;
  local_14 = xy[1];
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&local_18,width,4.0);
  local_18 = xy[1] + 1.0;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)
            ((float *)&stack0xffffffe4,((float)xy - 2.0) * width,2.0);
  return;
}



