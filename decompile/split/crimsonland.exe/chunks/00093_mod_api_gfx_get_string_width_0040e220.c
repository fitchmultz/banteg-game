/* mod_api_gfx_get_string_width @ 0040e220 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x20: clAPI_t::GFX_GetStringWidth (bridges to grim_measure_text_width) */

int mod_api_gfx_get_string_width(char *string)

{
  int iVar1;
  
  iVar1 = (*grim_interface_ptr->vtable->grim_measure_text_width)(string);
  return iVar1;
}



