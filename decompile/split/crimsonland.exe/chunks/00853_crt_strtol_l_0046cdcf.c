/* crt_strtol_l @ 0046cdcf */

/* CRT: parse integer with base (locale) */

long __thiscall crt_strtol_l(void *this,void *locale,char *str,char **endptr,int base)

{
  ulong uVar1;
  uint unaff_retaddr;
  
  uVar1 = crt_strtoxl(this,locale,str,endptr,0,unaff_retaddr);
  return uVar1;
}



