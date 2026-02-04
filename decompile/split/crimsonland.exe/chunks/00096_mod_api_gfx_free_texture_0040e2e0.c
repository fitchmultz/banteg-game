/* mod_api_gfx_free_texture @ 0040e2e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x2c: clAPI_t::GFX_FreeTexture (bridges to grim_destroy_texture) */

uchar mod_api_gfx_free_texture(int texId)

{
  (*grim_interface_ptr->vtable->grim_destroy_texture)(texId);
  return '\x01';
}



