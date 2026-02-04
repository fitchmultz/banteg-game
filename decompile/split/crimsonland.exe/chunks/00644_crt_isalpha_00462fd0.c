/* crt_isalpha @ 00462fd0 */

/* ctype alpha check (MBCS-aware) */

uint __thiscall crt_isalpha(void *this,int c)

{
  uint uVar1;
  
  if (1 < DAT_0047b3cc) {
    uVar1 = crt_isctype(this,c,0x103);
    return uVar1;
  }
  return *(ushort *)(crt_ctype_table + c * 2) & 0x103;
}



