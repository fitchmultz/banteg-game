/* crt_free @ 00460dc7 */

/* CRT free wrapper */

void __cdecl crt_free(void *ptr)

{
  crt_free_base(ptr);
  return;
}



