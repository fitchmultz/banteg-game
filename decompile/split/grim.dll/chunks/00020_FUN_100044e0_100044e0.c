/* FUN_100044e0 @ 100044e0 */

void FUN_100044e0(void)

{
  if (grim_vertex_buffer != (int *)0x0) {
    (**(code **)(*grim_vertex_buffer + 8))(grim_vertex_buffer);
  }
  grim_vertex_buffer = (int *)0x0;
  if (DAT_10059bb8 != (int *)0x0) {
    (**(code **)(*DAT_10059bb8 + 8))(DAT_10059bb8);
  }
  DAT_10059bb8 = (int *)0x0;
  return;
}



