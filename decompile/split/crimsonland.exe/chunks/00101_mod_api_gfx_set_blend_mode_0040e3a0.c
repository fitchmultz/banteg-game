/* mod_api_gfx_set_blend_mode @ 0040e3a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x38: clAPI_t::GFX_SetBlendMode (bridges to grim_set_config_var(19, src) and (20,
   dst)) */

void mod_api_gfx_set_blend_mode(int src,int dst)

{
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,dst);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,dst);
  return;
}



