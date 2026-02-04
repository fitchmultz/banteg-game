/* mod_api_gfx_begin @ 0040e3e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x44: clAPI_t::GFX_Begin (bridges to grim_begin_batch) */

void mod_api_gfx_begin(void)

{
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  DAT_004824d0 = 1;
  return;
}



