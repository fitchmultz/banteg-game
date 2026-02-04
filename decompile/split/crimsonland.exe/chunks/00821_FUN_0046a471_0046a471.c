/* FUN_0046a471 @ 0046a471 */

/* [binja] int32_t* sub_46a471(int32_t* arg1, int32_t* arg2) */

int * __cdecl FUN_0046a471(int *arg1,int *arg2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  uVar1 = *(ushort *)((int)arg2 + 6);
  uVar3 = (uVar1 & 0x7ff0) >> 4;
  uVar2 = *arg2;
  local_8 = 0x80000000;
  if (uVar3 == 0) {
    if (((arg2[1] & 0xfffffU) == 0) && (uVar2 == 0)) {
      arg1[1] = 0;
      *arg1 = 0;
      *(undefined2 *)(arg1 + 2) = 0;
      return arg1;
    }
    iVar4 = 0x3c01;
    local_8 = 0;
  }
  else if (uVar3 == 0x7ff) {
    iVar4 = 0x7fff;
  }
  else {
    iVar4 = uVar3 + 0x3c00;
  }
  local_8 = uVar2 >> 0x15 | (arg2[1] & 0xfffffU) << 0xb | local_8;
  arg1[1] = local_8;
  *arg1 = uVar2 << 0xb;
  while ((local_8 & 0x80000000) == 0) {
    local_8 = (uint)*arg1 >> 0x1f | local_8 * 2;
    *arg1 = *arg1 * 2;
    arg1[1] = local_8;
    iVar4 = iVar4 + 0xffff;
  }
  *(ushort *)(arg1 + 2) = uVar1 & 0x8000 | (ushort)iVar4;
  return arg1;
}



