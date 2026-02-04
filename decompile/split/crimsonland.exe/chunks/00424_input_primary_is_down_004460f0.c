/* input_primary_is_down @ 004460f0 */

/* returns true while primary action is held (mouse button 0 or primary fire keys) */

int input_primary_is_down(void)

{
  int iVar1;
  
  iVar1 = (*grim_interface_ptr->vtable->grim_is_mouse_button_down)(0);
  if ((char)iVar1 == '\0') {
    iVar1 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_state_table.input.fire_key);
    if ((char)iVar1 == '\0') {
      iVar1 = (*grim_interface_ptr->vtable->grim_is_key_active)(player_alt_fire_key);
      if ((char)iVar1 == '\0') {
        return 0;
      }
    }
  }
  return 1;
}



