/* strdup_malloc @ 0046e8f4 */

/* malloc+copy helper */

char * __cdecl strdup_malloc(char *src)

{
  size_t sVar1;
  char *pcVar2;
  
  if (src != (char *)0x0) {
    sVar1 = _strlen(src);
    pcVar2 = _malloc(sVar1 + 1);
    if (pcVar2 != (char *)0x0) {
      pcVar2 = crt_strcpy(pcVar2,src);
      return pcVar2;
    }
  }
  return (char *)0x0;
}


