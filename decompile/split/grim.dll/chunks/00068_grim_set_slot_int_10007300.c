/* grim_set_slot_int @ 10007300 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x94 (provisional): int slot setter */

void grim_set_slot_int(int index,int value)

{
  *(int *)(&grim_slot_ints + index * 4) = value;
  return;
}



