/* FUN_004666f5 @ 004666f5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_4666f5(int32_t* arg1) */

int __cdecl FUN_004666f5(int *arg1)

{
  byte bVar1;
  undefined3 extraout_var;
  int iVar2;
  void *pvVar3;
  
  bVar1 = FUN_0046b08c(arg1[4]);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  if (arg1 == (int *)&DAT_0047b3f8) {
    iVar2 = 0;
  }
  else {
    if (arg1 != (int *)&DAT_0047b418) {
      return 0;
    }
    iVar2 = 1;
  }
  _DAT_004d99d0 = _DAT_004d99d0 + 1;
  if ((*(ushort *)(arg1 + 3) & 0x10c) != 0) {
    return 0;
  }
  if ((&DAT_004d9a68)[iVar2] == 0) {
    pvVar3 = _malloc(0x1000);
    (&DAT_004d9a68)[iVar2] = pvVar3;
    if (pvVar3 == (void *)0x0) {
      arg1[2] = (int)(arg1 + 5);
      *arg1 = (int)(arg1 + 5);
      arg1[6] = 2;
      arg1[1] = 2;
      goto LAB_00466771;
    }
  }
  iVar2 = (&DAT_004d9a68)[iVar2];
  arg1[6] = 0x1000;
  arg1[2] = iVar2;
  *arg1 = iVar2;
  arg1[1] = 0x1000;
LAB_00466771:
  *(ushort *)(arg1 + 3) = *(ushort *)(arg1 + 3) | 0x1102;
  return 1;
}



