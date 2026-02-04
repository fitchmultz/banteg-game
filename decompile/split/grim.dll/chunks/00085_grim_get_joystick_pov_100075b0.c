/* grim_get_joystick_pov @ 100075b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xa4 (provisional): joystick POV hat value */

int grim_get_joystick_pov(int index)

{
  return grim_joystick_state.rgdwPOV[index];
}



