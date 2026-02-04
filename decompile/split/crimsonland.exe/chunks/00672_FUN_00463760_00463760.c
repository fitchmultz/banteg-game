/* FUN_00463760 @ 00463760 */

/* [binja] int32_t sub_463760(char* arg1) */

int __cdecl FUN_00463760(char *arg1)

{
  char cVar1;
  undefined *this;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  
  this = (undefined *)(int)*arg1;
  iVar2 = crt_tolower((int)this);
  if (iVar2 != 0x65) {
    do {
      arg1 = arg1 + 1;
      if (DAT_0047b3cc < 2) {
        uVar3 = (byte)crt_ctype_table[*arg1 * 2] & 4;
        this = crt_ctype_table;
      }
      else {
        puVar4 = (undefined *)0x4;
        uVar3 = crt_isctype(this,(int)*arg1,4);
        this = puVar4;
      }
      iVar2 = 0;
    } while (uVar3 != 0);
  }
  iVar2 = CONCAT31((int3)((uint)iVar2 >> 8),*arg1);
  *arg1 = DAT_0047b3d0;
  do {
    arg1 = arg1 + 1;
    cVar1 = *arg1;
    *arg1 = (char)iVar2;
    iVar2 = CONCAT31((int3)((uint)iVar2 >> 8),cVar1);
  } while (*arg1 != '\0');
  return iVar2;
}



