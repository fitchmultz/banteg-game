/* console_global_init @ 00401170 */

/* [binja] int32_t sub_401170() */

int console_global_init(void)

{
  int *piVar1;
  
  piVar1 = console_init(&console_log_queue);
  return (int)piVar1;
}



