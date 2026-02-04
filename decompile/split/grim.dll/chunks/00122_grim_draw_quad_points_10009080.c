/* grim_draw_quad_points @ 10009080 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x138 (provisional): push quad using 4 points */

void grim_draw_quad_points(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3)

{
  int *in_ECX;
  
  if ((grim_render_disabled == '\0') && (DAT_1005c898 != '\0')) {
    if (grim_batch_active == '\0') {
      (**(code **)(*in_ECX + 0xe8))();
    }
    *grim_vertex_write_ptr = x0;
    grim_vertex_write_ptr[1] = y0;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = grim_color_slot0;
    grim_vertex_write_ptr[5] = grim_uv_u0;
    grim_vertex_write_ptr[6] = grim_uv_v0;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    *grim_vertex_write_ptr = x1;
    grim_vertex_write_ptr[1] = y1;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = DAT_1005bc08;
    grim_vertex_write_ptr[5] = grim_uv_u1;
    grim_vertex_write_ptr[6] = grim_uv_v1;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    *grim_vertex_write_ptr = x2;
    grim_vertex_write_ptr[1] = y2;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = DAT_1005bc0c;
    grim_vertex_write_ptr[5] = DAT_1005b2a0;
    grim_vertex_write_ptr[6] = DAT_1005b2a4;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    *grim_vertex_write_ptr = x3;
    grim_vertex_write_ptr[1] = y3;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = grim_color_slot3;
    grim_vertex_write_ptr[5] = DAT_1005b2a8;
    grim_vertex_write_ptr[6] = DAT_1005b2ac;
    grim_vertex_count._0_2_ = (ushort)grim_vertex_count + 4;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    if (grim_vertex_capacity <= (ushort)grim_vertex_count) {
      (**(code **)(*in_ECX + 0xec))();
    }
  }
  return;
}



