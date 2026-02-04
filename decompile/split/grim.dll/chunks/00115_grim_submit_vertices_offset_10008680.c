/* grim_submit_vertices_offset @ 10008680 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x12c: copy verts, translate */

void grim_submit_vertices_offset(float *verts,int count,float *offset)

{
  int *in_ECX;
  uint uVar1;
  int iVar2;
  float *pfVar3;
  
  if (grim_render_disabled == '\0') {
    pfVar3 = grim_vertex_write_ptr;
    for (uVar1 = (uint)(count * 0x1c) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *pfVar3 = *verts;
      verts = verts + 1;
      pfVar3 = pfVar3 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)pfVar3 = *(undefined1 *)verts;
      verts = (float *)((int)verts + 1);
      pfVar3 = (float *)((int)pfVar3 + 1);
    }
    iVar2 = count;
    if (0 < count) {
      do {
        pfVar3 = grim_vertex_write_ptr;
        *grim_vertex_write_ptr = *grim_vertex_write_ptr + *offset;
        pfVar3[1] = offset[1] + pfVar3[1];
        grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    grim_vertex_count._0_2_ = (ushort)grim_vertex_count + (short)count;
    if (grim_vertex_capacity <= (ushort)grim_vertex_count) {
      (**(code **)(*in_ECX + 0xec))();
    }
  }
  return;
}



