/* sfx_entry_start_playback @ 0043be60 */

/* selects a voice/buffer and starts playback */

int __cdecl sfx_entry_start_playback(int entry)

{
  int *piVar1;
  int entry_00;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  entry_00 = entry;
  if (entry == 0) {
    return -1;
  }
  piVar3 = (int *)(entry + 0x24);
  iVar2 = dsound_restore_buffer(*(void **)(entry + 0x24));
  if ((char)iVar2 != '\0') {
    if (*(int *)(entry_00 + 0x74) != 0) goto LAB_0043be9c;
    sfx_entry_upload_buffer(entry_00);
  }
  if (*(int *)(entry_00 + 0x74) == 0) {
    uVar4 = 0;
    do {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(piVar1,&entry);
        if ((entry & 1U) == 0) goto LAB_0043bf10;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
    } while ((int)uVar4 < 0x10);
    uVar4 = crt_rand();
    uVar4 = uVar4 & 0x8000000f;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff0) + 1;
    }
    piVar3 = *(int **)(entry_00 + 0x24 + uVar4 * 4);
    (**(code **)(*piVar3 + 0x48))(piVar3);
LAB_0043bf10:
    piVar3 = *(int **)(entry_00 + 0x24 + uVar4 * 4);
    (**(code **)(*piVar3 + 0x44))(piVar3,sfx_rate_scale);
    piVar3 = *(int **)(entry_00 + 0x24 + uVar4 * 4);
    (**(code **)(*piVar3 + 0x30))(piVar3,0,0,0);
    return uVar4;
  }
LAB_0043be9c:
  sfx_entry_seek(entry_00,0);
  music_stream_fill(entry_00);
  music_stream_fill(entry_00);
  music_stream_fill(entry_00);
  (**(code **)(*(int *)*piVar3 + 0x30))((int *)*piVar3,0,0,1);
  return 0;
}



