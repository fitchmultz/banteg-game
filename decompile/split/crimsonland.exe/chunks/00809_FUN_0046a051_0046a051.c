/* FUN_0046a051 @ 0046a051 */

/* [binja] int32_t sub_46a051(int32_t arg1, int32_t* arg2) */

int __cdecl FUN_0046a051(int arg1,int *arg2)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_8;
  
  local_8 = 0;
  puVar1 = (uint *)(arg1 + ((int)arg2 / 0x20) * 4);
  bVar3 = 0x1f - (char)((int)arg2 % 0x20);
  if (((*puVar1 & 1 << (bVar3 & 0x1f)) != 0) &&
     (iVar2 = FUN_00469fb2(arg1,(int)arg2 + 1), iVar2 == 0)) {
    local_8 = FUN_00469ffb(arg1,(int)arg2 + -1);
  }
  *puVar1 = *puVar1 & -1 << (bVar3 & 0x1f);
  iVar2 = (int)arg2 / 0x20 + 1;
  if (iVar2 < 3) {
    puVar5 = (undefined4 *)(arg1 + iVar2 * 4);
    for (iVar4 = 3 - iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_8;
}



