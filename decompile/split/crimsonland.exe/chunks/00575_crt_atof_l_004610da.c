/* crt_atof_l @ 004610da */

/* CRT-like parse string to float (atof-style) */

float __thiscall crt_atof_l(void *this,char *str)

{
  uint uVar1;
  int iVar2;
  byte *this_00;
  undefined *puVar3;
  uint local_1c [6];
  
  while( true ) {
    if (DAT_0047b3cc < 2) {
      uVar1 = (byte)crt_ctype_table[(uint)(byte)*str * 2] & 8;
      this = crt_ctype_table;
    }
    else {
      puVar3 = (undefined *)0x8;
      uVar1 = crt_isctype(this,(uint)(byte)*str,8);
      this = puVar3;
    }
    if (uVar1 == 0) break;
    str = (char *)((byte *)str + 1);
  }
  this_00 = (byte *)str;
  _strlen(str);
  iVar2 = FUN_00464be7(this_00,local_1c,(byte *)str);
  return (float)*(double *)(iVar2 + 0x10);
}



