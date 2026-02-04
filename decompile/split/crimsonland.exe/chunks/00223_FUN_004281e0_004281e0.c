/* FUN_004281e0 @ 004281e0 */

/* [binja] void* sub_4281e0() */

void * FUN_004281e0(void)

{
  int *piVar1;
  
  piVar1 = &creature_pool.flags;
  do {
    ((creature_t *)(piVar1 + -0x23))->active = 0;
    if ((*piVar1 & 4) != 0) {
      (&creature_spawn_slot_table)[piVar1[-5]].owner = (creature_t *)0x0;
    }
    piVar1 = piVar1 + 0x26;
  } while ((int)piVar1 < 0x4aa3c4);
  return piVar1;
}



