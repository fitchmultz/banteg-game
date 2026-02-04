/* grim_draw_fullscreen_quad @ 10007870 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xc8: full-screen quad with current texture */

void grim_draw_fullscreen_quad(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xfc))(0);
  (**(code **)(*in_ECX + 0xe8))();
  (**(code **)(*in_ECX + 0x11c))(0,0,(float)grim_backbuffer_width,(float)grim_backbuffer_height);
  (**(code **)(*in_ECX + 0xf0))();
  return;
}



