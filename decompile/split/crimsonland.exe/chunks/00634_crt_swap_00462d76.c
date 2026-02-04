/* crt_swap @ 00462d76 */

/* CRT: swap elements for qsort */

void __cdecl crt_swap(char *a,char *b,size_t width)

{
  char cVar1;
  
  if (a != b) {
    for (; width != 0; width = width - 1) {
      cVar1 = *a;
      *a = *b;
      a = a + 1;
      *b = cVar1;
      b = b + 1;
    }
  }
  return;
}



