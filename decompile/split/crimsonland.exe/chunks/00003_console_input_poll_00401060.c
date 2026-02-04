/* console_input_poll @ 00401060 */

/* polls text input and updates console buffer */

int console_input_poll(void)

{
  int iVar1;
  
  iVar1 = (*grim_interface_ptr->vtable->grim_get_key_char)();
  if (console_input_enabled != '\0') {
    if ((iVar1 != 0) && (console_input_ready == '\0')) {
      if (iVar1 == 0xd) {
        console_input_ready = '\x01';
        *(undefined1 *)((int)&console_input_buf + console_input_cursor) = 0;
        console_input_cursor = console_input_cursor + 1;
        return 0;
      }
      if (iVar1 == 8) {
        if (0 < console_input_cursor) {
          console_input_cursor = console_input_cursor + -1;
        }
        *(undefined1 *)((int)&console_input_buf + console_input_cursor) = 0;
        return 0;
      }
      *(char *)((int)&console_input_buf + console_input_cursor) = (char)iVar1;
      iVar1 = console_input_cursor + 1;
      if (0x3ff < console_input_cursor + 1) {
        iVar1 = console_input_cursor;
      }
      console_input_cursor = iVar1;
      *(undefined1 *)((int)&console_input_buf + iVar1) = 0;
    }
    iVar1 = 0;
  }
  return iVar1;
}



