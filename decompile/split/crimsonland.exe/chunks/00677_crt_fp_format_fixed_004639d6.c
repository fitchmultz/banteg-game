/* crt_fp_format_fixed @ 004639d6 */

/* CRT: formats floating output in fixed notation (adds decimal/zeros) */

char * __cdecl crt_fp_format_fixed(char *dst,size_t precision,int *fp_info,int force_decimal)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = fp_info[1];
  if (((char)force_decimal != '\0') && (iVar1 - 1U == precision)) {
    iVar2 = *fp_info;
    dst[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = '0';
    (dst + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = '\0';
  }
  pcVar3 = dst;
  if (*fp_info == 0x2d) {
    *dst = '-';
    pcVar3 = dst + 1;
  }
  if (fp_info[1] < 1) {
    crt_str_shift_right(pcVar3,1);
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    pcVar3 = pcVar3 + fp_info[1];
  }
  if (0 < (int)precision) {
    crt_str_shift_right(pcVar3,1);
    *pcVar3 = DAT_0047b3d0;
    iVar1 = fp_info[1];
    if (iVar1 < 0) {
      if (((char)force_decimal != '\0') || (-iVar1 <= (int)precision)) {
        precision = -iVar1;
      }
      crt_str_shift_right(pcVar3 + 1,precision);
      _memset(pcVar3 + 1,0x30,precision);
    }
  }
  return dst;
}



