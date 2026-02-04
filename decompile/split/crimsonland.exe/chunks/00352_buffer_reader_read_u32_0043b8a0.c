/* buffer_reader_read_u32 @ 0043b8a0 */

/* reads a little-endian u32 from the buffer */

uint buffer_reader_read_u32(void)

{
  uint *puVar1;
  
  puVar1 = (uint *)(buffer_reader_offset + (int)buffer_reader_data);
  buffer_reader_offset = buffer_reader_offset + 4;
  return *puVar1;
}



