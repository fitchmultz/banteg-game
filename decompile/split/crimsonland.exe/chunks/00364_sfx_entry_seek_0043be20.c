/* sfx_entry_seek @ 0043be20 */

/* seeks streaming sfx data and resets playback cursors */

void __cdecl sfx_entry_seek(int entry,int sample_offset)

{
  int *sample_offset_00;
  
  if (*(int *)(entry + 0x74) != 0) {
    sample_offset_00 = *(int **)(entry + 0x24);
    (**(code **)(*sample_offset_00 + 0x34))(sample_offset_00,sample_offset);
    vorbis_pcm_seek(*(void **)(entry + 0x74),(void *)sample_offset,(uint)sample_offset_00);
    *(undefined4 *)(entry + 0x1c) = 0;
    *(undefined4 *)(entry + 0x78) = 0;
    *(undefined4 *)(entry + 0x7c) = 0;
    *(undefined4 *)(entry + 0x80) = 0;
  }
  return;
}



