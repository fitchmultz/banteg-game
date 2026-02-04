/* sfx_is_unmuted @ 0043d7c0 */

/* returns nonzero when sfx id is not muted */

int __cdecl sfx_is_unmuted(int sfx_id)

{
  uint in_EAX;
  
  if (sfx_unmuted_flag == '\0') {
    return in_EAX & 0xffffff00;
  }
  return (uint)(sfx_mute_flags[sfx_id] == '\0');
}



