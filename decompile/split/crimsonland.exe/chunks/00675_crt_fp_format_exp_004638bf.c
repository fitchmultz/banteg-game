/* crt_fp_format_exp @ 004638bf */

/* CRT: formats floating output in scientific notation (adds decimal/exponent) */

char * __cdecl crt_fp_format_exp(char *dst,int precision,int caps,int *fp_info,int force_decimal)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if ((char)force_decimal != '\0') {
    crt_str_shift_right(dst + (*fp_info == 0x2d),(uint)(0 < precision));
  }
  pcVar2 = dst;
  if (*fp_info == 0x2d) {
    *dst = '-';
    pcVar2 = dst + 1;
  }
  pcVar1 = pcVar2;
  if (0 < precision) {
    pcVar1 = pcVar2 + 1;
    *pcVar2 = pcVar2[1];
    *pcVar1 = DAT_0047b3d0;
  }
  pcVar2 = crt_strcpy(pcVar1 + precision + (uint)((char)force_decimal == '\0'),"e+000");
  if (caps != 0) {
    *pcVar2 = 'E';
  }
  if (*(char *)fp_info[3] != '0') {
    iVar3 = fp_info[1] + -1;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
      pcVar2[1] = '-';
    }
    if (99 < iVar3) {
      pcVar2[2] = pcVar2[2] + (char)(iVar3 / 100);
      iVar3 = iVar3 % 100;
    }
    if (9 < iVar3) {
      pcVar2[3] = pcVar2[3] + (char)(iVar3 / 10);
      iVar3 = iVar3 % 10;
    }
    pcVar2[4] = pcVar2[4] + (char)iVar3;
  }
  return dst;
}



