/* grim_set_sub_rect @ 100082c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x108: atlas sub-rect from grid table */

void grim_set_sub_rect(int atlas_size,int width,int height,int frame)

{
  float fVar1;
  
  DAT_1005b2a8 = *(float *)((&grim_subrect_ptr_table)[atlas_size] + frame * 8);
  grim_uv_v1 = *(float *)((&grim_subrect_ptr_table)[atlas_size] + 4 + frame * 8);
  grim_uv_u0 = DAT_1005b2a8;
  grim_uv_v0 = grim_uv_v1;
  grim_uv_u1 = (float)width * (1.0 / (float)atlas_size) + DAT_1005b2a8;
  DAT_1005b2a0 = grim_uv_u1;
  fVar1 = (1.0 / (float)atlas_size) * (float)height;
  DAT_1005b2a4 = fVar1 + grim_uv_v1;
  DAT_1005b2ac = fVar1 + grim_uv_v1;
  return;
}



