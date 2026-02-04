/* buffer_reader_find_tag @ 0043b8e0 */

/* searches the buffer for a tag and updates the cursor */

int __cdecl buffer_reader_find_tag(char *tag,int tag_len)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < buffer_reader_size) {
    do {
      iVar1 = 0;
      if (0 < tag_len) {
        do {
          if (*(char *)((int)buffer_reader_data + iVar1 + iVar2) != tag[iVar1]) break;
          iVar1 = iVar1 + 1;
        } while (iVar1 < tag_len);
      }
      if (iVar1 == tag_len) {
        buffer_reader_offset = iVar2 + tag_len;
        return CONCAT31((int3)((uint)iVar1 >> 8),1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < buffer_reader_size);
  }
  return buffer_reader_size & 0xffffff00;
}



