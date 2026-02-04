/* input_any_key_pressed @ 00446000 */

/* returns true if any key is down (scans keycodes 2..0x17e) */

int input_any_key_pressed(void)

{
  int iVar1;
  int key;
  
  key = 2;
  do {
    iVar1 = (*grim_interface_ptr->vtable->grim_is_key_active)(key);
    if ((char)iVar1 != '\0') {
      return CONCAT31((int3)((uint)iVar1 >> 8),1);
    }
    key = key + 1;
  } while (key < 0x17f);
  return iVar1;
}



