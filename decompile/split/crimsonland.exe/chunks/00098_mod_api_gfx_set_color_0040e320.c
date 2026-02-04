/* mod_api_gfx_set_color @ 0040e320 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x3c: clAPI_t::GFX_SetColor (bridges to grim_set_color) */

void mod_api_gfx_set_color(float r,float g,float b,float a)

{
  (*grim_interface_ptr->vtable->grim_set_color)(r,g,b,a);
  return;
}



