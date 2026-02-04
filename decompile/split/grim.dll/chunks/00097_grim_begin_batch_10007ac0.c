/* grim_begin_batch @ 10007ac0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xe8 (provisional): begin draw batch */

void grim_begin_batch(void)

{
  int iVar1;
  
  if (((grim_render_disabled == '\0') && (grim_batch_active == '\0')) &&
     (grim_batch_active = '\x01', DAT_1005c898 != '\0')) {
    (*grim_d3d_device->lpVtbl->BeginScene)(grim_d3d_device);
    iVar1 = (**(code **)(*grim_vertex_buffer + 0x2c))
                      (grim_vertex_buffer,0,0,&grim_vertex_write_ptr,0x2800);
    if (iVar1 < 0) {
      DAT_1005c898 = '\0';
    }
    grim_vertex_count._0_2_ = 0;
  }
  return;
}



