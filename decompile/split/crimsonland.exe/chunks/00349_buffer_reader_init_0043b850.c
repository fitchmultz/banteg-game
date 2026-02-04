/* buffer_reader_init @ 0043b850 */

/* initializes the buffer reader cursor and length */

void __cdecl buffer_reader_init(void *data,int size)

{
  buffer_reader_data = data;
  buffer_reader_size = size;
  buffer_reader_offset = 0;
  return;
}



