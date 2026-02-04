/* mod_api_gfx_end @ 0040e400 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x48: clAPI_t::GFX_End (bridges to grim_end_batch) */

void mod_api_gfx_end(void)

{
  (*grim_interface_ptr->vtable->grim_end_batch)();
  DAT_004824d0 = 0;
  return;
}



