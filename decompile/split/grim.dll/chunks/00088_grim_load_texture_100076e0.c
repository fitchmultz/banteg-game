/* grim_load_texture @ 100076e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xb4 (provisional) */

int grim_load_texture(char *name,char *path)

{
  int iVar1;
  
  iVar1 = grim_load_texture_internal(name,(ushort *)path);
  return iVar1;
}



