/* grim_draw_text_small_fmt @ 10009980 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x148: formatted small-font text (cdecl varargs, explicit self; vsprintf + vtable
   0x144) */

void grim_draw_text_small_fmt(IGrim2D *self,float x,float y,char *fmt,...)

{
  vsprintf(&grim_printf_buffer_alt,fmt,&stack0x00000014);
  (*self->vtable->grim_draw_text_small)(x,y,&grim_printf_buffer_alt);
  return;
}



