/* mod_api_inp_key_down @ 0040e660 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x74: clAPI_t::INP_KeyDown (uses grim_is_key_active) */

uchar mod_api_inp_key_down(int key)

{
  int iVar1;
  
  if (key == 1) {
    return '\0';
  }
  iVar1 = (*grim_interface_ptr->vtable->grim_is_key_active)(key);
  return (uchar)iVar1;
}



