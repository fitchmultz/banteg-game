/* grim_get_texture_handle @ 10007740 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xc0: lookup texture handle by name */

int grim_get_texture_handle(char *name)

{
  int iVar1;
  
  iVar1 = grim_find_texture_by_name(name);
  return iVar1;
}



