/* effect_select_texture @ 0042e0a0 */

/* selects effect texture page based on effect id */

void __cdecl effect_select_texture(int effect_id)

{
  int iVar1;
  int frame;
  
  iVar1 = (&effect_id_table)[effect_id].size_code;
  frame = (&effect_id_table)[effect_id].frame;
  if (iVar1 == 0x10) {
    (*grim_interface_ptr->vtable->grim_set_atlas_frame)(0x10,frame);
    return;
  }
  if (iVar1 == 0x20) {
    (*grim_interface_ptr->vtable->grim_set_atlas_frame)(8,frame);
    return;
  }
  if (iVar1 == 0x40) {
    (*grim_interface_ptr->vtable->grim_set_atlas_frame)(4,frame);
    return;
  }
  if (iVar1 == 0x80) {
    (*grim_interface_ptr->vtable->grim_set_atlas_frame)(2,frame);
  }
  return;
}



