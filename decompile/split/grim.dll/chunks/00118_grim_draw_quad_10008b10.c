/* grim_draw_quad @ 10008b10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x11c (provisional) */

void grim_draw_quad(float x,float y,float w,float h)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *in_ECX;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  
  if ((grim_render_disabled == '\0') && (DAT_1005c898 != '\0')) {
    if (grim_batch_active == '\0') {
      (**(code **)(*in_ECX + 0xe8))();
    }
    if (_grim_rotation_radians == 0.0) {
      fStack_20 = x + w;
      fStack_28 = x;
      fStack_24 = y;
      fStack_1c = y;
      fVar1 = y + h;
      fStack_10 = x;
      fStack_18 = fStack_20;
      fStack_14 = fVar1;
    }
    else {
      fStack_10 = w * 0.5 + x;
      fVar1 = h * 0.5 + y;
      fVar2 = h * h + w * w;
      fVar3 = (float)(0x5f3759df - ((int)fVar2 >> 1));
      fVar2 = (1.5 - fVar2 * 0.5 * fVar3 * fVar3) * fVar3 * fVar2 * 0.5;
      fVar3 = grim_rotation_cos * fVar2;
      fVar2 = fVar2 * DAT_10059f40;
      fStack_28 = fStack_10 - fVar3;
      fStack_24 = fVar1 - fVar2;
      fStack_20 = fStack_10 + fVar2;
      fStack_1c = -fVar3 + fVar1;
      fStack_18 = fStack_10 + fVar3;
      fStack_14 = fVar1 + fVar2;
      fStack_10 = -fVar2 + fStack_10;
      fVar1 = fVar1 + fVar3;
    }
    *grim_vertex_write_ptr = fStack_28;
    grim_vertex_write_ptr[1] = fStack_24;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = grim_color_slot0;
    grim_vertex_write_ptr[5] = grim_uv_u0;
    grim_vertex_write_ptr[6] = grim_uv_v0;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    *grim_vertex_write_ptr = fStack_20;
    grim_vertex_write_ptr[1] = fStack_1c;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = DAT_1005bc08;
    grim_vertex_write_ptr[5] = grim_uv_u1;
    grim_vertex_write_ptr[6] = grim_uv_v1;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    *grim_vertex_write_ptr = fStack_18;
    grim_vertex_write_ptr[1] = fStack_14;
    grim_vertex_write_ptr[2] = DAT_1005b288;
    grim_vertex_write_ptr[3] = DAT_1005b28c;
    grim_vertex_write_ptr[4] = DAT_1005bc0c;
    grim_vertex_write_ptr[5] = DAT_1005b2a0;
    grim_vertex_write_ptr[6] = DAT_1005b2a4;
    grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
    *grim_vertex_write_ptr = fStack_10;
    grim_vertex_write_ptr[1] = fVar1;
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



