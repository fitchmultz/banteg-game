/* console_clear_log @ 004011a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* clears console log history and resets scroll state (clear command handler) */

void console_clear_log(void)

{
  undefined4 *ptr;
  
  ptr = console_log_head;
  if (console_log_head != (undefined4 *)0x0) {
    if ((void *)*console_log_head != (void *)0x0) {
      crt_free((void *)*console_log_head);
    }
    *ptr = 0;
    if ((void *)ptr[1] != (void *)0x0) {
      console_log_node_free((void *)ptr[1],'\x01');
    }
    ptr[1] = 0;
    crt_free(ptr);
  }
  console_log_head = (undefined4 *)0x0;
  _DAT_0047eec0 = 0;
  _DAT_0047eec4 = 0;
  return;
}



