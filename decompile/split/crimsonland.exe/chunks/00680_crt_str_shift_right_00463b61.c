/* crt_str_shift_right @ 00463b61 */

/* CRT: shift string right by count (memmove) */

void __cdecl crt_str_shift_right(char *str,int count)

{
  size_t sVar1;
  
  if (count != 0) {
    sVar1 = _strlen(str);
    crt_memmove(str + count,str,sVar1 + 1);
  }
  return;
}



