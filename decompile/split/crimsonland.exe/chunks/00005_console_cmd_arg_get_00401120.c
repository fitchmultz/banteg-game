/* console_cmd_arg_get @ 00401120 */

/* returns console token N (1..argc-1); returns empty string if out of range */

char * __cdecl console_cmd_arg_get(int index)

{
  if (((0 < console_cmd_argc) && (0 < index)) && (index < console_cmd_argc)) {
    return (&console_cmd_name)[index];
  }
  return PTR_s_empty_string_00471158;
}



