/* wav_parse_into_entry @ 0043c110 */

/* parses WAV data into an entry and copies PCM */

int __cdecl wav_parse_into_entry(void *entry,void *data,int size)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)entry = 0;
  *(undefined4 *)((int)entry + 4) = 0;
  *(undefined4 *)((int)entry + 8) = 0;
  *(undefined4 *)((int)entry + 0xc) = 0;
  *(undefined2 *)((int)entry + 0x10) = 0;
  *(undefined2 *)entry = 1;
  *(undefined2 *)((int)entry + 2) = 1;
  *(undefined2 *)((int)entry + 0xe) = 0x10;
  *(undefined4 *)((int)entry + 4) = 0x5622;
  *(undefined2 *)((int)entry + 0xc) = 2;
  *(undefined2 *)((int)entry + 0x10) = 0;
  *(undefined4 *)((int)entry + 8) = 0xac44;
  buffer_reader_init(data,size);
  buffer_reader_seek(0);
  iVar1 = buffer_reader_find_tag(&DAT_00477c98,4);
  if ((char)iVar1 == '\0') {
    return iVar1;
  }
  buffer_reader_skip(4);
  buffer_reader_skip(2);
  iVar1 = buffer_reader_read_u16();
  *(short *)((int)entry + 2) = (short)iVar1;
  uVar2 = buffer_reader_read_u32();
  *(uint *)((int)entry + 4) = uVar2;
  buffer_reader_skip(6);
  uVar2 = buffer_reader_read_u16();
  *(short *)((int)entry + 0xe) = (short)uVar2;
  iVar1 = (uint)*(ushort *)((int)entry + 2) * (uVar2 & 0xffff);
  *(undefined2 *)((int)entry + 0x10) = 0;
  uVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
  *(short *)((int)entry + 0xc) = (short)uVar2;
  *(uint *)((int)entry + 8) = (uVar2 & 0xffff) * *(int *)((int)entry + 4);
  buffer_reader_find_tag(&DAT_00477c90,4);
  uVar2 = buffer_reader_read_u32();
  *(uint *)((int)entry + 0x18) = uVar2;
  puVar3 = operator_new(uVar2);
  *(undefined4 **)((int)entry + 0x14) = puVar3;
  puVar5 = (undefined4 *)(buffer_reader_offset + (int)data);
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar3 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar4 = uVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return CONCAT31((int3)(uVar2 >> 8),1);
}



