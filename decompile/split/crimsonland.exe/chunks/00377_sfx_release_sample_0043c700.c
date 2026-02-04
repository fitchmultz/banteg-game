/* sfx_release_sample @ 0043c700 */

/* releases an sfx sample by id */

int __cdecl sfx_release_sample(int sfx_id)

{
  uint in_EAX;
  undefined4 extraout_EAX;
  
  if (((-1 < sfx_id) && (sfx_id < 0x80)) &&
     (in_EAX = sfx_id * 0x84, (&sfx_entry_table)[sfx_id].pcm_data != (void *)0x0)) {
    sfx_release_entry((int)(&sfx_entry_table + sfx_id));
    return CONCAT31((int3)((uint)extraout_EAX >> 8),1);
  }
  return in_EAX & 0xffffff00;
}



