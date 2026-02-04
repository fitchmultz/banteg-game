/* grim_set_atlas_frame @ 10008230 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x104 (provisional) */

void grim_set_atlas_frame(int atlas_size,int frame)

{
  float fVar1;
  
  fVar1 = 1.0 / (float)atlas_size;
  DAT_1005b2a8 = *(float *)((&grim_subrect_ptr_table)[atlas_size] + frame * 8);
  grim_uv_v1 = *(float *)((&grim_subrect_ptr_table)[atlas_size] + 4 + frame * 8);
  grim_uv_u0 = DAT_1005b2a8;
  grim_uv_v0 = grim_uv_v1;
  grim_uv_u1 = DAT_1005b2a8 + fVar1;
  DAT_1005b2a0 = DAT_1005b2a8 + fVar1;
  DAT_1005b2a4 = grim_uv_v1 + fVar1;
  DAT_1005b2ac = grim_uv_v1 + fVar1;
  return;
}



