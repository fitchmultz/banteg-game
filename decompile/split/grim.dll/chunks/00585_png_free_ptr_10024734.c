/* png_free_ptr @ 10024734 */

/* free wrapper for png allocations */

void __cdecl png_free_ptr(void *ptr)

{
  if (ptr != (void *)0x0) {
    free(ptr);
    return;
  }
  return;
}



