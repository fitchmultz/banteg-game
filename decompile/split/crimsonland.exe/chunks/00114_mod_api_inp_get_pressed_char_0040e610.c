/* mod_api_inp_get_pressed_char @ 0040e610 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x7c: clAPI_t::INP_GetPressedChar (bridges to grim_get_key_char) */

char mod_api_inp_get_pressed_char(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040e618. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*grim_interface_ptr->vtable->grim_get_key_char)();
  return (char)iVar1;
}



