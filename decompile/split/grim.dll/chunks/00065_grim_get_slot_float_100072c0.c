/* grim_get_slot_float @ 100072c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x88 (provisional): float slot accessor */

float grim_get_slot_float(int index)

{
  return *(float *)(&grim_slot_floats + index * 4);
}



