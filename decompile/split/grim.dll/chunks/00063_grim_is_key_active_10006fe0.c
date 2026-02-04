/* grim_is_key_active @ 10006fe0 */

/* Grim2D vtable 0x80: routes key/mouse/joystick IDs */

int __thiscall grim_is_key_active(void *this,int key)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (key < 0x100) {
    iVar2 = (**(code **)(*(int *)this + 0x44))(key);
    return iVar2;
  }
  if (key == 0x100) {
    iVar2 = (**(code **)(*(int *)this + 0x58))(0);
    return iVar2;
  }
  if (key == 0x101) {
    iVar2 = (**(code **)(*(int *)this + 0x58))(1);
    return iVar2;
  }
  if (key == 0x102) {
    iVar2 = (**(code **)(*(int *)this + 0x58))(2);
    return iVar2;
  }
  if (key == 0x103) {
    iVar2 = (**(code **)(*(int *)this + 0x58))(3);
    return iVar2;
  }
  if (key == 0x104) {
    iVar2 = (**(code **)(*(int *)this + 0x58))(4);
    return iVar2;
  }
  uVar3 = 1;
  do {
    if (key == uVar3 + 0x11e) {
      iVar2 = (**(code **)(*(int *)this + 0xa8))(uVar3 - 1);
      return iVar2;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0xd);
  if (key == 0x131) {
    iVar2 = FUN_10006ea0();
    return iVar2;
  }
  if (key == 0x132) {
    iVar2 = FUN_10006ef0();
    return iVar2;
  }
  if (key == 0x133) {
    iVar2 = FUN_10006f40();
    return iVar2;
  }
  if (key == 0x134) {
    iVar2 = FUN_10006f90();
    return iVar2;
  }
  if (key == 0x13f) {
    fVar1 = (float)grim_joystick_state.lX;
  }
  else if (key == 0x140) {
    fVar1 = (float)grim_joystick_state.lY;
  }
  else if (key == 0x141) {
    fVar1 = (float)grim_joystick_state.lZ;
  }
  else if (key == 0x153) {
    fVar1 = (float)grim_joystick_state.lRx;
  }
  else if (key == 0x154) {
    fVar1 = (float)grim_joystick_state.lRy;
  }
  else {
    if (key != 0x155) {
      if (DAT_1005d3b4 == (int *)0x0) {
        return uVar3 & 0xffffff00;
      }
      iVar2 = 0;
      iVar5 = 0x16d;
      do {
        uVar3 = 0;
        iVar4 = iVar5;
        do {
          if (key == iVar4) {
            iVar2 = (**(code **)(*DAT_1005d3b4 + 0xc))(iVar2,uVar3);
            return iVar2;
          }
          uVar3 = uVar3 + 1;
          iVar4 = iVar4 + 1;
        } while ((int)uVar3 < 5);
        iVar5 = iVar5 + 5;
        iVar2 = iVar2 + 1;
      } while (iVar5 < 0x17c);
      return uVar3 & 0xffffff00;
    }
    fVar1 = (float)grim_joystick_state.lRz;
  }
  if (0.5 < ABS(fVar1 * 0.001)) {
    return 1;
  }
  return 0;
}



