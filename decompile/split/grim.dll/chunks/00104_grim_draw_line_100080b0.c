/* grim_draw_line @ 100080b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xe0 (provisional): builds line quad from endpoints */

void grim_draw_line(float *p0,float *p1,float thickness)

{
  int *in_ECX;
  undefined *puVar1;
  undefined *puVar2;
  
  if ((DAT_10059bb4 & 1) == 0) {
    DAT_10059bb4 = DAT_10059bb4 | 1;
    FUN_1000a92c((_onexit_t)&DAT_10008140);
  }
  puVar2 = &grim_line_dx;
  puVar1 = &grim_line_dx;
  _grim_line_dx = *p1 - *p0;
  _grim_line_dy = p1[1] - p0[1];
  thunk_FUN_1000cc2c();
  _grim_line_dx = _grim_line_dy * (float)p0;
  _grim_line_dy = _grim_line_dx * (float)p0;
  (**(code **)(*in_ECX + 0xe4))(p0,p1,&grim_line_dx,puVar1,puVar2);
  return;
}



