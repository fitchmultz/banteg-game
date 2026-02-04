/* FUN_10006ea0 @ 10006ea0 */

undefined4 FUN_10006ea0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = DAT_1005d158;
  fVar1 = DAT_1005d138;
  iVar3 = (*grim_interface_instance->vtable->grim_get_joystick_y)();
  if ((float)iVar3 - fVar2 < -fVar1) {
    return 1;
  }
  return 0;
}



