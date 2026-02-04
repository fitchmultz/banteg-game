/* music_stream_update @ 0043c520 */

/* updates streaming cursor and refills if needed */

void __cdecl music_stream_update(int entry)

{
  int entry_00;
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  entry_00 = entry;
  iVar1 = (**(code **)(**(int **)(entry + 0x24) + 0x10))(*(int **)(entry + 0x24),&entry);
  if (-1 < iVar1) {
    if (*(int *)(entry_00 + 0x78) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(entry_00 + 0x18) - *(int *)(entry_00 + 0x78);
    }
    *(undefined4 *)(entry_00 + 0x78) = 0;
    uVar3 = *(int *)(entry_00 + 0x80) + iVar1;
    *(int *)(entry_00 + 0x7c) = *(int *)(entry_00 + 0x7c) + iVar1;
    *(uint *)(entry_00 + 0x80) = uVar3;
    uVar2 = (int)(*(int *)(entry_00 + 0x18) + (*(int *)(entry_00 + 0x18) >> 0x1f & 3U)) >> 2;
    if (uVar2 < uVar3) {
      *(uint *)(entry_00 + 0x80) = uVar3 - uVar2;
      music_stream_fill(entry_00);
    }
  }
  return;
}



