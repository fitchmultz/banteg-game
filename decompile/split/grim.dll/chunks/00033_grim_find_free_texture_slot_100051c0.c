/* grim_find_free_texture_slot @ 100051c0 */

/* finds the first free texture slot */

int grim_find_free_texture_slot(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &grim_texture_slots;
  do {
    if (*piVar2 == 0) {
      return iVar1;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x1005d804);
  return -1;
}



