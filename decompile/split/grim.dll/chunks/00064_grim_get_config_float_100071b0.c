/* grim_get_config_float @ 100071b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x84: config float lookup (scaled) */

float grim_get_config_float(int id)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  float10 fVar3;
  
  if (0xff < id) {
    if (id == 0x13f) {
      return (float)grim_joystick_state.lX * 0.001;
    }
    if (id == 0x140) {
      return (float)grim_joystick_state.lY * 0.001;
    }
    if (id == 0x141) {
      return (float)grim_joystick_state.lZ * 0.001;
    }
    if (id == 0x153) {
      return (float)grim_joystick_state.lRx * 0.001;
    }
    if (id == 0x154) {
      return (float)grim_joystick_state.lRy * 0.001;
    }
    if (id == 0x155) {
      return (float)grim_joystick_state.lRz * 0.001;
    }
    if (id == 0x15f) {
      fVar3 = (float10)(**(code **)(*in_ECX + 0x70))();
      return (float)fVar3;
    }
    if (id == 0x160) {
      fVar3 = (float10)(**(code **)(*in_ECX + 0x74))();
      return (float)fVar3;
    }
    iVar2 = 0;
    iVar1 = 0x168;
    do {
      if (id == iVar1 + -5) {
        fVar3 = (float10)(**(code **)(*in_ECX + 0x78))(iVar2);
        return (float)fVar3;
      }
      if (id == iVar1) {
        fVar3 = (float10)(**(code **)(*in_ECX + 0x7c))(iVar2);
        return (float)fVar3;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x16b);
  }
  return 0.0;
}



