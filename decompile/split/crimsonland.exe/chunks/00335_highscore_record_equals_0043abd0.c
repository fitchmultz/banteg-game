/* highscore_record_equals @ 0043abd0 */

/* compares high score record metadata and name for equality */

int __cdecl highscore_record_equals(byte *left,byte *right)

{
  byte bVar1;
  uint3 uVar3;
  int iVar2;
  bool bVar4;
  
  uVar3 = (uint3)((uint)left >> 8);
  if (*(int *)(left + 0x24) != *(int *)(right + 0x24)) {
    return (uint)uVar3 << 8;
  }
  if (*(int *)(left + 0x20) != *(int *)(right + 0x20)) {
    return (uint)uVar3 << 8;
  }
  if (left[0x28] != right[0x28]) {
    return (uint)uVar3 << 8;
  }
  if (*(int *)(left + 0x34) != *(int *)(right + 0x34)) {
    return (uint)uVar3 << 8;
  }
  if (*(int *)(left + 0x30) != *(int *)(right + 0x30)) {
    return (uint)uVar3 << 8;
  }
  if (*(int *)(left + 0x2c) != *(int *)(right + 0x2c)) {
    return (uint)uVar3 << 8;
  }
  while( true ) {
    bVar1 = *left;
    bVar4 = bVar1 < *right;
    if (bVar1 != *right) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = left[1];
    bVar4 = bVar1 < right[1];
    if (bVar1 != right[1]) break;
    left = left + 2;
    right = right + 2;
    if (bVar1 == 0) {
      return 1;
    }
  }
  iVar2 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
  return CONCAT31((int3)((uint)iVar2 >> 8),iVar2 == 0);
}



