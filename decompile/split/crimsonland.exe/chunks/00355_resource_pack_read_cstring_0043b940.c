/* resource_pack_read_cstring @ 0043b940 */

/* reads a NUL-terminated pack entry name into DAT_004c3a68 */

uint __cdecl resource_pack_read_cstring(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = *(byte *)(param_1 + 3);
  while (((bVar1 & 0x10) == 0 && (uVar2 = crt_getc(param_1), uVar2 != 0))) {
    (&DAT_004c3a68)[iVar3] = (char)uVar2;
    bVar1 = *(byte *)(param_1 + 3);
    iVar3 = iVar3 + 1;
  }
  (&DAT_004c3a68)[iVar3] = 0;
  return (uint)~param_1[3] >> 4 & 1;
}



