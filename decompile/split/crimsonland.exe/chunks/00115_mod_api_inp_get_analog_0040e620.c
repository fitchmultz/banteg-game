/* mod_api_inp_get_analog @ 0040e620 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x78: clAPI_t::INP_GetAnalog */

float mod_api_inp_get_analog(int key)

{
  float10 fVar1;
  
  if (key == 0x163) {
    return ui_mouse_x;
  }
  if (key == 0x164) {
    return ui_mouse_y;
  }
  fVar1 = (float10)(*grim_interface_ptr->vtable->grim_get_config_float)(key);
  return (float)fVar1;
}



