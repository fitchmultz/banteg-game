/* ui_draw_clock_gauge_at @ 0040a4c0 */

/* draws the clock gauge at a position when progress > 0 */

void __cdecl ui_draw_clock_gauge_at(float *xy,float radius,float progress)

{
  if (0.0 < progress) {
    __ftol();
    __ftol();
    __ftol();
    ui_draw_clock_gauge();
  }
  return;
}



