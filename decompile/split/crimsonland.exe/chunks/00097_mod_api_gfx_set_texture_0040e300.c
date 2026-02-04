/* mod_api_gfx_set_texture @ 0040e300 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x30: clAPI_t::GFX_SetTexture (bridges to grim_bind_texture(handle, 0)) */

void mod_api_gfx_set_texture(int texId)

{
  (*grim_interface_ptr->vtable->grim_bind_texture)(texId,0);
  return;
}



