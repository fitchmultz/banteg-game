/* grim_draw_quad_xy @ 10008720 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x120: draw quad from xy pointer */

void grim_draw_quad_xy(float *xy,float w,float h)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x11c))(*xy,xy[1],w,h);
  return;
}



