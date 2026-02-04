/* grim_draw_quad_rotated_matrix @ 10008750 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x124 (provisional): quad with rotation matrix */

void grim_draw_quad_rotated_matrix(float x,float y,float w,float h)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *in_ECX;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((grim_render_disabled == '\0') && (DAT_1005c898 != '\0')) {
    if (grim_batch_active == '\0') {
      (**(code **)(*in_ECX + 0xe8))();
    }
    if (_grim_rotation_radians == 0.0) {
      fStack_18 = x + w;
      fStack_20 = x;
      fStack_1c = y;
      fStack_14 = y;
      fStack_c = y + h;
      fStack_8 = x;
      fStack_10 = fStack_18;
      fStack_4 = fStack_c;
    }
    else {
      fVar3 = w * 0.5;
      fStack_8 = fVar3 + x;
      fVar1 = h * 0.5;
      fStack_4 = fVar1 + y;
      fVar2 = w * -0.5;
      fVar4 = h * -0.5;
      fStack_20 = _DAT_1005a460 * fVar2 + _DAT_1005a464 * fVar4 + fStack_8;
      fStack_1c = fStack_4 + _DAT_1005a468 * fVar2 + fVar4 * _DAT_1005a46c;
      fStack_18 = _DAT_1005a460 * fVar3 + _DAT_1005a464 * fVar4 + fStack_8;
      fStack_14 = fStack_4 + _DAT_1005a468 * fVar3 + fVar4 * _DAT_1005a46c;
      fStack_10 = _DAT_1005a460 * fVar3 + _DAT_1005a464 * fVar1 + fStack_8;
      fStack_c = fStack_4 + _DAT_1005a468 * fVar3 + _DAT_1005a46c * fVar1;
      fStack_8 = _DAT_1005a460 * fVar2 + _DAT_1005a464 * fVar1 + fStack_8;
      fStack_4 = fStack_4 + _DAT_1005a468 * fVar2 + _DAT_1005a46c * fVar1;
    }
    *grim_vertex_write_ptr = fStack_20;
    grim_vertex_write_ptr[1] = fStack_1c;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = grim_color_slot0;
    grim_vertex_write_ptr[5] = grim_uv_u0;
    grim_vertex_write_ptr[6] = grim_uv_v0;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    *grim_vertex_write_ptr = fStack_18;
    grim_vertex_write_ptr[1] = fStack_14;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = DAT_1005bc08;
    grim_vertex_write_ptr[5] = grim_uv_u1;
    grim_vertex_write_ptr[6] = grim_uv_v1;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    *grim_vertex_write_ptr = fStack_10;
    grim_vertex_write_ptr[1] = fStack_c;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = DAT_1005bc0c;
    grim_vertex_write_ptr[5] = DAT_1005b2a0;
    grim_vertex_write_ptr[6] = DAT_1005b2a4;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    *grim_vertex_write_ptr = fStack_8;
    grim_vertex_write_ptr[1] = fStack_4;
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



