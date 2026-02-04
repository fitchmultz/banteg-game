/* crt_shortsort @ 00462d28 */

/* CRT: insertion sort for small arrays (cmp) */

void __cdecl crt_shortsort(char *lo,char *hi,size_t width,void *cmp)

{
  int iVar1;
  char *a;
  char *pcVar2;
  
  for (; a = lo, pcVar2 = lo, lo < hi; hi = hi + -width) {
    while (pcVar2 = pcVar2 + width, pcVar2 <= hi) {
      iVar1 = (*cmp)(pcVar2,a);
      if (0 < iVar1) {
        a = pcVar2;
      }
    }
    crt_swap(a,hi,width);
  }
  return;
}



