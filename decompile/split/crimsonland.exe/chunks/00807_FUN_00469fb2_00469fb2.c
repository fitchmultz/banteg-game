/* FUN_00469fb2 @ 00469fb2 */

/* [binja] int32_t sub_469fb2(int32_t arg1, int32_t arg2) */

int __cdecl FUN_00469fb2(int arg1,int arg2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(uint *)(arg1 + (arg2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(arg2 % 0x20) & 0x1f))) != 0) {
    return 0;
  }
  iVar2 = arg2 / 0x20 + 1;
  if (iVar2 < 3) {
    piVar1 = (int *)(arg1 + iVar2 * 4);
    do {
      if (*piVar1 != 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 3);
  }
  return 1;
}



