/* console_input_clear @ 00401030 */

/* clears console input buffer */

void console_input_clear(void)

{
  console_input_ready = 0;
  console_input_cursor = 0;
  console_input_buf._0_1_ = 0;
  return;
}



