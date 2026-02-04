/* mod_api_gfx_set_texture_filter @ 0040e380 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x34: clAPI_t::GFX_SetTextureFilter (bridges to grim_set_config_var(21, filter))
    */

void mod_api_gfx_set_texture_filter(int filter)

{
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,filter);
  return;
}



