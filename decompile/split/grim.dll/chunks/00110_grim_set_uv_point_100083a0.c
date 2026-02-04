/* grim_set_uv_point @ 100083a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x10c: set UV point */

void grim_set_uv_point(int index,float u,float v)

{
  (&grim_uv_u0)[index * 2] = u;
  (&grim_uv_v0)[index * 2] = v;
  return;
}



