/* sfx_release_all @ 0043d070 */

/* releases all loaded sfx samples */

void sfx_release_all(void)

{
  char *filename;
  sfx_entry_t *entry;
  
  if (config_blob.reserved0[0] == '\0') {
    entry = &sfx_entry_table;
    do {
      sfx_release_entry((int)entry);
      entry = entry + 1;
    } while ((int)entry < 0x4cc6d0);
    console_printf(&console_log_queue,s_SFX_Shutdown____004785fc);
    console_printf(&console_log_queue,s_SFX_Released__004785ec);
    console_flush_log(&console_log_queue,filename);
  }
  return;
}



