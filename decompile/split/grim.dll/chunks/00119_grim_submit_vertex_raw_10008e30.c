/* grim_submit_vertex_raw @ 10008e30 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xf4: push 1 raw vertex (7 floats) */

void grim_submit_vertex_raw(float *vertex)

{
  int *in_ECX;
  int iVar1;
  float *pfVar2;
  
  if ((grim_render_disabled == '\0') && (DAT_1005c898 != '\0')) {
    if (grim_batch_active == '\0') {
      (**(code **)(*in_ECX + 0xe8))();
    }
    pfVar2 = grim_vertex_write_ptr;
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
      *pfVar2 = *vertex;
      vertex = vertex + 1;
      pfVar2 = pfVar2 + 1;
    }
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    grim_vertex_count._0_2_ = (ushort)grim_vertex_count + 1;
    if (grim_vertex_capacity <= (ushort)grim_vertex_count) {
      (**(code **)(*in_ECX + 0xec))();
    }
  }
  return;
}



