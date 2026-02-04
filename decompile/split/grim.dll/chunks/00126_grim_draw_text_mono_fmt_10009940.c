/* grim_draw_text_mono_fmt @ 10009940 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x140: printf-style wrapper around draw_text_mono (cdecl varargs, explicit self) */

void grim_draw_text_mono_fmt(IGrim2D *self,float x,float y,char *fmt,...)

{
  vsprintf(&grim_printf_buffer,fmt,&stack0x00000014);
  (*self->vtable->grim_draw_text_mono)(x,y,&grim_printf_buffer);
  return;
}



