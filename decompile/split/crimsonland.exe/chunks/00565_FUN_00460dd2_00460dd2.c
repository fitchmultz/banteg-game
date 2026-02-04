/* FUN_00460dd2 @ 00460dd2 */

int __thiscall FUN_00460dd2(void *this,byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint c;
  byte *pbVar4;
  undefined *puVar5;
  
  while( true ) {
    if (DAT_0047b3cc < 2) {
      uVar1 = (byte)crt_ctype_table[(uint)*param_1 * 2] & 8;
      this = crt_ctype_table;
    }
    else {
      puVar5 = (undefined *)0x8;
      uVar1 = crt_isctype(this,(uint)*param_1,8);
      this = puVar5;
    }
    if (uVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar1 = (uint)*param_1;
  pbVar4 = param_1 + 1;
  if ((uVar1 == 0x2d) || (c = uVar1, uVar1 == 0x2b)) {
    c = (uint)*pbVar4;
    pbVar4 = param_1 + 2;
  }
  iVar3 = 0;
  while( true ) {
    if (DAT_0047b3cc < 2) {
      uVar2 = (byte)crt_ctype_table[c * 2] & 4;
    }
    else {
      puVar5 = (undefined *)0x4;
      uVar2 = crt_isctype(this,c,4);
      this = puVar5;
    }
    if (uVar2 == 0) break;
    iVar3 = (c - 0x30) + iVar3 * 10;
    c = (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
  }
  if (uVar1 == 0x2d) {
    iVar3 = -iVar3;
  }
  return iVar3;
}



