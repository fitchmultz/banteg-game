/* grim_end_batch @ 10007b20 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xf0 (provisional): end draw batch/flush */

void grim_end_batch(void)

{
  if ((grim_render_disabled == '\0') && (grim_batch_active != '\0')) {
    (**(code **)(*grim_vertex_buffer + 0x30))(grim_vertex_buffer);
    if (DAT_1005c898 != '\0') {
      if ((short)grim_vertex_count != 0) {
        (*grim_d3d_device->lpVtbl->DrawIndexedPrimitive)
                  (grim_d3d_device,D3DPT_TRIANGLELIST,0,grim_vertex_count & 0xffff,0,
                   (grim_vertex_count & 0xffff) >> 1);
      }
      (*grim_d3d_device->lpVtbl->EndScene)(grim_d3d_device);
      grim_batch_active = '\0';
    }
  }
  return;
}



