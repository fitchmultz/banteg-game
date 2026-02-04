/* console_cmd_argc_get @ 00401150 */

/* returns current console token count (argc; includes the command token at index 0) */

int console_cmd_argc_get(void)

{
  return console_cmd_argc;
}



