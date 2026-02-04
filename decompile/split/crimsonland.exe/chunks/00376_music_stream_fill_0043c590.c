/* music_stream_fill @ 0043c590 */

/* decodes and writes the next music stream chunk */

int __cdecl music_stream_fill(int entry)

{
  int iVar1;
  uint uVar2;
  uint extraout_EAX;
  int iVar3;
  int iVar4;
  char *dst;
  int *bytes;
  
  bytes = *(int **)(entry + 0x24);
  iVar1 = (int)(*(int *)(entry + 0x18) + (*(int *)(entry + 0x18) >> 0x1f & 3U)) >> 2;
  iVar4 = *(int *)(entry + 0x1c);
  uVar2 = (**(code **)(*bytes + 0x2c))();
  if (-1 < (int)uVar2) {
    if (&stack0x00000000 != (undefined1 *)0xc) {
      OutputDebugStringA(s_____SND__Somehow_data_on_the_sec_00477ccc);
      return extraout_EAX & 0xffffff00;
    }
    dst = (char *)0x8;
    do {
      iVar3 = vorbis_read_pcm16(*(void **)(entry + 0x74),(void *)((8 - (int)dst) + iVar1),dst,
                                (int)bytes);
      if (iVar3 < 1) {
        iVar3 = vorbis_read_pcm16(*(void **)(entry + 0x74),(void *)((8 - (int)dst) + iVar1),dst,
                                  (int)bytes);
      }
      dst = dst + -iVar3;
    } while ((0 < (int)dst) && (iVar3 != 0));
    (**(code **)(**(int **)(entry + 0x24) + 0x4c))(*(int **)(entry + 0x24),iVar1,8,0,0);
    iVar4 = iVar4 + *(int *)(entry + 0x1c);
    uVar2 = iVar4 / *(int *)(entry + 0x18);
    *(int *)(entry + 0x1c) = iVar4 % *(int *)(entry + 0x18);
  }
  return uVar2 & 0xffffff00;
}



