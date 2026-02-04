/* effect_free @ 0042e080 */

/* returns an effect entry to the free list */

void __cdecl effect_free(void *entry)

{
  *(void **)((int)entry + 0xb8) = effect_free_list_head;
  *(undefined4 *)((int)entry + 0x2c) = 0;
  effect_free_list_head = entry;
  return;
}



