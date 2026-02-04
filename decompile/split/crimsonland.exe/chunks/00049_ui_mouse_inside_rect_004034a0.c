/* ui_mouse_inside_rect @ 004034a0 */

/* returns 1 when the mouse is inside the rect and mouse capture is clear */

int __cdecl ui_mouse_inside_rect(float *xy,int h,int w)

{
  if ((((*xy < ui_mouse_x) && (xy[1] < ui_mouse_y)) && (ui_mouse_x < (float)w + *xy)) &&
     ((ui_mouse_y < (float)h + xy[1] && (ui_mouse_blocked == '\0')))) {
    return 1;
  }
  return 0;
}



