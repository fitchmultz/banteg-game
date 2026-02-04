/* mod_api_gfx_quad @ 0040e420 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x4c: clAPI_t::GFX_Quad (bridges to grim_draw_quad) */

void mod_api_gfx_quad(float x,float y,float w,float h)

{
  (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
  (*grim_interface_ptr->vtable->grim_draw_quad)(x,y,w,h);
  if (DAT_004824d0 == '\0') {
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  return;
}



