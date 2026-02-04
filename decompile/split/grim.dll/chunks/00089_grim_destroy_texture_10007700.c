/* grim_destroy_texture @ 10007700 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xbc (provisional): release texture handle */

void grim_destroy_texture(int handle)

{
  void *texture;
  int iVar1;
  bool bVar2;
  
  texture = (void *)(&grim_texture_slots)[handle];
  if (texture != (void *)0x0) {
    grim_texture_release(texture);
    operator_delete(texture);
    iVar1 = DAT_1005305c;
    bVar2 = handle == DAT_1005305c;
    (&grim_texture_slots)[handle] = 0;
    if (bVar2) {
      DAT_1005305c = iVar1 + -1;
    }
  }
  return;
}



