/* grim_submit_vertices_transform_color @ 100084e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x134: rotate + translate + apply color */

void grim_submit_vertices_transform_color
               (float *verts,int count,float *offset,float *matrix,float *color)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *in_ECX;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  
  if (grim_render_disabled == '\0') {
    pfVar7 = grim_vertex_write_ptr;
    for (uVar5 = (uint)(count * 0x1c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pfVar7 = *verts;
      verts = verts + 1;
      pfVar7 = pfVar7 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)pfVar7 = *(undefined1 *)verts;
      verts = (float *)((int)verts + 1);
      pfVar7 = (float *)((int)pfVar7 + 1);
    }
    iVar6 = count;
    if (0 < count) {
      do {
        pfVar7 = grim_vertex_write_ptr;
        fVar1 = grim_vertex_write_ptr[1];
        fVar2 = matrix[1];
        fVar3 = *grim_vertex_write_ptr;
        fVar4 = *matrix;
        grim_vertex_write_ptr[1] =
             *grim_vertex_write_ptr * matrix[2] + grim_vertex_write_ptr[1] * matrix[3];
        *pfVar7 = fVar3 * fVar4 + fVar1 * fVar2;
        pfVar7 = grim_vertex_write_ptr;
        *grim_vertex_write_ptr = *offset + *grim_vertex_write_ptr;
        pfVar7[1] = offset[1] + pfVar7[1];
        grim_vertex_write_ptr[4] = *color;
        grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    grim_vertex_count._0_2_ = (ushort)grim_vertex_count + (short)count;
    if (grim_vertex_capacity <= (ushort)grim_vertex_count) {
      (**(code **)(*in_ECX + 0xec))();
    }
  }
  return;
}



