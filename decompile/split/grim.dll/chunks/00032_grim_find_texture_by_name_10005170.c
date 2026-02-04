/* grim_find_texture_by_name @ 10005170 */

/* returns texture handle index for name */

int __cdecl grim_find_texture_by_name(char *name)

{
  int iVar1;
  int iVar2;
  char *unaff_EDI;
  undefined4 *puVar3;
  
  iVar2 = 0;
  if (0 < DAT_1005305c + 1) {
    puVar3 = &grim_texture_slots;
    do {
      if ((void *)*puVar3 != (void *)0x0) {
        iVar1 = grim_texture_name_equals((void *)*puVar3,name,unaff_EDI);
        if ((char)iVar1 != '\0') {
          return iVar2;
        }
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < DAT_1005305c + 1);
  }
  return -1;
}



