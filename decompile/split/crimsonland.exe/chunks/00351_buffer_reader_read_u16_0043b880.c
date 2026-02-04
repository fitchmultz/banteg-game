/* buffer_reader_read_u16 @ 0043b880 */

/* reads a little-endian u16 from the buffer */

int buffer_reader_read_u16(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(buffer_reader_offset + (int)buffer_reader_data);
  buffer_reader_offset = buffer_reader_offset + 2;
  return CONCAT22((short)((uint)buffer_reader_data >> 0x10),*puVar1);
}



