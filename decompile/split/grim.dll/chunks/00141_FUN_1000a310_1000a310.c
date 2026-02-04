/* FUN_1000a310 @ 1000a310 */

byte __cdecl FUN_1000a310(uint param_1)

{
  return grim_joystick_state.rgbButtons[param_1 & 0xff] >> 7;
}



