/* music_release_track @ 0043c980 */

/* releases a music track by id */

int __cdecl music_release_track(int track_id)

{
  uint in_EAX;
  undefined4 extraout_EAX;
  
  if (((-1 < track_id) && (track_id < 0x80)) &&
     (in_EAX = track_id * 0x84, (&music_entry_table)[track_id].pcm_data != (void *)0x0)) {
    sfx_release_entry((int)(&music_entry_table + track_id));
    return CONCAT31((int3)((uint)extraout_EAX >> 8),1);
  }
  return in_EAX & 0xffffff00;
}



