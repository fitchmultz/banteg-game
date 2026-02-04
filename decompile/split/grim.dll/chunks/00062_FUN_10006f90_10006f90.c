/* FUN_10006f90 @ 10006f90 */

undefined4 FUN_10006f90(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = DAT_1005d148;
  fVar1 = DAT_1005d138;
  iVar3 = (*grim_interface_instance->vtable->grim_get_joystick_x)();
  if (fVar1 < (float)iVar3 - fVar2) {
    return 1;
  }
  return 0;
}



