/* crt_isspace @ 00462ffe */

/* ctype space check (MBCS-aware) */

uint __thiscall crt_isspace(void *this,int c)

{
  uint uVar1;
  
  if (1 < DAT_0047b3cc) {
    uVar1 = crt_isctype(this,c,8);
    return uVar1;
  }
  return (byte)crt_ctype_table[c * 2] & 8;
}



