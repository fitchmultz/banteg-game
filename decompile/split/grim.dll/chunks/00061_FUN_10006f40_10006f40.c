/* FUN_10006f40 @ 10006f40 */

undefined4 FUN_10006f40(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = DAT_1005d148;
  fVar1 = DAT_1005d138;
  iVar3 = (*grim_interface_instance->vtable->grim_get_joystick_x)();
  if ((float)iVar3 - fVar2 < -fVar1) {
    return 1;
  }
  return 0;
}



