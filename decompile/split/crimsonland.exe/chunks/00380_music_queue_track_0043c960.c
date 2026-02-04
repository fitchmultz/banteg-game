/* music_queue_track @ 0043c960 */

/* queues a music track id */

void __cdecl music_queue_track(int track_id)

{
  if (-1 < track_id) {
    music_playlist[DAT_004cc8d0] = track_id;
    DAT_004cc8d0 = DAT_004cc8d0 + 1;
  }
  return;
}



