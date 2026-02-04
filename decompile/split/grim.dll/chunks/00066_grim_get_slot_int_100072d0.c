/* grim_get_slot_int @ 100072d0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x8c (provisional): int slot accessor */

int grim_get_slot_int(int index)

{
  return *(int *)(&grim_slot_ints + index * 4);
}



