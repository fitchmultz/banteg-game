/* buffer_reader_skip @ 0043b8c0 */

/* advances the buffer reader cursor */

void __cdecl buffer_reader_skip(int count)

{
  buffer_reader_offset = buffer_reader_offset + count;
  return;
}



