/* creature_spawn_slot_alloc @ 00430ad0 */

/* returns first free spawn slot index (creature_spawn_slot_table[i].owner == NULL); returns 0x1f if
   none free */

int creature_spawn_slot_alloc(void)

{
  int iVar1;
  creature_spawn_slot_t *pcVar2;
  
  iVar1 = 0;
  pcVar2 = &creature_spawn_slot_table;
  do {
    if (pcVar2->owner == (creature_t *)0x0) {
      return iVar1;
    }
    pcVar2 = pcVar2 + 1;
    iVar1 = iVar1 + 1;
  } while ((int)pcVar2 < 0x4852d0);
  return 0x1f;
}



