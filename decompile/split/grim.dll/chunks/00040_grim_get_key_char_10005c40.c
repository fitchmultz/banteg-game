/* grim_get_key_char @ 10005c40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x50 (provisional) */

int grim_get_key_char(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (DAT_1005d3e4 != 0) {
    iVar1 = DAT_1005d3c4;
    if (0 < DAT_1005d3e4) {
      puVar2 = &DAT_1005d3c4;
      iVar3 = DAT_1005d3e4;
      do {
        *puVar2 = puVar2[1];
        puVar2 = puVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    DAT_1005d3e4 = DAT_1005d3e4 + -1;
    return iVar1;
  }
  return 0;
}



