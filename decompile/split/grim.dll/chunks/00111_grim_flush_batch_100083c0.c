/* grim_flush_batch @ 100083c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xec: flush batch when vertex buffer fills */

void grim_flush_batch(void)

{
  int iVar1;
  
  if ((grim_render_disabled == '\0') && (grim_batch_active != '\0')) {
    (**(code **)(*grim_vertex_buffer + 0x30))(grim_vertex_buffer);
    (*grim_d3d_device->lpVtbl->DrawIndexedPrimitive)
              (grim_d3d_device,D3DPT_TRIANGLELIST,0,grim_vertex_count & 0xffff,0,
               (grim_vertex_count & 0xffff) >> 1);
    iVar1 = (**(code **)(*grim_vertex_buffer + 0x2c))
                      (grim_vertex_buffer,0,0,&grim_vertex_write_ptr,0x2800);
    if (-1 < iVar1) {
      grim_vertex_count = grim_vertex_count & 0xffff0000;
    }
  }
  return;
}



