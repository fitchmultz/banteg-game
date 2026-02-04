/* music_release_all @ 0043d0d0 */

/* releases all loaded music tracks */

void music_release_all(void)

{
  char *filename;
  music_entry_t *entry;
  
  if (sfx_unmuted_flag != '\0') {
    entry = &music_entry_table;
    do {
      sfx_release_entry((int)entry);
      entry = entry + 1;
    } while ((int)entry < 0x4c8450);
    console_flush_log(&console_log_queue,filename);
  }
  return;
}



