/* mod_api_gfx_set_subset @ 0040e350 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x40: clAPI_t::GFX_SetSubset (bridges to grim_set_uv) */

void mod_api_gfx_set_subset(float x1,float y1,float x2,float y2)

{
  (*grim_interface_ptr->vtable->grim_set_uv)(x1,y1,x2,y2);
  return;
}



