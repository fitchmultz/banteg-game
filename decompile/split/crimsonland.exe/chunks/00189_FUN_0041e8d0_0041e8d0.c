/* FUN_0041e8d0 @ 0041e8d0 */

bool FUN_0041e8d0(void)

{
  int iVar1;
  
  iVar1 = (*grim_interface_ptr->vtable->grim_get_joystick_pov)(0);
  return iVar1 == config_blob.reserved1._16_4_;
}



