/* mod_api_gfx_printf @ 0040e240 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x24: clAPI_t::GFX_Printf */

void mod_api_gfx_printf(float x,float y,char *fmt,...)

{
  char *in_stack_00000010;
  
  crt_vsprintf(&DAT_004d9d00,in_stack_00000010,&stack0x00000014);
  (*grim_interface_ptr->vtable->grim_draw_text_small)(y,(float)fmt,&DAT_004d9d00);
  return;
}



