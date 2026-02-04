/* grim_set_slot_float @ 100072e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x90 (provisional): float slot setter */

void grim_set_slot_float(int index,float value)

{
  *(float *)(&grim_slot_floats + index * 4) = value;
  return;
}



