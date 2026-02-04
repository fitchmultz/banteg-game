/* mod_api_gfx_draw_quads @ 0040e4c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x54: clAPI_t::GFX_DrawQuads */

void mod_api_gfx_draw_quads(mod_vertex2_t *v,int numQuads)

{
  float afStack_8 [2];
  
  if (DAT_004824d0 == '\0') {
    (*grim_interface_ptr->vtable->grim_begin_batch)();
  }
  afStack_8[0] = 0.0;
  afStack_8[1] = 0.0;
  (*grim_interface_ptr->vtable->grim_submit_vertices_offset)((float *)v,numQuads,afStack_8);
  if (DAT_004824d0 == '\0') {
    (*grim_interface_ptr->vtable->grim_end_batch)();
  }
  return;
}



