/* mod_api_gfx_clear @ 0040e1f0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x1c: clAPI_t::GFX_Clear (bridges to grim_clear_color) */

void mod_api_gfx_clear(float r,float g,float b,float a)

{
  (*grim_interface_ptr->vtable->grim_clear_color)(r,g,b,a);
  return;
}



