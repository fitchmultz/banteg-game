/* mod_api_gfx_quad_rot @ 0040e470 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x50: clAPI_t::GFX_QuadRot */

void mod_api_gfx_quad_rot(float x,float y,float w,float h,float a)

{
  (*grim_interface_ptr->vtable->grim_set_rotation)(a);
  (*grim_interface_ptr->vtable->grim_draw_quad_rotated_matrix)(x,y,w,h);
  if (DAT_004824d0 == '\0') {
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  return;
}



