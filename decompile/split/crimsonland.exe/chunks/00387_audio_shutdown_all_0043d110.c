/* audio_shutdown_all @ 0043d110 */

/* shuts down sfx + music systems */

void audio_shutdown_all(void)

{
  sfx_release_all();
  music_release_all();
  dsound_shutdown();
  return;
}



