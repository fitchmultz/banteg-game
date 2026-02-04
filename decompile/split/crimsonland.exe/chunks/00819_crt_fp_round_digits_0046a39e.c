/* crt_fp_round_digits @ 0046a39e */

/* CRT: round float digits and adjust exponent for printf formatting */

void __cdecl crt_fp_round_digits(char *dst,int precision,int *fp_info)

{
  char *_Str;
  char *dst_00;
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  char cVar4;
  
  dst_00 = dst;
  pcVar3 = (char *)fp_info[3];
  _Str = dst + 1;
  *dst = '0';
  pcVar1 = _Str;
  if (0 < precision) {
    dst = (char *)precision;
    precision = 0;
    do {
      cVar4 = *pcVar3;
      if (cVar4 == '\0') {
        cVar4 = '0';
      }
      else {
        pcVar3 = pcVar3 + 1;
      }
      *pcVar1 = cVar4;
      pcVar1 = pcVar1 + 1;
      dst = dst + -1;
    } while (dst != (char *)0x0);
  }
  *pcVar1 = '\0';
  if ((-1 < precision) && ('4' < *pcVar3)) {
    while (pcVar1 = pcVar1 + -1, *pcVar1 == '9') {
      *pcVar1 = '0';
    }
    *pcVar1 = *pcVar1 + '\x01';
  }
  if (*dst_00 == '1') {
    fp_info[1] = fp_info[1] + 1;
  }
  else {
    sVar2 = _strlen(_Str);
    crt_memmove(dst_00,_Str,sVar2 + 1);
  }
  return;
}



