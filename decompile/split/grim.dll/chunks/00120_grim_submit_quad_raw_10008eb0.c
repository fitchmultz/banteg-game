/* grim_submit_quad_raw @ 10008eb0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xf8: push 4 raw vertices (28 floats) */

void grim_submit_quad_raw(float *verts)

{
  int *in_ECX;
  int iVar1;
  float *pfVar2;
  
  if (grim_render_disabled == '\0') {
    pfVar2 = grim_vertex_write_ptr;
    for (iVar1 = 0x1c; iVar1 != 0; iVar1 = iVar1 + -1) {
      *pfVar2 = *verts;
      verts = verts + 1;
      pfVar2 = pfVar2 + 1;
    }
    grim_vertex_count._0_2_ = (ushort)grim_vertex_count + 4;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 0x1c;
    if (grim_vertex_capacity <= (ushort)grim_vertex_count) {
      (**(code **)(*in_ECX + 0xec))();
    }
  }
  return;
}



